#include <iostream>
#include <list>
#include <sstream>

#include <curlpp/Easy.hpp>
#include <curlpp/Exception.hpp>
#include <curlpp/Infos.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/cURLpp.hpp>

using namespace std;

int main()
{
    curlpp::Easy request;

    request.setOpt(
        new curlpp::options::Url(
            "http://localhost:11140/test/tag/ok"));

    const list<string> header {
        "Content-Type: application/json"
    };

    request.setOpt(new curlpp::options::HttpHeader(header));
    request.setOpt(new curlpp::options::Header(true));
    request.setOpt(new curlpp::options::PostFields("{key:'value'}"));
    request.setOpt(new curlpp::options::PostFieldSize(13));

    try
    {
        stringstream output;
        request.setOpt(cURLpp::Options::WriteStream(&output));
        request.perform();

        cout
            << curlpp::infos::EffectiveUrl::get(request)
            << endl
            << curlpp::infos::ResponseCode::get(request)
            << endl
            << output.str() // response header + body
            << endl;
    }
    catch(curlpp::LogicError & e) {
        std::cout << e.what() << std::endl;
    }
    catch(curlpp::RuntimeError & e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
