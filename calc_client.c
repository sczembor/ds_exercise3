/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calc.h"


void
com_1(host)
char *host;
{
	CLIENT *clnt;
	int  *result_1;
	int  *result_2;
	char * set_value_1_key;
	char * set_value_1_val1;
	int  set_value_1_val2;
	float  set_value_1_val3;
	getval  *result_3;
	char * get_value_1_key;
	int  *result_4;
	char * modify_value_1_key;
	char * modify_value_1_val1;
	int  modify_value_1_val2;
	float  modify_value_1_val3;
	int  *result_5;
	char * delete_key_1_key;
	int  *result_6;
	char * exist_1_key;
	int  *result_7;
	clnt = clnt_create(host, COM, COMVER, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror(host);
		exit(1);
	}
    while (1){
        printf("1. init()\n2.set_value()\n3.get_value()\n4.modify_value()\n5.delete_key()\n6.exist()\n7.num_items()\n8.exit()\nChoose one option(ex. \"1\"):");
        scanf("%i", &msgtype);
        switch (mes1.type) {
            case 1://init
            result_1 = innit_1(clnt);
            if (result_1 == NULL) {
                clnt_perror(clnt, "call failed:");
            }
            printf("function returned:%i\n",result_1);
            break;
            case 2://set_value
            scanf("%s", &set_value_1_key);
            scanf("%s", &set_value_1_val1);
            scanf("%i", &set_value_1_val2);
            scanf("%f", &set_value_1_val3);
            result_2 = set_value_1(set_value_1_key, set_value_1_val1, set_value_1_val2, set_value_1_val3, clnt);
            if (result_2 == NULL) {
                clnt_perror(clnt, "call failed:");
            }
            printf("function returned:%i\n",result_2);
            break;
            case 3://get_value
            scanf("%s", &get_value_1_key);
            result_3 = get_value_1(get_value_1_key, clnt);
            if (result_3 == NULL) {
                clnt_perror(clnt, "call failed:")
            }
            printf("function returned:%i\n",result_3.res);
            break;
            case 4://modify value
            scanf("%s", &modify_value_1_key);
            scanf("%s", &modify_value_1_val1);
            scanf("%i", &modify_value_1_val2);
            scanf("%f", &modify_value_1_val3);
            result_4 = modify_value_1(modify_value_1_key, modify_value_1_val1, modify_value_1_val2, modify_value_1_val3, clnt);
            if (result_4 == NULL) {
                clnt_perror(clnt, "call failed:");
            }
            printf("function returned:%i\n",result_4);
            break;
            case 5://delete_key
            scanf("%s", &delete_key_1_key);
            result_5 = delete_key_1(delete_key_1_key, clnt);
            if (result_5 == NULL) {
                clnt_perror(clnt, "call failed:");
            }
            printf("function returned:%i\n",result_5);
            break;
            case 6://exist
            scanf("%s", &exist_1_key);
            result_6 = exist_1(exist_1_key, clnt);
            if (result_6 == NULL) {
                clnt_perror(clnt, "call failed:");
            }
            printf("function returned:%i\n",result_6);
            break;
            case 7://num_items
            result_7 = num_items_1(clnt);
            if (result_7 == NULL) {
                clnt_perror(clnt, "call failed:");
            }
            printf("function returned:%i\n",result_7);
            break;
            default:
            perror ("Client: Invalid Arguemnt(function)");
            clnt_destroy( clnt );
            exit (1);
            break;
        }
    }
}


main(argc, argv)
int argc;
char *argv[];
{
	char *host;

	if(argc < 2) {
		printf("usage: %s server_host\n", argv[0]);
		exit(1);
	}
	host = argv[1];
	com_1(host);
}
