#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int isDelimiter(char c){
    int delimiter = 0;
    if (c == ' '){
        return delimiter = 1;
    }
    else if (c == ';' || c == '(' || c == ')' || c == '{' || c == '}' || c == '+' || c == '-' || 
                c == '*' || c == '/' || c == '<' || c == '>' || c == '=' )
    {
        return delimiter = 1;
    }    
    else
    {
        return delimiter = 0;
    }
    
}

void alphadefinition(char c[]){
    if (strcmp(c, "int") == 0 || strcmp(c, "float") == 0 || strcmp(c, "bool") == 0 )
    {
        printf(" - BASE_TYPE");
    }
    else if (strcmp(c, "while") == 0){
        printf(" - WHILE");
    }
    else if (strcmp(c, "do") == 0){
        printf(" - DO");
    }
    else{
        printf(" - ID");
    }
}

int main() {
    char str[] = {" { int b; b = 1; { int a; a = 2; do a = a+1; while (a < 100); }"};
    char token[15];
    char clear[15];
    int tkni = 0;
    char c;
    char it[] = {"int"};
    printf("-----Começo-----\n");
    for (int i = 0; i < strlen(str); i++)
    {
        
        c = str[i];

        if(isDelimiter(c)){
            if(c != ' '){
                printf("%c   %c", c, c);
                printf("\n");
            }
        }
        else{
            token[tkni] = c;
            tkni++;
            // printf("%c",c);
            if(isDelimiter(str[i+1])){
                printf("%s", token, (int)strlen(token));
                tkni = 0;
                
                //call function to reconignize identifier
                if(isalpha(token[0])){
                    alphadefinition(token);
                }
                if(isdigit(token[0])){
                    printf(" - DIGIT");
                }
                
                

                

                memset(token, 0, sizeof(token));
                printf("\n");
            }
        }
    }
    printf("\n-----Fim-----\n");



    return 0;
}