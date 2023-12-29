#pragma GCC optimize("Ofast,unroll-loops,mfma,mavx,mavx2")
#pragma GCC target("avx,avx2,fma")
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
double WIDTH = 500, HEIGHT = 500;
double k = 1.5;
double move_x = 0, move_y = 0;

bool inLine(double x, double y, double x_midle, double y_midle) {
    x -= x_midle;
    y -= y_midle;
    y *= -1;
    bool flag = false;
    flag |= std::fabs((x+10.0)*(x+10.0) + (y+40.0)*(y+40.0) - 400.0) <= 8;
    flag |= std::fabs(std::fabs(x - 05)/2.5 + std::fabs(y + 15)/4.5 - 10) <= 0.1;
    flag |= (std::fabs(x - 10) <= std::fabs(((x+x_midle)*k+1)/k-x_midle - 10)) &&
            (std::fabs(x - 10) <= std::fabs(((x+x_midle)*k-1)/k-x_midle - 10)) &&
            (y <= -5) && (y >= -45);
    flag |= (std::fabs(x - 25) <= std::fabs(((x+x_midle)*k+1)/k-x_midle - 25)) &&
            (std::fabs(x - 25) <= std::fabs(((x+x_midle)*k-1)/k-x_midle - 25)) &&
            (y <= -5) && (y >= -45);
    flag |= (std::fabs(y + 5) <= std::fabs(((y+y_midle)*k+1)/k-y_midle + 5)) &&
            (std::fabs(y + 5) <= std::fabs(((y+y_midle)*k-1)/k-y_midle + 5)) &&
            (x <= 25) && (x >= 10);
    flag |= (std::fabs(y + 45) <= std::fabs(((y+y_midle)*k+1)/k-y_midle + 45)) &&
            (std::fabs(y + 45) <= std::fabs(((y+y_midle)*k-1)/k-y_midle + 45)) &&
            (x <= 25) && (x >= 10);
    flag |= std::fabs(y + 4*(x-25)) <= 1.8 - k/5;
    flag |= std::fabs(y*3 - 4*(x+35)) <= 2 - k/5;
    flag |= std::fabs(y - 20) <= std::fabs(((y+y_midle)*k-1)/k-y_midle - 20) &&
            std::fabs(y - 20) <= std::fabs(((y+y_midle)*k+1)/k-y_midle - 20);
    flag |= std::fabs(y + 30 - (x + 10)*(x+10)/10) <= (1.5+(y >= -20)
            + (y >= -10) + (y >= 0)*0.5 + (y >= 10)*0.5 + (y >= 20)*0.5 + (y >= 30)*0.5
            + (y >= 40)*0.5 + (y >= 60) + (y >= 70) + (y >= 80) + (y >= 90) + (y >= 100)
            + (y >= -25)*0.5)/5;
    flag |= std::fabs(20 * x + (y + 35)*(y + 35) + 100) <= 5 + (x <= -20)*2 + (x <= -30)*2 + (x <= -40)*2 + (x <= -50)*2
            + (x <= -60)*2 + (x <= -70)*2 + (x <= -80)*2 + (x <= -90)*2 + (x <= -100)*2;

    return flag;
}

bool inSquare(double x, double y, double x_midle, double y_midle) {
    bool flag = false;
    x -= x_midle;
    y -= y_midle;
    y *= -1;
    flag |= (x > -1) && (y + 30 < (x + 10)*(x+10)/10) &&
            ((x+10.0)*(x+10.0) + (y+40.0)*(y+40.0) >= 400.0) &&
            (y < -0.5) && (y >= -45) && (x <= 10);
    flag |= (y < -0.5) && (y >= -5) && (std::fabs(x - 5)/2.5 + std::fabs(y + 15)/4.5 <= 10) &&
            (x >= 10);
    flag |= (y + 30 <= (x + 10)*(x+10)/10) && (x <= -10) && (y*3 >= 4*(x+35)) &&
            (20 * x + (y + 35)*(y + 35) + 100 >= 0) && (y >= -35);
    flag |= (20 * x + (y + 35)*(y + 35) + 100 <= 0) && ((x+10.0)*(x+10.0) + (y+40.0)*(y+40.0) <= 400.0) &&
            (std::fabs(x - 5)/2.5 + std::fabs(y + 15)/4.5 >= 10) && (y + 30 <= (x + 10)*(x+10)/10);
    flag |= (20 * x + (y + 35)*(y + 35) + 100 <= 0) && ((x+10.0)*(x+10.0) + (y+40.0)*(y+40.0) <= 400.0) &&
            (std::fabs(x - 5)/2.5 + std::fabs(y + 15)/4.5 <= 10) && (y + 30 >= (x + 10)*(x+10)/10);
    flag |= (std::fabs(x - 5)/2.5 + std::fabs(y + 15)/4.5 >= 10) && (y <= -4*(x-25)) &&
            (y + 30 <= (x + 10)*(x+10)/10) && (y > 0) && (x >= 0);
    flag |= ((x+10.0)*(x+10.0) + (y+40.0)*(y+40.0) >= 400.0) && (y <= -35) && (20 * x >= -(y + 35)*(y + 35) - 100) &&
            (std::fabs(x - 05)/2.5 + std::fabs(y + 15)/4.5 >= 10) && (y <= -4*(x-25)) && (y <= -45);
    flag |= (x >= 25) && (y <= - 4*(x-25)) && (y >= -45) &&
            (std::fabs(x - 05)/2.5 + std::fabs(y + 15)/4.5 >= 10) && (y <= -10);
//    flag |= ((x+10.0)*(x+10.0) + (y+40.0)*(y+40.0) <= 400.0) && (20 * x >= - (y + 35)*(y + 35) - 100) &&
//            (y + 30 <= (x + 10)*(x+10)/10) && (std::fabs(x - 05)/2.5 + std::fabs(y + 15)/4.5 <= 10);
//    flag |= (std::fabs(x - 05)/2.5 + std::fabs(y + 15)/4.5 <= 10) && (x >= 25) && (y <= - 4*(x-25));

    return flag;
}


