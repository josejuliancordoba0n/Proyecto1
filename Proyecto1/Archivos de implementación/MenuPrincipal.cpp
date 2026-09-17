#include "../Archivos de Cabecera/MenuPrincipal.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Constructor
MenuPrincipal::MenuPrincipal() {
}

///////////////////////////// Menú principal /////////////////////////////////////////////////////
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

        switch (opcion) {
        case 1:
            system("cls");
            menuCanchas();
            break;

        case 2:
            system("cls");
            menuClientes();
            break;

        case 3:
            system("cls");
            menuReservas();
            break;

        case 4:
            system("cls");
            menuEspera();
            break;

        case 5:
            system("cls");
            menuReportes();
            break;

        case 6:
            cout << "Saliendo..." <<endl;
            break;


        default:
            cout << "Opcion invalida." <<endl;
        }


    } while (opcion != 6);

}


///////////////////////////////////////Metodos Gestion Canchas///////////////////////////////////
void MenuPrincipal::menuCanchas() {
    int opcion;

    do {
        system("cls");
        cout << "\n======================================" <<endl;
        cout << "      GESTION DE CANCHAS" <<endl;
        cout << "======================================" <<endl <<endl;
        cout << "1. Registrar cancha" <<endl
            << "2. Mostrar todas las canchas" <<endl
            << "3. Buscar cancha por codigo" <<endl
            << "4. Modificar precio" <<endl
            << "5. Gestion de mantenimiento" <<endl
            << "6. Reporte de ocupacion" <<endl
            << "7. Volver al menu principal" <<endl <<endl;

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

        switch (opcion) {

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

    } while (opcion != 7);
}

void MenuPrincipal::registrarCancha() {
    system("cls");
    int idCancha;
    string tipoDeporte;
    int precioHora;

    cout << "===== REGISTRO DE CANCHA =====" <<endl;
    cout << "Recuerde que el maximo es de [10] canchas en total! \nActualmente hay un total de: [" << coleccionCanchas.getCantidad() << "]" <<endl;

    if (coleccionCanchas.getCantidad() >= 10) {
        cout << "Error. Ya se alcanzo el maximo de 10 canchas!" <<endl;
        system("pause");
        return;
    }

    string codigo;

    do {
        cout << "\nDigite el codigo de la cancha (2 digitos): C-";
        cin >> codigo;

        if (codigo.length() != 2) {
            cout << "Error. Debe ingresar exactamente 2 digitos!" << endl;
            idCancha = -1;
            continue;
        }

        bool valido = true;
        idCancha = 0;

        for (char ch : codigo) {
            if (ch < '0' || ch > '9') {
                valido = false;
                break;
            }

            idCancha = idCancha * 10 + (ch - '0');
        }

        if (!valido) {
            cout << "Error. Debe ingresar solo numeros!" << endl;
            idCancha = -1;
        }

    } while (idCancha < 1);

    if (coleccionCanchas.buscarCancha(idCancha) != nullptr) {
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

    string entrada;

    do {
        cout << "\nDigite el precio por hora (No puede ser menor que 100 ni mayor que 100 000)\n(Mo ingrese espacios por favor!): "<<endl;
        getline(cin, entrada);

        bool valido = true;

        for (char ch : entrada) {

            if (ch == ' ') {
                cout << "Error. No se permiten espacios." <<endl;
                valido = false;
                break;
            }

            if (ch < '0' || ch > '9') {
                cout << "Error. Debe ingresar solo numeros." <<endl;
                valido = false;
                break;
            }
        }

        if (valido) {
            precioHora = 0;
            for (char ch : entrada) {
                precioHora = precioHora * 10 + (ch - '0');
            }

            if (precioHora < 100 || precioHora > 100000) {
                cout << "Error. El precio no puede ser menor que 100 ni mayor que 100 000!" << endl;
                precioHora = -1;
            }
        }
        else {
            precioHora = -1;
        }

    } while (precioHora <= 0);

    char disponibilidad[12];

    for (int i = 0; i < 12; i++) {
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
    cout << "Entrando a mostrarCanchas...\n\n" <<endl;

    if (coleccionCanchas.getCantidad() == 0) {
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

    if (coleccionCanchas.getCantidad() == 0) {
        cout << "Error. No existen canchas registradas!" <<endl;
        system("pause");
        return;
    }

    do {
        cout << "\nDigite el codigo de la cancha que desea buscar: C-";
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

    if (cancha != nullptr) {
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
    int nuevoPrecio;

    cout << "===== MODIFICACION DE PRECIO =====" <<endl;
    cout << "Actualmente hay un total de: ["
        << coleccionCanchas.getCantidad()
        << "] canchas registradas." <<endl;

    if (coleccionCanchas.getCantidad() == 0) {
        cout << "Error. No existen canchas registradas!" <<endl;
        system("pause");
        return;
    }

    do {
        cout << "\nDigite el codigo de la cancha que desea modificar: C-";
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

    if (cancha == nullptr) {
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

    if (coleccionCanchas.modificarPrecio(idCancha, nuevoPrecio)) {
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

    if (coleccionCanchas.getCantidad() == 0) {
        cout << "Error. No existen canchas registradas!" <<endl;
        system("pause");
        return;
    }

    do {
        cout << "\nDigite el codigo de la cancha: C-";
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

    if (cancha == nullptr) {
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

    switch (opcion) {

    case 1:

        if (cancha->consultarFranja(franja) == 'M') {
            cout << "\nError. La franja seleccionada ya se encuentra en mantenimiento!" <<endl;
        }
        else if (cancha->cambiarEstadoFranja(franja, 'M')) {
            cout << "\nFranja colocada en mantenimiento correctamente!" <<endl;
        }
        else {
            cout << "\nError. No fue posible colocar la franja en mantenimiento!" <<endl;
        }

        break;

    case 2:

        if (cancha->consultarFranja(franja) != 'M') {
            cout << "\nError. La franja seleccionada no se encuentra en mantenimiento!" <<endl;
        }
        else if (cancha->cambiarEstadoFranja(franja, 'L')) {
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

    if (coleccionCanchas.getCantidad() == 0) {
        cout << "Error. No existen canchas registradas!" <<endl;
        system("pause");
        return;
    }

    for (int i = 0; i < coleccionCanchas.getCantidad(); i++) {

        Cancha* cancha = coleccionCanchas.getCancha(i);

        int ocupadas = 0;
        int libres = 0;
        int mantenimiento = 0;

        for (int j = 0; j < 12; j++) {

            char estado = cancha->consultarFranja(j);

            if (estado == 'O') {
                ocupadas++;
            }
            else if (estado == 'L') {
                libres++;
            }
            else if (estado == 'M') {
                mantenimiento++;
            }
        }

        float porcentajeOcupacion = (ocupadas * 100.0f) / 12;

        cout << "\n======================================" << endl;
        cout << "Codigo de cancha: [C-";
        if (cancha->getIdCancha() < 10) {
            cout << "0" << cancha->getIdCancha();
        }
        else { 
            cout << cancha->getIdCancha(); 
        }

        cout << "]" <<endl;

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

///////////////////////////////Metodos Gestion Cliente////////////////////////////////////////////
void MenuPrincipal::menuClientes() {
    int opcion;

    do {
        system("cls");
        cout << "\n======================================" <<endl;
        cout << "      GESTION DE CLIENTES" <<endl;
        cout << "======================================" <<endl <<endl;
        cout << "1. Registrar cliente" <<endl
            << "2. Mostrar listado de clientes" <<endl
            << "3. Buscar cliente por identificacion" <<endl
            << "4. Mostrar reservas de un cliente" <<endl
            << "5. Volver al menu principal" <<endl <<endl;

        do {
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "\nError. Debe ingresar un valor numerico!" <<endl;
                opcion = -1;
            }
            else if (opcion < 1 || opcion > 5) {
                cout << "\nError. Debe seleccionar una opcion entre 1 y 5!" <<endl;
            }

        } while (opcion < 1 || opcion > 5);

        switch (opcion) {

        case 1:
            registrarCliente();
            break;

        case 2:
            mostrarClientes();
            break;

        case 3:
            buscarCliente();
            break;

        case 4:
            mostrarReservasCliente();
            break;

        case 5:
            system("cls");
            cout << "\nRegresando al menu principal..." <<endl;
            break;

        default:
            cout << "\nOpcion invalida." <<endl;
        }

    } while (opcion != 5);
}

void MenuPrincipal::registrarCliente() {
    system("cls");
    int idCliente;
    string nombreCliente;
    string numTel;

    cout << "===== REGISTRO DE CLIENTE =====" <<endl;
    cout << "Recuerde que el maximo es de [100] clientes en total! \nActualmente hay un total de: ["
        << coleccionClientes.getCantidad() << "]" <<endl;

    if (coleccionClientes.getCantidad() >= 100) {
        cout << "Error. Ya se alcanzo el maximo de 100 clientes!" <<endl;
        system("pause");
        return;
    }

    do {
        cout << "Digite la identificacion del cliente: ";
        cin >> idCliente;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error. Debe ingresar una identificacion numerica!" <<endl;
            idCliente = -1;
        }
        else if (idCliente <= 0) {
            cout << "Error. La identificacion debe ser mayor que 0!" <<endl;
        }

    } while (idCliente <= 0);

    if (coleccionClientes.buscarCliente(idCliente) != nullptr) {
        cout << "Error. Ya existe un cliente con esa identificacion!" <<endl;
        system("pause");
        return;
    }

    cin.ignore(1000, '\n');

    bool nombreValido = false;
    do {
        cout << "Digite el nombre completo del cliente: (No ingresar acentos, numeros o simbolos): ";
        getline(cin, nombreCliente);
        bool soloEspacios = true;

        for (char ch : nombreCliente) {
            if (ch != ' ') {
                soloEspacios = false;
                break;
            }
        }

        if (nombreCliente.empty() || soloEspacios) {
            cout << "Error. El nombre no puede estar vacio!" << endl;
            nombreValido = false;
  
        }else {
            nombreValido = true;
            for (char ch : nombreCliente) {
                if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == ' ')) {
                    nombreValido = false;
                    cout << "Error. El nombre solo puede contener letras y espacios!" <<endl;
                    break;
                }
            }
        }

    } while (!nombreValido);

    bool telefonoValido = false;
    do {
        cout << "Digite el numero de telefono (Debe contener 8 digitos): ";
        getline(cin, numTel);

        if (numTel.empty()) {
            cout << "Error. El telefono no puede estar vacio!" <<endl;
            telefonoValido = false;
        }
        else {
            telefonoValido = true;
            for (char ch : numTel) {
                if (!(ch >= '0' && ch <= '9' && numTel.length() == 8)) {
                    telefonoValido = false;
                    cout << "Error. El telefono solo puede contener 8 digitos!" <<endl;
                    break;
                }
            }
        }

    } while (!telefonoValido);

    Cliente* nuevoCliente = new Cliente(idCliente, nombreCliente, numTel);
    coleccionClientes.agregarCliente(nuevoCliente);

    cout << "\nCliente registrado correctamente." <<endl;
    system("pause");
}

void MenuPrincipal::mostrarClientes() {
    system("cls");
    cout << "===== LISTADO DE CLIENTES =====" <<endl;

    if (coleccionClientes.getCantidad() == 0) {
        cout << "No existen clientes registrados actualmente!" <<endl;
    }
    else {
        cout << coleccionClientes.toStringListaClientes() <<endl;
    }
    system("pause");
}

void MenuPrincipal::buscarCliente() {
    system("cls");

    int idCliente;

    cout << "===== BUSQUEDA DE CLIENTE =====" <<endl;
    cout << "Actualmente hay un total de: ["
        << coleccionClientes.getCantidad()
        << "] clientes registrados." <<endl;

    if (coleccionClientes.getCantidad() == 0) {
        cout << "Error. No existen clientes registrados!" <<endl;
        system("pause");
        return;
    }

    do {
        cout << "\nDigite la identificacion del cliente que desea buscar: ";
        cin >> idCliente;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error. Debe ingresar una identificacion numerica!" <<endl;
            idCliente = -1;
        }
        else if (idCliente <= 0) {
            cout << "Error. La identificacion debe ser mayor que 0!" <<endl;
        }

    } while (idCliente <= 0);

    Cliente* cliente = coleccionClientes.buscarCliente(idCliente);

    if (cliente != nullptr) {
        cout << "\nCliente encontrado!" <<endl;
        cout << cliente->toStringCliente() <<endl;
    }
    else {
        cout << "\nError. No existe un cliente con esa identificacion!" <<endl;
    }

    system("pause");
}

void MenuPrincipal::mostrarReservasCliente() {
    system("cls");

    int idCliente;

    cout << "===== RESERVAS DE UN CLIENTE =====" <<endl;

    if (coleccionClientes.getCantidad() == 0) {
        cout << "Error. No existen clientes registrados!" <<endl;
        system("pause");
        return;
    }

    do {
        cout << "\nDigite la identificacion del cliente: ";
        cin >> idCliente;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error. Debe ingresar una identificacion numerica!" <<endl;
            idCliente = -1;
        }
        else if (idCliente <= 0) {
            cout << "Error. La identificacion debe ser mayor que 0!" <<endl;
        }

    } while (idCliente <= 0);

    Cliente* cliente = coleccionClientes.buscarCliente(idCliente);

    if (cliente == nullptr) {
        cout << "\nError. No existe un cliente con esa identificacion!" <<endl;
        system("pause");
        return;
    }

    cout << "\nCliente encontrado!" <<endl;
    cout << cliente->toStringCliente() <<endl;

    cout << coleccionReservas.mostrarReservasPorCliente(idCliente) <<endl;

    system("pause");
}

///////////////////////////////Metodos Gestion Listado de Espera//////////////////////////////////
void MenuPrincipal::menuEspera() {
    int opcion;

    do {
        system("cls");
        cout << "\n======================================" <<endl;
        cout << "      LISTADO DE ESPERA" <<endl;
        cout << "======================================" <<endl <<endl;
        cout << "1. Registrar cliente en espera" <<endl
            << "2. Mostrar listado de espera" <<endl
            << "3. Cambiar estado de una solicitud" <<endl
            << "4. Volver al menu principal" <<endl <<endl;

        do {
            cout << "Seleccione una opcion: ";
            cin >> opcion;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');

                cout << "\nError. Debe ingresar un valor numerico!" <<endl;
                opcion = -1;
            }
            else if (opcion < 1 || opcion > 4) {
                cout << "\nError. Debe seleccionar una opcion entre 1 y 4!" <<endl;
            }

        } while (opcion < 1 || opcion > 4);

        switch (opcion) {

        case 1:
            registrarEnEspera();
            break;

        case 2:
            mostrarListadoEspera();
            break;

        case 3:
            cambiarEstadoEspera();
            break;

        case 4:
            system("cls");
            cout << "\nRegresando al menu principal..." <<endl;
            break;

        default:
            cout << "\nOpcion invalida." <<endl;
        }

    } while (opcion != 4);
}

void MenuPrincipal::registrarEnEspera() {
    system("cls");

    int idCliente;
    int idCancha;
    int franja;

    cout << "===== REGISTRAR CLIENTE EN ESPERA =====" <<endl;


    if (coleccionClientes.getCantidad() == 0) {
        cout << "Error. No existen clientes registrados!" <<endl;
        system("pause");
        return;
    }

    if (coleccionCanchas.getCantidad() == 0) {
        cout << "Error. No existen canchas registradas!" <<endl;
        system("pause");
        return;
    }

    do {
        cout << "\nDigite la identificacion del cliente: ";
        cin >> idCliente;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error. Debe ingresar una identificacion numerica!" <<endl;
            idCliente = -1;
        }
        else if (idCliente <= 0) {
            cout << "Error. La identificacion debe ser mayor que 0!" <<endl;
        }

    } while (idCliente <= 0);

    Cliente* cliente = coleccionClientes.buscarCliente(idCliente);

    if (cliente == nullptr) {
        cout << "\nError. No existe un cliente con esa identificacion!" <<endl;
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

    Cancha* cancha = coleccionCanchas.buscarCancha(idCancha);

    if (cancha == nullptr) {
        cout << "\nError. No existe una cancha con ese codigo!" <<endl;
        system("pause");
        return;
    }

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

        cout << "\nDigite la posicion de la franja [0-11]: ";
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

    if (cancha->consultarFranja(franja) != 'O') {
        cout << "\nError. Solo se puede poner en espera una franja que este OCUPADA!" <<endl;
        system("pause");
        return;
    }

    RegistroEspera* nuevoRegistro = new RegistroEspera(0, 'E', cliente, cancha, franja);

    if (coleccionEspera.AgregarRegistroEspera(nuevoRegistro)) {
        cout << "\nCliente registrado en la lista de espera correctamente!" <<endl;
    }
    else {
        cout << "\nError. No fue posible registrar la solicitud (lista llena o ya existe una igual)." <<endl;
        delete nuevoRegistro;
    }

    system("pause");
}

void MenuPrincipal::mostrarListadoEspera() {
    system("cls");
    cout << coleccionEspera.toStringListaEspera() <<endl;
    system("pause");
}

void MenuPrincipal::cambiarEstadoEspera() {
    system("cls");

    int idEspera;
    int opcion;
    char nuevoEstado;

    cout << "===== CAMBIAR ESTADO DE SOLICITUD =====" <<endl;
    cout << coleccionEspera.toStringListaEspera() <<endl;

    if (coleccionClientes.getCantidad() == 0) {
        cout << "Error. No existen clientes registrados!" <<endl;
        system("pause");
        return;
    }

    do {
        cout << "Digite el numero de solicitud: ";
        cin >> idEspera;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error. Debe ingresar un valor numerico!" <<endl;
            idEspera = -1;
        }
        else if (idEspera <= 0) {
            cout << "Error. El numero de solicitud debe ser mayor que 0!" <<endl;
        }

    } while (idEspera <= 0);

    do {
        cout << "\n1. Esperando" <<endl;
        cout << "2. Asignado" <<endl;
        cout << "3. Cancelado" <<endl;
        cout << "Seleccione el nuevo estado: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error. Debe ingresar un valor numerico!" <<endl;
            opcion = -1;
        }
        else if (opcion < 1 || opcion > 3) {
            cout << "Error. Debe seleccionar una opcion entre 1 y 3!" <<endl;
        }

    } while (opcion < 1 || opcion > 3);

    if (opcion == 1) nuevoEstado = 'E';
    else if (opcion == 2) nuevoEstado = 'A';
    else nuevoEstado = 'C';

    if (coleccionEspera.cambiarEstadoSolicitud(idEspera, nuevoEstado)) {
        cout << "\nEstado actualizado correctamente!" <<endl;
    }
    else {
        cout << "\nError. No existe una solicitud con ese numero!" <<endl;
    }

    system("pause");
}

///////////////////////////////Metodos Gestion de Reservas (Persona 3)//////////////////////////////
void MenuPrincipal::menuReservas() {
    int opcion;

    do {
        system("cls");
        cout << "\n======================================" <<endl;
        cout << "      GESTION DE RESERVAS" <<endl;
        cout << "======================================" <<endl <<endl;
        cout << "1. Registrar reserva" <<endl
            << "2. Mostrar todas las reservas" <<endl
            << "3. Buscar reserva por numero" <<endl
            << "4. Mostrar reservas de una cancha" <<endl
            << "5. Cancelar reserva" <<endl
            << "6. Volver al menu principal" <<endl <<endl;

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

        switch (opcion) {

        case 1:
            registrarReserva();
            break;

        case 2:
            mostrarReservas();
            break;

        case 3:
            buscarReservaMenu();
            break;

        case 4:
            mostrarReservasPorCanchaMenu();
            break;

        case 5:
            cancelarReservaMenu();
            break;

        case 6:
            system("cls");
            cout << "\nRegresando al menu principal..." <<endl;
            break;

        default:
            cout << "\nOpcion invalida." <<endl;
        }

    } while (opcion != 6);
}

void MenuPrincipal::registrarReserva() {
    system("cls");
    int idCliente, idCancha, franjaInicial, cantidadFranjas;

    cout << "===== REGISTRAR RESERVA =====" <<endl;
    cout << "Recuerde que el maximo es de [120] reservas en total! \nActualmente hay un total de: [" << coleccionReservas.getCantidad() << "]" <<endl;

    if (coleccionReservas.getCantidad() >= 120) {
        cout << "Error. Ya se alcanzo el maximo de 120 reservas!" <<endl;
        system("pause");
        return;
    }

    if (coleccionClientes.getCantidad() == 0) {
        cout << "Error. No existen clientes registrados!" <<endl;
        system("pause");
        return;
    }

    if (coleccionCanchas.getCantidad() == 0) {
        cout << "Error. No existen canchas registradas!" <<endl;
        system("pause");
        return;
    }

    do {
        cout << "\nDigite la identificacion del cliente: ";
        cin >> idCliente;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error. Debe ingresar una identificacion numerica!" <<endl;
            idCliente = -1;
        }
        else if (idCliente <= 0) {
            cout << "Error. La identificacion debe ser mayor que 0!" <<endl;
        }

    } while (idCliente <= 0);

    Cliente* cliente = coleccionClientes.buscarCliente(idCliente);

    if (cliente == nullptr) {
        cout << "\nError. No existe un cliente con esa identificacion!" <<endl;
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

    Cancha* cancha = coleccionCanchas.buscarCancha(idCancha);

    if (cancha == nullptr) {
        cout << "\nError. No existe una cancha con ese codigo!" <<endl;
        system("pause");
        return;
    }

    
    if (idCancha < 10) {
        cout << "\n===== DISPONIBILIDAD DE LA CANCHA [C-0"
            << idCancha
            << "] =====" << endl;
    }
    else {
        cout << "\n===== DISPONIBILIDAD DE LA CANCHA [C-"
            << idCancha
            << "] =====" << endl;
    }

    for (int i = 0; i < 12; i++) {
        int horaInicio = 8 + i;
        int horaFin = 9 + i;
        cout << "[" << i << "] " << horaInicio << ":00 - " << horaFin << ":00 --> " << cancha->consultarFranja(i) <<endl;
    }

    do {
        cout << "\nDigite la franja inicial [0-11]: ";
        cin >> franjaInicial;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error. Debe ingresar un valor numerico!" <<endl;
            franjaInicial = -1;
        }
        else if (franjaInicial < 0 || franjaInicial > 11) {
            cout << "Error. La posicion de la franja debe estar entre 0 y 11!" <<endl;
        }

    } while (franjaInicial < 0 || franjaInicial > 11);

    do {
        cout << "Digite la cantidad de franjas consecutivas a reservar: ";
        cin >> cantidadFranjas;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error. Debe ingresar un valor numerico!" <<endl;
            cantidadFranjas = -1;
        }
        else if (cantidadFranjas < 1) {
            cout << "Error. Debe reservar al menos 1 franja!" <<endl;
        }

    } while (cantidadFranjas < 1);

    if (coleccionReservas.registrarReserva(cliente, cancha, franjaInicial, cantidadFranjas)) {
        cout << "\nReserva registrada correctamente." <<endl;
    }
    else {
        cout << "\nError. No se pudo registrar la reserva (franjas fuera de rango, invalidas u ocupadas)." <<endl;
        cout << "Si lo desea, puede registrar al cliente en el listado de espera." <<endl;
    }

    system("pause");
}

void MenuPrincipal::mostrarReservas() {
    system("cls");
    cout << "===== LISTADO DE RESERVAS =====" <<endl;

    if (coleccionReservas.getCantidad() == 0) {
        cout << "No existen reservas registradas actualmente!" <<endl;
    }
    else {
        cout << coleccionReservas.toStringListaReservas() <<endl;
    }
    system("pause");
}

void MenuPrincipal::buscarReservaMenu() {
    system("cls");
    int numeroReserva;

    cout << "===== BUSCAR RESERVA POR NUMERO =====" <<endl;

    if (coleccionReservas.getCantidad() == 0) {
        cout << "Error. No existen reservas registradas!" <<endl;
        system("pause");
        return;
    }

    do {
        cout << "Digite el numero de la reserva: ";
        cin >> numeroReserva;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error. Debe ingresar un valor numerico!" <<endl;
            numeroReserva = -1;
        }
        else if (numeroReserva <= 0) {
            cout << "Error. El numero debe ser mayor que 0!" <<endl;
        }

    } while (numeroReserva <= 0);

    Reserva* reserva = coleccionReservas.buscarReserva(numeroReserva);

    if (reserva == nullptr) {
        cout << "\nError. No existe una reserva con ese numero!" <<endl;
    }
    else {
        cout << "\nReserva encontrada!" <<endl;
        cout << reserva->toStringReserva() <<endl;
    }

    system("pause");
}

void MenuPrincipal::mostrarReservasPorCanchaMenu() {
    system("cls");
    int idCancha;

    cout << "===== RESERVAS DE UNA CANCHA =====" <<endl;

    if (coleccionCanchas.getCantidad() == 0) {
        cout << "Error. No existen canchas registradas!" <<endl;
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

    if (coleccionCanchas.buscarCancha(idCancha) == nullptr) {
        cout << "\nError. No existe una cancha con ese codigo!" <<endl;
        system("pause");
        return;
    }

    cout << "\n" << coleccionReservas.mostrarReservasPorCancha(idCancha) <<endl;
    system("pause");
}

void MenuPrincipal::cancelarReservaMenu() {
    system("cls");
    int numeroReserva;

    cout << "===== CANCELAR RESERVA =====" <<endl;

    if (coleccionReservas.getCantidad() == 0) {
        cout << "Error. No existen reservas registradas!" <<endl;
        system("pause");
        return;
    }

    do {
        cout << "Digite el numero de la reserva a cancelar: ";
        cin >> numeroReserva;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error. Debe ingresar un valor numerico!" <<endl;
            numeroReserva = -1;
        }
        else if (numeroReserva <= 0) {
            cout << "Error. El numero debe ser mayor que 0!" <<endl;
        }

    } while (numeroReserva <= 0);

    Reserva* reserva = coleccionReservas.buscarReserva(numeroReserva);

    if (reserva == nullptr) {
        cout << "\nError. No existe una reserva con ese numero!" <<endl;
        system("pause");
        return;
    }

    if (reserva->getEstado() != 'A') {
        cout << "\nError. Esa reserva ya se encuentra cancelada!" <<endl;
        system("pause");
        return;
    }

    cout << "\n" << reserva->toStringReserva() << endl;

    char eleccion;
    cout << "\n¿Seguro que quiere cancelar esta reserva numero: [" << numeroReserva << "]?" << endl;
    cout << "Esta accion es irreversible!" << endl;
    cout << "\nOpcion (S/N): ";
    cin >> eleccion;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nOpcion invalida, ingrese S o N!" << endl;
        system("pause");
        return;
    }

    switch(toupper(eleccion)) {
    case 'S':
        cout << "\nCancelacion concluida!." << endl;
        system("pause");
        break; 
    case 'N':
        cout << "\nCancelacion abortada!." << endl;
        system("pause");
        return;
    default:
        cout << "\nOpcion invalida, ingrese S o N!" << endl;
        system("pause");
        return;
    }

    int idCancha = reserva->getCancha()->getIdCancha();
    int franjaInicial = reserva->getFranjaInicial();
    int cantidadFranjas = reserva->getCantidadFranjas();

    if (coleccionReservas.cancelarReserva(numeroReserva)) {
        cout << "\nReserva cancelada correctamente. Las franjas quedaron libres." <<endl;

        bool hayEnEspera = false;
        for (int franja = franjaInicial; franja < franjaInicial + cantidadFranjas; franja++) {
            RegistroEspera* espera = coleccionEspera.buscarEsperaPorCanchaFranja(idCancha, franja);
            if (espera != nullptr) {
                if (!hayEnEspera) {
                    cout << "\n¡Atencion! Hay clientes en el listado de espera para esta cancha/franja:" <<endl;
                    hayEnEspera = true;
                }
                cout << espera->toStringRegistroEspera(espera->getIdSolicitudEspera()) <<endl;
            }
        }

        if (!hayEnEspera) {
            cout << "\nNo hay clientes en espera para esa cancha/franja." <<endl;
        }
    }
    else {
        cout << "\nError. No se pudo cancelar la reserva." <<endl;
    }

    system("pause");
}

/////////////////////////////// Metodos Reportes y estadisticas (Persona 3) //////////////////////////

void MenuPrincipal::menuReportes() {
    int opcion;

    do {
        system("cls");
        cout << "\n======================================" <<endl;
        cout << "      REPORTES Y ESTADISTICAS" <<endl;
        cout << "======================================" <<endl <<endl;
        cout << "1. Cancha con mayor cantidad de reservas activas" <<endl
            << "2. Cliente con mayor cantidad de reservas activas" << endl
            << "3. Ingreso total generado por reservas activas" <<endl
            << "4. Horas con mayor y menor cantidad de reservas" <<endl
            << "5. Porcentaje de ocupacion de cada cancha" << endl
            << "6. Volver al menu principal" <<endl <<endl;

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
                cout << "\nError. Debe seleccionar una opcion entre 1 y 4!" <<endl;
            }

        } while (opcion < 1 || opcion > 6);

        switch (opcion) {

        case 1:
            reporteCanchaMasReservas();
            break;
        
        case 2:
            reporteClienteMasReservas();
            break;


        case 3:
            reporteIngresoTotal();
            break;

        case 4:
            reporteHorasMayorMenor();
            break;

        case 5:
            reporteOcupacionPorcentaje();
            break;

        case 6:
            system("cls");
            cout << "\nRegresando al menu principal..." << endl;
            break;

        default:
            cout << "\nOpcion invalida." <<endl;
        }

    } while (opcion != 6);
}

