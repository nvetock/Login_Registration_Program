#include "Logger.h"


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
// 
// Helper Functions
// 
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

std::string Logger::levelToString(LogLevel level) const {

	switch (level) {
	case DEBUG: return "DEBUG";
	case INFO: return "INFO";
	case WARNING: return "WARNING";
	case ERROR: return "ERROR";
	case CRITICAL: return "CRITICAL";
	default: return "UNKNOWN";
	}
}


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
// 
// Logging Functions
// 
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

void Logger::log(LogLevel level, const std::string& message) const {


	// Output filestream for the log file.
	std::ofstream logFile(_log_file_name, std::ios::app);

	// Ensure log file is open
	if (logFile.is_open()) {
		// Get and convert current time
		auto now = std::chrono::system_clock::now();
		auto now_converted = std::chrono::system_clock::to_time_t(now);
		std::tm now_tm;
		localtime_s(&now_tm, &now_converted);

		// Input log message into filestream
		logFile
			<< "[ " << levelToString(level) << " ]\n"
			<< std::put_time(&now_tm, "%Y-%m-%d | %H:%M:%S") << '\n'
			<< message << '\n' << std::endl;

		// Close filestream
		logFile.close();
	}
	else {
		std::cerr << "Error: Unable to open log file: "
			<< _log_file_name << std::endl;
	}
}


void Logger::debug(const std::string& message) const{
	this->log(DEBUG, message);
}

void Logger::info(const std::string& message) const {
	this->log(INFO, message);
}

void Logger::warning(const std::string& message) const {
	this->log(WARNING, message);
}

void Logger::error(const std::string& message) const {
	this->log(ERROR, message);
}

void Logger::critical(const std::string& message) const {
	this->log(CRITICAL, message);
}
