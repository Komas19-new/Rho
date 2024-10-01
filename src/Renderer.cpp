#include "Renderer.hpp"
#include "GUI.hpp"
#include <libxml/HTMLparser.h>
#include <iostream>

void Renderer::render(const std::string& htmlContent, GUI& gui) {
    // Parse HTML content with libxml2
    htmlDocPtr doc = htmlReadMemory(htmlContent.c_str(), htmlContent.size(), "noname.xml", NULL, HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING);
    if (doc == nullptr) {
        std::cerr << "Failed to parse HTML" << std::endl;
        return;
    }

    // Display parsed content in the GUI (simplified example)
    xmlNode* root = xmlDocGetRootElement(doc);
    if (root) {
        gui.displayText("Parsed HTML Root Node: " + std::string((char*)root->name));
    }

    xmlFreeDoc(doc);
}
