// Engine Bing X2d.cpp: 定义应用程序的入口点。
//

#include "main.hpp"

int main()
{
    core::hidden_console(false);

    // cv::imwrite("result.png", core::utils::clearColor("data/spirit/kirby.png", {207, 176, 255, 255}));

    sf::RenderWindow window(sf::VideoMode(640, 480), "Kirby Creator", sf::Style::Close);

    sf::Event event{};
    while (window.isOpen())
    {
        std::this_thread::sleep_for(kbc::core::global::framePerSecond.getFrames());
        // check all the window's events that were triggered since the last iteration of the loop
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(kbc::core::global::bg.getSprite());
        window.display();
    }

    return 0;
}
