#include <iostream>
#include <SFML/Graphics.hpp>
#include "Node.hpp"
#include "Graph.hpp"

enum Mode
{
    ADD_NODE,
    SELECTION
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Graphe");
    std::vector<Graph*> graphs;
    graphs.push_back(new Graph());
    int iGraph = 0;
    Mode mode = ADD_NODE;
    graphs[iGraph]->addNode(100, 100);
    graphs[iGraph]->addNode(50, 50);
    graphs[iGraph]->addArc(0, 1);

    sf::CircleShape mouseCenter;
    mouseCenter.setRadius(5);
    mouseCenter.setFillColor(sf::Color::Red);
    mouseCenter.setPosition(80, 20);

    sf::RectangleShape testEntity;
    testEntity.setFillColor(sf::Color::White);
    testEntity.setPosition(200, 200);
    testEntity.setSize(sf::Vector2f(100, 2));
    testEntity.setRotation(45.f);

    sf::RectangleShape testEntity2;
    testEntity2.setFillColor(sf::Color::White);
    testEntity2.setPosition(200, 200);
    testEntity2.setSize(sf::Vector2f(100, 2));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape))
                window.close();
            /*
            else if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                switch(mode)
                {
                case ADD_NODE:
                    graphs[iGraph]->addNode(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                case SELECTION:
                    break;
                }
            }
            else if(event.type == sf::Event::KeyReleased)
            {
                if(event.key.code == sf::Keyboard::N)
                {
                    graphs.push_back(new Graph());
                    iGraph = graphs.size()-1;
                }
                else if(event.key.code == sf::Keyboard::Right)
                {
                    iGraph = (iGraph + 1)%graphs.size();
                    std::cout << "Changement sur le graphe " << graphs[iGraph]->getID() << std::endl;
                }
                else if(event.key.code == sf::Keyboard::Left)
                {
                    iGraph = (iGraph - 1) < 0 ? graphs.size()-1 : (iGraph - 1);
                    std::cout << "Changement sur le graphe " << graphs[iGraph]->getID() << std::endl;
                }
                else if(event.key.code == sf::Keyboard::Numpad0)
                {
                    mode = SELECTION;
                    std::cout << "Mode Selection" << std::endl;
                }
                else if(event.key.code == sf::Keyboard::Numpad1)
                {
                    mode = ADD_NODE;
                    std::cout << "Mode Add" << std::endl;
                }
            }
            */

        }

        for(auto g : graphs)
        {
            g->update(window);
        }

        window.clear();
        
        for(auto g : graphs)
        {
            window.draw(*g);
        }
        window.draw(testEntity);
        window.draw(testEntity2);

        window.display();
    }

    return 0;
}