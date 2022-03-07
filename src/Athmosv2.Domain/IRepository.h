
#include "User.h"
#include <list>
#pragma once
class IRepository
{
public:
	virtual void Create(User user) = 0;
	virtual void Modify(User user) = 0;
	virtual User Get(string id) = 0;
	virtual list<User> GetAll() = 0;
};

