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
	//BOOST_CHECK_EQUAL(list.GetVal(list.GetFirst()), "1");
	//BOOST_CHECK_EQUAL(list.GetVal(list.GetLast()), "2");
	//BOOST_CHECK_EQUAL(list.GetVal(list.GetNext(list.GetFirst())), "2");
	//BOOST_CHECK_EQUAL(list.GetVal(list.GetPrev(list.GetLast())), "1");
}