#pragma once

#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include "constants.h"
#include "Paddle.h"


class Ball : public sf::CircleShape
{
	public:

		Ball();
		~Ball();

		void PositionSet(float x, float y);
		void MoveBall(float time); // set initial ball movement and update position
		void CollisionWall(); //check for collisions with the wall and adjust
		void CollisionWithPaddle(Paddle &paddle, float time);

		float GetRadius();

		sf::CircleShape &getBall();
		sf::FloatRect bounds;
		sf::CircleShape myBall;

	private:
		
		
		float radius, xVel, yVel;

};
