
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    // Create the main window (resizable)
    //sf::RenderWindow window(sf::VideoMode(600, 600), "Fake app");
    
    // Unresizable main window
    sf::RenderWindow window;
    window.create(sf::VideoMode(600, 570), "Fake app!", sf::Style::Close);
    
    // Setting ellipse shape
    sf::CircleShape ellipse(30.f);
    ellipse.setFillColor(sf::Color::Red);
    
    // Setting ellipse shape
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(60, 60));
    rectangle.setFillColor(sf::Color::Blue);
    
    // Setting the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    
    // Loading background
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "menu_image.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);
    
    // Setting font for text
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "fakecoin.ttf")) {
    //    if (!font.loadFromFile(resourcePath() + "Roboto-Medium.ttf")) {
        
        return EXIT_FAILURE;
    }
    sf::Text text("fake coin app", font, 60);
    text.setFillColor(sf::Color::White);
    
    // Load a music to play
    //    sf::Music music;
    //    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
    //        return EXIT_FAILURE;
    //    }
    
    // Play the music
    //    music.play();
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }
        
        // Clear screen
        window.clear();
        
        // Draw the sprite
        window.draw(sprite);
        
        // Draw the string
        text.setPosition(120 , 0);
        window.draw(text);
        
        //draw the shape
        for(int i=0; i<5; i++){
            ellipse.setPosition(120 + 80 * i, 100);
            rectangle.setPosition(120 + 80 * i, 200);
            window.draw(ellipse);
            window.draw(rectangle);


        }

        // Update the window
        window.display();
    }
    
    return EXIT_SUCCESS;
}
