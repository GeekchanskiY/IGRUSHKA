#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include "Header.h"

int main() {
    APP app;
    app.Tick();
}
/*using namespace sf;

const int Width = 780;
const int Height = 900;
int Speed = 5;

void Key();

// ������, �������, ����������, �������� ������� ����� ����������
RenderWindow window(VideoMode(Width, Height), "Flappy Wiskey");
Image image;
Texture texture;
Sprite sprite;

int main()
{
    window.setFramerateLimit(60);

    //�������� �������� �� ����� � � ����
    image.loadFromFile("whiskey.png");
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setPosition(50, 50);

    // ������� ���� ����������. �����������, ���� ������� ����
    while (window.isOpen())
    {
        // ������������ ������� ������� � �����
        Event event;
        while (window.pollEvent(event))
        {
            // ������������ ����� �� �������� � ����� ������� ����?
            if (event.type == Event::Closed)
                // ����� ��������� ���
                window.close();
        }

        Key();

        // ��������� ����
        window.display();
        window.clear({ 255, 255, 255 });

        window.draw(sprite);
    }

    return 0;
}

void Key() {
    if (Keyboard::isKeyPressed(Keyboard::Space)) {
        sprite.move(Speed, 0);
    }
}*/