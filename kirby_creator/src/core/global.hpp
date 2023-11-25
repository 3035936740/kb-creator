#pragma once

#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <filesystem>
#include <SFML/Graphics.hpp>
#include "SFML/System/Time.hpp"
#include "other/BackgroundMusic.hpp"
#include "other/Background.hpp"
#include "common/utils/FramePerSecond.hpp"

using namespace std::chrono_literals;
using namespace kbc::utils;
using namespace kbc::utils::fps_literals;

namespace kbc::core::global {
    const inline std::shared_ptr<std::mutex> mutex;

    inline kbc::other::BackgroundMusic bgMusic;
    inline kbc::utils::FramePerSecond framePerSecond(30_fps, mutex);
    kbc::other::Background bg("data/bg/rainbow_route_1.png", 3.0f, 3.0f);
}
#endif // !GLOBAL_HPP
