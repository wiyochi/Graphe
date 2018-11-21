#ifndef NODE_H
#define NODE_H

#include <SFML/Graphics.hpp>

class Node : public sf::Drawable
{
public:
    Node(int x, int y);
    ~Node();
    static int nodeNumber;

private:
    sf::CircleShape m_shape;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // !NODE_H