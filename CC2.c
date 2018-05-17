#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
 Q={q1,q2,q3}
 
 S={0,1}
 
 g: 
    0   1
q1  q1  q2
q2  q3  q2
q3  q2  q2

q1 -> start state

F = {q2}

L(M1) = { w | w contains at least one 1 and an even number of 0s follow the last 1}
*/
int accepted(char const*string){
	int state = 1;
	int n = 0;
	
	while(n < strlen(string)){
		printf("Am ajuns in starea:%d\n",state);
		if(state == 1){
			if(string[n] == '0'){
				state = 1;
				n++;
				continue;
			}	
			if(string[n] == '1'){
				state = 2;
				n++;
				continue;
			}
		}

		if(state == 2){
			if(string[n] == '1'){
				state = 2;
				n++;
				continue;
			}
			if(string[n] == '0'){
				state = 3;
				n++;
				continue;
			}
		}

		if(state == 3){
			if((string[n] == '0') || (string[n] == '1')){
				state = 2;
				n++;
				continue;
			}
		}
	}

	if ((n == strlen(string))&&(state == 2))
		return 1;
	else 
		return 0;
}

int main(int argc, char const *argv[]){
	
	if(argc < 2){
		printf("Se asteapta introducerea unui parametru\n");
		exit(1);
	}
	if(accepted(argv[1]))
		printf("String acceptat\n");
	else 
		printf("String refuzat\n");
	return 0;
}