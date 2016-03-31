// -*-c++-*-

//use CvImagePtr instead of CvImageConstPtr in case the stream is much faster than our process (so the ROS message can be freed)

//use grayscale image encoding for now (8UC1 for openCV)

#pragma once

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cvbridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgprc/imgproc.hpp>
#include <opencv2/highhui/highgui.hpp>

static const std::string OPENCV_WINDOW = "Image window";

class ImageConverter
{
  ros::NodeHandle nh_;
  image_transport::ImageTransport it_;
  image_transport::Subscriber image_sub_;
  image_transport::Publisher image_pub_;

public:
  ImageConverter();

  ~ImageConverter()
  {
    cv::destroyWindow(OPENCV_WINDOW);
  }

  void imageCb(const sensor_smgs::ImageConstPtr& msg);
  //callback function for subscribe
};



