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

void generateMatlabPlotFile(vector<int> prediction){
    
    ofstream outputFile;
    outputFile.open("output.m");

    //writing the actual data's array
    for(int i = 0; i < differential.size(); i++){
        outputFile << "actual_data = ["
        outputFile << "5,4,0,1,1,3,6,2,0,0,2,4,2,4,1,2,6,1,6,4,5,2,0,6,3,3,3,3,2,
                        2,6,2,2,0,0,5,1,0,2,1,1,3,1,2,0,5,1,3,0,2,2,0,1,0,0,0,0,0,
                        0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1";
    }
    outputFile << "];" << endl << endl;

    //writing our predicted data's array
    outputFile << "predicted_data = ["
    for(int i = 0; i < differential.size(); i++){
        outputFile << prediction[i] << " ";
    }
    outputFile << "];" << endl << endl;

    //writing the plot functions
    outputFile << "plot(actual_data);\n
                    hold on;\n
                    plot(predicted_data);\n
                    legend("Actual Data","Prediction");\n
                    xlabel("Day");\n
                    ylabel("Number of Cases");\n";

    outputFile.close();
    
}