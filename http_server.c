#include "http_server.h"
create_socket(fd, domain, socket_type)
int* fd;
int domain;
int socket_type;
{
        errno = 0;
        *fd = socket(domain, socket_type, 0);
        if (*fd == -1)
        {
                perror("ERROR: Failed to create a socket *fd = socket(domain, socket_type, 0)");
                exit(1);
        }
}

bind_socket(fd, address, slen)
int fd;
const struct sockaddr* address;
socklen_t slen;
{
	int res;

        errno = 0;
        res = bind(fd, address, slen);
        if (res == -1)
        {
                perror("ERROR: Failed to bind a socket, res = bind(fd, address, slen)\n");
                exit(2);
        }
}

socket_listen(fd)
int fd;
{
	int res;
        errno = 0;
        res = listen(fd, SOMAXCONN);
        if (res == -1)
        {
                perror("ERROR: Failed to mark socket as listening, res = listen(fd, SOMAXCONN)\n");
                exit(3);
        }
}

get_socket_address(fd, address, address_len)
int fd;
struct sockaddr* address;
socklen_t* address_len;
{
	int res;
        errno = 0;
        res = getsockname(fd, address, address_len);
        if (res == -1)
        {
		perror("ERROR: Failed to get client address, getsockname(fd, address, address_len)");
                exit(4);
        }
}

reuse_port(fd)
int fd;
{
	int res, n;
	n = 0;
	errno = 0;
	res = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &n, sizeof(n));
	if (res == -1)
	{
		perror("ERROR: Failed to reuse port, reuse_port(fd)\n");
		exit(5);
	}
}

close_socket(fd)
int fd;
{
	int res;
        errno = 0;
        res = close(fd);
        if (res == -1)
        {
                perror("ERROR: Failed to close a server file descriptor res = close(fd)");
                exit(6);
        }
}
