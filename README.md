# simple_http_server
implementing a simple tcp/ip server using streaming sockets, to handle a clients request from a web broweser

# How we turned a simple iterative tcp/ip server with streaming sockets into a simple http-server

This is how you do it:

- First you define within a program a default http port - 8080
- You create a streaming socket that will establish connection within network using IPv4 IP addresses
- What is socket basically, you can ask. Well it a combination of a port number and IP address.
- Now we have both, so lets bind socket with IP address and port number.
- Next we mark out socket as a listening socket, so it accept connection on a peer socket.
- Then define an infinite loop, and inside this loop start accepting connection from client, which is a web broweser.
- Once client connects, accept returns you a socket, and you will use this socket to communicate with a client.
- First you read a client request, which is GET.
- Then we printed an IP address and port number of a client.
- Then we build an http responce POST and send a message 
