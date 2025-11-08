#include "auton.h"
#include "lemlib/asset.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include "robot.hpp"
#include "skills_auton.h"
#include "finals_auton.h"
#include "helpers.hpp"
#include <random>

ASSET(path1_txt);
ASSET(path3_txt);
ASSET(testpath_txt);

void auton(int autonToRun) {
    if (autonToRun == 0)
    {
        new_skills_auton();
    }

    if (autonToRun == 1)
    {
        Left_7B_2G();
    }
    if (autonToRun == 2)
    {
        Right_7B_2G();
    }

    if (autonToRun == 3)
    {
        finals_left_auton();
    }

    if (autonToRun == 4)
    {
        finals_right_auton();
    }

    if (autonToRun == 5)
    {
        pid_test();
    }

    if (autonToRun == 6)
    {
        Left_6B_1G();
    }
};

void Left_7B_2G()
{
    Left();

    // Intake 3 blocks and score in the high goal
    Top_Roller.move_velocity(-8000);
    setBlockMovementTarget(HIGH_GOAL);
    startIntaking();
    chassis.moveToPoint(-25, 12.5, 2000, {.maxSpeed = 70});
    chassis.waitUntilDone();
    chassis.turnToPoint(-65, 50, 1000);
    chassis.waitUntilDone();
    startScoring();
    // Ram
    chassis.moveToPoint(-11, 5, 2000, {.forwards = false, .minSpeed = 100});
}

void Left_6B_1G()
{
    Left();

    chassis.moveToPose(-13, 55, 90, 2000, {.forwards = true});
    chassis.waitUntilDone();
    Matchloader.extend();
    chassis.moveToPose(-10, 50, 120, 2000);
    chassis.waitUntilDone();
    chassis.moveToPose(-13, 55, 90, 2000, {.forwards = false});
    chassis.waitUntilDone();
    Matchloader.retract();
    startIntaking();
    chassis.moveToPoint(-9, 55, 1000);
    chassis.waitUntilDone();
    pros::delay(100);
    chassis.moveToPose(-50, 43, 90, 1300);
    chassis.waitUntilDone();
    chassis.moveToPoint(-35, 43, 1000, {.forwards = false, .maxSpeed = 70});
    startScoring();
}

void Left()
{
    right_mg.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    left_mg.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(-50.425, 18, 0);
    startIntaking();
    setBlockMovementTarget(INTAKE);

    // Move to matchloader
    chassis.moveToPose(-47, 49, 0, 1000, {}, true);
    chassis.turnToHeading(270, 1000);

    // Collect blocks from matchloader
    Matchloader.extend();
    chassis.moveToPose(-60, 43, 270, 1500);
    for (int i = 0; i < 3; i++) {
        chassis.moveToPoint(-66.5, 43, 450, {.minSpeed = 80});
        chassis.moveToPoint(-62.5, 43, 450);
    }
    Matchloader.retract();
 
    // Move to long goal
    chassis.waitUntilDone();
    chassis.moveToPoint(-35, 43, 1000, {.forwards = false, .maxSpeed = 70});
    chassis.waitUntilDone();

    // Score all 4 blocks in the long goal
    setBlockMovementTarget(LONG_GOAL);
    startScoring();
    pros::delay(2700);
    stopScoring();

    // Move back slightly
    chassis.moveToPoint(-50, 43, 1000);
    chassis.waitUntilDone();
}

void Right_7B_2G()
{
    right_mg.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    left_mg.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    chassis.setPose(50.425, 15, 0);
    startIntaking();
    setBlockMovementTarget(INTAKE);

    // Move to matchloader
    chassis.moveToPose(47, 49, 0, 1900, {}, true);
    chassis.turnToHeading(90, 1000);

    // Collect blocks from matchloader
    Matchloader.extend();
    chassis.moveToPose(60, 43, 90, 1500);
    for (int i = 0; i < 3; i++) {
        chassis.moveToPoint(64, 43, 450, {.minSpeed = 100});
        chassis.moveToPoint(60.3, 43, 450, {.minSpeed = 100});
    }
 
    // Move to long goal
    chassis.waitUntilDone();
    chassis.moveToPoint(34, 43, 1900, {.forwards = false, .maxSpeed = 70});
    chassis.waitUntilDone();

    // Score all 4 blocks in the long goal
    setBlockMovementTarget(LONG_GOAL);
    startScoring();
    pros::delay(2700);
    stopScoring();

    // Move back slightly
    chassis.moveToPoint(50, 43, 1000);
    chassis.waitUntilDone();

    // Score 3 blocks in the low goal
    bottomRollerMove(12000);
    chassis.turnToHeading(225, 500);
    chassis.waitUntilDone();
    chassis.moveToPoint(21.4, 11, 2000, {.maxSpeed = 60});
    chassis.waitUntilDone();
    bottomRollerMove(-12000);
}