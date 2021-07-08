# group_surfing_ws
Package for the launch files controlling.

## Requirements
- **turtlesim**
  - `sudo apt-get install ros-$(rosversion -d)-turtlesim`  
    

## Installation
1. Clone this repository  to your workspace
  
	`cd ~/YOUR_WS`  
  
	`git clone git@github.com:YunongPan/control_launch.git`  
  

2. Build the workspace  
  
	`cd ~/YOUR_WS`  
  
	`catkin_make`  

## Testing
1. Source env setting  
  
	`source ~/YOUR_WS/devel/setup.bash`  
  
	`roslaunch control_launch launch_trigger.launch`  
	  

  
2. Open another terminal, source the env and test  
  
	`source ~/YOUR_WS/devel/setup.bash`  
  
	`rosrun control_launch control_launch_client`  
	
3. After starting the node in step 2, a new terminal will be opened and the launch file will be started in the new terminal. After 10 seconds the launch file will be stopped. If you don't want the launch file to be stopped, just delete this part in the file `control_launch_client.cpp`.
   


  
