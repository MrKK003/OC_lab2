//
//  lab2_processes.cpp
//  OC_lab2
//
//  Created by Kirill Kiptyk on 10.11.2020.
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
//ofstream output_file("/Applications/OC_lab2/OC_lab2/output_processes.txt");

void print(vector <int> const &a,ofstream& output_file) {
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

void spawn(int n)
{
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    if(n)
    {
        if(fork()==0)
        {
            ofstream output_file;
            output_file.open("/Applications/OC_lab2/OC_lab2/"+to_string(n)+"_process_file.txt");
            output_file<<"Process "<<n<<endl;
            string path="/Applications/OC_lab2/OC_lab2/Sample_files/Sample_file_";
            path += to_string(n);
            path += ".txt";
            checking_for_difference(path, ultimatevector[n-1]);
            chrono::steady_clock::time_point end = chrono::steady_clock::now();
            print(ultimatevector[n-1],output_file);
            output_file <<"\n"<< "Time elapsed for process " << n << " :" << chrono::duration_cast<chrono::microseconds>(end-begin).count() << " microseconds" << endl;
            output_file.close();
            spawn(n-1);
        }
        else
            return;
    }
}


int main(int argc, char * argv[]){
    char * ch=argv[1];
    int N=atoi(ch);
//    int N;
//    cout << "Input the number of splits: ";
//    cin >> N;
    spawn(N);
    
//    output_file.close();

    return 0;
}
