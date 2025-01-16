#include <stdio.h>
#include <dlfcn.h>


int main(int argc, char *argv[]) {
    void *libfoo = dlopen("./libfoo.so", RTLD_NOW | RTLD_LOCAL);
    if (!libfoo)
        goto error;
    printf("libfoo at %p\n", libfoo);

    void *libbar = dlopen("./libbar.so", RTLD_NOW | RTLD_LOCAL);
    if (!libbar)
        goto error;
    printf("libbar at %p\n", libbar);

    void (*bar)() = dlsym(libbar, "bar");
    if (!bar)
        goto error;

    printf("calling bar()\n");
    bar();

    return 0;

error:
    fprintf(stderr, "error: %s\n", dlerror());
    return 1;
}
