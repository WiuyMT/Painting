// Copyright (c) 2018 Minh Tran, the University of Minnesota.

#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "flashphoto/flashphoto_app.h"
#include "imageio/image_manager.h"
#include "imagetools/convolution_filter_motion_blur.h"
#include "imagetools/image_editor.h"
#include "imagetools/pixel_buffer.h"

using image_tools::ImageEditor;

class FilterToolTest : public ::testing::Test {
  void SetUp() override {
    std::string file = "doraemon.png";
    image_to_modify_.LoadFromFile(file);
  }

 protected:
  ImageEditor image_to_modify_;
  ImageEditor image_sample_;
};

TEST_F(FilterToolTest, BlurFilterTest) {
  image_to_modify_.ApplyBlurFilter(4.0);
  image_tools::PixelBuffer output_buf_ = *(image_to_modify_.pixel_buffer());

  std::string image_test_ = "doraemon-blur-4.png";
  image_sample_.LoadFromFile(image_test_);
  image_tools::PixelBuffer sample_buf_ = *(image_sample_.pixel_buffer());

  EXPECT_TRUE(sample_buf_ == output_buf_);
}

TEST_F(FilterToolTest, SharpenFilterTest) {
  image_to_modify_.ApplySharpenFilter(8.0);
  image_tools::PixelBuffer output_buf_ = *(image_to_modify_.pixel_buffer());

  std::string image_test_ = "doraemon-sharpen-8.png";
  image_sample_.LoadFromFile(image_test_);
  image_tools::PixelBuffer sample_buf_ = *(image_sample_.pixel_buffer());

  EXPECT_TRUE(sample_buf_ == output_buf_);
}

TEST_F(FilterToolTest, EdgeFilterTest) {
  image_to_modify_.ApplyEdgeDetectFilter();
  image_tools::PixelBuffer output_buf_ = *(image_to_modify_.pixel_buffer());

  std::string image_test_ = "doraemon-edge.png";
  image_sample_.LoadFromFile(image_test_);
  image_tools::PixelBuffer sample_buf_ = *(image_sample_.pixel_buffer());

  EXPECT_TRUE(sample_buf_ == output_buf_);
}

TEST_F(FilterToolTest, QuantizeFilterTest) {
  image_to_modify_.ApplyQuantizeFilter(5.0);
  image_tools::PixelBuffer output_buf_ = *(image_to_modify_.pixel_buffer());

  std::string image_test_ = "doraemon-quantize-5.png";
  image_sample_.LoadFromFile(image_test_);
  image_tools::PixelBuffer sample_buf_ = *(image_sample_.pixel_buffer());

  EXPECT_TRUE(sample_buf_ == output_buf_);
}

TEST_F(FilterToolTest, ThresholdFilterTest) {
  image_to_modify_.ApplyThresholdFilter(1.0);
  image_tools::PixelBuffer output_buf_ = *(image_to_modify_.pixel_buffer());

  std::string image_test_ = "doraemon-threshold-1.png";
  image_sample_.LoadFromFile(image_test_);
  image_tools::PixelBuffer sample_buf_ = *(image_sample_.pixel_buffer());

  EXPECT_TRUE(sample_buf_ == output_buf_);
}

TEST_F(FilterToolTest, ChannelRedFilterTest) {
  image_to_modify_.ApplyChannelsFilter(10.0, 1.0, 1.0);
  image_tools::PixelBuffer output_buf_ = *(image_to_modify_.pixel_buffer());

  std::string image_test_ = "doraemon-red-10.png";
  image_sample_.LoadFromFile(image_test_);
  image_tools::PixelBuffer sample_buf_ = *(image_sample_.pixel_buffer());

  EXPECT_TRUE(sample_buf_ == output_buf_);
}

TEST_F(FilterToolTest, ChannelGreenFilterTest) {
  image_to_modify_.ApplyChannelsFilter(1.0, 10.0, 1.0);
  image_tools::PixelBuffer output_buf_ = *(image_to_modify_.pixel_buffer());

  std::string image_test_ = "doraemon-green-10.png";
  image_sample_.LoadFromFile(image_test_);
  image_tools::PixelBuffer sample_buf_ = *(image_sample_.pixel_buffer());

  EXPECT_TRUE(sample_buf_ == output_buf_);
}

