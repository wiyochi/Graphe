#if !defined(_SELECTOR_H_)
#define _SELECTOR_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Element/Element.hpp"

class Selector : public sf::Drawable
{
public:

private:

    void draw(sf::RenderTarget&, sf::RenderStates) const;

};

#endif // _SELECTOR_H_
