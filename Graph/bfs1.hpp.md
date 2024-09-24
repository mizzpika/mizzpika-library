---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: Graph/graph-template.hpp
    title: graph-template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/bfs1.hpp\"\n\n#line 1 \"Graph/graph-template.hpp\"\
    \n//graph_template\nstruct Edge{\n    long long to;\n    long long cost;\n   \
    \ Edge(long long to, long long cost) : to(to), cost(cost) {}\n    bool operator>(const\
    \ Edge &e) const{\n        return cost > e.cost;\n    }\n    bool operator<(const\
    \ Edge &e) const{\n        return cost < e.cost;\n    }\n};\n\nstruct Edge2{\n\
    \    long long from;\n    long long to;\n    long long cost;\n    Edge2(long long\
    \ from, long long to, long long cost) : from(from), to(to), cost(cost) {}\n  \
    \  bool operator>(const Edge2 &e) const{\n        return cost > e.cost;\n    }\n\
    \    bool operator<(const Edge2 &e) const{\n        return cost < e.cost;\n  \
    \  }\n};\n\nstruct Edge3 {\n    long long to;\n    Edge3(long long to) : to(to)\
    \ {}\n};\n\nstruct Graph{\n    Graph() = default;\n    vector<vector<Edge>> G;\n\
    \n    Graph(long long N){\n        G.resize(N);\n    }\n\n    long long size(){\n\
    \        return G.size();\n    }\n\n    void add(long long from, long long to,\
    \ long long cost = 1){\n        G[from].push_back(Edge(to, cost));\n        G[to].push_back(Edge(from,\
    \ cost));\n    }\n\n    void add_di(long long from, long long to, long long cost\
    \ = 1){\n        G[from].push_back(Edge(to, cost));\n    }\n\n    vector<Edge>\
    \ &operator[](long long v){\n        return G[v];\n    }\n};\n#line 4 \"Graph/bfs1.hpp\"\
    \n\n//bfs1(\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF)\nstruct bfs1{\n \
    \   vector<bool> visited;\n    vector<long long> dist;\n    vector<long long>\
    \ parent;\n\n    //bfs1(\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF)\u3092\
    \u69CB\u7BC9\n    bfs1(Graph &g, long long s){\n        long long n = g.size();\n\
    \        visited.assign(n, false);\n        dist.assign(n, -1);\n        parent.assign(n,\
    \ -1);\n        visited[s] = true;\n        dist[s] = 0;\n        parent[s] =\
    \ -1;\n        queue<long long> que;\n        que.push(s);\n        while(!que.empty()){\n\
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
  isVerificationFile: false
  path: Graph/bfs1.hpp
  requiredBy: []
  timestamp: '2024-09-24 18:52:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/bfs1.hpp
layout: document
redirect_from:
- /library/Graph/bfs1.hpp
- /library/Graph/bfs1.hpp.html
title: Graph/bfs1.hpp
---