TEST_F(FilterToolTest, ChannelBlueFilterTest) {
  image_to_modify_.ApplyChannelsFilter(1.0, 1.0, 10.0);
  image_tools::PixelBuffer output_buf_ = *(image_to_modify_.pixel_buffer());

  std::string image_test_ = "doraemon-blue-10.png";
  image_sample_.LoadFromFile(image_test_);
  image_tools::PixelBuffer sample_buf_ = *(image_sample_.pixel_buffer());

  EXPECT_TRUE(sample_buf_ == output_buf_);
}

TEST_F(FilterToolTest, MotionBlurNSFilterTest) {
  image_to_modify_.ApplyMotionBlurFilter(9.0, image_tools::MBLUR_DIR_N_S);
  image_tools::PixelBuffer output_buf_ = *(image_to_modify_.pixel_buffer());

  std::string image_test_ = "doraemon-mblur-ns-9.png";
  image_sample_.LoadFromFile(image_test_);
  image_tools::PixelBuffer sample_buf_ = *(image_sample_.pixel_buffer());

  EXPECT_TRUE(sample_buf_ == output_buf_);
}

TEST_F(FilterToolTest, MotionBlurEWFilterTest) {
  image_to_modify_.ApplyMotionBlurFilter(9.0, image_tools::MBLUR_DIR_E_W);
  image_tools::PixelBuffer output_buf_ = *(image_to_modify_.pixel_buffer());

  std::string image_test_ = "doraemon-mblur-ew-9.png";
  image_sample_.LoadFromFile(image_test_);
  image_tools::PixelBuffer sample_buf_ = *(image_sample_.pixel_buffer());

  EXPECT_TRUE(sample_buf_ == output_buf_);
}

TEST_F(FilterToolTest, MotionBlurNESWFilterTest) {
  image_to_modify_.ApplyMotionBlurFilter(9.0, image_tools::MBLUR_DIR_NE_SW);
  image_tools::PixelBuffer output_buf_ = *(image_to_modify_.pixel_buffer());

  std::string image_test_ = "doraemon-mblur-nesw-9.png";
  image_sample_.LoadFromFile(image_test_);
  image_tools::PixelBuffer sample_buf_ = *(image_sample_.pixel_buffer());

  EXPECT_TRUE(sample_buf_ == output_buf_);
}

TEST_F(FilterToolTest, MotionBlurNWSEFilterTest) {
  image_to_modify_.ApplyMotionBlurFilter(9.0, image_tools::MBLUR_DIR_NW_SE);
  image_tools::PixelBuffer output_buf_ = *(image_to_modify_.pixel_buffer());

  std::string image_test_ = "doraemon-mblur-nwse-9.png";
  image_sample_.LoadFromFile(image_test_);
  image_tools::PixelBuffer sample_buf_ = *(image_sample_.pixel_buffer());

  EXPECT_TRUE(sample_buf_ == output_buf_);
}

TEST_F(FilterToolTest, BlurToolTest) {
  int x = 1;
  float rad = 8.0;
  image_tools::ColorData black = image_tools::ColorData(0, 0, 0);
  image_to_modify_.StartStroke("Blur", black, rad, x, x);
  while (x < 1000) {
    image_to_modify_.AddToStroke(x, x);
    x++;
  }
  image_to_modify_.EndStroke(x+1, x+1);
  image_tools::PixelBuffer output_buf_ = *(image_to_modify_.pixel_buffer());

  std::string image_test_ = "doraemon-blurtool.png";
  image_sample_.LoadFromFile(image_test_);
  image_tools::PixelBuffer sample_buf_ = *(image_sample_.pixel_buffer());

  EXPECT_TRUE(sample_buf_ == output_buf_);
}

TEST_F(FilterToolTest, HighlighterToolTest) {
  int x = 1;
  float rad = 8.0;
  image_tools::ColorData black = image_tools::ColorData(0, 0, 0);
  image_to_modify_.StartStroke("Highlighter", black, rad, x, x);
  while (x < 1000) {
    image_to_modify_.AddToStroke(x, x);
    x++;
  }
  image_to_modify_.EndStroke(x+1, x+1);
  image_tools::PixelBuffer output_buf_ = *(image_to_modify_.pixel_buffer());

  std::string image_test_ = "doraemon-highlighter.png";
  image_sample_.LoadFromFile(image_test_);
  image_tools::PixelBuffer sample_buf_ = *(image_sample_.pixel_buffer());

  EXPECT_TRUE(sample_buf_ == output_buf_);
}

