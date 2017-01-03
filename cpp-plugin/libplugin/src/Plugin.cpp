#include <Plugin.hpp>

namespace libplugin
{
    Plugin::Plugin()
    {
    }

    Plugin::~Plugin()
    {
    }

    void
        Plugin::execute()
    {
        this->do_execute();
    }
}
