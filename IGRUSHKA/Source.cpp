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
Sprite bottle, truba, fon;


int main()
{
	window.setFramerateLimit(60);

	//загрузка картинки преграды
	barrier.loadFromFile("bochki.png");
	texturetruba.loadFromImage(barrier);
	truba.setTexture(texturetruba);
	truba.setPosition(250, -300);

	//загрузка картинки бутылки
	wiskey.loadFromFile("wiskey.png");
	texture.loadFromImage(wiskey);
	bottle.setTexture(texture);
	bottle.setPosition(50, 50);

	//изменение угла бутылки
	bottle.setRotation(-45);
	bottle.rotate(45);

	//загрузка картинки фона
	kristal.loadFromFile("fon.png");
	texturefon.loadFromImage(kristal);
	fon.setTexture(texturefon);
	fon.setPosition(0,0);

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
		app.Tick();
		// Отрисовка окна
		window.display();
		window.clear({ 255, 255, 255 });
		
		bottle.setPosition(app.Whiskey_X, app.Whiskey_y);
		window.draw(fon);
		window.draw(bottle);
		window.draw(truba);
	}

	return 0;
}

void Key() {
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		app.Jump();
	}
}