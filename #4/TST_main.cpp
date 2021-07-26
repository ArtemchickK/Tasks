#include <iostream>
#include "mString.h"
#include "Except.h"
using namespace std;

int mString::count_objects=0;

void insert_tst(mString a)
{
	try{	
		a.insert('q',-1);
	}
	catch(...)
	{

		cout << "negative insert symbol exception caught" << endl;
	}
	
	try{	
		a.insert("**",-1);
	}
	catch(...)
	{

		cout << "negative insert exception caught" << endl;
	}

	try{	
		a.insert('q',a.lenght()+30);
	}
	catch(...)
	{

		cout << "negative insert symbol exception caught" << endl;
	}
	
	try{	
		a.insert("**",a.lenght()+100);
	}
	catch(...)
	{

		cout << "negative insert exception caught" << endl;
	}


}

void index_tst(mString a)
{


	try{
		cout << a[-1] << endl;
	}
	catch(...)
	{
		cout << "negative index exception caught" << endl;
	}		

	try{	
		cout << a[a.lenght()+4] << endl;
	}
	catch(...)
	{
		cout << "exceed range exception caught" << endl;
	}		

}

void  delete_tst(mString a)
{
	try{	
		a.del(1);
	}
	catch(...)
	{

		cout << "delete symbol exception  caught" << endl;
	}

	try{	
		a.del(1, 10);
	}
	catch(...)
	{

		cout << "delete substring exception  caught" << endl;
	}
}

int main()
{
	mString a("HelloHello");


	index_tst(a);
	insert_tst(a);
	try{
		for(int i=0; i < 100; i++)
			a.del(1, 2);
	}
	catch(...)
	{

		cout << "delete substring exception  caught" << endl;
	}

	a = "HelloAgain";
	try{
		for(int i=0; i < 100; i++)
			a.del(1);
	}
	catch(...)
	{

		cout << "delete symbol exception  caught" << endl;
	}

	 mString::get_number_of_objects();

}



//empty string
int main0()
{
	mString a("");
	index_tst(a);
	insert_tst(a);
	delete_tst(a);
		

}



