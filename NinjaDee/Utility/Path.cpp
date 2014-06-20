#include "pch.h"
#include "Path.h"
#include "StringHelpers.h"

using namespace NinjaDee;

const std::wstring Path::Combine(const std::wstring &str1, const std::wstring &str2)
{
	std::wstring part1(str1);
	std::wstring part2(str2);

	part1 = Trim(part1);
	part2 = Trim(part2);

	while (part1.length() > 0 && (part1[part1.length() - 1] == L'\\' || part1[part1.length() - 1] == L'/'))
	{
		part1 = part1.substr(0, part1.length() - 1);
	}

	auto part2LastIndex = part2.find_first_of(LR"(\)");
	if (part2LastIndex == std::string::npos)
	{
		part2LastIndex = part2.find_first_of(LR"(/)");
	}
	if (part2LastIndex != std::string::npos && part2.length() > part2LastIndex + 1)
	{
		part2 = part2.substr(part2LastIndex + 1);
	}

	return part1 + LR"(\)" + part2;
}
std::wstring const Path::ChangeExtension(std::wstring const& str, const std::wstring &newExt)
{
	auto length = str.length();
	if (length == 0)
		return newExt;

	auto lastDot = str.find_last_of(L".");

	if (std::string::npos == lastDot)
		return str + L"." + newExt;
	
	return str.substr(0, lastDot) + L"." + newExt;
}
std::wstring const Path::GetFilenameWithoutExtension(std::wstring const& str)
{
	auto length = str.length();
	if (length == 0)
		return str;

	auto fileName = GetFileName(str);

	auto lastDot = fileName.find_last_of(L".");

	if (lastDot == std::string::npos)
		return fileName;

	return fileName.substr(0, lastDot);
}
std::wstring const Path::GetDirectoryName(std::wstring const& str)
{
	auto length = str.length();
	if (length == 0)
		return str;

	auto lastIndex = str.find_last_of(LR"(\)");
	if (lastIndex != std::string::npos)
	{
		return str.substr(0, lastIndex);
	}

	return str;
}
std::wstring const Path::GetExtension(std::wstring const& str)
{
	auto length = str.length();
	if (length == 0)
		return str;

	auto lastIndex = str.find_last_of(LR"(.)");
	if (lastIndex != std::string::npos && length > lastIndex)
	{
		return str.substr(lastIndex);
	}

	return L"";
}
std::wstring const Path::GetFileName(std::wstring const& str)
{
	auto length = str.length();
	if (length == 0)
		return str;

	auto lastIndex = str.find_last_of(LR"(\)");
	if (lastIndex != std::string::npos && length > lastIndex)
	{
		return str.substr(lastIndex + 1);
	}

	return str;
}