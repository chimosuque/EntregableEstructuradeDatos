#include <iostream>
using namespace std;

struct Tarea {
    int ID_tarea;
    string titulo;
    string contexto;
    string curso;
    string fecha_limite;
    string nivel_dificultad;
    string nivel_prioridad;
    string estado;
    string tipo_tarea;
    Tarea *siguiente;

    Tarea(int id, string t, string cxt, string cur, string fecha,
          string dif, string pri, string est, string tipo) {
        ID_tarea = id;
        titulo = t;
        contexto = cxt;
        curso = cur;
        fecha_limite = fecha;
        nivel_dificultad = dif;
        nivel_prioridad = pri;
        estado = est;
        tipo_tarea = tipo;
        siguiente = NULL;
    }
};

// Agregar una nueva tarea al final de la lista
void agregarTarea(Tarea *&inicio, int id, string t, string cxt, string cur, string fecha,
                  string dif, string pri, string est, string tipo) {
    Tarea *nueva = new Tarea(id, t, cxt, cur, fecha, dif, pri, est, tipo);
    if (inicio == NULL) {
        inicio = nueva;
    } else {
        Tarea *temp = inicio;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nueva;
    }
    cout << "\nTarea agregada correctamente.\n";
}

// Mostrar todas las tareas
void mostrarTareas(Tarea *inicio) {
    if (inicio == NULL) {
        cout << "\nNo hay tareas registradas.\n";
        return;
    }

    cout << "\n--- LISTA DE TAREAS REGISTRADAS ---\n";
    Tarea *temp = inicio;
    while (temp != NULL) {
        cout << "ID: " << temp->ID_tarea << endl;
        cout << "Título: " << temp->titulo << endl;
        cout << "Contexto: " << temp->contexto << endl;
        cout << "Curso: " << temp->curso << endl;
        cout << "Fecha Límite: " << temp->fecha_limite << endl;
        cout << "Dificultad: " << temp->nivel_dificultad << endl;
        cout << "Prioridad: " << temp->nivel_prioridad << endl;
        cout << "Estado: " << temp->estado << endl;
        cout << "Tipo: " << temp->tipo_tarea << endl;
        cout << "-----------------------------------\n";
        temp = temp->siguiente;
    }
}

// Buscar una tarea por ID
void buscarTarea(Tarea *inicio, int idBuscado) {
    Tarea *temp = inicio;
    bool encontrado = false;

    while (temp != NULL) {
        if (temp->ID_tarea == idBuscado) {
            cout << "\nTarea encontrada:\n";
            cout << "Título: " << temp->titulo << endl;
            cout << "Curso: " << temp->curso << endl;
            cout << "Estado: " << temp->estado << endl;
            cout << "Prioridad: " << temp->nivel_prioridad << endl;
            cout << "Fecha límite: " << temp->fecha_limite << endl;
            encontrado = true;
            break;
        }
        temp = temp->siguiente;
    }

    if (!encontrado) {
        cout << "\nNo se encontró una tarea con el ID " << idBuscado << ".\n";
    }
}

// Eliminar tarea por ID
void eliminarTarea(Tarea *&inicio, int idEliminar) {
    if (inicio == NULL) {
        cout << "\nNo hay tareas para eliminar.\n";
        return;
    }

    Tarea *temp = inicio;
    Tarea *anterior = NULL;

    while (temp != NULL && temp->ID_tarea != idEliminar) {
        anterior = temp;
        temp = temp->siguiente;
    }

    if (temp == NULL) {
        cout << "\nNo se encontró la tarea con ID " << idEliminar << ".\n";
    } else {
        if (anterior == NULL) {
            inicio = inicio->siguiente;
        } else {
            anterior->siguiente = temp->siguiente;
        }
        delete temp;
        cout << "\nTarea eliminada correctamente.\n";
    }
}

int main() {
	setlocale(LC_CTYPE,"Spanish");//permite ingresar ñ y tildes en windows
    Tarea *inicio = NULL;
    int opcion, id;
    string titulo, contexto, curso, fecha, dificultad, prioridad, estado, tipo;

    do {
        cout << "\n--- MENU PRINCIPAL DEL GESTOR DE TAREAS ---\n";
        cout << "1. Agregar nueva tarea\n";
        cout << "2. Mostrar tareas\n";
        cout << "3. Buscar tarea por ID\n";
        cout << "4. Eliminar tarea\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "\nIngrese ID de la tarea: ";
                cin >> id; cin.ignore();
                cout << "Titulo: "; getline(cin, titulo);
                cout << "Contexto: "; getline(cin, contexto);
                cout << "Curso: "; getline(cin, curso);
                cout << "Fecha límite (DD/MM/AAAA): "; getline(cin, fecha);
                cout << "Nivel de dificultad (Baja/Media/Alta): "; getline(cin, dificultad);
                cout << "Nivel de prioridad (Baja/Media/Alta): "; getline(cin, prioridad);
                cout << "Estado (Pendiente/En proceso/Completada): "; getline(cin, estado);
                cout << "Tipo de tarea (Tarea/Proyecto/Exposición): "; getline(cin, tipo);
                agregarTarea(inicio, id, titulo, contexto, curso, fecha, dificultad, prioridad, estado, tipo);
                break;
            case 2:
                mostrarTareas(inicio);
                break;
            case 3:
                cout << "\nIngrese el ID de la tarea a buscar: ";
                cin >> id;
                buscarTarea(inicio, id);
                break;
            case 4:
                cout << "\nIngrese el ID de la tarea a eliminar: ";
                cin >> id;
                eliminarTarea(inicio, id);
                break;
            case 5:
                cout << "\nSaliendo del programa...\n";
                break;
            default:
                cout << "\nOpción inválida.\n";
        }
    } while (opcion != 5);

    return 0;
}


