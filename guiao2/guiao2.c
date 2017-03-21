#include <unistd.h>
#include <sys/wait.h>


/* ex1
int main () {
	printf(" sou o filho e o meu pid = %d, sou o pai e o meu ppid= %d\n", getpid(), getppid());
	return 0;
}
*/


//!ma faz o ultimo comando que começa assim ex o make

/* ex2
int main () {
	fork();
	printf(" sou o filho e o meu pid = %d, sou o pai e o meu ppid= %d\n", getpid(), getppid());
	return 0;
}
*/

int main () {
	int p = fork();
	if (p==-1){
		{perror ("asneira no fork"); return (-1);}
	}
	if (p!=0)
		printf(" sou o filho e o meu pid = %d\n",p );
	printf(" sou o filho e o meu pid = %d, sou o pai e o meu ppid= %d\n", getpid(), getppid());

	return 0;
}