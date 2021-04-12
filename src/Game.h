#include "PGE.h"

struct Player;

class Game: public PixelGameEngine
{
private:
    Player *player;

    Sprite *olcPGELogo;
    Decal *olcPGEDecal;
    float creditScreenTime = 0, creditScreenDuration = 2.5;
public:
    ~Game();
protected:
    bool OnUserCreate() override;
    bool OnUserUpdate(float deltaTime) override;
};