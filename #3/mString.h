#include <iostream>
class mString {
    char *s1;
    public:
    mString() ;
    
    mString(const char *str) ;
    
    int lenght();
       
    void enter();
    
    void print() ;
    
    bool isempty() ;
    
    void add(char c) ;

    void add(const char *str) ;

    void insert(char c, int pos) ;

    void insert(const char *str, int pos);
    
    void del(int pos) ;

    void del(int pos1, int pos2) ;
    
    int search(const char *str);
    
    void replace(const char *str,const char *rp) ;
    
    mString(const mString & obj) ;
    
    mString & operator=(const mString & another);

    mString operator+(const mString & another);

    bool operator>(const mString & another);

    bool operator<(const mString & another);

    bool operator>=(const mString & another);

    bool operator<=(const mString & another);

    bool operator==(const mString & another);

    char operator[](int index);
    
    mString operator*(int num); 
     
    friend mString operator*(const int num, const mString & another) ;
    
    friend std::ostream & operator << (std::ostream & os, const mString & another);
    
    friend std::istream & operator >> (std::istream & in, mString & another);

    ~mString() ;
};
