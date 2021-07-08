#include <ros/ros.h>
#include <std_srvs/Trigger.h>


bool startCommand = false;
bool startCallback(std_srvs::Trigger::Request  &req,
         	     std_srvs::Trigger::Response &res)
{
    startCommand = !startCommand;
    res.success = true;
    res.message = " .launch file has been started.";

    if(startCommand)
    {
        startCommand = !startCommand;
        ROS_INFO("Start .launch file.");
        system("gnome-terminal -e 'sh -c \"roslaunch control_launch turlesim.launch\"'");
    }

    return true;
}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "start_launch_server");
    ros::NodeHandle n;
    ros::ServiceServer start_service = n.advertiseService("/start_launch_command", startCallback);
    ROS_INFO("Ready to start .launch file.");

    ros::spin();

    return 0;
}
