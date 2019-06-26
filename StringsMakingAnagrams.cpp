#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    map<char,int> a1;
    map<char,int> b1;
    int i,n=0;
    for(i=0;i<a.size();i++)
    {
        a1.insert(pair<char, int>(a[i],));
        a1[i].second++;
    }
    for(i=0;i<b.size();i++)
    {
        b1[i].first= a[i];
        b1[i].second++;
    }
    if(a1.size()>b1.size())
    {
        n=a1.size()-b1.size();
        for(i=0;i<b1.size();i++)
        {
            if(a[i].second-b[a[i].first]>0)
                n+=a[i].second-b[a[i].first];
            else
                n+=b[a[i].first]-a[i].second;
        }
    }

    return n;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
