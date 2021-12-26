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
Sprite bottle, truba, fon;

int main()
{
	APP app;
	window.setFramerateLimit(60);

	//�������� �������� �������
	wiskey.loadFromFile("wiskey.png");
	texture.loadFromImage(wiskey);
	bottle.setTexture(texture);
	bottle.setPosition(50, 50);

	//�������� �������� ����
	kristal.loadFromFile("fon.png");
	texturefon.loadFromImage(kristal);
	fon.setTexture(texturefon);
	fon.setPosition(0,0);

	//�������� �������� ��������
	kristal.loadFromFile("fon.png");
	texturefon.loadFromImage(kristal);
	fon.setTexture(texturefon);
	fon.setPosition(0, 0);


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
		app.Tick();
		// ��������� ����
		window.display();
		window.clear({ 255, 255, 255 });

		window.draw(fon);
		window.draw(bottle);
	}

	return 0;
}

void Key() {
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		bottle.move(Speed, 0);
	}
}