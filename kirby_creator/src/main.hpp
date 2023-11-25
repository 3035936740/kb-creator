#pragma once

#ifndef MAIN_HPP
#define MAIN_HPP
#include <core_game>
#include "spirit/Kirby.hpp"

[[maybe_unused]] inline const int init { []()->int {
    std::jthread music_thread([&](){
        kbc::core::global::bgMusic.setMusic("data/audio/green_greens.ogg",
                                            sf::seconds(6) + sf::milliseconds(780),
                                            sf::seconds(57) + sf::milliseconds(190));
        while (true){
            std::this_thread::sleep_for(kbc::core::global::framePerSecond.getFrames());
            kbc::core::global::bgMusic.loopDetection();
        }
    });

    music_thread.detach();


    std::this_thread::sleep_for(50ms);
    /*
    kbc::core::global::bgMusic.setMusic("data/audio/green_greens.ogg",
    sf::seconds(6) + sf::milliseconds(780),
    sf::seconds(57) + sf::milliseconds(190));

    kbc::core::global::bgMusic.setMusic("data/audio/candy_mountain.ogg",
    sf::seconds(5) + sf::milliseconds(560),
    sf::seconds(65) + sf::milliseconds(400));
    */

    return 0;
    }()
};

#endif // !MAIN_HPP