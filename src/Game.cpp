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
    mainView.setCenter(Vector2f(0,0)-mainView.getSize()/2.f);
    UIView.setCenter(mainView.getCenter()-mainView.getSize());
    window.setView(mainView);
    UI=false;
    if (mainTexture.loadFromFile("../../assets/blue.png")) {}
    ue.initUIElement(mainTexture, IntRect({0,0},{9,6}), mainView.getCenter(), {50,50});
    ue.moveConst({-225,-150});
}

RenderWindow Game::getWindow() {
    return std::move(this->window);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Game::update(Time dt) {
    pollEvents();
    ue.update();
    if (UI)window.setView(UIView);
    else window.setView(mainView);
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
                UI=!(UI);
            }
            if (kp->scancode==Keyboard::Scancode::E) {
                i=++i%9;
            }
            if (kp->scancode==Keyboard::Scancode::D) {
                ue.scale(ue.getScale()+Vector2f(10,10), 0.02, 1, i);
                //ue.scaleConst({-0.4,-0.4});
            }
            if (kp->scancode==Keyboard::Scancode::A) {
                ue.scale(ue.getScale()-Vector2f(10,10), 0.02, 1, i);
            }
        }
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Game::render() {
    window.setView(mainView);
    this->window.clear(sf::Color(150, 150, 150, 0));
    RectangleShape rect1;
    rect1.setPosition(mainView.getCenter()-mainView.getSize()/2.f);
    rect1.setSize({900,600});
    rect1.setFillColor(sf::Color(0, 0, 255, 100));
    window.draw(rect1);
    ue.render(window);
    if (UI)window.setView(UIView);
    RectangleShape rect2;
    rect2.setPosition(UIView.getCenter()-UIView.getSize()/2.f);
    rect2.setSize({900,600});
    rect2.setFillColor(sf::Color(255, 0, 0, 100));
    window.draw(rect2);

    this->window.display();
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool Game::isOpen() {
    return window.isOpen();
}

