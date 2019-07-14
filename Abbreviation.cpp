#include <bits/stdc++.h>

using namespace std;

// Complete the abbreviation function below.
string abbreviation(string a, string b) {
    int c=0,n=b.length();
    while(b.length()>0&&a.length()>0)
    {
        if(a.front()==b.front()||(a.front()-32)==b.front())
        {
            if((a.front()-32)==b.front())
            {
                a.erase(a.begin());
                if(a.front()==b.front())
                    {
                        c++;
                        a.erase(a.begin());
                        b.erase(b.begin());
                    }
                else
                {
                    c++;
                    b.erase(b.begin());
                }
            }
            else
            {
                c++;
                a.erase(a.begin());
                b.erase(b.begin());
            }
            
        }
        else if(isupper(a.front()))
            break;
        else
            a.erase(a.begin());
    }
    if(c==n)
        return "YES";
    else
        return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
