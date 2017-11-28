#include <iostream>

#include <boost/asio.hpp>

#include <boost/network/include/http/client.hpp>

using namespace std;

namespace http = boost::network::http;

void
    do_sync_post()
{
    http::client::request request("http://localhost:11140/test/tag/ok");
    request
        << boost::network::header("Connection", "close");

    http::client::options options;
    options
        .follow_redirects(true)
        .cache_resolved(true)
        .timeout(10);

    http::client client(options);

    http::client::response response = client.post(request);

    try
    {
        cout << "status: " << http::status(response) << endl;
        cout << "body: " << http::body(response) << endl;
    }
    catch(...)
    {
    }
}

void callback(
        boost::shared_ptr<boost::asio::io_service>& io_service,
        boost::shared_ptr<string> text,
        const boost::iterator_range<const char*>& range,
        const boost::system::error_code& error)
{
    cout << "callback\n";

    if (!error)
    {
        if(!boost::empty(range)) //BUG? callback more than one time
        {
            *text = string(range.begin(), range.end());
            io_service->stop();
        }
        else
        {
            cout << "empty\n";
        }
    }
    else
    {
        cout << "error\n";
        io_service->stop();
    }
}

void do_async_post()
{
    http::client::request request("http://localhost:11140/test/tag/ok");
    request
        << boost::network::header("Connection", "close");

    boost::shared_ptr<boost::asio::io_service> iosvc = boost::make_shared<boost::asio::io_service>();

    http::client::options options;
    options
        .follow_redirects(true)
        .cache_resolved(true)
        .io_service(iosvc)
        .timeout(10);

    http::client client(options);

    boost::shared_ptr<string> text(new string());

    http::client::response response = client.post(
        request,
        string("{key:'value'}"),
        string("application/json"),
        boost::bind(&callback, iosvc, text, _1, _2));

    iosvc->run();

    cout << *text << endl;
}

int main()
{
	do_sync_post();

    do_async_post();

	return 0;
}
