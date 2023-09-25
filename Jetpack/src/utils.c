/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-jetpack2tek3-keziah.picq
** File description:
** utils
*/

#include "../includes/my.h"

void convert_file_to_map(server_t *server, char **av, client_t *client)
{
    char *buff;
    struct stat sb;
    stat(av[6], &sb);
    buff = malloc(sizeof(char)*sb.st_size);
    int fd = open(av[6], O_RDONLY);
    read(fd, buff, sb.st_size);
    server->buff = buff;
    client[0].buff = buff;
    client[1].buff = buff;
    server->map = convert_str_to_word_array(buff);
    convert_the_tab(server);
}

int count_lines_x(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == '\n')
            return count;
        count++;
    }
}

int count_lines_y(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == '\n')
            count++;
    }
    return count;
}

char **convert_str_to_word_array(char *str)
{
    int x = 0;
    int y = 0;

    char **tab = malloc(sizeof(char*) * count_lines_y(str));
    for (int i = 0; i < count_lines_y(str); i++)
        tab[i] = malloc(sizeof(char) * count_lines_x(str) + 1);
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == '\n') {
            tab[y][x] = 0;
            y++;
            x = 0;
        } else {
            tab[y][x] = str[i];
            x++;
        }
    }
    return tab;
}

char* int_to_string(int num)
{
    int temp = num;
    int count = 0;

    while (temp != 0) {
        count++;
        temp /= 10;
    }
    char* str = (char*)malloc((count + 1) * sizeof(char));
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (int i = count - 1; i >= 0; i--) {
        str[i] = num % 10 + '0';
        num /= 10;
    }
    str[count] = '\0';
    return str;
}
