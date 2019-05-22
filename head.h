#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_SIZE 20
#define CMD_LEN 10
#define CMD_SIZE 3
#define HASH_SIZE 3



typedef struct {
    char *key;
    int valve;
    struct hashTable *next;
} hashTable;

typedef struct {
    char cmd[10];
    void (*func) ();
}TRoute;

hashTable *createTable();
hashTable *createChain(hashTable *table);
hashTable *searchItem(hashTable *table);
int hashFunc(char *key);
void addItem(hashTable *table, char *key);
void clnTable(hashTable *table);
void ClnMover(hashTable *table);
void printTable(hashTable *table);
void helpMenu();
void work();