#pragma once

#include "pch.h"
#include <cstdint>
#include <thread>

namespace NinjaDee{

	class ISink
	{

	};

	enum class LogLevel : int8_t { L_LOGALWAYS = 0, L_VERBOSE = 1, L_INFORMATIONAL = 2, L_WARNING = 3, L_ERROR = 4, L_FATAL = 5 };

	class LogEntry
	{
	public:
		LogEntry(const std::wstring &file, const int line,
			const std::wstring& function, const LogLevel level);

		std::wstring ToString() const;

	private:

		int64_t m_iMicroseconds;
		time_t m_tTimestamp;
		std::thread::id m_tThreadId;
		int m_iLine;
		std::wstring m_sFile;
		std::wstring m_sFunction;
		LogLevel m_eLevel;
		mutable std::wstring m_sMessage;
	};

	class Log
	{
	public:
		Log();

		static void Write(LogEntry entry);
		static void Write(LogLevel level, std::wstring &message);
		static void Write(LogLevel level, std::wstring &message, std::wstring &file, int line, std::wstring &function);

		static std::wstring GetLevelName(LogLevel level);
	private:
		static std::map<LogLevel, std::wstring> m_vLevelNames;
		static std::vector<ISink> m_vSinks;
	};

	inline void LogCapture(const char* t)
	{
		
	}

#define LOG_F(boolean_expression) \
	if(true == (boolean_expression)) LogCapture(#boolean_expression)
}