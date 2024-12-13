#include "pch.h"
#include "CppUnitTest.h"
#include "../Demo/Room.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Hospital;
namespace Tests
{
	TEST_CLASS(RoomTests)
	{
	public:

		TEST_METHOD(Ctor_ValidData_Success)
		{
			int number{ 175 };
			auto  room = Room::CreateRoom(number);

			Assert::AreEqual(room->GetNumber(), number);
		}

		TEST_METHOD(AddPatient_ValidData_True)
		{
			
			const std::string firstName{ "ϸ��" };
			const std::string secondName{ "������" };
			const std::string patronymicName{ "��������" };
			const std::string disease{ "�������" };
			int number{ 175 };
			auto  patient = Patient::CreatePatient(firstName, secondName, patronymicName, disease);
			auto  room = Room::CreateRoom(number);

			auto result = room->AddPatient(patient);

			Assert::IsTrue(result);
		}
	};
}