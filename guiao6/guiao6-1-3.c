#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	int fd = open("fifo",O_RDONLY);
	int n;
	char buffer[1024];
	while(n=(read(fd,buffer,sizeof(buffer)))>0){
		write(1,buffer,n);
	}
	return 0;
}