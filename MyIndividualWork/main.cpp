//My code also works for task 1.

#include "Task3.hpp"
#include "Eqn.hpp"
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    string a,b,c,d;
    vector <string> eqnlist;       //for storing all the entered equations.
    vector <string> answers;        //for storing all the corresponding answers to the equations.
    while(true)
    {
        cin>>s;
        s.erase(0,1);                   //for removing inverted commas from input.
        s.erase(s.length()-1,1);
        if(s=="stop")
        {
            for(int i=0;i<eqnlist.size();i++)                    //printing the whole log of equations and their answers after "stop" is entered.
            {
                cout<<eqnlist[i]<<'\t'<<'\t'<<'\t'<<answers[i]<<endl;
            }
            break;
        }
        else
        {


            eqnlist.push_back(s);
            int eq = s.find('=');
            string lhs = s.substr(0,eq);                    //separating lhs and rhs.
            string rhs = s.substr(eq+1,s.length()-1-eq);
            

            if(isdigit(lhs[0])==true || lhs[0]=='x')
            {
                lhs.insert(0,"+");
            }
            if(isdigit(rhs[0])==true || rhs[0]=='x')
            {
                rhs.insert(0,"+");
            }

            //solving for lhs.
            int nx=0;
            int npm=0;
            if(lhs.find('x')!=-1)
            {
                nx=1;
                for(int i=0;i<lhs.length();i++)
                {
                    if(!isdigit(lhs[i]) && lhs[i]!='x' && lhs[i]!='.')
                    {
                        npm++;
                    }
                }
            }
            else
            {
                for(int i=0;i<lhs.length();i++)
                {
                    if(!isdigit(lhs[i]) && lhs[i]!='.')
                    {
                        npm++;
                    }
                }
            }


            if(nx==0 && npm==1)
            {
                a="0";
                b=lhs;
            }
            else if(nx==1 && npm==1)
            {
                b="0";
                a=lhs.substr(0,lhs.find('x'));
            }
            else if(nx==1 && npm==2 && lhs.find('x')==lhs.length()-1)
            {
                string temp = "";
                int i=0;
                temp+=lhs[i];
                i++;
                while(isdigit(lhs[i]) || lhs[i]=='.')
                {
                    temp+=lhs[i];
                    i++;
                }
                b=temp;
                temp="";
                temp+=lhs[i];
                i++;
                while(isdigit(lhs[i]) || lhs[i]=='.')
                {
                    temp+=lhs[i];
                    i++;
                }
                a=temp;
            }
            else
            {
                string temp = "";
                int i=0;
                temp+=lhs[i];
                i++;
                while(isdigit(lhs[i]) || lhs[i]=='.')
                {
                    temp+=lhs[i];
                    i++;
                }
                a=temp;
                i++;
                temp="";
                temp+=lhs[i];
                i++;
                while((isdigit(lhs[i]) || lhs[i]=='.') && i<lhs.length())
                {
                    temp+=lhs[i];
                    i++;
                }
                b=temp;
            }

            //solving for rhs.
            nx=0;
            npm=0;
            if(rhs.find('x')!=-1)
            {
                nx=1;
                for(int i=0;i<rhs.length();i++)
                {
                    if(!isdigit(rhs[i]) && rhs[i]!='x' && rhs[i]!='.')
                    {
                        npm++;
                    }
                }
            }
            else
            {
                for(int i=0;i<rhs.length();i++)
                {
                    if(!isdigit(rhs[i]) && rhs[i]!='.')
                    {
                        npm++;
                    }
                }
            }


            if(nx==0 && npm==1)
            {
                c="0";
                d=rhs;
            }
            else if(nx==1 && npm==1)
            {
                d="0";
                c=rhs.substr(0,rhs.find('x'));
            }
            else if(nx==1 && npm==2 && rhs.find('x')==rhs.length()-1)
            {
                string temp = "";
                int i=0;
                temp+=rhs[i];
                i++;
                while(isdigit(rhs[i]) || rhs[i]=='.')
                {
                    temp+=rhs[i];
                    i++;
                }
                d=temp;
                temp="";
                temp+=rhs[i];
                i++;
                while(isdigit(rhs[i]) || rhs[i]=='.')
                {
                    temp+=rhs[i];
                    i++;
                }
                c=temp;
            }
            else
            {
                string temp = "";
                int i=0;
                temp+=rhs[i];
                i++;
                while(isdigit(rhs[i]) || rhs[i]=='.')
                {
                    temp+=rhs[i];
                    i++;
                }
                c=temp;
                i++;
                temp="";
                temp+=rhs[i];
                i++;
                while((isdigit(rhs[i]) || rhs[i]=='.') && i<rhs.length())
                {
                    temp+=rhs[i];
                    i++;
                }
                d=temp;
            }

            //passing the coefficients in the constructor.
            Task3 t(a,b,c,d);
            string answer=t.solve();
            answers.push_back(answer);
            cout<<answer<<"\n";
        }
    }
    return 0;
}