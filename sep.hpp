
namespace tkn{
	/*
	*   typedef boost::tokenizer<boost::char_separator<char> > 
    tokenizer;
  boost::char_separator<char> sep("-;", "|", boost::keep_empty_tokens);
	*/

	namespace sep
	{
		struct keep_empty_tokens {};
		struct remove_empty_tokens {};

		template<typename T>
		struct seperator {};

		template<typename T>
		struct char_seperator
		{
			char_seperator(std::string s, keep_empty_tokens t)
			{
				tokens_not_to_use.reserve(s.size());
				// make the vector have enough space.

				for (auto _ : s)
				{
					tokens_not_to_use.push_back(_);
				}
				// for each of the characters in the string we add them to the 
				// tokens_not_to_use vector.
				keep_empty_tokens = true;
			}

			char_seperator(std::string s, remove_empty_tokens t)
			{
				tokens_not_to_use.reserve(s.size());
				// make the vector have enough space.

				for (auto _ : s)
				{
					tokens_not_to_use.push_back(_);
				}
				// for each of the characters in the string we add them to the 
				// tokens_not_to_use vector.
				keep_empty_tokens = false;
			}
			std::vector<char> tokens_not_to_use{};
			bool keep_empty_tokens{};
		};
	} // namespace sep
} // namespace tkn
