---
title: dijkstra
documentation_of: ../Graph/dijkstra.hpp
---
負辺なし単一始点最短経路問題を解く

計算量:

* 構築:`O(|E|log|V|)`

* 最短経路:`O(N)`

* その他:`O(1)`

## 概要

* `dijkstra(Graph g, long long s)`で`g`においての`s`からの各頂点への最短経路を構築する

* `cost(long long to)`で`s`から`to`への最短距離を返す

* `path(long long to)`で`s`から`to`への最短経路をで返す

* `cango(long long to)`で`s`から`to`への経路が存在するかを返す
