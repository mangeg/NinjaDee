#pragma once

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
}