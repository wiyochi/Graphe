#if !defined(_ARC_H_)
#define _ARC_H_

#include <iostream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Node.hpp"
#include "Element.hpp"

class Arc : public Element
{
public:
    enum ORIENTATION
    {
        UNDIRECTED,
        DIRECTED
    };

    Arc(Node*, Node*, ORIENTATION);
    ~Arc();

    Node* getFirstNode() const;
    Node* getSecondNode() const;
    ORIENTATION getOrientation() const;

    void update();

    // Element methods
	void select() override;
	void unselect() override;
    bool isIn(sf::FloatRect) override;

private:
    std::pair<Node*, Node*> m_nodes;
    ORIENTATION m_orientation;
	sf::Vertex m_line[2];

    void draw(sf::RenderTarget&, sf::RenderStates) const;

};

#endif // _ARC_H_