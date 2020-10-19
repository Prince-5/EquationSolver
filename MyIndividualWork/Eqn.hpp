#ifndef EQN
#define EQN
#include<bits/stdc++.h>
using namespace std;

class Eqn{
	string a, b, c, d, e, f;
	public:
  		Eqn(string p, string q, string r, string s, string t, string u);
  		Eqn(float p, float q, float r, float s, float t, float  u);
		string s;
  		Eqn(string s1);
		Eqn();
		Eqn(Eqn &E);
		~Eqn();
		string getA();
  		string getB();
  		string getC();
  		string getD();
  		string getE();
  		string getF();
  		virtual string solve(){
			return "WHATEVER!";
		}
};
#endif
