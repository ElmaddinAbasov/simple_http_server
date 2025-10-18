#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
enum {http_default_port = 8080};
enum {buffer_cap = 1024};
enum {num_of_handling = 2};
create_socket(fd, domain, socket_type);
bind_socket(fd, address, slen);
socket_listen(fd);
get_socket_address(fd, address, address_len);
reuse_port(fd);
close_socket(fd);
#endif
