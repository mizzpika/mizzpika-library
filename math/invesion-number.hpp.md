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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../data-structure/binary-indexed-tree.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../../data-structure/binary-indexed-tree.hpp\"\n\
    #include <vector>\n#include <algorithm>\nusing namespace std;\n\nint inversion_number(vector<long\
    \ long> &a){\n    int n = a.size();\n    long long res = 0;\n    vector<long long>\
    \ b = a;\n    sort(b.begin(), b.end());\n    for (long long &x : a) {\n      \
    \  x = lower_bound(b.begin(), b.end(), x) - b.begin();\n    }\n    BinaryIndexedTree<int>\
    \ ft(n);\n    for(int i = 0; i < n; i++){\n        ft.add(a[i], 1);\n        res\
    \ += ft.sum(a[i] + 1, n);\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/invesion-number.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/invesion-number.hpp
layout: document
redirect_from:
- /library/math/invesion-number.hpp
- /library/math/invesion-number.hpp.html
title: math/invesion-number.hpp
---
