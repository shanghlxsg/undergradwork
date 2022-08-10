#!/usr/bin/env python3

import rospy
import RPi.GPIO as GPIO
import std_msgs.msg
from time import sleep
from geometry_msgs.msg import Twist

#import key_vel preset values
go_up = 0.8     #msg.linear.x
go_down = -0.5  #msg.linear.x
go_left = 1     #msg.angular.z
go_right = -1   #msg.angular.z

#define GPIO pins
#define step resolution
micro_step = 'Full'     # 'Full', '1/2', '1/4', '1/8', '1/16'

step_res = { 'Full': (0,0,0),
             '1/2': (1,0,0),
             '1/4': (0,1,0),
             '1/8': (1,1,0),
             '1/16': (1,1,1)}

#vertical axis A4988 controller, RPi pins
v_micro = (14,15,18) # [MS1,MS2,MS3]
v_step = 23
v_dir = 24
v_ctrl = (v_step, v_dir)

#horizontal axis A4988 controller, RPi pins
h_micro = (25,8,7) # [MS1,MS2,MS3]
h_step = 16
h_dir = 20
h_ctrl = (h_step, h_dir)

#define direction parameters
#0 = counterclockwise, 1 = clockwise.
dir_up = 0
dir_down = 1
dir_left = 0
dir_right = 1

#GPIO initialization
GPIO.setmode(GPIO.BCM)

GPIO.setup(v_micro, GPIO.OUT)
GPIO.setup(v_ctrl, GPIO.OUT)
GPIO.output(v_micro, step_res[micro_step])  #set step resolution

GPIO.setup(h_micro, GPIO.OUT)
GPIO.setup(h_ctrl, GPIO.OUT)
GPIO.output(h_micro, step_res[micro_step])  #set step resolution

#define time delay parameters
t_setup = 200/(10**9)   #200ns
t_step = 1/(10**6)      #1us

def rotate_up():
    print(micro_step,"step up.")
    GPIO.output(h_dir, dir_up)      #set direction
    sleep(t_setup)                  #setup time
    
    GPIO.output(h_step, 1)      #step HIGH pulse width
    sleep(t_step)
    
    GPIO.output(h_step, 0)      #step LOW pulse width
    
def rotate_down():
    print(micro_step,"step down.")
    GPIO.output(h_dir, dir_down)    #set direction
    sleep(t_setup)                  #setup time
    
    GPIO.output(h_step, 1)      #step HIGH pulse width
    sleep(t_step)
    
    GPIO.output(h_step, 0)      #step LOW pulse width
    
def rotate_left():
    print(micro_step,"step left.")
    GPIO.output(v_dir, dir_left)    #set direction
    sleep(t_setup)                  #setup time
    
    GPIO.output(v_step, 1)      #step HIGH pulse width
    sleep(t_step)
    
    GPIO.output(v_step, 0)      #step LOW pulse width

def rotate_right():
    print(micro_step,"step right.")    
    GPIO.output(v_dir, dir_right)   #set direction
    sleep(t_setup)                  #setup time
    
    GPIO.output(v_step, 1)      #step HIGH pulse width
    sleep(t_step)
    
    GPIO.output(v_step, 0)      #step LOW pulse width

def next_step(msg):
    if msg.linear.x == go_up:
        rotate_up()
    elif msg.linear.x == go_down:
        rotate_down()
    elif msg.angular.z == go_left:
        rotate_left()
    elif msg.angular.z == go_right:
        rotate_right()

if __name__ == '__main__':
    rospy.init_node('rpi_gpio_pantilt')
    print("Ready.")
    sub = rospy.Subscriber("key_vel", Twist, next_step)
    rospy.spin()
    
GPIO.cleanup()
