#include <iostream>
#include <cmath>

class Vector 
{
        int len;
        int *v;
    public:
        Vector() {
            len = 5;
            v = new int [5];
            
            if (v==NULL) {
                std::cout << "No memory";
                exit(0);
            }
            
            for (int i=0;i<5;i++) v[i]=0;  
        }
        
        Vector(int n) {
            len = n;
            v = new int [n];
            
            if (v==NULL) {
                std::cout << "No memory";
                exit(0);
            }
            
            for (int i=0;i<n;i++) v[i]=0;  
        }
        
        Vector(const Vector & obj) {
            len = obj.len;
            v = new int[len];
            
            for (int i=0;i<len;i++) {
                v[i]=obj.v[i]; 
            }
        }
        

        void set(int arg,int coord) {
                v[coord]=arg;
        }
        
        int get(int coord) {

            if ((coord<=0)||(coord>len)) {
                std::cout << "Error";
                exit(0);               
                
            }
            return v[coord-1];
        }

        double euc_norm() {
            double sum = 0;
            double sq = 0;
            int i = 0;

            for (i=0; i<len; i++)
            {
                sq = pow(v[i],2);
                sum = sum + sq;
            }

            double res = sqrt(sum);
            return res;
        }

        int max_norm() {
            int max = 0;
            int ab = 0;
            int i = 0;

            for (i=0; i<len; i++)
            {
                ab = abs(v[i]);
                if (max<ab) max = ab;
            }
            return max;
        }

        void print() {
            for(int i = 0; i < len; i++) {
                if (i!=(len-1)) std::cout << v[i] << ", ";
                else std::cout << v[i] ;
            }
            std::cout << std::endl;
        }
        ~Vector(){
            if (v!=NULL) delete[]v;
        }

};

int main()
{
    int len = 4;
    Vector v(len);
    
    for(int i = 0; i < len; i++)
        v.set(-i*2, i);
    v.print();
  
    Vector w(v);
    w.print();
  
    std::cout << "Euc_norm " << v.euc_norm() << std::endl;
    std::cout << "Max_norm " << v.max_norm() << std::endl;
    return 0;
    
}

int main0() 
{
    int num;
    std::cout << "number of elements = ";
    std::cin >> num;
    
    if (num<1) {
        std::cout << "Error in size of array ";
        exit(0);
    }
    
    Vector z(num), w;
    int g;
    double e;
    int m;
    int k = 0;
    int now = 0;
    int get_num = 0;
    
        std::cout << "Enter value of elements\n";
        for(k=0;k<num;k++) {
            std::cout << k+1 << ") ";
            std::cin >> now;
            z.set(now,k);
        }
        
        z.print();
        std::cout << "\n";
        
        std::cout << "Enter what element do you want get ";
        std::cin >> get_num;
        
        g=z.get(get_num);
        std::cout << "result = " << g << "\n";
        
        e=z.euc_norm();
        std::cout << "euc_norm = " << e << "\n" ;
        
        m=z.max_norm();
        std::cout << "max_norm = " << m << "\n";
        
        //Vector z1(z);
        
        //z1.print();
        
        w.print();
        
        //Vector w1(w);
        
        //w1.print();
    return 0;
}
