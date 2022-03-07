#include "../Athmosv2.Domain/IRepository.h"
#include "DataContext.h"
#pragma once
class Repository :
    public IRepository
{
private:
	DataContext context;

public:
	Repository() {
		this->context = DataContext();
	}

public:
	virtual void Create(User user) {
		context.GetUsers().push_front(user);
	};

	virtual void Modify(User user) {
		for (User u: context.GetUsers()) {
			if (u.GetId() == user.GetId()) {
				u.ChangeMainAttributes(user.GetNombre(), user.GetApellido());
			}
		}
	};

	virtual User Get(string id) {
		User userVacio = User::Build("", "", "", "");

		for (User u : context.GetUsers()) {
			if (u.GetId() == id) {
				return u;
			}
		}

		return userVacio;
	};

	virtual list<User> GetAll() {
		return context.GetUsers();
	};
};

