#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int pedirOpcionMenu()
{
    int opcion;
    printf("                          A B M                  \n\n");
    printf(" 1. Cargar datos desde archivos(modo texto)  \n 2. Cargar datos desde archivos(modo binario)  \n 3. ALTA\n 4. MODIFICACION\n 5. BAJA\n 6. LISTAR\n 7. ORDENAR\n 8. Guardar datos en archivos(modo texto)\n 9. Guardar datos en archivos(modo binario)\n 10. SALIR\n" );
    scanf("%d", &opcion);

    return opcion;

}
int getOptionModify()
{
    int optionModify;
    printf("%s","             MODIFICACION            \n");
    printf("%10s - %10s - %10s - %10s \n", "1.Nombre", "2.Horas trabajadas","3.Salario","4.Salir");
    scanf("%d", &optionModify);

    return optionModify;
}

int getOptionSort()
{
    int optionSort;
    printf("%s","           INFORMES                 \n");
    printf("%10s\n%10s\n%10s\n%10s\n", "1.Empleados ordenados por ID", "2.Empleados ordenados por nombre","3.Empleados ordenados por horas trabajadas", "4.Empleados ordenados por salario" );
    scanf("%d", &optionSort);

    return optionSort;
}
