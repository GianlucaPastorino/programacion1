#include <stdio.h>
#include <stdlib.h>

char mytolower(char caracter);

int main()
{
    char x = 'A';
    x = mytolower(x);
    printf("%c\n", x);
    return 0;
}

char mytolower(char caracter)
{
    if(caracter>='A' && caracter<='Z')
    {
        caracter += 32; // Por ubicaci�n del c�digo ascii, a las may�suclas le tengo que sumar 32 para llegar a las min�sculas.
    }
    return caracter;
}
