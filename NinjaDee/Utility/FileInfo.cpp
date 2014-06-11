#include "pch.h"
#include "FileInfo.h"

using namespace NinjaDee;

const DWORD FileInfo::m_iMaxPath = 4048;

FileInfo::FileInfo(std::wstring file)
:m_sFilePath(file)
{	
}

const std::wstring FileInfo::GetFullPath() const
{
	TCHAR buffer[m_iMaxPath] = L"";
	TCHAR** lppPart = { nullptr };
	auto result = GetFullPathName(m_sFilePath.c_str(), m_iMaxPath, buffer, lppPart);
	if (result == 0)
	{
		return L"";
	}

	return buffer;
}

const std::wstring FileInfo::GetLongPath() const
{
	TCHAR buffer[m_iMaxPath] = L"";
	auto result = GetLongPathName(GetFullPath().c_str(), buffer, m_iMaxPath);
	if (result == 0)
	{
		return L"";
	}

	return buffer;
}

const std::wstring FileInfo::GetShortPath() const
{
	TCHAR buffer[m_iMaxPath] = L"";
	auto result = GetShortPathName(GetLongPath().c_str(), buffer, m_iMaxPath);
	
	if (result == 0)
	{
		return L"";
	}

	return buffer;
}

const std::wstring FileInfo::GetFileName() const
{
	auto lastSlash = m_sFilePath.find_last_of(LR"(\)");
	if (lastSlash != std::string::npos && m_sFilePath.length() > lastSlash )
	{
		return m_sFilePath.substr(lastSlash + 1);
	}
	return m_sFilePath;
}

const std::wstring FileInfo::GetExtension() const
{
	auto dotIndex = m_sFilePath.find_last_of(L".");
	if (dotIndex != std::string::npos)
	{
		return m_sFilePath.substr(dotIndex);
	}
	return L"";
}

const LARGE_INTEGER FileInfo::GetSize() const
{
	LARGE_INTEGER def;
	def.LowPart = -1;
	def.HighPart = -1;
	def.QuadPart = -1;

	auto fHandle = CreateFile(GetFullPath().c_str(), GENERIC_READ, FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

	if (fHandle == INVALID_HANDLE_VALUE)
	{
		return def;
	}

	auto worked = GetFileSizeEx(fHandle, &def);
	CloseHandle(fHandle);

	if (worked)
		return def;

	return def;
}

const FILETIME FileInfo::GetLastChanged() const
{
	WIN32_FILE_ATTRIBUTE_DATA data = {0};
	auto success = GetFileAttributesEx(GetFullPath().c_str(), GetFileExInfoStandard, &data);
	if (success)
	{
		return data.ftLastWriteTime;
	}

	return FILETIME();
}