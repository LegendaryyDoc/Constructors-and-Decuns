#pragma once
#include "raylib.h"
#include <iostream>
class enemy
{
public:
	bool enabled = false;

	int damage = 1;

	Rectangle rec;

	Vector2 position;
	float speed = 1.0f;
	Texture2D mySprite;
	bool virtual follow(const Vector2 &dest);
	enemy(const std::string & fileName);//assign the sprite image.
	enemy();
	~enemy();

	void virtual draw();
};