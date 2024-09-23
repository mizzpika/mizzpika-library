---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/graph-template.cpp\"\n//graph_template\nstruct Edge{\n\
    \    ll to;\n    ll cost;\n    Edge(ll to, ll cost) : to(to), cost(cost) {}\n\
    \    bool operator>(const Edge &e) const{\n        return cost > e.cost;\n   \
    \ }\n    bool operator<(const Edge &e) const{\n        return cost < e.cost;\n\
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
    \    }\n};\n"
  code: "//graph_template\nstruct Edge{\n    ll to;\n    ll cost;\n    Edge(ll to,\
    \ ll cost) : to(to), cost(cost) {}\n    bool operator>(const Edge &e) const{\n\
    \        return cost > e.cost;\n    }\n    bool operator<(const Edge &e) const{\n\
    \        return cost < e.cost;\n    }\n};\n\nstruct Edge2{\n    ll from;\n   \
    \ ll to;\n    ll cost;\n    Edge2(ll from, ll to, ll cost) : from(from), to(to),\
    \ cost(cost) {}\n    bool operator>(const Edge2 &e) const{\n        return cost\
    \ > e.cost;\n    }\n    bool operator<(const Edge2 &e) const{\n        return\
    \ cost < e.cost;\n    }\n};\n\nstruct Edge3 {\n    ll to;\n    Edge3(ll to) :\
    \ to(to) {}\n};\n\nstruct Graph{\n    Graph() = default;\n    vector<vector<Edge>>\
    \ G;\n\n    Graph(ll N){\n        G.resize(N);\n    }\n\n    ll size(){\n    \
    \    return G.size();\n    }\n\n    void add(ll from, ll to, ll cost = 1){\n \
    \       G[from].push_back(Edge(to, cost));\n        G[to].push_back(Edge(from,\
    \ cost));\n    }\n\n    void add_di(ll from, ll to, ll cost = 1){\n        G[from].push_back(Edge(to,\
    \ cost));\n    }\n\n    vector<Edge> &operator[](ll v){\n        return G[v];\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/graph-template.cpp
  requiredBy: []
  timestamp: '2024-09-23 12:47:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/graph-template.cpp
layout: document
redirect_from:
- /library/Graph/graph-template.cpp
- /library/Graph/graph-template.cpp.html
title: Graph/graph-template.cpp
---
