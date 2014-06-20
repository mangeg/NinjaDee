#pragma once

#include "pch.h"

inline std::wstring TrimLeft(const std::wstring &str)
{
	auto ret = str;
	ret.erase(ret.begin(), find_if(ret.begin(), ret.end(), not1(std::ptr_fun<int, int>(isspace))));
	return ret;
}
inline std::wstring TrimRight(const std::wstring &str)
{
	auto ret = str;
	ret.erase(find_if(ret.rbegin(), ret.rend(), not1(std::ptr_fun<int, int>(isspace))).base(), ret.end());
	return ret;
}
inline std::wstring Trim(const std::wstring &str, const WCHAR &c = L'')
{
	auto ret = str;
	ret = TrimLeft(ret);
	ret = TrimRight(ret);
	return ret;
}

inline std::wstring FormatDateTime(SYSTEMTIME time)
{
	std::wstringstream ws;

	ws << time.wYear << L"-";
	ws << std::setfill(L'0') << std::setw(2);
	ws << time.wMonth << L"-";
	ws << std::setfill(L'0') << std::setw(2);
	ws << time.wDay << L" ";
	ws << std::setfill(L'0') << std::setw(2);
	ws << time.wHour << L":";
	ws << std::setfill(L'0') << std::setw(2);
	ws << time.wMinute << L":";
	ws << std::setfill(L'0') << std::setw(2);
	ws << time.wSecond << L":";
	ws << std::setfill(L'0') << std::setw(3);
	ws << time.wMilliseconds;

	return ws.str();
}
inline std::wstring GetLastErrorStdStr()
{
	DWORD error = GetLastError();
	if (error)
	{
		LPVOID lpMsgBuf;
		DWORD bufLen = FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			nullptr,
			error,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			reinterpret_cast<LPWSTR>(&lpMsgBuf),
			0, nullptr);
		if (bufLen)
		{
			LPWSTR lpMsgStr = static_cast<LPWSTR>(lpMsgBuf);
			std::wstring result(lpMsgStr, lpMsgStr + bufLen);

			LocalFree(lpMsgBuf);

			return result;
		}
	}
	return std::wstring();
}