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
    else if (strcmp(c, "else") == 0){
        printf(" - ELSE");
    }
    else if (strcmp(c, "break") == 0){
        printf(" - BREAK");
    }
    else if (strcmp(c, "false") == 0){
        printf(" - FALSE");
    }
    else if (strcmp(c, "for") == 0){
        printf(" - FOR");
    }
    else if (strcmp(c, "if") == 0){
        printf(" - IF");
    }
    else if (strcmp(c, "true") == 0){
        printf(" - TRUE");
    }
    else{
        printf(" - ID");
    }
}

void isreal(char c[]){

    for (int i = 0; i < strlen(c); i++)
    {
        if(c[i] == '.'){
            printf(" - REAL");
            return ;
        }
    }
    printf(" - NUM");
    return ;
    
}


int main() {
    char str[500];
    
    char token[15];
    char clear[15];
    char filename[] = "example.txt";
    FILE *file;
    int tkni = 0, i = 0;
    char c;
   
    printf(" file name: ");
    gets(filename);

    file = fopen(filename, "r");
    int z = 0;
    while((c = fgetc(file)) != EOF ){
        str[z] = c;
        z++;
    }



    printf("-----start-----\n");
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
                printf("%s", token);
                tkni = 0;
                
                //call function to reconignize identifier
                if(isalpha(token[0])){
                    alphadefinition(token);
                }
                if(isdigit(token[0])){
                    isreal(token);
                    // printf(" - NUM");
                }
                memset(token, 0, sizeof(token));
                printf("\n");
            }
        }
    }
    printf("\n-----end-----\n");

    return 0;
}