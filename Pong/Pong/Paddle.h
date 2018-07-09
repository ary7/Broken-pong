#pragma once

#include <SFML/Graphics.hpp>
#include "constants.h"


class Paddle : public sf::RectangleShape
{
	public:

		Paddle();
		~Paddle();

		//void PositionSet(float x, float y);
		void MovePaddle(sf::Event &event, float time);
		float GetX();
		float GetY();

		sf::RectangleShape &getRect();
		sf::FloatRect bounds;
		sf::RectangleShape rect;

	private:

		
};