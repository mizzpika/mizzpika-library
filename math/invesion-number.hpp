#pragma once
#include "../../data-structure/binary-indexed-tree.hpp"
#include <vector>
#include <algorithm>
using namespace std;

int inversion_number(vector<long long> &a){
    int n = a.size();
    long long res = 0;
    vector<long long> b = a;
    sort(b.begin(), b.end());
    for (long long &x : a) {
        x = lower_bound(b.begin(), b.end(), x) - b.begin();
    }
    BinaryIndexedTree<int> ft(n);
    for(int i = 0; i < n; i++){
        ft.add(a[i], 1);
        res += ft.sum(a[i] + 1, n);
    }
    return res;
}
