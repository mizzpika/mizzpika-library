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
  bundledCode: "#line 2 \"Graph/bellman-ford.hpp\"\n\n#line 2 \"Graph/graph-template.hpp\"\
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
    \ &operator[](long long v){\n        return G[v];\n    }\n};\n#line 4 \"Graph/bellman-ford.hpp\"\
    \n\n//bellman_ford\nstruct bellman_ford{\n    vector<long long> dist;\n    vector<long\
    \ long> prev;\n    long long start;\n    long long n;\n    bool cl = false;\n\n\
    \    //bellman_ford\u3092\u69CB\u7BC9\n    bellman_ford(Graph &g, long long s){\n\
    \        start = s;\n        n = g.size();\n        dist.assign(n, 1LL << 60);\n\
    \        prev.assign(n, -1);\n        vector<long long> counts(n);\n        vector<bool>\
    \ inqueue(n);\n\n        queue<long long> q;\n        dist[s] = 0;\n        q.push(s);\n\
    \        inqueue[s] = true;\n\n        while(!q.empty()){\n            long long\
    \ from = q.front();\n            q.pop();\n            inqueue[from] = false;\n\
    \n            for(auto &e : g[from]){\n                long long d = dist[from]\
    \ + e.cost;\n                if(d < dist[e.to]){\n                    dist[e.to]\
    \ = d;\n                    prev[e.to] = from;\n                    if(!inqueue[e.to]){\n\
    \                        q.push(e.to);\n                        inqueue[e.to]\
    \ = true;\n                        ++counts[e.to];\n\n                       \
    \ if(n < counts[e.to])cl = true;\n                    }\n                }\n \
    \           }\n        }\n    }\n\n    //\u6700\u5C0F\u30B3\u30B9\u30C8\u3092\u6C42\
    \u3081\u308B\n    long long get_cost(long long to){\n        return dist[to];\n\
    \    }\n\n    //\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\u308B\n    vector<long\
    \ long> get_path(long long to){\n        vector<long long> path;\n        if(dist[to]\
    \ != 1LL << 60){\n            for(long long i = to; i != -1; i = prev[i]){\n \
    \               path.push_back(i);\n            }\n            reverse(path.begin(),\
    \ path.end());\n        }\n        return path;\n    }\n\n    //\u5230\u9054\u53EF\
    \u80FD\u304B\u8ABF\u3079\u308B\n    bool cango(long long to){\n        return\
    \ (dist[to] != 1LL << 60);\n    }\n\n    //\u8CA0\u306E\u9589\u8DEF\u306E\u6709\
    \u7121\u3092\u8ABF\u3079\u308B\n    bool closed(){\n        return cl;\n    }\n\
    };\n"
  code: "#pragma once\n\n#include \"Graph/graph-template.hpp\"\n\n//bellman_ford\n\
    struct bellman_ford{\n    vector<long long> dist;\n    vector<long long> prev;\n\
    \    long long start;\n    long long n;\n    bool cl = false;\n\n    //bellman_ford\u3092\
    \u69CB\u7BC9\n    bellman_ford(Graph &g, long long s){\n        start = s;\n \
    \       n = g.size();\n        dist.assign(n, 1LL << 60);\n        prev.assign(n,\
    \ -1);\n        vector<long long> counts(n);\n        vector<bool> inqueue(n);\n\
    \n        queue<long long> q;\n        dist[s] = 0;\n        q.push(s);\n    \
    \    inqueue[s] = true;\n\n        while(!q.empty()){\n            long long from\
    \ = q.front();\n            q.pop();\n            inqueue[from] = false;\n\n \
    \           for(auto &e : g[from]){\n                long long d = dist[from]\
    \ + e.cost;\n                if(d < dist[e.to]){\n                    dist[e.to]\
    \ = d;\n                    prev[e.to] = from;\n                    if(!inqueue[e.to]){\n\
    \                        q.push(e.to);\n                        inqueue[e.to]\
    \ = true;\n                        ++counts[e.to];\n\n                       \
    \ if(n < counts[e.to])cl = true;\n                    }\n                }\n \
    \           }\n        }\n    }\n\n    //\u6700\u5C0F\u30B3\u30B9\u30C8\u3092\u6C42\
    \u3081\u308B\n    long long get_cost(long long to){\n        return dist[to];\n\
    \    }\n\n    //\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\u308B\n    vector<long\
    \ long> get_path(long long to){\n        vector<long long> path;\n        if(dist[to]\
    \ != 1LL << 60){\n            for(long long i = to; i != -1; i = prev[i]){\n \
    \               path.push_back(i);\n            }\n            reverse(path.begin(),\
    \ path.end());\n        }\n        return path;\n    }\n\n    //\u5230\u9054\u53EF\
    \u80FD\u304B\u8ABF\u3079\u308B\n    bool cango(long long to){\n        return\
    \ (dist[to] != 1LL << 60);\n    }\n\n    //\u8CA0\u306E\u9589\u8DEF\u306E\u6709\
    \u7121\u3092\u8ABF\u3079\u308B\n    bool closed(){\n        return cl;\n    }\n\
    };\n"
  dependsOn:
  - Graph/graph-template.hpp
  - Template/template.hpp
  isVerificationFile: false
  path: Graph/bellman-ford.hpp
  requiredBy: []
  timestamp: '2024-09-24 23:25:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/bellman-ford.hpp
layout: document
redirect_from:
- /library/Graph/bellman-ford.hpp
- /library/Graph/bellman-ford.hpp.html
title: Graph/bellman-ford.hpp
---
