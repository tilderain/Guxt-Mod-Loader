#pragma once

#include <windows.h>

#include "mod_loader.h"

void InitMod(void);

__declspec(dllexport) void ModEntry(HMODULE mod_loader_hmodule)
{
	WriteRelativeAddress = (void (*)(const int, const void* const))GetProcAddress(mod_loader_hmodule, "WriteRelativeAddress");
	WriteByte = (void (*)(const int, const char))GetProcAddress(mod_loader_hmodule, "WriteByte");
	WriteWord = (void (*)(const int, const short))GetProcAddress(mod_loader_hmodule, "WriteWord");
	WriteLong = (void (*)(const int, const int))GetProcAddress(mod_loader_hmodule, "WriteLong");
	WriteJump = (void (*)(const int, const void* const))GetProcAddress(mod_loader_hmodule, "WriteJump");
	WriteCall = (void (*)(const int, const void* const))GetProcAddress(mod_loader_hmodule, "WriteCall");
	FixDoorEnterBug = (void (*)(void))GetProcAddress(mod_loader_hmodule, "FixDoorEnterBug");

	InitMod();
}
