#include "Node.hpp"

bool Node::dragging = false;

Node::Node(int x, int y) :
    m_shape(10.f),
	m_dragged(false)
{
    m_shape.setFillColor(sf::Color::White);
    m_shape.setPosition(x, y);
	m_shape.setOutlineColor(sf::Color::White);

	m_selected = false;
}

Node::~Node()
{
    
}

void Node::update(sf::Window& window)
{
}

void Node::drag(int mouseX, int mouseY)
{
	if (!dragging || m_dragged)
	{
		if (!m_dragged && sf::Mouse::isButtonPressed(sf::Mouse::Left) && containPoint(mouseX, mouseY))
		{
			m_dragged = true;
			dragging = true;
		}
		else if (m_dragged && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			m_shape.setPosition(mouseX - m_shape.getRadius(), mouseY - m_shape.getRadius());
		}
		else
		{
			m_dragged = false;
			dragging = false;
		}
	}
}

void Node::mouseOn(int mouseX, int mouseY)
{
	if (!m_selected)
	{
		if (containPoint(mouseX, mouseY) && !dragging)
		{
			m_shape.setOutlineThickness(1);
		}
		else
		{
			m_shape.setOutlineThickness(0);
		}
	}
}

bool Node::containPoint(int x, int y)
{
    sf::Vector2f center = getPosition();

    float distance = std::sqrt((center.x - x)*(center.x - x) + (center.y - y)*(center.y - y));
    return (distance <= m_shape.getRadius());
}

sf::Vector2f Node::getPosition()
{
    return sf::Vector2f(m_shape.getPosition().x + m_shape.getRadius(), m_shape.getPosition().y + m_shape.getRadius());
}

void Node::setColor(sf::Color c)
{
	m_shape.setFillColor(c);
}

void Node::select()
{
	m_selected = true;
	m_shape.setOutlineColor(sf::Color::Red);
	m_shape.setOutlineThickness(1);
}

void Node::unselect()
{
	m_selected = false;
	m_shape.setOutlineColor(sf::Color::Transparent);
	m_shape.setOutlineThickness(0);
}

void Node::addNeighbor(Node * n)
{
	m_neighborhood.push_back(n);
}

bool Node::gotNeighbor(Node * n)
{
	bool c = false;
	for (auto node : m_neighborhood)
	{
		c = (c || (n == node));
	}
	return c;
}

// A TESTER
void Node::removeNeighbor(Node* n)
{
	if (gotNeighbor(n))
		m_neighborhood.erase(m_neighborhood.cbegin() + indNeighbor(n));
}

// A TESTER
int Node::indNeighbor(Node* n)
{
	unsigned int i = 0;
	while (i < m_neighborhood.size() && m_neighborhood[i] != n)
		i++;
	return (m_neighborhood[i] == n ? i : -1);
}

bool Node::isIn(sf::FloatRect rect)
{
	sf::Vector2f pos(getPosition());

	return (rect.contains(pos.x + m_shape.getRadius(), pos.y)\
		&& rect.contains(pos.x - m_shape.getRadius(), pos.y)\
		&& rect.contains(pos.x, pos.y + m_shape.getRadius())\
		&& rect.contains(pos.x, pos.y - m_shape.getRadius())\
	);
}

void Node::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_shape, states);
}