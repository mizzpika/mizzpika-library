---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"dp/longest-common-substring.hpp\"\n\n#include <vector>\n\
    #include <string>\n#include <algorithm>\nusing namespace std;\nvector<int> longest_common_substring(string\
    \ s, string t){\n    int m = s.size(), n = t.size();\n    vector dp(m + 1,vector<int>(n\
    \ + 1));\n    for(int i = 0; i < m; i++){\n        for(int j = 0; j < n; j++){\n\
    \            if(s[i] == t[j]){\n                dp[i + 1][j + 1] = max({dp[i][j\
    \ + 1], dp[i + 1][j], dp[i][j] + 1});\n            }else{\n                dp[i\
    \ + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);\n            }\n        }\n \
    \   }\n    int length = dp[m][n];\n\n    vector<int> lcs_restore(length);\n  \
    \  int i = m, j = n;\n    int idx = length - 1;\n\n    while(i > 0 && j > 0){\n\
    \        if(s[i - 1] == t[j - 1]){\n            lcs_restore[idx] = i - 1;\n  \
    \          i--, j--, idx--;\n        }else if(dp[i - 1][j] >= dp[i][j - 1]){\n\
    \            i--;\n        }else{\n            j--;\n        }\n    }\n\n    return\
    \ lcs_restore;\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <string>\n#include <algorithm>\n\
    using namespace std;\nvector<int> longest_common_substring(string s, string t){\n\
    \    int m = s.size(), n = t.size();\n    vector dp(m + 1,vector<int>(n + 1));\n\
    \    for(int i = 0; i < m; i++){\n        for(int j = 0; j < n; j++){\n      \
    \      if(s[i] == t[j]){\n                dp[i + 1][j + 1] = max({dp[i][j + 1],\
    \ dp[i + 1][j], dp[i][j] + 1});\n            }else{\n                dp[i + 1][j\
    \ + 1] = max(dp[i][j + 1], dp[i + 1][j]);\n            }\n        }\n    }\n \
    \   int length = dp[m][n];\n\n    vector<int> lcs_restore(length);\n    int i\
    \ = m, j = n;\n    int idx = length - 1;\n\n    while(i > 0 && j > 0){\n     \
    \   if(s[i - 1] == t[j - 1]){\n            lcs_restore[idx] = i - 1;\n       \
    \     i--, j--, idx--;\n        }else if(dp[i - 1][j] >= dp[i][j - 1]){\n    \
    \        i--;\n        }else{\n            j--;\n        }\n    }\n\n    return\
    \ lcs_restore;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/longest-common-substring.hpp
  requiredBy: []
  timestamp: '2025-05-14 10:04:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/longest-common-substring.hpp
layout: document
redirect_from:
- /library/dp/longest-common-substring.hpp
- /library/dp/longest-common-substring.hpp.html
title: dp/longest-common-substring.hpp
---
