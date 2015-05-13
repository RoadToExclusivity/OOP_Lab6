#include "stdafx.h"
#include "../task2/Student.h"

using namespace std;

const string NAME = "Henrick", SURNAME = "Ahnberg", PATRONYMIC = "BDawg";
const unsigned AGE = 24;

BOOST_AUTO_TEST_CASE(WrongName)
{
	{
		try
		{
			CStudent student("", SURNAME, PATRONYMIC, AGE);
			BOOST_CHECK(false);
		}
		catch (invalid_argument &e)
		{
			BOOST_CHECK(true);
		}
	}
	
	{
		try
		{
			CStudent student(NAME, "", PATRONYMIC, AGE);
			BOOST_CHECK(false);
		}
		catch (invalid_argument &e)
		{
			BOOST_CHECK(true);
		}
	}

	{
		try
		{
			CStudent student("D123", SURNAME, PATRONYMIC, AGE);
			BOOST_CHECK(false);
		}
		catch (invalid_argument &e)
		{
			BOOST_CHECK(true);
		}
	}

	{
		try
		{
			CStudent student(NAME, "D123", PATRONYMIC, AGE);
			BOOST_CHECK(false);
		}
		catch (invalid_argument &e)
		{
			BOOST_CHECK(true);
		}
	}

	{
		try
		{
			CStudent student(NAME, SURNAME, "D123", AGE);
			BOOST_CHECK(false);
		}
		catch (invalid_argument &e)
		{
			BOOST_CHECK(true);
		}
	}

	{
		try
		{
			CStudent student(NAME, SURNAME, PATRONYMIC, 10);
			BOOST_CHECK(false);
		}
		catch (out_of_range &e)
		{
			BOOST_CHECK(true);
		}
	}

	{
		try
		{
			CStudent student(NAME, SURNAME, PATRONYMIC, 70);
			BOOST_CHECK(false);
		}
		catch (out_of_range &e)
		{
			BOOST_CHECK(true);
		}
	}
}

BOOST_AUTO_TEST_CASE(ValidName)
{
	try
	{
		CStudent student(NAME, SURNAME, PATRONYMIC, AGE);
		BOOST_CHECK_EQUAL(student.GetAge(), AGE);
		BOOST_CHECK_EQUAL(student.GetName(), NAME);
		BOOST_CHECK_EQUAL(student.GetSurname(), SURNAME);
		BOOST_CHECK_EQUAL(student.GetPatronymic(), PATRONYMIC);
	}
	catch (exception &e)
	{
		BOOST_CHECK(false);
	}
}

BOOST_AUTO_TEST_CASE(RenameTests)
{
	CStudent student(NAME, SURNAME, PATRONYMIC, AGE);
	
	{
		try
		{
			student.Rename("", SURNAME, PATRONYMIC);
			BOOST_CHECK(false);
		}
		catch (invalid_argument &e)
		{
			BOOST_CHECK(true);
		}
	}
	
	BOOST_CHECK_EQUAL(student.GetName(), NAME);
	BOOST_CHECK_EQUAL(student.GetSurname(), SURNAME);
	BOOST_CHECK_EQUAL(student.GetPatronymic(), PATRONYMIC);

	{
		try
		{
			student.Rename(NAME, "", PATRONYMIC);
			BOOST_CHECK(false);
		}
		catch (invalid_argument &e)
		{
			BOOST_CHECK(true);
		}
	}

	BOOST_CHECK_EQUAL(student.GetName(), NAME);
	BOOST_CHECK_EQUAL(student.GetSurname(), SURNAME);
	BOOST_CHECK_EQUAL(student.GetPatronymic(), PATRONYMIC);

	{
		try
		{
			student.Rename(NAME, SURNAME, "");
			BOOST_CHECK(true);
		}
		catch (exception &e)
		{
			BOOST_CHECK(false);
		}
	}

	BOOST_CHECK_EQUAL(student.GetName(), NAME);
	BOOST_CHECK_EQUAL(student.GetSurname(), SURNAME);
	BOOST_CHECK_EQUAL(student.GetPatronymic(), "");

	{
		try
		{
			student.Rename("D123", SURNAME, PATRONYMIC);
			BOOST_CHECK(false);
		}
		catch (invalid_argument &e)
		{
			BOOST_CHECK(true);
		}
	}

	BOOST_CHECK_EQUAL(student.GetName(), NAME);
	BOOST_CHECK_EQUAL(student.GetSurname(), SURNAME);
	BOOST_CHECK_EQUAL(student.GetPatronymic(), "");

	{
		try
		{
			student.Rename(NAME, "D123", PATRONYMIC);
			BOOST_CHECK(false);
		}
		catch (invalid_argument &e)
		{
			BOOST_CHECK(true);
		}
	}

	BOOST_CHECK_EQUAL(student.GetName(), NAME);
	BOOST_CHECK_EQUAL(student.GetSurname(), SURNAME);
	BOOST_CHECK_EQUAL(student.GetPatronymic(), "");

	{
		try
		{
			student.Rename(NAME + "Q", SURNAME + "W", PATRONYMIC);
			BOOST_CHECK(true);
		}
		catch (exception &e)
		{
			BOOST_CHECK(false);
		}
	}

	BOOST_CHECK_EQUAL(student.GetName(), NAME + "Q");
	BOOST_CHECK_EQUAL(student.GetSurname(), SURNAME + "W");
	BOOST_CHECK_EQUAL(student.GetPatronymic(), PATRONYMIC);
}

BOOST_AUTO_TEST_CASE(AgeChangeTests)
{
	CStudent student(NAME, SURNAME, PATRONYMIC, AGE);

	{
		try
		{
			student.SetAge(10);
			BOOST_CHECK(false);
		}
		catch (out_of_range &e)
		{
			BOOST_CHECK(true);
		}
	}

	BOOST_CHECK_EQUAL(student.GetAge(), AGE);

	{
		try
		{
			student.SetAge(990);
			BOOST_CHECK(false);
		}
		catch (out_of_range &e)
		{
			BOOST_CHECK(true);
		}
	}

	BOOST_CHECK_EQUAL(student.GetAge(), AGE);

	{
		try
		{
			student.SetAge(AGE - 1);
			BOOST_CHECK(false);
		}
		catch (domain_error &e)
		{
			BOOST_CHECK(true);
		}
	}

	BOOST_CHECK_EQUAL(student.GetAge(), AGE);

	{
		try
		{
			student.SetAge(AGE + 1);
			BOOST_CHECK(true);
		}
		catch (exception &e)
		{
			BOOST_CHECK(false);
		}
	}

	BOOST_CHECK_EQUAL(student.GetAge(), AGE + 1);
}