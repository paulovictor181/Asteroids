/**********************************************************************************
// Player (Código Fonte)
//
// Criação:     01 Jan 2013
// Atualização: 04 Mar 2023
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
   // spriteL = new Sprite("Resources/PacManL.png");
   // spriteR = new Sprite("Resources/PacManR.png");
   // spriteU = new Sprite("Resources/PacManU.png");
   // spriteD = new Sprite("Resources/PacManD.png");

    // imagem do pacman é 48x48 (com borda transparente de 4 pixels)
    BBox(new Rect(-20, -20, 20, 20));
    MoveTo(480.0f, 450.0f);
    type = PLAYER;
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

void Player::Stop()
{
    velX = 0;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Player::Up()
{
    velX = 0;
    velY = -200.0f;
}

// ---------------------------------------------------------------------------------

void Player::Down()
{
    velX = 0;
    velY = 200.0f;
}

// ---------------------------------------------------------------------------------

void Player::Left()
{
    velX = -200.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Player::Right()
{
    velX = 200.0f;
    velY = 0;
}

// ---------------------------------------------------------------------------------

void Player::OnCollision(Object* obj)
{
    //if (obj->Type() == PIVOT)
        //PivotCollision(obj);
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    if (window->KeyDown(VK_LEFT))
    {
      
    }

    if (window->KeyDown(VK_RIGHT))
    {
       
    }

    if (window->KeyDown(VK_UP))
    {
      
    }

    if (window->KeyDown(VK_DOWN))
    {

    }

    // atualiza posição
    Translate(velX * gameTime, velY * gameTime);

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
   
}

// ---------------------------------------------------------------------------------