/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-jetpack2tek3-keziah.picq
** File description:
** main
*/

#include "../includes/my.h"

char **get_newstr_tab(char *command)
{
    int x = 0;
    int y = 0;

    char **tab = malloc(sizeof(char *) * count_lines_y(command));
    for (int i = 0; i < count_lines_y(command); i++)
        tab[i] = malloc(sizeof(char) * 10);
    for (int i = 0; command[i] != 0; i++) {
        if (command[i] == '\n') {
            tab[y][x] = 0;
            x = 0;
            y++;
        } else {
            tab[y][x] = command[i];
            x++;
        }
    }
    for (int i = 0; i < count_lines_y(command); i++)
        tab[i] = get_newstr(tab[i]);
    return tab;
}

int get_cords_y_three_bis(int y_3)
{
    if (y_3 == 4) {
        y_3 = 5;
        return y_3;
    } if (y_3 == 5) {
        y_3 = 4;
        return y_3;
    } if (y_3 == 6) {
        y_3 = 3;
        return y_3;
    } if (y_3 == 7) {
        y_3 = 2;
        return y_3;
    } if (y_3 == 8) {
        y_3 = 1;
        return y_3;
    } if (y_3 == 9) {
        y_3 = 0;
        return y_3;
    }
    return -1000;
}

int get_cords_y_four_bis(int y_4)
{
    if (y_4 == 4) {
        y_4 = 5;
        return y_4;
    } if (y_4 == 5) {
        y_4 = 4;
        return y_4;
    } if (y_4 == 6) {
        y_4 = 3;
        return y_4;
    } if (y_4 == 7) {
        y_4 = 2;
        return y_4;
    } if (y_4 == 8) {
        y_4 = 1;
        return y_4;
    } if (y_4 == 9) {
        y_4 = 0;
        return y_4;
    }
    return -1000;
}

void do_game(client_t *client, server_t *server)
{
    if (client[0].ready == true && client[1].ready == true) {
        int x = (int)client[0].x;
        int y_1 = (int)client[0].y;
        int y_2 = (int)client[1].y;
        int y_3 = get_cords_y_three(y_1);
        int y_4 = get_cords_y_four(y_2);
        first_checking(client, y_1, y_2, server);
        for (int i = 0; i < 20; i++) {
            second_checkings(client, server, y_1, y_2);
            last_checkings(client, server, y_1, y_2);
        }
        client[0].x = client[0].x + 0.1;
        usleep(20000);
    }
}

int main(int argc, char* argv[])
{
    struct timeval timeout;
    return_errors(argv[6], argc, &timeout);
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        return 1;
    } server_t *server = declare_server(argv);
    client_t *client = malloc(sizeof(client_t) * 2);
    connect_to_server(server);
    convert_file_to_map(server, argv, client);
    time_t start, end;
    init_client(client, server, argv);
    while (1) {
        set_socket(server, client);
        if (select(FD_SETSIZE, &server->readfds, NULL, NULL, &timeout) < 0) {
            perror("select");
            exit(EXIT_FAILURE);
        } check_connection(server, client);
        check_message(server, client);
        do_game(client, server);
    } return 0;
}
