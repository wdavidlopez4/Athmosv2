#include <string>
#include "Entity.h"

using namespace std;
#pragma once
class User :
    public Entity
{
private:
    string nombre, apellido, correo;

private:
    User(string nombre, string apellido, string correo, string id):Entity(id) {
        this->apellido = apellido;
        this->correo = correo;
        this->nombre = nombre;
    }

public:
    User static Build(string nombre, string apellido, string correo, string id) {
        User user(nombre, apellido, correo, id);
        return user;
    }

public:
    void ChangeMainAttributes(string nombre, string apellido) {
        this->apellido = apellido;
        this->nombre = nombre;
    }

    string GetId() {
        return id;
    }
    string GetNombre() {
        return nombre;
    }
    string GetApellido() {
        return apellido;
    }
    string GetCorreo() {
        return correo;
    }
};

