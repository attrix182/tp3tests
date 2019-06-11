#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Crea un espacio en memoria dinamica para guardar un empleado
 *
 * \return Employee*
 *
 */
Employee* employee_new();

/** \brief Crea empleados con parametros dados, que deber ser casteados
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParameters(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/** \brief Libera el espacio de un empleado dado de baja
 *
 * \param this Employee*
 * \return void
 *
 */
void employee_delete(Employee* this);


    // Setters y Getters

/** \brief Valida id
 *
 * \param this Employee* Puntero del array de empleados
 * \param id int recibe un id
 * \return int es 1 si esta bien,  0 si esta mal
 *
 */
int employee_setId(Employee* this,int id);

/** \brief
 *
 * \param this Employee* Puntero del array de empleados
 * \param id int* id recibe un puntero al id
 * \return int 1 si esta bien,  0 si esta mal
 *
 */
int employee_getId(Employee* this,int* id);


/** \brief Valida el Nombre
 *
 * \param Employee* this Puntero del array de empleados
 * \param char* nombre recibe un nombre
 * \return int es 1 si esta bien,  0 si esta mal
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief Escribe el parametro del nombre
 *
 * \param Employee* this Puntero del array de empleados
 * \param char* nombre Recibe un nombre
 * \return retorno, si esta bien es 1, si esta mal es 0
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Valida las horas de trabajo
 *
 * \param Employee* this Puntero del array de empleados
 * \param int horasTrabajadas Recibe una cantidad de horas de trabajo
 * \return int 1 si esta bien,  0 si esta mal
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief Valida las horas de trabajo
 *
 * \param this Employee* Puntero del array de empleados
 * \param horasTrabajadas int* Horas de trabajo
 * \return int 1 si esta bien,  0 si esta mal
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief Valida el sueldo
 *
 * \param Employee* this Puntero del array de empleados
 * \param float sueldo Recibe una cantidad de sueldo
 * \return retorno, si esta bien es 1, si esta mal es 0
 *
 */
int employee_setSueldo(Employee* this,int sueldo);


/** \brief escribe el parametro del sueldo
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int 1 si esta bien,  0 si esta mal
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);




//Funciones SORT

/** \brief Compara a los empleados por ID
 *
 * \param employeeA void* A
 * \param employeeB void* B
 * \return int Retorna 1 si son iguales. Si A es mayor que B retorna -1. Si A es menor que B retornara 0.
 *
 */
int employee_sortById(void* employeeA, void* employeeB);

/** \brief Compara a los empleados por nombre de forma alfabetica
 *
 * \param employeeA void* A
 * \param employeeB void* B
 * \return int  Retorna 1 si son iguales. Si A es mayor que B retorna -1. Si A es menor que B retornara 0.
 *
 */
int employee_SortByName(void* employeeA,void* employeeB);

/** \brief Compara a dos empledos por horas de trabajo
 *
 * \param employeeA void* A
 * \param employeeB void* B
 * \return int Retorna 1 si son iguales. Si A es mayor que B retorna -1. Si A es menor que B retornara 0.
 *
 */
int employee_SortByhoursWorked(void* employeeA,void* employeeB);

/** \brief Compara a los empleados por Salario
 *
 * \param employeeA void* A
 * \param employeeB void* B
 * \return int Retorna 1 si son iguales. Si A es mayor que B retorna -1. Si A es menor que B retornara 0.
 *
 */
int employee_SortBySalary(void* employeeA,void* employeeB);


#endif // employee_H_INCLUDED
