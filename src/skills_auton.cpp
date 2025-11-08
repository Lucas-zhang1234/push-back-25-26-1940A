#include "skills_auton.h"
#include "lemlib/asset.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/pose.hpp"
#include "robot.hpp"
#include "helpers.hpp"
ASSET(singlepath_auton_skills_61pt)
ASSET(testpath_txt)
ASSET(as_right_s_to_ml_txt)
ASSET(as_right_ml_to_lg_txt)
ASSET(as_right_lg_to_ml2_txt)
void skills_auton() {
    // Bottom_Roller.move(-12000);
    // Top_Roller.move(12000);
    // Switcheroo.retract();
    // chassis.setPose(-62.87, 15.447, 180);
    // pros::delay(200);
    // chassis.moveToPoint(-62.87, -8.335, 3000);

    chassis.setPose(45.65, 16.9, 0);
    startIntaking();
    setBlockMovementTarget(INTAKE);
    float firstMatchloaderY = 47.4;
    // Move to matchloader
    chassis.moveToPose(42.5, firstMatchloaderY, 0, 1000);
    chassis.turnToHeading(90, 1000);
    chassis.waitUntilDone();

    // Collect blocks from matchloader
    Matchloader.extend();
    chassis.moveToPose(55.5, firstMatchloaderY, 90, 1500,{.maxSpeed = 70});
    for (int i = 0; i < 7; i++) {
        chassis.moveToPoint(57, firstMatchloaderY, 450, {.minSpeed = 100});
        chassis.moveToPoint(55.2, firstMatchloaderY, 450);
    }
    chassis.moveToPoint(57.75, firstMatchloaderY, 450, {.minSpeed = 100});
    pros::delay(500);
    chassis.moveToPoint(55.2, firstMatchloaderY, 450);

    // Move to Long goal
    chassis.waitUntilDone();
    chassis.moveToPoint(50.5, firstMatchloaderY, 2000);
    chassis.waitUntilDone();
    Matchloader.retract();
    pros::delay(100);
    chassis.turnToHeading(280, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(29.3, firstMatchloaderY + 0.8, 2000);
    chassis.waitUntilDone();

    // Score all 7 blocks in the long goal
    setBlockMovementTarget(LONG_GOAL);
    startScoring();
    pros::delay(4700);

    // Reverse slightly
    chassis.moveToPoint(51.5, firstMatchloaderY, 1500, {.forwards = false});
    chassis.waitUntilDone();
    setBlockMovementTarget(INTAKE);
    chassis.turnToHeading(225, 70, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
    Top_Roller.move(12000);

    // Intake 4 more blocks
    chassis.moveToPose(13, 14, 225, 3000, {.maxSpeed = 60});
    chassis.waitUntilDone();

    // Go back to the front of the long goal
    chassis.moveToPoint(45.5, firstMatchloaderY, 1000, {.forwards = false});
    chassis.waitUntilDone();
    pros::delay(100);
    chassis.turnToHeading(270, 1000, {.direction = lemlib::AngularDirection::CW_CLOCKWISE});
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.moveToPose(28.4, firstMatchloaderY - 4.2, 270, 1800, {.maxSpeed = 70});
    chassis.waitUntilDone();

    // Score all 4 blocks in the long goal
    setBlockMovementTarget(LONG_GOAL);
    startScoring();
    pros::delay(2900);
    swapScoringTarget();

    // Move back
    chassis.moveToPoint(38, firstMatchloaderY,  1000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.turnToHeading(0, 1000);
    stopScoring();

    // // SETUP FROM CORNER ================================================
    // Bottom_Roller.move(-12000);
    // Top_Roller.move(12000);
    // Inside_Roller.move(0);
    // Switcheroo.retract();

    // chassis.setPose(lemlib::Pose(42.67, -64, 0));

    float secondMatchloaderY = -55.4;
    // ======== OTHER CORNER ========
    // Move back to other corner
    chassis.moveToPose(38, secondMatchloaderY, 0, 5000, {.forwards = false});
    chassis.turnToHeading(90, 1000);
    chassis.waitUntilDone();

    // Collect blocks from matchloader
    Matchloader.extend();
    startIntaking();
    setBlockMovementTarget(INTAKE);
    chassis.moveToPose(52, secondMatchloaderY, 90, 1500,{.maxSpeed = 70});
    for (int i = 0; i < 7; i++) {
        chassis.moveToPoint(56, secondMatchloaderY, 450, {.minSpeed = 100});
        chassis.moveToPoint(51.7, secondMatchloaderY, 450);
    }
    chassis.moveToPoint(55, secondMatchloaderY, 450, {.minSpeed = 100});
    pros::delay(400);
    chassis.moveToPoint(52, secondMatchloaderY, 450);

    // Move to Long goal
    chassis.waitUntilDone();
    chassis.moveToPoint(49.7, secondMatchloaderY, 1000);
    chassis.waitUntilDone();
    Matchloader.retract();
    pros::delay(100);
    chassis.moveToPose(22, secondMatchloaderY + 0.3, 90, 1000);
    chassis.waitUntilDone();
    pros::delay(200);

    // Score all 6 blocks in the long goal
    setBlockMovementTarget(LONG_GOAL);
    startScoring();
    pros::delay(4400);

    setBlockMovementTarget(INTAKE);

    // Reverse slightly
    chassis.moveToPoint(47, secondMatchloaderY, 2000, {.forwards = false});
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.turnToHeading(315, 70, {.direction = lemlib::AngularDirection::CW_CLOCKWISE});
    Top_Roller.move(12000);

    // Intake 4 more blocks
    startIntaking();
    setBlockMovementTarget(INTAKE);
    chassis.moveToPoint(10, -24, 3000, {.maxSpeed = 70});
    chassis.waitUntilDone();
    pros::delay(200);

    // Go back to the front of the long goal
    chassis.moveToPoint(44, secondMatchloaderY + 0.45, 1000, {.forwards = false});
    chassis.waitUntilDone();
    pros::delay(100);
    chassis.turnToHeading(270, 1000, {.direction = lemlib::AngularDirection::CCW_COUNTERCLOCKWISE});
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.moveToPose(22, secondMatchloaderY - 0.35, 270, 1000);
    chassis.waitUntilDone();
    pros::delay(200);

    // Score all 4 blocks in the long goal
    setBlockMovementTarget(LONG_GOAL);
    startScoring();
    pros::delay(3000);
    setBlockMovementTarget(INTAKE);

    // // SETUP FOR PARK ======================================================================
    // chassis.setPose(lemlib::Pose(26, -46.3, 270));
    // Bottom_Roller.move(-12000);
    // Top_Roller.move(12000);
    // Inside_Roller.move(-12000);
    // Switcheroo.extend();

    // Park and clear park zone
    ODOM_Lift.extend();
    bottomRollerMove(12000);
    chassis.moveToPoint(49, secondMatchloaderY, 1200, {.forwards = false, .minSpeed = 70});
    chassis.waitUntilDone();
    pros::delay(100);
    chassis.turnToHeading(217, 1000);
    chassis.waitUntilDone();
    pros::delay(100);
    chassis.moveToPoint(68.5, 8.8, 15000, {.minSpeed = 85});
    right_mg.move_velocity(450);
};

void new_skills_auton()
{
    chassis.setPose(-46.997, -15.275, 90);
    startIntaking();
    chassis.follow(as_right_s_to_ml_txt, 1.3, 2000, true, false);
    stopIntaking();
    chassis.follow(as_right_ml_to_lg_txt, 1.3, 2000, true, false);
    chassis.follow(as_right_lg_to_ml2_txt, 1.3, 2000, true, false);
}

void pid_test()
{
    // chassis.moveToPoint(-46.768, -46.868, 1000);
    // chassis.waitUntilDone();
    // pros::delay(100);
    // chassis.turnToHeading(270, 1000);
    // chassis.waitUntilDone();
    // Matchloader.extend();
    // chassis.moveToPoint(-55, -46.868, 1000);
    // startIntaking();
    // setBlockMovementTarget(INTAKE);
    // for (int i = 0; i < 7; i++) {
    //     chassis.moveToPoint(-61, -46.868, 450, {.minSpeed = 100});
    //     chassis.moveToPoint(-58.4, -46.868, 450);
    // }
    // chassis.moveToPoint(-29, -46.868, 1500, {.forwards = false});
    // chassis.waitUntilDone();
    // startScoring();
    chassis.setPose(-46.768, -15.046,  180);
    chassis.moveToPoint(-46.768, -46.639, 1000);
    chassis.waitUntilDone();
    chassis.turnToHeading(270, 1000);
    chassis.waitUntilDone();
    Matchloader.extend();
    chassis.moveToPoint(-55, -46.868, 1000);
    startIntaking();
    setBlockMovementTarget(INTAKE);
    for (int i = 0; i < 7; i++) {
        chassis.moveToPoint(-60.5, -46.868, 450, {.minSpeed = 110});
        chassis.moveToPoint(-55.5, -46.868, 450);
    }
    chassis.moveToPoint(-60.5, -46.868, 450, {.minSpeed = 110});
    pros::delay(300);

    // Go to the long goal and score 3 blue blocks
    chassis.moveToPoint(-56.154, -46.639, 2000);

    for (int i = 0; i < 4; i++)
    {
        startOuttaking();
        pros::delay(50);
        startIntaking();
        pros::delay(50);
    }
    
    chassis.waitUntilDone();
    chassis.moveToPoint(-29, -46.639, 1000, {.forwards = false});
    chassis.waitUntilDone();
    startScoring();
    pros::delay(2100);
    stopScoring();

    // Go to the other matchloader
    chassis.moveToPoint(-40, -46.639, 2000);
    chassis.waitUntilDone();
    chassis.moveToPose(8.636, -31.987, 90, 3000, {.lead = 0.6});
    chassis.waitUntilDone();
    chassis.moveToPose(27, -31.987, 90, 1500);
    chassis.waitUntilDone();
    chassis.moveToPose(56.484, -46.868, 90, 2000);
    chassis.waitUntilDone();

    // Intake 3 blocks
    startIntaking();
    for (int i = 0; i < 3; i++) {
        chassis.moveToPoint(57, -46.868, 450, {.minSpeed = 110});
        chassis.moveToPoint(52, -46.868, 450);
    }
    pros::delay(200);

    chassis.moveToPoint(27, -46.868, 2000, {.forwards = false});
    for (int i = 0; i < 4; i++)
    {
        startOuttaking();
        pros::delay(50);
        startIntaking();
        pros::delay(50);
    }
    chassis.waitUntilDone();
    startScoring();
    pros::delay(1300);
    stopScoring();

    chassis.moveToPoint(56.484, -46.868, 2000);
    chassis.waitUntilDone();
    startIntaking();
    for (int i = 0; i < 4; i++) {
        chassis.moveToPoint(57, -46.868, 450, {.minSpeed = 110});
        chassis.moveToPoint(52, -46.868, 450);
    }
    pros::delay(200);

    chassis.moveToPoint(27, -46.868, 2000, {.forwards = false});
    chassis.waitUntilDone();
    startScoring();
    pros::delay(3000);
    stopScoring();

    // Go to next matchloader and intake 3 blocks
    chassis.moveToPoint(56.484, 46.868, 2000);
    chassis.waitUntilDone();
    // Intake 3 blocks
    startIntaking();
    for (int i = 0; i < 3; i++) {
        chassis.moveToPoint(57, 46.868, 450, {.minSpeed = 110});
        chassis.moveToPoint(52, 46.868, 450);
    }
    pros::delay(200);

    chassis.moveToPoint(27, 46.868, 2000, {.forwards = false});
    for (int i = 0; i < 4; i++)
    {
        startOuttaking();
        pros::delay(50);
        startIntaking();
        pros::delay(50);
    }
    chassis.waitUntilDone();
    startScoring();
    pros::delay(1300);
    stopScoring();

    chassis.moveToPoint(56.484, 46.868, 2000);
    chassis.waitUntilDone();
    startIntaking();
    for (int i = 0; i < 4; i++) {
        chassis.moveToPoint(57, 46.868, 450, {.minSpeed = 110});
        chassis.moveToPoint(52, 46.868, 450);
    }
    pros::delay(200);
}