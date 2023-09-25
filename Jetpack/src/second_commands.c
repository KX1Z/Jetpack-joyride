/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-jetpack2tek3-keziah.picq copie
** File description:
** second_commands
*/

#include "../includes/my.h"

char* concatenate_strings(const char* str1, const char* str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *result;

    result = malloc(sizeof(char) * (len1 + len2 + 1));
    if (result != NULL) {
        strcpy(result, str1);
        strcat(result, str2);
    }
    return result;
}

int get_alph(char *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') ||
        (str[i] >= 'A' && str[i] <= 'Z'))
            continue;
        else
            return i;
    }
}

int if_newline(char *command, int i)
{
    for (; command[i] != 0; i++) {
        if (command[i] == '\n')
            return i;
    }
    return -1;
}

char *get_newstr(char *command)
{

    char *new_str = malloc(sizeof(char) * 10);
    int i = 0;
    int count = 0;

    for (; command[i] != 0; i++) {
        if ((command[i] >= 'a' && command[i] <= 'z') ||
        (command[i] >= 'A' && command[i] <= 'Z')) {
            new_str[count] = command[i];
            count++;
        }
    }
    new_str[i] = 0;
    return new_str;
}

char *convert_buffer(char *str)
{
    char *buff = malloc(sizeof(char) * strlen(str) + 2);
    int count = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (str[i] != '\n') {
            buff[count] = str[i];
            count++;
        }
    }
    buff[count] = 0;
    return buff;
}
