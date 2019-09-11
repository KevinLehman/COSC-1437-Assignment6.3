/*
Kevin Lehman  - 1463553
Tarrant County College - COSC 1437- Fall 2017
Assignment 3 - Week 6
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool testEmail(string);

int main()
{
	string emailAd;
	char loop = 'Y';
	
	while (loop != 'X')
	{
		cout << "Email Validation Rules: (Not official)" << endl;
		cout << "No whitespace characters allowed." << endl;
		cout << "Only one @ symbol." << endl;
		cout << "Only one . after the @ symbol" << endl;
		cout << "Must have 3 characters after the . following the @ symbol." << endl;
		cout << "Please enter an email address for validation check." << endl;
		getline(cin, emailAd);
		if (testEmail(emailAd))
		{
			cout << "Email is valid." << endl;
		}
		else
		{
			cout << "Email is invalid." << endl;
		}
		cout << "IF you wish to validate another email press Y or X to exit." << endl;
		cin >> loop;
		if (loop == 'x')
		{
			loop = toupper(loop);
		}
		cin.ignore();
	} 
	system("PAUSE");
	return 0;
}

bool testEmail(string emailAd)
{
	int countAt = 0;
	int countDot = 0;
	int findAt = emailAd.find('@');
	int findDot = emailAd.find('.', findAt);
	string afterDot = emailAd.substr(findDot+1);
	char input;
	

	for (int idx = 0; idx < emailAd.size(); idx++)
	{
		input = emailAd[idx];
		if (isspace(input))
		{
			return false;
		}
		if (input == '@')
		{
			countAt++;
			if (countAt > 1)
			{
				return false;
			}
		}
		if (countAt >= 1 && input == '.')
		{
			countDot++;
			if (countDot > 1)
			{
				return false;
			}
		}
	}
	if (afterDot.length() > 3)
	{
		return false;
	}

	return true;
}
