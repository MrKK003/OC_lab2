//
//  lab2_threads.cpp
//  OC_lab2
//
//  Created by Kirill Kiptyk.
//
//
//
#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <chrono>
#include <unistd.h>
#include <string>

using namespace std;
using namespace chrono;


vector <vector<int> > ultimatevector(100,vector<int>());
//ofstream output_file("/Applications/OC_lab2/OC_lab2/output_threads.txt");

void print(vector <int> const &a, ofstream& output_file) {
   output_file << "This line(s) is(are) different from the original file: ";
   for(int i=0; i < a.size(); i++)
    output_file << a.at(i) << ' ';
}


void checking_for_difference(string name,vector <int> &a){
    int counter=1;
    string line1;
    string line2;
    ifstream file1 ("/Applications/OC_lab2/OC_lab2/Sample_files/Original_file.txt");
    ifstream file2 (name);
    while (getline(file1, line1) && getline(file2, line2)){
        if (line1==line2){
            counter++;
        }
        else {
            a.push_back(counter);
            counter++;
        }
    }
    file1.close();
    file2.close();
}




int main(int argc, char * argv[]){
    char * ch=argv[1];
    int N=atoi(ch);

    chrono::steady_clock::time_point begin[N];
    chrono::steady_clock::time_point end[N];
    thread myThreads[N];
    for(int i = 0; i<N-1; i++){
        begin[i]=chrono::steady_clock::now();

        string path="/Applications/OC_lab2/OC_lab2/Sample_files/Sample_file_";
        path += to_string(i+1);
        path += ".txt";
        myThreads[i]= thread(checking_for_difference,path,ref(ultimatevector[i]));
    }
    
    string path1="/Applications/OC_lab2/OC_lab2/Sample_files/Sample_file_";
    path1 += to_string(N-1);
    path1 += ".txt";

    begin[N-1]=chrono::steady_clock::now();
    myThreads[N-1]=thread(checking_for_difference,path1,ref(ultimatevector[N-1]));

    for(int i = 0;i<N;i++)
    {
        myThreads[i].join();
        end[i]=chrono::steady_clock::now();
    }
    
    for (int i =0; i<N;i++){
        ofstream output_file;
        output_file.open("/Applications/OC_lab2/OC_lab2/"+to_string(i+1)+"_thread_file.txt");
        output_file<<"Thread "<<i+1<<endl;
        print(ultimatevector[i],output_file);
        output_file <<"\n"<< "Time elapsed for thread " << i+1 << " :" << chrono::duration_cast<chrono::microseconds>(end[i]-begin[i]).count() << " microseconds" << endl;
        output_file.close();
    }

//    output_file.close();
    
    return 0;
}
