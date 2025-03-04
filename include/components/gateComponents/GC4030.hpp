/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** GC4030
*/

#ifndef GC4030_HPP_
#define GC4030_HPP_

#include "../XorGate.hpp"

//           +---------4030---------+
// in_01  -1-|>-+---\       ignored-|-14-
//           |  |xor |-+            |
// in_02  -2-|>-+---/  |     /---+-<|-13- in_13
//           |         |  +-| xor|  |
// out_03 -3-|<--------+  |  \---+-<|-12- in_12
//           |            |         |
// out_04 -4-|<--------+  +-------->|-11- out_11
//           |         |            |
// in_05  -5-|>-+---\  |  +-------->|-10- out_10
//           |  |xor |-+  |         |
// in_06  -6-|>-+---/     |  /---+-<|-9-  in_09
//           |            +-| xor|  |
//        -7-|-ignored       \---+-<|-8-  in_08
//           +----------------------+

namespace nts
{
    namespace component
    {
        class GC4030 : public nts::AComponent
        {
            public:
                GC4030(const std::string &name="None");
                ~GC4030();
                nts::Tristate run(size_t pin);
            private:
                nts::component::XorGate _xg1;
                nts::component::XorGate _xg2;
                nts::component::XorGate _xg3;
                nts::component::XorGate _xg4;
        };
    };
};

#endif /* !GC4030_HPP_ */
