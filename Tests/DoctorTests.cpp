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
			const std::string firstName{ "Иван" };
			const std::string secondName{ "Иванов" };
			const std::string patronymicName{ "Ивановиич" };
			const std::string specialization{ "Доктор" };

			auto  doctor = Doctor::CreateDoctor(firstName, secondName, patronymicName, specialization);
			
			Assert::AreEqual(doctor->GetFirstName(), firstName);
			Assert::AreEqual(doctor->GetSecondName(), secondName);
			Assert::AreEqual(doctor->GetPatronymicName(), patronymicName);
			Assert::AreEqual(doctor->GetSpecialization(), specialization);
		}

		TEST_METHOD(AddPatient_ValidData_True)
		{
			const std::string firstName1{ "Иван" };
			const std::string secondName1{ "Иванов" };
			const std::string patronymicName1{ "Ивановиич" };
			const std::string specialization{ "Доктор" };
			const std::string firstName2{ "Пётр" };
			const std::string secondName2{ "Петров" };
			const std::string patronymicName2{ "Петрович" };
			const std::string disease{ "Болезнь" };
			auto  doctor = Doctor::CreateDoctor(firstName1, secondName1, patronymicName1, specialization);
			auto  patient = Patient::CreatePatient(firstName2, secondName2, patronymicName2, disease);

			auto result = doctor->AddPatient(patient);

			Assert::IsTrue(result);
		}
	};
}