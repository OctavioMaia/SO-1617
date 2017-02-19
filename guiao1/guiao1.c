#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void mycat(){
	char input;

	while(1){
		read(0,&input,1);
		write(1,&input,1);
	}
}

int dez_mb(){
	char input = 'a';
	int r,i;

	r = open("10mb.dat", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if(r==-1){
		perror("error");
		exit(-1);
	}else{
		for(i=0;i<10*1024*1024;i++){
			write(r,&input,1);
		}
	}


	return 0;
}

int main(){
	//mycat();
	dez_mb();
	return 0;
}