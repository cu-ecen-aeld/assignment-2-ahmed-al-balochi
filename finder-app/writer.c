#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <syslog.h>
#include <errno.h>

int main (int argc,char* argv[]){

	openlog ("writer_log", LOG_USER, LOG_LOCAL1);
	if(argc != 3){
		syslog(LOG_ERR, "invalid number of arguments %d\n", argc);
		return 1;
	}
	else{
		char* writerfile = argv[1];
		char* writerstr = argv[2];
		int fd;
		fd = creat (writerfile, 0644);
		if (fd == -1){
			syslog(LOG_ERR, "Error while opening file %s\n", strerror(errno));
			return 1;
		}
		else{
			size_t size = strlen(writerstr);
			ssize_t nr = sizeof(writerstr);
			syslog(LOG_DEBUG, "Writing %s to %s\n", writerstr, writerfile); 
			nr = write(fd, writerstr, size);
			closelog();
			if (nr == -1){
				printf("Error while writing to file\n");
				return 1;
			}
		}
	}
}
