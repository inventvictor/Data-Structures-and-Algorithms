//============================================================================
// Name        : test.cpp
// Author      : Inventor
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "Testclass.h"
using namespace std;

int length(char s[])
{
    int n = 0;
    for (int i = 0; s[i] != '\0';++i)
    {
    	++n;
    }
    return n;
}

int main()
{

	//    int val = length("hello");
//    cout << val << endl;
//    return 0;

	//*************
//	    int sum = 0, value = 0;
//	    while (std::cin >> value)
//	        sum += value;
//	    std::cout << "Sum is: " << sum << std::endl;
//	    return 0;

	//*************
//	    int v, v1, v2;
//		cout << "Enter the numbers to add" << endl;
//		cin >> v1 >> v2;
//		v = v1 + v2;
//		cout << "The sum of " << v1 << " and " << v2 << " is " << v << endl;
//		return 0;

	//*****************
//	int v = 0, sum = 0;
//
//	while(v <= 10)
//	{
//		sum += v;
//		++v;
//	}
//	cout << "The sum of numbers 1 to 10 is " << sum << endl;
//	return 0;

	//****************
//	int v = 0, sum = 0;
//	for(int i = 0; i <= 10; i++)
//	{
//		sum += v;
//		v += 1;
//	}
//	cout << "The sum of numbers 1 to 10 is " << sum << endl;

	//****************
//	int sum = 0, value = 0;
//	while(cin >> value)
//	{
//		sum += value;
//	}
//	cout << "The sum of numbers is " << sum << endl;
//	return 0;

	//*****************
	//implement the counting scheme ;
	//*****************
	int val = length("victor");
	cout << val << endl;
	return 0;

}

