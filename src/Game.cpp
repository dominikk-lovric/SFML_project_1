#include "../header/Game.h"

Game::Game() {
    initWindow();
}

Game::~Game() {

}

void Game::initWindow() {
    vm.size={900,500};
    window.create(vm, "game window", Style::Default);
}

RenderWindow Game::getWindow() {
    return std::move(this->window);
}

void Game::update(Time dt) {
}

void Game::render() {
    this->window.clear(sf::Color(150, 150, 150, 0));
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    this->window.display();
}

bool Game::isOpen() {
    return window.isOpen();
}
