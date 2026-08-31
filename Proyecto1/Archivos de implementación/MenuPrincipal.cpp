#include "../Archivos de Cabecera/MenuPrincipal.h"
#include <iostream>

using namespace std;

// Constructor
MenuPrincipal::MenuPrincipal() {
}

// Menú principal
void MenuPrincipal::iniciar() {
    int opcion;

    do {
        cout << "\n[----------[CENTRO DEPORTIVO ZONA ACTIVA]----------]\n\n";
        cout << "1. Gestion de canchas"
            "\n2. Gestion de clientes "
            "\n3. Gestion de reservas"
            "\n4. Gestion de listado de espera"
            "\n5. Reportes y estadisticas"
            "\n6. Salir" <<endl <<endl;

        do {
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "\nError. Debe ingresar un valor numerico!" <<endl;
                opcion = -1;
            }
            else if (opcion < 1 || opcion > 6) {
                cout << "\nError. Debe seleccionar una opcion entre 1 y 6!" <<endl;
            }

        } while (opcion < 1 || opcion > 6);

        switch(opcion) {
            case 1:
                system("cls");
                menuCanchas();
                break;

            case 2:
                cout << "\nFuncion en construccion..." <<endl;
                break;

            case 3:
                cout << "\nFuncion en construccion..." <<endl;
                break;

            case 4:
                cout << "\nFuncion en construccion..." <<endl;
                break;

            case 5:
                cout << "\nFuncion en construccion..." <<endl;
                break;

            case 6:
                cout << "Saliendo..." <<endl;
                break;


            default:
                cout << "Opcion invalida." <<endl;
        }


    } while(opcion != 6);

}


//Metodos Propios
void MenuPrincipal::menuCanchas() {
    int opcion;

    do {
        system("cls");
        cout << "\n======================================" <<endl;
        cout << "      GESTION DE CANCHAS" <<endl;
        cout << "======================================" <<endl<<endl;
        cout << "1. Registrar cancha" << endl
            << "2. Mostrar todas las canchas" << endl
            << "3. Buscar cancha por codigo" << endl
            << "4. Modificar precio" << endl
            << "5. Gestion de mantenimiento" << endl
            << "6. Reporte de ocupacion" << endl
            << "7. Volver al menu principal" << endl <<endl;

        do {
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "\nError. Debe ingresar un valor numerico!" <<endl;
                opcion = -1;
            }
            else if (opcion < 1 || opcion > 7) {
                cout << "\nError. Debe seleccionar una opcion entre 1 y 7!" <<endl;
            }

        } while (opcion < 1 || opcion > 7);

        switch(opcion) {

            case 1:
                registrarCancha();
                break;

            case 2:
                mostrarCanchas();
                break;

            case 3:
                buscarCancha();
                break;

            case 4:
                modificarPrecio();
                break;

            case 5:
                mantenimientoCancha();
                break;

            case 6:
                reporteOcupacion();
                break;

            case 7:
                system("cls");
                cout << "\nRegresando al menu principal..." <<endl;
                break;

            default:
                cout << "\nOpcion invalida." <<endl;
        }

    } while(opcion != 7);
}

void MenuPrincipal::registrarCancha() {
    system("cls");
    int idCancha;
    string tipoDeporte;
    float precioHora;

    cout << "===== REGISTRO DE CANCHA =====" <<endl;
    cout << "Recuerde que el maximo es de [10] canchas en total! \nActualmente hay un total de: ["<< coleccionCanchas.getCantidad() <<"]"<<endl;

    if(coleccionCanchas.getCantidad() >= 10) {
        cout <<"Error. Ya se alcanzo el maximo de 10 canchas!" <<endl;
        system("pause");
        return;
    }

    do {
        cout << "Digite el codigo de la cancha: ";
        cin >> idCancha;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error. Debe ingresar un codigo numerico!" <<endl;
            idCancha = -1;
        }
        else if (idCancha <= 0) {
            cout << "Error. El codigo debe ser mayor que 0!" <<endl;
        }

    } while (idCancha <= 0);

    if(coleccionCanchas.buscarCancha(idCancha) != nullptr) {
        cout << "Error. Ya existe una cancha con ese codigo!" <<endl;
        system("pause");
        system("cls");
        return;
    }

    cin.ignore(1000, '\n');

    do {

        cout << "\n===== DEPORTES DISPONIBLES =====" <<endl;
        cout << "- Futbol" <<endl;
        cout << "- Baloncesto" <<endl;
        cout << "- Voleibol" <<endl;
        cout << "- Tenis" <<endl;

        cout << "\nDigite el deporte que desea practicar: ";
        getline(cin, tipoDeporte);

        if (tipoDeporte != "Futbol" &&
            tipoDeporte != "Baloncesto" &&
            tipoDeporte != "Voleibol" &&
            tipoDeporte != "Tenis") {

            cout << "\nError. Debe ingresar uno de los deportes disponibles!" <<endl;
        }

    } while (tipoDeporte != "Futbol" &&
        tipoDeporte != "Baloncesto" &&
        tipoDeporte != "Voleibol" &&
        tipoDeporte != "Tenis");

    do {
        cout << "Digite el precio por hora: ";

        cin >> precioHora;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error. Debe ingresar un valor numerico!" <<endl;
            precioHora = -1;
        }
        else if (precioHora <= 0) {
            cout << "Error. El precio debe ser mayor que 0!" <<endl;
        }

    } while (precioHora <= 0);

    char disponibilidad[12];

    for(int i = 0; i < 12; i++) {
        disponibilidad[i] = 'L';
    }

    Cancha* nuevaCancha =
        new Cancha(idCancha, tipoDeporte, precioHora, disponibilidad);
    coleccionCanchas.agregarCancha(nuevaCancha);

    cout << "\nCancha registrada correctamente." <<endl;
    system("pause");
}

