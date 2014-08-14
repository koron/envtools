#include <windows.h>

/*
 * Compile: cl /LD /MD envtools.c
 *
 * Use from Vim: libcallnr('envtools.dll', 0)
 */

typedef BOOL (__stdcall *PROCTYPE)(LPVOID *, BOOL);

static char retvalBuf[1024];

    _declspec(dllexport) int
Reload(int dummy)
{
    HMODULE hShell32;
    PROCTYPE pRegenerateUserEnvironment;
    LPVOID lpEnv;

    hShell32 = LoadLibrary("shell32.dll");
    if (hShell32 == NULL)
        return 1;

    pRegenerateUserEnvironment = (PROCTYPE)GetProcAddress(hShell32,
            "RegenerateUserEnvironment");
    if (pRegenerateUserEnvironment == NULL)
    {
        FreeLibrary(hShell32);
        return 2;
    }

    pRegenerateUserEnvironment(&lpEnv, TRUE);
    FreeLibrary(hShell32);
    return 3;
}

    _declspec(dllexport) char*
Get(char *name)
{
    GetEnvironmentVariableA(name, retvalBuf,
            sizeof(retvalBuf) / sizeof(retvalBuf[0]));
    return retvalBuf;
}
