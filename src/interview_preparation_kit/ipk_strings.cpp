#include "ipk_strings.h"

#include <algorithm>
#include <cctype>
#include <array>
#include <numeric>
#include <vector>

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

	// https://www.hackerrank.com/challenges/special-palindrome-again
	int special_string_again(const int /*n*/, const std::string str)
	{
		// TODO, cleanup, maybe rename some variables
		int special_sub_strings{ static_cast<int>(str.size()) };
		for (size_t left_index = 0; left_index < str.size(); ++left_index)
		{
			const auto first_letter = str[left_index];

			size_t counter{ 1 };
			bool is_incrementing{ true };

			for (size_t right_index = left_index + 1; right_index < str.size() && counter != 0; ++right_index)
			{
				if (str[right_index] == first_letter)
				{
					// the same character substrings
					if (is_incrementing)
					{
						++special_sub_strings;
						++counter;
					}
					else
					{
						--counter;
					}
				}
				else
				{
					if (!is_incrementing)
					{
						break;
					}

					is_incrementing = false;
				}
			}

			if (counter == 0)
			{
				++special_sub_strings;
			}
		}

		return special_sub_strings;
	}

	// https://www.hackerrank.com/challenges/sherlock-and-valid-string
	std::string sherlock_and_the_valid_string(const std::string str)
	{
		const auto count_letter_occurences = [](const std::string& str, std::vector<int>& occurences)
		{
			constexpr int characters_count = 'z' - 'a' + 1;

			occurences.resize(characters_count, 0);
			for (const auto character : str)
			{
				++occurences[character - 'a'];
			}
		};

		// Could use std::array, but we will be removing 0-value elements for simplicity, so..
		std::vector<int> occurences;
		count_letter_occurences(str, occurences);

		std::sort(occurences.begin(), occurences.end(), std::greater<>{});
		occurences.erase(std::find(occurences.begin(), occurences.end(), 0), occurences.end());

		bool was_character_deleted{ false };
		int reference_value{ *std::find_if(occurences.begin(), occurences.end(), [](const auto value) { return value > 0; }) };
		for (size_t i = 0; i < occurences.size(); ++i)
		{
			const auto difference = std::abs(reference_value - occurences[i]);
			if (difference == 0)
			{
				continue;
			}

			// Last one, we don't care for it's value, just that no character was deleted so far
			if (!was_character_deleted && i == occurences.size() - 1)
			{
				break;
			}

			if (difference > 1 || was_character_deleted || (occurences[i] < reference_value && i > 1))
			{
				return "NO";
			}

			was_character_deleted = true;
			reference_value = std::max(reference_value, occurences[i]) - 1;
		}

		return "YES";
	}
}
