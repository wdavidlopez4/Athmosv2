// Athmosv2.App.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "../../src/Athmosv2.Infrastructure/Repository.h"
#include "../../src/Athmosv2.Application/UserServices.h"
#include "../../src/Athmosv2.Domain/IRepository.h"
#include <iostream>
#include <iomanip>

void Program(UserServices userServices) {
	int i;

	cout << "Bienvenido. Seleccione una opcion. ";
	cout << "1. Mostrar todos los usuarios ";
	cout << "2. Modificar usuario ";
	cout << "3. Crear un usuario ";

	cin >> i;

	if (i == 1) {
		const char separator = ' ';
		const int nameWidth = 6;
		const int numWidth = 8;

		list<User> us = userServices.ObtenerUsuarios();
		for (User u : us) {
			cout << left << setw(nameWidth) << setfill(separator) << u.GetNombre();
			cout << left << setw(nameWidth) << setfill(separator) << u.GetApellido();
			cout << left << setw(nameWidth) << setfill(separator) << u.GetCorreo();
			cout << endl;
		}
	}
	else if (i == 2) {
		string nombre, apellido, id;

		cout << "ingrese el nombre:";
		cin >> nombre;

		cout << "ingrese el apellido:";
		cin >> apellido;

		cout << "ingrese el Id del usuario a modificar:";
		cin >> id;

		userServices.ModificarUser(nombre, apellido, id);

		cout << "se a modificado exitosamente: " << endl;
		cout << nombre << endl;
	}
	else if (i == 3) {
		string nombre, apellido, id, correo;
		cout << "ingrese el nombre:";
		cin >> nombre;

		cout << "ingrese el apellido:";
		cin >> apellido;

		cout << "ingrese el correo:";
		cin >> correo;

		cout << "ingrese el Id:";
		cin >> id;

		userServices.CreateUser(nombre, apellido, correo, id);

		cout << "se ha creado exitosamente: " << endl;
		cout << nombre << endl;

	}
	else {
		cout << "Ninguna opcion seleccionada ";
	}
}

void Config() {
	//crear repositoryo
	IRepository* r;
	r = new Repository();

	//IOC
	UserServices userServices(r);

	//ejecutar programa
	Program(userServices);
}

int main()
{
    Config();
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
