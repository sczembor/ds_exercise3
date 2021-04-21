//
//  keys.c
//  
//
//  Created by Jan Ferbr on 21/04/2021.
//

#include "keys.h"
#include "calc.h"
#include <stdlib.h>
#define host "localhost"

int Innit() {
    CLIENT *clnt;
    clnt = clnt_create (host, COM, COMVER, "udp");
    int result;
    int res;
    if (clnt == NULL) {
        clnt_pcreateerror (host);
        exit (1);
    }
    
    res = innit_1(&result,clnt);
    if (res != RPC_SUCCESS) {
        clnt_perror(clnt, "call failed\n");
    }
    //printf("function returned:%i\n",result);
    
    
    clnt_destroy (clnt);
    return result;
}

int Set_value(char *key, char *value1, int value2, float value3) {
    CLIENT *clnt;
    int result;
    int res;
    clnt = clnt_create (host, COM, COMVER, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror (host);
        exit (1);
    }
    
    res = set_value_1(&key, &value1, value2, value3, &result, clnt);
    if (res != RPC_SUCCESS) {
        clnt_perror(clnt, "call failed\n");
    }
    //printf("function returned:%i\n",result_2);
    
    
    clnt_destroy (clnt);
    return result;
}

int Get_value(char *key, char *value1, int value2, float value3) {
    CLIENT *clnt;
    getval result;
    int res;
    clnt = clnt_create (host, COM, COMVER, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror (host);
        exit (1);
    }
    res = get_value_1(&key,&result, clnt);
    printf("problems incomin: %s\n",result.val1);
    if (res != RPC_SUCCESS) {
        clnt_perror(clnt, "call failed\n");
    }
    //value1=malloc(255*sizeof(char));
    //printf("address in memory %p\n", &value1);
    strcpy(value1,result.val1);
    //printf("value1 is:%s\n",value1);
    value2=result.val2;
    //printf("value2 is:%i\n",value2);
    value3=result.val3;
    //printf("value3 is:%f\n",value3);
    //printf("function returned:%i\n",result.res);
    //printf("value1:%s\nvalue2:%d\nvalue3:%f\n",result.val1,result.val2,result.val3);
    
    
    clnt_destroy (clnt);
    return result.res;
    
}

int Modify_value(char *key, char *value1, int value2, float value3) {
    CLIENT *clnt;
    int result;
    int res;
    clnt = clnt_create (host, COM, COMVER, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror (host);
        exit (1);
    }
    
    res = modify_value_1(&key, &value1, value2, value3, &result, clnt);
    if (res != RPC_SUCCESS) {
        clnt_perror(clnt, "call failed\n");
    }
    //printf("function returned:%i\n",result_2);
    
    
    clnt_destroy (clnt);
    return result;
}

int Delete_key(char* key){
    CLIENT *clnt;
    int result;
    int res;
    clnt = clnt_create (host, COM, COMVER, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror (host);
        exit (1);
    }
    res =delete_key_1(&key,&result,clnt);
    if (res != RPC_SUCCESS) {
        clnt_perror(clnt, "call failed\n");
    }
    clnt_destroy (clnt);
    return result;
}

int Exist(char* key){
    CLIENT *clnt;
    int result;
    int res;
    clnt = clnt_create (host, COM, COMVER, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror (host);
        exit (1);
    }
    res =exist_1(&key,&result,clnt);
    if (res != RPC_SUCCESS) {
        clnt_perror(clnt, "call failed\n");
    }
    clnt_destroy (clnt);
    return result;
}
int Num_items(){
    CLIENT *clnt;
    int result;
    int res;
    clnt = clnt_create (host, COM, COMVER, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror (host);
        exit (1);
    }
    res = num_items_1(&result,clnt);
    if (res != RPC_SUCCESS) {
        clnt_perror(clnt, "call failed\n");
    }
    clnt_destroy (clnt);
    return result;
}
