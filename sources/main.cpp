#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include "Element/Node.hpp"
#include "Graph.hpp"
#include "Diagram.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Graphe");

	// TODO: Faire l'ajout d'un arc (verifier que les 2 nodes selectionn�s sont du m�me arbre et que l'arc n'existe pas deja).

	Diagram* diagram = new Diagram();

    sf::FloatRect rect;
    bool click = false;
    sf::RectangleShape gRect;
    gRect.setFillColor(sf::Color::Transparent);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape))
                window.close();
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !click)
        {
            click = true;
            gRect.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
        }
        else if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2f size(sf::Mouse::getPosition(window).x - gRect.getPosition().x,\
                              sf::Mouse::getPosition(window).y - gRect.getPosition().y);

            gRect.setFillColor(sf::Color(255, 0, 0, 80));
            gRect.setSize(size);
        }
        else
        {
            click = false;
            gRect.setFillColor(sf::Color::Transparent);
            gRect.setSize(sf::Vector2f(0, 0));
        }

		diagram->update(window);

        window.clear();

		window.draw(*diagram);
        window.draw(gRect);

        window.display();
    }

    return 0;
}