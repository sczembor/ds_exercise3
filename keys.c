//
//  keys.c
//  
//
//  Created by Jan Ferbr on 21/04/2021.
//

#include "keys.h"
#include "calc.h"

#define host "localhost"

int init() {
    CLIENT *clnt;
    clnt = clnt_create (host, COM, COMVER, "udp");
    int result;
    if (clnt == NULL) {
        clnt_pcreateerror (host);
        exit (1);
    }
    
    result = innit_1(&result,clnt);
    if (result != RPC_SUCCESS) {
        clnt_perror(clnt, "call failed\n");
    }
    //printf("function returned:%i\n",result);
    
    
    clnt_destroy (clnt);
    return result;
}

int set_value(char *key, char *value1, int value2, float value3) {
    CLIENT *clnt;
    int result;
    clnt = clnt_create (host, COM, COMVER, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror (host);
        exit (1);
    }
    
    result = set_value_1(key, value1, value2, value3, &result, clnt);
    if (result != RPC_SUCCESS) {
        clnt_perror(clnt, "call failed\n");
    }
    //printf("function returned:%i\n",result_2);
    
    
    clnt_destroy (clnt);
    return result;
}

int get_value(char *key, char *value1, int value2, float value3) {
    CLIENT *clnt;
    getval result;
    clnt = clnt_create (host, COM, COMVER, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror (host);
        exit (1);
    }
    result = get_value_1(key, value1,&result, clnt);
    if (result != RPC_SUCCESS) {
        clnt_perror(clnt, "call failed\n");
    }
    value1=result.val1;
    value2=result.val2;
    values3=result.val3;
    //printf("function returned:%i\n",result.res);
    //printf("value1:%s\nvalue2:%d\nvalue3:%f\n",result.val1,result.val2,result.val3);
    
    
    clnt_destroy (clnt);
    return result;
    
}

int modify_value(char *key, char *value1, int value2, float value3) {
    CLIENT *clnt;
    int result;
    clnt = clnt_create (host, COM, COMVER, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror (host);
        exit (1);
    }
    
    result = modify_value_1(key, value1, value2, value3, &result, clnt);
    if (result != RPC_SUCCESS) {
        clnt_perror(clnt, "call failed\n");
    }
    //printf("function returned:%i\n",result_2);
    
    
    clnt_destroy (clnt);
    return result;
}

int delete_key(char* key){
    CLIENT *clnt;
    int result;
    clnt = clnt_create (host, COM, COMVER, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror (host);
        exit (1);
    }
    result =delete_key_1(key,&result,clnt);
    if (result != RPC_SUCCESS) {
        clnt_perror(clnt, "call failed\n");
    }
    clnt_destroy (clnt);
    return result;
}

int exist(char* key){
    CLIENT *clnt;
    int result;
    clnt = clnt_create (host, COM, COMVER, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror (host);
        exit (1);
    }
    result =exist_1(key,&result,clnt);
    if (result != RPC_SUCCESS) {
        clnt_perror(clnt, "call failed\n");
    }
    clnt_destroy (clnt);
    return result;
}
int exist(){
    CLIENT *clnt;
    int result;
    clnt = clnt_create (host, COM, COMVER, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror (host);
        exit (1);
    }
    result =num_items_1(&result,clnt);
    if (result != RPC_SUCCESS) {
        clnt_perror(clnt, "call failed\n");
    }
    clnt_destroy (clnt);
    return result;
}
