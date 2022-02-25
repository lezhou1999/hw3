#include <iostream>
#include <climits>
#include <assert.h>
#include <fstream>
#include <cstring>
#include<vector>
using namespace std;
#include "TimeCode.h"

TimeCode parse_line(vector<string> v){
    std::string str1 = v.at(0);
    int n1 = atoi(str1.c_str());
    std::string str2 = v.at(1);
    int n2 = atoi(str2.c_str());
    std::string str3 = v.at(3);
    int n3 = atoi(str3.c_str());
    std::string str4 = v.at(4);
    int n4 = atoi(str4.c_str());
    TimeCode result = TimeCode(n1*10+n2,n3*10+n4,0);
    //cout << result.ToString() <<endl;
    return result;  
}

int getSize(vector<TimeCode> input){
    int count;
    count = input.size();
    return count;
}

TimeCode getSum(vector<TimeCode> input){
    TimeCode res = TimeCode(0,0,0);
    for (size_t i=0;i<input.size();i++){

        res = input[i]+res;
    }
    return res;
}



vector<string> split(string eachLine,string delim){ 
    vector<string> result;
    //vector<string> finalResult;
    std::string::size_type i = 0;
    string determine = ":";
    std::string::size_type positionFirst = eachLine.find_first_of(delim);
    std::string::size_type found = eachLine.find_first_of(determine);
    //int positionLast = eachLine.find_last_of(delim);
    if (found!= std::string::npos){
    for(i =positionFirst+18; i< positionFirst+23;i++){
            string toStore;
            toStore=eachLine.at(i);
            result.push_back(toStore);
        }   
    }
    return result;
}

/*
vector<string> split(string eachLine,string delim){ 
    vector<string> result;
    //vector<string> finalResult;
    std::string::size_type i = 0;
    std::string::size_type positionFirst = eachLine.find_first_of(delim);
    while(positionFirst!=std::string::npos){
    for(i =positionFirst-2; i< positionFirst+3;i++){  
            string toStore;
            toStore=eachLine.at(i);
            result.push_back(toStore);
        }
    }
    return result;
}
*/

int main(){
    ifstream inFS; 
    string eachLine; 
    vector<TimeCode> toStore;   
    inFS.open("Space_Corrected.csv");
    if (!inFS.is_open()) {
      cout << "Could not open file numFile.txt." << endl;
      return -1; 
    }
    while(!inFS.fail()){
        getline(inFS, eachLine);
        string determine = ":";
        std::string::size_type found = eachLine.find_first_of(determine);
        //int positionLast = eachLine.find_last_of(delim);
        if (found!= std::string::npos){
            vector<string> v = split(eachLine, "\"");
            TimeCode tc = parse_line(v);
            toStore.push_back(tc);
            //cout <<tc.ToString() <<endl;        
            /*
            for(vector<string>::size_type i = 0; i != v.size(); ++i){
                cout << v[i] << " ";
            }
                cout<<endl;
            */
        }   
    }
    int count = getSize(toStore);
    TimeCode sum = getSum(toStore);
    TimeCode ave = sum/(count-1);
    cout<< count-1<< " data points."<< endl;
    cout<<"AVERAGE:" << ave.ToString()<<endl;
    return 0;
}

