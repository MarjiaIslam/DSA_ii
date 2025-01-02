#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    string str = "yes, we went to Gates after we left the dorm.";
    int firstWe = str.find("we");
    int secWe = str.find("we", firstWe+1);
    int thirdWe = str.find("we", secWe+1);
    int gPos = str.find('G');
    int zPos = str.find('Z');

    //cout<<zPos<<endl;
    cout<<"First we: "<<firstWe<<endl;
    cout<<"Second we: "<<secWe<<endl;
    cout<<"Third we: "<<thirdWe<<endl;
    cout<<"Is G there? ";
    cout<<(gPos != string::npos ? "Yes!" : "no!")<<endl;
    cout<<"Is Z there? ";
    cout<<(zPos != string::npos ? "Yes!" : "no!")<<endl;

    return 0;
}
