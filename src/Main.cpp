#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class Game: public olc::PixelGameEngine
{
private:
    olc::Sprite olcPGELogo;
    olc::Decal *olcPGEDecal;
    float creditScreenTime = 0, creditScreenDuration = 1.5;
protected:
    bool OnUserCreate() override
    {
        sAppName = "White Hot - Doudle Studios";
        olcPGELogo.LoadFromFile("../../olcPGELogo.png");
        olcPGEDecal = new olc::Decal(&olcPGELogo);
        return true;
    }

    bool OnUserUpdate(float deltaTime) override
    {
        Clear(0xFF404040);
        if (creditScreenTime < creditScreenDuration)
        {
            DrawDecal({ (ScreenWidth() - olcPGELogo.width * 0.75f) / 2.0f, (ScreenHeight() - olcPGELogo.height * 0.75f) / 2.0f, }, olcPGEDecal, { 0.75f, 0.75f });

            //creditScreenTime += deltaTime;
        }

        return !GetKey(olc::ESCAPE).bReleased;
    }
};

int main()
{
    Game game;
    if (game.Construct(800, 600, 1, 1))
        game.Start();
}