//
// Created by gyc on 2021/4/21.
//
#include "../../common_c.h"

typedef struct hash_entry {
    char *key;
    int value;
    UT_hash_handle hh;
} hash_entry;

hash_entry *head = NULL;

hash_entry *find_entry(char *key) {
    hash_entry *s = NULL;
    HASH_FIND_STR(head, key, s);
    return s;
}

void add_entry(char *key, int value) {
    hash_entry *s = find_entry(key);
    if (s == NULL) {
        s = (struct hash_entry *) malloc(sizeof(hash_entry));
        s->key = key;
        HASH_ADD_STR(head, key, s);
    }
    s->value = value;
//    strcpy(s->value, value);
}

typedef struct {
    int m;
    int *parent;
    double *weight;
} UF;

void initUF(UF *uf, int n) {
    int parent[n];
    double weight[n];
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        weight[i] = 1.0;
    }
    uf->parent = parent;
    uf->weight = weight;
    uf->m = 101;
}

int findRoot(UF *uf, int x) {
    if (uf->parent[x] != x) {
        int original = uf->parent[x];
        uf->parent[x] = findRoot(uf, original);
        uf->weight[x] *= uf->weight[original];
    }
    return uf->parent[x];
}

void unionUF(UF *uf, int x, int y, double value) {
    int rx = findRoot(uf, x);
    int ry = findRoot(uf, y);
    if (rx == ry) return;
    uf->parent[rx] = ry;
    uf->weight[rx] = value * uf->weight[y] / uf->weight[x];
}

double isConnected(UF *uf, int x, int y) {
    int rx = findRoot(uf, x);
    int ry = findRoot(uf, y);
    if (rx == ry) {
        return uf->weight[x] / uf->weight[y];
    }
    return -1;
}

double* calcEquation(char *** equations, int equationsSize, int* equationsColSize, double* values, int valuesSize,
                     char *** queries, int queriesSize, int* queriesColSize, int* returnSize){
    UF uf;
    initUF(&uf, equationsSize * 2);
    int id = 0;
    for(int i = 0; i < equationsSize; ++i) {
        char **arr = equations[i];
        char *left = arr[0];
        char *right = arr[1];
        if (!find_entry(left)) {
            add_entry(left, id ++);
        }
        if (!find_entry(right)) {
            add_entry(right, id ++);
        }
        unionUF(&uf, find_entry(left)->value, find_entry(left)->value, values[i]);
    }
    double *result = (double *) malloc(equationsSize * sizeof(double));
    *returnSize = queriesSize;
    for(int i = 0; i < queriesSize; ++i) {
        hash_entry *x = find_entry(queries[i][0]);
        hash_entry *y = find_entry(queries[i][1]);
        if (x && y) {
            result[i] = isConnected(&uf, x->value, y->value);
        }else {
            result[i] = -1;
        }
    }
    return result;
}


int main() {
    UF uf;
    initUF(&uf, 100);
    // 太麻烦了 不写了
}


