#include "doctor.h"

Hospital::Doctor::Doctor(const std::string& FirstName, std::string& SecondName, std::string& Patronymic, std::string& specialization) :FirstName{ FirstName }, SecondName{ SecondName }, Patronymic{ Patronymic }, specialization{ specialization } {}
