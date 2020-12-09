#include <stdio.h>
#include <stdint.h>

#include "../net.h"

#define BUFFER_SIZE 256

int main() {
	int conn = connect_net("127.0.0.1:8181");
	if (conn < 0) {
		fprintf(stderr, "%d\n", conn);
		return 1;
	}

	char buffer[BUFFER_SIZE];
	for (int i = 0; i < 20; ++i) {
		buffer[i] = 'a';
	}

	send_net(conn, buffer, BUFFER_SIZE);
	recv_net(conn, buffer, BUFFER_SIZE);

	printf("%s\n", buffer);
	close_net(conn);

	return 0;
}
