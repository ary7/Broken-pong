#include <SFML/Graphics.hpp>

#include "Paddle.h"
#include "Ball.h"
#include "constants.h"


void InitializeOrigins(Paddle &player, Paddle &computer, Ball &ball);
void HandleWindow(sf::Event &event, sf::RenderWindow &window);

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Pong", sf::Style::Titlebar | sf::Style::Close);
	sf::Clock clock;

	//sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	//sf::Time timeSinceLastUpdate = sf::Time::Zero;

	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	window.requestFocus();

	Paddle playerPaddle, computerPaddle;
	Ball gameBall;

	InitializeOrigins(playerPaddle, computerPaddle, gameBall); 

	while (window.isOpen())
	{
		sf::Event event;
			
		float delta = clock.restart().asMilliseconds(); // returns 15, 16 or 17 which messes up calculations
		//cout << delta << endl;

		//EVENTS

		while (window.pollEvent(event))
		{
			HandleWindow(event, window); // checks for window closing events
			playerPaddle.MovePaddle(event, delta); // checks for player movement events
			computerPaddle.MovePaddle(event, delta);	
		}

		//UPDATE
		

		gameBall.CollisionWithPaddle(playerPaddle, delta);
		gameBall.CollisionWithPaddle(computerPaddle, delta);
		gameBall.MoveBall(delta);
		gameBall.CollisionWall();
		
		//sf::Time elapsed = clock.getElapsedTime();
		//cout << elapsed.asSeconds() << endl;

		// RENDER

		window.clear();
		window.draw(playerPaddle.getRect());
		window.draw(computerPaddle.getRect());
		window.draw(gameBall.getBall());
		window.display();
	}

	return 0;
}

void InitializeOrigins(Paddle &player, Paddle &computer, Ball &ball)
{	
	player.rect.setOrigin(5, 50);
	player.rect.setPosition(25, 300);
	computer.rect.setOrigin(5, 50);
	computer.rect.setPosition(775, 300);
	ball.myBall.setOrigin(0, 0);
	ball.myBall.setPosition(390, 290);
	
}

void HandleWindow(sf::Event &event, sf::RenderWindow &window)
{
	if (event.type == sf::Event::Closed || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
	{
		window.close();
	}
}
