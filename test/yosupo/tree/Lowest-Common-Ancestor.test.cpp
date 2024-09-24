#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "Template/template.hpp"
#include "Graph/LCA"

int main(){
    ll n, q; cin >> n >> q;
    Graph g(n);
    rep(i,n - 1){
        ll p; cin >> p;
        g.add_di(p, i + 1);
    }
    LCA lca(g);
    while(q--){
        ll u, v; cin >> u >> v;
        cout << lca.query(u, v) << endl;
    }
}
