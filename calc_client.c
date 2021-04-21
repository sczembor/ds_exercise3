/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calc.h"
#include <stdio.h>
#include <stdlib.h>
#include "keys.h"


void
com_1(char *host)
{
	CLIENT *clnt;
	enum clnt_stat retval_1;
	int result_1;
	enum clnt_stat retval_2;
	int result_2;
	char *set_value_1_key;
	char *set_value_1_val1;
	int set_value_1_val2;
	float set_value_1_val3;
	enum clnt_stat retval_3;
	getval result_3;
	char *get_value_1_key;
	enum clnt_stat retval_4;
	int result_4;
	char *modify_value_1_key;
	char *modify_value_1_val1;
	int modify_value_1_val2;
	float modify_value_1_val3;
	enum clnt_stat retval_5;
	int result_5;
	char *delete_key_1_key;
	enum clnt_stat retval_6;
	int result_6;
	char *exist_1_key;
	enum clnt_stat retval_7;
	int result_7;
    bool_t res;

#ifndef	DEBUG
	clnt = clnt_create (host, COM, COMVER, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
    int msgtype;
    while (1){
        printf("1. init()\n2.set_value()\n3.get_value()\n4.modify_value()\n5.delete_key()\n6.exist()\n7.num_items()\n8.exit()\nChoose one option(ex. \"1\"):");
        scanf("%i", &msgtype);
        switch (msgtype) {
            case 1://init
            result_1 = Innit();
            printf("function returned:%i\n",result_1);
            break;
            case 2://set_value
            printf("key:");
            scanf("%s", &set_value_1_key);
            printf("value1:");
            scanf("%s", &set_value_1_val1);
            printf("value2:");
            scanf("%i", &set_value_1_val2);
            printf("value3:");
            scanf("%f", &set_value_1_val3);
            res = Set_value(set_value_1_key, set_value_1_val1, set_value_1_val2, set_value_1_val3);
            printf("function returned:%i\n",res);
            break;
            case 3://get_value
            printf("key:");
            scanf("%s", &get_value_1_key);
            res = Get_value(set_value_1_key, set_value_1_val1, set_value_1_val2, set_value_1_val3);
            printf("function returned:%i\n",res);
            printf("value1:%s\nvalue2:%d\nvalue3:%f\n",set_value_1_val1,set_value_1_val2,set_value_1_val3);
            break;
            case 4://modify value
            printf("key:");
            scanf("%s", &modify_value_1_key);
            printf("new value1:");
            scanf("%s", &modify_value_1_val1);
            printf("new value2:");
            scanf("%i", &modify_value_1_val2);
            printf("new value3:");
            scanf("%f", &modify_value_1_val3);
            res = Modify_value(modify_value_1_key, modify_value_1_val1, modify_value_1_val2, modify_value_1_val3);
            printf("function returned:%i\n",res);
            break;
            case 5://delete_key
            printf("key:");
            scanf("%s", &delete_key_1_key);
            res = Delete_key(delete_key_1_key);
            printf("function returned:%i\n",res);
            break;
            case 6://exist
            printf("key:");
            scanf("%s", &exist_1_key);
            res = Exist(exist_1_key);
            printf("function returned:%i\n",res);
            break;
            case 7://num_items
            res = Num_items();
            printf("function returned:%i\n",res);
            break;
            default:
            perror ("Client: Invalid Arguemnt(function)");
            #ifndef DEBUG
                clnt_destroy (clnt);
            #endif
            exit (1);
            break;
        }
    }
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	com_1 (host);
exit (0);
}
