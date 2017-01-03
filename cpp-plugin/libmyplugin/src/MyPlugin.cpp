#include <iostream>

#include <MyPlugin.hpp>

namespace myplugin
{
    using libplugin::Plugin;

    using std::cout;
    using std::endl;

    MyPlugin::MyPlugin()
        : Plugin()
    {
    }

    MyPlugin::~MyPlugin()
    {
    }

    void
        MyPlugin::do_execute()
    {
        cout << "MyPlugin::do_execute()" << endl;
    }

    extern "C" Plugin *
        create()
    {
        return new MyPlugin();
    }
}
