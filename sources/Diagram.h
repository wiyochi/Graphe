#ifndef DIAGRAM_H
#define DIAGRAM_H

#include <iostream>
#include <vector>
#include <random>
#include <SFML/Graphics.hpp>
#include "Graph.hpp"

class Diagram : public sf::Drawable
{
public:
	enum Mode
	{
		ADD_NODE,
		SELECTION
	};

	Diagram();
	~Diagram();

	void addGraph();
	void update(sf::RenderWindow& window);

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	std::vector<Graph*> m_graphs;
	int m_iGraph;
	Mode m_mode;

	// Simulate keyReleased
	bool m_mousePressed;
	bool m_keyboardPressed;

	std::default_random_engine re;
	std::uniform_int_distribution<int> distrib{ 0 , 255 };
};

#endif // !DIAGRAM_H