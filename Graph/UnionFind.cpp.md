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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../Graph-template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"../Graph-template.hpp\"\n\n//UnionFind\nstruct\
    \ UnionFind{\n    vector<ll>par, rank, siz;\n    UnionFind(ll n):par(n, -1), rank(n,\
    \ 0), siz(n, 1){}\n\n    //\u6839\u3092\u6C42\u3081\u308B\n    ll leader(ll x){\n\
    \        if(par[x] == -1){\n            return x;\n        }else{\n          \
    \  return par[x] = leader(par[x]);\n        }\n    }\n\n    //\u9023\u7D50\u5224\
    \u5B9A\n    bool same(ll x, ll y){\n        return leader(x) == leader(y);\n \
    \   }\n\n    //\u9023\u7D50\n    bool merge(ll x, ll y){\n        ll rx = leader(x),\
    \ ry = leader(y);\n        if(rx == ry){\n            return false;\n        }\n\
    \        if(rank[rx] < rank[ry]){\n            swap(rx, ry);\n        }\n    \
    \    par[ry] = rx;\n        if(rank[rx] == rank[ry]){\n            rank[rx]++;\n\
    \        }\n        siz[rx] += siz[ry];\n        return true;\n    }\n\n    //\u96C6\
    \u5408\u306E\u5927\u304D\u3055\u3092\u6C42\u3081\u308B\n    ll size(ll x){\n \
    \       return siz[leader(x)];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/UnionFind.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/UnionFind.cpp
layout: document
title: UnionFind
---
ノードの連結を管理します
