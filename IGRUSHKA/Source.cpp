#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include "Header.h"

APP app;

using namespace sf;

const int Width = app.ScreenWidth;
const int Height = app.ScreenHeight;
int Speed = 5;

void Key();

// Объект, который, собственно, является главным окном приложения
RenderWindow window(VideoMode(Width, Height), "Flappy Wiskey");
Image wiskey, kristal, barrier;
Texture texture, texturefon, texturetruba;
Sprite bottle, truba1, truba2, truba3, fon;


int main()
{
	//количество кадров в секунду 
	window.setFramerateLimit(60);

	//загрузка картинки преграды
	barrier.loadFromFile("bochki.png");
	texturetruba.loadFromImage(barrier);
	truba1.setTexture(texturetruba);
	truba2.setTexture(texturetruba);
	truba3.setTexture(texturetruba);

	//загрузка картинки бутылки
	wiskey.loadFromFile("wiskey.png");
	texture.loadFromImage(wiskey);
	bottle.setTexture(texture);
	bottle.setPosition(50, 50);

	//дефолт угла бутылки
	bottle.setRotation(-30);

	//загрузка картинки фона
	kristal.loadFromFile("fon.png");
	texturefon.loadFromImage(kristal);
	fon.setTexture(texturefon);
	fon.setPosition(0,0);

	app.create_entities();

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
			{
				// тогда закрываем его
				window.close();
			}

			else if (event.type == sf::Event::KeyReleased &&
				event.key.code == sf::Keyboard::Space)
			{
				std::cerr << "switch\n";
				app.Jump();
			}
		}

		app.Tick();
		// Отрисовка окна
		window.display();
		window.clear({ 255, 255, 255 });
		
		bottle.setPosition(app.Whiskey_X, app.Whiskey_y);
		truba1.setPosition(app.entity1.pos_x, app.entity1.pos_y);
		truba2.setPosition(app.entity2.pos_x, app.entity2.pos_y);
		truba3.setPosition(app.entity3.pos_x, app.entity3.pos_y);

		window.draw(fon);
		window.draw(bottle);
		window.draw(truba1);
		window.draw(truba2);
		window.draw(truba3);

		bottle.setRotation(app.Whiskey_angle);
	}

	return 0;
}

void Key() {
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		app.Jump();
	}
}