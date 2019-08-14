/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int ana(string s1,string s2)
{
    if(s1.length()!=s2.length())
        return -1;
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    int i=0;
    while(i<s1.length())
    {
        if(s1[i]!=s2[i])
            return -1;
            
    }
    return 0;
}
int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    
    int a= ana (s1,s2);
    if(a==0)
        cout<<"\nanagram";
    else
        cout<<"\nnot an anagram";
    return 0;
}
