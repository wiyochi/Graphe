#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Node.hpp"
#include "Arc.hpp"

class Graph : public sf::Drawable
{
public:
    Graph();
    ~Graph();
    void addNode(int x, int y);
    void addArc(int x, int y);
	void addArc(Node* n1, Node* n2);
    std::size_t getNodeCount() const;
    std::size_t getArcCount() const;
	void setColor(sf::Color);
	bool contain(Node * node);

    void update(sf::Window& window);
    int getID() const;

    Node* operator[](int index);

    static int graphNumber;

private:
    int m_ID;
    std::vector<Node*> m_nodes;
    std::vector<Arc*> m_arcs;
	sf::Color m_color;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // !GRAPH_H