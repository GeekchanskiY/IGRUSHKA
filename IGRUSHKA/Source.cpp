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
	window.setFramerateLimit(60);

	//�������� �������� ��������
	barrier.loadFromFile("bochki.png");
	texturetruba.loadFromImage(barrier);
	truba.setTexture(texturetruba);
	truba.setPosition(250, -300);

	//�������� �������� �������
	wiskey.loadFromFile("wiskey.png");
	texture.loadFromImage(wiskey);
	bottle.setTexture(texture);
	bottle.setPosition(50, 50);

	//��������� ���� �������
	bottle.setRotation(-45);
	bottle.rotate(45);

	//�������� �������� ����
	kristal.loadFromFile("fon.png");
	texturefon.loadFromImage(kristal);
	fon.setTexture(texturefon);
	fon.setPosition(0,0);

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