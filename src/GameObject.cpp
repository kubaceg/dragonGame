#include "GameObject.hpp"

GameObject::GameObject(SDL_Surface *sc) {
    screen = sc;
}

GameObject::~GameObject() {}

void GameObject::draw(){}

bool GameObject::move(){}

int GameObject::generateYPosition() {
    return std::rand() % screen->h;
}
