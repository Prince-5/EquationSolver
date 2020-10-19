#include<sstream>
#include<iomanip>
#include "Task6.hpp"

using namespace std;

        Task6 :: Task6(string inp):    Eqn(inp.substr(1,inp.size()-1)){
            Tangenteqn = inp.substr(1,inp.size()-1);
        }

        string Task6 :: solve(){
            int Findex, Sindex;
            float Numerator, denominator;
            char first;
            for(int i=0; i<Tangenteqn.size(); i++){
                if(Tangenteqn.at(i) == 's'){
                    Findex = i;
                    first= 's';
                    break;
                }
                else if(Tangenteqn.at(i) == 'c'){
                    Findex = i;
                    first = 'c';
                    break;
                }
            }

            if(first == 's'){
                if(Findex == 0)     denominator = 1;
                else        denominator = stoi(Tangenteqn.substr(0,Findex));
                for(int j=Findex+7; j<Tangenteqn.size(); j++){
                    if(Tangenteqn.at(j) == 'c'){
                        Sindex = j;
                        break;
                    }
                }
                if(Sindex == Findex+7)   
                   Numerator = 1;
                else       
                 Numerator = stoi(Tangenteqn.substr(Findex+7, Sindex-Findex-7));                
            }

            else if(first == 'c'){
                if(Findex == 0)   
                  Numerator = 1;
                else       
                 Numerator = stoi(Tangenteqn.substr(0,Findex));
                for(int j=Findex+7; j<Tangenteqn.size(); j++){
                    if(Tangenteqn.at(j) == 's'){
                        Sindex = j;
                        break;
                    }
                }
                if(Sindex == Findex+7)     
                 denominator = 1;
                else       
                 denominator = stoi(Tangenteqn.substr(Findex+7, Sindex-Findex-7));           
            }
            gradient = atan(Numerator/denominator);
            if(Tangenteqn.at(Findex+6) == '+')
            {   
                  gradient = gradient*(-1);
            }
	    stringstream stream;
	    stream<<fixed<<setprecision(4)<<gradient;
	    std::string s = stream.str();
	    return "x="+s;
            //printf("x=%0.4f \n",gradient);
        }

        /*float Task6 :: getgradient(){
            return gradient;
        }*/
