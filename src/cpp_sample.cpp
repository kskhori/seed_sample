#include <ros/ros.h>
#include <stdio.h>
#include "seed_smartactuator_sdk/seed3_command.h"
#include <std_msgs/Float32.h>

class Controller{
public:
  Controller(ros::NodeHandle _nh, int _id, std::string _usb);
  ~Controller();
  void onServo(bool _on);
  void setPos(int _time, int _pos);
  void chatterCallback(const std_msgs::Float32::ConstPtr& msg);

private:
  ros::NodeHandle nh_;
  ros::Subscriber sub_;
  seed::controller::SeedCommand *seed_;
  int id_;
};

Controller::Controller(ros::NodeHandle _nh,int _id, std::string _usb)
  :  nh_(_nh),id_(_id)
{
  sub_ = nh_.subscribe("displacement", 1000, &Controller::chatterCallback,this);

  seed_ = new seed::controller::SeedCommand;
  seed_->openPort(_usb,115200);
  seed_->openCom();

  // 原点復帰を実行する
  seed_->runScript(id_,1);
}

Controller::~Controller()
{
  seed_->closeCom();
  seed_->closePort();
}

void Controller::onServo(bool _on)
{
  seed_->onServo(id_,_on);
}

void Controller::setPos(int _time, int _pos)
{
  seed_->actuateContinuousAbsolutePosition(id_,_time,_pos);
}

void Controller::chatterCallback(const std_msgs::Float32::ConstPtr& msg)
{
  std::array<int,3> motor_state;
  int desired_pos = int(msg->data);   //[pulse]
  int desired_time = 1000;  //[msec]

  setPos(desired_time, desired_pos);

  motor_state = seed_->getPosition(id_);

  ROS_INFO("I heard: [%f],%d\n", msg->data,motor_state[2]);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "cpp_sample_node2");
  ros::NodeHandle nh;

  int id=1;
  std::string usb="/dev/ttyACM0";

  Controller ctrl(nh,id,usb);

  ros::spin();

  return 0;
}
