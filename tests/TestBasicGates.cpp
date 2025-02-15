/*
** EPITECH PROJECT, 2025
** nanoTekSpice
** File description:
** TestBasicGates
*/

#include "../include/tests.hpp"

Test(AndGate, pins)
{
    component::AndGate comp;

    cr_assert(comp.getNbInputs() == 2 &&
        comp.getNbOutputs() == 1 &&
        comp.isInputPin(1) &&
        comp.isInputPin(2) &&
        comp.isOutputPin(3));
}

Test(AndGate, simulate)
{
    component::AndGate comp;

    comp.setPin(1, nts::Tristate::True);
    comp.setPin(2, nts::Tristate::True);
    comp.simulate(1);
    if (comp.compute(3) != nts::Tristate::True)
        cr_assert(false);

    comp.setPin(1, nts::Tristate::True);
    comp.setPin(2, nts::Tristate::False);
    comp.simulate(1);
    if (comp.compute(3) != nts::Tristate::False)
        cr_assert(false);

    comp.setPin(1, nts::Tristate::False);
    comp.setPin(2, nts::Tristate::False);
    comp.simulate(1);
    if (comp.compute(3) != nts::Tristate::False)
        cr_assert(false);
}

Test(OrGate, pins)
{
    component::OrGate comp;

    cr_assert(comp.getNbInputs() == 2 &&
        comp.getNbOutputs() == 1 &&
        comp.isInputPin(1) &&
        comp.isInputPin(2) &&
        comp.isOutputPin(3));
}

Test(XorGate, pins)
{
    component::XorGate comp;

    cr_assert(comp.getNbInputs() == 2 &&
        comp.getNbOutputs() == 1 &&
        comp.isInputPin(1) &&
        comp.isInputPin(2) &&
        comp.isOutputPin(3));
}

Test(NotGate, pins)
{
    component::NotGate comp;

    cr_assert(comp.getNbInputs() == 1 &&
        comp.getNbOutputs() == 1 &&
        comp.isInputPin(1) &&
        comp.isOutputPin(2));
}
