/*
 * jsondec.c
 *
 *  Created on: May 19, 2017
 *      Author: inventor
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_JSON_LENGTH 2048
#define MAX_JSON_VALUES_LENGTH 10
#define MAX_JSON_NAMES_LENGTH 10
#define TRUE 1
#define FALSE 0


char array[MAX_JSON_LENGTH];
char *valuesArray[MAX_JSON_VALUES_LENGTH];

void extractJSONName(char* nameArray, char *name_string_head, char *name_string_tail, int index_);
void extractFromBracket(char *valueArray, char *bracket_head, char *bracket_tail, int index_);
void extractJSONValues(char *nameArray, char *name_string_head, char *name_string_tail, int index_);
struct dStruct getData();

char *str = "{\r\n  \"pinshhhhhhh\": [\"1\",\"2\"],\r\n  \"units\": [\"%\", \"degC\", \"degC\", \"degC\", \"%\"],\r\n  \"type\": \"LM35\",\r\n  \"id\": \"1\",\r\n  \"api_key\": \"asgbdhfbswiwhdncjdoed\",\r\n  \"isEnabled\": \"1\"\r\n}";
char *array_ptr = &array[0];
char *head_ptr = &array[0], *tail_ptr = &array[0];
int index_ = 0, _index = 0;
int k = 0;

struct dStruct
{
	char *jsonNames[MAX_JSON_NAMES_LENGTH];
	char *jsonValues[MAX_JSON_VALUES_LENGTH];
	} _dStruct;

int main()
{
	while(*str != '\0')
	{
		if((*str != ' ') && (*str != '\r') && (*str != '\n'))
		{
			*array_ptr = *str;
			array_ptr++;
		}
		str++;
	}
	*array_ptr = '\0';
	printf("%s\n", array);

	//***************GET NAMES****************//
	while(TRUE)
	{
		while(*tail_ptr != ':')
		{
			tail_ptr++;
			if(*tail_ptr == '}')
			{
				break;
			}
		}
		head_ptr = tail_ptr;
		while(*head_ptr != ',' && *head_ptr != '{')
		{
			head_ptr--;
			if(*tail_ptr == '}')
			{
				break;
			}
		}
		if(*tail_ptr == '}')
		{
			break;
		}
		else
		{
			//char *name_array_ptr = &namesArray[index_];
			char *name_array_ptr = (char*)malloc(sizeof(char*) * 2);
			extractJSONName(name_array_ptr, head_ptr+1, tail_ptr-1, index_);
			index_++;
			tail_ptr++;
			head_ptr = &array[0];
		}
	}

	head_ptr = &array[0];
	tail_ptr = &array[0];

	//**************GET VALUES****************//
	while(TRUE)
	{
		while(*head_ptr != ':')
		{
			head_ptr++;
			if(*tail_ptr == '}')
			{
				break;
			}
		}
		if(*(head_ptr+1) == '[')
		{
			while(*head_ptr != '[')
			{
				head_ptr++;
				if(*tail_ptr == '}')
				{
					break;
				}
			}
			tail_ptr = head_ptr;
			if(*head_ptr == '[')
			{
				//char *value_array_ptr = (char*)&valuesArray[_index];
				char *value_array_ptr = (char*)malloc(sizeof(char*) * 2);
				extractFromBracket(value_array_ptr, head_ptr, tail_ptr, _index);
				//printf("%s\n", value_array_ptr);
				_index++;
			}
		}
		else if(*(head_ptr+1) == '"')
		{
			while(*head_ptr != '"')
			{
				head_ptr++;
				if(*tail_ptr == '}')
				{
					break;
				}
			}
			tail_ptr = head_ptr;
			if(*head_ptr == '"')
			{
				while(TRUE)
				{
					if(tail_ptr == head_ptr && *tail_ptr == '"')
					{
						tail_ptr++;
					}
					else if(*tail_ptr != '"')
					{
						tail_ptr++;
					}
					else if(*tail_ptr == '"' && tail_ptr != head_ptr)
					{
						break;
					}
					else if(*tail_ptr == '}')
					{
						break;
					}
				}
			}
			//char *value_array_ptr = (char*)&valuesArray[_index];
			char *value_array_ptr = (char*)malloc(sizeof(char*) * 2);
			extractJSONValues(value_array_ptr, head_ptr, tail_ptr, _index);
			//printf("%s\n", value_array_ptr);
			_index++;
			if(*tail_ptr == '}' || *(tail_ptr+1) == '}')
			{
				tail_ptr++;
				break;
			}
		}
		if(*tail_ptr == '}')
		{
			break;
		}


	}


	printf("%s\n", _dStruct.jsonNames[0]);
	printf("%s\n", _dStruct.jsonNames[1]);
	printf("%s\n", _dStruct.jsonNames[2]);
	printf("%s\n", _dStruct.jsonNames[3]);
	printf("%s\n", _dStruct.jsonNames[4]);
	printf("%s\n", _dStruct.jsonNames[5]);

	printf("%s\n", _dStruct.jsonValues[0]);
	printf("%s\n", _dStruct.jsonValues[1]);
	printf("%s\n", _dStruct.jsonValues[2]);
	printf("%s\n", _dStruct.jsonValues[3]);
	printf("%s\n", _dStruct.jsonValues[4]);
	printf("%s\n", _dStruct.jsonValues[5]);





	return 0;
}

