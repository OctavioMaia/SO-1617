#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 64

int main(){
	int n;
	char b[MAX];

	//redirecionar output
	f=open("saida.txt", o_CREAT | O_WRONLY | O_TRUNC, 0666);
	//if (f== -1) ...

	dup2(f,1);
	close(f);

	if(!fork()){
		n = read(0,b,MAX);
		write(1,b,n);
		//if (f== -1) ...

		printf("ola gente\n");
	}
}