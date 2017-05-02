#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	int fd = open("fifo",O_RDONLY);
	int n = strlen(argv[1]);
	char buffer[n+1];
	memcpy(buf,argv[1],n);
	buf[n] = '\n';

	write(fd,buffer,n+1);
	return 0;
}