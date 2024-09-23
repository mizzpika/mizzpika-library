---
title: graph-template
documentation_of: ../Graph/graph-template.hpp
---
`Graph`ライブラリを使う際のテンプレート

## 概要（ここではGraphについて）

* `Graph g(n)`で頂点数`n`のグラフを初期化する

* `void add(long long from, long long to, long long cost = 1)`で`from`と`to`に相互に重さ`cost`の辺を張る。重さを指定していない場合は`1`となる。

* `void add_di(long long from, long long to, long long cost = 1)`で`from`から`to`に重さ`cost`の辺を張る。重さを指定していない場合は`1`となる。

* `long long size()`で`g`の頂点数を返す

* `&operator[](long long u)`で`u`から辺が張られている頂点集合`v`の情報を返す
