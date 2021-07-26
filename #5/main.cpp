#include <iostream>
#include "mString.h"
#include "Except.h"
#include "Chess.h"
#include <cmath>
using namespace std;



int main() {
	mString str;
	ChessCheck a;
	while(1) {
		try {
			cout << "Your step: ";
			cin >> str;
		    a.Get_string(str);
		    a.Player();
		}
		catch (int a) {
			if (a == -1) cout << "Error" << endl;
			if (a == 1) return 0;
		}
		catch (mStringException & exception){
        	exception.GetError();
    	}
	}

}