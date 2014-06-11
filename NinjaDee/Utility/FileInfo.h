#include "pch.h"

namespace NinjaDee
{
	class FileInfo
	{
	public:
		FileInfo(std::wstring file);

		const std::wstring GetFullPath() const;
		const std::wstring GetLongPath() const;
		const std::wstring GetShortPath() const;
		const std::wstring GetFileName() const;
		const std::wstring GetExtension() const;

		const LARGE_INTEGER GetSize() const;
		const FILETIME GetLastChanged() const;

	protected:
		std::wstring m_sFilePath;

		static const DWORD m_iMaxPath;
	};

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
}