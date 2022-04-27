// Created by Kirill Kiptyk on 06.10.2020.
// Variant 9
//#include <iostream>
//#include <fstream>
//#include <thread>
//#include <vector>
//#include <chrono>
//#include <unistd.h>
//using namespace std;
//using namespace chrono;
//
//vector<int> differerent_lines_1;
//vector<int> differerent_lines_2;
//vector<int> differerent_lines_3;
//vector<int> differerent_lines_4;
//
//vector <vector<int>> ultimatevector(100,vector<int>(100));
//
//void print(vector <int> &a) {
//   cout << "This line(s) is(are) different from the original file: ";
//   for(int i=0; i < a.size(); i++)
//   cout << a.at(i) << ' ';
//}
//
//
//void checking_for_difference(string name,vector <int> &a){
//    int counter=1;
//    string line1;
//    string line2;
//    ifstream file1 ("/Applications/OC_lab2/OC_lab2/Original_file.txt");
//    ifstream file2 (name);
//    while (getline(file1, line1) && getline(file2, line2)){
//        if (line1==line2){
//            counter++;
//        }
//        else {
//            a.push_back(counter);
//            counter++;
//        }
//    }
//    file1.close();
//    file2.close();
//}
//
//
//int main(){
//    ultimatevector.clear();
//    auto start1 = high_resolution_clock::now();
//    thread th1(checking_for_difference,"/Applications/OC_lab2/OC_lab2/Sample_files/Sample_file_1.txt",ref(ultimatevector[1]));
//    auto start2 = high_resolution_clock::now();
//    thread th2(checking_for_difference,"/Applications/OC_lab2/OC_lab2/Sample_files/Sample_file_2.txt",ref(ultimatevector[2]));
//    auto start3 = high_resolution_clock::now();
//    thread th3(checking_for_difference,"/Applications/OC_lab2/OC_lab2/Sample_files/Sample_file_3.txt",ref(ultimatevector[3]));
//    auto start4 = high_resolution_clock::now();
//    thread th4(checking_for_difference,"/Applications/OC_lab2/OC_lab2/Sample_files/Sample_file_4.txt",ref(ultimatevector[4]));
//    th1.join();
//    auto stop1 = high_resolution_clock::now();
//    th2.join();
//    auto stop2 = high_resolution_clock::now();
//    th3.join();
//    auto stop3 = high_resolution_clock::now();
//    th4.join();
//    auto stop4 = high_resolution_clock::now();
//    
//    auto duration1 = duration_cast<microseconds>(stop1 - start1);
//    auto duration2 = duration_cast<microseconds>(stop2 - start2);
//    auto duration3 = duration_cast<microseconds>(stop3 - start3);
//    auto duration4 = duration_cast<microseconds>(stop4 - start4);
//    
//    cout<<"THREADS"<<endl;
//    print(ultimatevector[1]);
//    cout<<"\n"<<"Time taken by thread: "<<duration1.count()<<" microseconds"<<"\n";
//    print(ultimatevector[2]);
//    cout<<"\n"<<"Time taken by thread: "<<duration2.count()<<" microseconds"<<"\n";
//    print(ultimatevector[3]);
//    cout<<"\n"<<"Time taken by thread: "<<duration3.count()<<" microseconds"<<"\n";
//    print(ultimatevector[4]);
//    cout<<"\n"<<"Time taken by thread: "<<duration4.count()<<" microseconds"<<"\n";
//
//    differerent_lines_1.clear();
//    differerent_lines_2.clear();
//    differerent_lines_3.clear();
//    differerent_lines_4.clear();
//    
////    ultimatevector.clear();
//    
//    cout<<"PROCESSES"<<endl;
//
//    auto start5 = high_resolution_clock::now();
//    auto start6 = high_resolution_clock::now();
//    auto start7 = high_resolution_clock::now();
//    auto start8 = high_resolution_clock::now();
//
//    int  n1,n2;
//    n1 = fork();
//    n2 = fork();
//    if (n1 > 0 && n2 > 0) {
//
//        checking_for_difference("/Applications/OC_lab2/OC_lab2/Sample_files/Sample_file_1.txt",ref(differerent_lines_1));
//        print(differerent_lines_1);
//        auto stop5 = high_resolution_clock::now();
//        auto duration5 = duration_cast<microseconds>(stop5 - start5);
//        cout<<"\n"<<"Time taken by process: "<<duration5.count()<<" microseconds"<<"\n";
//    }
//    else if (n1 > 0 && n2 == 0) {
//
//        checking_for_difference("/Applications/OC_lab2/OC_lab2/Sample_files/Sample_file_2.txt",ref(differerent_lines_2));
//        print(differerent_lines_2);
//        auto stop6 = high_resolution_clock::now();
//        auto duration6 = duration_cast<microseconds>(stop6 - start6);
//        cout<<"\n"<<"Time taken by process: "<<duration6.count()<<" microseconds"<<"\n";
//    }
//    else if (n1 == 0 && n2 > 0) {
//
//        checking_for_difference("/Applications/OC_lab2/OC_lab2/Sample_files/Sample_file_3.txt",ref(differerent_lines_3));
//        print(differerent_lines_3);
//        auto stop7 = high_resolution_clock::now();
//        auto duration7 = duration_cast<microseconds>(stop7 - start7);
//        cout<<"\n"<<"Time taken by process: "<<duration7.count()<<" microseconds"<<"\n";
//
//    }
//    else if (n1 == 0 && n2 == 0){
//
//        checking_for_difference("/Applications/OC_lab2/OC_lab2/Sample_files/Sample_file_4.txt",ref(differerent_lines_4));
//        print(differerent_lines_4);
//        auto stop8 = high_resolution_clock::now();
//        auto duration8 = duration_cast<microseconds>(stop8 - start8);
//        cout<<"\n"<<"Time taken by process: "<<duration8.count()<<" microseconds"<<"\n";
//
//    }
//
//
//    return 0;
//}
