#pragma once

#include "../Graph-template.cpp"

//UnionFind
struct UnionFind{
    vector<ll>par, rank, siz;
    UnionFind(ll n):par(n, -1), rank(n, 0), siz(n, 1){}

    //根を求める
    ll leader(ll x){
        if(par[x] == -1){
            return x;
        }else{
            return par[x] = leader(par[x]);
        }
    }

    //連結判定
    bool same(ll x, ll y){
        return leader(x) == leader(y);
    }

    //連結
    bool merge(ll x, ll y){
        ll rx = leader(x), ry = leader(y);
        if(rx == ry){
            return false;
        }
        if(rank[rx] < rank[ry]){
            swap(rx, ry);
        }
        par[ry] = rx;
        if(rank[rx] == rank[ry]){
            rank[rx]++;
        }
        siz[rx] += siz[ry];
        return true;
    }

    //集合の大きさを求める
    ll size(ll x){
        return siz[leader(x)];
    }
};
