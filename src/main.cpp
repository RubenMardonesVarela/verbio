//============================================================================
// Name        : main.cpp
// Author      : Ruben Mardones Varela
// Version     :
// Copyright   : 
// Description : Verbio test --> Words to digit converter
//============================================================================

#include "paragraphConverter.h"
#include <iostream>


using namespace std;



int main(int argc, char **argv)
{
	bool finish = false;
	string paragraph;
	string result;
	if(argc != 2)
	{
		cout << "Error in parameters" << endl;
	}
	else
	{
		paragraph += argv[1];
	}
	result = ParagraphConverter::convertToDigits(paragraph);
	cout << result << endl;
	return 0;
	vector<string> words = StringSpliter::split(paragraph, ' ');
	int indexNextWord = 0;
	int indexStartNumber = 0;
	int indexEndNumber = 0;
	vector<string> number;
	while(!finish)
	{
		string word = words[indexNextWord];
		auto it = mapOfNumbers.find(word);
		if(it == mapOfNumbers.end() || word == "and")
		{
			result += word;
			result += ' ';
			indexNextWord++;
			if(indexNextWord >= words.size())
			{
				finish = true;
			}
		}
		else
		{
			indexStartNumber = indexNextWord;
			indexEndNumber = indexStartNumber + 1;
			bool endNumberFound = false;

			if(indexEndNumber >= words.size())
			{
				endNumberFound = true;
				indexEndNumber = indexStartNumber;
			}
			//Look for the end of the number
			while(!endNumberFound)
			{
				string nextWord = words[indexEndNumber];
				auto it = mapOfsplitters.find(nextWord);
				if(it != mapOfsplitters.end())
				{
					//Found splitter
					indexEndNumber++;
					if(indexEndNumber >= words.size())
					{
						endNumberFound = true;
					}
				}
				else
				{
					auto it = mapOfNumbers.find(nextWord);
					if(it != mapOfNumbers.end())
					{
						//Found number --> can be "and"
						if(nextWord == "and")
						{
							string nextToAnd = words[indexEndNumber+1];
							auto it = mapOfNumbers.find(nextToAnd);
							if(it == mapOfNumbers.end())
							{
								endNumberFound = true;

							}
							else
							{
								indexEndNumber++;
								if(indexEndNumber >= words.size())
								{
									endNumberFound = true;
								}
							}
						}
						else
						{
							indexEndNumber++;
							if(indexEndNumber >= words.size())
							{
								endNumberFound = true;
							}

						}
					}
					else
					{
						endNumberFound = true;
					}

				}
			}
			// Convert the number to digits
			vector<string> number;

			for(int i = indexStartNumber;i<indexEndNumber;++i)
			{
				number.push_back(words[i]);
			}
			unsigned int numInteger = WordsToDigitsConverter::convert(number);
			result +=  to_string(numInteger);
			result += ' ';
			indexNextWord = indexEndNumber;

			if(indexNextWord >= words.size())
			{
				finish = true;
			}

		}
	}
	cout << result << endl;
}




