#include <stdio.h>

void leerentrada (int i);
void escribirsalida (int i);

struct fecha 
{
    int mes;
    int dia;
    int anio;
};

struct cuenta 
{
    char nombre [50];
    char calle[50];
    char ciudad[50];
    int Duro_cuenta;
    int tipo_cuenta;
    int num_cuenta;

    float anteriorsaldo;
    float nuevosaldo;
    float pago;
    struct fecha ultimopago;
} cliente [100];

main()
{
    int i, n;
    printf (" SISTEMA DE FACTURACION DE CLIENTES\n\n" );
    printf ("¿Cuantos clientes hay? ");
    scanf ("%d", &n);

    for (i = 0; i < n; ++i)
    {
        leerentrada(i);
        /* determinar el estado de la cuenta */
        if (cliente[i].pago > 0)
            cliente [i].tipo_cuenta =
                (cliente[i].pago < 0.1 * cliente[i].anteriorsaldo) ? 'R': 'A';

        else 
            cliente [i].tipo_cuenta =
            (cliente[i].anteriorsaldo > 0) ? 'D' : 'A';

        cliente[i].nuevosaldo = cliente[i].anteriorsaldo - cliente [i] .pago;
    }

    for (i = 0; i < n; ++i) 
    escribirsa1ida(i);
}

    void leerentrada(int i)
      /* leer datos de entrada y actualizar el registro para cada cliente */
    {
        printf (" \nC1iente nº %d\n", i + 1);
        printf ("   Nombre: ");
        scanf ("   %[^\n]", cliente [i] .nombre); 
        printf ("   Calle:  ");
        scanf("    %[^\n]", cliente[i].calle);
        printf ("   Ciudad: ");
        scanf ("   %[^\n]", cliente [i].ciudad);
        printf ("   Número de cuenta:  ");
        scanf ("%d",    &cliente[i].num_cuenta);
        printf ("   Saldo anterior:  ");    
        scanf ("%f",    &cliente[i].anteriorsaldo);
        printf ("   Pago actual:  ");
        scanf("%f",     &cliente[i].pago);
        printf ("   Fecha de pago (rnm/dd/aaaa):  ");
        scanf ( "%d/%d/%d" ,&cliente[i].ultimopago.mes, 
                            &cliente[i].ultimopago.dia, 
                            &cliente[i] .ultimopago.anio);
        return;
    }