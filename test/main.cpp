//============================================================================
// Name        : main_unit_tests.cpp
// Author      : Ruben Mardones
// Version     :
// Copyright   : 
// Description : Verbio test --> Unit tests
//============================================================================

#include "gtest/gtest.h"
#include "../src/paragraphConverter.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(stringSpliter, split)
{
	vector<string> words = StringSpliter::split("I am thirty eight years old", ' ');
	EXPECT_EQ(words.size(), 6);
	EXPECT_EQ(words[0], "I");
	EXPECT_EQ(words[1], "am");
	EXPECT_EQ(words[2], "thirty");
	EXPECT_EQ(words[3], "eight");
	EXPECT_EQ(words[4], "years");
	EXPECT_EQ(words[5], "old");
}

TEST(wordsToDigitConverter, convertOneDigit)
{
	vector<string> number = {"one"};
	EXPECT_EQ(WordsToDigitsConverter::convert(number), 1);
}

TEST(wordsToDigitConverter, convertTwoDigits)
{
	vector<string> number = {"twenty", "nine"};
	EXPECT_EQ(WordsToDigitsConverter::convert(number), 29);
}

TEST(wordsToDigitConverter, convertThreeDigits)
{
	vector<string> number = {"one", "hundred"};
	EXPECT_EQ(WordsToDigitsConverter::convert(number), 100);
}

TEST(wordsToDigitConverter, convertFourDigits)
{
	vector<string> number = {"five", "thousand","two", "hundred","and","sixty","four"};
	EXPECT_EQ(WordsToDigitsConverter::convert(number), 5264);
}

TEST(wordsToDigitConverter, convertFiveDigits)
{
	vector<string> number = {"sixty", "thousand","three", "hundred","and","four"};
	EXPECT_EQ(WordsToDigitsConverter::convert(number), 60304);
}

TEST(wordsToDigitConverter, convertSixDigits)
{
	vector<string> number = {"seven", "hundred","thousand","and","four"};
	EXPECT_EQ(WordsToDigitsConverter::convert(number),700004);
}

TEST(wordsToDigitConverter, convertSevenDigits)
{
	vector<string> number = {"one", "million","twenty","four","thousand","five","hundred","and","forty"};
	EXPECT_EQ(WordsToDigitsConverter::convert(number),1024540);
}

TEST(wordsToDigitConverter, convertEightDigits)
{
	vector<string> number = {"ninety", "million","one","thousand"};
	EXPECT_EQ(WordsToDigitsConverter::convert(number),90001000);
}

TEST(wordsToDigitConverter, convertNineDigits)
{
	vector<string> number = {"eight","hundred","and", "eighty","million","three","hundred","and", "thirty", "thousand"};
	EXPECT_EQ(WordsToDigitsConverter::convert(number), 880330000);
}

TEST(paragraphConverter, convertSimple)
{
	string result = ParagraphConverter::convertToDigits("I am thirty eight years old");
	EXPECT_EQ(result, "I am 38 years old");
}


TEST(paragraphConverter, convertStartingWithNumber)
{
	string result = ParagraphConverter::convertToDigits("Three thousand years ago, dinosaurs extingued");
	EXPECT_EQ(result, "3000 years ago, dinosaurs extingued");
}

TEST(paragraphConverter, convertEndingWithNumber)
{
	string result = ParagraphConverter::convertToDigits("Actually, I had forty");
	EXPECT_EQ(result, "Actually, I had 40");
}

TEST(paragraphConverter, convertParagraphWithAnd)
{
	string result = ParagraphConverter::convertToDigits("I had one thousand and one hundred and I was happy");
	EXPECT_EQ(result, "I had 1100 and I was happy");
}


