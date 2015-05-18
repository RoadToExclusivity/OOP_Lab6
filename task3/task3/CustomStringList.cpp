#include "stdafx.h"
#include "CustomStringList.h"

using namespace std;

CCustomStringList::CCustomStringList()
	:m_first(shared_ptr<CNode>()), m_last(shared_ptr<CNode>())
{
}

std::shared_ptr<CNode> CCustomStringList::GetFirst() const
{
	return m_first;
}

std::shared_ptr<CNode> CCustomStringList::GetLast() const
{
	return m_last;
}

std::shared_ptr<CNode> CCustomStringList::GetNext(const std::shared_ptr<const CNode> ptr) const
{
	return ptr->GetNext();
}

std::shared_ptr<CNode> CCustomStringList::GetPrev(const std::shared_ptr<const CNode> ptr) const
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
			break;
		}
		else
		{
			curPtr = curPtr->GetNext();
		}
	}

	if (found)
	{
		shared_ptr<CNode> tmp = curPtr->GetPrev();
		newPtr->SetPrev(tmp);
		newPtr->SetNext(curPtr);
		if (tmp)
		{
			tmp->SetNext(newPtr);
		}
		else
		{
			m_first = newPtr;
		}
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
	if (!elem->GetPrev())
	{
		m_first = elem->GetNext();
	}
	else
	{
		if (!elem->GetNext())
		{
			m_last = elem->GetPrev();
		}
		else
		{
			shared_ptr<CNode> prev = elem->GetPrev();
			prev->SetNext(elem->GetNext());
			elem->GetNext()->SetPrev(prev);
		}
	}
}