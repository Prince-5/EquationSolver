#include<bits/stdc++.h>
#include"Task5.hpp"

using namespace std;

void exchange(int* a,int* b)
{
	int a0=a[0];
	int a1=a[1];
	int a2=a[2];
	a[0]=b[0];
	a[1]=b[1];
	a[2]=b[2];
	b[0]=a0;
	b[1]=a1;
	b[2]=a2;
}
Task5::Task5(){}
Task5::Task5(string S1):Eqn(S1){}
Task5::Task5(Task5 &H)
{
	s = H.s;
	M = H.M;
}
Task5::~Task5()
{
	delete []M;
}
string Task5::solve()
{
	vector<string> result;
        stringstream check1(s);
        string intermediate;
        while(getline(check1,intermediate,';'))
        {
                result.push_back(intermediate);
        }
        M = new int*[3];
        for(int i=0;i<3;i++)
        {
                M[i] = new int[4];
        }
        for(int i=0;i<3;i++)
        {
                int j=0;
                for(int k=0;k<3;k++)
                {
                        int x=1;
                        int s1=1;
                        if(result[i][j]=='-')
                        {
                                x=-1;
                                j+=1;
                        }
                        if(result[i][j]=='+')
                        {
                                x=1;
                                j+=1;
                        }
                        if(result[i][j]=='1' || result[i][j]=='2' || result[i][j]=='3' || result[i][j]=='4' || result[i][j]=='5' || result[i][j]=='6' || result[i][j]=='7' || result[i][j]=='8' || result[i][j]=='9')
                        {
                                s1=result[i][j]-48;
                                j+=1;
                        }
                        if(result[i][j]=='x')
                        {
                                M[i][0]=x*s1;
                        }
                        else if(result[i][j]=='y')
                        {
                                M[i][1]=x*s1;
                        }
                        else if(result[i][j]=='z')
                        {
                                M[i][2]=x*s1;
                        }
                        j+=1;
                }
		j+=1;
                int x=1;
                if(result[i][j]=='-')
                {
                        x=-1;
                        j+=1;
                }
                else if(result[i][j]=='+')
                {
                        x=1;
                        j+=1;
                }
                string S = "";
                while(result[i][j]!=0)
                {
                        S=S+result[i][j];
                        j+=1;
                }
                if(S!="")
                {
                        M[i][3]=x*stoi(S);
                }
        }
	for(int i=0;i<3;i++)
	{
		if(M[i][i]==0)
		{
			for(int j=i+1;j<3;j++)
			{
				if(M[j][i]!=0)
				{
					exchange(M[i],M[j]);
					break;
				}
			}
			if(i==2)
			{
				for(int j=0;j<3;j++)
				{
					if(M[j][j]==0 && M[j][3]!=0)
					{
						string s = "Non-unique solution";
						return s;
					}
				}
				for(int j=0;j<3;j++)
                                {
                                        if(M[j][j]==0 && M[j][3]==0)
                                        {
						string s = "Non-unique solution";
						return s;
                                        }
                                }
				int m = M[0][3]/M[0][0];
				int n = M[1][3]/M[1][1];
				int p = M[2][3]/M[2][2];
				// std::string s = str;
				string s = "x="+to_string(m)+";y="+to_string(n)+";z="+to_string(p);
				return s;
			}
		}
		for(int j=0;j<3;j++)
		{
			if(j!=i)
			{
				int m=M[i][i];
				int n=M[j][i];
				M[j][0] = m*M[j][0]-n*M[i][0];
				M[j][1] = m*M[j][1]-n*M[i][1];
				M[j][2] = m*M[j][2]-n*M[i][2];
				M[j][3] = m*M[j][3]-n*M[i][3];
			}
		}
	}
	for(int i=0;i<3;i++)
	{
		if(M[i][i]!=0 && M[i][3]==0)
		{
			string s = "Non-unique solution";
			return s;
		}
	}
	int m = M[0][3]/M[0][0];
        int n = M[1][3]/M[1][1];
        int p = M[2][3]/M[2][2];
        string s = "x="+to_string(m)+";y="+to_string(n)+";z="+to_string(p);
	return s;
}
