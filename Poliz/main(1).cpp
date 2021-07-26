#include <iostream>
#include <string>
#include "Poliz.h"
using namespace std;

int main() {

	Poliz p;
	while(1){
		try {
			p.enter();
			p.poliz();
			p.count();
		    p.clear();
	    }
	    catch(const char* str) {
	    	cout << str << endl;
	    	p.clear();
	    }
	}
}