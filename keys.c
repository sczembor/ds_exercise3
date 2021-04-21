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
    
    res = innit_1(&result,clnt);
    if (res != RPC_SUCCESS) {
        clnt_perror(clnt, "call failed\n");
    }
    printf("function returned:%i\n",result);
    
    
    
    
    clnt_destroy (clnt);
}

int set_value(char *key, char *value1, int value2, float value3) {
    CLIENT *clnt;
    int result;
    clnt = clnt_create (host, COM, COMVER, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror (host);
        exit (1);
    }
    
    res = set_value_1(key, value1, value2, value3, &result, clnt);
    if (res != RPC_SUCCESS) {
        clnt_perror(clnt, "call failed\n");
    }
    printf("function returned:%i\n",result_2);
    
    
    clnt_destroy (clnt);
}

int get_value(char *key, char *value1, int value2, float value3) {
    CLIENT *clnt;
    getval result;
    clnt = clnt_create (host, COM, COMVER, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror (host);
        exit (1);
    }
    res = get_value_1(key, value1,&result, clnt);
    if (res != RPC_SUCCESS) {
        clnt_perror(clnt, "call failed\n");
    }
    
    printf("function returned:%i\n",result.res);
    printf("value1:%s\nvalue2:%d\nvalue3:%f\n",result.val1,result.val2,result.val3);
    
    
    clnt_destroy (clnt);
    
}

int modify_value(char *key, char *value1, int value2, float value3) {
    CLIENT *clnt;
    int result;
    clnt = clnt_create (host, COM, COMVER, "udp");
    if (clnt == NULL) {
        clnt_pcreateerror (host);
        exit (1);
    }
    
    res = modify_value_1(key, value1, value2, value3, &result, clnt);
    if (res != RPC_SUCCESS) {
        clnt_perror(clnt, "call failed\n");
    }
    printf("function returned:%i\n",result_2);
    
    
    clnt_destroy (clnt);
}
