#include <windows.h>
#include <stdio.h>
#include <direct.h>


constexpr int ExitCodeFail = -1;

char * const mutexName = reinterpret_cast<char*>(0x0079c040);
char * const className = reinterpret_cast<char*>(0x0079c140);
char * const windowTextA2 = reinterpret_cast<char*>(0x0079c240);
char * const windowTextA3 = reinterpret_cast<char*>(0x0079c340);

const char * const raymanArena1 = reinterpret_cast<char*>(0x005d83cc); //"Rayman Arena"
const char * const raymanArena2 = reinterpret_cast<char*>(0x005d83d0); //"Rayman Arena"

const char * const pauseFormat = reinterpret_cast<char*>(0x005d83c0); //"%s - pause"
const char * const restoreFormat = reinterpret_cast<char*>(0x005d839c); //"%s - restoring data... please wait"
const char * const pleaseRunSetup = reinterpret_cast<char*>(0x005d8334); //"Please run the %s setup."
const char * const notInitialized = reinterpret_cast<char*>(0x005d8320); //"%s not initialized."

const char * const s_UbiSoftUbiini_005d8388_0_4_ = reinterpret_cast<decltype(s_UbiSoftUbiini_005d8388_0_4_)>(0x005d8388); //"/UbiSoft/Ubi.ini"
const char * const s_UbiSoftUbiini_005d8388_4_4_ = reinterpret_cast<char*>(0x005d8388 + 4);
const char * const s_UbiSoftUbiini_005d8388_8_4_ = reinterpret_cast<char*>(0x005d8388 + 8);
const char * const s_UbiSoftUbiini_005d8388_12_4_ = reinterpret_cast<char*>(0x005d8388 + 12);
const char * const s_UbiSoftUbiini_005d8388 = reinterpret_cast<char*>(0x005d8388); //"/UbiSoft/Ubi.ini"

const char * const s_Directory_005d8374 = reinterpret_cast<char*>(0x005d837); //"Directory"
const char * const adapterSettingKey = reinterpret_cast<char*>(0x005d836c); //"Adapter"
const char * const identifierSettingKey = reinterpret_cast<char*>(0x005d8360); //"Identifier"
const char * const s_Gli_Mode_005d8354 = reinterpret_cast<char*>(0x005d8354); //"Gli_Mode"
char * const None = reinterpret_cast<char*>(0x005d8380); //"None"
char * const lpDefault_005f1108 = reinterpret_cast<char*>(0x005f1108); //lpDefault for GetPrivateProfileStringA

char * const arenaDirectoryPath = reinterpret_cast<char*>(0x00646760);

unsigned int * const firstCharOfGliMode = reinterpret_cast<unsigned int *>(0x0079c028);//DAT_0079c02
HANDLE* DAT_0079c440 = reinterpret_cast<HANDLE*>(0x0079c440);//DAT_0079c440
HANDLE* duplicatedHandle = reinterpret_cast<HANDLE*>(0x0079c448);//_DAT_0079c448
char * const DAT_0079c460 = reinterpret_cast<char *>(0x0079c460);//DAT_0079c460
char * const _SubStr_005d8350 = reinterpret_cast<char * const>(0x005d8350);//_SubStr_005d8350
HWND windowHwnd = reinterpret_cast<HWND>(0x0079c444);//DAT_0079c444
unsigned int * const DAT_0079c034 = reinterpret_cast<unsigned int *>(0x0079c034);//DAT_0079c034

auto FUN_0042fa90 = reinterpret_cast<void(*)()>(0x0042fa90);
auto FUN_00401b80 = reinterpret_cast<int(*)(HINSTANCE, WORD, unsigned int)>(0x00401b80);
auto FUN_00401000 = reinterpret_cast<void(*)()>(0x00401000);
auto FUN_004012f0 = reinterpret_cast<void(*)()>(0x004012f0);
auto FUN_00401300 = reinterpret_cast<void(*)()>(0x00401300);
auto FUN_004b4bb0 = reinterpret_cast<int(*)(void)>(0x004b4bb0);
auto FUN_004b1230 = reinterpret_cast<void(*)()>(0x004b4bb0);
auto FUN_004b4c20 = reinterpret_cast<int(*)(void)>(0x004b4c20);
auto SND_PrintUsedStaticMemory = reinterpret_cast<void(*)()>(0x0050f520); //symbol not accurate. Multiple symbols point here. Function immediately returns.
auto FUN_0040df70 = reinterpret_cast<void(*)()>(0x0040df70);
auto FUN_0040db70 = reinterpret_cast<int(*)(void)>(0x0040db70);
auto FUN_0040db60 = reinterpret_cast<int(*)(void)>(0x0040db60);
auto FUN_004010b0 = reinterpret_cast<void(*)()>(0x004010b0);
auto FUN_00401210 = reinterpret_cast<void(*)()>(0x00401210);
auto FUN_0040e130 = reinterpret_cast<void(*)()>(0x0040e130);
auto FUN_004024a0 = reinterpret_cast<void(*)(char*, char*, int)>(0x004024a0);

