---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Graph/LCA.hpp
    title: Graph/LCA.hpp
  - icon: ':warning:'
    path: Graph/bellman-ford.hpp
    title: Graph/bellman-ford.hpp
  - icon: ':warning:'
    path: Graph/bfs1.hpp
    title: Graph/bfs1.hpp
  - icon: ':warning:'
    path: Graph/bfs2.hpp
    title: Graph/bfs2.hpp
  - icon: ':warning:'
    path: Graph/kruskal.hpp
    title: Graph/kruskal.hpp
  - icon: ':warning:'
    path: Graph/warshall_floyd.hpp
    title: Graph/warshall_floyd.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/graph-template.hpp\"\n//graph_template\nstruct Edge{\n\
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
  path: Graph/graph-template.hpp
  requiredBy:
  - Graph/warshall_floyd.hpp
  - Graph/LCA.hpp
  - Graph/kruskal.hpp
  - Graph/bfs2.hpp
  - Graph/bfs1.hpp
  - Graph/bellman-ford.hpp
  timestamp: '2024-09-24 21:04:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/graph-template.hpp
layout: document
title: graph-template
---
`Graph`ライブラリを使う際のテンプレート

## 概要（ここではGraphについて）

* `Graph g(n)`で頂点数`n`のグラフを初期化する

* `void add(long long from, long long to, long long cost = 1)`で`from`と`to`に相互に重さ`cost`の辺を張る。重さを指定していない場合は`1`となる。

* `void add_di(long long from, long long to, long long cost = 1)`で`from`から`to`に重さ`cost`の辺を張る。重さを指定していない場合は`1`となる。

* `long long size()`で`g`の頂点数を返す

* `&operator[](long long u)`で`u`から辺が張られている頂点集合`v`の情報を返す
