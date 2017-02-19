#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

void mycat(){
	char input;

	while(read(0, &input, 1)){
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
	close(r);

	return 0;
}

void mycat_n(int N){
	char input;

	while(read(0, &input, N)){
		write(1,&input,N);
	}
}

ssize_t readln(int fildes, char *buf, size_t nbyte){
	int i=0;
	char input;

	while((input=read(fildes,buf,1)==1) && &buf[i]!='\0'){
		buf[i]=input;
		i++;
	}
	printf("%d\n",i);
}

void n1(char *file){
	int linha=0;
	int fd;
	char buf[1024];

	if(file){
		printf("file: %s\n",file);
		fd = open(file,O_RDONLY);
		readln(fd,buf,1);
	}else{
		printf("not file\n");
		mycat();
	}
}

int main(int argc, char* argv[]) {
	//mycat();
	//dez_mb();
	//mycat_n(8);
	
	/*
	char buf[1024];
	int fp = open("teste.txt",O_RDONLY);
	readln(fp,buf,1024);
	*/

	n1(argv[1]);

	return 0;
}