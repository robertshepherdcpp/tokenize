#include"sep.hpp" // seperator<T>
#include"help.hpp" // helper::is_alphabetical

#include<string> // std::string
#include<vector> // std::vector

// tokenizer tokens(str, sep);

namespace tkn
{

	struct IndexVal
	{
		int i{};
		char c{};
	};

	template<typename T>
	auto find(std::vector<T>& v, char TokenToFind) -> bool
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] == TokenToFind)
			{
				return true;
			}
		}
		// represents value not found.
		//return IndexVal{ -1, 'z' };
		return true;
	}

	template<typename T, typename sep::char_seperator<T> a>
	struct tokenizer
	{
		// this is the generic seperator.
	};

	template<>
	struct tokenizer<char, a>
	{
		tokensizer(std::string raw_string, sep::char_seperator<char>& c)
		{
			for (auto _ : raw_string)
			{
				// so for all of the elements in the raw string we want to see if c.keep_empty_tokens is true
				// or false. We can use a member function find, that returns the index and the value.
				if (find(c.tokens_not_to_use, _))
				{
					// so this current token is a character that we do not want, we will check if the user wants it like:
					// <> or just doesn't want it atall.
					if (c.keep_empty_tokens == true)
					{
						tokened += "<";
					}
					else
					{
						// the user doesn't want to keep them so we do nothing with them.
					}
				}
				else if (helper::is_alphabetical(_) == true)
				{
					// this is alphabetical. so we just add it to the string.
					tokened += ("> <" + _);
				}
				else
				{
					// we just have a character
					tokened += ("> <" + _);
				}
			}
		}

		auto get()
		{
			return tokened;
		}

		std::string tokened{};
	};
} // namespace tkn
