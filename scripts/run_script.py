#!/usr/bin/env python
# -*- coding: utf-8 -*-
import rospy
from seed_sample.srv import *
from seed_smartactuator_sdk.seed3_command import SeedCommand

class RunScriptServer:
  def __init__(self):
    rospy.init_node("run_script_node")
    self.seed=SeedCommand()

    self.seed.open_port("/dev/ttyACM0",115200)
    self.seed.open_com()

    self.server = rospy.Service('run_script', RunScript, self.callback)

  def main(self):
    rospy.spin()

  def callback(self,req):
    rospy.loginfo("run script, ID: %d, No.: %d" % (req.can_id, req.script_number))

    self.seed.run_script(req.can_id,req.script_number)
    return RunScriptResponse('succeeded')

if __name__ == '__main__':
  server = RunScriptServer()

  try:
    server.main()
  except rospy.ROSInterruptException: pass
