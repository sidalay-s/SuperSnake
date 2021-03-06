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
			if (Event.key.code == sf::Keyboard::Space)
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

			// TODO - Volume Modification

			// Lower Volume Level
			if (Event.key.code == sf::Keyboard::J)
			{
				LowerVolume();
			}

			if (Event.key.code == sf::Keyboard::K)
			{
				RaiseVolume();
			}

			// Direction
			if (Event.key.code == sf::Keyboard::Up)
			{
				AddDirection(Direction::UP);
				TurningTiles.emplace_back(1, 270.f);
			}
			else if (Event.key.code == sf::Keyboard::Down)
			{
				AddDirection(Direction::DOWN);
				TurningTiles.emplace_back(1, 90.f);
			}
			else if (Event.key.code == sf::Keyboard::Left)
			{
				AddDirection(Direction::LEFT);
				TurningTiles.emplace_back(1, 180.f);
			}
			else if (Event.key.code == sf::Keyboard::Right)
			{
				AddDirection(Direction::RIGHT);
				TurningTiles.emplace_back(1, 0.f);
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

