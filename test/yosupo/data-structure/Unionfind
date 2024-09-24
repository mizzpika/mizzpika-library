#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "Template/template.hpp"
#include "Graph/DSU.hpp"

int main(){
    ll n, q; cin >> n >> q;
    DSU dsu(n);
    rep(i,q){
        ll t, u, v; cin >> t >> u >> v;
        if(t == 1){
            dsu.merge(u, v);
        }else{
            cout << (dsu.same(u, v) ? 1 : 0) << endl;
        }
    }
}
