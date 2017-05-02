#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	mkfifo("fifo",0666);
	int fd = open("fifo",O_WRONLY);
	int f = open("log",O_CREAT | O_WRONLY);
	int n;
	
	while(n=(read(fd,buffer,sizeof(buffer)))>0){
		write(f,buffer,n);
	}
	return 0;
}