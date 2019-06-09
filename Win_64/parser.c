#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee = employee_new();
    int r;
    int i = 0;
    char idAux[50],nameAux[50],hoursWorkedAux[50],salaryAux[50];

    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nameAux,hoursWorkedAux,salaryAux);
    while(!feof(pFile))
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nameAux,hoursWorkedAux,salaryAux);
            if(r==4)
            {
                auxEmployee = employee_newParameters(idAux ,nameAux, hoursWorkedAux, salaryAux);
                ll_add(pArrayListEmployee, auxEmployee );
                i++;
            }
     }
        printf("Se cargaron %d empleados a la lista con exito !\n", i);

        return i;

}



/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
*
* \param path char*
* \param pArrayListEmployee LinkedList*
* \return int
*
*/
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee employeeAux;
    int i = 0;

    fread(&employeeAux, sizeof(Employee), 1, pFile);

    while(!feof(pFile))
    {
        Employee *employeeNew = employee_new();
        employee_setId(employeeNew,employeeAux.id);
        employee_setHorasTrabajadas(employeeNew,employeeAux.horasTrabajadas);
        employee_setNombre(employeeNew,employeeAux.nombre);
        employee_setSueldo(employeeNew,employeeAux.sueldo);
        i ++;
        ll_add(pArrayListEmployee, employeeNew);
        fread(&employeeAux, sizeof(Employee), 1, pFile);
    }
    return 1;
}