void MenuPrincipal::reporteClienteMasReservas() {
    system("cls");

    cout << "===== CLIENTE CON MAYOR CANTIDAD DE RESERVAS ACTIVAS ====="
        << endl << endl;

    if (coleccionClientes.getCantidad() == 0) {
        cout << "No existen clientes registrados." << endl;
        system("pause");
        return;
    }

    Cliente* mejorCliente = nullptr;
    int maxReservas = -1;

    for (int i = 0; i < coleccionClientes.getCantidad(); i++) {

        Cliente* c = coleccionClientes.getCliente(i);

        int total =
            coleccionReservas.contarReservasActivasPorCliente(
                c->getIdCliente());

        cout << "Cliente ["
            << c->getIdCliente()
            << "] "
            << c->getNombreCliente()
            << ": "
            << total
            << " reserva(s) activa(s)"
            << endl;

        if (total > maxReservas) {
            maxReservas = total;
            mejorCliente = c;
        }
    }

    cout << endl;

    if (mejorCliente != nullptr && maxReservas > 0) {

        cout << "==> El cliente con MAYOR cantidad de reservas activas es:"
            << endl;

        cout << "[" << mejorCliente->getIdCliente() << "] "
            << mejorCliente->getNombreCliente()
            << " con "
            << maxReservas
            << " reserva(s)."
            << endl;
    }
    else {
        cout << "Ningun cliente tiene reservas activas todavia."
            << endl;
    }

    system("pause");
}

