# seed_sample

This program is borrowed by Mr. Shiigi from THK CO., LTD.
Mainly, ROS program of this linear actuator is written by him. So that,
if you have any problem about linear actuator, please contact him(https://github.com/y-shiigi).

## Requirements

- seed command library
```
sudo apt-get install ros-kinetic-seed-smartactuator-sdk
```
ros-kinetic~ is example. please adjust ros version of your environment.
After installation, make the codes by catkin_make.


## Usage

```
sudo chmod 666 /dev/ttyACM0
rosrun seed_sample run_script.py
```
And in an another terminal, run script.
arg. 1 : Driver ID set by SEED Editor. (0:All axes , 1,2,3, ...: each axis)
Example below shows ID 1, script 1 (Zelo calib.).
```
rosservice call /run_script 1 1
```

or
```
rosrun seed_sample cpp_sample_node2
```


## More information

In run_script_node, subscribed/published topic is down below.
--------------------------------------------------------------------------------
Node [/run_script_node]
Publications: 
 * /rosout [rosgraph_msgs/Log]

Subscriptions: None

Services: 
 * /run_script


In cpp_sample_node2, subscribed/published topic is down below.
--------------------------------------------------------------------------------
Node [/cpp_sample_node2]

Publications:
 * /rosout [rosgraph_msgs/Log]
 * /slider_position [std_msgs/Float32] : Desired actuation position[m]

Subscriptions:
 * /displacement [std_msgs/Int32] : Desired actuation position[pulse]


## Notice

- Port is automatially open when you run run_script.py. Error is occur if power is nos supplied. please turn it on in advance.
- Communication module is recognized as /dev/ttyACM*. Another sensors are connected as /dev/ttyACM0, change the port name (written in /seed_sample/scripts/run_script.py)