void extractJSONName(char *nameArray, char *name_string_head, char *name_string_tail, int index_)
{
	char *name_array_ptr = &nameArray[0];
	//printf("extractJSONName pointer size = %d\n", sizeof(&nameArray[0]));
	while(name_string_head != name_string_tail)
	{
		if(*name_string_head != '"')
		{
			*name_array_ptr = *name_string_head;
			name_array_ptr++;
		}
		name_string_head++;
	}
	*name_array_ptr = '\0';
	_dStruct.jsonNames[index_] = nameArray;
	}

void extractJSONValues(char *nameArray, char *name_string_head, char *name_string_tail, int index_)
{
	char *name_array_ptr = &nameArray[0];
	//printf("extractJSONValues pointer size = %d\n", sizeof(name_array_ptr));
	while(name_string_head != name_string_tail)
	{
		if(*name_string_head != '"')
		{
			*name_array_ptr = *name_string_head;
			name_array_ptr++;
		}
		name_string_head++;
	}
	*name_array_ptr = '\0';
	_dStruct.jsonValues[index_] = nameArray;
	}

void extractFromBracket(char *valueArray, char *bracket_head, char *bracket_tail, int index_)
{
	char *value_array_ptr = &valueArray[0];
	//printf("extractFromBracket pointer size = %d\n", sizeof(value_array_ptr));
	while(TRUE)
	{
		while(*bracket_head != '"')
		{
			bracket_head++;
		}
		while(TRUE)
		{
			if(bracket_tail == bracket_head && *bracket_tail == '"')
			{
				bracket_tail++;
			}
			else if(*bracket_tail != '"')
			{
				bracket_tail++;
			}
			else if(*bracket_tail == '"' && bracket_tail != bracket_head)
			{
				break;
			}
		}
		while(bracket_head != bracket_tail)
		{
			if(*bracket_head != '"')
			{
				*value_array_ptr = *bracket_head;
				value_array_ptr++;
			}
			bracket_head++;
		}
		if(*(bracket_head+1) == ',')
		{
			bracket_head++;
			bracket_tail++;
			*value_array_ptr = ',';
			value_array_ptr++;
		}
		else if(*(bracket_head+1) == ']')
		{
			*value_array_ptr = '\0';
			break;
		}
	}
	_dStruct.jsonValues[index_] = valueArray;
	}

struct dStruct getData()
{
	return _dStruct;
	}
