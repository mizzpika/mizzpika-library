---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/DSU.hpp
    title: DSU
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
  bundledCode: "#line 2 \"Graph/kruskal.hpp\"\n\n#line 2 \"Graph/graph-template.hpp\"\
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
    \    }\n};\n#line 4 \"Graph/kruskal.hpp\"\n\n#line 2 \"Graph/DSU.hpp\"\n\n//DSU\n\
    struct DSU{\n    vector<long long> par, rank, siz;\n    DSU(long long n):par(n,\
    \ -1), rank(n, 0), siz(n, 1){}\n\n    //\u6839\u3092\u6C42\u3081\u308B\n    long\
    \ long leader(long long x){\n        if(par[x] == -1){\n            return x;\n\
    \        }else{\n            return par[x] = leader(par[x]);\n        }\n    }\n\
    \n    //\u9023\u7D50\u5224\u5B9A\n    bool same(long long x, long long y){\n \
    \       return leader(x) == leader(y);\n    }\n\n    //\u9023\u7D50\n    bool\
    \ merge(long long x, long long y){\n        long long rx = leader(x), ry = leader(y);\n\
    \        if(rx == ry){\n            return false;\n        }\n        if(rank[rx]\
    \ < rank[ry]){\n            swap(rx, ry);\n        }\n        par[ry] = rx;\n\
    \        if(rank[rx] == rank[ry]){\n            rank[rx]++;\n        }\n     \
    \   siz[rx] += siz[ry];\n        return true;\n    }\n\n    //\u96C6\u5408\u306E\
    \u5927\u304D\u3055\u3092\u6C42\u3081\u308B\n    long long size(long long x){\n\
    \        return siz[leader(x)];\n    }\n};\n#line 6 \"Graph/kruskal.hpp\"\n\n\
    //kruskal\nstruct kruskal{\n    long long n;\n    vector<Edge2> edges;\n    bool\
    \ mn_finish = false, mx_finish = false;\n    long long mn, mx;\n    set<long long>\
    \ mn_path, mx_path;\n    //kruskal\u306E\u69CB\u7BC9\n    kruskal(Graph &g){\n\
    \        n = g.size();\n        for(long long i = 0; i < n; i++){\n          \
    \  for(auto e : g[i]){\n                edges.emplace_back(i, e.to, e.cost);\n\
    \            }\n        }\n    }\n\n    //\u6700\u5C0F\u5168\u57DF\u6728\u306E\
    \u30B3\u30B9\u30C8\u3092\u6C42\u3081\u308B\n    long long min_cost(){\n      \
    \  if(mn_finish){\n            return mn;\n        }\n        sort(edges.begin(),\
    \ edges.end());\n        DSU dsu(n);\n        long long ret = 0;\n        for(auto\
    \ e : edges){\n            if(dsu.merge(e.from, e.to)){\n                ret +=\
    \ e.cost;\n                mn_path.insert(e.from);\n                mn_path.insert(e.to);\n\
    \            }\n        }\n        return mn = ret;\n    }\n\n    //\u6700\u5927\
    \u5168\u57DF\u6728\u306E\u30B3\u30B9\u30C8\u3092\u6C42\u3081\u308B\n    long long\
    \ max_cost(){\n        if(mx_finish){\n            return mx;\n        }\n   \
    \     sort(edges.rbegin(), edges.rend());\n        DSU dsu(n);\n        long long\
    \ ret = 0;\n        for(auto e : edges){\n            if(dsu.merge(e.from, e.to)){\n\
    \                ret += e.cost;\n                mx_path.insert(e.from);\n   \
    \             mx_path.insert(e.to);\n            }\n        }\n        return\
    \ mx = ret;\n    }\n\n    //\u6700\u5C0F\u5168\u57DF\u6728\u306E\u30D1\u30B9\u3092\
    set\u3067\u6C42\u3081\u308B\n    set<long long> min_path(){\n        if(mn_finish){\n\
    \            return mn_path;\n        }\n        sort(edges.begin(), edges.end());\n\
    \        DSU dsu(n);\n        long long ret = 0;\n        for(auto e : edges){\n\
    \            if(dsu.merge(e.from, e.to)){\n                ret += e.cost;\n  \
    \              mn_path.insert(e.from);\n                mn_path.insert(e.to);\n\
    \            }\n        }\n        return mn_path;\n    }\n\n    //\u6700\u5927\
    \u5168\u57DF\u6728\u306E\u30D1\u30B9\u3092set\u3067\u6C42\u3081\u308B\n    set<long\
    \ long> max_path(){\n        if(mx_finish){\n            return mx_path;\n   \
    \     }\n        sort(edges.rbegin(), edges.rend());\n        DSU dsu(n);\n  \
    \      long long ret = 0;\n        for(auto e : edges){\n            if(dsu.merge(e.from,\
    \ e.to)){\n                ret += e.cost;\n                mx_path.insert(e.from);\n\
    \                mx_path.insert(e.to);\n            }\n        }\n        return\
    \ mx_path;\n    }\n};\n"
  code: "#pragma once\n\n#include \"Graph/graph-template.hpp\"\n\n#include \"Graph/DSU.hpp\"\
    \n\n//kruskal\nstruct kruskal{\n    long long n;\n    vector<Edge2> edges;\n \
    \   bool mn_finish = false, mx_finish = false;\n    long long mn, mx;\n    set<long\
    \ long> mn_path, mx_path;\n    //kruskal\u306E\u69CB\u7BC9\n    kruskal(Graph\
    \ &g){\n        n = g.size();\n        for(long long i = 0; i < n; i++){\n   \
    \         for(auto e : g[i]){\n                edges.emplace_back(i, e.to, e.cost);\n\
    \            }\n        }\n    }\n\n    //\u6700\u5C0F\u5168\u57DF\u6728\u306E\
    \u30B3\u30B9\u30C8\u3092\u6C42\u3081\u308B\n    long long min_cost(){\n      \
    \  if(mn_finish){\n            return mn;\n        }\n        sort(edges.begin(),\
    \ edges.end());\n        DSU dsu(n);\n        long long ret = 0;\n        for(auto\
    \ e : edges){\n            if(dsu.merge(e.from, e.to)){\n                ret +=\
    \ e.cost;\n                mn_path.insert(e.from);\n                mn_path.insert(e.to);\n\
    \            }\n        }\n        return mn = ret;\n    }\n\n    //\u6700\u5927\
    \u5168\u57DF\u6728\u306E\u30B3\u30B9\u30C8\u3092\u6C42\u3081\u308B\n    long long\
    \ max_cost(){\n        if(mx_finish){\n            return mx;\n        }\n   \
    \     sort(edges.rbegin(), edges.rend());\n        DSU dsu(n);\n        long long\
    \ ret = 0;\n        for(auto e : edges){\n            if(dsu.merge(e.from, e.to)){\n\
    \                ret += e.cost;\n                mx_path.insert(e.from);\n   \
    \             mx_path.insert(e.to);\n            }\n        }\n        return\
    \ mx = ret;\n    }\n\n    //\u6700\u5C0F\u5168\u57DF\u6728\u306E\u30D1\u30B9\u3092\
    set\u3067\u6C42\u3081\u308B\n    set<long long> min_path(){\n        if(mn_finish){\n\
    \            return mn_path;\n        }\n        sort(edges.begin(), edges.end());\n\
    \        DSU dsu(n);\n        long long ret = 0;\n        for(auto e : edges){\n\
    \            if(dsu.merge(e.from, e.to)){\n                ret += e.cost;\n  \
    \              mn_path.insert(e.from);\n                mn_path.insert(e.to);\n\
    \            }\n        }\n        return mn_path;\n    }\n\n    //\u6700\u5927\
    \u5168\u57DF\u6728\u306E\u30D1\u30B9\u3092set\u3067\u6C42\u3081\u308B\n    set<long\
    \ long> max_path(){\n        if(mx_finish){\n            return mx_path;\n   \
    \     }\n        sort(edges.rbegin(), edges.rend());\n        DSU dsu(n);\n  \
    \      long long ret = 0;\n        for(auto e : edges){\n            if(dsu.merge(e.from,\
    \ e.to)){\n                ret += e.cost;\n                mx_path.insert(e.from);\n\
    \                mx_path.insert(e.to);\n            }\n        }\n        return\
    \ mx_path;\n    }\n};\n"
  dependsOn:
  - Graph/graph-template.hpp
  - Template/template.hpp
  - Graph/DSU.hpp
  isVerificationFile: false
  path: Graph/kruskal.hpp
  requiredBy: []
  timestamp: '2024-09-25 22:12:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/kruskal.hpp
layout: document
redirect_from:
- /library/Graph/kruskal.hpp
- /library/Graph/kruskal.hpp.html
title: Graph/kruskal.hpp
---