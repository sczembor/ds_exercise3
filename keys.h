//
//  keys.h
//  
//
//  Created by Jan Ferbr on 21/04/2021.
//

#ifndef keys_h
#define keys_h

int innit();
int set_value(char* key, char* value1, int value2, float value3);
int get_value(char* key);
int modify_value(char* key, char* value1, int value2, float value3);
int delete_key(char* key);
int exist(char* key);
int num_items();


#endif /* keys_h */
