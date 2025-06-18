#include <iostream>
#include "Logger.h"

// Intentionally global logger.
Logger mylog{ "Logs/new_log_test.log" };

int main()
{
	std::cout << "Hello world!" << std::endl;

	return 0;
}