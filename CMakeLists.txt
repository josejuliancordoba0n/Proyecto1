cmake_minimum_required(VERSION 4.3)
project(Proyecto1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Proyecto1
        Proyecto1/main.cpp
        "Proyecto1/Archivos de implementación/Cancha.cpp"
        "Proyecto1/Archivos de implementación/ListaCanchas.cpp"
        "Proyecto1/Archivos de implementación/Cliente.cpp"
        "Proyecto1/Archivos de implementación/ListaCliente.cpp"
        "Proyecto1/Archivos de implementación/RegistroEspera.cpp"
        "Proyecto1/Archivos de implementación/ListaRegistroEspera.cpp"
        "Proyecto1/Archivos de implementación/MenuPrincipal.cpp")

# Prefer target_include_directories to avoid global include pollution
target_include_directories(Proyecto1 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/Proyecto1/Archivos de Cabecera")
