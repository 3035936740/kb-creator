//
// Created by Bing on 2023/11/22.
//

#ifndef KIRBY_HPP
#define KIRBY_HPP
#include <utility>

namespace kbc::spirit{
    class Kirby {
    private:

    public:
        Kirby();
        virtual ~Kirby();
        Kirby(const Kirby&);
        Kirby(Kirby&&) noexcept ;
        virtual Kirby& operator=(const Kirby&);
        virtual Kirby& operator=(Kirby&&) noexcept;
    };
}

#endif // KIRBY_HPP
