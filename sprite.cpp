#include <SFML/Graphics.hpp>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Drawing 2D Stuff");

    // Example: Create a shape to draw into our render texture
    sf::CircleShape sprite(50.f);
    sprite.setFillColor(sf::Color::Green);
    // game loop
    while (window.isOpen())
    {
        // windows events
        while (const std::optional event = window.pollEvent())
        {
            // close window
            if (event->is<sf::Event::Closed>())
                window.close();
            
        }

        // clear window with black clolor
        window.clear(sf::Color::Black);

        // draw everything here
        // window.draw
        // create a 500x500 render-texture
        sf::RenderTexture renderTexture({500, 500});

        // drawing uses the same functions
        renderTexture.clear(sf::Color::Blue);
        renderTexture.draw(sprite); // or any other drawable
        renderTexture.display();

        // get the target texture (where the stuff has been drawn)
        const sf::Texture& texture = renderTexture.getTexture();

        // draw it to the window
        sf::Sprite sprite(texture);
        window.draw(sprite);

        // end t he frame
        window.display();
        
    }
    
}
