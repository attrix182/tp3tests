#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED


/** \brief Muestra un menu principal y recibe una opcion ingresada por el usuario
 *
 * \return int opcion ingresada
 *
 */
int pedirOpcionMenu();

/** \brief Muetra un menu para ediciones
 *
 * \return int opcion ingresada
 *
 */
int getOptionModify();

/** \brief Muetra un menu para ordenamientos
 *
 * \return int opcion ingresada
 *
 */
int getOptionSort();


int getDireccion();
#endif // MENU_H_INCLUDED
