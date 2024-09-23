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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../graph-template.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"../graph-template.cpp\"\n\n//dijkstra\nstruct\
    \ dijkstra{\n    vector<ll> dist;\n    vector<ll> prev;\n\n    //dijkstra\u3092\
    \u69CB\u7BC9\n    dijkstra(Graph &G, ll s){\n        ll N = G.size();\n      \
    \  dist.assign(N, 1LL << 60);\n        prev.assign(N, -1);\n        priority_queue<pair<ll,\
    \ ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;\n        dist[s] = 0;\n\
    \        pq.emplace(dist[s], s);\n        while (!pq.empty()){\n            auto\
    \ p = pq.top();\n            pq.pop();\n            ll v = p.second;\n       \
    \     if(dist[v] < p.first)continue;\n            for (auto &e : G[v]){\n    \
    \            if (dist[e.to] > dist[v] + e.cost){\n                    dist[e.to]\
    \ = dist[v] + e.cost;\n                    prev[e.to] = v;\n                 \
    \   pq.emplace(dist[e.to], e.to);\n                }\n            }\n        }\n\
    \    }\n\n    //\u6700\u5C0F\u30B3\u30B9\u30C8\u3092\u6C42\u3081\u308B\n    ll\
    \ cost(ll to){\n        return dist[to];\n    }\n\n    //\u6700\u77ED\u7D4C\u8DEF\
    \u3092\u6C42\u3081\u308B\n    vector<ll> path(ll to){\n        vector<ll> get_path;\n\
    \        for (ll i = to; i != -1; i = prev[i]){\n            get_path.push_back(i);\n\
    \        }\n        reverse(get_path.begin(), get_path.end());\n        return\
    \ get_path;\n    }\n\n    //\u5230\u9054\u53EF\u80FD\u304B\u8ABF\u3079\u308B\n\
    \    bool cango(ll to){\n        return dist[to] != 1LL << 60;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/dijkstra.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/dijkstra.cpp
layout: document
title: dijkstra
---
負辺なし単一始点最短経路問題を解きます

## 概要

* `dijkstra(Graph g, long long s)`で`g`においての`s`からの各頂点への最短経路を構築する。

* `cost(long long to)`で`s`から`to`への最短距離を返す

* `path(long long to)`で`s`から`to`への最短経路をで返す

* `cango(long long to)`で`s`から`to`への経路が存在するかを返す