TEST_F(FilterToolTest, PenToolTest) {
  int x = 1;
  float rad = 8.0;
  image_tools::ColorData black = image_tools::ColorData(0, 0, 0);
  image_to_modify_.StartStroke("Pen", black, rad, x, x);
  while (x < 1000) {
    image_to_modify_.AddToStroke(x, x);
    x++;
  }
  image_to_modify_.EndStroke(x+1, x+1);
  image_tools::PixelBuffer output_buf_ = *(image_to_modify_.pixel_buffer());

  std::string image_test_ = "doraemon-pen.png";
  image_sample_.LoadFromFile(image_test_);
  image_tools::PixelBuffer sample_buf_ = *(image_sample_.pixel_buffer());

  EXPECT_TRUE(sample_buf_ == output_buf_);
}

TEST_F(FilterToolTest, EraserToolTest) {
  int x = 1;
  float rad = 8.0;
  image_tools::ColorData black = image_tools::ColorData(0, 0, 0);
  image_to_modify_.StartStroke("Eraser", black, rad, x, x);
  while (x < 1000) {
    image_to_modify_.AddToStroke(x, x);
    x++;
  }
  image_to_modify_.EndStroke(x+1, x+1);
  image_tools::PixelBuffer output_buf_ = *(image_to_modify_.pixel_buffer());

  std::string image_test_ = "doraemon-eraser.png";
  image_sample_.LoadFromFile(image_test_);
  image_tools::PixelBuffer sample_buf_ = *(image_sample_.pixel_buffer());

  EXPECT_TRUE(sample_buf_ == output_buf_);
}

TEST_F(FilterToolTest, ChalkToolTest) {
  int x = 1;
  float rad = 8.0;
  image_tools::ColorData black = image_tools::ColorData(0, 0, 0);
  image_to_modify_.StartStroke("Chalk", black, rad, x, x);
  while (x < 1000) {
    image_to_modify_.AddToStroke(x, x);
    x++;
  }
  image_to_modify_.EndStroke(x+1, x+1);
  image_tools::PixelBuffer output_buf_ = *(image_to_modify_.pixel_buffer());

  std::string image_test_ = "doraemon-chalk.png";
  image_sample_.LoadFromFile(image_test_);
  image_tools::PixelBuffer sample_buf_ = *(image_sample_.pixel_buffer());

  EXPECT_TRUE(sample_buf_ == output_buf_);
}

TEST_F(FilterToolTest, StampToolTest) {
  int x = 1;
  float rad = 8.0;
  image_tools::ColorData black = image_tools::ColorData(0, 0, 0);
  image_to_modify_.StartStroke("Stamp", black, rad, x, x);
  while (x < 1000) {
    image_to_modify_.AddToStroke(x, x);
    x++;
  }
  image_to_modify_.EndStroke(x+1, x+1);
  image_tools::PixelBuffer output_buf_ = *(image_to_modify_.pixel_buffer());

  std::string image_test_ = "doraemon-stamp.png";
  image_sample_.LoadFromFile(image_test_);
  image_tools::PixelBuffer sample_buf_ = *(image_sample_.pixel_buffer());

  EXPECT_TRUE(sample_buf_ == output_buf_);
}

TEST_F(FilterToolTest, CalligraphyToolTest) {
  int x = 1;
  float rad = 8.0;
  image_tools::ColorData black = image_tools::ColorData(0, 0, 0);
  image_to_modify_.StartStroke("Calligraphy Pen", black, rad, x, x);
  while (x < 1000) {
    image_to_modify_.AddToStroke(x, x);
    x++;
  }
  image_to_modify_.EndStroke(x+1, x+1);
  image_tools::PixelBuffer output_buf_ = *(image_to_modify_.pixel_buffer());

  std::string image_test_ = "doraemon-calligraphy.png";
  image_sample_.LoadFromFile(image_test_);
  image_tools::PixelBuffer sample_buf_ = *(image_sample_.pixel_buffer());

  EXPECT_TRUE(sample_buf_ == output_buf_);
}

TEST_F(FilterToolTest, SprayCanToolTest) {
  int x = 1;
  float rad = 8.0;
  image_tools::ColorData black = image_tools::ColorData(0, 0, 0);
  image_to_modify_.StartStroke("Spray Can", black, rad, x, x);
  while (x < 1000) {
    image_to_modify_.AddToStroke(x, x);
    x++;
  }
  image_to_modify_.EndStroke(x+1, x+1);
  image_tools::PixelBuffer output_buf_ = *(image_to_modify_.pixel_buffer());

  std::string image_test_ = "doraemon-spraycan.png";
  image_sample_.LoadFromFile(image_test_);
  image_tools::PixelBuffer sample_buf_ = *(image_sample_.pixel_buffer());

  EXPECT_TRUE(sample_buf_ == output_buf_);
}
