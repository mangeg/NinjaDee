#include "pch.h"
#include "FileSystem.h"

NinjaDee::FileSystem::FileSystem()
{
}

bool NinjaDee::FileSystem::FileExists(std::wstring const& file)
{
	auto attribs = GetFileAttributes(file.c_str());

	if (attribs == INVALID_FILE_ATTRIBUTES)
		// Folder/File does not exist
	{
		return false;
	}

	if (!(attribs & FILE_ATTRIBUTE_DIRECTORY))
		return true;

	return false;
}
bool NinjaDee::FileSystem::FolderExists(std::wstring const& folder)
{
	auto attribs = GetFileAttributes(folder.c_str());

	if (attribs == INVALID_FILE_ATTRIBUTES )
		// Folder/File does not exist
	{
		return false;
	}
	if (attribs & FILE_ATTRIBUTE_DIRECTORY)
		return true;

	return false;
}