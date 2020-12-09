#ifndef HTTPLIB_NET_H
#define HTTPLIB_NET_H

#include <stddef.h> // For size_t

extern int listen_net(char *address);
extern int accept_net(int listener);

extern int connect_net(char *address);
extern int close_net(int conn);

extern int send_net(int conn, char *buffer, size_t size);
extern int recv_net(int conn, char *buffer, size_t size);

#endif
