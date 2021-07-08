#include <ros/ros.h>
#include <std_srvs/Trigger.h>


bool stopCommand = false;
bool stopCallback(std_srvs::Trigger::Request  &req,
         	     std_srvs::Trigger::Response &res)
{
    stopCommand = !stopCommand;
    res.success = true;
    res.message = " .launch file has been killed.";

    if(stopCommand)
    {
        stopCommand = !stopCommand;
        ROS_INFO("Stop .launch file.");
        system("pkill roslaunch"); // All .launch files will be killed together with this method

//        If you just need to kill some nodes, please uncomment the following and modify the node name. (There may be a better way...)

//        system("rosnode kill turtlesim_node_1"); 
//        system("rosnode kill turtlesim_node_2");
//        system("rosnode kill ... ");
    }
    return true;
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "stop_launch_server");
    ros::NodeHandle n;
    ros::ServiceServer stop_service = n.advertiseService("/stop_launch_command", stopCallback);
    ROS_INFO("Ready to stop .launch file.");

    ros::spin();

    return 0;
}

