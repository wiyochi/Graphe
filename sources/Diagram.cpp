#include "Diagram.hpp"

Diagram::Diagram() :
	m_iGraph(-1),
	m_mode(Diagram::SELECTION),
	m_selectedNode(nullptr),
	m_nodesForArc(nullptr, nullptr),
	m_switchOT(0),
	m_mousePressed(false),
	m_keyboardPressed(false)
{
	addGraph();
	m_graphs[m_iGraph]->addNode(100, 100);
	m_graphs[m_iGraph]->addNode(50, 50);
	m_graphs[m_iGraph]->addArc(0, 1);
}

Diagram::~Diagram()
{
	for(auto g : m_graphs)
	{
		delete g;
	}
}


void Diagram::addGraph()
{
	m_graphs.push_back(new Graph());
	m_iGraph = m_graphs.size() - 1;
	m_graphs[m_iGraph]->setColor(sf::Color(distrib(re), distrib(re), distrib(re)));
	std::cout << "Add new graphe" << std::endl;
}

void Diagram::update(sf::RenderWindow& window)
{
	int mouseX = sf::Mouse::getPosition(window).x;
	int mouseY = sf::Mouse::getPosition(window).y;

	if (!m_mousePressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_mousePressed = true;
		switch (m_mode)
		{
		case ADD_NODE:
			m_graphs[m_iGraph]->addNode(mouseX, mouseY);
			break;
		case ADD_ARC:
			for (auto g : m_graphs)
			{
				for (uint i = 0; i < g->getNodeCount(); i++)
				{
					if ((*g)[i]->containPoint(mouseX, mouseY))
					{
						if (m_switchOT == 0)
						{
							if (m_nodesForArc.first) m_nodesForArc.first->unselect();
							m_nodesForArc.first = (*g)[i];
							m_nodesForArc.first->select();
							m_switchOT = 1;
						}
						else
						{
							if (m_nodesForArc.second) m_nodesForArc.second->unselect();
							m_nodesForArc.second = (*g)[i];
							m_nodesForArc.second->select();
							m_switchOT = 0;
						}
					}
				}
			}
			break;
		case MOVE_NODE:
			break;
		case SELECTION:
			for (auto g : m_graphs)
			{
				for (uint i = 0; i < g->getNodeCount(); i++)
				{
					if ((*g)[i]->containPoint(mouseX, mouseY))
					{
						if (m_selectedNode) m_selectedNode->unselect();
						m_selectedNode = (*g)[i];
						m_selectedNode->select();
					}
				}
			}
			break;
		}
	}
	else if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_mousePressed = false;
	}

	if (!m_keyboardPressed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
		{
			m_keyboardPressed = true;
			addGraph();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			m_keyboardPressed = true;
			m_iGraph = (m_iGraph + 1) % m_graphs.size();
			std::cout << "Changement sur le graphe " << m_graphs[m_iGraph]->getID() << std::endl;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			m_keyboardPressed = true;
			m_iGraph = (m_iGraph - 1) < 0 ? m_graphs.size() - 1 : (m_iGraph - 1);
			std::cout << "Changement sur le graphe " << m_graphs[m_iGraph]->getID() << std::endl;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0))
		{
			m_keyboardPressed = true;
			m_mode = Diagram::SELECTION;
			for (auto g : m_graphs)
			{
				for (uint i = 0; i < g->getNodeCount(); i++)
				{
					(*g)[i]->unselect();
				}
			}
			std::cout << "Mode Selection" << std::endl;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
		{
			m_keyboardPressed = true;
			m_mode = Diagram::ADD_NODE;
			std::cout << "Mode Add node" << std::endl;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
		{
			m_keyboardPressed = true;
			m_mode = Diagram::MOVE_NODE;
			std::cout << "Mode Move" << std::endl;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
		{
			m_keyboardPressed = true;
			m_mode = Diagram::ADD_ARC;
			for (auto g : m_graphs)
			{
				for (uint i = 0; i < g->getNodeCount(); i++)
				{
					(*g)[i]->unselect();
				}
			}
			std::cout << "Mode Add arc" << std::endl;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
		{
			m_keyboardPressed = true;
			if (m_mode == Diagram::ADD_ARC)
			{
				m_graphs[m_iGraph]->addArc(m_nodesForArc.first, m_nodesForArc.second);
			}
		}
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::N) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)\
				&& !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0)\
				&& !sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)\
				&& !sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3) && !sf::Keyboard::isKeyPressed(sf::Keyboard::V))
	{
		m_keyboardPressed = false;
	}

	// If selection, treatments for dragging nodes
	if(m_mode == MOVE_NODE)
	{
		for (auto g : m_graphs)
		{
			for (uint i = 0; i < g->getNodeCount(); i++)
			{
				(*g)[i]->drag(mouseX, mouseY);
				(*g)[i]->mouseOn(mouseX, mouseY);
			}
		}
	}

	// Update arcs (for now)
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
