/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-jetpack2tek3-keziah.picq
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <sys/select.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #include <time.h>

    typedef struct server {
        int port;
        int sockfd;
        int number_of_clients;
        struct sockaddr_in servaddr;
        fd_set readfds;
        int max_clients;
        socklen_t len;
        struct sockaddr_in cliaddr;
        char **map;
        char **convert_buff;
        char *buff;
    } server_t;

    typedef struct client {
        char *message;
        int id;
        int jetpack_state;
        int sock_state;
        struct sockaddr_in cliaddr;
        bool ready;
        int jetpack;
        float x;
        float y;
        int coins;
        bool state_life;
        float gravity;
        char *buff;
    } client_t;

    // function prototypes
    server_t *declare_server(char **arv);
    void connect_to_server(server_t *server);
    void check_connection(server_t *server, client_t *client);
    void set_socket(server_t *server, client_t *client);
    void check_message(server_t *server, client_t *client);
    // void check_commands(server_t *server, client_t *client,
    // char *command, int valread, int sd, int i);
    char* concatenate_strings(const char* str1, const char* str2);
    int get_alph(char *str);
    char *get_newstr(char *command);
    void init_client(client_t *client, server_t *server, char **argv);
    void convert_file_to_map(server_t *server, char **av, client_t *client);
    void convert_the_tab(server_t *server);
    int if_newline(char *command, int i);
    char *convert_buffer(char *str);
    char **get_newstr_tab(char *command);
    void check_message_for_instr(int i, client_t *client,
    server_t *server, char *buffer);

    //utils
    char **convert_str_to_word_array(char *str);
    int count_lines_x(char *str);
    int count_lines_y(char *str);
    int count_lines_x(char *str);
    char* int_to_string(int num);
    int get_cords_y_three(int y_one);
    int get_cords_y_four(int y_two);
    void first_checking(client_t *client, int y_1, int y_2, server_t *server);
    void second_checkings(client_t *client, server_t *server, int y_1, int y_2);
    void last_checkings(client_t *client, server_t *server, int y_1, int y_2);
    int get_cords_y_three_bis(int y_3);
    int get_cords_y_four_bis(int y_4);
    void increment_client(client_t *client, int sock, server_t *server);
    void commands_map(client_t *client, int i);
    int return_errors(char *file, int ac, struct timeval *timeout);


#endif /* !MY_H_ */
