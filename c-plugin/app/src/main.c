#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

typedef
    void (* show_func_t)(void);

int main()
{
    void *dlHandle = dlopen(MYPLUGIN_PATH, RTLD_LAZY);

    if(dlHandle == NULL)
    {
        fprintf(stderr, "dlopen error: %s\n", dlerror());
        exit(1);
    }

    show_func_t showFunc = (show_func_t)dlsym(dlHandle, "show");

    if(showFunc == NULL)
    {
        fprintf(stderr, "dlsym error: %s\n", dlerror());
        exit(1);
    }

    showFunc();

    const int result = dlclose(dlHandle);

    if(result != 0)
    {
        fprintf(stderr, "dlclose error: %s\n", dlerror());
        exit(1);
    }

    return 0;
}
