This is a Rayman Arena decompilation project. The project uses Frida to replace routines in the game.
The process will be decompilation by Ghidra decompiler, edit into legal C++ (unless I can get Ghidra to output it), clean up with Clang tools, then finish by hand.
Th code is C++ without classes or templates.
C++ will be used as enhanced C at least until completed, to make the binary easier to use for patches and to minimize work.
The plan is to focus on areas of the game of the most use for interesting modding first.
Since the project uses Frida for patching, this would allow interesting extensions before full completion.
Frida may also be used to fuzz the original routines, trace and capture game data, and compare or use this information with the reimplementation.

In the visual studio native tools command prompt (or similar environment):

Debug
cl.exe /std:c++17 /Zi /LD patch.cpp /I\frida  /link /OUT:arenadecomp.asi user32.lib Advapi32.lib Ole32.lib Shell32.lib IPHLPAPI.lib Ws2_32.lib frida/frida-gum.lib

Release
cl.exe /std:c++17 /LD patch.cpp /I\frida  /link /OUT:arenadecomp.asi user32.lib Advapi32.lib Ole32.lib Shell32.lib IPHLPAPI.lib Ws2_32.lib frida/frida-gum.lib

Use [Ultimate Asi Loader](https://github.com/ThirteenAG/Ultimate-ASI-Loader), with rayman arena and put arenadecomp.asi into the plugins directory.

You may want to rename dinput8.dll from the asi loader to one of the other supported dll names.
The controller patch for arena on the pcwiki replaces dinput8.dll
