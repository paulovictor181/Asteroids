/**********************************************************************************
// Level1 (Arquivo de Cabeçalho)
//
// Criação:     14 Ago 2023
// Atualização: 18 Ago 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Nível 1 do jogo ASTEROIDS
//
**********************************************************************************/

#ifndef _ASTEROIDS_LEVEl1_H_
#define _ASTEROIDS_LEVEL1_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"

// ------------------------------------------------------------------------------

class Level1 : public Game
{
private:
    Sprite* backg = nullptr;       // background
    Scene* scene = nullptr;        // gerenciador de cena
    bool viewBBox = false;          // habilita visualização da bounding box

public:
    void Init();                    // inicializa jogo
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo
};

// -----------------------------------------------------------------------------

#endif