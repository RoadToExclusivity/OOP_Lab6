#include "stdafx.h"
#include "Node.h"

CNode::CNode(const std::string &s)
	:m_value(s), m_prev(std::shared_ptr<CNode>()), m_next(std::shared_ptr<CNode>())
{
}

std::shared_ptr<const CNode> CNode::GetPrev() const
{
	return m_prev;
}

std::shared_ptr<const CNode> CNode::GetNext() const
{
	return m_next;
}

std::string CNode::GetValue() const
{

}

void CNode::SetPrev(std::shared_ptr<CNode> &prev)
{
	m_prev = prev;
}

void CNode::SetNext(std::shared_ptr<CNode> &next)
{
	m_next = next;
}