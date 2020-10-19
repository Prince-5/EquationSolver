#ifndef TASK6
#define TASK6
#include"Eqn.hpp"
#include <bits/stdc++.h>


using namespace std;

class Task6: public Eqn{

    private:

       string Tangenteqn;

        float gradient;
         
    public:
    
        Task6( string inp);

        string solve();

        //float getgradient();
        
};

#endif
