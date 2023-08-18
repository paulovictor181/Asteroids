/**********************************************************************************
// Player (Arquivo de Cabe�alho)
//
// Cria��o:     14 Ago 2023
// Atualiza��o: 18 Ago 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Player do jogo ASTEROIDS
//
**********************************************************************************/

#ifndef _ASTEROIDS_PLAYER_H_
#define _ASTEROIDS_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites

// ---------------------------------------------------------------------------------
// Constantes Globais

// estados poss�veis para o jogador
enum PLAYERSTATE { STOPED, UP, DOWN, LEFT, RIGHT };

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    Sprite* spriteL = nullptr;         // sprite do player indo para esquerda
    Sprite* spriteR = nullptr;         // sprite do player indo para direita
    Sprite* spriteU = nullptr;         // sprite do player indo para cima
    Sprite* spriteD = nullptr;         // sprite do player indo para baixo
    float vel;                          // velocidade do player

public:
    uint currState = STOPED;            // estado atual do jogador
    uint nextState = STOPED;            // pr�ximo estado do jogador

    Player();                           // construtor
    ~Player();                          // destrutor

    void OnCollision(Object* obj);     // resolu��o da colis�o

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif