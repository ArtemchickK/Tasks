#include <iostream>
#include "mString.h"
using namespace std;

   mString::mString() { 
        s1 = new char [1];
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
        for (j=0;j<size;j++) s1[j] = str[j];
        s1[size] = '\0';
    }
    
    void mString::enter() {
        char c;
        char *tmp;
        int i = 0 , size = 64;
        if (s1 == NULL) s1 = new char [size];
        else {
            delete []s1;
            s1 = new char [size];
        }
        
        while (c!='\n') {
            cin.get(c);
            if (i == size) {
                tmp = new char [size*2];
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
        if ((pos>size)||(pos<0)) {
            cout << "Wrong position" << endl;
            return ;
        }
        char *tmp = new char [size+2];
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
        if ((pos>size)||(pos<0)) {
            cout << "Wrong position" << endl;
            return ;
        }
        int n = 0;
        const char *check = str;
        while (*check++) n++;
        char *tmp = new char [size+n+1];

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
        if (s1 == NULL) {
            cout << "The word is empty" << endl;
            return ;
        }
        int size = lenght();
        if ((pos>=size)||(pos<0)) {
            cout << "Wrong position" << endl;
            return ;
        }
        int i = 0, tmp_str = 0;
        char *tmp = new char [size];
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

        if (s1 == NULL) {
            cout << "The word is empty" << endl;
            return ;
        }
        int size = lenght();
        
        if ((pos1>=size)||(pos1<0)) {
            cout << "Wrong position" << endl;
            return ;
        }

        if ((pos2>=size)||(pos2<0)) {
            cout << "Wrong position" << endl;
            return ;
        }

        if (pos1>pos2){
            cout << "Wrong position" << endl;
            return ;
        }

        for (int i=pos1;i<=pos2;i++) del(pos1);
    }

    int mString::search(const char *str) {
        if (str == NULL) {
            cout << "пустая подстрочка" << endl;
            return -1;
        }

        if (s1 == NULL) {
            cout << "строка пустая" << endl;
            return -1;
        }

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
        if (pos1 == -1) return ;
        int pos2 = 0;
        const char *check = str;
        while (*check++) pos2++;
        pos2 = pos2 + pos1 -1;
        del(pos1,pos2);
        insert(rp,pos1);
    }
    
  
    
    mString::mString(const mString & obj) {
        int size = lenght();
        if (size == 0) {
            s1 = new char [1];
            s1[0] = '\0';
        }
        else {
            s1 = new char [size];
            for (int i=0;i<=size;i++) {
                s1[i]=obj.s1[i]; 
            }
        }
    }

    mString::~mString() {
        if (s1!=NULL) delete[]s1;
    }
    
    void menu() {
        cout << "0 - ввести строку\n1 - определить длину строки\n2 - проверить является ли строка пустой\n3 - добавить символ в конец строки\n4 - добавить строку в конец\n5 - вставить симол в заданную позицию\n6 - вставить строку в заданную позицию\n7 - удалить символ по заданной позиции\n8 - удаление подстроки по начальной и конечной позиции\n9 - поиск подстроки в строке\n10 - замена подстроки на заданную\n11 - печать строки на экран\n12 - вызов меню\nдругая цифра - выход" << endl;
    }

int main()
{
    mString a(""), b=a;
    a.print();
    b.print();
    cout << a.lenght() << endl;
    
    mString c("Hello");
    
    for(int i = 0; i < 7; i++)
        c.del(0);
    cout << c.lenght() << endl;
    
    mString d("Forest");
    d.replace("For", "QWERTYUIOP");
    d.print();
}

/*int main0()
{
    mString z("Hello");
    z.print();
    mString s;
    mString st(s);
  
    char c;
    char *str = new char [64];
    char *str2 = new char [64];
    int pos1 = 0, pos2 = 0;
    int res = 0;
    menu();
    while (true) {
        cout << "Введите действие ";
        cin >> res;
        cin.get();
        switch (res) {
            case 0: s.enter();
                    break;
            case 1: cout << "Длина = " << s.lenght() << endl;
                    break;
            case 2: cout << s.isempty() << endl;
                    break;
            case 3: cout << " Введите символ "; 
                    cin.get(c);
                    s.add(c);
                    s.print();
                    break;
            case 4: cout << " Введите строку ";
                    cin.getline(str, 256, '\n');
                    s.add(str);
                    s.print();
                    break;
            case 5: cout << " Введите символ и позицию" << endl;
                    cin.get(c);
                    cin >> pos1;
                    s.insert(c,pos1);
                    s.print();
                    break;
            case 6: cout << " Введите строку и позицию" << endl;
                    cin.getline(str, 256, '\n');
                    cin >> pos1;
                    s.insert(str,pos1);
                    s.print();
                    break;
            case 7: cout << " Введите позицию ";
                    cin >> pos1;
                    s.del(pos1);
                    s.print();
                    break;
            case 8: cout << " Введите позиции" << endl;
                    cin >> pos1;
                    cin >> pos2;
                    s.del(pos1,pos2);
                    s.print();
                    break;
            case 9: cout << " Введите подстроку ";
                    cin.getline(str, 256, '\n');
                    cout << s.search(str) << endl;
                    break;
            case 10: cout << " Введите подстроку и замену" << endl;
                    cin.getline(str, 256, '\n');
                    cin.getline(str2, 256, '\n');
                    s.replace(str,str2);
                    s.print();
                    break;
            case 11: s.print();
                     break;
            case 12: menu();
                     break;
            
            default: return 0;

            }
    }
}*/

    
     
