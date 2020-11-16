/***********************************************************************
 * Program:
 *    Lab 06, Sanitization
 *    Brother Helfrich, CS470
 * Author:
 *    Lance Bunch, Timothy Johnson, Stefano Nicotra, Gavin Olsen
 * Summary:
 *    Please include a detailed description of:
 *    1. Prompt the user for a vulnerability to mitigate
 *    2. Show the user what kind of input is valid or invalid depending on the mitigation
 ************************************************************************/
#include <iostream> // for CIN and COUT
#include <string>   // because we need to interface with strings occasionally
#include <vector>
#include <algorithm> // for converting strings to lowercase
#include <cctype>
#include <string>
#include "pair.h"
#include <regex> //for whitelisting

using std::cout;
using std::string;
using std::cin;
using std::vector;
using custom::pair;

void testCaller(int, vector<pair<string, string>>&);
string generateSQL(string&, string&);
bool checkTautology(string&);
bool checkUnion(string&);
bool checkAdditional(string&);
bool checkComment(string&);
bool checkStrong(string&);
void fillTestCases(vector<pair<string, string>>&);

/***************************
 * MAIN
 * Drive the decisions.
 **************************/
int main()
{
	vector<pair<string, string>> testCases;
	fillTestCases(testCases);

	int input;
	do
	{
		cout << "Command Injection\n";
		cout << "Options:\n"
			<< "\t1: No Mitigation\n"
			<< "\t2: Weak Mitigation - Tautology\n"
			<< "\t3: Weak Mitigation - Comment\n"
			<< "\t4: Weak Mitigation - Union Query\n"
			<< "\t5: Weak Mitigation - Additional Statement\n"
			<< "\t6: Strong Mitigation - All\n"
			<< "\t0: Quit\n"
                        << ">";
		cin >> input;
		if (input < 7 && input > 0)
		{
			testCaller(input, testCases);
		}
		else if (input != 0)
		{
			cout << "invalid input\n";
		}
	} while (input != 0);
	return 0;
}


/********************************************
 * GENERATESQL
 * Write a C++ function to accept two strings
(username and a password) and return a
 * single string (SQL) represents the query
 * used to determine if a user is
 * authenticated on a given system.
 *   INPUT username, password
 *******************************************/
string generateSQL(string& username, string& password) {
	return "SELECT authenticate FROM passwordList WHERE name='" + username + "' and passwd='"+ password + "';";
}

/***********************************************
* asciiToLower
* Returns lowercased version of given char
************************************************/
char asciiToLower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

/***********************************************
* Lowercase
* Returns lowercased version of string.
************************************************/
string lowercase(string& subject)
{
   string result = "";
   for (char const &c: subject)
   {
      result += asciiToLower(c);
   }

   return result;
}


/***********************************************
* Check Tautology
* Mitigates for tautology attacks.
* Returns bool of if string is safe.
************************************************/
bool checkTautology(string& subject)
{
   return lowercase(subject).find(" or ") != string::npos || subject.find("'") != string::npos;
}

/***********************************************
* Check Union
* Mitigates for union query attacks.
* Returns bool of if string is safe.
************************************************/
bool checkUnion(string& subject)
{
   return lowercase(subject).find(" union ") != string::npos;
}

/***********************************************
* Check Additional
* Mitigates for additional statement attacks.
* Returns bool of if string is safe.
************************************************/
bool checkAdditional(string& subject)
{
   return subject.find(";") != string::npos;
}

/***********************************************
* Check Comment
* Mitigates for additional statement attacks.
* Returns bool of if string is safe.
************************************************/
bool checkComment(string& subject)
{
   return subject.find("--") != string::npos;
}

/***********************************************
* Check Strong
* Uses strong mitigation to prevent successful attacks.
* Returns bool of if string is safe.
************************************************/
bool checkStrong(string& subject)
{
	regex whitelist("[a-zA-Z0-9_]+");
	return regex_match(subject, whitelist);
	//return checkTautology(subject) || checkUnion(subject) || checkAdditional(subject) || checkComment(subject);
}

/***********************************************
* Print Good Input
************************************************/
void printGoodInput(string username, string password)
{
   cout << "Username: [" << username << "] Password: [" << password << "]" << std::endl;
   cout << "\033[32m" << "Input identified as safe >  "<< "\033[0m" << "username: " << username << " password: " << password << std::endl;
}

