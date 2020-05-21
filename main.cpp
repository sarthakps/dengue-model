#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<ctime>

#include"MACROS.h"
#include"variables.h"
#include"Host.h"
#include"helper.h"
#include"simulation.h"
#include"DifferentialModel.h"


using namespace std;


int main(){

    differentialModel();

    // //giving a seed to srand for random number generation using rand()
    // srand(time(NULL));

    // vector<Host> hosts;
    // makeHosts(hosts, 1600);

    // //to run the simulation
    // runSim2(hosts);

    // //printing the infections for the given period (day wise)
    // printInfectedVector();

    return 0;
}