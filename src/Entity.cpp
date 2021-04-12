#include "Entity.h"

#include "Game.h"

Entity::Entity(Game *_game, vf2d _pos, vf2d _hitBox)
    : game(_game), pos(_pos), hitBox(_hitBox) {}

Entity::~Entity() {}

void Entity::Update(float deltaTime)
{}

void Entity::Draw(float deltaTime)
{
    // Fill
    game->FillRectDecal(pos, hitBox, olc::WHITE);
    // Outline
    game->DrawRect(pos, hitBox, olc::BLACK);
}