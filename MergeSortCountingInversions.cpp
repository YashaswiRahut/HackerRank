#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long merge (vector<int> a,int left,int right)
    {
        int x=0,y=0,t;
        vector<int>b;
        if(a[right]-a[left]>1)
        {
            
            x=merge(a,left,(right - left)/2);
            y=merge(a,(right - left)/2+1,right);  
        }
        else
        {
            for(int i=left,j=(right - left)/2+1;i<=(right - left)/2;i++,j++)
            {
                if(j<=right)
                {
                    if(a[i]>a[j])
                    {
                        x++;
                        b.push_back(a[j]);
                        b.push_back(a[i]);
                    }
                    else
                    {
                        b.push_back(a[i]);
                        b.push_back(a[j]);
                    }
                }
                else
                    break;
            }
        }
       return x;
    }

// Complete the countInversions function below.
long countInversions(vector<int> arr) {

    int z=merge(arr,0,arr.size()-1);
    return z;

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
