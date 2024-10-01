#include "GUI.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

GUI::GUI() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
    }

    // Allow window resizing by adding the SDL_WINDOW_RESIZABLE flag
    window = SDL_CreateWindow("Rho Web Engine", 100, 100, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Initialize random seed
}

GUI::~GUI() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void GUI::displayText(const std::string& text) {
    std::cout << "GUI Display: " << text << std::endl;
}

int GUI::run() {
    SDL_Event e;
    bool quit = false;
    
    Uint32 lastColorChange = SDL_GetTicks(); // Track time for color change

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }

            // Handle window resizing events
            if (e.type == SDL_WINDOWEVENT) {
                if (e.window.event == SDL_WINDOWEVENT_RESIZED) {
                    int newWidth = e.window.data1;
                    int newHeight = e.window.data2;
                    std::cout << "Window resized to " << newWidth << "x" << newHeight << std::endl;

                    // Optionally, redraw the window on resize
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set color to black
                    SDL_RenderClear(renderer);
                    SDL_RenderPresent(renderer);
                }
            }
        }

        Uint32 currentTime = SDL_GetTicks();
        
        // Change the color every 1000 ms (1 second)
        if (currentTime - lastColorChange >= 1000) {
            Uint8 r = std::rand() % 256;
            Uint8 g = std::rand() % 256;
            Uint8 b = std::rand() % 256;

            SDL_SetRenderDrawColor(renderer, r, g, b, 255);
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);

            lastColorChange = currentTime;
        }
    }

    return 0;
}
