#include "Ball.h"


Ball::Ball()
{
	radius = BALL_RADIUS;

	xVel = BALL_SPEED;
	yVel = BALL_SPEED;

	myBall.setRadius(radius);
	myBall.setFillColor(sf::Color::White);
}

Ball::~Ball()
{
}

void Ball::PositionSet(float x, float y)
{
	myBall.setPosition(x-radius, y-radius);;
}

void Ball::MoveBall(float time)
{
	float x = (xVel * 100) / 100;
	float y = (yVel * 100) / 100;

	x = xVel * time;
	y = yVel * time;
	//= xVel * time;
	//float y = yVel * time;
	
	myBall.move(x, y);
	bounds = myBall.getGlobalBounds();
	
}

void Ball::CollisionWall()
{
	if ((myBall.getPosition().x <= 0) || (myBall.getPosition().x + (radius*2)  >= SCREEN_WIDTH))
	{
		xVel *= -1;
		//cout << myBall.getPosition().x << endl;
	}

	if ((myBall.getPosition().y <= 0) || (myBall.getPosition().y + (radius*2) >= SCREEN_HEIGHT))
	{
		yVel *= -1;
	}
}

void Ball::CollisionWithPaddle(Paddle & paddle, float time)
{
	//bounding box collision DOES work but needs proper time implementation to work efficiently.
	//implement time tomorrow to avoid this.

	if (bounds.intersects(paddle.bounds))
	{
		if (myBall.getPosition().x < 400)
		{
			cout << myBall.getPosition().x << endl;
			float relativeY = (paddle.GetY() + (PADDLE_HEIGHT / 2)) - myBall.getPosition().y - (radius);
			float normalizedY = (relativeY / (PADDLE_HEIGHT / 2));
			float bounceAngle = normalizedY * MAX_BOUNCE;
			myBall.move(6, 0);

			xVel = BALL_SPEED * cos(bounceAngle);
			yVel = BALL_SPEED * -sin(bounceAngle);
		}
		else
		{
			float relativeY = (paddle.GetY() + (PADDLE_HEIGHT / 2)) - myBall.getPosition().y - (radius);
			float normalizedY = (relativeY / (PADDLE_HEIGHT / 2));
			float bounceAngle = normalizedY * MAX_BOUNCE;
			myBall.move(-6, 0);

			xVel = BALL_SPEED * cos(bounceAngle);
			yVel = BALL_SPEED * sin(bounceAngle);
		}

		////cout << "Hello" << endl;
		////std::this_thread::sleep_for(10s);

		////cout << paddle.GetY() << "\t";
		//float relativeY = (paddle.GetY() + (PADDLE_HEIGHT / 2)) - myBall.getPosition().y - (radius);  //50

		//
		//
		//float normalizedY = (relativeY / (PADDLE_HEIGHT / 2)); //1
		////cout << normalizedY << "\t";

		//float bounceAngle = normalizedY * MAX_BOUNCE; // 75

		//cout << myBall.getPosition().y << "\t";
		//cout << normalizedY << endl;

		//xVel = BALL_SPEED * cos(bounceAngle); //0.5 * cos(75);

		////cout << bounceAngle << "\t" << endl;
		//xVel = BALL_SPEED * cos(bounceAngle);
		////cout << xVel << endl;
		//yVel = BALL_SPEED * -sin(bounceAngle);

		////xVel *= 0;
	}
}

float Ball::GetRadius()
{
	return myBall.getRadius();
}

sf::CircleShape &Ball::getBall()
{
	return myBall;
}

