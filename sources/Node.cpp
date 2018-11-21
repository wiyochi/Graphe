#include "Node.hpp"

int Node::nodeNumber = 0;

Node::Node(int x, int y) :
    m_shape(10.f)
{
    m_shape.setFillColor(sf::Color::White);
    m_shape.setPosition(x, y);
    nodeNumber++;
}

Node::~Node()
{
    
}

void Node::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_shape, states);
}