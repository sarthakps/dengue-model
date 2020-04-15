using namespace std;

void printInfectedVector(){

    //day wise printing
    for(int i = 0; i<infected.size(); i++)
        cout<<"Day "<< i << ": " << infected[i] << endl << endl;
    
    //counting and printing total infections for the entire season
    int totalInfections = 0;
    for(auto i:infected)
        totalInfections+=i;

    cout<<endl<<endl<<"Total Infections = "<<totalInfections;

}