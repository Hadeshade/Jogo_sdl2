// Criado por mim (Marco Antonio) seguindo tutorial de um livro;
/*
                                    BREVE DESCRIÇÃO:
    Definição das funções da classe Game. A função init é a função principal que inicializa
a janela, o renderizador e que chama os objetos a serem apresentados e verifica se tudo vai
ser criado com sucesso ou não; A função render é responsável por renderizar tudo que criamos
na função init e jogar para a tela; A função update é a função que dá vida a animação e ao 
movimento de nossos objetos; A função clear fecha todos os sistemas abertos e finaliza o jogo
da forma correta (de acordo com as boas práticas de programação);
*/

#include "Game.h"


Game::Game()
{
}

Game::~Game()
{
}

bool Game::init(const char* title,int xpos, int ypos, int width, int height, int flags) 
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init success\n";
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if (m_pWindow != 0)
        {
            std::cout << "window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if (m_pRenderer != 0)
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer, 0,0, 0, 255);
                TheTextureManager::Instance()->load("animate.png","animate",m_pRenderer);
                m_go.load(100,100,128,82, "animate");
                m_player.load(300,300,128,82,"animate");
                
                // A proxima linha foi apenas um teste com outro sprite-sheet;
                //TheTextureManager::Instance()->load("teste_animacao.png","teste",m_pRenderer); 
            }
            else
            {
                std::cout << "renderer init fail\n";
                return false;           // falha na inicialização do renderizador
            }   
        }
        else
        {
            std::cout << "window init fail\n";
            return false;               // falha na inicialização da janela
        } 
    }
    else
    {
        std::cout << "SDL init fail\n";
        return false;
    }
    
    std::cout << "init success\n";

    
    m_pRunning = true;
    
    return true;
    
}

void Game::render() 
{
    SDL_RenderClear(m_pRenderer);        // clear the renderer to the draw color
    
    m_go.draw(m_pRenderer);
    m_player.draw(m_pRenderer);
    // As proximas linhas de codigo foram substituidas pelas linhas anteriores:
    // TheTextureManager::Instance()->draw("animate",0,0,128,82,m_pRenderer);
    //TheTextureManager::Instance()->drawFrame("animate",100,100,128,82,1,m_currentFrame,m_pRenderer);
    // TheTextureManager::Instance()->drawFrame("teste",200,200,71,88,1,m_currentFrame2,m_pRenderer);

    SDL_RenderPresent(m_pRenderer);      // draw to the screen 
}

void Game::update() 
{
    m_go.update();
    m_player.update();
    
    //m_currentFrame = int(((SDL_GetTicks()/100)%6));
    //m_currentFrame2 = int(((SDL_GetTicks()/100)%8));
}

void Game::handleEvents() 
{
    SDL_Event event;
    if (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            m_pRunning = false;
        break;
        
        default:
        break;
        }
    }
    
}

void Game::clear() 
{
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}
