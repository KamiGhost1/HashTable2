#include "head.h"

void work(){
    TRoute routeTable[] ={
        {"add",addItem},
        {"search",searchItem},
        {"show",printTable},
        {"help",helpMenu}
    };
    _Bool find;
    char cmd[CMD_LEN];
    int valve = NULL;
    int i;
    hashTable *table;
    table = createTable();
    printf("Start of work!\n");
    while(1){
        printf(">>");
        find = 0;
        scanf("%s",cmd);
        for(i=0;i<sizeof(routeTable)/sizeof(TRoute);i++){
            if (!strcmp(routeTable[i].cmd,cmd)){
                find =1;
                routeTable[i].func(table);
                break;
            }
        }
        if (find)
            continue; 
        if (!strcmp(cmd,"exit"))
            break;
        if (!find){
            printf("unknown command '%s'...\n",cmd);
            printf("use (help)!\n");
        }
    }
    printf("end of work! bye! =)\n");
}