#include "src/interview_preparation_kit/ipk_warm_up.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"


int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(ipk_warm_up, sock_merchant_1)
{
	constexpr int size{ 9 };
	const std::vector<int> socks_colors{ 10, 20, 20, 10, 10, 30, 50, 10, 20 };

	ASSERT_EQ(ipk_warm_up::sock_merchant(size, socks_colors), 3);
}

TEST(ipk_warm_up, repeated_string_1)
{
	const std::string str{"aba"};
	const long long n = { 10 };

	ASSERT_EQ(ipk_warm_up::repeated_string(str, n), 7);
}

TEST(ipk_warm_up, repeated_string_2)
{
	const std::string str{ "a" };
	const long long n = { 1000000000000 };

	ASSERT_EQ(ipk_warm_up::repeated_string(str, n), 1000000000000);
}