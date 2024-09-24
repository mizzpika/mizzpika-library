---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Template/short.hpp
    title: Template/short.hpp
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bits/stdc++.h:\
    \ line -1: no such header\n"
  code: '#include "bits/stdc++.h"

    #pragma GCC optimize("Ofast,unroll-loops")

    #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

    using namespace std;

    using ll = long long;

    #define rep(i,n) for(ll i = 0LL; i < (ll)n; ++i)

    #define rep1(i,n) for(ll i = 1LL; i <= (ll)n; ++i)

    #define rep2(i,m,n) for(ll i = (ll)m; i < (ll)n; ++i)

    #define rrep(i,n) for(ll i = (ll)n - 1; i >= 0LL; --i)

    #define rrep1(i,n) for(ll i = (ll)n; i > 0LL; --i)

    #define rrep2(i,m,n) for(ll i = (ll)m; i > (ll)n; --i)

    #define _GLIBCXX_DEBUG

    #define _CRT_SECURE_NO_WARNINGS

    '
  dependsOn: []
  isVerificationFile: false
  path: Template/template.hpp
  requiredBy:
  - Template/short.hpp
  timestamp: '2024-09-24 21:02:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Template/template.hpp
layout: document
redirect_from:
- /library/Template/template.hpp
- /library/Template/template.hpp.html
title: Template/template.hpp
---
