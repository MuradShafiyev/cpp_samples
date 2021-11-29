#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    int arr[26];
    memset(arr, 0, sizeof(arr));
    int len = s.length();
    //1
    for(int i = 0; i < len; i++)
    {
        int c = s[i] - 97;
        arr[c] += 1; 
    }
    int n_min = 0, n_max = 0, min=9999;
    
    //2
    int* max = max_element(arr, arr + 26);
    for(int i = 0; i < 26; i++)
    {
        if(arr[i] > 0 && arr[i] < min)
            min = arr[i]; 
    }
    
    //3
    for(int i = 0; i < 26; i++)
    {
        if(arr[i] == *max)
            n_max++;
        if(arr[i] == min)
            n_min++;  
    }
    
    //4
    if(((*max - min) == 1) && ((n_max == 1) || (n_min == 1)))
        return "YES";
    if((*max - min) == 0)
        return "YES";
    if(((*max-min)>1) && (n_min == 1) 
    && ((n_max * *max) + (n_min * min) == len))
        return "YES";
        
        
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
