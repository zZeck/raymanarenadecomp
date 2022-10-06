#include <windows.h>
#include <vector>
#include "frida/frida-gum.h"

void stub_FUN_0042fa90();
int stub_FUN_00401b80(HINSTANCE, WORD, unsigned int);
void stub_FUN_00401000();
void stub_FUN_004012f0();
void stub_FUN_00401300();
int stub_FUN_004b4bb0();
void stub_FUN_004b1230();
int stub_FUN_004b4c20();
void stub_SND_PrintUsedStaticMemory();
void stub_FUN_0040df70();
int stub_FUN_0040db70();
int stub_FUN_0040db60();
void stub_FUN_004010b0();
void stub_FUN_00401210();
void stub_FUN_0040e130();
void stub_FUN_004024a0(char*, char*, int);

UINT __stdcall stub_GetWindowsDirectoryA(LPSTR lpBuffer, UINT uSize);
LPSTR __stdcall stub_GetCommandLineA(VOID);
DWORD __stdcall stub_GetPrivateProfileStringA(
    LPCSTR lpAppName,
    LPCSTR lpKeyName,
    LPCSTR lpDefault,
    LPSTR lpReturnedString,
    DWORD nSize,
    LPCSTR lpFileName
);
HANDLE __stdcall stub_CreateMutexA(
    LPSECURITY_ATTRIBUTES lpMutexAttributes,
    BOOL bInitialOwner,
    LPCSTR lpName
);
DWORD __stdcall stub_GetLastError(VOID);
HANDLE __stdcall stub_GetCurrentProcess(VOID);
HANDLE __stdcall stub_GetCurrentThread(VOID);
BOOL __stdcall stub_DuplicateHandle(
    HANDLE hSourceProcessHandle,
    HANDLE hSourceHandle,
    HANDLE hTargetProcessHandle,
    LPHANDLE lpTargetHandle,
    DWORD dwDesiredAccess,
    BOOL bInheritHandle,
    DWORD dwOptions
);
UINT __stdcall stub_SetErrorMode(UINT uMode);
int __cdecl stub__chdir(const char *_Path);
int __cdecl stub_sprintf(char *_Buffer, const char *_Format, ...);
void __cdecl stub_exit(int _Code);
HWND __stdcall stub_GetDesktopWindow(VOID);
BOOL __stdcall stub_GetWindowRect(HWND hWnd, LPRECT lpRect);
BOOL __stdcall stub_MoveWindow(
    HWND hWnd,
    int X,
    int Y,
    int nWidth,
    int nHeight,
    BOOL bRepaint);
BOOL __stdcall stub_SystemParametersInfoA(
    UINT uiAction,
    UINT uiParam,
    PVOID pvParam,
    UINT fWinIni);
int __stdcall stub_ShowCursor(BOOL bShow);
BOOL __stdcall stub_CloseHandle(HANDLE hObject);
char *__cdecl stub_strrchr(char *_String, int _Ch);
char *__cdecl stub__strlwr(char *_String);
int __cdecl stub__stricmp(const char *_String1, const char *_String2);
const char *__cdecl stub_strstr(const char *_Str, const char *_SubStr);


