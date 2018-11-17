#pragma once

#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>

void DebugOut(wchar_t *fmt, ...);
//std::wstring s2ws(const std::string &str)
//{
//	auto strLength = (int)str.length() + 1;
//	auto len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), strLength, 0, 0);
//	auto buf = new wchar_t[len];
//
//	MultiByteToWideChar(CP_ACP, 0, str.c_str(), strLength, buf, len);
//	auto wideStr = std::wstring{ buf };
//	delete[] buf;
//
//	return wideStr;
//}