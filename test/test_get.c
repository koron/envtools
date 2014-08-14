#include <windows.h>
#include <stdio.h>

typedef char* (*PROCTYPE)(char*);

int main(int argc, char** argv) {
    HMODULE h;
    PROCTYPE p;

    h = LoadLibrary("envtools.dll");
    if (h == NULL) {
        printf("failed to load\n");
        return 1;
    }

    p = (PROCTYPE)GetProcAddress(h, "Get");
    if (p == NULL) {
        FreeLibrary(h);
        printf("can't find proc\n");
        return 1;
    }

    printf("p=%p returns %s\n", p, p("OS"));
    FreeLibrary(h);
    return 0;
}
