#include <iostream>
#include <cstring> 
using namespace std;
/* ---------------------PROYECTO GESTOR DE TAREAS  -----------------------*/


// ---------------- Estructura de datos -----------------
struct Tarea {
    int ID_tarea;
    char Titulo[20];
    char Contexto[200];
    char Curso[20];
    char Fecha_Limite[15];
    char Nivel_Dificultad[10];
    char Nivel_Prioridad[10];
    char Estado[15];
    char Tipo_Tarea[20];
};

// Arreglo para almacenar hasta 100 tareas
Tarea listaTareas[150];
int totalTareas = 0; // Contador de tareas almacenadas en el array

// --------- llamada a las funciones para su correcta lectura del conpilardor---------
//-----------para que las funciones debajo del ejecutor se pueddn utilizar correctamente---
void menuPrincipal();
void agregarTarea();

// ---------------- Función principal ------------------

int main(int argc, char** argv) {
	menuPrincipal();
	return 0;
}
// ----------------- Menú principal --------------------
void menuPrincipal() {
    int opcion;

    do {
        cout << "\n========= MENU PRINCIPAL =========\n";
        cout << "[1] Agregar nueva tarea\n";
        cout << "[2] Modificar una tarea\n";
        cout << "[3] Mostrar tareas\n";
        cout << "[4] Eliminar tarea\n";
        cout << "[5] Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar buffer

        switch (opcion) {
            case 1:
                agregarTarea();
                break;
            case 2:
                cout << ">> Modificar tarea \n";
                break;
            case 3:
                cout << ">> Mostrar tareas \n";
                break;
            case 4:
                cout << ">> Eliminar tarea \n";
                break;
            case 5:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
        }
    } while (opcion != 5);
}

// ----------------- Submenú: Agregar tarea -----------------
void agregarTarea() {
    int cantidad;
    cout << "\n>> Cuantas tareas desea agregar: ";
    cin >> cantidad;
    cin.ignore(); // limpiamos la memoria para evitar errores 

    for (int i = 0; i < cantidad; i++) {
        cout << "\n--- Registrando tarea " << i + 1 << " ---\n";

        cout << "[1] Ingrese ID de la tarea: ";
        cin >> listaTareas[totalTareas].ID_tarea;
        cin.ignore();

        cout << "[2] Ingrese titulo de la tarea: ";
        cin.getline(listaTareas[totalTareas].Titulo, 20); //ingresamos  al array lista tareas en la posicion [Total tareas] que es el contador del array y le damos un limite.

        cout << "[3] Ingrese contexto o descripcion: ";
        cin.getline(listaTareas[totalTareas].Contexto, 200);

        cout << "[4] Ingrese curso correspondiente: ";
        cin.getline(listaTareas[totalTareas].Curso, 20);

        cout << "[5] Ingrese fecha limite (DD/MM/AAAA): ";
        cin.getline(listaTareas[totalTareas].Fecha_Limite, 15);

        cout << "[6] Ingrese nivel de dificultad (Baja/Media/Alta): ";
        cin.getline(listaTareas[totalTareas].Nivel_Dificultad, 10);

        cout << "[7] Ingrese nivel de prioridad (Baja/Media/Alta): ";
        cin.getline(listaTareas[totalTareas].Nivel_Prioridad, 10);

        cout << "[8] Ingrese estado de la tarea (Pendiente/En proceso/Completada): ";
        cin.getline(listaTareas[totalTareas].Estado, 15);

        cout << "[9] Ingrese tipo de tarea (Tarea/Proyecto/Exposicion/Otro): ";
        cin.getline(listaTareas[totalTareas].Tipo_Tarea, 20);

        totalTareas++; // Aumentar el contador de tareas almacenadas
    }

    cout << "\n>> Tareas agregadas correctamente.\n";
}


