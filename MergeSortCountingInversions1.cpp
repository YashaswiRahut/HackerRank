#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long n=0;

vector<int> merg(vector<int>a,vector<int>b)
{
    vector <int> v;
    int k=0,i=0,j=0;
    while(k<(a.size()+b.size()))
        {
            if(i<a.size()&&j<b.size())
            {
                if(a[i]<b[j])
                {
                    v.push_back(a[i]);
                    i++;
                    k++;
                }   
                else if(a[i]>b[j])
                {
                    v.push_back(b[j]);
                    j++;
                    k++;
                    n++;
                }
                else
                {
                    v.push_back(a[i]);
                    i++;
                    k+=2;
                    v.push_back(b[j]);
                    j++;
                }
            }
            else if(i<a.size())
                {
                    v.push_back(a[i]);
                    i++;
                    k++;
                }
            else if(j<b.size())
                {
                    v.push_back(b[j]);
                    j++;
                    k++;
                }
        }
    return v;
}
vector<int> divid(vector<int>arr,int l,int r)
{
    vector<int> v;
    vector<int> a;
    vector<int> b;
    if(r-l>0)
    {
        a=divid(arr,l,(r-l)/2);
        b=divid(arr,((r-l)/2)+1,r);
        v=merg(a,b);
    }
    else
        v.push_back(arr[l]); 
    return v;
}
// Complete the countInversions function below.
long countInversions(vector<int> arr) {

vector<int> f;
f=divid(arr,0,arr.size()-1);
return n;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        fout << result << "\n";
    }

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
