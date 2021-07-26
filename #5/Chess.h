#include <iostream>
using namespace std;


struct Step {
	char figure;
	char pos1[2];
	char pos2[2];
};

class Parser{
	mString str1;
public:
	Parser () {str1 = "";}

	Parser(mString str2) {str1 = str2;}

	Step Get_inf_from_string() ;

	void Print() {cout << str1;}
};

class Figure {
public:
	Step step;
	Figure (Step tmp) {step = tmp;}
	virtual void move () = 0;
};

//ферзь
class Q : public Figure {
public:
	Q(Step step) : Figure(step) {} 

	void move ();
};

//ладья
class R : public Figure {
public: 
	R(Step step) : Figure(step) {}
	void move () ;
};

//конь
class N : public Figure {
public: 
	N(Step step) : Figure(step) {}
	void move () ;
};

//король
class K : public Figure {
public: 
	K(Step step) : Figure(step) {}
	void move () ;
};

//слон
class B : public Figure {
public: 
	B(Step step) : Figure(step) {}
	void move () ;
};

class ChessCheck {
	Step st;
	mString cmd;
	Figure *fig[5] = {new K(st), new Q(st), new B(st), new N(st), new R(st)};
public:
	ChessCheck () ;

	void Get_string(mString str) ;

	void Player() ;

	void Print() {
		cout << cmd;
	}

	~ChessCheck() {
		for (int i=0;i<5;i++) if(fig[i]!=NULL) delete [] fig[i];
	}
};