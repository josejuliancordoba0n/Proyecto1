cmake_minimum_required(VERSION 4.3)
project(Proyecto1)

set(CMAKE_CXX_STANDARD 14)

include_directories("Proyecto1/Archivos de Cabecera")

add_executable(Proyecto1
        Proyecto1/main.cpp
        "Proyecto1/Archivos de implementación/Cancha.cpp"
        "Proyecto1/Archivos de Cabecera/Cancha.h"
        "Proyecto1/Archivos de implementación/ListaCanchas.cpp"
        "Proyecto1/Archivos de Cabecera/ListaCanchas.h"
        "Proyecto1/Archivos de implementación/MenuPrincipal.cpp"
        "Proyecto1/Archivos de Cabecera/MenuPrincipal.h")
