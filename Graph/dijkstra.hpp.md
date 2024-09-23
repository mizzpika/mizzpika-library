---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Graph/dijkstra.hpp\"\n//dijkstra\n//dijkstra\nstruct dijkstra{\n\
    \    vector<ll> dist;\n    vector<ll> prev;\n\n    //dijkstra\u3092\u69CB\u7BC9\
    \n    dijkstra(Graph &G, ll s){\n        ll N = G.size();\n        dist.assign(N,\
    \ 1LL << 60);\n        prev.assign(N, -1);\n        priority_queue<pair<ll, ll>,\
    \ vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;\n        dist[s] = 0;\n   \
    \     pq.emplace(dist[s], s);\n        while (!pq.empty()){\n            auto\
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
  code: "//dijkstra\n//dijkstra\nstruct dijkstra{\n    vector<ll> dist;\n    vector<ll>\
    \ prev;\n\n    //dijkstra\u3092\u69CB\u7BC9\n    dijkstra(Graph &G, ll s){\n \
    \       ll N = G.size();\n        dist.assign(N, 1LL << 60);\n        prev.assign(N,\
    \ -1);\n        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll,\
    \ ll>>> pq;\n        dist[s] = 0;\n        pq.emplace(dist[s], s);\n        while\
    \ (!pq.empty()){\n            auto p = pq.top();\n            pq.pop();\n    \
    \        ll v = p.second;\n            if(dist[v] < p.first)continue;\n      \
    \      for (auto &e : G[v]){\n                if (dist[e.to] > dist[v] + e.cost){\n\
    \                    dist[e.to] = dist[v] + e.cost;\n                    prev[e.to]\
    \ = v;\n                    pq.emplace(dist[e.to], e.to);\n                }\n\
    \            }\n        }\n    }\n\n    //\u6700\u5C0F\u30B3\u30B9\u30C8\u3092\
    \u6C42\u3081\u308B\n    ll cost(ll to){\n        return dist[to];\n    }\n\n \
    \   //\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\u308B\n    vector<ll> path(ll\
    \ to){\n        vector<ll> get_path;\n        for (ll i = to; i != -1; i = prev[i]){\n\
    \            get_path.push_back(i);\n        }\n        reverse(get_path.begin(),\
    \ get_path.end());\n        return get_path;\n    }\n\n    //\u5230\u9054\u53EF\
    \u80FD\u304B\u8ABF\u3079\u308B\n    bool cango(ll to){\n        return dist[to]\
    \ != 1LL << 60;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2024-09-23 11:30:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/dijkstra.hpp
layout: document
redirect_from:
- /library/Graph/dijkstra.hpp
- /library/Graph/dijkstra.hpp.html
title: Graph/dijkstra.hpp
---
