#include "shell.h"


/**
* _strcmp - compares two strings
* @stra: string 1
* @strb: string 2
* Return: if both strings are same 0, else -1
**/

int _strcmp(char *stra, char *strb)
{
	int i;

	for (i = 0; stra[i] != '\0'; i++)
	{
		if (stra[i] == '\0')
			return (1);
		if (stra[i] != strb[i])
			return (-1);
	}
	return (0);
}

/**
* _strlen - calculates the length of a given string
* @strglen: pointer to char
* Return: length of string
**/
int _strlen(char *string)
{
	int strglen;
	int count = 0;

	for (strglen = 0; string[strglen] != '\0'; strglen++)
	{
        count++;
	}
    return (count);
}


/**
* _strcat - concatenates two strings with a format in between
* @stra: string 1
* @strb: string 2
* @formatter: char to add in between
* Return: pointer to new string
**/
char *_strcat(char *stra, char *strb, char formatter)
{
	char *result;
	int i, j;

	result = _malloc(sizeof(char) * (_strlen(stra) + _strlen(strb) + 2));
	if (result == NULL)
		return (NULL);

	for (i = 0; stra[i] != '\0'; i++)
		result[i] = stra[i];

	result[i] = formatter;
	i++;

	for (j = 0; strb[j] != '\0'; j++, i++)
		result[i] = strb[j];

	result[i] = '\0';
	return (result);
}


/**
* _strcat2 - concatenates two strings
* @stra: string 1
* @strb: string 2
* Return: pointer to new concatenated string
**/
char *_strcat2(char *stra, char *strb)
{
	char *result;
        int i, j;

        result = malloc(sizeof(char) * (_strlen(stra) + _strlen(strb) + 1));
        if (result == NULL)
                return (NULL);

        for (i = 0; stra[i] != '\0'; i++)
                result[i] = stra[i];
        for (j = 0; strb[j] != '\0'; j++, i++)
                result[i] = strb[j];

        result[i] = '\0';
        return (result);
}

/**
* _strcpy - copies a given string and returns a copy
* @strng: pointer to chars to be copied
* @i: number of chars to be copied
* Return: pointer to copy
**/

char *_strcpy(char *strng, int i)
{
	int j;
	char *res;

	res = _malloc(sizeof(res) * (i + 1));
	if (res == NULL)
		return (NULL);
	for (j = 0; j < i; j++)
	{
		res[j] = *strng;
		strng++;
	}
	res[j] = '\0';
	return (res);
}
