#pragma once
#include <iostream>
#include <string>

namespace Hospital
{
	class Doctor final
	{
	private:
		std::string FirstName;
		std::string SecondName;
		std::string Patronymic;
		std::string specialization;
	public:
		Doctor(const std::string& FirstName, std::string& SecondName, std::string& Patronymic, std::string& specialization);
	};

}
