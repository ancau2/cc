#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *boat;
char[3] east = {'g','c','w'};
char[3] west = {'n','n','n'};

/*  n = nothing;
	g = goat;
	c = cabbage;
	w = wolf;
*/

void addNewItem(char item){
	char *aux = boat;
	boat = (char *) malloc(sizeof(boat)+1);
	strcpy(boat,aux);
	boat[strlen(boat)-1] = item;
}

void deleteLastItem(){
	char *aux = boat;
	boat = (char *) malloc(sizeof(boat)-1);
	for(int i = 0;i < strlen(aux)-1;i++){
		boat[i] = aux[i];
	}
}

void resetBoat(){
	boat = (char *) malloc(0);
	strcpy(boat,"");
}

int accepted(){
	for(int i = 0; i < 3; i++){
		if(west[i] == 'n')
			return 0;
	}
	return 1;
}

void solve(){
	while(!accepted()){
		
	}
}


int main(int argc, char const *argv[])
{
	resetBoat();
	solve();
	return 0;
}