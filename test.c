//
// Created by gyc on 2021/4/22.
//

#include "common_c.h"

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

int main() {

    add_entry("a", 101);

    hash_entry *entry = find_entry("a");
    printf("%d", entry->value);
}
