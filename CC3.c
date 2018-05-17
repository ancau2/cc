#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
Q = {q1,q2,q3,q4}

S = {0,1}

g:
     0       1        Eps
q1  {q1}   {q1,q2}     {}
q2  {q3}     {}        {q3}
q3  {}       {q4}      {}
q4  {q4}     {q4}      {}

q1 -> start state

F = {q4}
*/

int accepted(const char* string){
	int state = 1;
	int n = 0;
	while(n < strlen(string)){
		if(state == 1){

		}

		if(state == 2){
		
		}

		if(state == 3){

		}

		if(state == 4){
			
		}
	}

	if((n == strlen(string)) && (state == 4))
		return 1;
    else return 0;
}

int main(int argc, char const *argv[])
{
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