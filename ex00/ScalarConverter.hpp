#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>

class ScalarConverter {
	public:
		static void convert(const std::string &literal);
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &);
		ScalarConverter &operator=(const ScalarConverter &);
};

#endif