#include<string> // std::string

namespace helper
{
	auto is_alphabetical(char b)
	{
		std::string c{ b };
		return c == "a" || c == "b" || c == "c" || c == "d" || c == "e" || c == "f" || c == "g" || c == "h" || c == "i" || c == "j" ||
			c == "k" || c == "l" || c == "m" || c == "n" || c == "o" || c == "p" || c == "q" || c == "r" || c == "s" || c == "t" ||
			c == "u" || c == "v" || c == "w" || c == "x" || c == "y" || c == "z";
	}
}
