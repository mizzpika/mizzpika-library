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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: Graph/dsu.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"Graph/graph-template.hpp\"\n\n#include \"Graph/dsu.hpp\"\
    \n\n//kruskal\nstruct kruskal{\n    long long n;\n    vector<Edge2> edges;\n \
    \   //kruskal\u306E\u69CB\u7BC9\n    kruskal(Graph &g){\n        n = g.size();\n\
    \        for(long long i = 0; i < n; i++){\n            for(auto e : g[i]){\n\
    \                edges.emplace_back(i, e.to, e.cost);\n            }\n       \
    \ }\n    }\n\n    //\u6700\u5C0F\u5168\u57DF\u6728\u306E\u30B3\u30B9\u30C8\u3092\
    \u6C42\u3081\u308B\n    long long mincost(){\n        sort(edges.begin(), edges.end());\n\
    \        dsu uf(n);\n        long long ret = 0;\n        for(auto e : edges){\n\
    \            if(uf.merge(e.from, e.to))ret += e.cost;\n        }\n        return\
    \ ret;\n    }\n\n    //\u6700\u5927\u5168\u57DF\u6728\u306E\u30B3\u30B9\u30C8\u3092\
    \u6C42\u3081\u308B\n    long long maxcost(){\n        sort(edges.rbegin(), edges.rend());\n\
    \        dsu uf(n);\n        long long ret = 0;\n        for(auto e : edges){\n\
    \            if(uf.merge(e.from, e.to))ret += e.cost;\n        }\n        return\
    \ ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/kruskal.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/kruskal.hpp
layout: document
redirect_from:
- /library/Graph/kruskal.hpp
- /library/Graph/kruskal.hpp.html
title: Graph/kruskal.hpp
---
