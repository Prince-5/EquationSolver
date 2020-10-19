#ifndef TASK7
#define TASK7

#include"LinearEqn.hpp"

class Task7: public Eqn{
  float a,b,c,d,e,f;
public:
  Task7(string p, string q, string r, string s, string t, string u);

  string solve();

};

#endif