void what() {
    GumInterceptor *interceptor = gum_interceptor_obtain();
    gum_interceptor_replace(interceptor, (gpointer)0x0042fa90, &stub_FUN_0042fa90, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)0x00401b80, &stub_FUN_00401b80, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)0x00401000, &stub_FUN_00401000, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)0x004012f0, &stub_FUN_004012f0, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)0x00401300, &stub_FUN_00401300, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)0x004b4bb0, &stub_FUN_004b4bb0, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)0x004b1230, &stub_FUN_004b1230, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)0x004b4c20, &stub_FUN_004b4c20, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)0x0050f520, &stub_SND_PrintUsedStaticMemory, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)0x0040df70, &stub_FUN_0040df70, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)0x0040db70, &stub_FUN_0040db70, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)0x0040db60, &stub_FUN_0040db60, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)0x004010b0, &stub_FUN_004010b0, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)0x00401210, &stub_FUN_00401210, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)0x0040e130, &stub_FUN_0040e130, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)0x004024a0, &stub_FUN_004024a0, nullptr, nullptr);

    auto getWindowsDirectoryA = gum_module_find_export_by_name(nullptr, "GetWindowsDirectoryA");
    auto getCommandLineA = gum_module_find_export_by_name(nullptr, "GetCommandLineA");
    auto sprintf = gum_module_find_export_by_name("MSVCRT", "sprintf");
    auto _chdir = gum_module_find_export_by_name("MSVCRT", "_chdir");
    auto strstr = gum_module_find_export_by_name("MSVCRT", "strstr");
    auto strrchr = gum_module_find_export_by_name("MSVCRT", "strrchr");
    auto _strlwr = gum_module_find_export_by_name("MSVCRT", "_strlwr");
    auto _stricmp = gum_module_find_export_by_name("MSVCRT", "_stricmp");
    auto createMutexA = gum_module_find_export_by_name(nullptr, "CreateMutexA");
    auto getLastError = gum_module_find_export_by_name(nullptr, "GetLastError");
    auto getPrivateProfileStringA = gum_module_find_export_by_name(nullptr, "GetPrivateProfileStringA");
    auto getCurrentProcess = gum_module_find_export_by_name(nullptr, "GetCurrentProcess");
    auto getCurrentThread = gum_module_find_export_by_name(nullptr, "GetCurrentThread");
    auto duplicateHandle = gum_module_find_export_by_name(nullptr, "DuplicateHandle");
    auto setErrorMode = gum_module_find_export_by_name(nullptr, "SetErrorMode");
    auto exit = gum_module_find_export_by_name("MSVCRT", "exit");
    auto getDesktopWindow = gum_module_find_export_by_name(nullptr, "GetDesktopWindow");
    auto getWindowRect = gum_module_find_export_by_name(nullptr, "GetWindowRect");
    auto moveWindow = gum_module_find_export_by_name(nullptr, "MoveWindow");
    auto systemParametersInfoA = gum_module_find_export_by_name(nullptr, "SystemParametersInfoA");
    auto showCursor = gum_module_find_export_by_name(nullptr, "ShowCursor");
    auto closeHandle = gum_module_find_export_by_name(nullptr, "CloseHandle");

    gum_interceptor_replace(interceptor, (gpointer)getWindowsDirectoryA, &stub_GetWindowsDirectoryA, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)getCommandLineA, &stub_GetCommandLineA, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)sprintf, &stub_sprintf, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)strstr, &stub_strstr, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)strrchr, &stub_strrchr, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)_strlwr, &stub__strlwr, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)_stricmp, &stub__stricmp, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)_chdir, &stub__chdir, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)createMutexA, &stub_CreateMutexA, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)getLastError, &stub_GetLastError, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)getPrivateProfileStringA, &stub_GetPrivateProfileStringA, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)getCurrentProcess, &stub_GetCurrentProcess, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)getCurrentThread, &stub_GetCurrentThread, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)duplicateHandle, &stub_DuplicateHandle, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)setErrorMode, &stub_SetErrorMode, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)exit, &stub_exit, nullptr, nullptr); //this is not patching MSVCRT!exit somehow
    gum_interceptor_replace(interceptor, (gpointer)getDesktopWindow, &stub_GetDesktopWindow, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)getWindowRect, &stub_GetWindowRect, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)moveWindow, &stub_MoveWindow, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)systemParametersInfoA, &stub_SystemParametersInfoA, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)showCursor, &stub_ShowCursor, nullptr, nullptr);
    gum_interceptor_replace(interceptor, (gpointer)closeHandle, &stub_CloseHandle, nullptr, nullptr);
    
}
auto FUN_00401650 = reinterpret_cast<int(*)(HINSTANCE hInstance,int aStatusFromCaller, const char * const param_3,WORD wShowWindowIGNORED)>(0x00401650);

void *calls[1024];
int count = 0;

void stub_FUN_0042fa90() {
    calls[count] = (stub_FUN_0042fa90);
    count += 1;
    return;
}
int stub_FUN_00401b80(HINSTANCE, WORD, unsigned int){
    calls[count] = (stub_FUN_00401b80);
    count += 1;
    return 1;
}
void stub_FUN_00401000() {
    calls[count] = (stub_FUN_00401000);
    count += 1;
    return;
}
void stub_FUN_004012f0() {
    calls[count] = (stub_FUN_004012f0);
    count += 1;
    return;
}
void stub_FUN_00401300() {
    calls[count] = (stub_FUN_00401300);
    count += 1;
    return;
}
int stub_FUN_004b4bb0() {
    calls[count] = (stub_FUN_004b4bb0);
    count += 1;
    return 0;
}
void stub_FUN_004b1230() {
    calls[count] = (stub_FUN_004b1230);
    count += 1;
    return;
}
int stub_FUN_004b4c20() {
    calls[count] = (stub_FUN_004b4c20);
    count += 1;
    return 1;
}
void stub_SND_PrintUsedStaticMemory() {
    calls[count] = (stub_SND_PrintUsedStaticMemory);
    count += 1;
    return;
}
void stub_FUN_0040df70() {
    calls[count] = (stub_FUN_0040df70);
    count += 1;
    return;
}
int stub_FUN_0040db70() {
    calls[count] = (stub_FUN_00401000);
    count += 1;
    return 0;
}
int stub_FUN_0040db60() {
    calls[count] = (stub_FUN_0040db60);
    count += 1;
    return 0;
}
void stub_FUN_004010b0() {
    calls[count] = (stub_FUN_004010b0);
    count += 1;
    return;
}
void stub_FUN_00401210() {
    calls[count] = (stub_FUN_00401210);
    count += 1;
    return;
}
void stub_FUN_0040e130() {
    calls[count] = (stub_FUN_0040e130);
    count += 1;
    return;
}
void stub_FUN_004024a0(char*, char*, int) {
    calls[count] = (stub_FUN_004024a0);
    count += 1;
    return;
}


