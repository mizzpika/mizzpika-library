---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/dsu.cpp\"\n//dsu\nstruct dsu{\n    vector<ll>par,\
    \ rank, siz;\n    UnionFind(ll n):par(n, -1), rank(n, 0), siz(n, 1){}\n\n    //\u6839\
    \u3092\u6C42\u3081\u308B\n    ll leader(ll x){\n        if(par[x] == -1){\n  \
    \          return x;\n        }else{\n            return par[x] = leader(par[x]);\n\
    \        }\n    }\n\n    //\u9023\u7D50\u5224\u5B9A\n    bool same(ll x, ll y){\n\
    \        return leader(x) == leader(y);\n    }\n\n    //\u9023\u7D50\n    bool\
    \ merge(ll x, ll y){\n        ll rx = leader(x), ry = leader(y);\n        if(rx\
    \ == ry){\n            return false;\n        }\n        if(rank[rx] < rank[ry]){\n\
    \            swap(rx, ry);\n        }\n        par[ry] = rx;\n        if(rank[rx]\
    \ == rank[ry]){\n            rank[rx]++;\n        }\n        siz[rx] += siz[ry];\n\
    \        return true;\n    }\n\n    //\u96C6\u5408\u306E\u5927\u304D\u3055\u3092\
    \u6C42\u3081\u308B\n    ll size(ll x){\n        return siz[leader(x)];\n    }\n\
    };\n"
  code: "//dsu\nstruct dsu{\n    vector<ll>par, rank, siz;\n    UnionFind(ll n):par(n,\
    \ -1), rank(n, 0), siz(n, 1){}\n\n    //\u6839\u3092\u6C42\u3081\u308B\n    ll\
    \ leader(ll x){\n        if(par[x] == -1){\n            return x;\n        }else{\n\
    \            return par[x] = leader(par[x]);\n        }\n    }\n\n    //\u9023\
    \u7D50\u5224\u5B9A\n    bool same(ll x, ll y){\n        return leader(x) == leader(y);\n\
    \    }\n\n    //\u9023\u7D50\n    bool merge(ll x, ll y){\n        ll rx = leader(x),\
    \ ry = leader(y);\n        if(rx == ry){\n            return false;\n        }\n\
    \        if(rank[rx] < rank[ry]){\n            swap(rx, ry);\n        }\n    \
    \    par[ry] = rx;\n        if(rank[rx] == rank[ry]){\n            rank[rx]++;\n\
    \        }\n        siz[rx] += siz[ry];\n        return true;\n    }\n\n    //\u96C6\
    \u5408\u306E\u5927\u304D\u3055\u3092\u6C42\u3081\u308B\n    ll size(ll x){\n \
    \       return siz[leader(x)];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/dsu.cpp
  requiredBy: []
  timestamp: '2024-09-23 13:31:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/dsu.cpp
layout: document
title: dsu
---
ノードの連結を管理します
