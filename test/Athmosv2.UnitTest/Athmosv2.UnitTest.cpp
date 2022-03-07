#include "pch.h"
#include "CppUnitTest.h"
#include "../../src/Athmosv2.Application/UserServices.h"
#include "../../src/Athmosv2.Infrastructure/Repository.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Athmosv2UnitTest
{
	TEST_CLASS(Athmosv2UnitTest)
	{
	public:
		
		TEST_METHOD(Test_CrearUsuario)
		{
			//crear repositoryo
			IRepository* r;
			r = new Repository();

			UserServices userServices(r);

			string id = "20";
			userServices.CreateUser("william", "david", "lopez@", id);

			//verificacion
			User user = userServices.ObtenerUsuario("20");

			Assert::AreEqual(user.GetId(), id);
		}

		TEST_METHOD(Test_Buscar)
		{
			//crear repositoryo
			IRepository* r;
			r = new Repository();

			UserServices userServices(r);

			list<User> users = userServices.ObtenerUsuarios();

			//verificacion
			string strSize = to_string(users.size());
			string strConst = to_string(5);

			Assert::AreEqual(strSize, strConst);
		}
	};
}
