/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-jetpack2tek3-keziah.picq
** File description:
** commands
*/

#include "../includes/my.h"

void check_if_true(client_t *client)
{
    if (client[0].ready == true && client[1].ready == true) {
        send(client[1].sock_state,
        "START\n", 6, 0) && send(client[0].sock_state, "START\n", 6, 0);
    }
}

void check_if_start(client_t *client)
{
    if (client[0].ready == true && client[1].ready == true)
        printf("START");
}

void print_command(char **new_str, int m, int i, client_t *client)
{
    char *message;
    if (strcmp(new_str[m], "ID") == 0) {
        printf("Client message: %s\n", new_str[m]);
        if (client[i].id == 1)
            message = concatenate_strings("ID ", "1\n");
        if (client[i].id == 2)
            message = concatenate_strings("ID ", "2\n");
        write(client[i].sock_state, message, strlen(message));
        return;
    } if (strcmp(new_str[m], "MAP") == 0) {
        commands_map(client, i);
        return;
    } if (strcmp(new_str[m], "READY") == 0) {
        client[i].ready = true;
        check_if_true(client);
        return;
    } if (strcmp(new_str[i], "START") == 0) {
        check_if_start(client);
        return;
    }
}

void check_commands(server_t *server, client_t *client,
char *command, int valread, int sd, int i)
{
    command[valread] = '\0';
    char **new_str = get_newstr_tab(command);
    char *message;
    if (command[0] == 'F' && command[1] == 'I' &&
        command[2] == 'R' && command[3] == 'E') {
        if (command[5] == '0') {
            client[i].jetpack = 0;
        }
        if (command[5] == '1')
            client[i].jetpack = 1;
        return;
    }
    for (int m = 0; m < count_lines_y(command); m++)
        print_command(new_str, m, i, client);
}

void check_message_for_instr(int i, client_t *client,
server_t *server, char *buffer)
{
    int valread;

    if ((valread = read(client[i].sock_state, buffer, 1024)) == 0) {
        close(client[i].sock_state);
        client[i].sock_state = 0;
        server->number_of_clients--;
    } else {
        check_commands(server, client, buffer, valread,
        client[i].sock_state, i);
    }
}
