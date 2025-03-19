#include "ScalarConverter.hpp"

static bool isPseudoLiteral(const std::string &s)
{
	return (s == "nan" || s == "nanf" ||
			s == "+inf" || s == "-inf" ||
			s == "+inff" || s == "-inff");
}

static bool isCharLiteral(const std::string &s)
{
	return (s.length() == 1 && !std::isdigit(s[0]));
}

void ScalarConverter::convert(const std::string &literal)
{
	char c = 0;
	int i = 0;
	float f = 0;
	double d = 0;

	std::cout << std::fixed << std::setprecision(1);

	if (isPseudoLiteral(literal))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (literal[literal.size()] == 'f')
			std::cout << "float: " << literal << std::endl;
		else
			std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
		return ;
	}
	else if (isCharLiteral(literal))
	{
		c = literal[0];
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}
	else
	{
		char *endptr = NULL;
		d = std::strtod(literal.c_str(), &endptr);
		if (endptr == literal.c_str() || (*endptr && *endptr != 'f'))
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return ;
		}
		f = static_cast<float>(d);
		i = static_cast<int>(d);
		c = static_cast<char>(d);
	}
	// Print char conversion
	std::cout << "char: ";
    if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max() || std::isnan(d))
    {
		std::cout << "impossible" << std::endl;
	}
    else if (!std::isprint(c))
        std::cout << "Non displayable" << std::endl;
    else
	{
        std::cout << "'" << c << "'" << std::endl;
	}
	
	std::cout << "int: ";
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || std::isnan(d))
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;
	
	std::cout << "float: ";
	if (std::isnan(f))
        std::cout << "nanf" << std::endl;
    else if (f == std::numeric_limits<float>::infinity())
        std::cout << "+inff" << std::endl;
    else if (f == -std::numeric_limits<float>::infinity())
        std::cout << "-inff" << std::endl;
    else
        std::cout << f << "f" << std::endl;
    
    std::cout << "double: ";
    if (std::isnan(d))
        std::cout << "nan" << std::endl;
    else if (d == std::numeric_limits<double>::infinity())
        std::cout << "+inf" << std::endl;
    else if (d == -std::numeric_limits<double>::infinity())
        std::cout << "-inf" << std::endl;
    else
        std::cout << d << std::endl;
}
