#include "pch.h"

namespace NinjaDee
{
	class FileInfo
	{
	public:
		FileInfo(std::wstring file);

		std::wstring GetFullPath();
		std::wstring GetFileName();
		std::wstring GetExtension();

	protected:
		std::wstring m_sFilePath;
	};
}