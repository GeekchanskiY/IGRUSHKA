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

// Объект, который, собственно, является главным окном приложения
RenderWindow window(VideoMode(Width, Height), "Flappy Wiskey");
Image image;
Texture texture;
Sprite sprite;

int main()
{
    window.setFramerateLimit(60);

    //загрузка картинки из файла и в окно
    image.loadFromFile("whiskey.png");
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setPosition(50, 50);

    // Главный цикл приложения. Выполняется, пока открыто окно
    while (window.isOpen())
    {
        // Обрабатываем очередь событий в цикле
        Event event;
        while (window.pollEvent(event))
        {
            // Пользователь нажал на «крестик» и хочет закрыть окно?
            if (event.type == Event::Closed)
                // тогда закрываем его
                window.close();
        }

        Key();

        // Отрисовка окна
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