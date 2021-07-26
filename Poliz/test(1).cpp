#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <stdlib.h>
//#include <stdio.h>
#include "Poliz.h"
using namespace std;



	void Poliz::enter() {
		string new_phrase;
		getline(cin,new_phrase,'\n');
		phrase = new_phrase;
	}

	string Poliz::mult(string str1, int num) {
		char *tmp = new char[str1.length()];
		int j = 0;
		for (int i = 0; i < str1.length(); ++i)
			if (str1[i]!='"') {
				tmp[j] = str1[i];
				j++;
			}
		tmp[j] = '\0';
		string res(tmp);
		j = 0; int k = 1;
		char *tmp1 = new char[res.length()*num+3];
		tmp1[0] = '"';
		while(k < res.length()*num+1) 
			for (int i = 0; i < res.length(); ++i,++k) tmp1[k] = res[i];
		tmp1[k] = '"';
		tmp1[k+1] = '\0';
		string fin(tmp1);
		return fin;
	}

string Poliz::subtrack(string str1,string str2) {
	char* tmp = new char [str1.length()+3];
	bool b=false;
	int k=1;
	tmp[0] = '"';
	for (int i=0;i<str1.length();i++){
		b = false;
		for (int j=0;j<str2.length();j++) if (str1[i] == str2[j]) b = true;
		if (b) continue;
			else {tmp[k] = str1[i]; k++;}
	}
	tmp[k] = '"'; tmp[k+1] = '\0';
	string s(tmp);
	delete[] tmp;
	return s;
}

	string Poliz::plusto(string str1, string str2) {
		char* tmp = new char [str1.length()+str2.length()+3];
		int k = 1; tmp[0] = '"';
		for (int i=0;i<str1.size();i++) if(str1[i]!='"') { tmp[k] = str1[i]; k++; }
		for (int i=0;i<str2.size();i++) if(str2[i]!='"') { tmp[k] = str2[i]; k++; }
		tmp[k] = '"'; tmp[k+1] = '\0';
		string s(tmp);
		delete [] tmp;
		return s;
	}

	bool Poliz::is_name(char c) {
		if ((c>='a' && c<='z') || (c>='A' && c<='Z')) return true;
			else return false;
	}

	bool Poliz::is_operator(char c) {
		if ((c == '-')||(c == '+')||(c == '*')||(c=='=')) return true;
		else return false;
	}

	bool Poliz::is_num (char c) {
		if ((c >= '0') && ( c <= '9')) return true;
		else return false; 
	}

	string Poliz::to_string1(char c) {
		switch(c) {
			case '(': return "(";
			break;
			case ')': return ")";
			break;
			case '+': return "+";
			break;
			case '-': return "-";
			break;
			case '=': return "=";
			break;
			case '*': return "*";
			break;
			case '"':return " " ;
			break;
			default: return " ";
			break;
		}
	}

	int Poliz::priority (string s) {
			if (s == "(") return -1;
			if (s == ")") return -1;
			if (s == "+") return 0;
			if (s=="-") return 0;
			if (s == "=") return -1;
			if (s=="*") return 1;
	}

	void Poliz::poliz () {
	int i = 0, n1=0, n2=0;
		char* name;
		char* num;
		while(phrase[i]!='\0') {
			if (phrase[i]=='"') {
				i++;
				while (phrase[i]!='"') {
					if (phrase[i] == '\0') break;
					i++;
				}
			}
			if (phrase[i]=='(') n1++;
			if (phrase[i]==')') n2++;
			i++; 
		}
		if (n1!=n2) throw "Дисбаланс скобок";
		i = 0;
		stack <string> st;
		while(phrase[i]!='\0') {
			
			while (phrase[i] == ' ') {
				i++;
				continue;
			}

			if (is_name(phrase[i])) {
				PART part;
				int j = 0;
				name = new char [16];
				while ((is_name(phrase[i])) || (is_num(phrase[i]))) {
					name[j] = phrase[i];
					j++; i++;
				}
				name[j] = '\0';
				string sname(name);
				part.content = sname;
				part.type = "name";
				massive.push_back(part); 
				delete [] name;
				continue;
			}

			if (is_operator(phrase[i])) {
				PART part;
				string value = to_string1(phrase[i]);
				while ((!st.empty()) && (priority(st.top()) >= priority(value))) {
					part.content = st.top();
					part.type = "operator";
					massive.push_back(part);
					st.pop();
				}
				st.push(value);
				int k=i+1;
				while(phrase[k]==' ') k++;
				if (phrase[k]=='+') throw "Две операции + подряд";
				if (phrase[k]=='-') throw "Две операции - подряд";
				if (phrase[k]=='*') throw "Две операции * подряд";
				if (phrase[k]=='=') throw "Две операции = подряд";
				if ((!is_num(phrase[k])) && (!is_name(phrase[k])) && (phrase[k]!='"') && (phrase[k]!='(')) throw "Неверное выражение";
				i++;
				continue;
			}

			if (is_num(phrase[i])) {
				PART part;
				int j = 0;
				num = new char [16];
				while (is_num(phrase[i])) {
					num[j] = phrase[i];
					j++; i++;
				}
				if (is_name(phrase[i])) throw "Название переменной начинается не с буквы";
				num[j] = '\0';
				string snum(num);
				part.content = snum;
				part.type = "num";
				massive.push_back(part); 
				delete [] num;
				continue;
			}

			if (phrase[i] == '"') {
				PART part;
				int j=0;
				name = new char [64];
				while (1) {
					name[j] = phrase[i]; j++; i++;
					if (phrase[i] == '"') break;
					if (i == phrase.size()) throw "Дисбаланс кавычек";
				}
				if (!is_operator(phrase[i+1]) && (phrase[i+1])!='\0' && (phrase[i+1])!=' ' && (phrase[i+1])!=')') throw "Вложенные кавычки";
				name[j] = '"';
				name[j+1] = '\0';
				string sname(name);
				part.content = sname;
				part.type = "quote";
				massive.push_back(part); 
				delete [] name;
				i++;
				continue;
			} 

			if (phrase[i] == '(') {
				string value = to_string1(phrase[i]);
				st.push(value);
				i++;
				continue;
			}

			if (phrase[i] == ')') {
				PART part;
				if (st.empty()) throw "Дисбаланс скобок";	
				while (st.top()!="(") {
					part.content = st.top();
					part.type = "operator";
					massive .push_back(part);
					st.pop();
					if (st.empty()) throw "Дисбаланс скобок";  
				}
				st.pop();
				i++;
				continue;
			}

			if (!is_name(phrase[i]) && !is_operator(phrase[i]) && !is_num(phrase[i]) && (phrase[i]!=')')
					&& (phrase[i]!='(') && phrase[i]!='"') throw "Неверное выражение";
		}

		while(!st.empty()) {
			PART part;
			part.content = st.top();
			part.type = "operator";
			massive.push_back(part);
			st.pop();
		}
	}

	void Poliz::show_poliz() {
		cout << "poliz size = " << massive.size() << " poliz: ";
		for (int k = 0;k<massive.size();k++) 
			cout << massive[k].content << "(" << massive[k].type << ") " ;
		cout << endl;
		cout << "saved: ";
		for (int k = 0;k<last.size();k++) 
			cout << last[k].elem << '('<< last[k].content<< ')' << ' ';
		cout << endl;
	}

	void Poliz::count() {
		stack <PART> st;
		PART tmp1,tmp2,oper;
		PART res;
		int num = 0;
		bool eq=false, pr=false;
		int i=0;

		if (massive[0].content == "print") {
			pr = true;
			i = 1;
		}
		if (massive[0].content == "exit")  { 
			clear(); last.clear(); exit(0);
		}
		
		
		for (int k=0;k<massive.size();k++) if (massive[k].content == "print" && k!=0) throw "Использование print в качестве имени переменной";
		for (int k=0;k<massive.size();k++) if (massive[k].content == "exit" && k!=0) throw "Использование exit в качестве имени переменной";
		for (int k=0;k<massive.size();k++) if (massive[k].content == "=") eq=true;

		while(i<massive.size()) {
			if ((massive[i].type == "name") || (massive[i].type == "quote") || (massive[i].type == "num")) {
				st.push(massive[i]); i++;
				continue; 
			}

			if (massive[i].type == "operator") {
				if (st.empty()) throw "Неверная запись выражения";
				tmp1 = st.top(); st.pop(); if (st.empty()) throw "Неверная запись выражения";
				tmp2 = st.top(); st.pop(); 
				oper.content = massive[i].content;
				oper.type = "operator";
				res = make_operation(tmp2,tmp1,oper);
				num++;
				st.push(res); i++;
				continue;
			}
		}

		PART fin = st.top(); st.pop();
		if (!st.empty()) throw "Несколько переменных подряд";
		if (pr) { 
			if (fin.type == "name" ) {
				bool not_find = true; 
				for (int j = 0; j < last.size(); ++j)
							if (last[j].elem == fin.content) {
								cout << "~result = " << last[j].content << endl;
								not_find = false;
							}
				if (not_find && massive.size()!=2) cout << "~result = " << fin.content << endl;
					else if (not_find && massive.size()==2) throw "Неинициализированная переменная";
			}
			else cout << "~result = " << fin.content << endl;
		}

		if (!eq && num && !pr) {
			cout << "~result = " << fin.content << endl;
		}


	}

	string Poliz::to_string(int n) {
		char buf[40];
		sprintf(buf,"%d",n);
		return buf;
	}

	PART Poliz::make_operation(PART str1,PART str2,PART op) {
		bool b;
		string tmp1,tmp2;
		if (str1.type == "name" && op.content!="=") {
			bool not_exist = true;
			for (int i=0;i<last.size();i++) {
				if (str1.content == last[i].elem) {
					tmp1 = last[i].content;
					not_exist = false;
				}
			}
			if (not_exist) throw "Неинициализированная переменная";
		}

		if (str2.type == "name") {
			bool not_exist = true;
			for (int i=0;i<last.size();i++) {
				if (str2.content == last[i].elem) {
					tmp2 = last[i].content;
					not_exist = false;
				}
			}
			if (not_exist) throw "Неинициализированная переменная";
		}
		PART res;
		if (op.content == "+") {
			if (str1.type == "num" && str2.type == "num") {
				res.type = "num";
				res.content = to_string(stoi(str1.content)+stoi(str2.content));
				return res;
			}
			else if(str1.type == "quote" && str2.type == "quote")  {
				res.type = "quote";
				res.content = plusto(str1.content,str2.content);
				return res;
			}
				else if(str1.type == "quote" && str2.type == "name") {
					res.type = "quote";
					res.content = plusto(str1.content,tmp2);
					return res;
				}
					else if(str1.type == "name" && str2.type == "quote") {
						res.type = "quote";
						res.content = plusto(tmp1,str2.content);
						return res;
					}
						else if(str1.type == "name" && str2.type == "name") {
							res.type = "quote";
							res.content = plusto(tmp1,tmp2);
							return res;
						}
							else throw "Невозможная операция";
						
		}
		
		if (op.content == "-") {
			if (str1.type == "num" && str2.type == "num") {
				res.type = "num";
				res.content = to_string(stoi(str1.content)-stoi(str2.content));
				return res;
			}
			else if(str1.type == "quote" && str2.type == "quote")  {
				res.type = "quote";
				res.content = subtrack(str1.content, str2.content);
				return res;
			}
				else if(str1.type == "quote" && str2.type == "name") {
					res.type = "quote";
					res.content = subtrack(str1.content,tmp2);
					return res;
				}
					else if(str1.type == "name" && str2.type == "quote") {
						res.type = "quote";
						res.content = subtrack(tmp1,str2.content);
						return res;
					}
						else if(str1.type == "name" && str2.type == "name") {
							res.type = "quote";
							res.content = subtrack(tmp1, tmp2);
							return res;
						}
							else throw "Невозможная операция";
						
		}

		if (op.content == "*") {
			if (str1.type == "num" && str2.type == "num") {
				res.type = "num";
				res.content = to_string(stoi(str1.content)*stoi(str2.content));
				return res;
			}
				else if(str1.type == "num" && str2.type == "name"){
					res.type = "quote";
					res.content = mult(tmp2,stoi(str1.content));
					return res;
				}
					else if(str1.type == "name" && str2.type == "num"){
						res.type = "quote";
						res.content = mult(tmp1,stoi(str2.content));;
						return res;
					}
						else if(str1.type == "num" && str2.type == "quote"){
							res.type = "quote";
							res.content = mult(str2.content,stoi(str1.content));
							return res;
						}
							else if(str1.type == "quote" && str2.type == "num"){
								res.type = "quote";
								res.content = mult(str1.content,stoi(str2.content));
								return res;
							}
								else throw "Невозможная операция";
							}

			if (op.content == "=") {
				if (str1.type == "name" && str2.type == "quote") {
					ELEMENT el;
					bool not_exist = true;
					res.type = "name";
					res.content = str2.content;
					el.elem = str1.content;
					el.content = str2.content;
					for (int i = 0; i < last.size(); ++i)
							if (last[i].elem == str1.content) {
								last[i] = el;
								not_exist = false;
							}
					if (not_exist) last.push_back(el);
					return res;
				}
					else if (str1.type == "name" && str2.type == "name") {
						ELEMENT el;
						bool not_exist = true;
						res.type = "name";
						res.content = tmp2;
						el.elem = str1.content;
						el.content = tmp2;
						for (int i = 0; i < last.size(); ++i)
							if (last[i].elem == str1.content) {
								last[i] = el;
								not_exist = false;
							}
						if (not_exist) last.push_back(el);
						return res;
					}
						else throw "Неверное присваивание";
			}
		
		
	}
