#include <dlfcn.h>
#include <stdlib.h>

#include <iostream>

#include <Plugin.hpp>

using libplugin::Plugin;

using std::cerr;
using std::endl;

typedef
    Plugin * (*create_plugin_t)();

int main()
{
    void *dlHandle = dlopen(MYPLUGIN_PATH, RTLD_LAZY);

    if(dlHandle == NULL)
    {
        cerr << "dlopen error: " << dlerror() << endl;
        exit(1);
    }

    create_plugin_t create_plugin = (create_plugin_t)dlsym(dlHandle, "create");

    if(create_plugin == NULL)
    {
        cerr << "dlsym error: " << dlerror() << endl;
        exit(1);
    }

    Plugin *plugin = create_plugin();

    plugin->execute();

    const int result = dlclose(dlHandle);

    if(result != 0)
    {
        cerr << "dlclose error: " << dlerror() << endl;
        exit(1);
    }

    return 0;
}
