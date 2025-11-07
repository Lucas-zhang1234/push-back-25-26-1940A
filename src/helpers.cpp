#include "helpers.hpp"
#include "pros/rtos.hpp"
#include "robot.hpp"

void colourSort() {
    // nothing
}

void startScoring() {
    // LEGACY
    // Switcheroo.extend();
    
    Top_Roller.move(12000);
    // Inside_Roller.move(-12000);
}

void stopScoring() {
    // LEGACY
    Top_Roller.move(0);
    // Inside_Rollser.move(0);
    // Bottom_Roller.move(0);
}

void startIntaking() {
    stopIntaking();
    // LEGACY
    bottomRollerMove(-12000);
    Top_Roller.move(12000);
}

void stopIntaking() {
    stopScoring();
    bottomRollerMove(0);
}

void swapScoringTarget() {
    // Switcheroo.toggle();
}

void setBlockMovementTarget(BlockMoveTarget target) {
    // LEGACY
    // if (target == BlockMoveTarget::INTAKE)
    // {
    //     Switcheroo.retract();
    // }
    // if (target == BlockMoveTarget::HIGH_GOAL || target == BlockMoveTarget::LONG_GOAL)
    // {
    //     Switcheroo.extend();
    // }
    // if (target == BlockMoveTarget::LOW_GOAL)
    // {
    //     Switcheroo.retract();
    // }
}

void bottomRollerMove(int voltage)
{
    Bottom_Roller_Blue.move(-voltage);
    Bottom_Roller_Green.move(voltage);
}