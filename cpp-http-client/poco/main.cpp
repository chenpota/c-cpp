#include <iostream>
#include <sstream>

#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/NetException.h>
#include <Poco/StreamCopier.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>

using namespace std;

int main()
{
    Poco::URI uri("http://localhost:11140/test/tag/ok");

    Poco::Net::HTTPClientSession session(
        uri.getHost(),
        uri.getPort());

    string path(uri.getPathAndQuery());
    if(path.empty())
        path = "/";

    Poco::Net::HTTPRequest req(
        Poco::Net::HTTPRequest::HTTP_POST,
        path,
        Poco::Net::HTTPMessage::HTTP_1_1);
    req.setContentType("application/json");

    try
    {
        req.setContentLength(13);
        ostream& os = session.sendRequest(req);
        os << "{key:'value'}";

        Poco::Net::HTTPResponse res;
        istream &is = session.receiveResponse(res);

        // response status
        cout << res.getStatus() << " " << res.getReason() << endl;

        // response header
        for(auto ax = res.begin(); ax != res.end(); ++ax)
        {
            const auto &name = ax->first;
            const auto &value = ax->second;
            cout << name << " = " << value << endl << flush;
        }

        // response body
        stringstream ss;
        Poco::StreamCopier::copyStream(is, ss);
        const auto response = ss.str();
        cout << response << endl;
    }
    catch(Poco::Net::ConnectionRefusedException ex)
    {
        cout << ex.displayText() << endl;
        return 1;
    }
    catch(Poco::Net::NetException ex)
    {
        cout << ex.displayText() << endl;
        return 1;
    }

    return 0;
}
