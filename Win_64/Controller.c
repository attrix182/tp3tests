#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "funcionesGet.h"
#include "parser.h"
#include "menu.h"




int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pArchivo;

    if((pArchivo = fopen(path, "r"))==NULL)
    {
        printf("No se puedo leer\n");
        exit(1);
    }
    else
    {

        parser_EmployeeFromText(pArchivo, pArrayListEmployee);

        return 1;
    }


}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pArchivo = fopen(path, "rb");
    if(pArchivo == NULL)
    {
        printf("El archivo no se pudo cargar.\n");
        fclose(pArchivo);
        exit(1);

    }
    else
    {
        parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
        return 1;
    }

    fclose(pArchivo);

    return 1;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* newEmployees = employee_new();
    int ret = 0;
    char idAux[50],nameAux[50],hoursWorkedAux[50],salaryAux[50];
    int lenList = ll_len(pArrayListEmployee);
    int auxIntID;
    int i;

    if(pArrayListEmployee !=NULL)
    {
        auxIntID = getInt("Ingrese id del nuevo empleado \n");
        itoa(auxIntID, idAux, 10);

        for( i = 0; i <lenList ; i++ )
        {
            newEmployees = (Employee*)ll_get(pArrayListEmployee, i);
            if( newEmployees->id == auxIntID)
            {
                printf("El id que desea agregar ya existe!\n");
                break;

            }
        }

        if( newEmployees->id != auxIntID)
        {

            getString("ingrese nombre \n", nameAux);
            getString("ingrese horas trabajadas \n", hoursWorkedAux);
            getString("ingrese salario \n", salaryAux);

            newEmployees = employee_newParameters(idAux, nameAux, hoursWorkedAux, salaryAux);
            ll_add(pArrayListEmployee, newEmployees);
            ret = 0;
        }
    }

    return ret;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{

    Employee *auxEmployee;
    char nameAux[50];
    int idAuxInt;
    int salaryAuxInt;
    int hoursWorkedAuxInt;
    int option;
    int listLen = ll_len(pArrayListEmployee);
    int i;

    if(pArrayListEmployee != NULL)
    {
        idAuxInt = getInt("Ingrese el id que desea modificar:  ");
        system("cls");
        for( i = 0; i <listLen ; i++ )
        {

            auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            if( idAuxInt == auxEmployee->id )
            {
                do
                {
                    option = getOptionModify();

                    switch(option)
                    {
                    case 1:
                        getString("Ingrese nuevo nombre \n", nameAux);
                        employee_setNombre(auxEmployee, nameAux);
                        break;
                    case 2:
                        hoursWorkedAuxInt = getInt("ingrese horas trabajadas\n");
                        employee_setHorasTrabajadas(auxEmployee, hoursWorkedAuxInt);
                        break;
                    case 3:
                        salaryAuxInt = getInt("ingrese salario \n");
                        employee_setSueldo(auxEmployee, salaryAuxInt);
                        break;
                    case 4:
                        option = 4;
                        break;
                    default:
                        printf("Opcion invalida");
                        break;
                    }
                }
                while(option != 4);

            }
        }

    }
    return 1;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

    Employee* auxEmployee;
    int listLen = ll_len(pArrayListEmployee);
    int i;
    int idAux;

    if(pArrayListEmployee !=NULL)
    {
        idAux = getInt("ingrese ID  a remover");

        for(i=0; i<listLen; i++)
        {
            auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);

            if(auxEmployee->id == idAux)
            {
                ll_remove(pArrayListEmployee, i);
                printf("Empleado borrado con exito!\n");
                employee_delete(auxEmployee);
                break;
            }
        }
        if( auxEmployee->id != idAux)
        {
            printf("Ese Id no existe.\n");
        }

    }

    return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployeeAux;
    int ret = 0;
    int idAux;
    char nameAux[50];
    int hoursWorkedAux;
    int salaryAux;
    int lenList = ll_len(pArrayListEmployee);
    int i;
    if(pArrayListEmployee!=NULL)
    {
        if(lenList>0)
        {
            printf(" Id------Nombre-----Horas trabajadas---Sueldo \n");

            for(i = 0; i < lenList; i++)
            {
                pEmployeeAux = (Employee*)ll_get(pArrayListEmployee, i);
                employee_getId(pEmployeeAux, &idAux);
                employee_getNombre(pEmployeeAux,nameAux);
                employee_getHorasTrabajadas(pEmployeeAux,&hoursWorkedAux);
                employee_getSueldo(pEmployeeAux,&salaryAux);
                printf("%5d  %10s %10d  %15d\n",idAux, nameAux, hoursWorkedAux, salaryAux);
            }

            ret = 1;

        }
        else
        {
            printf("No se cargaron los datos.\n");
        }
    }
    return ret;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int option;

    if(pArrayListEmployee != NULL)
    {
        option = getOptionSort();
    }

    switch(option)
    {
    case 1:
        ll_sort(pArrayListEmployee, employee_sortById, 0);
        break;
    case 2:
        ll_sort(pArrayListEmployee, employee_SortByName, 0);
        break;
    case 3:
        ll_sort(pArrayListEmployee, employee_SortByhoursWorked, 0);
        break;
    case 4:
        ll_sort(pArrayListEmployee, employee_SortBySalary, 0);
        break;
    }



    return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

    int listLen = ll_len(pArrayListEmployee);
    Employee* pEmpleadoAux;
    FILE* pArchivo = fopen(path, "w");
    int i;
    if(pArchivo != NULL)
    {

        fprintf(pArchivo, "id,nombre,horasTrabajadas,sueldo\n");

        if(pArrayListEmployee!=NULL)
        {
            for(i = 0; i < listLen; i++)
            {
                pEmpleadoAux = (Employee*)ll_get(pArrayListEmployee, i);
                fprintf(pArchivo, "%d,%s,%d,%d\n", pEmpleadoAux->id, pEmpleadoAux->nombre, pEmpleadoAux->horasTrabajadas, pEmpleadoAux->sueldo);
            }
            printf("Archivo guardado con exito\n");
        }
        fclose(pArchivo);
        return 1;
    }
    else
    {
        printf("Error al abrir archivo\n");
        return 0;
    }
    return 1;
}




int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    Employee* pEmployeeAux;
    FILE* pArchivo = fopen(path, "wb");

    int listLen = ll_len(pArrayListEmployee);
    int i;

    if(pArchivo == NULL)
    {

        printf("Error al guardar\n");
        return 0;
    }

    if(pArrayListEmployee!=NULL)
    {
        for(i = 0; i < listLen; i++)
        {
            pEmployeeAux = (Employee*)ll_get(pArrayListEmployee, i);
            fwrite(pEmployeeAux,sizeof(Employee), 1, pArchivo);
        }
        printf("Archivo .bin guardado\n");
    }
    fclose(pArchivo);
    return 1;

}

