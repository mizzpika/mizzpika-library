#pragma once

#include "Template/template.hpp"

#define lb(a,x) static_cast<ll>(lower_bound(all(a), x) - a.begin())
#define ub(a,x) static_cast<ll>(upper_bound(all(a), x) - a.begin())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SORT(a) sort(all(a));
#define RSORT(a) sort(rall(a));
#define REV(a) reverse(all(a));
#define CEIL(x,y) (x + y - 1) / y
#define pb push_back
#define eb emplace_back
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)
using ld = long double;
using ll = long long;
using ull = unsigned long long;

using vi = vector<int>;
using vl = vector<ll>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;

using vvi = vector<vi>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using vvb = vector<vb>;
using vvs = vector<vs>;


using pii = pair<int, int>;
using pll = pair<ll, ll>;

using si = set<int>;
using sl = set<ll>;

using mii = map<int, int>;
using mll = map<ll, ll>;

//in
void in(){}
template<class T>void in(vector<T> &v){
    for(T &t : v)cin >> t;
}
template<class T>void in(vector<vector<T>> &v){
    for(auto &row : v)for(T&element : row)cin >> element;
}
template<class Head, class... Tail>void in(Head &head, Tail &...tail){
    cin >> head; in(tail...);
}

//out
void out(){}
template<class T>void out(const T &t){
    cout << t << endl;
}
template<class T>void out(vector<T> &v){
    for(T &t : v)cout << t << ' ';
    cout << endl;
}
template<class T>void out(vector<vector<T>> &v){
    for(vector<T> &row : v){
        for(T &element : row){
            cout << element << ' ';
        }
        cout << endl;
    }
}
template<class Head, class...Tail>void out(const Head &head, const Tail &...tail){
    cout << head; out(tail...);
}

//chmax
template<typename T>bool chmax(T &a, T b){
    return((a < b)? (a = b, true) : (false));
}

//chmin
template<typename T>bool chmin(T &a, T b){
    return((a > b)? (a = b, true) : (false));
}

//min
template<typename T>T MIN(vector<T> &v){
    T mn = numeric_limits<T>::max();
    for(T &e : v){
        mn = min(mn, e);
    }
    return mn;
}

//max
template<typename T>T MAX(vector<T> &v){
    T mx = numeric_limits<T>::min();
    for(T &e : v){
        mx = max(mx, e);
    }
    return mx;
}

//sum
template<typename T>T SUM(vector<T> &v){
    T sum = 0;
    for(T &e : v){
        sum += e;
    }
    return sum;
}

//l_sort
template<typename T>void l_sort(vector<T> &l, vector<T> &r){
    assert(l.size() == r.size());
    long long n = l.size();
    vector<pair<T, T>> p;
    for(ll i = 0; i < n; i++){
        p.emplace_back(l[i], r[i]);
    }
    sort(p.begin(), p.end());
    for(ll i = 0; i < n; i++){
        l[i] = p[i].first;
        r[i] = p[i].second;
    }
}

//r_sort
template<typename T>void r_sort(vector<T> &l, vector<T> &r){
    assert(l.size() == r.size());
    long long n = l.size();
    vector<pair<T, T>> p;
    for(ll i = 0; i < n; i++){
        p.emplace_back(r[i], l[i]);
    }
    sort(p.begin(), p.end());
    for(ll i = 0; i < n; i++){
        l[i] = p[i].second;
        r[i] = p[i].first;
    }
}
