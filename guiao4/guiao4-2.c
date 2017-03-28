#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int fp,saida,erros;
	char aux;

	fp = open("/etc/passwd", O_RDONLY);
	dup2(fp,0);
	close(fp);

	//saida
	saida=open("saida.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	dup2(saida,1);
	close(saida);

	//erros
	erros=open("erros.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	dup2(erros,2);
	close(erros);


	if(fork()==0){
		while(read(0,&aux,1)==1){
			write(1,&aux,1);
		}
		write(2,"ERRO",4);	
	}

	return 0;
}