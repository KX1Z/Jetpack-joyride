/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-jetpack2tek3-keziah.picq
** File description:
** init_server
*/

#include "../includes/my.h"

server_t *declare_server(char **argv)
{
    server_t *server = malloc(sizeof(server_t));
    server->len = sizeof(server->cliaddr);
    server->number_of_clients = 0;
    server->port = atoi(argv[2]);
    int opt = 1;

    if ((server->sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(server->sockfd, SOL_SOCKET, SO_REUSEADDR, &opt,
    sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    server->servaddr.sin_family = AF_INET;
    server->servaddr.sin_addr.s_addr = INADDR_ANY;
    server->servaddr.sin_port = htons(server->port);
    return server;
}

void connect_to_server(server_t *server)
{
    if (bind(server->sockfd, (struct sockaddr *)&server->servaddr,
    sizeof(server->servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server->sockfd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("SERVER SUCCESSFULLY CREATED\n");
}

void init_client(client_t *client, server_t *server, char **av)
{
    for (int i = 0; i < 2; i++)
        client->sock_state = 0;
    client[0].id = 1;
    client[1].id = 2;
    client[0].ready = false;
    client[1].ready = false;
    client[0].jetpack = 0;
    client[1].jetpack = 0;
    client[0].x = 0;
    client[1].x = 0;
    client[0].y = 4;
    client[1].y = 4;
    client[0].coins = 0;
    client[1].coins = 0;
    client[0].state_life = true;
    client[1].state_life = true;
    client[0].gravity = atof(av[4]);
    client[1].gravity = atof(av[4]);
}
