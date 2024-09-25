---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Graph/kruskal.hpp
    title: Graph/kruskal.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/data-structure/Unionfind.test.cpp
    title: test/yosupo/data-structure/Unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/DSU.hpp\"\n\n//DSU\nstruct DSU{\n    vector<long long>\
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
  code: "#pragma once\n\n//DSU\nstruct DSU{\n    vector<long long> par, rank, siz;\n\
    \    DSU(long long n):par(n, -1), rank(n, 0), siz(n, 1){}\n\n    //\u6839\u3092\
    \u6C42\u3081\u308B\n    long long leader(long long x){\n        if(par[x] == -1){\n\
    \            return x;\n        }else{\n            return par[x] = leader(par[x]);\n\
    \        }\n    }\n\n    //\u9023\u7D50\u5224\u5B9A\n    bool same(long long x,\
    \ long long y){\n        return leader(x) == leader(y);\n    }\n\n    //\u9023\
    \u7D50\n    bool merge(long long x, long long y){\n        long long rx = leader(x),\
    \ ry = leader(y);\n        if(rx == ry){\n            return false;\n        }\n\
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
  timestamp: '2024-09-25 22:12:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/data-structure/Unionfind.test.cpp
documentation_of: Graph/DSU.hpp
layout: document
title: DSU
---
ノードの連結を管理する

計算量:

* 全て`O(1)`（連結は厳密には異なる）

## 概要

* `DSU dsu(n)`で頂点数`n`のDSUを初期化する

* `dsu.merge(long long from, long long to)`で`from`と`to`を連結します。また、既に連結していれば`false`、初めて連結すれば`true`を返す

* `dsu.same(long long from, long long to)`で`from`と`to`が同一集合にいるかを返す

* `dsu.leader(long long u)`で`u`が属している集合の親（`u`∈`s`かつ`v`∈`s`ならば`leader(u)`=`leader(v)`）を返す

* `dsu.size(long long u)`で`u`が属している集合の要素数を返す