#include "Fetcher.hpp"
#include "Renderer.hpp"
#include "GUI.hpp"

int main(int argc, char** argv) {
    // Initialize GUI
    GUI gui;

    // Fetch an HTML page
    Fetcher fetcher;
    std::string htmlContent = fetcher.fetch("http://example.com");

    // Render the page
    Renderer renderer;
    renderer.render(htmlContent, gui);

    return gui.run();
}
