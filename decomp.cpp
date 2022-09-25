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

const char * const s_UbiSoftUbiini_005d8388_0_4_ = reinterpret_cast<char*>(0x005d8388); //"/UbiSoft/Ubi.ini"
const char * const s_UbiSoftUbiini_005d8388_4_4_ = reinterpret_cast<char*>(0x005d8388 + 4);
const char * const s_UbiSoftUbiini_005d8388_8_4_ = reinterpret_cast<char*>(0x005d8388 + 8);
const char * const s_UbiSoftUbiini_005d8388_12_4_ = reinterpret_cast<char*>(0x005d8388 + 12);
const char * const s_UbiSoftUbiini_005d8388 = reinterpret_cast<char*>(0x005d8388); //"/UbiSoft/Ubi.ini"

const char * const s_Directory_005d8374 = reinterpret_cast<char*>(0x005d837); //"Directory"
const char * const adapterSettingKey = reinterpret_cast<char*>(0x005d836c); //"Adapter"
const char * const identifierSettingKey = reinterpret_cast<char*>(0x005d8360); //"Identifier"
const char * const s_Gli_Mode_005d8354 = reinterpret_cast<char*>(0x005d8354); //"Gli_Mode"
char * const lpDefault_005d8380 = reinterpret_cast<char*>(0x005d8380); //lpDefault for GetPrivateProfileStringA
char * const lpDefault_005f1108 = reinterpret_cast<char*>(0x005f1108); //lpDefault for GetPrivateProfileStringA

char * const _String_00646760 = reinterpret_cast<char*>(0x00646760);
char * const DAT_0064675e = reinterpret_cast<char*>(0x0064675e);

unsigned int * const DAT_0079c028 = reinterpret_cast<unsigned int *>(0x0079c028);//DAT_0079c02

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

