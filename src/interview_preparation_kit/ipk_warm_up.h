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

}