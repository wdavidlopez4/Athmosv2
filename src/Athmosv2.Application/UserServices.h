#include "../Athmosv2.Domain/IRepository.h"
#include <list>
#pragma once
class UserServices
{
private:
	IRepository* repository;

public:
	UserServices(IRepository* repository) {
		this->repository = repository;
	}

public:
	void CreateUser(string nombre, string apellido, string correo, string id) {
		User user = User::Build(nombre, apellido, correo, id);

		this->repository->Create(user);
	}
	void ModificarUser(string nombre, string apellido, string id) {
		User user = this->repository->Get(id);
		user.ChangeMainAttributes(nombre, apellido);

		this->repository->Modify(user);
	}
	list<User> ObtenerUsuarios() {
		return this->repository->GetAll();
	}
	User ObtenerUsuario(string id) {
		return this->repository->Get(id);
	}
};

