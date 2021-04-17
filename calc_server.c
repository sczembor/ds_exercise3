/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Element{
    int type;
    char key[254];
    char value1[254];
    int value2;
    float value3;
    struct Element* pNext;
};

//GLOBALS ----------
struct Element tmp;
struct Element* pHead = NULL;


//FUNCTIONS  DECLARATIONS  -------------
int addNode(char* key, char* value1, int* value2, float* value3);
int modifyNode(char* key, char* value1, int* value2, float* value3);
int deleteList(void);
int searchList(char* _key);
int deleteElement(char* key);
struct Element* getValue(char* key);
int numElements(void);

bool_t
innit_1_svc(int *result, struct svc_req *rqstp)
{
	bool_t retval;

	*result=deleteList();
    
    retval=TRUE;
	return retval;
}

bool_t
set_value_1_svc(char *key, char *val1, int val2, float val3, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

    strcpy(tmp.key,key);
    strcpy(tmp.value1,val1);
    tmp.value2=val2;
    tmp.value3=val3;
    
    if(searchList(&tmp.key)==0)
    {
        *result = addNode(&tmp.key,&tmp.value1,&tmp.value2,&tmp.value3);
    }
    else{
        *result = -1;
    }
    
    retval=TRUE;
	return retval;
}

bool_t
get_value_1_svc(char *key, getval *result,  struct svc_req *rqstp)
{
	bool_t retval;

    strcpy(tmp.key,key);
    if(searchList(&tmp.key)==1){
        result->res=0;
        tmp=*getValue(tmp.key);
        result->val1 = malloc(255*sizeof(char));
        strcpy(result->val1,tmp.value1);
        printf("server side what we copy:%s\n",tmp.value1);
        printf("server side result:%s\n",result->val1);
        result->val2=tmp.value2;
        result->val3=tmp.value3;
        printf("val1:%s\nval2:%d\nval3:%f\n", result->val1,result->val2,result->val3);
    }
    else{
        result->res=-1;
    }
    retval=TRUE;
	return retval;
}

bool_t
modify_value_1_svc(char *key, char *val1, int val2, float val3, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

    strcpy(tmp.key,key);
    strcpy(tmp.value1,val1);
    tmp.value2=val2;
    tmp.value3=val3;
    
    *result = modifyNode(&tmp.key, &tmp.value1,&tmp.value2,&tmp.value3);
    
    retval=TRUE;
	return retval;
}

bool_t
delete_key_1_svc(char *key, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

    strcpy(tmp.key,key);
    *result = deleteElement(&tmp.key);

    retval=TRUE;
	return retval;
}

bool_t
exist_1_svc(char *key, int *result,  struct svc_req *rqstp)
{
	bool_t retval;

    strcpy(tmp.key,key);
    *result=searchList(&tmp.key);

    retval=TRUE;
	return retval;
}

bool_t
num_items_1_svc(int *result, struct svc_req *rqstp)
{
	bool_t retval;

	*result =numElements();

    retval=TRUE;
	return retval;
}

int
com_1_freeresult (SVCXPRT *transp, xdrproc_t xdr_result, caddr_t result)
{
	xdr_free (xdr_result, result);

	/*
	 * Insert additional freeing code here, if needed
	 */

	return 1;
}

int addNode(char* key, char* value1, int* value2, float* value3)
{
    struct Element* new = (struct Element*)malloc(sizeof(struct Element));
    strcpy(new->key,key);
    strcpy(new->value1,value1);
    new->value2 = *value2;
    new->value3 = *value3;
    new->pNext = pHead;
    pHead = new;
    return 0;
}
int deleteList()
{
    struct Element* tmp = NULL;
    while(pHead != NULL){
        tmp = pHead->pNext;
        free(pHead);
        pHead = tmp;
    }
    return 0;
}
int searchList(char* _key)
{
    struct Element* tmp = pHead;
    while(tmp != NULL)
    {
        if(strcmp(_key, tmp->key) == 0)
        return 1;
        tmp = tmp->pNext;
    }
    return 0;//element does not exsist
}
struct Element* getValue(char* key)
{
    struct Element* tmp = pHead;
    while(tmp != NULL)
    {
        if(!strcmp(key, tmp->key))
        return tmp;
        tmp = tmp->pNext;
    }
    return NULL;//element does not exsist
}
int modifyNode(char* key, char* value1, int* value2, float* value3)
{
    struct Element* tmp = pHead;
    while(tmp != NULL)
    {
        if(!strcmp(key, tmp->key))
        {
            strcpy(tmp->value1, value1);
            tmp->value2 = *value2;
            tmp->value3 = *value3;
            return 0;
        }
        tmp = tmp->pNext;
    }
    return -1;//element does not exsist
}
int deleteElement(char* key)
{
    struct Element* prev = NULL;
    struct Element* tmp = pHead;
    while(tmp)
    {
        if(!strcmp(key, tmp->key))
        {
            if(prev!=NULL)
            prev->pNext = tmp->pNext;
            else
            pHead = tmp->pNext;
            free(tmp);
            return 0;
        }
        prev = tmp;
        tmp = tmp->pNext;
    }
    return -1;//element does not exsist
}
int numElements()
{
    int num = 0;
    struct Element* tmp = pHead;
    while(tmp)
    {
        num = num + 1;
        tmp = tmp->pNext;
    }
    return num;
}


