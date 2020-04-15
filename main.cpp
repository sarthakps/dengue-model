#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<ctime>

#include"matplotlibcpp.h"
#include"MACROS.h"
#include"variables.h"
#include"Host.h"
#include"simulation.h"

using namespace std;
  
namespace plt = matplotlibcpp;

void printInfectedVector(vector<int> &array){

    //day wise printing
    for(int i = 0; i<array.size(); i++)
        cout<<"Day "<< i << ": " << array[i] << endl << endl;
    
    //counting and printing total infections for the entire season
    int totalInfections = 0;
    for(auto i:array)
        totalInfections+=i;

    cout<<endl<<endl<<"Total Infections = "<<totalInfections;

}

int main(){

    //giving a seed to srand for random number generation using rand()
    srand(time(NULL));

    vector<Host> hosts;
    makeHosts(hosts, 1600);

    //to run the simulation
    runSim2(hosts);

    //printing the infections for the given period (day wise)
    printInfectedVector(infected);

    plt::figure_size(1200, 780);
    plt::plot(infected);

    return 0;
}