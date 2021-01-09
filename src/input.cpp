#include "engine.hpp"

void Engine::Input()
{
	sf::Event Event{};

	while (Window.pollEvent(Event))
	{
		// Window Closed
		if (Event.type == sf::Event::Closed)
		{
			Window.close();
		}

		// Handle Keyboard Input
		if (Event.type == sf::Event::KeyPressed)
		{
			// Quit
			if (Event.key.code == sf::Keyboard::Escape)
			{
				Window.close();
			}

			// Pause
			if (Event.key.code == sf::Keyboard::P)
			{
				TogglePause();
			}

			// New Game
			if (CurrentGameState == GameState::GAMEOVER)
			{
				if (Event.key.code == sf::Keyboard::Enter)
				{
					StartGame();
				}
			}

			// Direction
			if (Event.key.code == sf::Keyboard::Up)
			{
				AddDirection(Direction::UP);
			}
			else if (Event.key.code == sf::Keyboard::Down)
			{
				AddDirection(Direction::DOWN);
			}
			else if (Event.key.code == sf::Keyboard::Left)
			{
				AddDirection(Direction::LEFT);
			}
			else if (Event.key.code == sf::Keyboard::Right)
			{
				AddDirection(Direction::RIGHT);
			}
		}
	}
}

void Engine::AddDirection(int NewDirection)
{
	if (DirectionQueue.empty())
	{
		DirectionQueue.emplace_back(NewDirection);
	}
	else
	{
		if (DirectionQueue.back() != NewDirection)
		{
			DirectionQueue.emplace_back(NewDirection);
		}
	}
}

