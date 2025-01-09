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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../Nyaan's\
    \ library/math/bigint-all.hpp: line -1: no such header\n"
  code: "#pragma once\n#include \"../../Nyaan's library/math/bigint-all.hpp\"\n\n\
    string base_conversion(string n, ull m, ull k) {\n    ull decimalValue = 0;\n\
    \    for (char digit : n) {\n        decimalValue *= m;\n        if ('0' <= digit\
    \ && digit <= '9') {\n            decimalValue += digit - '0';\n        } else\
    \ if ('a' <= digit && digit <= 'z') {\n            decimalValue += digit - 'a'\
    \ + 10;\n        } else if ('A' <= digit && digit <= 'Z') {\n            decimalValue\
    \ += digit - 'A' + 10;\n        }\n    }\n    if (decimalValue == 0) {\n     \
    \   return \"0\";\n    }\n    string result;\n    while (decimalValue > 0) {\n\
    \        ull remainder = decimalValue % k;\n        if (remainder < 10) {\n  \
    \          result.push_back('0' + remainder);\n        } else {\n            result.push_back('a'\
    \ + remainder - 10);\n        }\n        decimalValue /= k;\n    }\n    reverse(result.begin(),\
    \ result.end());\n    return result;\n}\n\nstring base_conversion_bigint(string\
    \ n, bigint m, bigint k) {\n    bigint decimalValue = 0;\n    for (char digit\
    \ : n) {\n        decimalValue *= m;\n        if ('0' <= digit && digit <= '9')\
    \ {\n            decimalValue += digit - '0';\n        } else if ('a' <= digit\
    \ && digit <= 'z') {\n            decimalValue += digit - 'a' + 10;\n        }\
    \ else if ('A' <= digit && digit <= 'Z') {\n            decimalValue += digit\
    \ - 'A' + 10;\n        }\n    }\n    if (decimalValue == 0) {\n        return\
    \ \"0\";\n    }\n    string result;\n    while (decimalValue > 0) {\n        bigint\
    \ remainder = decimalValue % k;\n        if (remainder < 10) {\n            result.push_back('0'\
    \ + stoll(remainder.to_string()));\n        } else {\n            result.push_back('a'\
    \ + stoll(remainder.to_string()) - 10);\n        }\n        decimalValue /= k;\n\
    \    }\n    reverse(result.begin(), result.end());\n    return result;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/base_conversion.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/base_conversion.hpp
layout: document
redirect_from:
- /library/math/base_conversion.hpp
- /library/math/base_conversion.hpp.html
title: math/base_conversion.hpp
---
