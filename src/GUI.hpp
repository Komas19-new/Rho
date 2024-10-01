#ifndef GUI_HPP
#define GUI_HPP

#include <SDL2/SDL.h>
#include <string>

class GUI {
public:
    GUI();
    ~GUI();
    void displayText(const std::string& text);
    int run();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif // GUI_HPP
