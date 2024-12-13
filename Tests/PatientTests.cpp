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
			const std::string firstName{ "ϸ��" };
			const std::string secondName{ "������" };
			const std::string patronymicName{ "��������" };
			const std::string disease{ "�������" };

			auto  patient = Patient::CreatePatient(firstName, secondName, patronymicName, disease);

			Assert::AreEqual(patient->GetFirstName(), firstName);
			Assert::AreEqual(patient->GetSecondName(), secondName);
			Assert::AreEqual(patient->GetPatronymicName(), patronymicName);
			Assert::AreEqual(patient->GetDisease(), disease);
		}

		TEST_METHOD(AddDoctor_ValidData_True)
		{
			const std::string firstName1{ "ϸ��" };
			const std::string secondName1{ "������" };
			const std::string patronymicName1{ "��������" };
			const std::string disease{ "�������" };
			const std::string firstName2{ "����" };
			const std::string secondName2{ "������" };
			const std::string patronymicName2{ "���������" };
			const std::string specialization{ "������" };
			auto  patient = Patient::CreatePatient(firstName1, secondName1, patronymicName1, disease);
			auto  doctor = Doctor::CreateDoctor(firstName2, secondName2, patronymicName2, specialization);
			

			auto result = patient->AddDoctor(doctor);

			Assert::IsTrue(result);
		}

		TEST_METHOD(AddRoom_ValidData_True)
		{
			const std::string firstName{ "ϸ��" };
			const std::string secondName{ "������" };
			const std::string patronymicName{ "��������" };
			const std::string disease{ "�������" };
			int number{ 175 };
			auto  patient = Patient::CreatePatient(firstName, secondName, patronymicName, disease);
			auto  room = Room::CreateRoom(number);


			auto result = patient->AddRoom(room);

			Assert::IsTrue(result);
		}
	};
}