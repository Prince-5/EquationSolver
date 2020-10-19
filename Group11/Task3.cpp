//ax + b = cx + d

#include<bits/stdc++.h>
#include "Task3.hpp"

Task3 :: Task3(string p, string q, string r, string s) : Eqn(p, q, r, s, "0", "0"){
            if(p=="+")
            {
                a=1;
            }
            else if(p=="-")
            {
                a=-1;
            }
            else
            {
                a=stof(p);
            }
            b=stof(q); 
            if(r=="+")
            {
                c=1;
            }
            else if(r=="-")
            {
                c=-1;
            }
            else
            {
                c=stof(r);
            }
            d=stof(s);
        }

string Task3 :: solve(){
            if(b==d)
            {
                if(a==c)
                {
                    return "Infinite solutions";
                }
                else
                {
                    return "x=0.0000";
                }            
            }
            else
            {
                if(a==c)
                {
                    return "No solution";
                }
                else
                {
                    double answer = (d-b)/(a-c);
                    int dotindex;
                    double ranswer;
                    ranswer = round(answer*10000);
                    ranswer = ranswer/10000;
                    string fanswer=to_string(ranswer);
                    for(int i=0;i<fanswer.length();i++)
                    {
                        if(fanswer[i]=='.')
                        {
                            dotindex=i;
                        }
                    }
                    //cout<<a<<b<<c<<d<<"\n";
                    return "x="+fanswer.substr(0,dotindex+5);
                }
            }
}
