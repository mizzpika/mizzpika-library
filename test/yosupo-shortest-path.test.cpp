#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "bits/stdc++.h"
#include "Graph/dijkstra"
using namespace std;
int main(){
    int n, m, s, t; cin >> n >> m >> s >> t;
    s--, t--;
    Graph g(n);
    rep(i,m){
        ll a, b, c; cin >> a >> b >> c; a--, b--;
        g.add_di(a, b, c);
    }
    dijkstra ds(g, s);
    if(!ds.cango(t)){
        cout << -1;
        return 0;
    }
    auto res = ds.path(t);
    for(auto e : res){
        cout << e << ' ';
    }
}
