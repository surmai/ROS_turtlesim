#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

using namespace std;

ros::Publisher velocity_Publisher;

const double PI = 3.14159265359;

void move();
void rotate();

int main(int argc, char **argv)

{
	ros::init(argc, argv, "turtsur1");
    ros::NodeHandle n;
    ros::Rate rate(1); 

    velocity_Publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);

    for (int i = 0; i<10 && ros::ok(); i++)
    {
        rate.sleep();

        if (i%2==0)
        {
            move();
        }
       else {
            rotate();
        }
}
    return 0;
}

void move()
{
geometry_msgs::Twist vel_msg;

 vel_msg.linear.x =3.00;
 vel_msg.linear.y =0;
 vel_msg.linear.z =0;

 vel_msg.angular.x = 0;
 vel_msg.angular.y = 0;
 vel_msg.angular.z = 0;

    velocity_Publisher.publish(vel_msg);
}
void rotate()

{
    geometry_msgs::Twist vel_msg;
 vel_msg.linear.x =0;
 vel_msg.linear.y =0;
 vel_msg.linear.z =0;

 vel_msg.angular.x = 0;
 vel_msg.angular.y = 0;
 vel_msg.angular.z = (double)(72*PI/180);
 velocity_Publisher.publish(vel_msg);
}
