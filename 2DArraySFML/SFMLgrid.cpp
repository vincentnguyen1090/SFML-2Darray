//
// Created by vince on 2/28/2023.
//

#include "SFMLgrid.h"
#include <iostream>
sf::RectangleShape** SFMLgrid::createArray()
{
    arr = new sf::RectangleShape*[rows];
    for (int i = 0; i < rows; ++i) {
        *(arr + i) = new sf::RectangleShape[colos];
    }
    return arr;
}
void SFMLgrid::fillArray()
{
    for (int i = 0; i < this->rows; ++i)
    {
        for (int j = 0; j < this->colos; ++j)
        {
            *(*(arr + i) + j) = newRectangleShape(i * 100.f,j * 100.f);
        }
    }
}
sf::RectangleShape SFMLgrid::newRectangleShape(float x, float y)
{
    sf::RectangleShape rect(sf::Vector2f(100.f,100.f));
    rect.setFillColor(randomColor());
    rect.setPosition(sf::Vector2f(x, y));
    return rect;
}
sf::Color SFMLgrid::randomColor()
{
    int r = rand() % 256;
    int g = rand() % 256;
    int b = rand() % 256;
    return sf::Color(r, g, b, 255);
}
void SFMLgrid::deleteArray()
{
    for (int i = 0; i < rows; i++) {
        delete [] *(arr + i);
    }
    delete [] arr;
}
SFMLgrid::SFMLgrid()
:rows(1), colos(1)
{
    createArray();
    fillArray();
}
SFMLgrid::SFMLgrid(const SFMLgrid& og_arr)
: rows(og_arr.rows), colos(og_arr.colos)
{
    createArray();
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < colos; ++j)
        {
            *(*(arr + i) + j) = *(*(og_arr.arr + i) + j);
        }
    }
}
SFMLgrid::~SFMLgrid()
{
    deleteArray();
}
void SFMLgrid::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < colos; ++j)
        {
            window.draw(*(*(arr + i) + j));
        }
    }
}
void SFMLgrid::eventHandler(sf::RenderWindow& window, sf::Event event)
{
    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Right)
        {
            deleteArray();
            ++rows;
            ++colos;
            createArray();
            fillArray();
        }
        else if(event.key.code == sf::Keyboard::Left)
        {
            if(rows > 0 && colos > 0)
            {
                --rows;
                --colos;
            }
        }
    }
}