#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int flag1 = 0;
    int flag2 = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        option = pedirOpcionMenu();

        switch(option)
        {
        case 1:
            if(flag1 == 0 && flag2 !=1)
            {
                controller_loadFromText("data.csv",listaEmpleados);

                flag1 = 1;
            }
            else
            {
                printf("Error. Ya se cargaron los datos.\n");
            }
            system("pause");
            break;
        case 2:
            if(flag2 == 0 && flag1 !=1)
            {

                controller_loadFromBinary("data.bin", listaEmpleados);
                flag2 = 1;
            }
            else
            {
                printf("Error. Ya se cargaron los datos.\n");
            }
            system("pause");
            break;
        case 3:
            if(flag1 == 1 || flag2 == 1)
            {
                controller_addEmployee(listaEmpleados);
            }
            else
            {
                printf("No ha cargado los datos aun \n");
            }
            system("pause");
            break;
        case 4:
            if( flag1 == 1 || flag2 == 1)
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay datos que mostrar\n");
            }
            system("pause");
            break;
        case 5:
            if( flag1 == 1 || flag2 == 1)
            {
                controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay datos para eliminar\n");
            }
            system("pause");
            break;
        case 6:
            if( flag1 == 1 || flag2 == 1)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay datos que listar\n");
            }
            system("pause");
            break;;
        case 7:
            if( flag1 == 1 || flag2 == 1)
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay datos que ordenar\n");
            }
            system("pause");
            break;;
        case 8:
            if(flag1 == 1|| flag2 == 1)
            {
                controller_saveAsText("data.csv",listaEmpleados);
            }
            else
            {
                printf("No hay datos que guardar\n");
            }
            system("pause");
            break;
        case 9:
            if(flag1 == 1|| flag2 == 1)
            {
                controller_saveAsBinary("data.bin",listaEmpleados);
            }
            else
            {
                printf("No hay datos que guardar\n");
            }
            system("pause");
            break;
        case 10:
            option = 10;
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }

        system("cls");
    }
    while(option != 10);
    return 0;
}
