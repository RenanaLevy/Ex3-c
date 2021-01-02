#include <stdio.h>
#include <string.h>

#define SIZE 250
#define LINE 256

int main(){
    //printf("enter\n");
    char str[SIZE][LINE];
    for(int i = 0; i<SIZE ; i++){
        scanf("%[^\n]%*c", str[i]);
    }
    for(int i = 0; str[i]; i++){
        printf("%s\n", str[i]);
    }
}