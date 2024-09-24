---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/dijkstra.hpp
    title: dijkstra
  - icon: ':heavy_check_mark:'
    path: Graph/graph-template.hpp
    title: graph-template
  - icon: ':question:'
    path: Template/template.hpp
    title: Template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/yosupo/graph/shortest-path.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/shortest_path\"\n#line 2 \"Template/template.hpp\"\
    \n\n#include <bits/stdc++.h>\n#pragma GCC optimize(\"Ofast,unroll-loops\")\n#pragma\
    \ GCC target(\"sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native\"\
    )\nusing namespace std;\nusing ll = long long;\n#define rep(i,n) for(ll i = 0LL;\
    \ i < (ll)n; ++i)\n#define rep1(i,n) for(ll i = 1LL; i <= (ll)n; ++i)\n#define\
    \ rep2(i,m,n) for(ll i = (ll)m; i < (ll)n; ++i)\n#define rrep(i,n) for(ll i =\
    \ (ll)n - 1; i >= 0LL; --i)\n#define rrep1(i,n) for(ll i = (ll)n; i > 0LL; --i)\n\
    #define rrep2(i,m,n) for(ll i = (ll)m; i > (ll)n; --i)\n#define _GLIBCXX_DEBUG\n\
    #define _CRT_SECURE_NO_WARNINGS\n#line 2 \"Graph/dijkstra.hpp\"\n\n#line 2 \"\
    Graph/graph-template.hpp\"\n\n#line 4 \"Graph/graph-template.hpp\"\n\n//graph_template\n\
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
    \ &operator[](long long v){\n        return G[v];\n    }\n};\n#line 4 \"Graph/dijkstra.hpp\"\
    \n\n//dijkstra\nstruct dijkstra{\n    vector<long long> dist;\n    vector<long\
    \ long> prev;\n\n    //dijkstra\u3092\u69CB\u7BC9\n    dijkstra(Graph &G, long\
    \ long s){\n        long long N = G.size();\n        dist.assign(N, 1LL << 60);\n\
    \        prev.assign(N, -1);\n        priority_queue<pair<ll, ll>, vector<pair<ll,\
    \ ll>>, greater<pair<ll, ll>>> pq;\n        dist[s] = 0LL;\n        pq.emplace(dist[s],\
    \ s);\n        while (!pq.empty()){\n            auto p = pq.top();\n        \
    \    pq.pop();\n            long long v = p.second;\n            if(dist[v] <\
    \ p.first) continue;\n            for (auto &e : G[v]){\n                if (dist[e.to]\
    \ > dist[v] + e.cost){\n                    dist[e.to] = dist[v] + e.cost;\n \
    \                   prev[e.to] = v;\n                    pq.emplace(dist[e.to],\
    \ e.to);\n                }\n            }\n        }\n    }\n\n    //\u6700\u5C0F\
    \u30B3\u30B9\u30C8\u3092\u6C42\u3081\u308B\n    long long cost(ll to){\n     \
    \   return dist[to];\n    }\n\n    //\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\
    \u308B\n    vector<long long> path(long long to){\n        vector<ll> get_path;\n\
    \        for (long long i = to; i != -1; i = prev[i]){\n            get_path.push_back(i);\n\
    \        }\n        reverse(get_path.begin(), get_path.end());\n        return\
    \ get_path;\n    }\n\n    //\u5230\u9054\u53EF\u80FD\u304B\u8ABF\u3079\u308B\n\
    \    bool cango(ll to){\n        return dist[to] != 1LL << 60;\n    }\n};\n#line\
    \ 4 \"test/yosupo/graph/shortest-path.test.cpp\"\nint main(){\n    ll n, m, s,\
    \ t; cin >> n >> m >> s >> t;\n    Graph g(n);\n    rep(i,m){\n        ll a, b,\
    \ c; cin >> a >> b >> c;\n        g.add_di(a, b, c);\n    }\n    dijkstra ds(g,\
    \ s);\n    if(!ds.cango(t)){\n        cout << -1;\n        return 0;\n    }\n\
    \    auto res = ds.path(t);\n    cout << ds.cost(t) << ' ' << res.size() - 1 <<\
    \ endl;\n    rep(i,res.size() - 1){\n        cout << res[i] << ' ' << res[i +\
    \ 1] << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ \"Template/template.hpp\"\n#include \"Graph/dijkstra.hpp\"\nint main(){\n  \
    \  ll n, m, s, t; cin >> n >> m >> s >> t;\n    Graph g(n);\n    rep(i,m){\n \
    \       ll a, b, c; cin >> a >> b >> c;\n        g.add_di(a, b, c);\n    }\n \
    \   dijkstra ds(g, s);\n    if(!ds.cango(t)){\n        cout << -1;\n        return\
    \ 0;\n    }\n    auto res = ds.path(t);\n    cout << ds.cost(t) << ' ' << res.size()\
    \ - 1 << endl;\n    rep(i,res.size() - 1){\n        cout << res[i] << ' ' << res[i\
    \ + 1] << endl;\n    }\n}\n"
  dependsOn:
  - Template/template.hpp
  - Graph/dijkstra.hpp
  - Graph/graph-template.hpp
  isVerificationFile: true
  path: test/yosupo/graph/shortest-path.test.cpp
  requiredBy: []
  timestamp: '2024-09-24 23:19:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/graph/shortest-path.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/graph/shortest-path.test.cpp
- /verify/test/yosupo/graph/shortest-path.test.cpp.html
title: test/yosupo/graph/shortest-path.test.cpp
---
