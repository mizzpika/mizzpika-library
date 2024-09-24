---
title: DSU
documentation_of: ../Graph/DSU.hpp
---
ノードの連結を管理する

計算量:

* 全て`O(1)`（連結は厳密には異なる）

## 概要

* `DSU dsu(n)`で頂点数`n`のDSUを初期化する

* `dsu.merge(long long from, long long to)`で`from`と`to`を連結します。また、既に連結していれば`false`、初めて連結すれば`true`を返す

* `dsu.same(long long from, long long to)`で`from`と`to`が同一集合にいるかを返す

* `dsu.leader(long long u)`で`u`が属している集合の親（`u`∈`s`かつ`v`∈`s`ならば`leader(u)`=`leader(v)`）を返す

* `dsu.size(long long u)`で`u`が属している集合の要素数を返す
