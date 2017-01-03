#include <iostream>

#include <MyPlugin.hpp>

namespace myplugin
{
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
}

extern "C" {
    libplugin::Plugin *
        create()
    {
        return new myplugin::MyPlugin();
    }
}
