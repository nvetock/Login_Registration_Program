#ifndef LOGGER_H
#define LOGGER_H

#include <ctime>
#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>

class Logger
{
	enum LogLevel { DEBUG, INFO, WARNING, ERROR, CRITICAL };

public:
	// Open log filestream when object is created
	Logger(const std::string& filename)
		: _log_file_name{filename}
	{
		// Create a 'Logs/' directory if one doesn't exist in project root folder.
		if (!std::filesystem::is_directory("Logs/")) { std::filesystem::create_directory("Logs/"); }
	}

	~Logger() { }

	// Quick log functions
	void debug(const std::string& message) const;
	void info(const std::string& message) const;
	void warning(const std::string& message) const;
	void error(const std::string& message) const;
	void critical(const std::string& message) const;

private:
	std::string _log_file_name{};

	/// <summary>
	/// Logs a message with a given log level.
	/// </summary>
	/// <param name="level"></param>
	/// <param name="message"></param>
	void log(LogLevel level, const std::string& message) const;

	/// <summary>
	/// Converts LogLevel enum to string.
	/// </summary>
	/// <param name="level">LogLevel</param>
	/// <returns>string output</returns>
	std::string levelToString(LogLevel level) const;
};

#endif