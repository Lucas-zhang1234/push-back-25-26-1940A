#include "robot.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/optical.hpp"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Controller partner(pros::E_CONTROLLER_PARTNER);

pros::MotorGroup left_mg({-18, -20, -19});    
pros::MotorGroup right_mg({12, 14, 13});

lemlib::Drivetrain drivetrain(&left_mg, &right_mg,
                              11.301, // track width in inches
                              lemlib::Omniwheel::NEW_4, // Wheel configuration
                              400, // RPM
                              2 // Drift was 2  0.5
);

pros::Imu imu(9); 


lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            nullptr, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);


// lateral PID controller
lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              0, // anti windup
                                              0, // small error range, in inches
                                              0, // small error range timeout, in milliseconds
                                              0, // large error range, in inches
                                              0, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(2, // proportional gain (kP)
                                              -1.6, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              1.5, // anti windup
                                              0.1, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              1, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// create the chassis
lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors // odometry sensors
);

pros::Motor Top_Roller(1, pros::v5::MotorGears::green);
pros::Motor Bottom_Roller_Blue(21, pros::v5::MotorGears::blue);
pros::Motor Bottom_Roller_Green(2, pros::v5::MotorGears::green);


pros::adi::Pneumatics Double_Park({22, 'g'}, true);            // Starts retracted, extends when the ADI port is high
pros::adi::Pneumatics Matchloader({22, 'h'}, false);
pros::adi::Pneumatics ODOM_Lift({22, 'e'},false);
