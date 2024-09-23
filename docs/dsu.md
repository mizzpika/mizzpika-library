---
title: dsu
documentation_of: ../Graph/dsu.hpp
---
ノードの連結を管理する

## 概要

* `dsu uf(n)`で頂点数`n`のdsuを初期化する

* `uf.merge(long long from, long long to)`で`from`と`to`を連結します。また、既に連結していれば`false`、初めて連結すれば`true`を返す

* `uf.same(long long from, long long to)`で`from`と`to`が同一集合にいるかを返す

* `uf.leader(long long u)`で`u`が属している集合の親（`u`∈`s`かつ`v`∈`s`ならば`leader(u)`=`leader(v)`）を返す

* `uf.size(long long u)`で`u`が属している集合の要素数を返す
