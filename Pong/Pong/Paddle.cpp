#include "Paddle.h"

Paddle::Paddle()
{
	rect.setSize(sf::Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT)); // set size of paddle to 100 wide, 10 high.
	bounds = rect.getGlobalBounds(); // global bounds of paddle are set
}

Paddle::~Paddle()
{
}

//void Paddle::PositionSet(float x, float y)
//{
//	
//	rect.setPosition(x, y);
//	//bounds = rect.getGlobalBounds();
//
////	std::cout << xPos << "      " << yPos << std::endl;
//	//std::cout << rect.getPosition().y << std::endl;
//}

void Paddle::MovePaddle(sf::Event & event, float time)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
	{
		if (rect.getPosition().y <= 0 + PADDLE_HEIGHT / 2)
		{
			rect.setPosition(rect.getPosition().x, 0 + PADDLE_HEIGHT / 2);
		}
		else
		{
			rect.move(0, -PADDLE_SPEED*time);
		}	
	}
	else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
	{
		if (rect.getPosition().y >= SCREEN_HEIGHT - PADDLE_HEIGHT / 2)
		{
			rect.setPosition(rect.getPosition().x, SCREEN_HEIGHT - PADDLE_HEIGHT / 2);		
		}
		else
		{
			rect.move(0, PADDLE_SPEED*time);
			
		}	
	}

	bounds = rect.getGlobalBounds();
}

float Paddle::GetX()
{
	return rect.getPosition().x;
}

float Paddle::GetY()
{
	return rect.getPosition().y;
}

sf::RectangleShape & Paddle::getRect()
{
	return rect;
}
