---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: Template/template.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ \"Template/template.cpp\"\n#include \"Graph/dijkstra.hpp\"\nusing namespace\
    \ std;\nint main(){\n    int n, m, s, t; cin >> n >> m >> s >> t;\n    Graph g(n);\n\
    \    rep(i,m){\n        ll a, b, c; cin >> a >> b >> c;\n        g.add_di(a, b,\
    \ c);\n    }\n    dijkstra ds(g, s);\n    if(!ds.cango(t)){\n        cout << -1;\n\
    \        return 0;\n    }\n    auto res = ds.path(t);\n    cout << ds.cost(t)\
    \ << ' ' << res.size() - 1 << endl;\n    rep(i,res.size() - 1){\n        cout\
    \ << res[i] << ' ' << res[i + 1] << endl;\n    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo-shortest-path.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-shortest-path.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-shortest-path.test.cpp
- /verify/test/yosupo-shortest-path.test.cpp.html
title: test/yosupo-shortest-path.test.cpp
---
