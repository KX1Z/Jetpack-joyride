/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-jetpack2tek3-keziah.picq
** File description:
** server_algoritm
*/

#include "../includes/my.h"

void set_socket(server_t *server, client_t *client)
{
    int sd;
    FD_ZERO(&server->readfds);
    FD_SET(server->sockfd, &server->readfds);
    server->max_clients = server->sockfd;

    for (int i = 0; i < 2; i++) {
        sd = client[i].sock_state;

        if (sd > 0)
            FD_SET(sd, &server->readfds);
        if (sd > server->max_clients)
            server->max_clients = sd;
    }
}

void check_connection(server_t *server, client_t *client)
{
    int sock = 1;

    if (FD_ISSET(server->sockfd, &server->readfds)) {
        if ((sock = accept(server->sockfd,
        (struct sockaddr *)&server->cliaddr, &server->len)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        printf("this is the new sock value : %d\n", sock);
        if (server->number_of_clients >= 2) {
            write(sock, "Error: Too many connections",
            strlen("Error: Too many connections"));
            close(sock);
        }
        increment_client(client, sock, server);
    }
}

void commands_map(client_t *client, int i)
{
    char *tmp = convert_buffer(client[0].buff);
    char *str1 = strdup("MAP 1.00000 ");
    char *str2 = concatenate_strings(str1,
    int_to_string(count_lines_x(client[0].buff)));
    char *str3 = concatenate_strings(str2, " ");
    char *str4 = concatenate_strings(str3,
    int_to_string(count_lines_y(client[0].buff)));
    char *str5 = concatenate_strings(str4, " ");
    char *result = concatenate_strings(str5, tmp);
    char *result2 = concatenate_strings(result, "\n");
    write(client[i].sock_state, result2, strlen(result2));
}

void check_message(server_t *server, client_t *client)
{
    int sd;
    char *buffer;

    for (int i = 0; i < 2; i++) {
        sd = client[i].sock_state;
        if (FD_ISSET(sd, &server->readfds)) {
            buffer = malloc(sizeof(char) * 1024);
            check_message_for_instr(i, client, server, buffer);
        }
    }
}
