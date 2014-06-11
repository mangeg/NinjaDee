#include "pch.h"
#include "Path.h"

using namespace NinjaDee;

const std::wstring Path::Combine(const std::wstring &str1, const std::wstring &str2)
{
	std::wstring part1(str1);
	std::wstring part2(str2);	

	part1.erase(part1.begin(), find_if(part1.begin(), part1.end(), [](WCHAR &c)
	{
		return c != L'/';
	} ));

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