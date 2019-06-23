#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

vector<string> split_string(string);

int activityNotifications(vector<int> expenditure, int d) {

int a=0,i,j,k,m,c=0;

int v[d];
for(j=d;j<expenditure.size();j++)
{
    int count[201]={0};
    for(i=j-d;i<j;i++)
    {
        count[expenditure[i]]++;
        //cout<<"\ncount[expenditure[i]]++; "<<expenditure[i]<<" "<<count[expenditure[i]];
    }
    k=0;
    for(i=0;i<=200;i++)
    {
        while(count[i]>0)
        {
        v[k++]=i;
        //cout<<"\nv[count[i]]=i; "<<v[count[i]];
        count[i]--;
        }
    }
    /*cout<<"\nsorted array : ";
    for(i=0;i<d;i++)
        cout<<" "<<v[i];*/
    k=d/2;
    if (d%2!=0)
        m=v[k];
    else
        m=(v[k]+v[k+1])/2;
    //cout<<"\n"<<m;
    if(expenditure[j]>=2*m)
        c++;
}
return c;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
