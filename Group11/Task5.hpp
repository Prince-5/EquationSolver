#ifndef TASK5
#define TASK5
#include<bits/stdc++.h>
#include"Eqn.hpp"

using namespace std;

void exchange(int*,int*);
class Task5: public Eqn
{
	public:
		int** M;
		//string s;
		Task5();
		Task5(string S1);
		Task5(Task5 &H);
		~Task5();
		string solve();
};
#endif
