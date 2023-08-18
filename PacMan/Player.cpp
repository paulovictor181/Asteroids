/**********************************************************************************
// Player (Código Fonte)
//
// Criação:     14 Ago 2023
// Atualização: 18 Ago 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Player do jogo PacMan
//
**********************************************************************************/

#include "Asteroids.h"
#include "Player.h"

// ---------------------------------------------------------------------------------

Player::Player()
{
    spriteL = new Sprite("Resources/SpaceshipL.png");
    spriteR = new Sprite("Resources/SpaceshipR.png");
    spriteU = new Sprite("Resources/SpaceshipU.png");
    spriteD = new Sprite("Resources/SpaceshipD.png");

    vel = 70;

    // imagem da nave é 92x96 (com borda transparente de 4 pixels)
    BBox(new Rect(-46, -48, 46, 48));
    MoveTo(480.0f, 450.0f);
    type = PLAYER;
    currState = DOWN;
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete spriteL;
    delete spriteR;
    delete spriteU;
    delete spriteD;
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object* obj)
{
    
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    if (window->KeyDown(VK_LEFT))
    {
        currState = LEFT;
        Translate(-vel * gameTime, 0);
    }

    if (window->KeyDown(VK_RIGHT))
    {   
        currState = RIGHT;
        Translate(vel * gameTime, 0);
    }

    if (window->KeyDown(VK_UP))
    {
        currState = UP;
        Translate(0, -vel * gameTime);
    }

    if (window->KeyDown(VK_DOWN))
    {
        currState = DOWN;
        Translate(0, vel * gameTime);
    }

    // mantém player dentro da tela
    if (x + 20 < 0)
        MoveTo(window->Width() + 20.f, Y());

    if (x - 20 > window->Width())
        MoveTo(-20.0f, Y());

    if (Y() + 20 < 0)
        MoveTo(x, window->Height() + 20.0f);

    if (Y() - 20 > window->Height())
        MoveTo(x, -20.0f);
}

// ---------------------------------------------------------------------------------

void Player::Draw()
{
   switch(currState)
    {
    case LEFT:  spriteL->Draw(x, y, Layer::UPPER); break;
    case RIGHT: spriteR->Draw(x, y, Layer::UPPER); break;
    case UP:    spriteU->Draw(x, y, Layer::UPPER); break;
    case DOWN:  spriteD->Draw(x, y, Layer::UPPER); break;
    default: 
        switch(nextState)
        {
        case LEFT:  spriteL->Draw(x, y, Layer::UPPER); break;
        case RIGHT: spriteR->Draw(x, y, Layer::UPPER); break;
        case UP:    spriteU->Draw(x, y, Layer::UPPER); break;
        case DOWN:  spriteD->Draw(x, y, Layer::UPPER); break;
        default:    spriteL->Draw(x, y, Layer::UPPER);
        }
    }
}

// ---------------------------------------------------------------------------------