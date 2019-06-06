#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "funcionesGet.h"
#include "parser.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
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

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
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
        }
        if( newEmployees->id != auxIntID)
        {
            printf("ingrese nombre");
            scanf("%s", nameAux);

            printf("ingrese horas");
            scanf("%s", hoursWorkedAux);

            printf("ingrese salario");
            scanf("%s", salaryAux);



            newEmployees = employee_newParameters(idAux, nameAux, hoursWorkedAux, salaryAux);
            ll_add(pArrayListEmployee, newEmployees);
            ret = 0;
        }
    }

    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
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

/** \brief Ordenar empleados
*
* \param path char*
* \param pArrayListEmployee LinkedList*
* \return int
*
*/
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

