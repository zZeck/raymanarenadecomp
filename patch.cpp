#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif

#include <windows.h>
#include "frida/frida-gum.h"
#include "decomp.cpp"

extern __declspec(dllexport) INT APIENTRY DllMain(HINSTANCE hInstDll, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
        {
            gum_init_embedded();

            GumInterceptor *interceptor = gum_interceptor_obtain();

            gum_interceptor_replace(interceptor, (gpointer)0x00401650, &initializeWindowsStuff, nullptr, nullptr);

	        break;
        }
    }
    return true;
}
