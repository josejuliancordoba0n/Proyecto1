cmake_minimum_required(VERSION 4.3)
project(Proyecto1)

set(CMAKE_CXX_STANDARD 14)

include_directories("Proyecto1/Clases individuales")

add_executable(Proyecto1
        "Proyecto1/Clases individuales/Cliente.cpp"
        "Proyecto1/Clases individuales/Cliente.h"
        Proyecto1/main.cpp
        "Proyecto1/Clases Listas/LlstaCliente.cpp"
        "Proyecto1/Clases Listas/LlstaCliente.h")
