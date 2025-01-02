#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str1 =  "Hello world";
    cout<<str1<<endl;

    char chr_str[] = "Hello Universe";
    string str2 = string(chr_str);
    cout<<str2<<endl;

    cout << str1.length() << endl;

    cout << "str1[0]: " << str1[0] << "str1[6]: " << str1[6] <<endl;

    str1 += ".";
    cout << str1 << endl;
    str2 += ".";
    str2 += str1;
    cout << str2 << endl;

    cout << "Enter the word: " << endl;
    string word, line;
    cin>> word;
    cin.sync();
    cout<< "The word: " << word << endl;

    cout << "Enter the line: " << endl;
    getline(cin, line);
    cout<< "The line: " << line << endl;

    string str3 = "Hello";
    string str4 = str3;
    str3[0] = 'y';
    cout << str3 << " " << str4 << endl;

    if(str4 == str3)
    {
        cout << "str3 and str4 both changed!!" << endl;
    }
    if(str4 != str3)
    {
        cout << "str4 did not change!!" << endl;
    }
    return 0;
}
