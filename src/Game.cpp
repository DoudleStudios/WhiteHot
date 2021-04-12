#include "Game.h"

#include "Entity.h"

Game::~Game()
{
    delete player;
    delete olcPGELogo;
    delete olcPGEDecal;
}

bool Game::OnUserCreate()
{
    sAppName = "White Hot - Doudle Studios";
    olcPGELogo = new Sprite("../../olcPGELogo.png");
    olcPGEDecal = new Decal(olcPGELogo);
    player = new Player(this, { 50, 50 }, { 50, 50 });
    return true;
}

bool Game::OnUserUpdate(float deltaTime)
{
    Clear(BLACK);

    if (creditScreenTime < creditScreenDuration)
    {
        DrawDecal({ (ScreenWidth() - olcPGELogo->width * 0.75f) / 2.0f, (ScreenHeight() - olcPGELogo->height * 0.75f) / 2.0f, }, olcPGEDecal, { 0.75f, 0.75f });

        creditScreenTime += deltaTime;
        return true;
    }

    player->Update(deltaTime);
    player->Draw(deltaTime);

    return !GetKey(ESCAPE).bReleased;
}