void MenuPrincipal::mostrarCanchas() {
    system("cls");
    cout << "Entrando a mostrarCanchas..." <<endl;
    
    if(coleccionCanchas.getCantidad() == 0) {
        cout << "No existen canchas registradas actualmente!" <<endl;
    }
    else {
        cout << coleccionCanchas.toStringListaCanchas() <<endl;
    }
    system("pause");
}

void MenuPrincipal::buscarCancha() {
    system("cls");

    int idCancha;

    cout << "===== BUSQUEDA DE CANCHA =====" <<endl;
    cout << "Actualmente hay un total de: ["
         << coleccionCanchas.getCantidad()
         << "] canchas registradas." <<endl;

    if(coleccionCanchas.getCantidad() == 0) {
        cout << "Error. No existen canchas registradas!" <<endl;
        system("pause");
        return;
    }

    do {
        cout << "\nDigite el codigo de la cancha que desea buscar: ";
        cin >> idCancha;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error. Debe ingresar un codigo numerico!" <<endl;
            idCancha = -1;
        }
        else if (idCancha <= 0) {
            cout << "Error. El codigo debe ser mayor que 0!" <<endl;
        }

    } while (idCancha <= 0);

    Cancha* cancha = coleccionCanchas.buscarCancha(idCancha);

    if(cancha != nullptr) {
        cout << "\nCancha encontrada!" <<endl;
        cout << cancha->toStringCancha() <<endl;
    }
    else {
        cout << "\nError. No existe una cancha con ese codigo!" <<endl;
    }

    system("pause");
}

void MenuPrincipal::modificarPrecio() {
    system("cls");

    int idCancha;
    float nuevoPrecio;

    cout << "===== MODIFICACION DE PRECIO =====" <<endl;
    cout << "Actualmente hay un total de: ["
         << coleccionCanchas.getCantidad()
         << "] canchas registradas." <<endl;

    if(coleccionCanchas.getCantidad() == 0) {
        cout << "Error. No existen canchas registradas!" <<endl;
        system("pause");
        return;
    }

    do {
        cout << "\nDigite el codigo de la cancha que desea modificar: ";
        cin >> idCancha;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error. Debe ingresar un codigo numerico!" <<endl;
            idCancha = -1;
        }
        else if (idCancha <= 0) {
            cout << "Error. El codigo debe ser mayor que 0!" <<endl;
        }

    } while (idCancha <= 0);

    Cancha* cancha = coleccionCanchas.buscarCancha(idCancha);

    if(cancha == nullptr) {
        cout << "\nError. No existe una cancha con ese codigo!" <<endl;
        system("pause");
        return;
    }

    do {
        cout << "Digite el nuevo precio por hora: ";
        cin >> nuevoPrecio;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error. Debe ingresar un valor numerico!" <<endl;
            nuevoPrecio = -1;
        }
        else if (nuevoPrecio <= 0) {
            cout << "Error. El precio debe ser mayor que 0!" <<endl;
        }

    } while (nuevoPrecio <= 0);

    if(coleccionCanchas.modificarPrecio(idCancha, nuevoPrecio)) {
        cout << "\nPrecio modificado correctamente!" <<endl;
    }
    else {
        cout << "\nError. No fue posible modificar el precio!" <<endl;
    }

    system("pause");
}

