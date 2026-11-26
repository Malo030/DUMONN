#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test Interface SFML");
    window.setFramerateLimit(60);

    // 1. Création du bouton (rectangle)
    sf::RectangleShape bouton(sf::Vector2f(220.f, 70.f));
    bouton.setOrigin(sf::Vector2f(110.f, 35.f)); // Centre du rectangle
    bouton.setPosition(sf::Vector2f(400.f, 300.f));
    bouton.setFillColor(sf::Color(50, 120, 210));
    bouton.setOutlineThickness(2.f);
    bouton.setOutlineColor(sf::Color::White);

    // 2. Icône "Play" (triangle à 3 côtés, évite d'avoir besoin d'une police .ttf)
    sf::CircleShape iconePlay(20.f, 3);
    iconePlay.setOrigin(sf::Vector2f(20.f, 20.f));
    iconePlay.setRotation(90.f);
    iconePlay.setPosition(sf::Vector2f(404.f, 300.f));
    iconePlay.setFillColor(sf::Color::White);

    bool modeActif = false;

    while (window.isOpen()) {
        // Position de la souris convertie dans le repère de la fenêtre
        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePos = window.mapPixelToCoords(pixelPos);

        // Vérifie si la souris survole le bouton
        bool survol = bouton.getGlobalBounds().contains(mousePos);

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Détection du clic gauche sur le bouton
            if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left && survol) {
                modeActif = !modeActif;
                std::cout << "Bouton clique ! Etat : " << (modeActif ? "ON" : "OFF") << "\n";
            }
        }

        // Changement visuel au survol
        bouton.setFillColor(survol ? sf::Color(80, 155, 245) : sf::Color(50, 120, 210));

        // Couleur de fond selon l'état du bouton
        sf::Color couleurFond = modeActif ? sf::Color(25, 65, 60) : sf::Color(30, 30, 35);

        window.clear(couleurFond);
        window.draw(bouton);
        window.draw(iconePlay);
        window.display();
    }

    return 0;
}