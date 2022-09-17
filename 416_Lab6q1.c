#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum,csum,msum,input;
void *runner();

int main(int argc, char *argv[]){
	pthread_t tid;
        pthread_attr_t attr;
     	pthread_attr_init(&attr);

	input = atoi(argv[1]);

	pthread_create(&tid, &attr, runner, argv[1]);

	if(input > 0){
		for(int i = 0; i <= input; i++) 
			msum += i;
	}
	//pthread_join(tid, NULL);

	sum = csum - msum;
	printf("csum - msum = %d\n", sum);
	return 0;
}
void *runner(){
     	int input2 = input*2;
	int i;
	if (input2 > 0){
		for (i = 0; i<= input2; i++) 
			csum +=1;
	}
	pthread_exit(0);
}
