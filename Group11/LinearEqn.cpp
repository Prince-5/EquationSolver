#include "LinearEqn.hpp"

LinearEqn::LinearEqn(float p, float q, float r, float s, float t, float  u) : Eqn(p,q,r,s,t,u){
  a=p;
  b=q;
  c=r;
  d=s; e=t; f=u;
}

string LinearEqn::solve(){
  return to_string((d*f - a*c)/(a*b - d*e));
}
