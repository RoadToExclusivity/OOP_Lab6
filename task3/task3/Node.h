#pragma once
class CNode
{
public:
	CNode(const std::string &s);

	std::shared_ptr<const CNode> GetPrev() const;
	std::shared_ptr<const CNode> GetNext() const;
	std::string GetValue() const;
	void SetPrev(std::shared_ptr<CNode> &prev);
	void SetNext(std::shared_ptr<CNode> &prev);

private:
	std::string m_value;
	std::shared_ptr<CNode> m_next, m_prev;
};

