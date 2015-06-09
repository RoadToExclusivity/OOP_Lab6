#pragma once
class CNode
{
public:
	CNode(const std::string &s);

	const std::shared_ptr<CNode> GetPrev() const;
	const std::shared_ptr<CNode> GetNext() const;
	std::string GetValue() const;
	void SetPrev(const std::shared_ptr<CNode> &prev);
	void SetNext(const std::shared_ptr<CNode> &next);

private:
	std::string m_value;
	std::shared_ptr<CNode> m_prev;
	std::weak_ptr<CNode> m_next;
};

