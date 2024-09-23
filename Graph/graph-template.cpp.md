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
    \    long long to;\n    long long cost;\n    Edge(long long to, long long cost)\
    \ : to(to), cost(cost) {}\n    bool operator>(const Edge &e) const{\n        return\
    \ cost > e.cost;\n    }\n    bool operator<(const Edge &e) const{\n        return\
    \ cost < e.cost;\n    }\n};\n\nstruct Edge2{\n    long long from;\n    long long\
    \ to;\n    long long cost;\n    Edge2(long long from, long long to, long long\
    \ cost) : from(from), to(to), cost(cost) {}\n    bool operator>(const Edge2 &e)\
    \ const{\n        return cost > e.cost;\n    }\n    bool operator<(const Edge2\
    \ &e) const{\n        return cost < e.cost;\n    }\n};\n\nstruct Edge3 {\n   \
    \ long long to;\n    Edge3(long long to) : to(to) {}\n};\n\nstruct Graph{\n  \
    \  Graph() = default;\n    vector<vector<Edge>> G;\n\n    Graph(long long N){\n\
    \        G.resize(N);\n    }\n\n    long long size(){\n        return G.size();\n\
    \    }\n\n    void add(long long from, long long to, long long cost = 1){\n  \
    \      G[from].push_back(Edge(to, cost));\n        G[to].push_back(Edge(from,\
    \ cost));\n    }\n\n    void add_di(long long from, long long to, long long cost\
    \ = 1){\n        G[from].push_back(Edge(to, cost));\n    }\n\n    vector<Edge>\
    \ &operator[](long long v){\n        return G[v];\n    }\n};\n"
  code: "//graph_template\nstruct Edge{\n    long long to;\n    long long cost;\n\
    \    Edge(long long to, long long cost) : to(to), cost(cost) {}\n    bool operator>(const\
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
    \ &operator[](long long v){\n        return G[v];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/graph-template.cpp
  requiredBy: []
  timestamp: '2024-09-23 13:51:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/graph-template.cpp
layout: document
redirect_from:
- /library/Graph/graph-template.cpp
- /library/Graph/graph-template.cpp.html
title: Graph/graph-template.cpp
---
