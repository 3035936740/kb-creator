//
// Created by Bing on 2023/11/21.
//
#pragma once

#ifndef INIT_HPP
#define INIT_HPP

namespace kbc::core::init{
    [[maybe_unused]] const bool loadLeadTexture {[](){
        // global::lead.loadFromFile("data/spirit/kirby.png");
        // global::player.setTexture(global::lead);
        // global::player.setTexture(sf::IntRect());
        return true;
    }()};
}

#endif //INIT_HPP
