/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** CD4030
*/

#ifndef CD4030_HPP_
#define CD4030_HPP_

#include "XorGate.hpp"

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
        class CD4030 : public nts::AComponent
        {
            public:
                CD4030(const std::string &name="None");
                ~CD4030();
                nts::Tristate run(size_t) final;
            private:
                std::vector<nts::component::XorGate &> _xorGates;
        };
    };
};

#endif /* !CD4030_HPP_ */