/***********************************************
* Print bad Input
************************************************/
void printBadInput(string username, string password)
{
   cout << "Username: [" << username << "] Password: [" << password << "]" << std::endl;
   cout << "\033[31m" << "Malicious input identified > "  << "\033[0m" << generateSQL(username, password) << std::endl;
}


/**********************************************
* Test Caller
* Calls each test case according to which input
* is received
**********************************************/
void testCaller(int testOption, vector<pair<string, string>>& testCases)
{
   int i = 1;
	for (pair<string, string> subject : testCases)
	{
                cout << "\t -- Test case #" << i << " -- " << std::endl;
		switch (testOption)
		{
		case 1:
                        cout << "Generating raw SQL... \n";
			cout << generateSQL(subject.first, subject.second) << std::endl;
			break;
		case 2:
			if (checkTautology(subject.first) || checkTautology(subject.second))
				printBadInput(subject.getFirst(), subject.getSecond());
			else
				printGoodInput(subject.getFirst(), subject.getSecond());
			break;
		case 3:
			if (checkComment(subject.first) || checkComment(subject.second))
				printBadInput(subject.getFirst(), subject.getSecond());
			else
				printGoodInput(subject.getFirst(), subject.getSecond());
			break;
		case 4:
			if (checkUnion(subject.first) || checkUnion(subject.second))
				printBadInput(subject.getFirst(), subject.getSecond());
			else
				printGoodInput(subject.getFirst(), subject.getSecond());
			break;
		case 5:
			if (checkAdditional(subject.first) || checkAdditional(subject.second))
				printBadInput(subject.getFirst(), subject.getSecond());
			else
				printGoodInput(subject.getFirst(), subject.getSecond());
			break;
		case 6:
			if (checkStrong(subject.first) || checkStrong(subject.second))
				printBadInput(subject.getFirst(), subject.getSecond());
			else
				printGoodInput(subject.getFirst(), subject.getSecond());
			break;
		}
                i++;
	}
}

/***********************************************************
*
************************************************************/
void fillTestCases(vector<pair<string, string>>& testCases)
{
	// return "SELECT authenticate FROM passwordList WHERE name='" + username + "' and passwd='"+ password + "';";

        // typical use case scenario
	testCases.push_back((pair<string, string>("username1234", "password1234")));
	testCases.push_back((pair<string, string>("admin", "admin")));
	testCases.push_back((pair<string, string>("stefano_nicotra", "nicotra_stefano")));
	testCases.push_back((pair<string, string>("Gavin_Olsen", "Unkr4kb13_p4ssWd")));
	testCases.push_back((pair<string, string>("Timothy_Johnson", "1234")));
	testCases.push_back((pair<string, string>("Bunch_Lance", "asddsa123")));
	testCases.push_back((pair<string, string>("private", "donotenter")));
	testCases.push_back((pair<string, string>("PRIvate", "DoNotEnter")));
	testCases.push_back((pair<string, string>("testuser", "testpassword")));
	testCases.push_back((pair<string, string>("whyis6scaredof7", "bcuz789")));
	testCases.push_back((pair<string, string>("1appleaday", "k33psd0kt0r4w4y")));
	testCases.push_back((pair<string, string>("xkcd", "correcthorsebatterystaple")));
        // tautology
	testCases.push_back((pair<string, string>("root", "tautology' OR '1'='1")));
	testCases.push_back((pair<string, string>("admin", "tautology' OR 'x'='x")));
        // comment
	testCases.push_back((pair<string, string>("root';--", "commentAttack")));
	testCases.push_back((pair<string, string>("admin';--", "commentAttack")));
        // union
	testCases.push_back((pair<string, string>("union", "attack' UNION SELECT authenticate FROM passwordList; --")));
	testCases.push_back((pair<string, string>("union", "nothing' UNION SELECT * FROM userData; --")));
        // additional statement
	testCases.push_back((pair<string, string>("additionalStatement", "attack'; SELECT * FROM passwordList WHERE name='root")));
	testCases.push_back((pair<string, string>("additionalStatement", "nothing'; INSERT INTO passwordList (name, passwd) VALUES 'Bob', '1234")));
}
