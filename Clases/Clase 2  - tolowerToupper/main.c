#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Incluyo la librer�a/biblioteca donde est� tolower y toupper

int main()
{
    char x = 'A';
    char y = 'b';

    x = tolower(x); // Pasar a minuscula
    y = toupper(y); // Pasar a mayuscula

    printf("%c\n", x);
    printf("%C\n", y);

    return 0;
}