void MenuPrincipal::mantenimientoCancha() {
    system("cls");

    int idCancha;
    int franja;
    int opcion;

    cout << "===== GESTION DE MANTENIMIENTO =====" <<endl;
    cout << "Actualmente hay un total de: ["
         << coleccionCanchas.getCantidad()
         << "] canchas registradas." <<endl;

    if(coleccionCanchas.getCantidad() == 0) {
        cout << "Error. No existen canchas registradas!" <<endl;
        system("pause");
        return;
    }

    do {
        cout << "\nDigite el codigo de la cancha: ";
        cin >> idCancha;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error. Debe ingresar un codigo numerico!" <<endl;
            idCancha = -1;
        }
        else if (idCancha <= 0) {
            cout << "Error. El codigo debe ser mayor que 0!" <<endl;
        }

    } while (idCancha <= 0);

    Cancha* cancha = coleccionCanchas.buscarCancha(idCancha);

    if(cancha == nullptr) {
        cout << "\nError. No existe una cancha con ese codigo!" <<endl;
        system("pause");
        return;
    }

    cout << "\nCancha encontrada!" <<endl;
    cout << cancha->toStringCancha() <<endl;

    cout << "\n===== FRANJAS HORARIAS =====" <<endl;

    for (int i = 0; i < 12; i++) {
        int horaInicio = 8 + i;
        int horaFin = 9 + i;

        cout << "[" << i << "] "
            << horaInicio << ":00 - "
            << horaFin << ":00"
            <<endl;
    }

    do {
        cout << "\nDigite la posicion de la franja que desea modificar [0-11]: ";
        cin >> franja;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error. Debe ingresar un valor numerico!" <<endl;
            franja = -1;
        }
        else if (franja < 0 || franja > 11) {
            cout << "Error. La posicion de la franja debe estar entre 0 y 11!" <<endl;
        }

    } while (franja < 0 || franja > 11);

    do {
        cout << "\n1. Colocar mantenimiento" <<endl;
        cout << "2. Retirar mantenimiento" <<endl;
        cout << "Seleccione una opcion: ";

        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error. Debe ingresar un valor numerico!" <<endl;
            opcion = -1;
        }
        else if (opcion != 1 && opcion != 2) {
            cout << "Error. Debe seleccionar 1 o 2!" <<endl;
        }

    } while (opcion != 1 && opcion != 2);

    switch(opcion) {

        case 1:

            if(cancha->consultarFranja(franja) == 'M') {
                cout << "\nError. La franja seleccionada ya se encuentra en mantenimiento!" <<endl;
            }
            else if(cancha->cambiarEstadoFranja(franja, 'M')) {
                cout << "\nFranja colocada en mantenimiento correctamente!" <<endl;
            }
            else {
                cout << "\nError. No fue posible colocar la franja en mantenimiento!" <<endl;
            }

            break;

        case 2:

            if(cancha->consultarFranja(franja) != 'M') {
                cout << "\nError. La franja seleccionada no se encuentra en mantenimiento!" <<endl;
            }
            else if(cancha->cambiarEstadoFranja(franja, 'L')) {
                cout << "\nMantenimiento retirado correctamente!" <<endl;
            }
            else {
                cout << "\nError. No fue posible retirar el mantenimiento!" <<endl;
            }

            break;

        default:
            cout << "\nError. Opcion invalida!" <<endl;
    }

    system("pause");
}

void MenuPrincipal::reporteOcupacion() {
    system("cls");

    cout << "===== REPORTE DE OCUPACION =====" <<endl;
    cout << "Actualmente hay un total de: ["
         << coleccionCanchas.getCantidad()
         << "] canchas registradas." <<endl;

    if(coleccionCanchas.getCantidad() == 0) {
        cout << "Error. No existen canchas registradas!" <<endl;
        system("pause");
        return;
    }

    for(int i = 0; i < coleccionCanchas.getCantidad(); i++) {

        Cancha* cancha = coleccionCanchas.getCancha(i);

        int ocupadas = 0;
        int libres = 0;
        int mantenimiento = 0;

        for(int j = 0; j < 12; j++) {

            char estado = cancha->consultarFranja(j);

            if(estado == 'O') {
                ocupadas++;
            }
            else if(estado == 'L') {
                libres++;
            }
            else if(estado == 'M') {
                mantenimiento++;
            }
        }

        float porcentajeOcupacion = (ocupadas * 100.0f) / 12;

        cout << "\n======================================" <<endl;
        cout << "Codigo de cancha: ["
             << cancha->getIdCancha()
             << "]" <<endl;

        cout << "Tipo de deporte: ["
             << cancha->getTipoDeporte()
             << "]" <<endl;

        cout << "Franjas ocupadas: ["
             << ocupadas
             << "]" <<endl;

        cout << "Franjas libres: ["
             << libres
             << "]" <<endl;

        cout << "Franjas en mantenimiento: ["
             << mantenimiento
             << "]" <<endl;

        cout << "Porcentaje de ocupacion: ["
             << porcentajeOcupacion
             << "%]" <<endl;
    }

    system("pause");
}

// Destructor
MenuPrincipal::~MenuPrincipal() {
}
