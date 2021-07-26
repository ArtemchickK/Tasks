#include <iostream>
#include "mString.h"
#include "Except.h"
#include "Chess.h"
using namespace std;


    ChessCheck::ChessCheck (){
        mString tmp;
        cmd = tmp;
        st.figure = ' ';
        for (int i=0;i<2;i++){
            st.pos1[i] = ' ';
            st.pos2[i] = ' ';
        }
for (int i=0;i<5;i++) if(fig[i]!=NULL) delete [] fig[i];
        fig[0] = new K(st);
        fig[1] = new Q(st);
        fig[2] = new B(st);
        fig[3] = new N(st);
        fig[4] = new R(st);
    }

    void ChessCheck::Player() {
        switch (st.figure) {
            case 'K': fig[0]->move();
                      break; 
            case 'Q': fig[1]->move();
                      break;
            case 'B': fig[2]->move();
                      break; 
            case 'N': fig[3]->move();
                      break;
            case 'R': fig[4]->move();
                      break; 
            default : break;
        }
    }

    void ChessCheck::Get_string(mString str) {
        mString tmp1("Exit");
        mString tmp2("exit");

        if ((str == tmp1)||(str == tmp2)) throw 1;
        else cmd = str;

        Parser par(cmd);
        Step step;
        step = par.Get_inf_from_string();
        st.figure = step.figure;
        for (int i=0;i<2;i++){
            st.pos1[i] = step.pos1[i];
            st.pos2[i] = step.pos2[i];
        }
for (int i=0;i<5;i++) if(fig[i]!=NULL) delete [] fig[i];
        fig[0] = new K(st);
        fig[1] = new Q(st);
        fig[2] = new B(st);
        fig[3] = new N(st);
        fig[4] = new R(st);
    }

//слон
    void B::move () {
        
        if (abs(step.pos1[0]-step.pos2[0]) == abs(step.pos1[1]-step.pos2[1])) cout << "Ok" << endl;
        else cout << "Error" << endl;
        return ;
    }
//король
    void K::move () {
        
        if (abs(step.pos1[0]-step.pos2[0])<=1 && abs(step.pos1[1]-step.pos2[1])<=1 ) cout << "Ok" << endl;
        else cout << "Error" << endl;
        return ;
    }

//конь
    void N::move () {
       
        if ( ( abs(step.pos1[0] - step.pos2[0]) == 1 && abs(step.pos1[1] - step.pos2[1]) == 2) || ( abs(step.pos1[0] - step.pos2[0]) == 2 &&
        abs (step.pos1[1] - step.pos2[1]) == 1) ) cout << "Ok" << endl;
        else cout << "Error" << endl; 
        return ;
    }

//ладья
    void R::move () {
        
        if ((step.pos1[0]-step.pos2[0] == 0) || (step.pos1[1]-step.pos2[1] == 0) ) cout << "Ok" << endl;
        else cout << "Error" << endl;
        return ;
    }

