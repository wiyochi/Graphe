#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Node.hpp"

class Graph : public sf::Drawable
{
public:
    Graph();
    ~Graph();
    void addNode(int x, int y);
    void update(sf::Window& window);
    std::size_t getNodeCount() const;
    int getID() const;

    Node* operator[](int index);

    static int graphNumber;

private:
    int m_ID;
    std::vector<Node*> m_nodes;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // !GRAPH_H