#include "Arc.hpp"

Arc::Arc(Node* n1, Node* n2, Arc::ORIENTATION o) :
    m_nodes(n1, n2),
    m_orientation(o)
{
    m_shape.setFillColor(sf::Color::White);
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
    sf::Vector2f pFirst = m_nodes.first->getPosition();
    sf::Vector2f pSecond = m_nodes.second->getPosition();
    double diffX = pSecond.x - pFirst.x;
    double diffY = pSecond.y - pFirst.y;
    double hypotenuse = std::sqrt(diffX*diffX + diffY*diffY);

    m_shape.setPosition(pFirst);
    m_shape.setSize(sf::Vector2f(hypotenuse, 2));
    m_shape.setRotation((pSecond.y < pFirst.y) ? (360 - (std::acos(diffX / hypotenuse) * 180 / M_PI)) : (std::acos(diffX / hypotenuse) * 180 / M_PI));
}

void Arc::select()
{
    m_selected = true;
    m_shape.setOutlineColor(sf::Color::Red);
    m_shape.setOutlineThickness(1);
}

void Arc::unselect()
{
    m_selected = false;
	m_shape.setOutlineColor(sf::Color::Transparent);
	m_shape.setOutlineThickness(0);
}

bool Arc::isIn(sf::FloatRect rect)
{
    sf::Vector2f pos(m_shape.getPosition());
    return (rect.contains(pos)\
        && rect.contains(pos.x + m_shape.getSize().x, pos.y + m_shape.getSize().y)
    );
}


void Arc::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_shape, states);
}