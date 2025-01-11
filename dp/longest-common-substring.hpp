#pragma once

#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> longest_common_substring(string s, string t){
    int m = s.size(), n = t.size();
    vector dp(m + 1,vector<int>(n + 1));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(s[i] == t[j]){
                dp[i + 1][j + 1] = max({dp[i][j + 1], dp[i + 1][j], dp[i][j] + 1});
            }else{
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    int length = dp[m][n];

    vector<int> lcs_restore(length);
    int i = m, j = n;
    int idx = length - 1;

    while(i > 0 && j > 0){
        if(s[i - 1] == t[j - 1]){
            lcs_restore[idx] = i - 1;
            i--, j--, idx--;
        }else if(dp[i - 1][j] >= dp[i][j - 1]){
            i--;
        }else{
            j--;
        }
    }

    return lcs_restore;
}
