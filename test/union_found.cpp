//
// Created by gyc on 2021/4/8.
//
#include "../common.h"

class UF {

private:
    int count;
    int *parent;


public:
    UF(int n);
    void unionNode(int p ,int q);
    bool isConnected(int p, int q);
    int getCount();
    int findRoot(int p);
};

UF::UF(int n) {
    this->count = n;
    parent = new int[n];
    for(int i = 0; i < n; ++i) {
        parent[i] = i;
    }
}

void UF::unionNode(int p, int q) {
    int rp = findRoot(p);
    int rq = findRoot(q);
    if (rp == rq) return;
    parent[rp] = rq;

}

bool UF::isConnected(int p, int q) {
    int rp = findRoot(p);
    int rq = findRoot(q);
    return rp == rq;
}

int UF::getCount() {
    return count;
}

int UF::findRoot(int p) {
    while (p != parent[p]) {
        parent[p] = parent[parent[p]];
        p = parent[p];
    }
    return p;
}

int main() {
    auto uf = UF(100);

    uf.unionNode(1,2);
    uf.unionNode(2,3);
    uf.unionNode(3, 4);

    uf.unionNode(51,52);
    uf.unionNode(52,53);
    uf.unionNode(53, 54);

    uf.unionNode(1, 54);

    cout << uf.isConnected(53, 3) << endl;
    cout << uf.isConnected(2, 40) << endl;

}
