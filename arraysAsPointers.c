#include<stdio.h>

void changeLetter(char inputStr[20]){
    inputStr[1]='a';
}

int main(){
    char myString[20] = "Hello World!";

    changeLetter(myString);

    printf("%s",myString);

    return 0;
}