void MenuPrincipal::reporteOcupacionPorcentaje() {

    system("cls");

    cout << "===== PORCENTAJE DE OCUPACION DE CADA CANCHA ====="
        << endl << endl;

    if (coleccionCanchas.getCantidad() == 0) {
        cout << "No existen canchas registradas." << endl;
        system("pause");
        return;
    }

    for (int i = 0; i < coleccionCanchas.getCantidad(); i++) {

        Cancha* cancha = coleccionCanchas.getCancha(i);

        int ocupadas = 0;

        for (int j = 0; j < 12; j++) {

            if (cancha->consultarFranja(j) == 'O') {
                ocupadas++;
            }
        }

        float porcentaje = (ocupadas * 100.0f) / 12;

        cout << "Cancha [C-";

        if (cancha->getIdCancha() < 10) {
            cout << "0";
        }

        cout << cancha->getIdCancha()
            << "] ("
            << cancha->getTipoDeporte()
            << ") --> "
            << porcentaje
            << "% de ocupacion"
            << endl;
    }

    system("pause");
}

void MenuPrincipal::reporteCanchaMasReservas() {
    system("cls");
    cout << "===== CANCHA CON MAYOR CANTIDAD DE RESERVAS ACTIVAS =====" <<endl <<endl;

    if (coleccionCanchas.getCantidad() == 0) {
        cout << "No existen canchas registradas." <<endl;
        system("pause");
        return;
    }

    Cancha* mejorCancha = nullptr;
    int maxReservas = -1;

    for (int i = 0; i < coleccionCanchas.getCantidad(); i++) {
        Cancha* c = coleccionCanchas.getCancha(i);
        int total = coleccionReservas.contarReservasActivasPorCancha(c->getIdCancha());

        cout << "Cancha [C-";

        if (c->getIdCancha() < 10) {
            cout << "0";
        }

        cout << c->getIdCancha()
            << "] ("
            << c->getTipoDeporte()
            << "): "
            << total
            << " reserva(s) activa(s)"
            << endl;

        if (total > maxReservas) {
            maxReservas = total;
            mejorCancha = c;
        }
    }
   
    cout <<endl;

    if (mejorCancha != nullptr && maxReservas > 0) {
        cout << "==> La cancha con MAYOR cantidad de reservas activas es la [C-";

        if (mejorCancha->getIdCancha() < 10) {
            cout << "0";
        }

        cout << mejorCancha->getIdCancha()
            << "] con "
            << maxReservas
            << " reserva(s)." << endl;
    }
    else {
        cout << "Ninguna cancha tiene reservas activas todavia." << endl;
    }

    system("pause");
}

