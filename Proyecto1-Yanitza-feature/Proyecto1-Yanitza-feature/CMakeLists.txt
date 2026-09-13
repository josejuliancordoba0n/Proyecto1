cmake_minimum_required(VERSION 4.3)
project(Proyecto1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Proyecto1
        main.cpp
        "Archivos de implementación/Cancha.cpp"
        "Archivos de implementación/ListaCanchas.cpp"
        "Archivos de implementación/Cliente.cpp"
        "Archivos de implementación/ListaCliente.cpp"
        "Archivos de implementación/RegistroEspera.cpp"
        "Archivos de implementación/ListaRegistroEspera.cpp"
        "Archivos de implementación/MenuPrincipal.cpp")

# Prefer target_include_directories to avoid global include pollution
target_include_directories(Proyecto1 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Archivos de Cabecera")
