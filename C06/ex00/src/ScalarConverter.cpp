#include "ScalarConverter.hpp"

const std::string typeNames[] = {"nan", "+inf", "-inf", "nanf", "+inff", "-inff"};
const int typesSize = 6;

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

void charPrinting(int toInt) {
	if (toInt >= 0 && toInt <= 127) {
		if (!std::isprint(toInt) || toInt == 32 || toInt == 127) {
			std::cout << "char: Non displayable character" << std::endl;
		}
		else {
			std::cout << "char: '" << static_cast<char>(toInt) << "'" << std::endl;
		}
	}
	else {
		std::cout << "char: Impossible convert to char" << std::endl;
	}
}

void otherPrinting (int toInt, float toFloat, double toDouble) {
	std::cout << "int: " << toInt << std::endl;
	std::cout << "float: " << toFloat;
	if (toFloat == toInt)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << toDouble;
	if (toDouble == toInt)
		std::cout << ".0";
	std::cout << std::endl;
}

void convertToInt(const std::string& str) {
	int intC = std::stoi(str);
	int floatC = static_cast<float>(intC);
	int doubleC = static_cast<double>(intC);

	charPrinting(intC);
	otherPrinting(intC, floatC, doubleC);
	std::exit(EXIT_SUCCESS);
}

void convertToFloat(const std::string& str) {
	 if (str.back() == 'f') {
		float floatC = std::stof(str);
		double doubleC = static_cast<double>(floatC);
		int intC = static_cast<int>(doubleC);

		charPrinting(intC);
		otherPrinting(intC, floatC, doubleC);
		std::exit(EXIT_SUCCESS);
	 }
}

void convertToDouble(const std::string& str) {
	size_t pos = str.find(str);
	if (pos != std::string::npos) {
		double doubleC = std::stod(str);
		int intC = static_cast<int>(doubleC);
		float floatC = static_cast<float>(doubleC);

		charPrinting(intC);
		otherPrinting(intC, floatC, doubleC);
		std::exit(EXIT_SUCCESS);
    }
}

void ScalarConverter::convert(const std::string& str) {
	try {
		if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0])) {
			std::cout << "char: '" << static_cast<char>(str[0]) << "'" << std::endl;
			std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
			std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
			std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
			return;
		}
		for (int i = 0; i < typesSize; i++) {
			if (str == typeNames[i]){
				std::cout << "char: Invalid conversion to char" << std::endl;
				std::cout << "int: Invalid conversion to int" << std::endl;
				std::cout << "float: " << typeNames[i%3] << "f" << std::endl;
				std::cout << "double: " << typeNames[i%3] << std::endl;
				return ;
			}
		}
		convertToFloat(str);
		convertToDouble(str);
		convertToInt(str);
	}
	catch (std::exception& e) {
		std::cout << "char: Impossible convert to char" << std::endl;
		std::cout << "int: Impossible convert to int" << std::endl;
		std::cout << "float: Impossible convert to float" << std::endl;
		std::cout << "double: Impossible convert to double" << std::endl;
	}
}
