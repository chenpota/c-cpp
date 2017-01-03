#ifndef _PLUGIN_HPP_
#define _PLUGIN_HPP_

namespace libplugin
{
    class Plugin
    {
    public:
        Plugin();

        virtual ~Plugin();

        void
            execute();

    private:
        virtual void
            do_execute() = 0;
    };
}

#endif