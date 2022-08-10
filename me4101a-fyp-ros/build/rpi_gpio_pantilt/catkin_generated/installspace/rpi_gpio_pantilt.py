#!/usr/bin/env python3

import rospy
import RPi.GPIO as GPIO
from RpiMotorLib import RpiMotorLib
from std_msgs.msgs import Float32MultiArray
#from geometry_msgs.msgs import Twist

#import key_val preset values
go_up = (0.8, 0)
go_down = (-0.5, 0)
go_left = (0, 1)
go_right = (0, -1)

#define GPIO pins
v_micro = (14,15,18) # (MS1,MS2,MS3)
v_step = 23
v_dir = 24

h_micro = (25,8,7) # (MS1,MS2,MS3)
h_step = 16
h_dir = 20

#define parameters
step_type = "Full"  # Full, Half, 1/4, 1/8, 1/16
step_num = 1        # number of steps, 200 for one revolution in Full steps.
step_delay = 0.05   # wait time (in sec) between steps.
ver_bose = False
init_delay = 0.05   # initial delay (in sec) between initialization and movement.

#declare named instance of class pass GPIO pins numbers
v_motor = RpiMotorLib.A4988Nema(v_dir, v_step, v_micro, "A4988")
h_motor = RpiMotorLib.A4988Nema(h_dir, h_step, h_micro, "A4988")

#call function and arguments
#v_motor.motor_go(clockwise=False, step_type, step_num, step_delay, ver_bose, init_delay)

def rotate_up():
    h_motor.motor_go(False, step_type, step_num, step_delay, ver_bose, init_delay)
    print("rotating up...")
    
def rotate_down():
    h_motor.motor_go(True, step_type, step_num, step_delay, ver_bose, init_delay)
    print("rotating down...")
    
def rotate_left():
    v_motor.motor_go(False, step_type, step_num, step_delay, ver_bose, init_delay)
    print("rotating left...")

def rotate_right():
    v_motor.motor_go(True, step_type, step_num, step_delay, ver_bose, init_delay)
    print("rotating right...")

def go_where(key_val):
    if key_val == go_up:
        rotate_up()
    elif key_val == go_down:
        rotate_down()
    elif key_val == go_left:
        rotate_left()
    elif key_val == go_right:
        rotate_right()

    GPIO.cleanup()

if __name__ == '__main__':
    rospy.init_node('rpi_gpio_pantilt')
    rospy.Subscriber("key_val", Float32MultiArray, go_where)
    rospy.spin()
    
GPIO.cleanup()
