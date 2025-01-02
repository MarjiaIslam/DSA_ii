#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    string old = "Thank you very very much";
    cout << old << endl;

    int found = old.find("very");
    string neww = old.substr(0,found);
    cout << neww << endl;

    neww += old.substr(found+5);
    cout << neww << endl;

    return 0;
}
