#include <iostream>
#include <random>
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

	std::default_random_engine re;
	std::uniform_int_distribution<int> distrib{ 0 , 255 };

	// TODO: Creer un objet "scene" ou "shema" qui generalise le tableau de graphs
	// pour pouvoir utiliser correctement SELECTION et ADD_NODE
	// et pour creer une selection de node inter-graph (surligner le node selectionné)

	Mode mode = ADD_NODE;

    std::vector<Graph*> graphs;
    graphs.push_back(new Graph());
    int iGraph = 0;
	graphs[iGraph]->setColor(sf::Color(distrib(re), distrib(re), distrib(re)));
    graphs[iGraph]->addNode(100, 100);
    graphs[iGraph]->addNode(50, 50);
    graphs[iGraph]->addArc(0, 1);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape))
                window.close();
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
					graphs[iGraph]->setColor(sf::Color(distrib(re), distrib(re), distrib(re)));
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
        }

		if (mode == SELECTION)
		{
			for (auto g : graphs)
			{
				g->update(window);
			}
		}

        window.clear();
        
        for(auto g : graphs)
        {
            window.draw(*g);
        }

        window.display();
    }

    return 0;
}