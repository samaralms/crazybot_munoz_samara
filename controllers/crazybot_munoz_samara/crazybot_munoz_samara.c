/*
 * File:          crazybot_munoz_samara.c
 * Date:
 * Description:
 * Author:
 * Modifications:
 */

/*
 * You may need to add include files like <webots/distance_sensor.h> or
 * <webots/differential_wheels.h>, etc.
 */ ///LIBRERRIAS
#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/position_sensor.h>
//#include <webots/distance_sensor.h>
#include <webots/keyboard.h>

///LIBRERIA STANDARDS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * You may want to add macros here.
 */
#define TIME_STEP 64
double b=0;
double e=0;
double a,c,d,f;
double Fin_Lin_Vel;

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char **argv)
{
  /* necessary to initialize webots stuff */
  wb_robot_init();
  wb_keyboard_enable(TIME_STEP);

  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */
 
   
  //esta importando
   WbDeviceTag wheel_left = wb_robot_get_device("motor_left");
   WbDeviceTag wheel_right = wb_robot_get_device("motor_right");
   //WbDeviceTag distance_sensor = wb_robot_get_device("distance_s");
   WbDeviceTag right_pos = wb_robot_get_device("position_right");
   WbDeviceTag left_pos = wb_robot_get_device("position_left"); 
   
   wb_position_sensor_enable(right_pos,TIME_STEP);
   wb_position_sensor_enable(left_pos,TIME_STEP);

 
  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */
  while (wb_robot_step(TIME_STEP) != -1) {
     
     
     

 
  
  int key = wb_keyboard_get_key();
  
  wb_position_sensor_get_value(left_pos);
  wb_position_sensor_get_value(right_pos);
  
  
  a = wb_position_sensor_get_value(left_pos);
  c = a-b ;
  b = a;
  
  d = wb_position_sensor_get_value(right_pos);
  f = d-e ;
  e = d;
  
  
  if(key==WB_KEYBOARD_UP){
  
    wb_motor_set_position(wheel_left, INFINITY);
    wb_motor_set_velocity(wheel_left, -40);
    wb_motor_set_position(wheel_right, INFINITY); 
    wb_motor_set_velocity(wheel_right, -40); 
    }
    
     if(key==WB_KEYBOARD_DOWN){
  
     wb_motor_set_position(wheel_left, INFINITY);
     wb_motor_set_velocity(wheel_left, 1.33);
     wb_motor_set_position(wheel_right, INFINITY); 
      wb_motor_set_velocity(wheel_right, 1.33); 
    }
    
    if(key==WB_KEYBOARD_LEFT){
  
     wb_motor_set_position(wheel_left, INFINITY);
     wb_motor_set_velocity(wheel_left, -5);
     wb_motor_set_position(wheel_right, INFINITY); 
     wb_motor_set_velocity(wheel_right, -5); 
    }
    
     if(key==WB_KEYBOARD_RIGHT){
  
     wb_motor_set_position(wheel_left, INFINITY);
     wb_motor_set_velocity(wheel_left, 5);
     wb_motor_set_position(wheel_right, INFINITY); 
     wb_motor_set_velocity(wheel_right, 5); 
    }
    
    
    
    
     printf("Angular Velocity Left: %lf  \n", (c/0.064));
     printf("Linear Velocity Left: %lf  \n", (c/0.064)*0.075);
     printf("Left RPM: %f \n", (c/0.064)*(60/(2*3.1416)));
     
     printf("Angular Velocity Right: %lf  \t", (f/0.064));
     printf("Linear Velocity Right: %lf  \t", (f/0.064)*0.075);
     printf("Right RPM: %f \t", (f/0.064)*(60/(2*3.1416)));
     
      Fin_Lin_Vel= (((c/0.064)*0.075) + (f/0.064)*0.075)/2;
     
     printf("Final Linear Velocity: %lf \t",Fin_Lin_Vel);
     
    
      fflush(stdout);
    
    
     
    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */

    /* Process sensor data here */

    /*
     * Enter here functions to send actuator commands, like:
     * wb_differential_wheels_set_speed(100.0,100.0);
     */
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