UINT __stdcall stub_GetWindowsDirectoryA(LPSTR lpBuffer, UINT uSize) {
    calls[count] = (stub_GetWindowsDirectoryA);
    count += 1;
    return 0;
}
char someStr[] = "blahblah/blah";
LPSTR __stdcall stub_GetCommandLineA(VOID){
    calls[count] = (stub_GetCommandLineA);
    count += 1;
    return someStr;
}
DWORD __stdcall stub_GetPrivateProfileStringA(
    LPCSTR lpAppName,
    LPCSTR lpKeyName,
    LPCSTR lpDefault,
    LPSTR lpReturnedString,
    DWORD nSize,
    LPCSTR lpFileName
) {
    calls[count] = (stub_GetPrivateProfileStringA);
    count += 1;
    strcpy(lpReturnedString, "blah");
    return 1;
}
HANDLE __stdcall stub_CreateMutexA(
    LPSECURITY_ATTRIBUTES lpMutexAttributes,
    BOOL bInitialOwner,
    LPCSTR lpName
) {
    calls[count] = (stub_CreateMutexA);
    count += 1;
    return (HANDLE)1;
}
DWORD __stdcall stub_GetLastError(VOID) {
    calls[count] = (stub_GetLastError);
    count += 1;
    return 1;
}
HANDLE __stdcall stub_GetCurrentProcess(VOID) {
    calls[count] = (stub_GetCurrentProcess);
    count += 1;
    return (HANDLE)1;
}
HANDLE __stdcall stub_GetCurrentThread(VOID) {
    calls[count] = (stub_GetCurrentThread);
    count += 1;
    return (HANDLE)1;
}
BOOL __stdcall stub_DuplicateHandle(
    HANDLE hSourceProcessHandle,
    HANDLE hSourceHandle,
    HANDLE hTargetProcessHandle,
    LPHANDLE lpTargetHandle,
    DWORD dwDesiredAccess,
    BOOL bInheritHandle,
    DWORD dwOptions
) {
    calls[count] = (stub_DuplicateHandle);
    count += 1;
    return true;
}
UINT __stdcall stub_SetErrorMode(UINT uMode) {
    calls[count] = (stub_SetErrorMode);
    count += 1;
    return 1;
}
void __cdecl stub_exit(int _Code) {
    return;
}
int __cdecl stub__chdir(const char *_Path) { 
    return 1;
}
int __cdecl stub_sprintf(char *_Buffer, const char *_Format, ...) {
    return 1;
}
HWND __stdcall stub_GetDesktopWindow(VOID) {
    calls[count] = (stub_GetDesktopWindow);
    count += 1;
    return (HWND)1;
}
BOOL __stdcall stub_GetWindowRect(HWND hWnd, LPRECT lpRect) {
    calls[count] = (stub_GetWindowRect);
    count += 1;
    return true;
}
BOOL __stdcall stub_MoveWindow(
    HWND hWnd,
    int X,
    int Y,
    int nWidth,
    int nHeight,
    BOOL bRepaint) {
    calls[count] = (stub_MoveWindow);
    count += 1;
    return true;
}
BOOL __stdcall stub_SystemParametersInfoA(
    UINT uiAction,
    UINT uiParam,
    PVOID pvParam,
    UINT fWinIni) {
    calls[count] = (stub_SystemParametersInfoA);
    count += 1;
    return true;
}
int __stdcall stub_ShowCursor(BOOL bShow) {
    calls[count] = (stub_ShowCursor);
    count += 1;
    return 0;
}
BOOL __stdcall stub_CloseHandle(HANDLE hObject) {
    calls[count] = (stub_CloseHandle);
    count += 1;
    return true;
}

char *__cdecl stub_strrchr(char *_String, int _Ch) {
    return _String;
}
char *__cdecl stub__strlwr(char *_String) {
    return _String;
}
int __cdecl stub__stricmp(const char *_String1, const char *_String2) {
    return 0;
}
const char *__cdecl stub_strstr(const char *_Str, const char *_SubStr) {
    return _Str;
}




