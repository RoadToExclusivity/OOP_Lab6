#include "stdafx.h"
#include "../task3/CustomStringList.h"

using namespace std;

BOOST_AUTO_TEST_CASE(CheckEmptyList)
{
	CCustomStringList list;
	BOOST_CHECK(list.GetFirst() == nullptr);
	BOOST_CHECK(list.GetLast() == nullptr);
}

BOOST_AUTO_TEST_CASE(SimpleListWithSize2)
{
	CCustomStringList list;
	list.Insert("1");
	BOOST_CHECK_EQUAL(list.GetFirst(), list.GetLast());
	BOOST_CHECK_EQUAL(list.GetVal(list.GetFirst()), "1");
	list.Insert("2");
	BOOST_CHECK_EQUAL(list.GetVal(list.GetFirst()), "1");
	BOOST_CHECK_EQUAL(list.GetVal(list.GetLast()), "2");
	BOOST_CHECK_EQUAL(list.GetVal(list.GetNext(list.GetFirst())), "2");
	BOOST_CHECK_EQUAL(list.GetVal(list.GetPrev(list.GetLast())), "1");
}

BOOST_AUTO_TEST_CASE(BigListCheck)
{
	CCustomStringList list;
	for (size_t i = 0; i < 10; ++i)
	{
		list.Insert(to_string(i));
	}

	auto ptr = list.GetFirst();
	for (size_t i = 0; i < 10; ++i)
	{
		BOOST_CHECK_EQUAL(ptr->GetValue(), to_string(i));
		ptr = list.GetNext(ptr);
	}
	BOOST_CHECK(ptr == nullptr);
}

BOOST_AUTO_TEST_CASE(ListDeleteCheck)
{
	CCustomStringList list;
	for (size_t i = 0; i < 10; ++i)
	{
		list.Insert(to_string(i));
	}

	auto ptr = list.GetFirst();
	list.Delete(ptr);
	ptr = list.GetLast();
	for (size_t i = 9; i > 0; --i)
	{
		BOOST_CHECK_EQUAL(ptr->GetValue(), to_string(i));
		ptr = list.GetPrev(ptr);
	}
	BOOST_CHECK(ptr == nullptr);

	ptr = list.GetFirst();
	for (size_t i = 1; i < 5; ++i)
	{
		ptr = list.GetNext(ptr);
	}
	list.Delete(ptr);

	ptr = list.GetFirst();
	for (size_t i = 1; i < 9; ++i)
	{
		if (i < 5)
		{
			BOOST_CHECK_EQUAL(ptr->GetValue(), to_string(i));
		}
		else
		{
			BOOST_CHECK_EQUAL(ptr->GetValue(), to_string(i + 1));
		}
		ptr = list.GetNext(ptr);
	}
	BOOST_CHECK(ptr == nullptr);

	list.Delete(list.GetLast());
	ptr = list.GetFirst();
	for (size_t i = 1; i < 8; ++i)
	{
		if (i < 5)
		{
			BOOST_CHECK_EQUAL(ptr->GetValue(), to_string(i));
		}
		else
		{
			BOOST_CHECK_EQUAL(ptr->GetValue(), to_string(i + 1));
		}
		ptr = list.GetNext(ptr);
	}
	BOOST_CHECK(ptr == nullptr);
}