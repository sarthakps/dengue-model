using namespace std;

//to store number of infections of each day
vector<int> infected;

//total number of hosts on campus at start of season
int totalHosts = 1600;

//average infection rate
float infectionRate = 0.0028125;

//time step for differential simulation (taken as 1 day here)
double dt;

//length of dengue season
double lengthOfSeason;