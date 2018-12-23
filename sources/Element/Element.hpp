#if !defined(_ELEMENT_H_)
#define _ELEMENT_H_

#include <iostream>
#include <SFML/Graphics.hpp>

class Element : public sf::Drawable
{
public:
    virtual void select() = 0;
    virtual void unselect() = 0;
    virtual bool isIn(sf::FloatRect) = 0;

private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const = 0;

protected:
	bool m_selected;
};

#endif // _ELEMENT_H_
