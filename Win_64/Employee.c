#include "Employee.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>



Employee* employee_new()
{
    Employee* pEmployee;
    pEmployee =  (Employee*)calloc(sizeof(Employee), 1);
    return pEmployee;
}

Employee* employee_newParameters(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{

    Employee* auxiliarEmpleado = employee_new();

    if( auxiliarEmpleado != NULL )
    {
        int id = atoi(idStr);
        employee_setId(auxiliarEmpleado, id);

        int horasTrabajadas = atoi(horasTrabajadasStr);
        employee_setHorasTrabajadas(auxiliarEmpleado, horasTrabajadas);

        int sueldo = atoi(sueldoStr);
        employee_setSueldo(auxiliarEmpleado, sueldo);


        employee_setNombre(auxiliarEmpleado, nombreStr);
    }
    return auxiliarEmpleado;


    return 0;
}

void employee_delete(Employee* this)
{
    if(this!=NULL)
        free(this);
}

//Setters y Getters

int employee_setId(Employee* this,int id)
{
    int retorno = 0;
    if(this!=NULL)
    {
        if(id>0)
        {
            this->id = id;
            retorno = 1;
        }
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre) ///MODIFICAR
{
    int retorno = 0;
    if(this!=NULL  && strlen(nombre) != 0)
    {
        strcpy( this->nombre, nombre );
        retorno = 1;
    }
    return retorno;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = 0;
    if(this!=NULL)
    {
        if(horasTrabajadas > 0 || horasTrabajadas <24)
        {
            this->horasTrabajadas = horasTrabajadas;
            retorno = 1;
        }
    }
    return retorno;
}



int employee_setSueldo(Employee* this, int sueldo)
{
    int retorno = 0;
    if(this!=NULL)
    {
        if(sueldo > 1000 || sueldo <90000)
        {
            this->sueldo = sueldo;
            retorno = 1;
        }
    }
    return retorno;
}



int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = 0;
    if(this!=NULL)
    {
        strcpy ( nombre, this->nombre); //
        retorno = 1;
    }
    return retorno;
}




int employee_getId(Employee* this,int* id)
{
    int retorno = 0;
    if(this!=NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = 0;
    if(this!=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}



int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = 0;
    if(this!=NULL)
    {
        *sueldo = this->sueldo;
        retorno = 1;
    }
    return retorno;
}


int employee_sortById(void* employeeA,void* employeeB)
{
    Employee * empA;
    Employee * empB;
    int ret;

    if((employeeA != NULL)&&(employeeB !=NULL))
    {
        empA = (Employee*)employeeA;
        empB = (Employee*)employeeB;

        if(empA->id > empB->id)
        {
            ret = -1;
        }
        else if(empA->id == empB->id)
        {
            ret = 1;
        }
        else
        {
            ret = 0;
        }
    }
    return ret;

}

int employee_SortByName(void* employeeA,void* employeeB)
{
    Employee * empA;
    Employee * empB;
    int ret;

    if((employeeA != NULL)&&(employeeB !=NULL))
    {
        empA = (Employee*)employeeA;
        empB = (Employee*)employeeB;
        ret = strcmp(empB->nombre, empA->nombre);

}
    return ret;

}

int employee_SortByhoursWorked(void* employeeA,void* employeeB)
{

    Employee * empA;
    Employee * empB;
    int ret;

    if((employeeA != NULL)&&(employeeB !=NULL))
    {
        empA = (Employee*)employeeA;
        empB = (Employee*)employeeB;

        if(empA->horasTrabajadas > empB->horasTrabajadas)
        {
            ret = -1;
        }
        else if(empA->horasTrabajadas == empB->horasTrabajadas)
        {
            ret = 1;
        }
        else
        {
            ret = 0;
        }
    }
    return ret;

}

int employee_SortBySalary(void* employeeA,void* employeeB)
{

    Employee * empA;
    Employee * empB;
    int ret;

    if((employeeA != NULL)&&(employeeB !=NULL))
    {
        empA = (Employee*)employeeA;
        empB = (Employee*)employeeB;

        if(empA->sueldo > empB->sueldo)
        {
            ret = -1;
        }
        else if(empA->sueldo == empB->sueldo)
        {
            ret = 1;
        }
        else
        {
            ret = 0;
        }
    }
    return ret;

}
