#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	int fd = open("fifo",O_WRONLY);
	int n;
	char buffer[1024];
	while(n=(read(0,buffer,sizeof(buffer)))>0){
		write(fd,buffer,n);
	}
	return 0;
}	