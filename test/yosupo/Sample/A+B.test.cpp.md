---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Template/short.hpp
    title: Template/short.hpp
  - icon: ':heavy_check_mark:'
    path: Template/template.hpp
    title: Template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/yosupo/Sample/A+B.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 2 \"Template/template.hpp\"\n\n#include <bits/stdc++.h>\n#pragma GCC optimize(\"\
    Ofast,unroll-loops\")\n#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native\"\
    )\nusing namespace std;\nusing ll = long long;\n#define rep(i,n) for(ll i = 0LL;\
    \ i < (ll)n; ++i)\n#define rep1(i,n) for(ll i = 1LL; i <= (ll)n; ++i)\n#define\
    \ rep2(i,m,n) for(ll i = (ll)m; i < (ll)n; ++i)\n#define rrep(i,n) for(ll i =\
    \ (ll)n - 1; i >= 0LL; --i)\n#define rrep1(i,n) for(ll i = (ll)n; i > 0LL; --i)\n\
    #define rrep2(i,m,n) for(ll i = (ll)m; i > (ll)n; --i)\n#define _GLIBCXX_DEBUG\n\
    #define _CRT_SECURE_NO_WARNINGS\n#line 2 \"Template/short.hpp\"\n\n#line 4 \"\
    Template/short.hpp\"\n\n#define lb(a,x) static_cast<ll>(lower_bound(all(a), x)\
    \ - a.begin())\n#define ub(a,x) static_cast<ll>(upper_bound(all(a), x) - a.begin())\n\
    #define all(a) a.begin(), a.end()\n#define rall(a) a.rbegin(), a.rend()\n#define\
    \ SORT(a) sort(all(a));\n#define RSORT(a) sort(rall(a));\n#define REV(a) reverse(all(a));\n\
    #define CEIL(x,y) (x + y - 1) / y\n#define pb push_back\n#define eb emplace_back\n\
    #define INT(...) int __VA_ARGS__;in(__VA_ARGS__)\n#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)\n\
    #define STR(...) string __VA_ARGS__;in(__VA_ARGS__)\n#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)\n\
    #define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)\n#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)\n\
    using ld = long double;\nusing ll = long long;\nusing ull = unsigned long long;\n\
    \nusing vi = vector<int>;\nusing vl = vector<ll>;\nusing vc = vector<char>;\n\
    using vb = vector<bool>;\nusing vs = vector<string>;\n\nusing vvi = vector<vi>;\n\
    using vvl = vector<vl>;\nusing vvc = vector<vc>;\nusing vvb = vector<vb>;\nusing\
    \ vvs = vector<vs>;\n\n\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\
    \nusing si = set<int>;\nusing sl = set<ll>;\n\nusing mii = map<int, int>;\nusing\
    \ mll = map<ll, ll>;\n\n//in\nvoid in(){}\ntemplate<class T>void in(vector<T>\
    \ &v){\n    for(T &t : v)cin >> t;\n}\ntemplate<class T>void in(vector<vector<T>>\
    \ &v){\n    for(auto &row : v)for(T&element : row)cin >> element;\n}\ntemplate<class\
    \ Head, class... Tail>void in(Head &head, Tail &...tail){\n    cin >> head; in(tail...);\n\
    }\n\n//out\nvoid out(){}\ntemplate<class T>void out(const T &t){\n    cout <<\
    \ t << endl;\n}\ntemplate<class T>void out(vector<T> &v){\n    for(T &t : v)cout\
    \ << t << ' ';\n    cout << endl;\n}\ntemplate<class T>void out(vector<vector<T>>\
    \ &v){\n    for(vector<T> &row : v){\n        for(T &element : row){\n       \
    \     cout << element << ' ';\n        }\n        cout << endl;\n    }\n}\ntemplate<class\
    \ Head, class...Tail>void out(const Head &head, const Tail &...tail){\n    cout\
    \ << head; out(tail...);\n}\n\n//chmax\ntemplate<typename T>bool chmax(T &a, T\
    \ b){\n    return((a < b)? (a = b, true) : (false));\n}\n\n//chmin\ntemplate<typename\
    \ T>bool chmin(T &a, T b){\n    return((a > b)? (a = b, true) : (false));\n}\n\
    \n//min\ntemplate<typename T>T MIN(vector<T> &v){\n    T mn = numeric_limits<T>::max();\n\
    \    for(T &e : v){\n        mn = min(mn, e);\n    }\n    return mn;\n}\n\n//max\n\
    template<typename T>T MAX(vector<T> &v){\n    T mx = numeric_limits<T>::min();\n\
    \    for(T &e : v){\n        mx = max(mx, e);\n    }\n    return mx;\n}\n\n//sum\n\
    template<typename T>T SUM(vector<T> &v){\n    T sum = 0;\n    for(T &e : v){\n\
    \        sum += e;\n    }\n    return sum;\n}\n\n//l_sort\ntemplate<typename T>void\
    \ l_sort(vector<T> &l, vector<T> &r){\n    assert(l.size() == r.size());\n   \
    \ long long n = l.size();\n    vector<pair<T, T>> p;\n    for(ll i = 0; i < n;\
    \ i++){\n        p.emplace_back(l[i], r[i]);\n    }\n    sort(p.begin(), p.end());\n\
    \    for(ll i = 0; i < n; i++){\n        l[i] = p[i].first;\n        r[i] = p[i].second;\n\
    \    }\n}\n\n//r_sort\ntemplate<typename T>void r_sort(vector<T> &l, vector<T>\
    \ &r){\n    assert(l.size() == r.size());\n    long long n = l.size();\n    vector<pair<T,\
    \ T>> p;\n    for(ll i = 0; i < n; i++){\n        p.emplace_back(r[i], l[i]);\n\
    \    }\n    sort(p.begin(), p.end());\n    for(ll i = 0; i < n; i++){\n      \
    \  l[i] = p[i].second;\n        r[i] = p[i].first;\n    }\n}\n#line 4 \"test/yosupo/Sample/A+B.test.cpp\"\
    \nint main(){\n    LL(a,b);out(a+b);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"Template/template.hpp\"\
    \n#include \"Template/short.hpp\"\nint main(){\n    LL(a,b);out(a+b);\n}\n"
  dependsOn:
  - Template/template.hpp
  - Template/short.hpp
  isVerificationFile: true
  path: test/yosupo/Sample/A+B.test.cpp
  requiredBy: []
  timestamp: '2024-09-25 22:12:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Sample/A+B.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Sample/A+B.test.cpp
- /verify/test/yosupo/Sample/A+B.test.cpp.html
title: test/yosupo/Sample/A+B.test.cpp
---
