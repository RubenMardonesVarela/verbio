#include "paragraphConverter.h"
#include <iostream>

bool isWordInMap(const string &word,map<string, unsigned int>& mapWithKeys )
{
	auto it = mapWithKeys.find(word);
	return it != mapWithKeys.end();
}

bool isWordASplitterNumber(const string &word)
{
	return isWordInMap(word,mapOfsplitters);
}

bool isWordANumber(const string &word)
{
	return isWordInMap(word,mapOfNumbers);
}

string ParagraphConverter::convertToDigits(const string &input)
{
	string result;
	/*  1. Split the paragraph into different words, using empty space as a separator */
	vector<string> words = StringSpliter::split(input, ' ');
	/* 2. Go over the vector of words. If the word is not the beginning of a number
	 *    add the word to the restult, otherwise track the end of the number, and convert
	 *    the number to digits. Then, continue the process again until the paragraph is finished */
	bool finish = false;
	int indexNextWord = 0;
	int indexStartNumber = 0;
	int indexEndNumber = 0;
	vector<string> number;
	while(!finish)
	{
		string word = words[indexNextWord];
		// The beginning of a number can not start with "and"
		if(!isWordANumber(word) || word == "and")
		{
			result += word;
			indexNextWord++;
			finish = indexNextWord >= words.size();
			if(!finish)
			{
				result += ' ';
			}
		}
		// The next word is the beginning of a number
		else
		{
			indexStartNumber = indexNextWord;
			indexEndNumber = indexStartNumber + 1;
			//Look for the end of the number
			bool endNumberFound = indexEndNumber >= words.size();
			while(!endNumberFound)
			{
				string nextWord = words[indexEndNumber];
				// Next word is splitter -> increase index to keep looking for the end
				if(isWordASplitterNumber(nextWord))
				{
					indexEndNumber++;
					endNumberFound = indexEndNumber >= words.size();
				}
				else
				{
					// Next word is a number string --> take care with special case "and"
					if(isWordANumber(nextWord))
					{
						if(nextWord == "and")
						{
							string nextToAnd = words[indexEndNumber+1];
							if(!isWordANumber(nextToAnd))
							{
								endNumberFound = true;

							}
							else
							{
								indexEndNumber++;
								endNumberFound = indexEndNumber >= words.size();

							}
						}
						else
						{
							indexEndNumber++;
							endNumberFound = indexEndNumber >= words.size();
						}
					}
					// Next word is not a number nor a splitter
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
			indexNextWord = indexEndNumber;
			finish = indexNextWord >= words.size();
			if(!finish)
			{
				result += ' ';
			}
		}
	}

	return result;
}