char* (*msvcrt_strrchr)(char* const, char const);
decltype(_chdir) *msvcrt__chdir;
decltype(_strlwr) *msvcrt__strlwr;
decltype(_stricmp) *msvcrt__stricmp;
decltype(exit) *msvcrt_exit;
decltype(sprintf) *msvcrt_sprintf;
char* (*msvcrt_strstr)(char const* const, char const* const);

void link() {
  auto msvcrt = LoadLibrary(L"msvcrt.dll");
  msvcrt_strrchr = reinterpret_cast<decltype(msvcrt_strrchr)>(GetProcAddress(msvcrt, "strrchr"));
  msvcrt__chdir = reinterpret_cast<decltype(msvcrt__chdir)>(GetProcAddress(msvcrt, "_chdir"));
  msvcrt__strlwr = reinterpret_cast<decltype(msvcrt__strlwr)>(GetProcAddress(msvcrt, "_strlwr"));
  msvcrt__stricmp = reinterpret_cast<decltype(msvcrt__stricmp)>(GetProcAddress(msvcrt, "_stricmp"));
  msvcrt_exit = reinterpret_cast<decltype(msvcrt_exit)>(GetProcAddress(msvcrt, "exit"));
  msvcrt_sprintf = reinterpret_cast<decltype(msvcrt_sprintf)>(GetProcAddress(msvcrt, "sprintf"));
  msvcrt_strstr = reinterpret_cast<decltype(msvcrt_strstr)>(GetProcAddress(msvcrt, "strstr"));
}

