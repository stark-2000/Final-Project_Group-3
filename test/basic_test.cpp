/*  MIT License

    Copyright (c) 2022 Dhinesh Rajasekaran

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to
    deal in the Software without restriction, including without limitation the
    rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
    sell copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

/**
 * @copyright (c) 2022 Dhinesh Rajasekaran
 * @file basic_test.cpp
 * @author Dhinesh Rajasekaran (dhinesh@umd.edu)
 * @brief Using "gtest" to create level 2 integration test - Test if a simple task plan works
 * string
 * @version 1.0
 * @date 2022-11-15
 *
 */

#include <rclcpp/rclcpp.hpp>
#include <gtest/gtest.h>
#include <stdlib.h>
#include <std_msgs/msg/string.hpp>

class TaskPlanningFixture : public testing::Test {
 public:
  TaskPlanningFixture()
      : node_(std::make_shared<rclcpp::Node>("basic_test"))
  {
    RCLCPP_INFO_STREAM(node_->get_logger(), "DONE WITH CONSTRUCTOR!!");
  }

  void SetUp() override {
    // Setup things that should occur before every test instance should go here

    /*
     * Define any ros2 package and exectuable you want to test
     * Example: package name = cpp_pubsub, node name = minimal_publisher, executable = talker
     */
    bool retVal = StartROSExec ("beginner_tutorials", "minimal_publisher", "talker");
    ASSERT_TRUE(retVal);

    RCLCPP_INFO_STREAM(node_->get_logger(), "DONE WITH SETUP!!");
  }

  void TearDown() override {
    // Tear things that should occur after every test instance should go here

    // Stop the running ros2 node, if any.
    bool retVal = StopROSExec ();
    ASSERT_TRUE(retVal);

    std::cout << "DONE WITH TEARDOWN" << std::endl;
  }

 protected:
  rclcpp::Node::SharedPtr node_;
  std::stringstream cmd_ss, cmdInfo_ss, killCmd_ss;

  bool StartROSExec (const char* pkg_name,
                     const char* node_name,
                     const char* exec_name)
  {
    cmd_ss << "ros2 run " << pkg_name << " " << exec_name << " > /dev/null 2> /dev/null &";
    cmdInfo_ss << "ros2 node info " << "/" << node_name << " > /dev/null 2> /dev/null";
    killCmd_ss << "pkill --signal SIGINT " << exec_name << " > /dev/null 2> /dev/null";

    // First kill the ros2 node, in case it's still running.
    StopROSExec();
    
    // Start a ros2 node and wait for it to get ready:
    int retVal =  system (cmd_ss.str().c_str());
    if (retVal != 0)
      return false;
    
    retVal = -1;
    while (retVal != 0) {
      retVal = system (cmdInfo_ss.str().c_str());
      sleep (1);
    }
    return true;
  }

  bool StopROSExec ()
  {
    if (killCmd_ss.str().empty())
      return true;
    
    int retVal =  system (killCmd_ss.str().c_str());
    return retVal == 0;
  }
  
};

TEST_F(TaskPlanningFixture, TrueIsTrueTest) {
  std::cout << "TEST BEGINNING!!" << std::endl;
  EXPECT_TRUE(true);

  /*
   * Subscribe to the topic 
   */
  using std_msgs::msg::String;
  using SUBSCRIBER = rclcpp::Subscription<String>::SharedPtr;
  bool hasData = false;
  SUBSCRIBER subscription = node_->create_subscription<String>
    ("/swarm_sim/two_wheel_robot", 10,
     // Lambda expression begins
     [&](const std_msgs::msg::String& msg) {
       RCLCPP_INFO(node_->get_logger(), "I heard: '%s'", msg.data.c_str());
       hasData = true;
     } // end of lambda expression
     );

  /*
   * Check to see if we get data within 3 sec
   */
  using timer = std::chrono::system_clock;
  using namespace std::chrono_literals;
  timer::time_point clock_start;
  timer::duration elapsed_time;
  clock_start = timer::now();
  elapsed_time = timer::now() - clock_start;
  rclcpp::Rate rate(2.0);    // 2hz checks
  while (elapsed_time < 3s)
    {
      rclcpp::spin_some(node_);
      rate.sleep();
      elapsed_time = timer::now() - clock_start;
    }
  EXPECT_TRUE (hasData);
}

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  ::testing::InitGoogleTest(&argc, argv);
  int result = RUN_ALL_TESTS();
  rclcpp::shutdown();
  std::cout << "DONE SHUTTING DOWN ROS" << std::endl;
  return result;
}