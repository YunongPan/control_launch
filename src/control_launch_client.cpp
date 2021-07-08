#include <ros/ros.h>
#include <std_srvs/Trigger.h>
#include <unistd.h>


int main(int argc, char** argv)
{

    ros::init(argc, argv, "control_launch_client");


    ros::NodeHandle node;


    ros::service::waitForService("/start_launch_command");
    ros::ServiceClient start_launch_client = node.serviceClient<std_srvs::Trigger>("/start_launch_command");


    std_srvs::Trigger srv_start;
    srv_start = {};


    start_launch_client.call(srv_start);


    ROS_INFO(".launch file started.");

    int i = 10;
    while (i > 0) 
    {
        sleep(1);
        ROS_INFO("The file will be stopped after %i seconds.", i);
        i--;
    }

    ros::service::waitForService("/stop_launch_command");
    ros::ServiceClient stop_launch_client = node.serviceClient<std_srvs::Trigger>("/stop_launch_command");


    std_srvs::Trigger srv_stop;
    srv_stop = {};


    stop_launch_client.call(srv_stop);


    ROS_INFO(".launch file stopped.");


    return 0;
};
