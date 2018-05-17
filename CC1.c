#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<stdio.h>
char plecare[]="mwcg";
char sosire[]="    ";
int solved(){
	for (int i = 1; i < 4; ++i)
	{
		if(sosire[i] == ' '){
			return 0;
		}
	}
	return 1;
}
void afis(){
	int i;
	printf("pe malul de plecare avem:");
	for (i = 0; i < 4; ++i)
	{
		printf("%c",plecare[i]);
	}
	printf("\npe malul de sosire avem: ");
	for (i = 0; i < 4; ++i)
	{
		printf("%c",sosire[i]);
	}
	printf("\n");
}
int verif(){
	char* i = NULL;
	if((i=strchr(plecare,'g')) != NULL){
		
		if(strchr(plecare,'c')){
			return 0;
		}

		if(strchr(plecare,'w')){
			return 0;
		}
	}
	if(!solved()){
		int i;
		for (i = 0; i < 4; ++i){
			if(sosire[i] == 'g')
				break;
		}
		if(i<4){
			if(strchr(sosire,'c') || strchr(sosire,'w')){
				sosire[i]=' ';
				plecare[i]='g';
				sosire[0]=' ';
				plecare[0]='m';
				return 2;
			}
		}
	}
	return 1;
}
void solve(){
	int i;
	if(solved()){
		printf("gata\n");
		return;
	}
	else{
		
		for(i=1;i<4;i++){
			if(plecare[i]!=' '){
				sosire[i]=plecare[i];
				plecare[i]=' ';
				sosire[0]='m';
				plecare[0]=' ';
				afis();
				int z=verif();
				if(z==1){
					solve();
					break;
				}else if(z==0){
					plecare[i] = sosire[i];
					sosire[i]=' ';
					printf("nu merge\n");
				}else{
					afis();
				}
			}
		}
	}
	return;
}

int main(int argc, char const *argv[]){
	solve();
	return 0;
}