/*contar el número de vocales, consonantes, dígitos, espacios en blanco y "otros" caracteres en una linea de texto*/
#include <stdio.h>
#include <ctype.h>

/*Prototipo de la funcion*/
void analiza_linea(char linea[], int *pv, int *pc, int *pd, int *pb, int *po);

main ()
{
    char linea [80];         /*Linea de texto*/
    int vocales = 0;         /*Contador de vocales*/
    int consonantes = 0;     /*Contador de consonantes*/
    int digitos = 0;        /*Contador de digitos*/
    int blancos = 0;         /*Contador de espacios en blanco*/
    int otros = 0;           /*Contador del resto de caracteres*/

    printf ("Introducir una linea de texto:\n");
    scanf("%[A\n]", linea);

    analiza_linea(linea, &vocales, &consonantes, &digitos, &blancos, &otros);
    
    printf ("\nNº de vocales: %d, vocales");
    printf ("\nNº de consonantes: %d, consonantes");
    printf ("\nNº de digitos: %d, digitos");
    printf ("\nNº de blancos: %d, blancos");
    printf ("\nNº de otros caracteres: %d, otros");
}

void analiza_linea (char linea[], int *pv, int *pc, int *pd, int *pb, int *po)
/* analizar los caracteres en una linea de texto*/
{
    char c;
    int cont = 0;
    while ((c = toupper(linea[cont])) != '\0')
    {
        if (c == ' A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            ++ *pv;
        else if (c >= 'A' && c <= 'Z')
                 ++ *pc;
            else if (c >= 'O' && c <= '9')
                    ++ *pd;
                else if (c == ' ' || c == '\t')
                        ++ *pb;
                    else
                        ++ *po;
        ++cont;
    }
    return;
}
