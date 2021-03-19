// Criado por mim (Marco Antonio) seguindo tutorial de um livro;
/*
                                    BREVE DESCRIÇÃO:
    Classe criada com o objetivo de criar nossos players, usando uma prática de POO: a herança.
Essa Classe a principio é igual a GameObject só que com leves diferenças; Essa classe herda tudo
da classe mãe (GameObject), e sobrescreve as funções para fazer coisas diferentes;
*/
#include "GameObject.h"

class Player : public GameObject 
{
public:
    void load(int x, int y, int width, int height, std::string textureid);
    void draw(SDL_Renderer* pRenderer);
    void update();
    void clear();
};