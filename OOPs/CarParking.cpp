#include<iostream>
#include <bits/stdc++.h>

using namespace std;
#include<memory>
class CarParking{
    private:
    map<string, int> totalHours;
    map<string, int> carCount;
    int toMinutes(){}
    int calcHours(){}
    int calculatehours(){}
    int calculateCharges(){}
    public:
    void addRecord(string org, string start, string end){
        int hours=calculatehours(start, end);
        totalHours[org]+=hours;
        carCount[org]+=1;
    }
    void printCharges(){
        for(auto &it: totalHours){
            string org=it.first;
            int hours=it.second;
            int cars=carCount[org];
            int rate=calculateRate(org);
            int charges=hours*rate;
            cout<<"Organization: "<<org<<", Total Hours: "<<hours<<", Cars: "<<cars<<", Charges: $"<<charges<<endl;
        }
    }

};
int main(){
    CarParking cp;
    string line;
    while(getline(cin, line)){
        if(line.empty())continue;
        string org, start, end;
        stringstream ss(line);
        getline(ss, org, ',');
        getline(ss, start, ',');
        getline(ss, end, ',');
        cout << "Organization: " << org << ", Start Time: " << start << ", End Time: " << end << endl;
        cp.addRecord(org, start, end);
    }
    calculator.printCharges();

    return 0;
}