#ifndef NODE_H
#define NODE_H

#define PT(n,x,y) n << "(" << x << "," << y << ")"

#include <math.h>
#include <iostream>
#include <SFML/Graphics.hpp>

class Node : public sf::Drawable
{
public:
    Node(int x, int y);
    ~Node();
    void update(sf::Window& window);
    bool containPoint(int x, int y);
    sf::Vector2f getPosition();
	void setColor(sf::Color c);

	static bool dragging;

private:
    sf::CircleShape m_shape;
    bool m_dragged;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // !NODE_H