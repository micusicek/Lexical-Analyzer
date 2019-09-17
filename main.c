#include <stdio.h>
#include <string.h>

int main() {
    char str[] = {" { int b; b = 1; { int a; a = 2; do a = a+1; while (a < 100); }"};

    char *tkn;
    tkn = strtok (str," ");
    while (tkn != NULL) {
        printf ("%s", tkn);
        
        if(!strcmp(tkn, "int")){
            printf(" - BASE_TYPE");
        }

        if(!strcmp(tkn, "do")){
            printf(" - DO");
        }

        if(!strcmp(tkn, "while")){
            printf(" - WHILE");
        }

        





        
        
    
        tkn = strtok (NULL, " ");
        printf("\n");
    }


    return 0;
}