#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

#include "../net.h"

#define BUFFER_SIZE 256

int main() {
	int listener = listen_net("0.0.0.0:8181");
	if (listener < 0) {
		fprintf(stderr, "%d\n", listener);
		return 1;
	}

	printf("Server is listening...\n");
	char buffer[BUFFER_SIZE];

	while (1) {
		int conn = accept_net(listener);
		if (conn < 0) {
			fprintf(stderr, "Error: accept\n");
			return 3;
		}
		while (1) {
			int length = recv_net(conn, buffer, BUFFER_SIZE);
			if (length <= 0) {
				break;
			}
			for (char *p = buffer; *p != '\0'; ++p) {
				*p = toupper(*p);
			}
			send_net(conn, buffer, BUFFER_SIZE);
		}
		close_net(conn);
	}

	close_net(listener);
	return 0;
}
