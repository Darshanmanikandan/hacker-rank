#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]",s);
    s = realloc(s, strlen(s) + 1);
    // check for a space in the string and replace it with the "\n" new line character 
    for (char *c = s; *(c) != '\n'; c++) {
    if (*c == ' ') {
        *c = '\n';
    }
}
printf("%s",s); // printing the string 
    return 0;
}