//
// Created by Bing on 2023/11/22.
//

#include "Kirby.hpp"

kbc::spirit::Kirby::Kirby() = default;

kbc::spirit::Kirby::~Kirby() = default;

kbc::spirit::Kirby::Kirby(const kbc::spirit::Kirby& kirby){
    *this = kirby;
}

kbc::spirit::Kirby::Kirby(kbc::spirit::Kirby&& kirby) noexcept {
    *this = std::move(kirby);
}

kbc::spirit::Kirby& kbc::spirit::Kirby::operator=(const kbc::spirit::Kirby& kirby){
    if (this == &kirby)
        return *this;
    *this = kirby;
    return *this;
}

kbc::spirit::Kirby& kbc::spirit::Kirby::operator=(kbc::spirit::Kirby&& kirby) noexcept {
    if (this == &kirby)
        return *this;
    *this = std::move(kirby);
    return *this;
}