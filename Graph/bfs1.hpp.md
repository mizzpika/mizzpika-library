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
  bundledCode: "#line 2 \"Graph/bfs1.hpp\"\n\n#line 2 \"Graph/graph-template.hpp\"\
    \n\n#line 2 \"Template/template.hpp\"\n\n#include <bits/stdc++.h>\n#pragma GCC\
    \ optimize(\"Ofast,unroll-loops\")\n#pragma GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native\"\
    )\nusing namespace std;\nusing ll = long long;\n#define rep(i,n) for(ll i = 0LL;\
    \ i < (ll)n; ++i)\n#define rep1(i,n) for(ll i = 1LL; i <= (ll)n; ++i)\n#define\
    \ rep2(i,m,n) for(ll i = (ll)m; i < (ll)n; ++i)\n#define rrep(i,n) for(ll i =\
    \ (ll)n - 1; i >= 0LL; --i)\n#define rrep1(i,n) for(ll i = (ll)n; i > 0LL; --i)\n\
    #define rrep2(i,m,n) for(ll i = (ll)m; i > (ll)n; --i)\n#define _GLIBCXX_DEBUG\n\
    #define _CRT_SECURE_NO_WARNINGS\n#line 4 \"Graph/graph-template.hpp\"\n\n//graph_template\n\
    struct Edge{\n    ll to;\n    ll cost;\n    Edge(ll to, ll cost) : to(to), cost(cost)\
    \ {}\n    bool operator>(const Edge &e) const{\n        return cost > e.cost;\n\
    \    }\n    bool operator<(const Edge &e) const{\n        return cost < e.cost;\n\
    \    }\n};\n\nstruct Edge2{\n    ll from;\n    ll to;\n    ll cost;\n    Edge2(ll\
    \ from, ll to, ll cost) : from(from), to(to), cost(cost) {}\n    bool operator>(const\
    \ Edge2 &e) const{\n        return cost > e.cost;\n    }\n    bool operator<(const\
    \ Edge2 &e) const{\n        return cost < e.cost;\n    }\n};\n\nstruct Edge3 {\n\
    \    ll to;\n    Edge3(ll to) : to(to) {}\n};\n\nstruct Graph{\n    Graph() =\
    \ default;\n    vector<vector<Edge>> G;\n\n    Graph(ll N){\n        G.resize(N);\n\
    \    }\n\n    ll size(){\n        return G.size();\n    }\n\n    void add(ll from,\
    \ ll to, ll cost = 1){\n        G[from].push_back(Edge(to, cost));\n        G[to].push_back(Edge(from,\
    \ cost));\n    }\n\n    void add_di(ll from, ll to, ll cost = 1){\n        G[from].push_back(Edge(to,\
    \ cost));\n    }\n\n    vector<Edge> &operator[](ll v){\n        return G[v];\n\
    \    }\n};\n#line 4 \"Graph/bfs1.hpp\"\n\n//bfs1(\u5358\u4E00\u59CB\u70B9\u6700\
    \u77ED\u7D4C\u8DEF)\nstruct bfs1{\n    vector<bool> visited;\n    vector<long\
    \ long> dist;\n    vector<long long> parent;\n\n    //bfs1(\u5358\u4E00\u59CB\u70B9\
    \u6700\u77ED\u7D4C\u8DEF)\u3092\u69CB\u7BC9\n    bfs1(Graph &g, long long s){\n\
    \        long long n = g.size();\n        visited.assign(n, false);\n        dist.assign(n,\
    \ -1);\n        parent.assign(n, -1);\n        visited[s] = true;\n        dist[s]\
    \ = 0;\n        parent[s] = -1;\n        queue<long long> que;\n        que.push(s);\n\
    \        while(!que.empty()){\n            long long cur = que.front();\n    \
    \        que.pop();\n            for(auto nxt : g[cur]){\n                if(!visited[nxt.to]){\n\
    \                    que.push(nxt.to);\n                    visited[nxt.to] =\
    \ true;\n                    dist[nxt.to] = dist[cur] + 1;\n                 \
    \   parent[nxt.to] = cur;\n                }\n            }\n        }\n    }\n\
    \n    //\u6700\u5C0F\u30B3\u30B9\u30C8\u3092\u6C42\u3081\u308B\n    long long\
    \ cost(long long to){\n        return dist[to];\n    }\n\n    //\u6700\u77ED\u7D4C\
    \u8DEF\u3092\u6C42\u3081\u308B\n    vector<long long> path(long long to){\n  \
    \      vector<long long> path;\n        if(!visited[to]){\n            return\
    \ path;\n        }\n        for(long long i = to; i != -1; i = parent[i]){\n \
    \           path.push_back(i);\n        }\n        reverse(path.begin(), path.end());\n\
    \        return path;\n    }\n\n    //\u5230\u9054\u53EF\u80FD\u304B\u8ABF\u3079\
    \u308B\n    bool cango(long long to){\n        return visited[to];\n    }\n};\n"
  code: "#pragma once\n\n#include \"Graph/graph-template.hpp\"\n\n//bfs1(\u5358\u4E00\
    \u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF)\nstruct bfs1{\n    vector<bool> visited;\n\
    \    vector<long long> dist;\n    vector<long long> parent;\n\n    //bfs1(\u5358\
    \u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF)\u3092\u69CB\u7BC9\n    bfs1(Graph\
    \ &g, long long s){\n        long long n = g.size();\n        visited.assign(n,\
    \ false);\n        dist.assign(n, -1);\n        parent.assign(n, -1);\n      \
    \  visited[s] = true;\n        dist[s] = 0;\n        parent[s] = -1;\n       \
    \ queue<long long> que;\n        que.push(s);\n        while(!que.empty()){\n\
    \            long long cur = que.front();\n            que.pop();\n          \
    \  for(auto nxt : g[cur]){\n                if(!visited[nxt.to]){\n          \
    \          que.push(nxt.to);\n                    visited[nxt.to] = true;\n  \
    \                  dist[nxt.to] = dist[cur] + 1;\n                    parent[nxt.to]\
    \ = cur;\n                }\n            }\n        }\n    }\n\n    //\u6700\u5C0F\
    \u30B3\u30B9\u30C8\u3092\u6C42\u3081\u308B\n    long long cost(long long to){\n\
    \        return dist[to];\n    }\n\n    //\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\
    \u3081\u308B\n    vector<long long> path(long long to){\n        vector<long long>\
    \ path;\n        if(!visited[to]){\n            return path;\n        }\n    \
    \    for(long long i = to; i != -1; i = parent[i]){\n            path.push_back(i);\n\
    \        }\n        reverse(path.begin(), path.end());\n        return path;\n\
    \    }\n\n    //\u5230\u9054\u53EF\u80FD\u304B\u8ABF\u3079\u308B\n    bool cango(long\
    \ long to){\n        return visited[to];\n    }\n};\n"
  dependsOn:
  - Graph/graph-template.hpp
  - Template/template.hpp
  isVerificationFile: false
  path: Graph/bfs1.hpp
  requiredBy: []
  timestamp: '2024-09-25 22:12:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/bfs1.hpp
layout: document
redirect_from:
- /library/Graph/bfs1.hpp
- /library/Graph/bfs1.hpp.html
title: Graph/bfs1.hpp
---
