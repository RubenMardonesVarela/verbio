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
		return 0;
	}
	else
	{
		paragraph += argv[1];
	}
	result = ParagraphConverter::convertToDigits(paragraph);
	cout << result << endl;
	return 0;
}




