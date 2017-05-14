#include <signal.h>
#include <string.h>

int segundos=0;
int ctrlc=0;

void int_handler(int s){
	printf("%d\n", segundos);
	ctrlc++;
}

void quit_handler(int s){
	printf("%d\n",ctrlc );
	exit(0);
}

void alrm_handler(int s){
	alarm(1);
	segundos++;
}

int main(){
	signal(SIGINT, int_handler);
	signal(SIGQUIT, quit_handler);
	signal(SIGALRM, alrm_handler);
	alarm(1);

	while(1){
		pause();
	}


	return 0;
}