//
//  keys.h
//  
//
//  Created by Jan Ferbr on 21/04/2021.
//

#ifndef keys_h
#define keys_h

int Innit();
int Set_value(char* key, char* value1, int value2, float value3);
int Get_value(char* key, char* value1, int* value2, float* value3);
int Modify_value(char* key, char* value1, int value2, float value3);
int Delete_key(char* key);
int Exist(char* key);
int Num_items();


#endif /* keys_h */
