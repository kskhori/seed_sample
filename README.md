# seed_sample

This program is borrowed by Mr. Shiigi from THK CO., LTD.
Mainly, ROS program of this linear actuator is written by him. So that,
if you have any problem about linear actuator, please contact him(https://github.com/y-shiigi).


## Usage



```
sudo chmod 666 /dev/ttyACM0
rosrun seed_sample run_script.py
```


or
```
rosrun seed_sample cpp_sample_node2
```


## More information

In cpp_sample_node2, subscribed/published topic is down below.
--------------------------------------------------------------------------------
Node [/cpp_sample_node2]

Publications:
 * /rosout [rosgraph_msgs/Log]
 * /slider_position [std_msgs/Float32] : Desired actuation position[m]

Subscriptions:
 * /displacement [std_msgs/Int32] : Desired actuation position[pulse]

## Add your files

existing Git repository with the following command:

```
cd existing_repo
git remote add origin https://gitlab.cds.tohoku.ac.jp/horippy/seed_sample.git
git branch -M main
git push -uf origin main
```
