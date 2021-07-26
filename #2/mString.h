
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

    ~mString() ;
};
