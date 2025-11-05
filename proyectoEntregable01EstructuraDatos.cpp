#include <iostream>
using namespace std;

// ==================== ESTRUCTURA PRINCIPAL ====================
struct Tarea {
    int id;
    string titulo;
    string descripcion;
    string curso;
    string fechaLimite;
    string dificultad;
    string prioridad;
    string estado;
    string tipo;
    Tarea *siguiente;

    // Constructor
    Tarea(int id_, string t, string desc, string c, string f, string d, string p, string e, string tp) {
        id = id_;
        titulo = t;
        descripcion = desc;
        curso = c;
        fechaLimite = f;
        dificultad = d;
        prioridad = p;
        estado = e;
        tipo = tp;
        siguiente = NULL;
    }
};

// ==================== FUNCIONES PRINCIPALES ====================

// Agregar una nueva tarea
void agregarTarea(Tarea *&inicio) {
    int cantidad;
    cout << "\n> Cuantas tareas desea agregar: ";
    cin >> cantidad;
    cin.ignore();

    for (int i = 0; i < cantidad; i++) {
        int id;
        string titulo, descripcion, curso, fecha, dificultad, prioridad, estado, tipo;

        cout << "\n[1] Ingrese ID de la tarea: ";
        cin >> id;
        cin.ignore();
        cout << "[2] Ingrese titulo de la tarea: ";
        getline(cin, titulo);
        cout << "[3] Ingrese contexto o descripcion: ";
        getline(cin, descripcion);
        cout << "[4] Ingrese curso correspondiente: ";
        getline(cin, curso);
        cout << "[5] Ingrese fecha limite (DD/MM/AAAA): ";
        getline(cin, fecha);
        cout << "[6] Ingrese nivel de dificultad (Baja / Media / Alta): ";
        getline(cin, dificultad);
        cout << "[7] Ingrese nivel de prioridad (Baja / Media / Alta): ";
        getline(cin, prioridad);
        cout << "[8] Ingrese estado de la tarea (Pendiente / En proceso / Completada): ";
        getline(cin, estado);
        cout << "[9] Ingrese tipo de tarea (Tarea / Proyecto / Exposicion / Otro): ";
        getline(cin, tipo);

        Tarea *nueva = new Tarea(id, titulo, descripcion, curso, fecha, dificultad, prioridad, estado, tipo);

        if (inicio == NULL) {
            inicio = nueva;
        } else {
            Tarea *temp = inicio;
            while (temp->siguiente != NULL) {
                temp = temp->siguiente;
            }
            temp->siguiente = nueva;
        }

        cout << "\nTarea agregada exitosamente.\n";
    }
}

