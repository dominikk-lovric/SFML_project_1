#include "../header/Game.h"
Game::Game() {
    initWindow();
    initSnake();
}

Game::~Game() {

}

void Game::initWindow() {
    i=0;
    vm.size={900,600};
    window.create(vm, "game window", Style::Default);
    mainView.setSize({900,600});
    UIView.setSize({900,600});
    GameOverView.setSize({900,600});
    mainView.setCenter(Vector2f(0,0)-mainView.getSize());
    UIView.setCenter(mainView.getCenter()-mainView.getSize());
    GameOverView.setCenter(mainView.getCenter()+mainView.getSize());
    window.setView(mainView);
    UIb=false;
    if (blueTexture.loadFromFile("../../assets/blue.png")) {}
    if (redTexture.loadFromFile("../../assets/red.png")) {}
    ui.setView(UIView);
    ui.addUIElement(UIElement(blueTexture, IntRect({0,0},{9,6}), UIView.getCenter(), {50,20}));
    ui.addUIElement(UIElement(redTexture, IntRect({0,0},{9,9}), UIView.getCenter()-UIView.getSize()/2.f, {30,30}));

}

void Game::initSnake() {
    srand(time({}));
    if (snakeTexture.loadFromFile("../../assets/domonster.png")) {}
    if (appleTexture.loadFromFile("../../assets/monster_apple.png")) {}
    grid.initGrid(mainView, 6, 4);
    snake.initSnake(snakeTexture, Vector2i(167,167), grid.getSize(), mainView);
    apple.initApple(appleTexture, Vector2i(255,255), grid.getSize(), grid.getCellSize(), mainView);
    gameRunning=true;
}

RenderWindow& Game::getWindow() {
    return this->window;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Game::update(Time dt) {
    pollEvents();
    if (UIb) {
        if (gameRunning) {
            snake.update(dt);
            apple.update(snake);
            if (snake.isElementInBody(snake.getHeadPos())||((snake.getHeadPos().x<0)||(snake.getHeadPos().y<0)||(snake.getHeadPos().x>=grid.getSize().x||snake.getHeadPos().y>=grid.getSize().y))) {
                gameRunning=false;
            }
        }else {
            if (Keyboard::isKeyPressed(Keyboard::Key::R)) {
                gameRunning=true;
                initSnake();
            }
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
    if (UIb){window.setView(mainView);
        this->window.clear(sf::Color(150, 150, 150, 0));
        grid.render(window);
        apple.render(window);
        snake.render(window);
        if (!gameRunning) {
            window.setView(GameOverView);
            RectangleShape redScreen;
            redScreen.setSize({900,600});
            redScreen.setPosition(GameOverView.getCenter()-redScreen.getSize()/2.f);
            redScreen.setFillColor(Color(255,0,0,100));
            window.draw(redScreen);
        }
        this->window.display();
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool Game::isOpen() {
    return window.isOpen();
}

