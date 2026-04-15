/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("Z"));
}

TEST(PasswordTest, mixed_case_password)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("ZZz"));
}

TEST(PasswordTest, mixed_letter_password)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("ZA"));
}

TEST(PasswordTest, mixed_case_letter_password)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("ZaA"));
}

TEST(PasswordTest, mixed_case_pass)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("Za"));
}

TEST(PasswordTest, mixed_case_pass_reverse)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("aZ"));
}

TEST(PasswordTest, mixed_symbol_pass)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("Za%Za"));
}

TEST(PasswordTest, mixed_letter_pass)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("ZA"));
}

TEST(PasswordTest, matching_case_pass)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("ZZ"));
}

TEST(PasswordTest, diff_case_pass)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("Zz"));
}

TEST(PasswordTest, all_unique) {
	Password my_password;
	ASSERT_EQ(5, my_password.unique_characters("abcde"));
}

TEST(PasswordTest, no_unique) {
	Password my_password;
	ASSERT_EQ(1, my_password.unique_characters("aaaaa"))
}

TEST(PasswordTest, mixed_case) {
	Password my_password;
	ASSERT_EQ(2, my_password.unique_characters("aAaAaA"))
}

TEST(PasswordTest, with_symbols) {
	Password my_password;
	ASSERT_EQ(4, my_password.unique_characters("a%&b"))
}

TEST(PasswordTest, repetition) {
	Password my_password;
	ASSERT_EQ(3, my_password.unique_characters("abcba"))
}