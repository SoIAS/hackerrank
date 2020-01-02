#include "ipk_strings.h"

#include <algorithm>
#include <cctype>

namespace ipk_strings
{
	// https://www.hackerrank.com/challenges/alternating-characters
	int alternating_characters(const std::string str)
	{
		if (str.empty())
		{
			return 0;
		}

		const auto find_next = [&str](const size_t current_index)
		{
			// As per specification the string contains only A or B
			const auto next_letter = std::toupper(str[current_index]) == 'A' ? 'B' : 'A';

			return std::find(str.begin() + current_index, str.end(), next_letter);
		};

		size_t min_deletions{};
		size_t current_index{ 0 };
		for (auto it = find_next(current_index); it != str.end(); it = find_next(current_index))
		{
			const size_t new_index = std::distance(str.begin(), it);
			min_deletions += new_index - current_index - 1;
			current_index = new_index;
		}

		min_deletions += str.size() - current_index - 1;

		// Could have used int in the beginning, but then I would have to use static cast on disnance, so...
		// Preferably we would return unsigned, but keeping the return type + signature as in the challenges
		return static_cast<int>(min_deletions);
	}
}