int main()
{
    bool flag = false;
    bool flag2 = false;
    sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "(kek)");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.text.unicode == 36) {
                    window.close();
                } else if (event.text.unicode == 56 && k > 1.5) {
                    k *= 0.9;
                } else if (event.text.unicode == 55 && k < 30) {
                    k *= 1.1;
                } else if (event.text.unicode == 0) {
                    flag = !flag;
                } else if (event.text.unicode == 1) {
                    flag2 = !flag2;
                } else if (event.text.unicode == 73) {
                    move_y += 10;
                } else if (event.text.unicode == 74) {
                    move_y -= 10;
                } else if (event.text.unicode == 71) {
                    move_x += 10;
                } else if (event.text.unicode == 72) {
                    move_x -= 10;
                }
            }
        }
        window.clear();
        sf::RectangleShape x(sf::Vector2f(WIDTH, HEIGHT));
        x.setFillColor(sf::Color(255, 250, 250));
        window.draw(x);
        for (double i = 0; i < WIDTH * k; i += k*10) {
            sf::RectangleShape line(sf::Vector2f(1, HEIGHT));
            line.setPosition(WIDTH/2 + i + move_x*k, 0);
            line.setFillColor(sf::Color(150, 150, 240));
            window.draw(line);
            line.setPosition(WIDTH/2 - i + move_x*k, 0);
            window.draw(line);
        }
        for (double i = 0; i < HEIGHT * k; i += k*10) {
            sf::RectangleShape line(sf::Vector2f(WIDTH, 1));
            line.setPosition(0, HEIGHT/2 + i + move_y*k);
            line.setFillColor(sf::Color(150, 150, 240));
            window.draw(line);
            line.setPosition(0, HEIGHT/2 - i + move_y*k);
            window.draw(line);
        }
        sf::RectangleShape OX(sf::Vector2f(WIDTH, 3));
        OX.setPosition(0, HEIGHT/2 + move_y*k);
        OX.setFillColor(sf::Color(0, 0, 0));
        window.draw(OX);
        sf::RectangleShape OY(sf::Vector2f(3, HEIGHT));
        OY.setPosition(WIDTH/2 + move_x*k, 0);
        OY.setFillColor(sf::Color(0, 0, 0));
        window.draw(OY);
        for (int i = 0; i < WIDTH; ++i) {
            for (int j = 0; j < HEIGHT; ++j) {
                sf::RectangleShape pixel(sf::Vector2f(1, 1));
                pixel.setPosition(i, j);
                if (inSquare((i) / k - move_x, (j) / k - move_y, WIDTH / k / 2, HEIGHT / k / 2)) {
                    pixel.setFillColor(sf::Color(150, 250, 0, 40));
                    window.draw(pixel);
                }
                if (inLine((i) / k - move_x, (j) / k - move_y, WIDTH / k / 2, HEIGHT / k / 2)) {
                    pixel.setFillColor(sf::Color(0, 0, 0));
                    window.draw(pixel);
                }
            }
        }
        if (flag) {
            sf::Texture bg;
            bg.loadFromFile("/Users/macbook/CLionProjects/untitled/AVM2.png");
            sf::Sprite herosprite;
            herosprite.setTexture(bg);
            herosprite.setPosition(0, 0);
            window.draw(herosprite);
        }
        if (flag2) {
            sf::Texture bg;
            bg.loadFromFile("/Users/macbook/CLionProjects/untitled/VVM.png");
            sf::Sprite herosprite;
            herosprite.setTexture(bg);
            herosprite.setPosition(-250, 0);
            window.draw(herosprite);
        }
        sf::Texture bg;
        bg.loadFromFile("/Users/macbook/CLionProjects/untitled/Math.png");
        sf::Sprite herosprite;
        herosprite.setTexture(bg);
        herosprite.setPosition(-500 + move_x, -200);
        window.draw(herosprite);
        window.display();
    }

    return 0;
}