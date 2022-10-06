#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif

#include <windows.h>
#include "frida/frida-gum.h"
#include "decomp.cpp"
#include "decomptest.cpp"

auto entry = reinterpret_cast<void(*)()>(0x004c6fc4);

void PauseDialog(const HINSTANCE hInstDll);
LRESULT CALLBACK WindowProc(const HWND hwnd, const UINT uMsg, const WPARAM wParam, const LPARAM lParam);

void __stdcall nothing()
{
    return;
}

extern __declspec(dllexport) INT APIENTRY DllMain(HINSTANCE hInstDll, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
        {
            gum_init_embedded();
            GumInterceptor *interceptor = gum_interceptor_obtain();

            gum_interceptor_replace(interceptor, (gpointer)entry, &nothing, nullptr, nullptr);

            link();

            void *originalCalls[1024];
            memset(originalCalls, 0, sizeof(originalCalls));
            memset(calls, 0, sizeof(calls));
            what();
            count = 0;
            FUN_00401650(nullptr, 0, "", 0);
            memcpy(originalCalls, calls, sizeof(calls));
            memset(calls, 0, sizeof(calls));
            count = 0;
            initializeWindowsStuff(nullptr, 0, "", 0);
            void *reimplementCalls[1024];
            memset(reimplementCalls, 0, sizeof(reimplementCalls));
            memcpy(reimplementCalls, calls, sizeof(calls));
            auto isMatching = memcmp(originalCalls, reimplementCalls, sizeof(originalCalls));

            //GumInterceptor *interceptor = gum_interceptor_obtain();

            gum_interceptor_replace(interceptor, (gpointer)FUN_00401650, &initializeWindowsStuff, nullptr, nullptr);

	        break;
        }
    }
    return true;
}
