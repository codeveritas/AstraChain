
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
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "FormSFML.h"
#include "ResourcePath.hpp"

int main(int, char const**)
{
    // Create the main window (resizable)
    //sf::RenderWindow window(sf::VideoMode(600, 600), "Fake app");
    
    // Unresizable main window
    sf::RenderWindow window;
    window.create(sf::VideoMode(600, 570), "Fake app!", sf::Style::Close);
    
    // button from library
    form::Button button3(270, 350, 90, 20, "Connect");

    
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
    sf::Text text("fake coin app", font, 42);
    text.setFillColor(sf::Color::White);
    
    sf::Text buttonText("button", font, 30);
    buttonText.setFillColor(sf::Color::Black);
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
        
        sf::Text buttonText("button", font, 24);
        buttonText.setFillColor(sf::Color::Black);
        
        buttonText.setFillColor(sf::Color::White);
        buttonText.setString("Login");
        buttonText.setPosition(500, 5);
        window.draw(buttonText);
        buttonText.setString("Settings");
        buttonText.setPosition(500, 40);
        window.draw(buttonText);
        buttonText.setString("Button");
        buttonText.setFillColor(sf::Color::Black);

        text.setPosition(45 , 15);
        window.draw(text);
        
        //draw shapes
        for(int i=0; i<5; i++){
            ellipse.setPosition(120 + 80 * i, 100);
            rectangle.setPosition(120 + 80 * i, 200);
            buttonText.setPosition(80 + 100 * i , 300);
            window.draw(buttonText);
            window.draw(ellipse);
            window.draw(rectangle);
        }
        
        // draw button
        window.draw(button3.displayButton());
        window.draw(button3.displayText());
        
        // Update the window
        window.display();
    }
    
    return EXIT_SUCCESS;
}
