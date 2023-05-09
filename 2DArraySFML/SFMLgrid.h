//
// Created by vince on 2/28/2023.
//

#ifndef SFML_2DARRAY_SFMLGRID_H
#define SFML_2DARRAY_SFMLGRID_H
#include <SFML/Graphics.hpp>

class SFMLgrid : public sf::Drawable
{
private:
    sf::RectangleShape** arr = nullptr;
    int rows, colos;
    //dynamically create an array of current row and col size
    sf::RectangleShape** createArray();

    //fills the array with sf::RectangleShapes
    void fillArray();

    sf::Color randomColor();

    //returns a rectangle shape that is positioned at x and y
    sf::RectangleShape newRectangleShape(float x, float y);

    //deletes the arr
    void deleteArray();
public:
    ////Big Three Goes here
    SFMLgrid();
    SFMLgrid(const SFMLgrid& arr);
    ~SFMLgrid();

    //loop through 2D array and draw each rectangle
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //increases the array size when right arrow is pressed, decreases when left is pressed
    void eventHandler(sf::RenderWindow& window, sf::Event event);
};

#endif //SFML_2DARRAY_SFMLGRID_H
