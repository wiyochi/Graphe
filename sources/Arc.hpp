#ifndef ARC_H
#define ARC_H

#include <iostream>
#include <string>
#include <math.h>
#include <SFML/Graphics.hpp>
#include "Node.hpp"

class Arc : public sf::Drawable
{
public:
    enum ORIENTATION
    {
        UNDIRECTED,
        DIRECTED_R,
        DIRECTED_L
    };

    Arc(Node* n1, Node* n2, ORIENTATION o);
    ~Arc();

    Node* getFirstNode() const;
    Node* getSecondNode() const;
    ORIENTATION getOrientation() const;

    void update();

private:
    std::pair<Node*, Node*> m_nodes;
    ORIENTATION m_orientation;
    sf::RectangleShape m_shape;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

#endif // !ARC_H