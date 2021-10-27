#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
    map<int, int> m1, m2;
    vector<int> res;
    
    for(int i = 0; i < queries.size(); i++)
    {
        // insert sorğusu
        if(queries[i][0] == 1)
        {
            int k = m1[queries[i][1]];
            
            //decrease count of present frequency
            //cari frequency sayını azaldır
            if(k > 0)
                m2[k]--;
            
            //increase occurence of a number    
            //ədədin tezliyini artırır
            m1[queries[i][1]]++;
            
            //increase count of present frequency + 1
            //hal-hazırki frequency sayını + 1 artırır
            m2[k+1]++;
        }
        
        //delete soröusu
        else if(queries[i][0] == 2)
        {
            int k = m1[queries[i][1]];
            if(k > 0)
            {
                //decrease occurence of a number
                //ədədin tezliyini(occurrence) azaldır
                m1[queries[i][1]]--;
                
                //decrease count of present frequency
                //cari frequency sayını azaldır
                m2[k]--;
                
                //increase count of present frequency - 1
                //hal-hazırki frequency sayını -1 azaldır
                if(k-1 > 0)
                    m2[k-1]++;
            }
        }
        else
        {
            //true if the count of asked frequency is non-zero
            //axtarılan frequency sayı sıfırdan fərqli olduqda true
            if(m2[queries[i][1]] > 0)
                res.push_back(1);
            else
                res.push_back(0);
        }
    }
    return res;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> ans = freqQuery(queries);

    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i];

        if (i != ans.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