// Modificar una tarea existente
void modificarTarea(Tarea *inicio) {
    if (inicio == NULL) {
        cout << "\nNo existen tareas registradas.\n";
        return;
    }

    int id;
    cout << "\n> Ingrese el ID de la tarea a modificar: ";
    cin >> id;
    cin.ignore();

    Tarea *temp = inicio;
    while (temp != NULL && temp->id != id) {
        temp = temp->siguiente;
    }

    if (temp == NULL) {
        cout << "\nNo se encontro una tarea con ese ID.\n";
        return;
    }

    int opcion;
    do {
        cout << "\n> Que desea modificar:\n";
        cout << "[1] Titulo\n[2] Contexto o descripcion\n[3] Curso\n[4] Fecha limite\n";
        cout << "[5] Nivel de dificultad\n[6] Nivel de prioridad\n[7] Estado\n[8] Tipo de tarea\n";
        cout << "[9] Modificar todos los campos\n[10] Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: cout << "Nuevo titulo: "; getline(cin, temp->titulo); break;
            case 2: cout << "Nueva descripcion: "; getline(cin, temp->descripcion); break;
            case 3: cout << "Nuevo curso: "; getline(cin, temp->curso); break;
            case 4: cout << "Nueva fecha limite: "; getline(cin, temp->fechaLimite); break;
            case 5: cout << "Nueva dificultad: "; getline(cin, temp->dificultad); break;
            case 6: cout << "Nueva prioridad: "; getline(cin, temp->prioridad); break;
            case 7: cout << "Nuevo estado: "; getline(cin, temp->estado); break;
            case 8: cout << "Nuevo tipo: "; getline(cin, temp->tipo); break;
            case 9:
                cout << "Titulo: "; getline(cin, temp->titulo);
                cout << "Descripcion: "; getline(cin, temp->descripcion);
                cout << "Curso: "; getline(cin, temp->curso);
                cout << "Fecha limite: "; getline(cin, temp->fechaLimite);
                cout << "Dificultad: "; getline(cin, temp->dificultad);
                cout << "Prioridad: "; getline(cin, temp->prioridad);
                cout << "Estado: "; getline(cin, temp->estado);
                cout << "Tipo: "; getline(cin, temp->tipo);
                break;
            case 10:
                cout << "Regresando al menu principal...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 10);
}

// Mostrar tareas (con subopciones)
void mostrarTareas(Tarea *inicio) {
    if (inicio == NULL) {
        cout << "\nNo existen tareas registradas.\n";
        return;
    }

    int opcion;
    do {
        cout << "\n> Como desea ver las tareas:\n";
        cout << "[1] Mostrar todas\n[2] Por curso\n[3] Por prioridad\n[4] Por dificultad\n";
        cout << "[5] Por estado\n[6] Por tipo\n[7] Volver al menu principal\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        string filtro;
        Tarea *temp = inicio;
        bool encontrado = false;

        switch (opcion) {
            case 1:
                while (temp != NULL) {
                    cout << "\nID: " << temp->id
                         << "\nTitulo: " << temp->titulo
                         << "\nDescripcion: " << temp->descripcion
                         << "\nCurso: " << temp->curso
                         << "\nFecha: " << temp->fechaLimite
                         << "\nDificultad: " << temp->dificultad
                         << "\nPrioridad: " << temp->prioridad
                         << "\nEstado: " << temp->estado
                         << "\nTipo: " << temp->tipo << endl;
                    cout << "--------------------------\n";
                    temp = temp->siguiente;
                }
                break;

            case 2:
                cout << "Ingrese curso: "; getline(cin, filtro);
                while (temp != NULL) {
                    if (temp->curso == filtro) {
                        cout << temp->titulo << " (" << temp->curso << ")\n";
                        encontrado = true;
                    }
                    temp = temp->siguiente;
                }
                if (!encontrado) cout << "No hay tareas de ese curso.\n";
                break;

            case 3:
                cout << "Ingrese prioridad: "; getline(cin, filtro);
                while (temp != NULL) {
                    if (temp->prioridad == filtro) {
                        cout << temp->titulo << " (" << temp->prioridad << ")\n";
                        encontrado = true;
                    }
                    temp = temp->siguiente;
                }
                if (!encontrado) cout << "No hay tareas con esa prioridad.\n";
                break;

            case 4:
                cout << "Ingrese dificultad: "; getline(cin, filtro);
                while (temp != NULL) {
                    if (temp->dificultad == filtro) {
                        cout << temp->titulo << " (" << temp->dificultad << ")\n";
                        encontrado = true;
                    }
                    temp = temp->siguiente;
                }
                if (!encontrado) cout << "No hay tareas con esa dificultad.\n";
                break;

            case 5:
                cout << "Ingrese estado: "; getline(cin, filtro);
                while (temp != NULL) {
                    if (temp->estado == filtro) {
                        cout << temp->titulo << " (" << temp->estado << ")\n";
                        encontrado = true;
                    }
                    temp = temp->siguiente;
                }
                if (!encontrado) cout << "No hay tareas con ese estado.\n";
                break;

            case 6:
                cout << "Ingrese tipo: "; getline(cin, filtro);
                while (temp != NULL) {
                    if (temp->tipo == filtro) {
                        cout << temp->titulo << " (" << temp->tipo << ")\n";
                        encontrado = true;
                    }
                    temp = temp->siguiente;
                }
                if (!encontrado) cout << "No hay tareas de ese tipo.\n";
                break;

            case 7:
                cout << "Volviendo al menu principal...\n";
                break;

            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 7);
}

// Eliminar tarea
void eliminarTarea(Tarea *&inicio) {
    if (inicio == NULL) {
        cout << "\nNo existen tareas para eliminar.\n";
        return;
    }

    int id;
    cout << "\n> Ingrese el ID de la tarea a eliminar: ";
    cin >> id;
    cin.ignore();

    Tarea *temp = inicio;
    Tarea *anterior = NULL;

    while (temp != NULL && temp->id != id) {
        anterior = temp;
        temp = temp->siguiente;
    }

    if (temp == NULL) {
        cout << "\nNo se encontro una tarea con ese ID.\n";
        return;
    }

    int confirmacion;
    cout << "\n¿Esta seguro que desea eliminar esta tarea?\n";
    cout << "[1] Si, eliminar\n[2] No, cancelar\nOpcion: ";
    cin >> confirmacion;
    cin.ignore();

    if (confirmacion == 1) {
        if (anterior == NULL) inicio = inicio->siguiente;
        else anterior->siguiente = temp->siguiente;

        delete temp;
        cout << "\nTarea eliminada correctamente.\n";
    } else {
        cout << "\nOperacion cancelada.\n";
    }
}

// ==================== FUNCION PRINCIPAL ====================
int main() {
    Tarea *inicio = NULL;
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
        cin.ignore();

        switch (opcion) {
            case 1: agregarTarea(inicio); break;
            case 2: modificarTarea(inicio); break;
            case 3: mostrarTareas(inicio); break;
            case 4: eliminarTarea(inicio); break;
            case 5:
                cout << "\n¿Desea salir del programa?\n[1] Si\n[2] No\nOpcion: ";
                int salir;
                cin >> salir;
                if (salir == 1) {
                    cout << "\nSaliendo del programa...\n";
                    return 0;
                }
                break;
            default:
                cout << "Opcion invalida.\n";
        }

    } while (true);
}