int initializeWindowsStuff(HINSTANCE hInstance,int aStatusFromCaller, const char * const param_3,WORD wShowWindowIGNORED)
{
  msvcrt_sprintf(mutexName,raymanArena1,raymanArena2);
  msvcrt_sprintf(className,raymanArena1,raymanArena2);
  msvcrt_sprintf(windowTextA2,pauseFormat,raymanArena2);
  msvcrt_sprintf(windowTextA3,restoreFormat,raymanArena2);

  if (aStatusFromCaller != 0) return ExitCodeFail;

  char ubiIniPath [260];
  GetWindowsDirectoryA(ubiIniPath,260);
  auto endPosition = strnlen_s(ubiIniPath, SIZE_MAX);
  strcpy(ubiIniPath + endPosition, s_UbiSoftUbiini_005d8388_0_4_);

  auto commandLine = GetCommandLineA();//this returns a string in ""
  char stringScratchSpace [260];
  strcpy(stringScratchSpace, commandLine + 1);//moves past the first "

  auto lastSlashPointer = msvcrt_strrchr(stringScratchSpace,'\\');
  if (lastSlashPointer == nullptr) { //not sure how the commandLine could have no slash in it.
    GetPrivateProfileStringA
              (raymanArena2, s_Directory_005d8374,None,stringScratchSpace,
               0xff,ubiIniPath);
    auto settingsCompareDefaultResult = msvcrt__stricmp(stringScratchSpace,None);
      auto gotRequestedSetting = settingsCompareDefaultResult != 0;
      if (gotRequestedSetting) {
        msvcrt__chdir(stringScratchSpace);
      }
  } else {
    *lastSlashPointer = '\0'; //terminate path at last slash, just before the slash. This will also remove the trailing " from the command line
    auto changedDirectoryResult = msvcrt__chdir(stringScratchSpace);
    auto changedWorkingDirectory = changedDirectoryResult != -1;
    if (!changedWorkingDirectory)
    {
      GetPrivateProfileStringA
              (raymanArena2,s_Directory_005d8374,None,stringScratchSpace,
               0xff,ubiIniPath);
      auto settingsCompareDefaultResult = msvcrt__stricmp(stringScratchSpace,None);
      auto gotRequestedSetting = settingsCompareDefaultResult != 0;
      if (gotRequestedSetting) {
        msvcrt__chdir(stringScratchSpace);
      }
    }
  }
  strcpy(arenaDirectoryPath, stringScratchSpace);
  msvcrt__strlwr(arenaDirectoryPath);
  for(auto pathIndexFromBack = strnlen_s(arenaDirectoryPath, SIZE_MAX) -1; pathIndexFromBack >= 0; pathIndexFromBack -= 1) {
    auto isBackslash = arenaDirectoryPath[pathIndexFromBack] == '\\';
    if (!isBackslash) break;
    arenaDirectoryPath[pathIndexFromBack] = '\0';
  }

  CreateMutexA(nullptr,true,mutexName);
  if (GetLastError() == ERROR_ALREADY_EXISTS) return ExitCodeFail;

  GetWindowsDirectoryA(ubiIniPath,260);
  auto endPosition2 = strnlen_s(ubiIniPath, SIZE_MAX);
  strcpy(ubiIniPath + endPosition2, s_UbiSoftUbiini_005d8388_0_4_);
  char adapterNumber [256];
  GetPrivateProfileStringA
            (raymanArena2,adapterSettingKey,lpDefault_005f1108,adapterNumber,0xff,ubiIniPath
            );
  char displayDeviceGuid [256];
  GetPrivateProfileStringA
            (raymanArena2,identifierSettingKey,lpDefault_005f1108,displayDeviceGuid,0xff,
             ubiIniPath);
  char gliMode [256];
  GetPrivateProfileStringA
            (raymanArena2,s_Gli_Mode_005d8354,lpDefault_005f1108,gliMode,0xff,
             ubiIniPath);

  if (((adapterNumber[0] == '\0') || (displayDeviceGuid[0] == '\0')) || (gliMode[0] == '\0')) {
    msvcrt_sprintf(stringScratchSpace,pleaseRunSetup,raymanArena2);
    char raymanArenaNotInitialized [256];
    msvcrt_sprintf(raymanArenaNotInitialized,notInitialized,raymanArena2);
    FUN_004024a0(stringScratchSpace,raymanArenaNotInitialized,0);
    msvcrt_exit(ExitCodeFail);
  }

  *firstCharOfGliMode = (unsigned int)(gliMode[0] != '0');
  FUN_0042fa90();
  *DAT_0079c440 = hInstance;
  auto currentProcessHandle = GetCurrentProcess();
  auto currentThread = GetCurrentThread();
  DuplicateHandle(currentProcessHandle,currentThread,currentProcessHandle,duplicatedHandle,0,false,DUPLICATE_SAME_ACCESS);
  strcpy(DAT_0079c460, param_3);
  SetErrorMode(1);
  auto lastwhat = msvcrt_strstr(param_3,_SubStr_005d8350);

  if (lastwhat != nullptr) return 0;

  FUN_00401000();
  auto someCode = FUN_00401b80(hInstance,wShowWindowIGNORED,*firstCharOfGliMode);

  if (someCode == 0) return ExitCodeFail;

  FUN_004012f0();
  FUN_00401300();
  someCode = FUN_004b4bb0();
  if (someCode != 0) {
    FUN_004b1230();
    someCode = FUN_004b4c20();
    if (someCode == 0) return ExitCodeFail;
  }
  SND_PrintUsedStaticMemory();
  FUN_0040df70();
  auto hWnd = GetDesktopWindow();
  tagRECT lpRect;
  GetWindowRect(hWnd,&lpRect);
  auto height = FUN_0040db70() + 0x20;
  auto width = FUN_0040db60() + 12;
  auto yPos = (lpRect.bottom - FUN_0040db70()) / 2;
  auto xPos = (lpRect.right - FUN_0040db60()) / 2;
  MoveWindow(windowHwnd,xPos,yPos,width,height,true);
  FUN_004010b0();
  unsigned int screenSaverState;
  SystemParametersInfoA(SPI_GETSCREENSAVEACTIVE,0,&screenSaverState,0);
  SystemParametersInfoA(SPI_SETSCREENSAVEACTIVE,false,nullptr,0);
  ShowCursor(0);
  PVOID pvParam;
  SystemParametersInfoA(SPI_SETSCREENSAVERRUNNING,true,&pvParam,0);
  *DAT_0079c034 = 1;
  FUN_00401210();
  FUN_0040e130();
  pvParam = nullptr;
  SystemParametersInfoA(SPI_SETSCREENSAVERRUNNING,false,&pvParam,0);
  ShowCursor(1);
  SystemParametersInfoA(SPI_SETSCREENSAVEACTIVE,screenSaverState,nullptr,0);
  CloseHandle(duplicatedHandle);

  return 0;
}
