#include "Eqn.hpp"
#include<bits/stdc++.h>

Eqn :: Eqn(string p, string q, string r, string s, string t, string u){
	a = p; 
	b = q; 
	c = r;
  	d = s; 
	e = t; 
	f = u;
}

Eqn :: Eqn(float p, float q, float r, float s, float t, float  u){
  	a = to_string(p);
  	b = to_string(q);
  	c = to_string(r);
  	d = to_string(s);
  	e = to_string(t);
  	f = to_string(u);
}

Eqn::Eqn(string s1):s(s1){}

Eqn::Eqn(Eqn &E){
	s = E.s;
}

Eqn::Eqn(){}

Eqn::~Eqn(){}string Eqn :: getA(){
	return a;
}

string Eqn :: getB(){
	return b;
}

string Eqn :: getC(){
	return c;
}

string Eqn :: getD(){
	return d;
}

string Eqn :: getE(){
	return e;
}

string Eqn :: getF(){
	return f;
}
