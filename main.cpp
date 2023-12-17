#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
    // Configuración de la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Caída y rebote de una esfera");
    window.setFramerateLimit(60);

    // Configuración de la esfera
    sf::CircleShape sphere(30.0f);
    sphere.setFillColor(sf::Color::Red);
    sf::Vector2f position(400.0f, 0.0f);
    sf::Vector2f velocity(0.0f, 0.0f);
    float gravity = 0.5f; // Ajusta la gravedad según tus necesidades
    float bounceFactor = 0.7f; // Factor de rebote (ajusta según sea necesario)

    // Bucle principal
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Aplicar gravedad
        velocity.y += gravity;

        // Actualizar posición de la esfera
        position += velocity;
        sphere.setPosition(position);

        // Verificar colisión con el suelo
        if (position.y + sphere.getRadius() >= window.getSize().y) {
            // Rebote en el suelo
            position.y = window.getSize().y - sphere.getRadius();
            velocity.y = -velocity.y * bounceFactor;
        }

        // Limpiar la pantalla
        window.clear();

        // Dibujar la esfera
        window.draw(sphere);

        // Mostrar el contenido en la ventana
        window.display();
    }

    return 0;
}
