#include "http_server.h"
static char http_method[buffer_cap];
static char uri[buffer_cap];
static char http_version[buffer_cap];
main()
{
	int sfd, fd, res, i;
	struct sockaddr_in s, s2, client_address;
	socklen_t slen, slen2, client_len;
	ssize_t cnt;
	char buffer[buffer_cap];
	char resp[] = "HTTP/1.0 200 OK\r\n"
                  "Server: webserver-c\r\n"
                  "Content-type: text/html\r\n\r\n"
                  "<h1>hello, world</h1>\r\n";

	slen2 = sizeof(s2);
	client_len = sizeof(client_address);
	i = 0;

	create_socket(&sfd, AF_INET, SOCK_STREAM);
	s.sin_family = AF_INET;
	s.sin_port = htons(http_default_port);
	s.sin_addr.s_addr = htons(INADDR_ANY);
	slen = sizeof(s);

	bind_socket(sfd, (const struct sockaddr*)&s, slen);
	socket_listen(sfd);

	for (;i < num_of_handling;)
	{
		errno = 0;
		fd = accept(sfd, (struct sockaddr*)&s2, &slen2);
		if (fd == -1)
		{
			perror("ERROR: Failed to accept connection\n");
			exit(7);
		}
		printf("connection was established\n");

		get_socket_address(fd, (struct sockaddr*)&client_address, &client_len);

		errno = 0;
		cnt = read(fd, buffer, buffer_cap);
		if (cnt == -1)
		{
			perror("ERROR: Failed to read data\n");
			exit(8);
		}

		errno = 0;
		res = sscanf(buffer, "%s %s %s", http_method, uri, http_version);
		if (res != 3)
		{
			perror("ERROR: Failed to parse http request from client\n");
			exit(9);
		}
		printf("[%s:%u]\t %s %s %s\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), http_method, uri, http_version);
		write(fd, resp, strlen(resp));
		close(fd);
		i++;
	}
	reuse_port(sfd);
	close_socket(sfd);
	exit(0);
}
