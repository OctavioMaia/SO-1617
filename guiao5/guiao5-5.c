int main(){
	int a[2];
	pip(a);
	if(!fork()){
		dup2(a[1],1);
		close(a[1]);
		execlp("grep","grep","-v","^#","/etc/passwd", (char*)0);
		exit(1);
	}
	close(a[1]);
	dup2(a[0],0);
	close(a[0]);

	pipe(a);
	if(!fork()){
		dup2(a[1],1);
		close(a[1]);
		execlp("cut","cut","-f7","-d:",(char*)0);
		exit(1);
	}
	close(a[1]);
	dup2(a[0],0);
	close(a[0]);

	if(!fork()){
		dup2(a[1],1);
		close(a[1]);
		execlp("uniq","uniq",(char*)0);
		exit(1);
	}
	close(a[1]);
	dup2(a[0],0);
	close(a[0]);
	execlp("wc","wc","-l",(char*)0);
}