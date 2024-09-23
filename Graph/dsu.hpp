//dsu
struct dsu{
    vector<long long> par, rank, siz;
    dsu(long long n):par(n, -1), rank(n, 0), siz(n, 1){}

    //根を求める
    long long leader(long long x){
        if(par[x] == -1){
            return x;
        }else{
            return par[x] = leader(par[x]);
        }
    }

    //連結判定
    bool same(long long x, long long y){
        return leader(x) == leader(y);
    }

    //連結
    bool merge(long long x, long long y){
        long long rx = leader(x), ry = leader(y);
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
    long long size(long long x){
        return siz[leader(x)];
    }
};
