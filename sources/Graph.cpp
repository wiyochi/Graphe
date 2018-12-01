#include "Graph.hpp"

int Graph::graphNumber = 0;

Graph::Graph() :
	m_color(sf::Color::White)
{
    m_ID = ++graphNumber;
}

Graph::~Graph()
{
    
}

void Graph::addNode(int x, int y)
{
    m_nodes.push_back(new Node(x, y));
    std::cout << "Ajout Node (" << getID() << ") : "\
            << x\
            << "," << y\
            << " : "\
            << getNodeCount()\
            << std::endl;
	m_nodes[m_nodes.size() - 1]->setColor(m_color);
}

void Graph::addArc(int iNode1, int iNode2)
{
    m_arcs.push_back(new Arc(m_nodes[iNode1], m_nodes[iNode2], Arc::UNDIRECTED));
    std::cout << "Ajout Arc (" << getID() << ") : "\
            << iNode1\
            << "," << iNode2\
            << " : "\
            << getArcCount()\
            << std::endl;
}

void Graph::addArc(Node * n1, Node * n2)
{
	if (contain(n1) && contain(n2))
	{
		m_arcs.push_back(new Arc(n1, n2, Arc::UNDIRECTED));
		std::cout << "Ajout Arc (" << getID() << ") : "\
			<< n1\
			<< "," << n2\
			<< " : "\
			<< getArcCount()\
			<< std::endl;
	}
}

std::size_t Graph::getNodeCount() const
{
    return m_nodes.size();
}

std::size_t Graph::getArcCount() const
{
    return m_arcs.size();
}

void Graph::setColor(sf::Color c)
{
	m_color = c;
	for (auto node : m_nodes)
	{
		node->setColor(m_color);
	}
}

bool Graph::contain(Node * node)
{
	bool c = false;
	for (auto n : m_nodes)
	{
		c = c || (n == node);
	}
	return c;
}

void Graph::update(sf::Window& window)
{
    for(auto node : m_nodes)
    {
        node->update(window);
    }
    for(auto arc : m_arcs)
    {
        arc->update();
    }
}

int Graph::getID() const
{
    return m_ID;
}

Node* Graph::operator[](int index)
{
    return m_nodes[index];
}


void Graph::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(auto n : m_nodes)
    {
        target.draw(*n, states);
    }

    for(auto a : m_arcs)
    {
        target.draw(*a, states);
    }
}