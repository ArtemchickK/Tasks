#include <iostream>
using namespace std;

class mStringException {
    char *err_name;
    int name_size;
public:
    mStringException() {
        err_name = NULL;
    }

    mStringException (const char *msg) ;

    mStringException (const mStringException & obj);
    
    void GetError ();

    ~mStringException () {
        if (err_name != NULL) delete[] err_name;
    }    
};