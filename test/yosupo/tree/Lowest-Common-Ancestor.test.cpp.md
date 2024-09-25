---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/LCA.hpp
    title: Graph/LCA.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/graph-template.hpp
    title: graph-template
  - icon: ':heavy_check_mark:'
    path: Template/template.hpp
    title: Template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/yosupo/tree/Lowest-Common-Ancestor.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#line 2 \"Template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n#pragma GCC optimize(\"Ofast,unroll-loops\")\n#pragma\
    \ GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native\"\
    )\nusing namespace std;\nusing ll = long long;\n#define rep(i,n) for(ll i = 0LL;\
    \ i < (ll)n; ++i)\n#define rep1(i,n) for(ll i = 1LL; i <= (ll)n; ++i)\n#define\
    \ rep2(i,m,n) for(ll i = (ll)m; i < (ll)n; ++i)\n#define rrep(i,n) for(ll i =\
    \ (ll)n - 1; i >= 0LL; --i)\n#define rrep1(i,n) for(ll i = (ll)n; i > 0LL; --i)\n\
    #define rrep2(i,m,n) for(ll i = (ll)m; i > (ll)n; --i)\n#define _GLIBCXX_DEBUG\n\
    #define _CRT_SECURE_NO_WARNINGS\n#line 2 \"Graph/LCA.hpp\"\n\n#line 2 \"Graph/graph-template.hpp\"\
    \n\n#line 4 \"Graph/graph-template.hpp\"\n\n//graph_template\nstruct Edge{\n \
    \   ll to;\n    ll cost;\n    Edge(ll to, ll cost) : to(to), cost(cost) {}\n \
    \   bool operator>(const Edge &e) const{\n        return cost > e.cost;\n    }\n\
    \    bool operator<(const Edge &e) const{\n        return cost < e.cost;\n   \
    \ }\n};\n\nstruct Edge2{\n    ll from;\n    ll to;\n    ll cost;\n    Edge2(ll\
    \ from, ll to, ll cost) : from(from), to(to), cost(cost) {}\n    bool operator>(const\
    \ Edge2 &e) const{\n        return cost > e.cost;\n    }\n    bool operator<(const\
    \ Edge2 &e) const{\n        return cost < e.cost;\n    }\n};\n\nstruct Edge3 {\n\
    \    ll to;\n    Edge3(ll to) : to(to) {}\n};\n\nstruct Graph{\n    Graph() =\
    \ default;\n    vector<vector<Edge>> G;\n\n    Graph(ll N){\n        G.resize(N);\n\
    \    }\n\n    ll size(){\n        return G.size();\n    }\n\n    void add(ll from,\
    \ ll to, ll cost = 1){\n        G[from].push_back(Edge(to, cost));\n        G[to].push_back(Edge(from,\
    \ cost));\n    }\n\n    void add_di(ll from, ll to, ll cost = 1){\n        G[from].push_back(Edge(to,\
    \ cost));\n    }\n\n    vector<Edge> &operator[](ll v){\n        return G[v];\n\
    \    }\n};\n#line 4 \"Graph/LCA.hpp\"\n\n//LCA\nstruct LCA {\n    vector<vector<long\
    \ long>> parent;\n    vector<long long> dist;\n\n    LCA(Graph &g, long long root\
    \ = 0){\n        vector<vector<Edge3>> G(g.size());\n        for(long long i =\
    \ 0; i < g.size(); i++){\n            for(auto e : g[i]){\n                G[i].emplace_back(e.to);\n\
    \            }\n        }\n        long long V = G.size();\n        long long\
    \ K = 1;\n        while ((1 << K) < V) K++;\n        parent.assign(K, vector<long\
    \ long>(V, -1));\n        dist.assign(V, -1);\n        dfs(G, root, -1, 0);\n\
    \        for (long long k = 0; k + 1 < K; k++) {\n            for (long long v\
    \ = 0; v < V; v++) {\n                if (parent[k][v] < 0) {\n              \
    \      parent[k + 1][v] = -1;\n                } else {\n                    parent[k\
    \ + 1][v] = parent[k][parent[k][v]];\n                }\n            }\n     \
    \   }\n    }\n\n    void dfs(const vector<vector<Edge3>> &G, long long v, long\
    \ long p, long long d) {\n        parent[0][v] = p;\n        dist[v] = d;\n  \
    \      for (auto e : G[v]) {\n            if (e.to != p) dfs(G, e.to, v, d + 1);\n\
    \        }\n    }\n\n    //\u6700\u5C0F\u5171\u901A\u7956\u5148\u3092\u6C42\u3081\
    \u308B\n    long long query(long long u, long long v) {\n        if (dist[u] <\
    \ dist[v]) swap(u, v);\n        long long K = parent.size();\n        for (long\
    \ long k = 0; k < K; k++) {\n            if ((dist[u] - dist[v]) >> k & 1) {\n\
    \                u = parent[k][u];\n            }\n        }\n        if (u ==\
    \ v) return u;\n        for (long long k = K - 1; k >= 0; k--) {\n           \
    \ if (parent[k][u] != parent[k][v]) {\n                u = parent[k][u];\n   \
    \             v = parent[k][v];\n            }\n        }\n        return parent[0][u];\n\
    \    }\n\n    //\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B\n    long long\
    \ get_dist(long long u, long long v){\n        return dist[u] + dist[v] - 2 *\
    \ dist[query(u, v)];\n    }\n\n    //a\u304Cu\u3068v\u306Epath\u4E0A\u306B\u3042\
    \u308B\u304B\n    bool is_on_path(long long u, long long v, long long a){\n  \
    \      return get_dist(u, a) + get_dist(a, v) == get_dist(u, v);\n    }\n};\n\
    #line 4 \"test/yosupo/tree/Lowest-Common-Ancestor.test.cpp\"\n\nint main(){\n\
    \    ll n, q; cin >> n >> q;\n    Graph g(n);\n    rep(i,n - 1){\n        ll p;\
    \ cin >> p;\n        g.add_di(p, i + 1);\n    }\n    LCA lca(g);\n    while(q--){\n\
    \        ll u, v; cin >> u >> v;\n        cout << lca.query(u, v) << endl;\n \
    \   }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n#include \"Template/template.hpp\"\
    \n#include \"Graph/LCA.hpp\"\n\nint main(){\n    ll n, q; cin >> n >> q;\n   \
    \ Graph g(n);\n    rep(i,n - 1){\n        ll p; cin >> p;\n        g.add_di(p,\
    \ i + 1);\n    }\n    LCA lca(g);\n    while(q--){\n        ll u, v; cin >> u\
    \ >> v;\n        cout << lca.query(u, v) << endl;\n    }\n}\n"
  dependsOn:
  - Template/template.hpp
  - Graph/LCA.hpp
  - Graph/graph-template.hpp
  isVerificationFile: true
  path: test/yosupo/tree/Lowest-Common-Ancestor.test.cpp
  requiredBy: []
  timestamp: '2024-09-25 22:12:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/tree/Lowest-Common-Ancestor.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/tree/Lowest-Common-Ancestor.test.cpp
- /verify/test/yosupo/tree/Lowest-Common-Ancestor.test.cpp.html
title: test/yosupo/tree/Lowest-Common-Ancestor.test.cpp
---