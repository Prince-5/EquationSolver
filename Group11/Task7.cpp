#include"Task7.hpp"
#include<cmath>
#include<sstream>
#include<iomanip>

Task7::Task7(string p, string q, string r, string s, string t, string u) : Eqn(p, q, r, s, t, u){
  a = stof(p);
  int found = q.find("x");
  if(found==string::npos) c=stof(q);
  else {
    if(q.size()==1) q.replace(0, 1, "1");
    else{
      if(q.size()==2 && q[0]=='-') q="-1";
      else q.erase(q.size()-1, 1);  }
    b = stof(q);
   }
  found = r.find("x");
  if(found==string::npos) c=stof(r);
  else{
    if(r.size()==1) r.replace(0, 1, "1");
    else r.erase(r.size()-1, 1);
    b = stof(r);
  }

  d = stof(s);

  found = t.find("x");
  if(found==string::npos) f=stof(t);
  else {
    if(t.size()==1) t.replace(0, 1, "1");
    else t.erase(t.size()-1, 1);
    e = stof(t);  }

  found = u.find("x");
  if(found==string::npos) f=stof(u);
  else{
    if(u.size()==1) u.replace(0, 1, "1");
    else u.erase(u.size()-1, 1);
     e = stof(u);
  }
}

string Task7::solve(){
  LinearEqn l(log(a), b, c, log(d), e, f);
  stringstream stream;
  string soln = l.solve();
  float x = stof(soln);
  stream<<fixed<<setprecision(4)<<x;
  std::string s = stream.str();
  if(s!="-inf" && s!="inf")
    return "x="+s;
  else
    return "No solution";
}
