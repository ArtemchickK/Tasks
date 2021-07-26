#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct ELEMENT
{
	string elem;
	string content;
};

struct PART
{
	string content;
	string type;
};

class Poliz
{
	vector <PART> massive;
	vector <ELEMENT> last;
	string phrase;
public:

	Poliz() {}

	void enter() ;

	string mult(string str1, int num) ;

	string subtrack(string str1,string str2) ;

	string plusto(string str1, string str2) ;

	void clear() {
		massive.clear();
	}
	
	bool is_name(char c) ;

	bool is_operator(char c) ;

	bool is_num (char c) ;

	string to_string1(char c) ;

	int priority (string s) ;

	void poliz () ;

	void show_poliz() ;

	void count() ;

	string to_string(int n) ;

	PART make_operation(PART str1,PART str2,PART op) ;

	~Poliz() {
		last.clear(); massive.clear();
	}

};

