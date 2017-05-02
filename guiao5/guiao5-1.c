#include <unistd.h>
#include <stdio.h>

int main(){
	int pd[2];
	pipe(pd);

	if(!fork()){
		close(pd[1]); //so vou ler, n vou escrever
		char aux[100];
		while(1){
			int n = read(pd[0],aux,sizeof(aux));
			if(n<=0) break;
			write(1,aux,n);
		}
		printf("terminou\n");
		_exit(0);
	}
	close(pd[0]);
	sleep(3);
	write(pd[1],"aaa\n",4);
	close(pd[1]);
}