int initializeWindowsStuff(HINSTANCE param_1,int aStatusFromCaller,char *param_3,WORD wShowWindowIGNORED)
{
  char currentPathChar;
  LPSTR commandLine;
  char *windowsDirectoryPathTemp;
  DWORD mutexErrorCode;
  HANDLE hTargetProcessHandle;
  HANDLE hSourceHandle;
  HANDLE hSourceProcessHandle;
  HWND hWnd;
  int iVar5;
  int iVar6;
  int iVar7;
  int windowsPathLengthNegative;
  unsigned int uVar9;
  char *windowsDirectoryPathTemp2;
  HANDLE *lpTargetHandle;
  BOOL BVar11;
  DWORD dwOptions;
  tagRECT *lpRect;
  PVOID pvParam;
  HANDLE local_620;
  UINT UStack1564;
  tagRECT tStack1560;
  char settingsString [260];
  char local_400 [256];
  char local_300 [256];
  char local_200 [256];
  char local_100 [256];
  
  sprintf(mutexName,raymanArena1,raymanArena2);
  sprintf(className,raymanArena1,raymanArena2);
  sprintf(windowTextA2,pauseFormat,raymanArena2);
  sprintf(windowTextA3,restoreFormat,raymanArena2);
  if (aStatusFromCaller != 0) {
    return ExitCodeFail;
  }
  char windowsDirectoryPath [260];
  GetWindowsDirectoryA(windowsDirectoryPath,260);
  windowsPathLengthNegative = -1;
  windowsDirectoryPathTemp = windowsDirectoryPath;
  do {
    windowsDirectoryPathTemp2 = windowsDirectoryPathTemp;
    if (windowsPathLengthNegative == 0) break;
    windowsPathLengthNegative = windowsPathLengthNegative + -1;
    windowsDirectoryPathTemp2 = windowsDirectoryPathTemp + 1;
    currentPathChar = *windowsDirectoryPathTemp;
    windowsDirectoryPathTemp = windowsDirectoryPathTemp2;
  } while (currentPathChar != '\0');
  *(unsigned int *)(windowsDirectoryPathTemp2 + -1) = *(unsigned int*)s_UbiSoftUbiini_005d8388_0_4_;
  *(unsigned int *)(windowsDirectoryPathTemp2 + 3) = *(unsigned int*)s_UbiSoftUbiini_005d8388_4_4_;
  *(unsigned int *)(windowsDirectoryPathTemp2 + 7) = *(unsigned int*)s_UbiSoftUbiini_005d8388_8_4_;
  *(unsigned int *)(windowsDirectoryPathTemp2 + 11) = *(unsigned int*)s_UbiSoftUbiini_005d8388_12_4_;
  windowsDirectoryPathTemp2[15] = s_UbiSoftUbiini_005d8388[16];
  commandLine = GetCommandLineA();
  windowsDirectoryPathTemp = commandLine + 1;
  windowsPathLengthNegative = -(int)windowsDirectoryPathTemp;
  do {
    currentPathChar = *windowsDirectoryPathTemp;
    windowsDirectoryPathTemp[(int)(settingsString + windowsPathLengthNegative)] = currentPathChar;
    windowsDirectoryPathTemp = windowsDirectoryPathTemp + 1;
  } while (currentPathChar != '\0');
  windowsDirectoryPathTemp = strrchr(settingsString,'\\');
  if (windowsDirectoryPathTemp == (char *)0x0) {
    GetPrivateProfileStringA
              (raymanArena2, s_Directory_005d8374,lpDefault_005d8380,settingsString,
               0xff,windowsDirectoryPath);
    windowsPathLengthNegative = _stricmp(settingsString,lpDefault_005d8380);
  } else {
    windowsDirectoryPathTemp = strrchr(settingsString,'\\');
    *windowsDirectoryPathTemp = '\0';
    windowsPathLengthNegative = _chdir(settingsString);
    if (windowsPathLengthNegative != -1) goto LAB_004017f3;
    GetPrivateProfileStringA
              (raymanArena2,s_Directory_005d8374,lpDefault_005d8380,settingsString,
               0xff,windowsDirectoryPath);
    windowsPathLengthNegative = _stricmp(settingsString,lpDefault_005d8380);
  }
  if (windowsPathLengthNegative != 0) {
    _chdir(settingsString);
  }
LAB_004017f3:
  windowsPathLengthNegative = 0;
  do {
    currentPathChar = settingsString[windowsPathLengthNegative];
    _String_00646760[windowsPathLengthNegative] = currentPathChar;
    windowsPathLengthNegative = windowsPathLengthNegative + 1;
  } while (currentPathChar != '\0');
  _strlwr(_String_00646760);
  windowsPathLengthNegative = -1;
  windowsDirectoryPathTemp = _String_00646760;
  do {
    if (windowsPathLengthNegative == 0) break;
    windowsPathLengthNegative = windowsPathLengthNegative + -1;
    currentPathChar = *windowsDirectoryPathTemp;
    windowsDirectoryPathTemp = windowsDirectoryPathTemp + 1;
  } while (currentPathChar != '\0');
joined_r0x00401820:
  if (windowsPathLengthNegative != -2) {
    uVar9 = 0xffffffff; //are these things -1 or positive max?
    windowsDirectoryPathTemp = _String_00646760;
    do {
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      currentPathChar = *windowsDirectoryPathTemp;
      windowsDirectoryPathTemp = windowsDirectoryPathTemp + 1;
    } while (currentPathChar != '\0');
    if (DAT_0064675e[~uVar9] != '\\') goto LAB_0040185d;
    uVar9 = 0xffffffff;
    windowsDirectoryPathTemp = _String_00646760;
    do {
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      currentPathChar = *windowsDirectoryPathTemp;
      windowsDirectoryPathTemp = windowsDirectoryPathTemp + 1;
    } while (currentPathChar != '\0');
    DAT_0064675e[~uVar9] = 0;
    windowsPathLengthNegative = -1;
    windowsDirectoryPathTemp = _String_00646760;
    do {
      if (windowsPathLengthNegative == 0) break;
      windowsPathLengthNegative = windowsPathLengthNegative + -1;
      currentPathChar = *windowsDirectoryPathTemp;
      windowsDirectoryPathTemp = windowsDirectoryPathTemp + 1;
    } while (currentPathChar != '\0');
    goto joined_r0x00401820;
  }
LAB_0040185d:
  CreateMutexA(nullptr,true,mutexName);
  mutexErrorCode = GetLastError();
  if (mutexErrorCode == ERROR_ALREADY_EXISTS) {
    return ExitCodeFail;
  }
  GetWindowsDirectoryA(windowsDirectoryPath,260);
  windowsPathLengthNegative = -1;
  windowsDirectoryPathTemp = windowsDirectoryPath;
  do {
    windowsDirectoryPathTemp2 = windowsDirectoryPathTemp;
    if (windowsPathLengthNegative == 0) break;
    windowsPathLengthNegative = windowsPathLengthNegative + -1;
    windowsDirectoryPathTemp2 = windowsDirectoryPathTemp + 1;
    currentPathChar = *windowsDirectoryPathTemp;
    windowsDirectoryPathTemp = windowsDirectoryPathTemp2;
  } while (currentPathChar != '\0');
  *(unsigned int *)(windowsDirectoryPathTemp2 + -1) = *(unsigned int*)s_UbiSoftUbiini_005d8388_0_4_;
  *(unsigned int *)(windowsDirectoryPathTemp2 + 3) = *(unsigned int*)s_UbiSoftUbiini_005d8388_4_4_;
  *(unsigned int *)(windowsDirectoryPathTemp2 + 7) = *(unsigned int*)s_UbiSoftUbiini_005d8388_8_4_;
  *(unsigned int *)(windowsDirectoryPathTemp2 + 11) = *(unsigned int*)s_UbiSoftUbiini_005d8388_12_4_;
  windowsDirectoryPathTemp2[15] = s_UbiSoftUbiini_005d8388[16];
  GetPrivateProfileStringA
            (raymanArena2,adapterSettingKey,lpDefault_005f1108,local_400,0xff,windowsDirectoryPath
            );
  GetPrivateProfileStringA
            (raymanArena2,identifierSettingKey,lpDefault_005f1108,local_300,0xff,
             windowsDirectoryPath);
  GetPrivateProfileStringA
            (raymanArena2,s_Gli_Mode_005d8354,lpDefault_005f1108,local_100,0xff,
             windowsDirectoryPath);
  if (((local_400[0] != '\0') && (local_300[0] != '\0')) && (local_100[0] != '\0')) {
    *DAT_0079c028 = (unsigned int)(local_100[0] != '0');
    FUN_0042fa90();
    dwOptions = 2;
    BVar11 = 0;
    lpTargetHandle = &local_620;
    mutexErrorCode = 0;
    *(HINSTANCE*)0x0079c440 = param_1;
    hTargetProcessHandle = GetCurrentProcess();
    hSourceHandle = GetCurrentThread();
    hSourceProcessHandle = GetCurrentProcess();
    DuplicateHandle(hSourceProcessHandle,hSourceHandle,hTargetProcessHandle,lpTargetHandle,mutexErrorCode,
                    BVar11,dwOptions);
    *(HANDLE*)0x0079c448 = local_620;
    windowsDirectoryPathTemp = param_3;
    do {
      currentPathChar = *windowsDirectoryPathTemp;
      windowsDirectoryPathTemp[(int)0x0079c460 - (int)param_3] = currentPathChar;
      windowsDirectoryPathTemp = windowsDirectoryPathTemp + 1;
    } while (currentPathChar != '\0');
    SetErrorMode(1);
    windowsDirectoryPathTemp = strstr(param_3,(char *)0x005d8350);
    if (windowsDirectoryPathTemp == (char *)0x0) {
      FUN_00401000();
      windowsPathLengthNegative = FUN_00401b80(param_1,wShowWindowIGNORED,*DAT_0079c028);
      if (windowsPathLengthNegative == 0) {
        return ExitCodeFail;
      }
      FUN_004012f0();
      FUN_00401300();
      windowsPathLengthNegative = FUN_004b4bb0();
      if (windowsPathLengthNegative != 0) {
        FUN_004b1230();
        windowsPathLengthNegative = FUN_004b4c20();
        if (windowsPathLengthNegative == 0) {
          return ExitCodeFail;
        }
      }
      SND_PrintUsedStaticMemory();
      FUN_0040df70();
      lpRect = &tStack1560;
      hWnd = GetDesktopWindow();
      GetWindowRect(hWnd,lpRect);
      BVar11 = 1;
      windowsPathLengthNegative = FUN_0040db70();
      windowsPathLengthNegative = windowsPathLengthNegative + 0x20;
      iVar5 = FUN_0040db60();
      iVar5 = iVar5 + 0xc;
      iVar6 = FUN_0040db70();
      iVar6 = (tStack1560.bottom - iVar6) / 2;
      iVar7 = FUN_0040db60();
      MoveWindow((HWND)0x0079c444,(tStack1560.right - iVar7) / 2,iVar6,iVar5,windowsPathLengthNegative,BVar11);
      FUN_004010b0();
      SystemParametersInfoA(0x10,0,&UStack1564,0);
      SystemParametersInfoA(0x11,0,(PVOID)0x0,0);
      ShowCursor(0);
      pvParam = 0;
      SystemParametersInfoA(0x61,1,&pvParam,0);
      *(int*)0x0079c034 = 1;
      FUN_00401210();
      FUN_0040e130();
      pvParam = 0;
      SystemParametersInfoA(0x61,0,&pvParam,0);
      ShowCursor(1);
      SystemParametersInfoA(0x11,UStack1564,(PVOID)0x0,0);
      CloseHandle(local_620);
    }
    return 0;
  }
  sprintf(settingsString,(char*)0x005d8334,raymanArena2);
  sprintf(local_200,(char*)0x005d8320,raymanArena2);
  FUN_004024a0(settingsString,local_200,0);
  exit(ExitCodeFail);
}
