#ifndef NODE_H
#define NODE_H

#define PT(n,x,y) n << "(" << x << "," << y << ")"

#include <math.h>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

class Node : public sf::Drawable
{
public:
    Node(int x, int y);
    ~Node();
    void update(sf::Window& window);
	void drag(int mouseX, int mouseY);
	void mouseOn(int mouseX, int mouseY);
    bool containPoint(int x, int y);
    sf::Vector2f getPosition();
	void setColor(sf::Color c);
	void select();
	void unselect();
	void addNeighbor(Node* n);
	bool gotNeighbor(Node* n);

	static bool dragging;

private:
    sf::CircleShape m_shape;
    bool m_dragged;
	bool m_selected;

	std::vector<Node*> m_neighborhood;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // !NODE_H