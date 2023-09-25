/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-jetpack2tek3-keziah.picq copie
** File description:
** seconds_utils
*/

#include "../includes/my.h"

void increment_client(client_t *client, int sock, server_t *server)
{
    for (int i = 0; i < 2; i++) {
        if (client[i].sock_state == 0) {
            client[i].sock_state = sock;
            server->number_of_clients++;
            break;
        }
    }
}

void convert_the_tab(server_t *server)
{
    int y = 0;
    char **tab = malloc(sizeof(char*) * count_lines_y(server->buff));
    for (int i = count_lines_y(server->buff) - 1; i >= 0; i--) {
        tab[y] = server->map[i];
        y++;
    }
    server->convert_buff = tab;
}

int return_errors(char *file, int ac, struct timeval *timeout)
{
    struct stat stats;
    char *buffer = NULL;
    int fd = open(file, O_RDONLY);

    if (ac != 7)
        exit(84);
    if (fd == -1)
        exit(84);
    stat(file, &stats);
    buffer = malloc(sizeof(char) * (stats.st_size + 1));
    if (read(fd, buffer, stats.st_size) == -1)
        exit(84);
    close(fd);
    timeout->tv_sec = 0;
    timeout->tv_usec = 0;
}
