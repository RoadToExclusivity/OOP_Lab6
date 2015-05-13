#include "stdafx.h"
#include "Student.h"

using namespace std;

bool IsCorrectString(const std::string &s)
{
	for (char c : s)
	{
		if (!isalpha(c))
		{
			return false;
		}
	}

	return true;
}

bool IsCorrectAge(unsigned age)
{
	return (age <= MAX_AGE && age >= MIN_AGE);
}

CStudent::CStudent(string name, string surname, string patronymic, unsigned age)
{
	if (!IsCorrectString(name) || !IsCorrectString(surname) || !IsCorrectString(patronymic) || name.length() == 0 || surname.length() == 0)
	{
		throw invalid_argument("Invalid full student's name");
	}

	if (!IsCorrectAge(age))
	{
		throw out_of_range("Wrong age");
	}

	m_name = move(name);
	m_surname = move(surname);
	m_patronymic = move(patronymic);

	m_age = age;
}

std::string CStudent::GetName() const
{
	return m_name;
}

std::string CStudent::GetSurname() const
{
	return m_surname;
}

std::string CStudent::GetPatronymic() const
{
	return m_patronymic;
}

unsigned CStudent::GetAge() const
{
	return m_age;
}

void CStudent::Rename(std::string name, std::string surname, std::string patronymic)
{
	if (!IsCorrectString(name) || !IsCorrectString(surname) || !IsCorrectString(patronymic) || name.length() == 0 || surname.length() == 0)
	{
		throw invalid_argument("Invalid full student's name");
	}

	m_name = move(name);
	m_surname = move(surname);
	m_patronymic = move(patronymic);
}

void CStudent::SetAge(unsigned newAge)
{
	if (!IsCorrectAge(newAge))
	{
		throw out_of_range("Wrong age");
	}

	if (newAge < m_age)
	{
		throw domain_error("New age less than previous");
	}

	m_age = newAge;
}