#include <iostream>
#include "mString.h"
using namespace std;


int main1()
{
        mString a("World"), b, c;
        b = "";
        c = b;
 
        b = b + "Hello";
 
        b = 2 * b * 3 + "  " + a;
	c = b; 

        cout << a << endl;
        cout << b << endl; 
        cout << c << endl; 
	
        cout << a[0] << endl;
        cout << b[1] << endl; 
        cout << c[2] << endl; 
 

        if(a < b)
                cout << "< Less" << endl;
 
        else
                cout << "< not Less" << endl;

        if(c > b)
                cout << ">Greater" << endl;
 
        else
                cout << ">not greater" << endl;

        if(a <= b)
                cout << "<= Less eq" << endl;
 
        else
                cout << "<= not less eq" << endl;
	
	if(a >= c)
                cout << ">= Greater eq" << endl;
 
        else
                cout << ">= not greater eq" << endl;

	if(b == c)
                cout << "== Eq" << endl;
 
        else
                cout << "== not eq" << endl;


}


int main2()
{
        mString a("Mir"), b, c;
        b = "";
        c = b;
 
        b = b + "Hello";
 
        b = 1 * b * 2 + "  " + a + "XXX";
	c = b; 

        cout << a << endl;
        cout << b << endl; 
        cout << c << endl; 
	
        cout << a[0] << endl;
        cout << b[1] << endl; 
        cout << c[2] << endl; 
 

        if(b < a)
                cout << "< Less" << endl;
 
        else
                cout << "< not Less" << endl;

        if(b > c)
                cout << ">Greater" << endl;
 
        else
                cout << ">not greater" << endl;

        if(b <= a)
                cout << "<= Less eq" << endl;
 
        else
                cout << "<= not less eq" << endl;
	
	if(b >= c)
                cout << ">= Greater eq" << endl;
 
        else
                cout << ">= not greater eq" << endl;

	if(b == c)
                cout << "== Eq" << endl;
 
        else
                cout << "== not eq" << endl;


}

int main()
{
        mString a("Fox"), b, c;
        b = "";
        c = b;
 
        b = b + "Dog";
 
        b = 4 * b * 1 + "  " + a;
	c = b; 

        cout << a << endl;
        cout << b << endl; 
        cout << c << endl; 
	
        cout << a[0] << endl;
        cout << b[1] << endl; 
        cout << c[2] << endl; 
 

        if(c < b)
                cout << "< Less" << endl;
 
        else
                cout << "< not Less" << endl;

        if(c > a)
                cout << ">Greater" << endl;
 
        else
                cout << ">not greater" << endl;

        if(b <= c)
                cout << "<= Less eq" << endl;
 
        else
                cout << "<= not less eq" << endl;
	
	if(c >= a)
                cout << ">= Greater eq" << endl;
 
        else
                cout << ">= not greater eq" << endl;

	if(b == c)
                cout << "== Eq" << endl;
 
        else
                cout << "== not eq" << endl;


}

int main4()
{
        mString a("Red"), b, c;
        b = "";
        c = b;
 
        b = b + "Blue";
 
        b = 2 * b * 2 + "  " + a + b;
	c = b; 

        cout << a << endl;
        cout << b << endl; 
        cout << c << endl; 
	
        cout << a[0] << endl;
        cout << b[1] << endl; 
        cout << c[2] << endl; 
 

        if(c < b)
                cout << "< Less" << endl;
 
        else
                cout << "< not Less" << endl;

        if(c > a)
                cout << ">Greater" << endl;
 
        else
                cout << ">not greater" << endl;

        if(b <= c)
                cout << "<= Less eq" << endl;
 
        else
                cout << "<= not less eq" << endl;
	
	if(c >= a)
                cout << ">= Greater eq" << endl;
 
        else
                cout << ">= not greater eq" << endl;

	if(b == c)
                cout << "== Eq" << endl;
 
        else
                cout << "== not eq" << endl;


}

