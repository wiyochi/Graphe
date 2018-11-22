#include "Graph.hpp"

int Graph::graphNumber = 0;

Graph::Graph()
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
}

std::size_t Graph::getNodeCount() const
{
    return m_nodes.size();
}

int Graph::getID() const
{
    return m_ID;
}


void Graph::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(auto n : m_nodes)
    {
        target.draw(*n, states);
    }
}