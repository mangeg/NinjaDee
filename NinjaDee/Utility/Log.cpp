#include "pch.h"
#include "Log.h"
#include <chrono>
#include <mutex>
#include "..\..\SDK\Include\Path.h"

using namespace NinjaDee;

namespace {
	std::once_flag g_start_time_flag;
	std::chrono::steady_clock::time_point g_start_time;

	int64_t  microsecondsCounter() {
		std::call_once(g_start_time_flag, []() { g_start_time = std::chrono::steady_clock::now(); });
		auto  now = std::chrono::steady_clock::now();
		return std::chrono::duration_cast<std::chrono::microseconds>(now - g_start_time).count();
	}
} // anonymous

std::map<LogLevel, std::wstring> Log::m_vLevelNames = { 
	{LogLevel::L_LOGALWAYS, std::wstring(L"Log Always")},
	{LogLevel::L_INFORMATIONAL, std::wstring(L"Informational")},
	{LogLevel::L_VERBOSE, std::wstring(L"Verbose")},
	{LogLevel::L_WARNING, std::wstring(L"Warning")},
	{LogLevel::L_ERROR, std::wstring(L"Error")},
	{LogLevel::L_FATAL, std::wstring(L"Fatal")},
};

Log::Log()
{
}

void Log::Write(LogEntry entry)
{
}

void Log::Write(LogLevel level, std::wstring &message)
{
	auto entry = LogEntry(L"", 0, L"", level);
	Write(entry);
}

void Log::Write(LogLevel level, std::wstring &message, std::wstring& file, int line, std::wstring& function)
{
	auto entry = LogEntry(file, line, function, level);
	Write(entry);
}

std::wstring Log::GetLevelName(LogLevel level)
{
	return m_vLevelNames[level];
}

LogEntry::LogEntry(std::wstring const& file, int const line, std::wstring const& function, LogLevel const level)
: m_tTimestamp(1)
, m_tThreadId(std::this_thread::get_id())
, m_iMicroseconds(microsecondsCounter())
, m_sFile(Path::GetFileName(file))
, m_iLine(line)
, m_sFunction(function)
, m_eLevel(level)
{
}

std::wstring LogEntry::ToString() const
{
	return L"";
}