void MenuPrincipal::reporteIngresoTotal() {
    system("cls");
    cout << "===== INGRESO TOTAL GENERADO POR RESERVAS ACTIVAS =====" <<endl <<endl;

    float total = 0.0f;
    int cantidadActivas = 0;

    for (int i = 0; i < coleccionReservas.getCantidad(); i++) {
        Reserva* r = coleccionReservas.getReserva(i);
        if (r->getEstado() == 'A') {
            cout << "Reserva [" << r->getNumeroReserva() << "] - Cliente: "
                 << r->getCliente()->getNombreCliente() << " - Monto: CRC " << r->getMonto() <<endl;
            total += r->getMonto();
            cantidadActivas++;
        }
    }

    cout <<endl;
    cout << "Cantidad de reservas activas consideradas: " << cantidadActivas <<endl;
    cout << "==> Ingreso total generado: CRC " << total <<endl;

    system("pause");
}

void MenuPrincipal::reporteHorasMayorMenor() {
    system("cls");
    cout << "===== HORAS CON MAYOR Y MENOR CANTIDAD DE RESERVAS =====" <<endl <<endl;

    int contadorPorFranja[12];
    for (int i = 0; i < 12; i++) {
        contadorPorFranja[i] = 0;
    }

    for (int i = 0; i < coleccionReservas.getCantidad(); i++) {
        Reserva* r = coleccionReservas.getReserva(i);
        if (r->getEstado() == 'A') {
            int inicio = r->getFranjaInicial();
            int cantidad = r->getCantidadFranjas();
            for (int f = inicio; f < inicio + cantidad && f < 12; f++) {
                contadorPorFranja[f]++;
            }
        }
    }

    int franjaMax = 0, franjaMin = 0;
    for (int i = 0; i < 12; i++) {
        int horaInicio = 8 + i;
        int horaFin = 9 + i;
        cout << "[" << horaInicio << ":00 - " << horaFin << ":00] --> "
            << contadorPorFranja[i] << " reserva(s)" <<endl;

        if (contadorPorFranja[i] > contadorPorFranja[franjaMax]) franjaMax = i;
        if (contadorPorFranja[i] < contadorPorFranja[franjaMin]) franjaMin = i;
    }

    cout <<endl;
    cout << "==> Hora con MAYOR cantidad de reservas: ["
        << (8 + franjaMax) << ":00 - " << (9 + franjaMax) << ":00] con "
        << contadorPorFranja[franjaMax] << " reserva(s)." <<endl;
    cout << "==> Hora con MENOR cantidad de reservas: ["
        << (8 + franjaMin) << ":00 - " << (9 + franjaMin) << ":00] con "
        << contadorPorFranja[franjaMin] << " reserva(s)." <<endl;

    system("pause");
}




// Destructor
MenuPrincipal::~MenuPrincipal() {
}
