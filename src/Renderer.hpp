#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <string>

class GUI;

class Renderer {
public:
    void render(const std::string& htmlContent, GUI& gui);
};

#endif
