#if !defined(_NODE_H_)
#define _NODE_H_

#define PT(n,x,y) n << "(" << x << "," << y << ")"

#include <math.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Element.hpp"

class Node : public Element
{
public:
    Node(int, int);
    ~Node();
    void update(sf::Window&);
	void drag(int, int);
	void mouseOn(int, int);
    bool containPoint(int, int);
    sf::Vector2f getPosition();
	void setColor(sf::Color);

    // Element methods
	void select() override;
	void unselect() override;
    bool isIn(sf::FloatRect) override;

	static bool dragging;

private:
    sf::CircleShape m_shape;
    bool m_dragged;

    void draw(sf::RenderTarget&, sf::RenderStates) const;
};

#endif // _NODE_H_