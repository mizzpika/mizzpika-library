---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/DSU.hpp
    title: DSU
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/yosupo/data-structure/Unionfind.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#line 2 \"Template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n#pragma GCC optimize(\"Ofast,unroll-loops\")\n#pragma\
    \ GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native\"\
    )\nusing namespace std;\nusing ll = long long;\n#define rep(i,n) for(ll i = 0LL;\
    \ i < (ll)n; ++i)\n#define rep1(i,n) for(ll i = 1LL; i <= (ll)n; ++i)\n#define\
    \ rep2(i,m,n) for(ll i = (ll)m; i < (ll)n; ++i)\n#define rrep(i,n) for(ll i =\
    \ (ll)n - 1; i >= 0LL; --i)\n#define rrep1(i,n) for(ll i = (ll)n; i > 0LL; --i)\n\
    #define rrep2(i,m,n) for(ll i = (ll)m; i > (ll)n; --i)\n#define _GLIBCXX_DEBUG\n\
    #define _CRT_SECURE_NO_WARNINGS\n#line 2 \"Graph/DSU.hpp\"\n\n//DSU\nstruct DSU{\n\
    \    vector<long long> par, rank, siz;\n    DSU(long long n):par(n, -1), rank(n,\
    \ 0), siz(n, 1){}\n\n    //\u6839\u3092\u6C42\u3081\u308B\n    long long leader(long\
    \ long x){\n        if(par[x] == -1){\n            return x;\n        }else{\n\
    \            return par[x] = leader(par[x]);\n        }\n    }\n\n    //\u9023\
    \u7D50\u5224\u5B9A\n    bool same(long long x, long long y){\n        return leader(x)\
    \ == leader(y);\n    }\n\n    //\u9023\u7D50\n    bool merge(long long x, long\
    \ long y){\n        long long rx = leader(x), ry = leader(y);\n        if(rx ==\
    \ ry){\n            return false;\n        }\n        if(rank[rx] < rank[ry]){\n\
    \            swap(rx, ry);\n        }\n        par[ry] = rx;\n        if(rank[rx]\
    \ == rank[ry]){\n            rank[rx]++;\n        }\n        siz[rx] += siz[ry];\n\
    \        return true;\n    }\n\n    //\u96C6\u5408\u306E\u5927\u304D\u3055\u3092\
    \u6C42\u3081\u308B\n    long long size(long long x){\n        return siz[leader(x)];\n\
    \    }\n};\n#line 4 \"test/yosupo/data-structure/Unionfind.test.cpp\"\n\nint main(){\n\
    \    ll n, q; cin >> n >> q;\n    DSU dsu(n);\n    while(q--){\n        ll t,\
    \ u, v; cin >> t >> u >> v;\n        if(t == 0){\n            dsu.merge(u, v);\n\
    \        }else{\n            cout << (dsu.same(u, v) ? 1 : 0) << endl;\n     \
    \   }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include \"\
    Template/template.hpp\"\n#include \"Graph/DSU.hpp\"\n\nint main(){\n    ll n,\
    \ q; cin >> n >> q;\n    DSU dsu(n);\n    while(q--){\n        ll t, u, v; cin\
    \ >> t >> u >> v;\n        if(t == 0){\n            dsu.merge(u, v);\n       \
    \ }else{\n            cout << (dsu.same(u, v) ? 1 : 0) << endl;\n        }\n \
    \   }\n}\n"
  dependsOn:
  - Template/template.hpp
  - Graph/DSU.hpp
  isVerificationFile: true
  path: test/yosupo/data-structure/Unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-09-25 08:18:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/data-structure/Unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/data-structure/Unionfind.test.cpp
- /verify/test/yosupo/data-structure/Unionfind.test.cpp.html
title: test/yosupo/data-structure/Unionfind.test.cpp
---
