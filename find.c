#include <stdio.h>
#include <string.h>
#include "find.h"

#define SIZE 250
#define LINE 256
#define WORD 30

//Input lines.
void searchLines(char *wordToSearch){
    char str[SIZE][LINE*WORD];
    for(int i = 0; i<SIZE ; i++){
        scanf("%[^\n]%*c", str[i]);
        substring(str[i], wordToSearch);
    }
}

//Print the line if it containig the wordToSearch.
void substring(char line[], char *wordToSearch){
    int lenWord = strlen(wordToSearch);
    int count = 0;

    for(int i = 0; line[i] && (count < lenWord); i++){
        if(line[i] == *(wordToSearch + count)){
            count++;
        }
        else{
            count = 0;
        }
    }

    if(count == lenWord){
        printf("%s\n", line);
    }
}

//Input words.
void searchwords(char *wordToSearch){
    char str[SIZE*LINE][WORD];
    for(int i = 0; i < SIZE*LINE; i++){
        scanf("%s", str[i]);
        similarWord(str[i], wordToSearch);
    }
}

//Print the word if it similar to wordToSearch.
void similarWord(char word[], char *wordToSearch){
    int countDifferent = 0;
    int wordLen = strlen(word);
    int searchLen = strlen(wordToSearch);

    if(searchLen == 1){
        if(wordLen == 1 && word[0] == *wordToSearch){
            printf("%s\n", word);
        }
        else if(wordLen == 2 && ((word[0] == *wordToSearch) || (word[1] == *wordToSearch))){
            printf("%s\n", word);
        }
        else{
            return;
        }
    }

    else if(searchLen > 1){
        if((wordLen == (searchLen+1)) || (wordLen == searchLen)){

            for(int i = 0; word[i] && (countDifferent <= 1); i++){
                if(word[i] == *wordToSearch){
                    wordToSearch++;
                }
                else{
                    countDifferent++;
                }  
            }

            if(wordLen == searchLen && countDifferent ==1){
                return;
            }

            if(countDifferent <= 1){
                printf("%s\n", word);
            }
        }
    }
}

//Main.
int main(){
    char word[30];
    char type;
    scanf(" %s", word);
    //printf("%s\n", word);
    scanf(" %c", &type);
    if (type == 'a'){
        searchLines(word);
    }
    else if (type == 'b'){
        searchwords(word);
    }
    else{
        printf("invalid input\n");
    }
}