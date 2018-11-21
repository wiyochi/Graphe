#include <iostream>
#include <SFML/Graphics.hpp>
#include "Node.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Graphe");
    std::vector<Node*> nodes;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape))
                window.close();
            else if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                nodes.push_back(new Node(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
                std::cout << "Ajout Node: " << sf::Mouse::getPosition(window).x\
                                            << "," << sf::Mouse::getPosition(window).y\
                                            << " : "
                                            << Node::nodeNumber
                                            << std::endl;
            }
        }

        window.clear();
        
        for(auto n : nodes)
        {
            window.draw(*n);
        }

        window.display();
    }

    return 0;
}