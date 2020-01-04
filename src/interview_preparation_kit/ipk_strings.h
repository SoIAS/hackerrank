#pragma once

#include <string>

namespace ipk_strings
{
	// using same function signature as in the challenge, so that's why there are unnecessary things (like copying a vector that is never modified locally)

	// https://www.hackerrank.com/challenges/alternating-characters
	int alternating_characters(std::string str);

	// https://www.hackerrank.com/challenges/ctci-making-anagrams
	int make_anagram(std::string a, std::string b);

	// https://www.hackerrank.com/challenges/special-palindrome-again
	int special_string_again(int n, std::string str);
}