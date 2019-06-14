#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "funcionesGet.h"

int pedirOpcionMenu()
{
    int opcion;
    printf("                          A B M                  \n\n");
    printf(" 1. Cargar datos desde archivos(modo texto)  \n 2. Cargar datos desde archivos(modo binario)  \n 3. ALTA\n 4. MODIFICACION\n 5. BAJA\n 6. LISTAR\n 7. ORDENAR\n 8. Guardar datos en archivos(modo texto)\n 9. Guardar datos en archivos(modo binario)\n 10. SALIR\n" );
    opcion = getInt("");

    return opcion;

}
int getOptionModify()
{
    int optionModify;
    printf("%s","             MODIFICACION            \n");
    printf("%10s - %10s - %10s - %10s \n", "1.Nombre", "2.Horas trabajadas","3.Salario","4.Salir");
    optionModify = getInt("");

    return optionModify;
}

int getOptionSort()
{
    int optionSort;
    printf("%s","           INFORMES                 \n");
    printf("%10s\n%10s\n%10s\n%10s\n", "1.Empleados ordenados por ID", "2.Empleados ordenados por nombre","3.Empleados ordenados por horas trabajadas", "4.Empleados ordenados por salario" );
    optionSort = getInt("");

    return optionSort;
}

int getDireccion()
{

    int optionDireccion;
    printf("%s","           SENTIDO                 \n");
    printf("%s %s %s\n", "1.Ascendente", "2.Descendente","3.Salir" );

    do
    {

        optionDireccion = getInt("");

        switch(optionDireccion)
        {
        case 1:
            optionDireccion = 1;
            break;
        case 2:
            optionDireccion = 0;
            break;
        case 3:
            optionDireccion = 3;
        default:
            printf("Opcion invalida\n");
            break;
        }
        return optionDireccion;
    }
    while(optionDireccion != 3);


}

