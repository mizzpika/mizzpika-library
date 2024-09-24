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
  bundledCode: "#line 2 \"Graph/bfs2.hpp\"\n\n#line 2 \"Graph/graph-template.hpp\"\
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
    \ &operator[](long long v){\n        return G[v];\n    }\n};\n#line 4 \"Graph/bfs2.hpp\"\
    \n\n//bfs2(\u5168\u70B9\u5BFE\u6700\u77ED\u7D4C\u8DEF)\nstruct bfs2{\n    vector<vector<bool>>\
    \ visited;\n    vector<vector<long long>> dist;\n    vector<vector<long long>>\
    \ parent;\n    bfs2(Graph &g){\n        long long n = g.size();\n        visited.assign(n,\
    \ vector<bool>(n, false));\n        dist.assign(n, vector<long long>(n, -1));\n\
    \        parent.assign(n, vector<long long>(n, -1));\n        for(long long s\
    \ = 0; s < n; s++){\n            visited[s][s] = true;\n            dist[s][s]\
    \ = 0;\n            parent[0][0] = -1;\n            queue<long long> que;\n  \
    \          que.push(s);\n            while(!que.empty()){\n                long\
    \ long cur = que.front();\n                que.pop();\n                for(auto\
    \ nxt : g[cur]){\n                    if(!visited[s][nxt.to]){\n             \
    \           que.push(nxt.to);\n                        visited[s][nxt.to] = true;\n\
    \                        dist[s][nxt.to] = dist[s][cur] + 1;\n               \
    \         parent[s][nxt.to] = cur;\n                    }\n                }\n\
    \            }\n        }\n    }\n\n    //\u6700\u5C0F\u30B3\u30B9\u30C8\u3092\
    \u6C42\u3081\u308B\n    long long cost(long long from, long long to){\n      \
    \  return dist[from][to];\n    }\n\n    //\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\
    \u3081\u308B\n    vector<long long> path(long long from, long long to){\n    \
    \    vector<long long> path;\n        if(!visited[from][to]){\n            return\
    \ path;\n        }\n        for(long long i = to; i != -1; i = parent[from][i]){\n\
    \            path.push_back(i);\n        }\n        reverse(path.begin(), path.end());\n\
    \        return path;\n    }\n\n    //\u5230\u9054\u53EF\u80FD\u304B\u8ABF\u3079\
    \u308B\n    bool cango(long long from, long long to){\n        return visited[from][to];\n\
    \    }\n};\n"
  code: "#pragma once\n\n#include \"Graph/graph-template.hpp\"\n\n//bfs2(\u5168\u70B9\
    \u5BFE\u6700\u77ED\u7D4C\u8DEF)\nstruct bfs2{\n    vector<vector<bool>> visited;\n\
    \    vector<vector<long long>> dist;\n    vector<vector<long long>> parent;\n\
    \    bfs2(Graph &g){\n        long long n = g.size();\n        visited.assign(n,\
    \ vector<bool>(n, false));\n        dist.assign(n, vector<long long>(n, -1));\n\
    \        parent.assign(n, vector<long long>(n, -1));\n        for(long long s\
    \ = 0; s < n; s++){\n            visited[s][s] = true;\n            dist[s][s]\
    \ = 0;\n            parent[0][0] = -1;\n            queue<long long> que;\n  \
    \          que.push(s);\n            while(!que.empty()){\n                long\
    \ long cur = que.front();\n                que.pop();\n                for(auto\
    \ nxt : g[cur]){\n                    if(!visited[s][nxt.to]){\n             \
    \           que.push(nxt.to);\n                        visited[s][nxt.to] = true;\n\
    \                        dist[s][nxt.to] = dist[s][cur] + 1;\n               \
    \         parent[s][nxt.to] = cur;\n                    }\n                }\n\
    \            }\n        }\n    }\n\n    //\u6700\u5C0F\u30B3\u30B9\u30C8\u3092\
    \u6C42\u3081\u308B\n    long long cost(long long from, long long to){\n      \
    \  return dist[from][to];\n    }\n\n    //\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\
    \u3081\u308B\n    vector<long long> path(long long from, long long to){\n    \
    \    vector<long long> path;\n        if(!visited[from][to]){\n            return\
    \ path;\n        }\n        for(long long i = to; i != -1; i = parent[from][i]){\n\
    \            path.push_back(i);\n        }\n        reverse(path.begin(), path.end());\n\
    \        return path;\n    }\n\n    //\u5230\u9054\u53EF\u80FD\u304B\u8ABF\u3079\
    \u308B\n    bool cango(long long from, long long to){\n        return visited[from][to];\n\
    \    }\n};\n"
  dependsOn:
  - Graph/graph-template.hpp
  - Template/template.hpp
  isVerificationFile: false
  path: Graph/bfs2.hpp
  requiredBy: []
  timestamp: '2024-09-24 22:59:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/bfs2.hpp
layout: document
redirect_from:
- /library/Graph/bfs2.hpp
- /library/Graph/bfs2.hpp.html
title: Graph/bfs2.hpp
---
