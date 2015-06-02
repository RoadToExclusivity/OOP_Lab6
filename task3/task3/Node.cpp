#include "stdafx.h"
#include "Node.h"

CNode::CNode(const std::string &s)
	:m_value(s), m_prev(std::shared_ptr<CNode>()), m_next(std::shared_ptr<CNode>())
{
}

const std::shared_ptr<CNode> CNode::GetPrev() const
{
	return m_prev;
}

const std::shared_ptr<CNode> CNode::GetNext() const
{
	return m_next;
}

std::string CNode::GetValue() const
{
	return m_value;
}

void CNode::SetPrev(const std::shared_ptr<CNode> &prev)
{
	m_prev = prev;
}

void CNode::SetNext(const std::shared_ptr<CNode> &next)
{
	m_next = next;
}

void CNode::Free()
{
	m_prev = nullptr;
	m_next = nullptr;
}