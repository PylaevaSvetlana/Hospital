#include "pch.h"
#include "CppUnitTest.h"
#include "../Demo/Patient.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Hospital;
namespace Tests
{
	TEST_CLASS(PatientTests)
	{
	public:

		TEST_METHOD(Ctor_ValidKnownData_Success)
		{
			const std::string firstName{ "Пётр" };
			const std::string secondName{ "Петров" };
			const std::string patronymicName{ "Петрович" };
			const std::string disease{ "Болезнь" };

			auto  patient = Patient::CreatePatient(firstName, secondName, patronymicName, disease);

			Assert::AreEqual(patient->GetFirstName(), firstName);
			Assert::AreEqual(patient->GetSecondName(), secondName);
			Assert::AreEqual(patient->GetPatronymicName(), patronymicName);
			Assert::AreEqual(patient->GetDisease(), disease);
		}

		TEST_METHOD(AddDoctor_ValidData_True)
		{
			const std::string firstName1{ "Пётр" };
			const std::string secondName1{ "Петров" };
			const std::string patronymicName1{ "Петрович" };
			const std::string disease{ "Болезнь" };
			const std::string firstName2{ "Иван" };
			const std::string secondName2{ "Иванов" };
			const std::string patronymicName2{ "Ивановиич" };
			const std::string specialization{ "Доктор" };
			auto  patient = Patient::CreatePatient(firstName1, secondName1, patronymicName1, disease);
			auto  doctor = Doctor::CreateDoctor(firstName2, secondName2, patronymicName2, specialization);
			

			auto result = patient->AddDoctor(doctor);

			Assert::IsTrue(result);
		}

		TEST_METHOD(AddRoom_ValidData_True)
		{
			const std::string firstName{ "Пётр" };
			const std::string secondName{ "Петров" };
			const std::string patronymicName{ "Петрович" };
			const std::string disease{ "Болезнь" };
			int number{ 175 };
			auto  patient = Patient::CreatePatient(firstName, secondName, patronymicName, disease);
			auto  room = Room::CreateRoom(number);


			auto result = patient->AddRoom(room);

			Assert::IsTrue(result);
		}
	};
}