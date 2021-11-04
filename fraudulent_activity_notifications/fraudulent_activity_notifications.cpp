#include <bits/stdc++.h>
#define ll long long int
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */

int activityNotifications(vector<int> expenditure, int d) {
    ll res = 0, low_median, high_median, 
        accB; //acc balance
    vector<int> countArr(200);
    
    for(ll i = 0; i < d; i++)
        countArr[expenditure[i]]++;
    
    for(ll i = d; i <= expenditure.size() - 1; i++)
    {
        accB = 0; low_median = -1; high_median = -1;
        for(ll j = 0; j < countArr.size(); j++)
        {
            accB += countArr[j];
            
            if(low_median == -1 && accB >= int(floor((d+1)/2.0)))
                low_median = j;
                
            if(high_median == -1 && accB >= int(ceil((d+1)/2.0)))
                high_median = j;
        }
        
        ll double_median = low_median + high_median;
        if(expenditure[i] >= double_median)
            res++;
        
        countArr[expenditure[i - d]]--;
        countArr[expenditure[i]]++;
    }

    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

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

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
