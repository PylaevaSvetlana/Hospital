#pragma once
#include "Patient.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

namespace Hospital
{
	/*
	* @brief класс Пациент.
	*/
	class Patient;
	class Room;
	/*
	* @brief класс Палата.
	*/
	class Room final : public std::enable_shared_from_this<Room>
	{
	private:
		/*
	    * @brief номер палаты.
	    */
		int number;
		/*
		* @brief вектор указателей на пациентов.
		*/
		std::vector< Patient* > patients;
		/*
		* @brief конструктор класса Палата.
		* @param number - номер палаты.
		*/
		Room(int number);
	public:
		/*
		* @brief метод создания объекта палата.
		* @param number - номер палаты.
		*/
		static std::shared_ptr<Room> CreateRoom(int number);
		/*
		* @brief метод сериализации в строку ToString().
		* @return возвращает строку с данными о палате.
		*/
		std::string ToString() const;
		/*
		* @brief метод получения номера палаты.
		* @return возвращает номер палаты.
		*/
		int GetNumber() const noexcept;
		/*
		* @brief метод добавления связи палаты с пациентом.
		* @param patient - объект класса пациент.
		* @return возваращет true если все прошло успешно.
		*/
		bool AddPatient(std::shared_ptr<Patient>& patient);
		/*
		* @brief метод получения пациентов палаты.
		* @return возвращает вектор пациентов палаты.
		*/
		std::vector<Patient*>& GetPatients() noexcept;
		/*
		* @brief метод получения пациентов палаты.
		* @return возвращает вектор пациентов палаты.
		*/
		const std::vector<Patient*>& GetPatients() const noexcept;
	};
}