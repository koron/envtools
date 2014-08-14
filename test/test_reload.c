#include <windows.h>
#include <stdio.h>

typedef int (*PROCTYPE)(int);

int main(int argc, char** argv) {
    HMODULE h;
    PROCTYPE p;

    h = LoadLibrary("envtools.dll");
    if (h == NULL) {
        printf("failed to load\n");
        return 1;
    }

    p = (PROCTYPE)GetProcAddress(h, "Reload");
    if (p == NULL) {
        FreeLibrary(h);
        printf("can't find proc\n");
        return 1;
    }

    printf("p=%p returns %d\n", p, p(0));
    FreeLibrary(h);
    return 0;
}
