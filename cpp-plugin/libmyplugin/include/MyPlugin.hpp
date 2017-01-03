#ifndef _MY_PLUGIN_HPP_
#define _MY_PLUGIN_HPP_

#include <Plugin.hpp>

namespace myplugin
{
    class MyPlugin: public libplugin::Plugin
    {
    public:
        MyPlugin();

        virtual ~MyPlugin();

        virtual void
            do_execute();
    };
}

extern "C" libplugin::Plugin *
    create();

#endif