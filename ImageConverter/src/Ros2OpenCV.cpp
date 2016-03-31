#include "../include/Ros2OpenCV.h"

ImageConverter::ImageConverter()
  : it_(nh_)
{
  //Subscribe to input video feed and publish output video feed
  image_sub_ = it_.subscribe("/camera/rgb/image_mono", 1, &ImageConverter::imageCb, this);
  image_pub_ = it_.advertise("/image_converter/output_video", 1);

  cv::namedWindow(OPENCV_WINDOW);
}


void ImageConverter:imageCb(const sensor_smgs::ImageConstPtr& msg);
{
  cv_bridge::CvImagePtr cv_ptr;
  try
    {
      cv_ptr = cv_bridge::toCvCopy(msg, sensormsgs::image_encodings::"MONO8");
    }
  catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }
}
