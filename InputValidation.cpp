#include "InputValidation.h"

namespace Validator {

	void ignoreLine() {

	}

	bool hasUnextractedInput() {
		return !std::cin.eof() && std::cin.peek() != '\n';
	}



	bool isInputValid(std::string& inputRef) {
		while (true) {

			if (!std::cin) {
				std::cin.clear(); // Return to 'normal' operation mode
				ignoreLine();     // Remove bad input
				continue;
			}
		}
		


		return false;
	}

}