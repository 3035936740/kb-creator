#pragma once

#ifndef DEFINE_HPP
#define DEFINE_HPP
#include <filesystem>
#include "SFML/System/Time.hpp"

namespace kbc::core::define{
  struct BackgroundMusic {
      std::filesystem::path audioPath;
      sf::Time start_pos;
      sf::Time end_pos;
  };
}

#endif //DEFINE_HPP
