#include "head.h"

hashTable *createTable(){
    hashTable *table;
    int i = 0;
    table = (hashTable*)malloc(sizeof(hashTable)*HASH_SIZE);
    for (i; i<HASH_SIZE;i++){
        table[i];
        createChain(table);
    }
    return table;
}

hashTable *createChain(hashTable *table){
    table=(hashTable*)malloc(sizeof(hashTable));
    table->key = NULL;
    table->next = NULL;
    table->valve = NULL;
    return table;
}


void addItem(hashTable *table, char *key){
    _Bool matches =0;
    char *s1;
    int valve;
    printf("enter valve and key: ");
    scanf("%d %s", &valve, key);
    s1 = (char*)malloc(sizeof(char)*strlen(key));
    memcpy(s1,key,sizeof(char)*strlen(key));
    table+=hashFunc(key);
    if (table->key == NULL){
        table->key = s1;
        table->valve = valve;
        table->next = createChain(table->next);
    }
    else if(table->key != NULL){
        while (table->next != NULL){
            if (table->valve == valve && table->key==key)
                matches=1;
            table=table->next;
        }
        if (!matches){
            if (table->key != NULL){
                table->next=createChain(table->next);
                table = table->next;
            }
            table->key = s1;
            table->valve = (int)valve;
            table->next = createChain(table->next);
        }
    }
    s1=NULL;
    free(s1);
}

void printTable(hashTable *table){
    int i=0;
    hashTable *ptr;
    for (i;i<HASH_SIZE;i++){
        printf("%d:\n",i);
        if (table->key!=NULL){
            ptr = table;
            while (ptr->next!=NULL){
                printf("key: %s ; valve: %d\n", ptr->key , ptr->valve);
                ptr = ptr->next;
            }
        }
        table++;
    }
}

hashTable *searchItem(hashTable *table){
    _Bool matches = 0;
    char key[20];
    printf("enter key: ");
    scanf("%s",key);
    table+=hashFunc(key);
    if (key!=NULL){
        while(table->next !=NULL){
            if (!strcmp(key,table->key)){
                matches = 1;
                printf("\nfound!\nkey: %s ; valve: %d\n",table->key,table->valve);
            }
            table=table->next;
        }
        if (!matches)
            printf("\n%s not found!\n");
    }
}

int hashFunc(char *key){
    int i = 0;
    int Sum, len;
    Sum = 0;
    len = strlen(key);
    for (i; i<len;i++)
        Sum += (int)(key[i]);
    Sum%=HASH_SIZE;
    return Sum;
}

/*
void ClnMover(hashTable *table){
    if (table->key==NULL)
        return NULL;
    if(table->next!=NULL)
        ClnMover(table->next);
    table->key = NULL;
    table->valve = NULL;
    table->next=NULL;
    free(table);
}

void clnTable(hashTable *table){
    int i =0;
    for (i;i<HASH_SIZE;i++){
        ClnMover(table);
        table++;
    }
}*/ 

void helpMenu(){
     printf("\tSTART WORK:\n -start\n\tEND WORK:\nexit()\n");
     printf("\tOPTIONS:\n-add - add new item\n-s - search item in table\n");
}
