#include "pch.h"
#include "CppUnitTest.h"
#include "../Demo/Doctor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Hospital;
namespace Tests
{
	TEST_CLASS(DoctorTests)
	{
	public:

		TEST_METHOD(Ctor_ValidData_Success)
		{
			const std::string firstName{ "����" };
			const std::string secondName{ "������" };
			const std::string patronymicName{ "���������" };
			const std::string specialization{ "������" };

			auto  doctor = Doctor::CreateDoctor(firstName, secondName, patronymicName, specialization);
			
			Assert::AreEqual(doctor->GetFirstName(), firstName);
			Assert::AreEqual(doctor->GetSecondName(), secondName);
			Assert::AreEqual(doctor->GetPatronymicName(), patronymicName);
			Assert::AreEqual(doctor->GetSpecialization(), specialization);
		}

		TEST_METHOD(AddPatient_ValidData_True)
		{
			const std::string firstName1{ "����" };
			const std::string secondName1{ "������" };
			const std::string patronymicName1{ "���������" };
			const std::string specialization{ "������" };
			const std::string firstName2{ "ϸ��" };
			const std::string secondName2{ "������" };
			const std::string patronymicName2{ "��������" };
			const std::string disease{ "�������" };
			auto  doctor = Doctor::CreateDoctor(firstName1, secondName1, patronymicName1, specialization);
			auto  patient = Patient::CreatePatient(firstName2, secondName2, patronymicName2, disease);

			auto result = doctor->AddPatient(patient);

			Assert::IsTrue(result);
		}
	};
}