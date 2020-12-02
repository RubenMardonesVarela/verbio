#include "wordsToDigitConverter.h"


unsigned int WordsToDigitsConverter::convert(vector<string>& words)
{
	unsigned int numberInDigits = 0;
	unsigned int partialNumber = 0;
	for(auto&& word : words)
	{
		auto it = mapOfsplitters.find(word);
		if(it != mapOfsplitters.end())
		{
			if(partialNumber == 0)
			{
				partialNumber = 1;
			}
			partialNumber *= it->second;
			numberInDigits += partialNumber;
			partialNumber = 0;
		}
		else
		{
			auto it = mapOfNumbers.find(word);
			if(it != mapOfNumbers.end())
			{
				if(word == "hundred")
				{
					if(partialNumber == 0)
					{
						partialNumber = 1;
					}
					partialNumber *= it->second;
				}
				else
				{
					partialNumber += it->second;
				}

			}
		}
	}
	numberInDigits += partialNumber;
	return numberInDigits;
}




