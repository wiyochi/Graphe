#if !defined(_DIAGRAM_H_)
#define _DIAGRAM_H_

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
		ADD_ARC,
		MOVE_NODE,
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

	Graph* m_selectedGraph;
	Node* m_selectedNode;
	std::pair<Node*, Node*> m_nodesForArc;
	int m_switchOT;
	void unselectAll();

	// Simulate keyReleased
	bool m_mousePressed;
	bool m_keyboardPressed;

	std::default_random_engine re;
	std::uniform_int_distribution<int> distrib{ 0 , 255 };
};

#endif // _DIAGRAM_H_