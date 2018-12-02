#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include "Node.hpp"
#include "Graph.hpp"
#include "Diagram.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Graphe");

	// TODO: Faire l'ajout d'un arc (verifier que les 2 nodes selectionnés sont du même arbre et que l'arc n'existe pas deja).

	Diagram* diagram = new Diagram();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape))
                window.close();
        }

		diagram->update(window);

        window.clear();

		window.draw(*diagram);

        window.display();
    }

    return 0;
}