#include <stdio.h>
#include <string.h>

int main() {
    char str[] = {" { int b; b = 1; { int a; a = 2; do a = a+1; while (a < 100); }"};
    //read string str character by character
    //if delimiter process current token
    //if not delimiter add current cahracter to currnet token
    //
    //processing token
    //find which token it is 1-31 from token table
    //print it
    //if it's not a valid token print error
    return 0;
}
