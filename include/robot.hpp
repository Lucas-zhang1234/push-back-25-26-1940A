#include "../include/main.h"
#include "lemlib/api.hpp"

extern pros::Controller master;
extern pros::Controller partner;

extern pros::MotorGroup left_mg;    
extern pros::MotorGroup right_mg;

extern lemlib::Drivetrain drivetrain;

extern pros::Imu imu;

extern pros::Rotation horizontalRotation;
extern pros::Rotation verticallRotation;

extern lemlib::TrackingWheel horizontalTrackingWheel;

extern lemlib::TrackingWheel verticalTrackingWheel;

extern lemlib::OdomSensors sensors;

extern lemlib::ControllerSettings lateral_controller;

extern lemlib::ControllerSettings angular_controller;

extern lemlib::Chassis chassis;

extern pros::Motor Top_Roller;
extern pros::Motor Bottom_Roller_Blue;
extern pros::Motor Bottom_Roller_Green;

extern pros::adi::Pneumatics Double_Park;
extern pros::adi::Pneumatics Matchloader;
extern pros::adi::Pneumatics ODOM_Lift;