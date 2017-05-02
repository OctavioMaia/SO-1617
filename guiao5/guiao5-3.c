#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int pd[2],n;
	pipe(pd);
	char aux[10];
	if(!fork()) {
		close(pd[1]);
		dup2(pd[0],0);
		close(pd[0]);
		execlp("wc","wc",(char*)0);
		exit(0);
	}
	close(pd[0]);
	while(1) {
		n = read(0,aux,sizeof(aux));
		if (n<=0) break;
		write(pd[1],aux,n); 
	}
	close(pd[1]);
}