//ферзь
    void Q::move () {
       
        if ( (abs(step.pos1[0]-step.pos2[0]) == abs(step.pos1[1]-step.pos2[1])) || (step.pos1[0]-step.pos2[0] == 0) 
                || (step.pos1[1]-step.pos2[1] == 0)) cout << "Ok" << endl;
        else cout << "Error" << endl;
        return ;
    }

    Step Parser::Get_inf_from_string() {
        Step step;
        if (str1.lenght()<7) throw -1;

        if (str1[2]==str1[5] && str1[3] == str1[6]) throw -1;

        if (str1[0]!='K'&&str1[0]!='Q'&&str1[0]!='N'&&str1[0]!='B'&&str1[0]!='R') throw -1;
        else step.figure = str1[0];

        if (str1[1]!=' ') throw -1;

        if ((str1[2]<'a')||(str1[2]>'a'+7)) throw -1;
        else step.pos1[0] = str1[2];

        if ((str1[3]<'1')||(str1[3]>'8')) throw -1;
        else step.pos1[1] = str1[3];

        if (str1[4]!=' ') throw -1;

        if ((str1[5]<'a')||(str1[5]>'a'+7)) throw -1;
        else step.pos2[0] = str1[5];

        if ((str1[6]<'1')||(str1[6]>'8')) throw -1;
        else step.pos2[1] = str1[6];

        return step;        
    }



    mStringException::mStringException (const char *msg) {
        int size = 0;
        while(msg[size]!='\0') size++;
        err_name = new char [size+1];
        name_size = size;
        for (int j=0;j<size;j++) err_name[j] = msg[j];
        err_name[size] = '\0'; 
    }

    mStringException::mStringException (const mStringException & obj) {
        name_size = obj.name_size;
        err_name = new char [name_size+1];
            for (int i=0;i<name_size;i++)
                err_name[i]=obj.err_name[i]; 
        err_name[name_size] = '\0';
    }

    void mStringException::GetError () {
        if (err_name == NULL) cout << "Unknown error" << endl;
        cout << err_name << endl;
    }


   mString::mString() { 
        s1 = new char [1];
        if (s1 == NULL) throw(mStringException("Ошибка выделения памяти"));
        s1[0] = '\0';
    }
    
    
   int mString::lenght() {
        if (s1 == NULL) return 0;
        
        int n = 0;
        while (s1[n]!='\0'){
             n++;
        } 
        return n;
    }

    mString::mString(const char *str) {
        int i = 0, j = 0;
        int size = 0;
        while(str[size]!='\0') size++;
        s1 = new char [size+1];
        if (s1 == NULL) throw (mStringException("Ошибка выделения памяти"));
        for (j=0;j<size;j++) s1[j] = str[j];
        s1[size] = '\0';
    }
    
    void mString::enter() {
        char c;
        char *tmp;
        int i = 0 , size = 64;
        if (s1 == NULL)
            s1 = new char [size];
        else {
            delete []s1;
            s1 = new char [size];
        }

        if (s1 == NULL) throw(mStringException("Ошибка выделения памяти")); 
        
        while (c!='\n') {
            cin.get(c);
            if (i == size) {
                tmp = new char [size*2];
                if (tmp == NULL) throw(mStringException("Ошибка выделения памяти"));
                for (int j=0;j<size;j++) tmp[j] = s1[j];
                delete [] s1;
                s1 = tmp; 
                size*=2;
            }
            s1[i] = c;
            i++;
        }
        s1[i-1] = '\0';
    }
    
    void mString::print() {
        if (s1 == NULL ) {
            cout << " " << endl;
            return ;
        }
        cout << s1 << endl;
    }
    
    bool mString::isempty(){
        char *tmp = s1;
        if (tmp[0] == '\0') return true;
        else return false;
    }
    
    void mString::add(char c) {
        int i = 0;
        int size = lenght();
        char *tmp = new char [size+2];
        if (tmp == NULL) throw(mStringException("Ошибка выделения памяти"));
        for (i=0;i<size;i++) {
            tmp[i] = s1[i]; 
        }
        tmp[size] = c;
        tmp[size+1] = '\0';
        if (s1!=NULL) delete[]s1;
        s1 = tmp;
    }

    void mString::add(const char *str) {
        int i = 0, j = 0;;
        int size = lenght();
        int n = 0;
        const char *check = str;
        while (*check++) n++;

        char *tmp = new char [size+n+2];
        if (tmp == NULL) throw(mStringException("Ошибка выделения памяти"));

        for (i=0;i<size;i++) {
            tmp[i] = s1[i];
            j++; 
        }

        for (i=0;i<n;i++) {
            tmp[j]=str[i];
            j++; 
        }
        tmp[size+n+1] = '\0';
        if (s1!=NULL) delete[]s1;
        s1 = tmp; 
    }

    void mString::insert(char c, int pos) {
        int size = lenght();
        if ((pos>size)||(pos<0)) throw (mStringException("Неправильная позиция"));
        char *tmp = new char [size+2];
        if (tmp == NULL) throw(mStringException("Ошибка выделения памяти"));
        int i = 0, pos_tmp = 0, pos_str = 0;

        for (i=0;i<pos;i++) {
            tmp[i]=s1[i];
            pos_str++;
            pos_tmp++;
        }

        tmp[pos_tmp] = c;

        for (i=pos_str;i<size;i++) {
            tmp[pos_tmp+1] = s1[i];
            pos_tmp++;
        }

        tmp[size+1] = '\0';
        if (s1!=NULL) delete[]s1;
        s1 = tmp;
    }

    void mString::insert(const char *str, int pos)
    {
        int size = lenght();
        if ((pos>size)||(pos<0)) throw (mStringException("Неправильная позиция"));
        int n = 0;
        const char *check = str;
        while (*check++) n++;
        char *tmp = new char [size+n+1];
        if (tmp == NULL) throw(mStringException("Ошибка выделения памяти"));
        int i = 0, pos_tmp = 0, pos_str = 0;

        for (i=0;i<pos;i++) {
            tmp[i]=s1[i];
            pos_str++;
            pos_tmp++;
        }

        for (i=0;i<n;i++){
            tmp[pos_tmp] = str[i];
            pos_tmp++;
        }

        for (i=pos_str;i<size;i++) {
            tmp[pos_tmp] = s1[i];
            pos_tmp++;
        }

        tmp[size+n] = '\0';
        if (s1!=NULL) delete[]s1;
        s1 = tmp;
    }
    
    void mString::del(int pos) {
        if (s1 == NULL) throw (mStringException("Пустое слово"));
        int size = lenght();
        if ((pos>=size)||(pos<0)) throw (mStringException("Неправильная позиция"));
        int i = 0, tmp_str = 0;
        char *tmp = new char [size];
        if (tmp == NULL) throw(mStringException("Ошибка выделения памяти"));
        for (i=0;i<pos;i++){
            tmp[i]=s1[i];
            tmp_str++;
        }
        tmp_str++;
        for (i=tmp_str;i<size;i++){
            tmp[i-1]=s1[i];
        }
        tmp[size-1]='\0';
        if (s1!=NULL) delete[]s1;
        s1 = tmp; 
    }

    void mString::del(int pos1, int pos2) {

        if (s1 == NULL) throw(mStringException("Пустое слово"));
        int size = lenght();
        
        if ((pos1>=size)||(pos1<0)) throw (mStringException("Неправильная позиция"));
        if ((pos2>=size)||(pos2<0)) throw (mStringException("Неправильная позиция"));
        if (pos1>pos2) throw (mStringException("Неправильная позиция"));

        for (int i=pos1;i<=pos2;i++) del(pos1);
    }

    int mString::search(const char *str) {
        if (str == NULL) throw (mStringException("Пустая подстрочка"));

        if (s1 == NULL) throw (mStringException("Пустое слово"));

        int size = lenght();
        int i = 0, j =0, current = 0, now = 0;
        int size_str = 0;

        if (size_str>size) return -1;
        char *tmp = s1;
        bool b = true;
        const char *check = str;
        while (*check++) size_str++;

        for (i=0;i<size;i++) {
            if (tmp[i]!=str[j]) continue;
            else {
                current = i;
                now = i;
                for (j=0;j<size_str;j++) {
                    if (tmp[current]!=str[j]) {
                        b = false;
                        break;
                    }
                    else  {
                        current++;
                        if (current>size) return -1;
                    }
                }
                if (b) return now;
                else {
                    j = 0;
                    b = true;
                } 
            }
        }
        return -1;
    }

    void mString::replace(const char *str,const char *rp) { 
        if (rp == NULL) {
            return ;
        }
        int pos1 = search(str);
        if (pos1 == -1) throw (mStringException("Заданная подстрока не найдена"));
        int pos2 = 0;
        const char *check = str;
        while (*check++) pos2++;
        pos2 = pos2 + pos1 -1;
        del(pos1,pos2);
        insert(rp,pos1);
    }
    
  
    
     mString::mString(const mString & obj) {
        int size = 0;
        while (obj.s1[size]!='\0') size++;
            s1 = new char [size+1];
            if (s1 == NULL) throw (mStringException("Ошибка выделения памяти"));
            for (int i=0;i<size;i++) {
                s1[i]=obj.s1[i]; 
            }
            s1[size] = '\0';
          
    }

    mString::~mString() {
        if (s1!=NULL) delete[]s1;
    }
    
    mString & mString::operator=(const mString & another) {
        int size = 0;
        const char *check = another.s1;
        while (*check++) size++;
        
        if (this->s1!=NULL) delete [] this->s1;
        this->s1 = new char [size+1];
        if (this->s1 == NULL) throw (mStringException("Ошибка выделения памяти"));

        for (int i=0;i<size;i++) this->s1[i] = another.s1[i];
        this->s1[size] = '\0';
        return *this;
    }

    mString mString::operator+(const mString & another) {
        mString tmp;
        int i = 0;
        int size = 0;
        const char *check = another.s1;
        while (*check++) size++;
        
        if (tmp.s1!=NULL) delete [] tmp.s1;
        tmp.s1 = new char [this->lenght()+size+1];
        if (tmp.s1 == NULL) throw (mStringException("Ошибка выделения памяти"));
        for(;i<this->lenght();i++) tmp.s1[i] = this->s1[i];
        for(int j=0;j<size;j++,i++) tmp.s1[i] = another.s1[j];
        tmp.s1[this->lenght()+size] = '\0';
        return tmp; 
    }

    bool mString::operator>(const mString & another) {
        int i = 0;
        for(;this->s1[i]==another.s1[i];++i);
        if ((this->s1[i]=='\0')&&(another.s1[i]=='\0')) return false;
        if (another.s1[i]=='\0') return true;
        if (this->s1[i]=='\0') return false;
        if (another.s1[i]<this->s1[i]) return true;
        else return false;
    }
    
    bool mString::operator<(const mString & another){
        int i = 0;
        for(;this->s1[i]==another.s1[i];++i);
        if ((this->s1[i]=='\0')&&(another.s1[i]=='\0')) return false;
        if (this->s1[i]=='\0') return true;
        if (another.s1[i]=='\0') return false;
        if (another.s1[i]>this->s1[i]) return true;
        else return false; 
    }

    bool mString::operator<=(const mString & another){
        int i = 0;
        for(;this->s1[i]==another.s1[i];++i);
        if ((this->s1[i]=='\0')&&(another.s1[i]=='\0')) return true;
        if (this->s1[i]=='\0') return true;
        if (another.s1[i]=='\0') return false;
        if (another.s1[i]>this->s1[i]) return true;
        else return false; 
    }

    bool mString::operator>=(const mString & another) {
        int i = 0;
        for(;this->s1[i]==another.s1[i];++i);
        if ((this->s1[i]=='\0')&&(another.s1[i]=='\0')) return true;
        if (another.s1[i]=='\0') return true;
        if (this->s1[i]=='\0') return false;
        if (another.s1[i]<this->s1[i]) return true;
        else return false;
    }

    bool mString::operator==(const mString & another) {
        int size = 0;
        const char *check = another.s1;
        while (*check++) size++;
        
        if (this->lenght()!=size) return false;
        for(int i=0;i<size;i++) {
            if (this->s1[i]!=another.s1[i]) return false;
        }
        return true;
    }

    char mString::operator[](int index) {
        if ((index>=this->lenght())||(index<0)) {
            throw(mStringException("Неверный диапозон"));
            return '\n';
        }
        return this->s1[index];    
    }
    
    ostream & operator << (ostream & os, const mString & another){
        if ((another.s1==NULL)||(another.s1[0]=='\0')) {
            os << "~string: " << endl;
            return os;
        }
        os << "~string: " << another.s1 << endl;
        return os;
    }
    
    istream & operator >> (istream & in, mString & another) {
        in.getline(another.s1,256,'\n');
        return in;
    } 
    
    mString mString::operator*(int num) {
        int size = num*this->lenght();
        mString tmp;
        if (tmp.s1!=NULL) delete[] tmp.s1;
        tmp.s1 = new char [size+1];
        if (s1 == NULL) throw (mStringException("Ошибка выделения памяти"));
        int i=0;
        while (i < size) {
            for(int j=0;j<this->lenght();j++,i++)
                tmp.s1[i] = this->s1[j];    
        }
        tmp.s1[size] = '\0';
        return tmp;
    }

    mString operator*(const int num, const mString & another) {
        int n = 0;
        const char *check = another.s1;
        while (*check++) n++;

        int size = num*n;
        mString tmp;
        if (tmp.s1!=NULL) delete[] tmp.s1;
        tmp.s1 = new char [size+1];
        if (tmp.s1 == NULL) throw (mStringException("Ошибка выделения памяти"));
        int i=0;
        while (i < size) {
            for(int j=0;j<n;j++,i++)
                tmp.s1[i] = another.s1[j];    
        }
        tmp.s1[size] = '\0';
        return tmp;
    }