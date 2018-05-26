#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
Q = {q1,q2,q3,q4}

S = {0,1}

g:
     0       1        Eps
q1  {q1}   {q1,q2}     {}
q2  {q3}     {}        {}
q3  {}       {q4}      {q3}
q4  {q4}     {q4}      {}

q1 -> start state

F = {q4}
*/

int accepted(int state,int n,const char* string){
    while(n < strlen(string)){
        printf("stare: %d caracter: %c\n",state,string[n]);
        switch(state){
            case 1:
                if (string[n] == '0') {
                    n++;
                } else if (string[n] == '1') {
                    n++;
                    if (accepted(1, n, string) == 0) {
                        printf("traseu incorect, mergem in starea 2\n");
                        state = 2;
                    }
                    else{
                        return 1;
                    }
                }else{
                    return 0;
                }
                break;
            case 2:
                if(string[n]!='1'){
                    state=3;
                    n++;
                }
                else{
                    return 0;
                }
                break;
            case 3:
                if(string[n]=='1'){
                    state=4;
                    n++;
                }
                else {
                    return 0;
                }
                break;
            case 4:
                if(string[n]=='1'||string[n]=='1'){
                    n++;
                }
                else{return 0;}
                break;
            default:
                printf("nu a intrat pe nicio stare");
                break;
        }
    }

    if (state == 4) {
        return n == strlen(string) ? 1 : 0;
    } else {
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    if(argc < 2){
        printf("Se asteapta introducerea unui parametru\n");
        exit(1);
    }
    if(accepted(1,0,argv[1]))
        printf("String acceptat\n");
    else
        printf("String refuzat\n");
    return 0;
}