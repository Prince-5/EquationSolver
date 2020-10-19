//qx + p = r or p + qx = r or qx - p = r or p - qx = r

#include<sstream>
#include<iomanip>
#include "Task1.hpp"

Task1 :: Task1(float p, float q, float r) : Eqn(p, q, r, 0, 0, 0){}

string Task1 :: solve(){
	float solution = (stof(getC()) - stof(getA())) / stof(getB());
	stringstream stream;
	stream<<fixed<<setprecision(4)<<solution;
	std::string s = stream.str();
	return "x="+s;
}
