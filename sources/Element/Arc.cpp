#include "Arc.hpp"

Arc::Arc(Node* n1, Node* n2, Arc::ORIENTATION o) :
    m_nodes(n1, n2),
    m_orientation(o)
{
	m_line[0] = sf::Vertex(n1->getPosition());
	m_line[1] = sf::Vertex(n2->getPosition());
	n1->addNeighbor(n2);
	n2->addNeighbor(n1);
}

Arc::~Arc()
{
}

Node* Arc::getFirstNode() const
{
    return m_nodes.first;
}

Node* Arc::getSecondNode() const
{
    return m_nodes.second;
}

Arc::ORIENTATION Arc::getOrientation() const
{
    return m_orientation;
}

void Arc::update()
{
	m_line[0] = sf::Vertex(m_nodes.first->getPosition());
	m_line[1] = sf::Vertex(m_nodes.second->getPosition());
}

void Arc::select()
{
    m_selected = true;
	m_line[0].color = sf::Color::Red;
	m_line[1].color = sf::Color::Red;
}

void Arc::unselect()
{
    m_selected = false;
	m_line[0].color = sf::Color::White;
	m_line[1].color = sf::Color::White;
}

bool Arc::isIn(sf::FloatRect rect)
{
	return(rect.contains(m_line[0].position) && rect.contains(m_line[1].position));
}


void Arc::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_line, 2, sf::Lines, states);
}