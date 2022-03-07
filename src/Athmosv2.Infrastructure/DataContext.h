#include "../Athmosv2.Domain/User.h"
#include <list>
#pragma once
class DataContext
{
private:
	list<User> users;

public:
	DataContext() {
		if (users.size() == 0) {
			this->users.begin();
			users.push_front(User::Build("william", "ss", "will@", "1"));
			users.push_front(User::Build("deivid", "lop", "dei@", "2"));
			users.push_front(User::Build("santaigo", "sanc", "sant@", "3"));
			users.push_front(User::Build("pedro", "mend", "pedro@", "4"));
			users.push_front(User::Build("juan", "camar", "juan@", "5"));
		}
	}

public:
	list<User> GetUsers() {
		return users;
	}
};

