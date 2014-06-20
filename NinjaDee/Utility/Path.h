#pragma once

#include "pch.h"

namespace NinjaDee
{
	class Path
	{
	public:

		static const std::wstring Combine(const std::wstring &str1, const std::wstring &str2);
		static const std::wstring GetFileName(const std::wstring &str);
		static const std::wstring GetExtension(const std::wstring &str);
		static const std::wstring ChangeExtension(const std::wstring &str, const std::wstring &newExt);
		static const std::wstring GetFilenameWithoutExtension(const std::wstring &str);
		static const std::wstring GetDirectoryName(const std::wstring &str);
	};
}