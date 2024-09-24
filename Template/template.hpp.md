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
  - icon: ':heavy_check_mark:'
    path: Graph/dijkstra.hpp
    title: dijkstra
  - icon: ':heavy_check_mark:'
    path: Graph/graph-template.hpp
    title: graph-template
  - icon: ':warning:'
    path: Graph/kruskal.hpp
    title: Graph/kruskal.hpp
  - icon: ':warning:'
    path: Graph/warshall_floyd.hpp
    title: Graph/warshall_floyd.hpp
  - icon: ':warning:'
    path: Template/short.hpp
    title: Template/short.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-shortest-path.test.cpp
    title: test/yosupo-shortest-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/graph/shortest-path.test.cpp
    title: test/yosupo/graph/shortest-path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 2 "Template/template.hpp"


    #include <bits/stdc++.h>

    #pragma GCC optimize("Ofast,unroll-loops")

    #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

    using namespace std;

    using ll = long long;

    #define rep(i,n) for(ll i = 0LL; i < (ll)n; ++i)

    #define rep1(i,n) for(ll i = 1LL; i <= (ll)n; ++i)

    #define rep2(i,m,n) for(ll i = (ll)m; i < (ll)n; ++i)

    #define rrep(i,n) for(ll i = (ll)n - 1; i >= 0LL; --i)

    #define rrep1(i,n) for(ll i = (ll)n; i > 0LL; --i)

    #define rrep2(i,m,n) for(ll i = (ll)m; i > (ll)n; --i)

    #define _GLIBCXX_DEBUG

    #define _CRT_SECURE_NO_WARNINGS

    '
  code: '#pragma once


    #include <bits/stdc++.h>

    #pragma GCC optimize("Ofast,unroll-loops")

    #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

    using namespace std;

    using ll = long long;

    #define rep(i,n) for(ll i = 0LL; i < (ll)n; ++i)

    #define rep1(i,n) for(ll i = 1LL; i <= (ll)n; ++i)

    #define rep2(i,m,n) for(ll i = (ll)m; i < (ll)n; ++i)

    #define rrep(i,n) for(ll i = (ll)n - 1; i >= 0LL; --i)

    #define rrep1(i,n) for(ll i = (ll)n; i > 0LL; --i)

    #define rrep2(i,m,n) for(ll i = (ll)m; i > (ll)n; --i)

    #define _GLIBCXX_DEBUG

    #define _CRT_SECURE_NO_WARNINGS

    '
  dependsOn: []
  isVerificationFile: false
  path: Template/template.hpp
  requiredBy:
  - Graph/warshall_floyd.hpp
  - Graph/LCA.hpp
  - Graph/kruskal.hpp
  - Graph/dijkstra.hpp
  - Graph/bfs2.hpp
  - Graph/bfs1.hpp
  - Graph/graph-template.hpp
  - Graph/bellman-ford.hpp
  - Template/short.hpp
  timestamp: '2024-09-24 22:45:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-shortest-path.test.cpp
  - test/yosupo/graph/shortest-path.test.cpp
documentation_of: Template/template.hpp
layout: document
redirect_from:
- /library/Template/template.hpp
- /library/Template/template.hpp.html
title: Template/template.hpp
---
