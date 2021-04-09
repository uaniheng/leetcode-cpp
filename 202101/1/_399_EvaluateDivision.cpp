//
// Created by gyc on 2021/1/6.
//

#include "../../common.h"

class UF {

private:
    int *parent;
    double *weight;


public:
    UF(int n);
    void unionNode(int p, int q, double value);
    double isConnected(int p, int q);
    int findRoot(int p);
};

UF::UF(int n) {
    parent = new int[n];
    weight = new double[n];
    for(int i = 0; i < n; ++i) {
        parent[i] = i;
        weight[i] = 1.0;
    }
}

void UF::unionNode(int p, int q, double value) {
    int rp = findRoot(p);
    int rq = findRoot(q);
    if (rp == rq) return;
    parent[rp] = rq;
    weight[rp] = weight[q] * value / weight[p];
}

double UF::isConnected(int p, int q) {
    int rp = findRoot(p);
    int rq = findRoot(q);
    if (rp == rq) return weight[p] / weight[q];
    return -1;
}

int UF::findRoot(int p) {
//    while (p != parent[p]) {
//        weight[parent[p]] = weight[parent[p]] * weight[parent[parent[p]]];
//        parent[p] = parent[parent[p]];
//        p = parent[p];
//    }
//    return p;
    if (p != parent[p]) {
        int origin = parent[p];
        parent[p] = findRoot(parent[p]);
        weight[p] *= weight[origin];
    }
    return parent[p];
}

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        auto uf = UF(n * 2);
        auto notes = unordered_map<string, int>(2 * n);
        int id = 0;
        for(int i = 0; i < n; ++i) {
            auto e = equations[i];
            if (!notes.count(e[0])){
                notes[e[0]] = id ++;
            }
            if (!notes.count(e[1])) {
                notes[e[1]] = id ++;
            }
            uf.unionNode(notes[e[0]], notes[e[1]], values[i]);
            cout << e[0] << "->" << e[1] << endl;
            cout << values[i] << endl;
            cout << uf.isConnected(notes[e[0]], notes[e[1]]) << endl;
        }
        cout << "a->c" << endl;
        cout << uf.isConnected(notes["a"], notes["c"]) << endl;
        int m = queries.size();
        auto res = vector<double>( m);
        for(int i = 0; i < m; ++i) {
            int x = notes.count(queries[i][0]) ? notes[queries[i][0]] : -1;
            int y = notes.count(queries[i][1]) ? notes[queries[i][1]] : -1;
            if (x == -1 || y == -1) {
                res[i] = -1;
            }else{
                res[i] = uf.isConnected(x, y);
            }
        }
        return res;
    }
};

int main() {
    vector<vector<string>> v1 = {{"a", "b"}, {"b", "c"}};
    vector<double> v2 = {2.0, 3.0};
    vector<vector<string>> v3 = {{"a","c"}, {"b","a"}};

    auto res = Solution().calcEquation(v1, v2, v3);

    for(auto i : res) {
        cout << i << endl;
    }
}