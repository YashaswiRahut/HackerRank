#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
class t{
    public:
    int item1,item2;
};

int Maxi(int a, int b)
        {
            return a > b ? a : b;
        }

int Sum(int index, int sum,vector<int> _arr)
        {
            map<int,t> sumDict;
            if (index >= _arr.size() )
                return sum;
            /* if (sumDict.ContainsKey(index) && sumDict[index].Item1 >= sum)
            {
                sumDict[index] = new Tuple<int, int>( sum, sumDict[index].Item2);
                return sumDict[index].Item2;
            }
            if(sumDict.find(index) && sumDict[index].item1>=sum)
            {
                sumDict[index]=
            }*/
            return Maxi(Sum(index + 2, sum + _arr[index],_arr),Sum(index + 1, sum,_arr));
        }

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> _arr) {
        int sum = 0;
        return Sum(0,sum,_arr);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

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

    int res = maxSubsetSum(arr);

    fout << res << "\n";

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
