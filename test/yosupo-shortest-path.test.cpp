#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "bits/stdc++.h"
#include "Graph/dijkstra.hpp"
using namespace std;
int main(){
    int n, m, s, t; cin >> n >> m >> s >> t;
    Graph g(n);
    rep(i,m){
        ll a, b, c; cin >> a >> b >> c;
        g.add_di(a, b, c);
    }
    dijkstra ds(g, s);
    if(!ds.cango(t)){
        cout << -1;
        return 0;
    }
    auto res = ds.path(t);
    cout << ds.cost(t) << ' ' << res.size() - 1 << endl;
    rep(i,res.size() - 1){
        cout << res[i] << ' ' << res[i + 1] << endl;
    }
}
