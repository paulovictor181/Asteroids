/**********************************************************************************
// Player (Arquivo de Cabeçalho)
//
// Criação:     14 Ago 2023
// Atualização: 18 Ago 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Player do jogo ASTEROIDS
//
**********************************************************************************/

#ifndef _ASTEROIDS_PLAYER_H_
#define _ASTEROIDS_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // interface de Sprites

// ---------------------------------------------------------------------------------
// Constantes Globais

// estados possíveis para o jogador
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
    uint nextState = STOPED;            // próximo estado do jogador

    Player();                           // construtor
    ~Player();                          // destrutor

    void OnCollision(Object* obj);     // resolução da colisão

    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif