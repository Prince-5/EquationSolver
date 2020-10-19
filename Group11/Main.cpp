#include<bits/stdc++.h>
#include<boost/algorithm/string.hpp>
#include "Eqn.hpp"
#include "Task1.hpp"
#include "Task3.hpp"
#include "Task5.hpp"
#include "Task6.hpp"
#include "LinearEqn.hpp"
#include "Task7.hpp"

int count(string target, string s){
  int occurrences = 0;
   std::string::size_type pos = 0;
   while ((pos = s.find(target, pos )) != std::string::npos) {
          ++ occurrences;
          pos += target.length();
   }
   return occurrences;
}

int main(){
	string solution;
	Eqn *task;
	while(true){
		string s;	
		cin>>s;
		if(s.compare("stop") == 0)
            		break;
		else{				
			int isTask1 = 1, isTask3 = 0, isTask5 = 0, isTask6 = 0, isTask7 = 0, occurence = 0, positionOfx = -1, positionOfOperator = -1, positionOfEqualsTo = -1;
			for(int i = 0; i < s.length(); i++){
				if(s[i] == 'y' || s[i] == '^' || s[i] == 'z' || s[i] == 's' || s[i] == 'l'){
					isTask1 = 0;
					isTask3 = 0;
					break;	
				}   
				if(s[i] == 'x')
					if(!occurence){
						positionOfx = i;
						occurence = 1;
					}else{
						isTask1 = 0;
						isTask3 = 1;
						break;
					}
				if(s[i] == '+' || s[i] == '-')
					if(i != 1)
						if(positionOfOperator == -1)
							positionOfOperator = i;
				if(s[i] == '=')
					positionOfEqualsTo = i;
			}
			if(!isTask1 && !isTask3)
				for(int i = 0; i < s.length(); i++){
					if(s[i] == 'z'){
						isTask5 = 1;
						break;
					}
					if(s[i] == 's'){
						isTask6 = 1;
						break;
					}
					if(s[i] == '^'){
						isTask7 = 1;
						break;
					}					
				}		 
			if(isTask1){
				float p, q;
				string str;
				if(positionOfOperator != -1)
					if(positionOfx < positionOfOperator){
						str = s.substr(1, positionOfx - 1);
						if(str.compare("") == 0 || str.compare("-") == 0){
							if(str.compare("") == 0)
								q = 1;
							else
								q = -1;
						}else
							q = stof(str); 	
						p = stof(s.substr(positionOfOperator + 1, positionOfEqualsTo - 1));
						if(s[positionOfOperator] == '-')
							p = -p;	
					}else{ 
						p = stof(s.substr(1, positionOfOperator - 1));
						str = s.substr(positionOfOperator + 1, positionOfx - 1);
						if(str.compare("") == 0 || str.compare("-") == 0){
							if(str.compare("") == 0)
								q = 1;
							else
								q = -1;
						}else{
							q = stof(str); 	
							if(s[positionOfOperator] == '-')
								q = -q;
						}	
					}
				else{
					p = 0;
					str = s.substr(1, positionOfx - 1);
						if(str.compare("") == 0 || str.compare("-") == 0){
							if(str.compare("") == 0)
								q = 1;
							else
								q = -1;
						}else
							q = stof(str); 	
				}
				if(q != 0){
					float r = stof(s.substr(positionOfEqualsTo + 1, s.length() - 2));
					Task1 task1(p, q, r);
					task = &task1;
					solution = task->solve();      
				}else
					cout<<"Infinite solution\n";
			}else if(isTask3){
			    string a, b, c, d;	
			    s.erase(0,1);                   //for removing inverted commas from input.
        		    s.erase(s.length()-1,1);
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
			    Task3 task3(a,b,c,d);
			    task = &task3;
			    solution = task->solve();
			}else if(isTask5){
				s.erase(0,1);                   //for removing inverted commas from input.
        		    	s.erase(s.length()-1,1);
				Task5 task5(s);
				solution = task5.solve();
			}else if(isTask6){
				Task6 task6(s);
				solution = task6.solve();
				//printf("%0.4f \n", obj.getgradient());
			}else if(isTask7){
				  s.erase(0,1);
				  s.erase(s.length()-1, 1);
				  vector<string> res;
				  vector<string>r1;
				  vector<string>r2, r3;
				  size_t found = s.find("-");
				  if(found != string::npos)
				    s.replace(found, 1, "+-");

				  while(found != string::npos){
				    found = s.find("-", found+2);
				    if (found != string::npos)  {
				      s.replace(found, 1, "+-");
				    }
				    else break;
				  }

				  std::string delm("+()^");
				  boost::split(r1, s, boost::is_any_of("="));

				  int ind = r1[0].find("^");
				  int ind1 = r1[1].find("^");
				  if(ind == string::npos) r1[0].append("^(1)");
				  if(ind1 == string::npos) r1[1].append("^(1)");

				  found = r1[0].find("+");
				  //No of + should be one more that no of -
				  int c1 = count("+", r1[0]);
				  int c2 = count("-", r1[0]);

				  if(c1!=0 && c1<c2){
				    if(r1[0].find("x")!=string::npos) r1[0].append("+0");
				    if(r1[0].find("x")==string::npos) r1[0].append("+0x");
				  }
				  if(c1==0){
				    if(r1[0].find("x")!=string::npos) r1[0].append("+0");
				    if(r1[0].find("x")==string::npos) r1[0].append("+0x");
				  }


				  found = r1[1].find("+");
				  //No of + should be one more that no of -
				  c1 = count("+", r1[1]);
				  c2 = count("-", r1[1]);

				  if(c1!=0 && c1<c2){
				    if(r1[1].find("x")!=string::npos) r1[1].append("+0");
				    if(r1[1].find("x")==string::npos) r1[1].append("+0x");
				  }
				  if(c1==0){
				    if(r1[1].find("x")!=string::npos) r1[1].append("+0");
				    if(r1[1].find("x")==string::npos) r1[1].append("+0x");
				  }

				  boost::split(r2, r1[0], boost::is_any_of(delm));
				  boost::split(r3, r1[1], boost::is_any_of(delm));

				  vector<string> result;

				  for(int i=0; i<r2.size(); i++) { if(r2[i]!="") result.push_back(r2[i]); }
				  for(int i=0; i<r3.size(); i++) { if(r3[i]!="") result.push_back(r3[i]); }

				  // cout << result[0] << " " << result[1] << " " << result[2] << " " << result[3] << " " << result[4] << " " << result[5] << "\n";
				  Task7 task7(result[0], result[1], result[2], result[3], result[4], result[5]);
				  // std::cout << "x=" << l.solve() << std::endl;
				  solution = task7.solve();
			}else{		   
				cout<<"NOT OUR TASK!\n";
				break;
			}
			cout<<solution<<"\n";
		}
	}
	return 0;
}
