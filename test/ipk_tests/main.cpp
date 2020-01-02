#include "src/interview_preparation_kit/ipk_warm_up.h"
#include "src/interview_preparation_kit/ipk_arrays.h"
#include "src/interview_preparation_kit/ipk_strings.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

// Obviously these are not full tests (lacking bunch of corner cases), but I am simply using it to valid a sample case given by the exercise docs

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

TEST(ipk_warm_up, jumping_on_clouds_1)
{
	const std::vector<int> clouds{ 0,0,1,0,0,1,0 };

	ASSERT_EQ(ipk_warm_up::jumping_on_clouds(clouds), 4);
}

TEST(ipk_warm_up, jumping_on_clouds_2)
{
	const std::vector<int> clouds{ 0,0,0,0,1,0 };

	ASSERT_EQ(ipk_warm_up::jumping_on_clouds(clouds), 3);
}

TEST(ipk_warm_up, counting_valleys_1)
{
	std::stringstream ss;

	const std::string steps{ "UDDDUDUU" };
	ASSERT_EQ(ipk_warm_up::counting_valleys(static_cast<int>(steps.size()), steps), 1);
}

TEST(ipk_arrays, hourglass_sum_1)
{
	const std::vector<std::vector<int>> values{
		{1,1,1,0,0,0},
		{0,1,0,0,0,0},
		{1,1,1,0,0,0},
		{0,0,2,4,4,0},
		{0,0,0,2,0,0},
		{0,0,1,2,4,0}};

	ASSERT_EQ(ipk_arrays::hourglass_sum(values), 19);
}

TEST(ipk_arrays, rot_left_1)
{
	const std::vector<int> values{ 41, 73, 89, 7, 10, 1, 59, 58, 84, 77, 77, 97, 58, 1, 86, 58, 26, 10, 86, 51 };
	const std::vector<int> result{ 77, 97, 58, 1, 86, 58, 26, 10, 86, 51, 41, 73, 89, 7, 10, 1, 59, 58, 84, 77 };
	
	constexpr int offset{ 10 };
	
	ASSERT_EQ(ipk_arrays::rot_left(values, offset), result);
}

TEST(ipk_arrays, rot_left_2)
{
	const std::vector<int> values{ 1, 2, 3, 4, 5 };
	const std::vector<int> result{ 4, 5, 1, 2, 3 };

	constexpr int offset{ 3 };

	ASSERT_EQ(ipk_arrays::rot_left(values, offset), result);
}


TEST(ipk_arrays, min_swaps_1)
{
	const std::vector<int> values{ 2, 3, 4, 1, 5 };

	ASSERT_EQ(ipk_arrays::minimum_swaps(values), 3);
}

TEST(ipk_arrays, min_swaps_2)
{
	const std::vector<int> values{ 1, 3, 5, 2, 4, 6, 7};

	ASSERT_EQ(ipk_arrays::minimum_swaps(values), 3);
}

TEST(ipk_arrays, minimum_bribes_1)
{
	const std::vector<int> values{ 2, 1, 5, 3, 4 };

	ASSERT_EQ(ipk_arrays::minimum_bribes(values), 3);
}

TEST(ipk_arrays, minimum_bribes_2)
{
	const std::vector<int> values{ 2, 5, 1, 3, 4 };

	ASSERT_EQ(ipk_arrays::minimum_bribes(values), -1);
}

TEST(ipk_arrays, minimum_bribes_3)
{
	const std::vector<int> values{ 5, 1, 2, 3, 7, 8, 6, 4 };

	ASSERT_EQ(ipk_arrays::minimum_bribes(values), -1);
}

TEST(ipk_arrays, minimum_bribes_4)
{
	const std::vector<int> values{ 1, 2, 5, 3, 7, 8, 6, 4 };

	ASSERT_EQ(ipk_arrays::minimum_bribes(values), 7);
}

TEST(ipk_arrays, array_manipulation_1)
{
	const std::vector<std::vector<int>> queries{ {1, 2, 100}, { 2, 5, 100}, {3, 4, 100} };

	ASSERT_EQ(ipk_arrays::array_manipulation(5, queries), 200);
}

TEST(ipk_arrays, array_manipulation_2)
{
	const std::vector<std::vector<int>> queries{ {2, 3, 603}, {1, 1, 286}, {4, 4, 882} };

	ASSERT_EQ(ipk_arrays::array_manipulation(4, queries), 882);
}

TEST(ipk_arrays, array_manipulation_3)
{
	const std::vector<std::vector<int>> queries{
		{1, 1, 5},
		{2, 5, 5},
		{2, 8, 5},
		{1, 2, 5},
		{8, 9, 5},
		{4, 6, 5} };

	ASSERT_EQ(ipk_arrays::array_manipulation(10, queries), ipk_arrays::array_manipulation_slow_but_correct(10, queries));
}

TEST(ipk_arrays, array_manipulation_4)
{
	const std::vector<std::vector<int>> queries{
		{5, 8, 4},
		{7, 9, 9},
		{4, 5, 9},
		{4, 8, 5},
		{1, 3, 1},
		{8, 10, 4},
		{5, 6, 6},
		{4, 5, 5},
		{3, 8, 1},
		{3, 8, 2} };

	ASSERT_EQ(ipk_arrays::array_manipulation(10, queries), ipk_arrays::array_manipulation_slow_but_correct(10, queries));
}

TEST(ipk_arrays, array_manipulation_5)
{
	const std::vector<std::vector<int>> queries{
		{3, 3, 1},
		{2, 3, 2},
		{1, 3, 3} };

	ASSERT_EQ(ipk_arrays::array_manipulation(3, queries), ipk_arrays::array_manipulation_slow_but_correct(3, queries));
}

TEST(ipk_strings, alternatic_characters_1)
{
	ASSERT_EQ(ipk_strings::alternating_characters("AAAA"), 3);
}

TEST(ipk_strings, alternatic_characters_2)
{
	ASSERT_EQ(ipk_strings::alternating_characters("BBBBB"), 4);
}

TEST(ipk_strings, alternatic_characters_3)
{
	ASSERT_EQ(ipk_strings::alternating_characters("ABABABAB"), 0);
}

TEST(ipk_strings, alternatic_characters_4)
{
	ASSERT_EQ(ipk_strings::alternating_characters("BABABA"), 0);
}

TEST(ipk_strings, alternatic_characters_5)
{
	ASSERT_EQ(ipk_strings::alternating_characters("AAABBB"), 4);
}

TEST(ipk_strings, make_anagram_1)
{
	ASSERT_EQ(ipk_strings::make_anagram("cde", "abc"), 4);
}