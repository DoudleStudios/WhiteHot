#include "PGE.h"

class Game; // No need to include

struct Entity
{
    Game *game;

    vf2d pos;
    vf2d hitBox;

    Entity(Game *, vf2d pos = {}, vf2d hitBox = {});
    virtual ~Entity();
    virtual void Update(float deltaTime);
    virtual void Draw(float deltaTime);
};

// TODO: Add abstraction
struct Player: public Entity
{
    Player(Game *game, vf2d pos = {}, vf2d hitBox = {})
        : Entity(game, pos, hitBox) {}
};

struct Enemy: public Entity
{
    Enemy(Game *game, vf2d pos = {}, vf2d hitBox = {})
        : Entity(game, pos, hitBox) {}
};