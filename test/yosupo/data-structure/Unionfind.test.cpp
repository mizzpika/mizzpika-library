#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "Template/template.hpp"
#include "Graph/DSU.hpp"

int main(){
    ll n, q; cin >> n >> q;
    DSU dsu(n);
    while(q--){
        ll t, u, v; cin >> t >> u >> v;
        if(t == 0){
            dsu.merge(u, v);
        }else{
            cout << (dsu.same(u, v) ? 1 : 0) << endl;
        }
    }
}
