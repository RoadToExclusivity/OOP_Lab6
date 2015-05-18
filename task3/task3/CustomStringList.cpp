#include "stdafx.h"
#include "CustomStringList.h"

using namespace std;

CCustomStringList::CCustomStringList()
	:m_first(shared_ptr<CNode>()), m_last(shared_ptr<CNode>())
{
}

std::shared_ptr<const CNode> CCustomStringList::GetFirst() const
{
	return m_first;
}

std::shared_ptr<const CNode> CCustomStringList::GetLast() const
{
	return m_last;
}

std::shared_ptr<const CNode> CCustomStringList::GetNext(const std::shared_ptr<const CNode> ptr) const
{
	return ptr->GetNext();
}

std::shared_ptr<const CNode> CCustomStringList::GetPrev(const std::shared_ptr<const CNode> ptr) const
{
	return ptr->GetPrev();
}

std::string CCustomStringList::GetVal(const std::shared_ptr<const CNode> ptr) const
{
	return ptr->GetValue();
}

void CCustomStringList::Insert(const std::string &s)
{
	auto newPtr = make_shared<CNode>(s);

	if (!m_first)
	{
		m_first = newPtr;
		m_last = newPtr;

		return;
	}

	auto curPtr = m_first;
	bool found = false;
	while (curPtr)
	{
		if (curPtr->GetValue() > s)
		{
			found = true;
		}
		else
		{
			curPtr = curPtr->GetNext();
		}
	}

	if (found)
	{
		shared_ptr<CNode> tmp = curPtr->GetPrev();
	}
	else
	{
		newPtr->SetPrev(m_last);
		m_last->SetNext(newPtr);
		m_last = newPtr;
	}
}

void CCustomStringList::Delete(const std::shared_ptr<CNode> elem)
{

}