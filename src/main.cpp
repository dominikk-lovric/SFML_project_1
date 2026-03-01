#include "../header/stdafx.h"
#include "../header/Game.h"
int main() {
	Game game;
	Clock clock;
	while (game.isOpen()) {
		sf::Time deltaTime = clock.restart();
		game.update(deltaTime);

		game.render();
	}
	return 0;
}