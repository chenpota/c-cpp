#include <iostream>

#include <cpprest/http_client.h>
#include <cpprest/base_uri.h>

using namespace std;

int main()
{
    const auto uri = web::uri("http://localhost:11140/test/tag/ok");

    web::json::value json_values;
    json_values["key"] = web::json::value::string("value");

    web::http::client::http_client(uri)
        .request(
            web::http::methods::POST,
            "",
            json_values)
        .then([](web::http::http_response rsp)
        {
            cout << rsp.status_code() << endl;

            for(const auto &header: rsp.headers())
            {
                cout << header.first << " = " << header.second << endl;
            }

            cout << rsp.extract_string().get();
        })
        .wait();

    return 0;
}
