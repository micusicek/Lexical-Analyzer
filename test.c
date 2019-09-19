#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int isDelimiter(char c){
/*
    Idetify if charecter read is considered a delimiter.
    If yes, returns 1 (true);
    If no , returns 0 (false)
*/
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
/*
    Definition of all the possible outcomes involving letters
    Each 'if statements' compares variable 'c' with a possible symbolic pattern,
    If pattern is found, it will print the token name,
    Otherwise, prints 'ID' 
*/
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
/*
    Reads variable 'c' and looks for a '.' (dot)
    If found, 'c' is a float number, therefore prints '- REAL'
    If not, prints '- NUM'
*/
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


int checkfuture(char c, char d){
    if((c == '=') && (d == '=')){
        printf("%c%c - EQUAL\n", c, d);
        return 1;
    }
    if((c == '&') && (d == '&')){
        printf("%c%c - AND\n", c, d);
        return 1;
    }
    if((c == '>') && (d == '=')){
        printf("%c%c - GE\n", c, d);
        return 1;
    }
    if((c == '<') && (d == '=')){
        printf("%c%c - LE\n", c, d);
        return 1;
    }
    if((c == '!') && (d == '=')){
        printf("%c%c - NE\n", c, d);
        return 1;
    }
    if((c == '|') && (d == '|')){
        printf("%c%c - OR\n", c, d);
        return 1;
    }
    return 0;
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
        if(c != '\n'){
            // quickfix for breakline making output ugly. 
            // program does nothing if 'c' is '\n'


            if(checkfuture(c, str[i+1])){
                i++;
            }
            else{
                if(isDelimiter(c)){
                    //if 'c' is a delimiter, prints the delimiter
                    //avoids printing white spaces, in order to look cleaner
                    if(c != ' '){
                        printf("%c   %c", c, c);
                        printf("\n");
                    }
                    
                }
                else{
                //if 'c' is not reconigzed as delimiter, adds to string 'token', untill the future character is delimiter
                //once future character delimiter, prints token
                token[tkni] = c;
                tkni++;
                // printf("%c",c);
                if(isDelimiter(str[i+1])){
                    printf("%s", token);
                    tkni = 0;
                    
                    //call function to reconignize identifier
                    if(isalpha(token[0])){
                        //define which token name use if variable token is not a number
                        alphadefinition(token);
                    }
                    if(isdigit(token[0])){
                        //define which token name use if variable token is a number
                        isreal(token);
                    }
                    memset(token, 0, sizeof(token)); //clean variable token, to be ready for next use.
                    printf("\n");
                }
            }
            }        

        }
    }
    printf("\n-----end-----\n");

    return 0;
}