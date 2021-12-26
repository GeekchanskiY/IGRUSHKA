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

// ������, �������, ����������, �������� ������� ����� ����������
RenderWindow window(VideoMode(Width, Height), "Flappy Wiskey");
Image wiskey, kristal, barrier;
Texture texture, texturefon, texturetruba;
Sprite bottle, truba1, truba2, truba3, fon;


int main()
{
	//���������� ������ � ������� 
	window.setFramerateLimit(60);

	//�������� �������� ��������
	barrier.loadFromFile("bochki.png");
	texturetruba.loadFromImage(barrier);
	truba1.setTexture(texturetruba);
	truba2.setTexture(texturetruba);
	truba3.setTexture(texturetruba);

	//�������� �������� �������
	wiskey.loadFromFile("wiskey.png");
	texture.loadFromImage(wiskey);
	bottle.setTexture(texture);
	bottle.setPosition(50, 50);

	//������ ���� �������
	bottle.setRotation(-30);

	//�������� �������� ����
	kristal.loadFromFile("fon.png");
	texturefon.loadFromImage(kristal);
	fon.setTexture(texturefon);
	fon.setPosition(0,0);

	app.create_entities();

	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
			{
				// ����� ��������� ���
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
		// ��������� ����
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