#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
	openlog(NULL, LOG_PID, LOG_USER);

	if (argc != 3) {
		syslog(LOG_ERR, "missing arguments");
		return EXIT_FAILURE;
	}

	const char* writefile = argv[1];
	const char* writestr = argv[2];

	int fd = creat(writefile, S_IRWXU);
	if(fd == -1) {
		syslog(LOG_ERR, "cannot create file: %s", writefile);
		return EXIT_FAILURE;
	}

	ssize_t len = write(fd, writestr, strlen(writestr));
	if(len == -1) {
		syslog(LOG_ERR, "failed to write to file: %s", writefile);
		close(fd);
		return EXIT_FAILURE;
	}

	syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);
	close(fd);
	return EXIT_SUCCESS;
}
