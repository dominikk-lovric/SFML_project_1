#include "../header/Game.h"
Game::Game() {
    initWindow();
}

Game::~Game() {

}

void Game::initWindow() {
    i=0;
    vm.size={900,600};
    window.create(vm, "game window", Style::Default);
    mainView.setSize({900,600});
    UIView.setSize({900,600});
    mainView.setCenter(Vector2f(0,0)-mainView.getSize());
    UIView.setCenter(mainView.getCenter()-mainView.getSize());
    window.setView(mainView);
    UIb=false;
    if (blueTexture.loadFromFile("../../assets/blue.png")) {}
    if (redTexture.loadFromFile("../../assets/red.png")) {}
    ui.setView(UIView);
    ui.addUIElement(UIElement(blueTexture, IntRect({0,0},{9,6}), UIView.getCenter(), {50,20}));
    ui.addUIElement(UIElement(redTexture, IntRect({0,0},{9,9}), UIView.getCenter()-UIView.getSize()/2.f, {30,30}));


}

RenderWindow& Game::getWindow() {
    return this->window;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Game::update(Time dt) {
    pollEvents();
    if (UIb) {
        ui.update(window);
        if (ui.getElementHover(0,window)) {ui.scaleUIElement(0,{100,20},0.01,1,6);
            }
        else {ui.scaleUIElement(0, {50,20},0.1,1,6);
            }
        if (ui.getElementHover(1,window)) {ui.scaleUIElement(1,{50,50},0.03,0.9975,3);
        }
        else {ui.scaleUIElement(1, {30,30},0.03,0.9975,3);
        }
    }

}

void Game::pollEvents() {
    while (optional<Event> ev = window.pollEvent()) {
        if (ev->is<Event::Closed>()) {
            window.close();
        }
        else if (const auto kp = ev->getIf<Event::KeyPressed>()) {
            if (kp->scancode==Keyboard::Scancode::Escape) {
                window.close();
            }
            if (kp->scancode==Keyboard::Scancode::Q) {
                UIb=!(UIb);
            }
            if (kp->scancode==Keyboard::Scancode::E) {
                i=++i%9;
            }
            if (kp->scancode==Keyboard::Scancode::D) {
            }
            if (kp->scancode==Keyboard::Scancode::A) {
            }
        }
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Game::render() {
    window.setView(mainView);
    this->window.clear(sf::Color(150, 150, 150, 0));
    if (UIb){
        window.setView(UIView);
        ui.render(window);

    }


    this->window.display();
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool Game::isOpen() {
    return window.isOpen();
}

