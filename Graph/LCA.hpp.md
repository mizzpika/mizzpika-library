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
  bundledCode: "#line 2 \"Graph/LCA.hpp\"\n\n#line 1 \"Graph/graph-template.hpp\"\n\
    //graph_template\nstruct Edge{\n    long long to;\n    long long cost;\n    Edge(long\
    \ long to, long long cost) : to(to), cost(cost) {}\n    bool operator>(const Edge\
    \ &e) const{\n        return cost > e.cost;\n    }\n    bool operator<(const Edge\
    \ &e) const{\n        return cost < e.cost;\n    }\n};\n\nstruct Edge2{\n    long\
    \ long from;\n    long long to;\n    long long cost;\n    Edge2(long long from,\
    \ long long to, long long cost) : from(from), to(to), cost(cost) {}\n    bool\
    \ operator>(const Edge2 &e) const{\n        return cost > e.cost;\n    }\n   \
    \ bool operator<(const Edge2 &e) const{\n        return cost < e.cost;\n    }\n\
    };\n\nstruct Edge3 {\n    long long to;\n    Edge3(long long to) : to(to) {}\n\
    };\n\nstruct Graph{\n    Graph() = default;\n    vector<vector<Edge>> G;\n\n \
    \   Graph(long long N){\n        G.resize(N);\n    }\n\n    long long size(){\n\
    \        return G.size();\n    }\n\n    void add(long long from, long long to,\
    \ long long cost = 1){\n        G[from].push_back(Edge(to, cost));\n        G[to].push_back(Edge(from,\
    \ cost));\n    }\n\n    void add_di(long long from, long long to, long long cost\
    \ = 1){\n        G[from].push_back(Edge(to, cost));\n    }\n\n    vector<Edge>\
    \ &operator[](long long v){\n        return G[v];\n    }\n};\n#line 4 \"Graph/LCA.hpp\"\
    \n\n//LCA\nstruct LCA {\n    vector<vector<long long>> parent;\n    vector<long\
    \ long> dist;\n\n    LCA(Graph &g, long long root = 0){\n        vector<vector<Edge3>>\
    \ G(g.size());\n        for(long long i = 0; i < g.size(); i++){\n           \
    \ for(auto e : g[i]){\n                G[i].emplace_back(e.to);\n            }\n\
    \        }\n        long long V = G.size();\n        long long K = 1;\n      \
    \  while ((1 << K) < V) K++;\n        parent.assign(K, vector<long long>(V, -1));\n\
    \        dist.assign(V, -1);\n        dfs(G, root, -1, 0);\n        for (long\
    \ long k = 0; k + 1 < K; k++) {\n            for (long long v = 0; v < V; v++)\
    \ {\n                if (parent[k][v] < 0) {\n                    parent[k + 1][v]\
    \ = -1;\n                } else {\n                    parent[k + 1][v] = parent[k][parent[k][v]];\n\
    \                }\n            }\n        }\n    }\n\n    void dfs(const vector<vector<Edge3>>\
    \ &G, long long v, long long p, long long d) {\n        parent[0][v] = p;\n  \
    \      dist[v] = d;\n        for (auto e : G[v]) {\n            if (e.to != p)\
    \ dfs(G, e.to, v, d + 1);\n        }\n    }\n\n    //\u6700\u5C0F\u5171\u901A\u7956\
    \u5148\u3092\u6C42\u3081\u308B\n    long long query(long long u, long long v)\
    \ {\n        if (dist[u] < dist[v]) swap(u, v);\n        long long K = parent.size();\n\
    \        for (long long k = 0; k < K; k++) {\n            if ((dist[u] - dist[v])\
    \ >> k & 1) {\n                u = parent[k][u];\n            }\n        }\n \
    \       if (u == v) return u;\n        for (long long k = K - 1; k >= 0; k--)\
    \ {\n            if (parent[k][u] != parent[k][v]) {\n                u = parent[k][u];\n\
    \                v = parent[k][v];\n            }\n        }\n        return parent[0][u];\n\
    \    }\n\n    //\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B\n    long long\
    \ get_dist(long long u, long long v){\n        return dist[u] + dist[v] - 2 *\
    \ dist[query(u, v)];\n    }\n\n    //a\u304Cu\u3068v\u306Epath\u4E0A\u306B\u3042\
    \u308B\u304B\n    bool is_on_path(long long u, long long v, long long a){\n  \
    \      return get_dist(u, a) + get_dist(a, v) == get_dist(u, v);\n    }\n};\n"
  code: "#pragma once\n\n#include \"Graph/graph-template.hpp\"\n\n//LCA\nstruct LCA\
    \ {\n    vector<vector<long long>> parent;\n    vector<long long> dist;\n\n  \
    \  LCA(Graph &g, long long root = 0){\n        vector<vector<Edge3>> G(g.size());\n\
    \        for(long long i = 0; i < g.size(); i++){\n            for(auto e : g[i]){\n\
    \                G[i].emplace_back(e.to);\n            }\n        }\n        long\
    \ long V = G.size();\n        long long K = 1;\n        while ((1 << K) < V) K++;\n\
    \        parent.assign(K, vector<long long>(V, -1));\n        dist.assign(V, -1);\n\
    \        dfs(G, root, -1, 0);\n        for (long long k = 0; k + 1 < K; k++) {\n\
    \            for (long long v = 0; v < V; v++) {\n                if (parent[k][v]\
    \ < 0) {\n                    parent[k + 1][v] = -1;\n                } else {\n\
    \                    parent[k + 1][v] = parent[k][parent[k][v]];\n           \
    \     }\n            }\n        }\n    }\n\n    void dfs(const vector<vector<Edge3>>\
    \ &G, long long v, long long p, long long d) {\n        parent[0][v] = p;\n  \
    \      dist[v] = d;\n        for (auto e : G[v]) {\n            if (e.to != p)\
    \ dfs(G, e.to, v, d + 1);\n        }\n    }\n\n    //\u6700\u5C0F\u5171\u901A\u7956\
    \u5148\u3092\u6C42\u3081\u308B\n    long long query(long long u, long long v)\
    \ {\n        if (dist[u] < dist[v]) swap(u, v);\n        long long K = parent.size();\n\
    \        for (long long k = 0; k < K; k++) {\n            if ((dist[u] - dist[v])\
    \ >> k & 1) {\n                u = parent[k][u];\n            }\n        }\n \
    \       if (u == v) return u;\n        for (long long k = K - 1; k >= 0; k--)\
    \ {\n            if (parent[k][u] != parent[k][v]) {\n                u = parent[k][u];\n\
    \                v = parent[k][v];\n            }\n        }\n        return parent[0][u];\n\
    \    }\n\n    //\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B\n    long long\
    \ get_dist(long long u, long long v){\n        return dist[u] + dist[v] - 2 *\
    \ dist[query(u, v)];\n    }\n\n    //a\u304Cu\u3068v\u306Epath\u4E0A\u306B\u3042\
    \u308B\u304B\n    bool is_on_path(long long u, long long v, long long a){\n  \
    \      return get_dist(u, a) + get_dist(a, v) == get_dist(u, v);\n    }\n};\n"
  dependsOn:
  - Graph/graph-template.hpp
  isVerificationFile: false
  path: Graph/LCA.hpp
  requiredBy: []
  timestamp: '2024-09-24 20:59:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/LCA.hpp
layout: document
redirect_from:
- /library/Graph/LCA.hpp
- /library/Graph/LCA.hpp.html
title: Graph/LCA.hpp
---
