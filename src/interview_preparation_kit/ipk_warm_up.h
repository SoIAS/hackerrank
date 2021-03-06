#pragma once

#include <vector>
#include <string>

namespace ipk_warm_up
{
	// using same function signature as in the challenge, so that's why there are unnecessary things (like copying a vector that is never modified locally)


	// https://www.hackerrank.com/challenges/sock-merchant
	int sock_merchant(int size, std::vector<int> array);

	// https://www.hackerrank.com/challenges/repeated-string
	long long repeated_string(std::string str, long long n);

	// https://www.hackerrank.com/challenges/jumping-on-the-clouds
	int jumping_on_clouds(std::vector<int> clouds);

	// https://www.hackerrank.com/challenges/counting-valleys
	int counting_valleys(int n, std::string str);

}