/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-jetpack2tek3-keziah.picq
** File description:
** game
*/

#include "../includes/my.h"

int get_cords_y_three(int y_one)
{
    int y_3 = y_one;
    if (y_3 == 0) {
        y_3 = 9;
        return y_3;
    } if (y_3 == 1) {
        y_3 = 8;
        return y_3;
    } if (y_3 == 2) {
        y_3 = 7;
        return y_3;
    } if (y_3 == 3) {
        y_3 = 6;
        return y_3;
    }
    if (get_cords_y_three_bis(y_3) != -1000)
        return get_cords_y_three_bis(y_3);

}

int get_cords_y_four(int y_two)
{
    int y_4 = y_two;
    if (y_4 == 0) {
        y_4 = 9;
        return y_4;
    } if (y_4 == 1) {
        y_4 = 8;
        return y_4;
    } if (y_4 == 2) {
        y_4 = 7;
        return y_4;
    } if (y_4 == 3) {
        y_4 = 6;
        return y_4;
    }
    if (get_cords_y_four_bis(y_4) != -1000)
        return get_cords_y_four_bis(y_4);

}

void first_checking(client_t *client, int y_1, int y_2, server_t *server)
{
    if (client[0].jetpack == 0 && y_1 - 1 >= 0)
        client[0].y -= 0.1;
    if (client[1].jetpack == 0 && y_2 - 1 >= 0)
        client[1].y -= 0.1;
    if (client[0].jetpack == 1 && y_1 + 1 < count_lines_y(server->buff) - 1) {
        client[0].y = client[0].y + 0.1;
    }
    if (client[1].jetpack == 1 && y_2 + 1 < count_lines_y(server->buff) - 1) {
        client[1].y = client[1].y + 0.1;
    }
}

void second_checkings(client_t *client, server_t *server, int y_1, int y_2)
{
    int x = (int)client[0].x;
    int y_3 = get_cords_y_three(y_1);
    if (server->convert_buff[y_1][x] == 'e')
        client[0].state_life = false;
    if (server->convert_buff[y_2][x] == 'e')
        client[1].state_life = false;
    if (client[0].state_life == false) {
        dprintf(client[0].sock_state, "FINISH 2\n");
        dprintf(client[1].sock_state, "FINISH 2\n");
    }
    if (client[1].state_life == false) {
        dprintf(client[0].sock_state, "FINISH 1\n");
        dprintf(client[1].sock_state, "FINISH 1\n");
    }
    if (server->convert_buff[y_1][x] == 'c') {
    server->convert_buff[y_1][x] = '_';
    client[0].coins++;
    dprintf(client[0].sock_state, "COIN 1 %d %d\n", x, y_3);
    dprintf(client[1].sock_state, "COIN 1 %d %d\n", x, y_3);
    }
}

void last_checkings(client_t *client, server_t *server, int y_1, int y_2)
{
    int x = (int)client[0].x;
    int y_4 = get_cords_y_four(y_2);

    if (server->convert_buff[y_2][x] == 'c') {
        server->convert_buff[y_2][x] = '_';
        client[1].coins++;
        dprintf(client[0].sock_state, "COIN 2 %d %d\n", x, y_4);
        dprintf(client[1].sock_state, "COIN 2 %d %d\n", x, y_4);
    }
    dprintf(client[0].sock_state, "PLAYER 1 %.1f %.1f %d %d\n",
    client[0].x, client[0].y, client[0].coins, client[0].jetpack);
    dprintf(client[0].sock_state, "PLAYER 2 %.1f %.1f %d %d\n",
    client[0].x, client[1].y, client[1].coins, client[1].jetpack);
    dprintf(client[1].sock_state, "PLAYER 1 %.1f %.1f %d %d\n",
    client[0].x, client[0].y, client[0].coins, client[0].jetpack);
    dprintf(client[1].sock_state, "PLAYER 2 %.1f %.1f %d %d\n",
    client[0].x, client[1].y, client[1].coins, client[1].jetpack);
}
