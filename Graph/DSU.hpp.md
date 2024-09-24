---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Graph/kruskal.hpp
    title: Graph/kruskal.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/DSU.hpp\"\n//DSU\nstruct DSU{\n    vector<long long>\
    \ par, rank, siz;\n    DSU(long long n):par(n, -1), rank(n, 0), siz(n, 1){}\n\n\
    \    //\u6839\u3092\u6C42\u3081\u308B\n    long long leader(long long x){\n  \
    \      if(par[x] == -1){\n            return x;\n        }else{\n            return\
    \ par[x] = leader(par[x]);\n        }\n    }\n\n    //\u9023\u7D50\u5224\u5B9A\
    \n    bool same(long long x, long long y){\n        return leader(x) == leader(y);\n\
    \    }\n\n    //\u9023\u7D50\n    bool merge(long long x, long long y){\n    \
    \    long long rx = leader(x), ry = leader(y);\n        if(rx == ry){\n      \
    \      return false;\n        }\n        if(rank[rx] < rank[ry]){\n          \
    \  swap(rx, ry);\n        }\n        par[ry] = rx;\n        if(rank[rx] == rank[ry]){\n\
    \            rank[rx]++;\n        }\n        siz[rx] += siz[ry];\n        return\
    \ true;\n    }\n\n    //\u96C6\u5408\u306E\u5927\u304D\u3055\u3092\u6C42\u3081\
    \u308B\n    long long size(long long x){\n        return siz[leader(x)];\n   \
    \ }\n};\n"
  code: "//DSU\nstruct DSU{\n    vector<long long> par, rank, siz;\n    DSU(long long\
    \ n):par(n, -1), rank(n, 0), siz(n, 1){}\n\n    //\u6839\u3092\u6C42\u3081\u308B\
    \n    long long leader(long long x){\n        if(par[x] == -1){\n            return\
    \ x;\n        }else{\n            return par[x] = leader(par[x]);\n        }\n\
    \    }\n\n    //\u9023\u7D50\u5224\u5B9A\n    bool same(long long x, long long\
    \ y){\n        return leader(x) == leader(y);\n    }\n\n    //\u9023\u7D50\n \
    \   bool merge(long long x, long long y){\n        long long rx = leader(x), ry\
    \ = leader(y);\n        if(rx == ry){\n            return false;\n        }\n\
    \        if(rank[rx] < rank[ry]){\n            swap(rx, ry);\n        }\n    \
    \    par[ry] = rx;\n        if(rank[rx] == rank[ry]){\n            rank[rx]++;\n\
    \        }\n        siz[rx] += siz[ry];\n        return true;\n    }\n\n    //\u96C6\
    \u5408\u306E\u5927\u304D\u3055\u3092\u6C42\u3081\u308B\n    long long size(long\
    \ long x){\n        return siz[leader(x)];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/DSU.hpp
  requiredBy:
  - Graph/kruskal.hpp
  timestamp: '2024-09-24 18:26:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/DSU.hpp
layout: document
redirect_from:
- /library/Graph/DSU.hpp
- /library/Graph/DSU.hpp.html
title: Graph/DSU.hpp
---
