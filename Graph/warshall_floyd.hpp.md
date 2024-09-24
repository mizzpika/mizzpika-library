---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/graph-template.hpp
    title: graph-template
  - icon: ':heavy_check_mark:'
    path: Template/template.hpp
    title: Template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/warshall_floyd.hpp\"\n\n#line 2 \"Graph/graph-template.hpp\"\
    \n\n#line 2 \"Template/template.hpp\"\n\n#include <bits/stdc++.h>\n#pragma GCC\
    \ optimize(\"Ofast,unroll-loops\")\n#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native\"\
    )\nusing namespace std;\nusing ll = long long;\n#define rep(i,n) for(ll i = 0LL;\
    \ i < (ll)n; ++i)\n#define rep1(i,n) for(ll i = 1LL; i <= (ll)n; ++i)\n#define\
    \ rep2(i,m,n) for(ll i = (ll)m; i < (ll)n; ++i)\n#define rrep(i,n) for(ll i =\
    \ (ll)n - 1; i >= 0LL; --i)\n#define rrep1(i,n) for(ll i = (ll)n; i > 0LL; --i)\n\
    #define rrep2(i,m,n) for(ll i = (ll)m; i > (ll)n; --i)\n#define _GLIBCXX_DEBUG\n\
    #define _CRT_SECURE_NO_WARNINGS\n#line 4 \"Graph/graph-template.hpp\"\n\n//graph_template\n\
    struct Edge{\n    long long to;\n    long long cost;\n    Edge(long long to, long\
    \ long cost) : to(to), cost(cost) {}\n    bool operator>(const Edge &e) const{\n\
    \        return cost > e.cost;\n    }\n    bool operator<(const Edge &e) const{\n\
    \        return cost < e.cost;\n    }\n};\n\nstruct Edge2{\n    long long from;\n\
    \    long long to;\n    long long cost;\n    Edge2(long long from, long long to,\
    \ long long cost) : from(from), to(to), cost(cost) {}\n    bool operator>(const\
    \ Edge2 &e) const{\n        return cost > e.cost;\n    }\n    bool operator<(const\
    \ Edge2 &e) const{\n        return cost < e.cost;\n    }\n};\n\nstruct Edge3 {\n\
    \    long long to;\n    Edge3(long long to) : to(to) {}\n};\n\nstruct Graph{\n\
    \    Graph() = default;\n    vector<vector<Edge>> G;\n\n    Graph(long long N){\n\
    \        G.resize(N);\n    }\n\n    long long size(){\n        return G.size();\n\
    \    }\n\n    void add(long long from, long long to, long long cost = 1){\n  \
    \      G[from].push_back(Edge(to, cost));\n        G[to].push_back(Edge(from,\
    \ cost));\n    }\n\n    void add_di(long long from, long long to, long long cost\
    \ = 1){\n        G[from].push_back(Edge(to, cost));\n    }\n\n    vector<Edge>\
    \ &operator[](long long v){\n        return G[v];\n    }\n};\n#line 4 \"Graph/warshall_floyd.hpp\"\
    \n\n//warshall_floyd\nstruct warshall_floyd{\n    vector<vector<long long>> d;\n\
    \    vector<vector<long long>> next;\n    bool cl = false;\n\n    //warshall_floyd\u3092\
    \u69CB\u7BC9\n    warshall_floyd(Graph &g){\n        long long n = g.size();\n\
    \        d.resize(n, vector<long long>(n, 1long long << 60));\n        next.resize(n,\
    \ vector<long long>(n, -1));\n\n        for(long long i = 0; i < n; i++){\n  \
    \          d[i][i] = 0;\n        }\n\n        for(long long i = 0; i < n; i++){\n\
    \            for(auto e : g[i]){\n                d[i][e.to] = e.cost;\n     \
    \           next[i][e.to] = e.to;\n            }\n        }\n\n        for(long\
    \ long k = 0; k < n; ++k){\n            for(long long i = 0; i < n; ++i){\n  \
    \              for(long long j = 0; j < n; ++j){\n                    if(d[i][k]\
    \ == 1LL << 60 || d[k][j] == 1LL << 60)continue;\n                    if(d[i][j]\
    \ > d[i][k] + d[k][j]){\n                        d[i][j] = d[i][k] + d[k][j];\n\
    \                        next[i][j] = next[i][k];\n                    }\n   \
    \             }\n            }\n        }\n\n        for(long long i = 0; i <\
    \ n; i++){\n            if(d[i][i] < 0){\n                cl = true;\n       \
    \         break;\n            }\n        }\n    }\n\n    //\u6700\u5C0F\u30B3\u30B9\
    \u30C8\u3092\u6C42\u3081\u308B\n    long long cost(long long from, long long to){\n\
    \        return d[from][to];\n    }\n\n    //\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\
    \u3081\u308B\n    vector<long long> path(long long from, long long to) {\n   \
    \     if (d[from][to] == 1LL << 60) return {};\n        vector<long long> path;\n\
    \        for(long long at = from; at != to; at = next[at][to]){\n            if\
    \ (at == -1) return {};\n            path.push_back(at);\n        }\n        path.push_back(to);\n\
    \        return path;\n    }\n\n    //\u5230\u9054\u53EF\u80FD\u304B\u8ABF\u3079\
    \u308B\n    bool cango(long long from, long long to){\n        return d[from][to]\
    \ != 1LL << 60;\n    }\n\n    //\u8CA0\u306E\u9589\u8DEF\u306E\u6709\u7121\u3092\
    \u8ABF\u3079\u308B\n    bool closed(){\n        return cl;\n    }\n};\n"
  code: "#pragma once\n\n#include \"Graph/graph-template.hpp\"\n\n//warshall_floyd\n\
    struct warshall_floyd{\n    vector<vector<long long>> d;\n    vector<vector<long\
    \ long>> next;\n    bool cl = false;\n\n    //warshall_floyd\u3092\u69CB\u7BC9\
    \n    warshall_floyd(Graph &g){\n        long long n = g.size();\n        d.resize(n,\
    \ vector<long long>(n, 1long long << 60));\n        next.resize(n, vector<long\
    \ long>(n, -1));\n\n        for(long long i = 0; i < n; i++){\n            d[i][i]\
    \ = 0;\n        }\n\n        for(long long i = 0; i < n; i++){\n            for(auto\
    \ e : g[i]){\n                d[i][e.to] = e.cost;\n                next[i][e.to]\
    \ = e.to;\n            }\n        }\n\n        for(long long k = 0; k < n; ++k){\n\
    \            for(long long i = 0; i < n; ++i){\n                for(long long\
    \ j = 0; j < n; ++j){\n                    if(d[i][k] == 1LL << 60 || d[k][j]\
    \ == 1LL << 60)continue;\n                    if(d[i][j] > d[i][k] + d[k][j]){\n\
    \                        d[i][j] = d[i][k] + d[k][j];\n                      \
    \  next[i][j] = next[i][k];\n                    }\n                }\n      \
    \      }\n        }\n\n        for(long long i = 0; i < n; i++){\n           \
    \ if(d[i][i] < 0){\n                cl = true;\n                break;\n     \
    \       }\n        }\n    }\n\n    //\u6700\u5C0F\u30B3\u30B9\u30C8\u3092\u6C42\
    \u3081\u308B\n    long long cost(long long from, long long to){\n        return\
    \ d[from][to];\n    }\n\n    //\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\u308B\
    \n    vector<long long> path(long long from, long long to) {\n        if (d[from][to]\
    \ == 1LL << 60) return {};\n        vector<long long> path;\n        for(long\
    \ long at = from; at != to; at = next[at][to]){\n            if (at == -1) return\
    \ {};\n            path.push_back(at);\n        }\n        path.push_back(to);\n\
    \        return path;\n    }\n\n    //\u5230\u9054\u53EF\u80FD\u304B\u8ABF\u3079\
    \u308B\n    bool cango(long long from, long long to){\n        return d[from][to]\
    \ != 1LL << 60;\n    }\n\n    //\u8CA0\u306E\u9589\u8DEF\u306E\u6709\u7121\u3092\
    \u8ABF\u3079\u308B\n    bool closed(){\n        return cl;\n    }\n};\n"
  dependsOn:
  - Graph/graph-template.hpp
  - Template/template.hpp
  isVerificationFile: false
  path: Graph/warshall_floyd.hpp
  requiredBy: []
  timestamp: '2024-09-24 23:14:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/warshall_floyd.hpp
layout: document
redirect_from:
- /library/Graph/warshall_floyd.hpp
- /library/Graph/warshall_floyd.hpp.html
title: Graph/warshall_floyd.hpp
---
