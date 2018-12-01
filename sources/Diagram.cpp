#include "Diagram.h"

Diagram::Diagram() :
	m_iGraph(-1),
	m_mode(Diagram::SELECTION)
{
	addGraph();
	m_graphs[m_iGraph]->addNode(100, 100);
	m_graphs[m_iGraph]->addNode(50, 50);
	m_graphs[m_iGraph]->addArc(0, 1);
}

Diagram::~Diagram()
{
}


void Diagram::addGraph()
{
	m_graphs.push_back(new Graph());
	m_iGraph = m_graphs.size() - 1;
	m_graphs[m_iGraph]->setColor(sf::Color(distrib(re), distrib(re), distrib(re)));
}

void Diagram::update(sf::RenderWindow& window)
{
	if (!m_mousePressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_mousePressed = true;
		switch (m_mode)
		{
		case ADD_NODE:
			m_graphs[m_iGraph]->addNode(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
		case SELECTION:
			break;
		}
	}
	else
	{
		m_mousePressed = false;
	}

	if (!m_keyboardPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::N))
	{
		m_keyboardPressed = true;
		addGraph();
	}
	else if (!m_keyboardPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_keyboardPressed = true;
		m_iGraph = (m_iGraph + 1) % m_graphs.size();
	}
	else if (!m_keyboardPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_keyboardPressed = true;
		m_iGraph = (m_iGraph - 1) < 0 ? m_graphs.size() - 1 : (m_iGraph - 1);
	}
	else if (!m_keyboardPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0))
	{
		m_keyboardPressed = true;
		m_mode = Diagram::SELECTION;
	}
	else if (!m_keyboardPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
	{
		m_keyboardPressed = true;
		m_mode = Diagram::ADD_NODE;
	}
	else
	{
		m_keyboardPressed = false;
	}

	for (auto g : m_graphs)
	{
		g->update(window);
	}
}


void Diagram::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto g : m_graphs)
	{
		target.draw(*g, states);
	}
}
