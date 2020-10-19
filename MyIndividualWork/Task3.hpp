#ifndef TASK3
#define TASK3
#include "Eqn.hpp"
#include<bits/stdc++.h>

using namespace std;

class Task3 : public Eqn{
	float a, b, c, d;
  	public:
        	Task3(string p, string q, string r, string s);
        	string solve();
};
#endif
