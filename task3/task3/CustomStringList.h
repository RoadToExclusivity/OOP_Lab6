#pragma once
#include "Node.h"

class CCustomStringList
{
public:
	CCustomStringList();
	
	std::shared_ptr<const CNode> GetFirst() const;
	std::shared_ptr<const CNode> GetLast() const;
	std::shared_ptr<const CNode> GetNext(const std::shared_ptr<const CNode> ptr) const;
	std::shared_ptr<const CNode> GetPrev(const std::shared_ptr<const CNode> ptr) const;
	std::string GetVal(const std::shared_ptr<const CNode> ptr) const;

	void Insert(const std::string &s);
	void Delete(const std::shared_ptr<CNode> elem);
private:
	std::shared_ptr<CNode> m_first, m_last;
};

