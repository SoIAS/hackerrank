#include "ipk_strings.h"

#include <algorithm>
#include <cctype>
#include <array>

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

	// https://www.hackerrank.com/challenges/ctci-making-anagrams
	int make_anagram(std::string a, std::string b)
	{
		constexpr int cache_size = 'z' - 'a' + 1;

		const auto cache_letters_in_string = [](const std::string& str, std::array<int, cache_size>& cache)
		{
			for (const auto character : str)
			{
				++cache[character - 'a'];
			}
		};

		std::array<int, cache_size> a_cache{}, b_cache{};

		cache_letters_in_string(a, a_cache);
		cache_letters_in_string(b, b_cache);
	
		int min_deletions{};
		for (size_t i = 0; i < cache_size; ++i)
		{
			min_deletions += std::abs(a_cache[i] - b_cache[i]);
		}

		return min_deletions;
	}
}
