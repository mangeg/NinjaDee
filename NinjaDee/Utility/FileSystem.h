#pragma once

#include "pch.h"

namespace NinjaDee
{
	class FileSystem
	{
	public:
		FileSystem();

		static bool FileExists(const std::wstring& file);
		static bool FolderExists(const std::wstring& folder);
	};
}