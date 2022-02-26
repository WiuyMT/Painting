// Copyright (c) 2018 Minh Tran, the University of Minnesota.

#include <iostream>
#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "flashphoto/flashphoto_app.h"
#include "imageio/image_manager.h"
#include "imagetools/convolution_filter_motion_blur.h"
#include "imagetools/pixel_buffer.h"
#include "mia/image_editor_commands.h"
#include "mia/command_line_processor.h"

using image_tools::ImageEditor;

class CommandLineTest : public ::testing::Test {
  void SetUp() override {
    cmd_ = new image_tools::CommandLineProcessor();
  }
  void TearDown() override {
    delete cmd_;
  }

 protected:
  int result_;
  image_tools::CommandLineProcessor* cmd_;
};

TEST_F(CommandLineTest, ValidSyntax1Test) {
  char* arg[] = {strdup("./build/bin/mia"), strdup("abc")};
  testing::internal::CaptureStdout();
  result_ = cmd_->ProcessCommandLine(2, arg);
  testing::internal::GetCapturedStdout();
  EXPECT_TRUE(result_ == 1);
}

TEST_F(CommandLineTest, ValidSyntax2Test) {
  char* arg[] = {strdup("./build/bin/mia"), strdup("-h")};
  testing::internal::CaptureStdout();
  result_ = cmd_->ProcessCommandLine(2, arg);
  testing::internal::GetCapturedStdout();
  EXPECT_TRUE(result_ == 1);
}

TEST_F(CommandLineTest, ValidSyntax3Test) {
  char* arg[] = {strdup("./build/bin/mia"), strdup("input"),
                         strdup("output.png")};
  testing::internal::CaptureStdout();
  result_ = cmd_->ProcessCommandLine(3, arg);
  testing::internal::GetCapturedStdout();
  EXPECT_TRUE(result_ == 1);
}

TEST_F(CommandLineTest, ValidSyntax4Test) {
  char* arg[] = {strdup("./build/bin/mia"), strdup("input.png"),
      strdup("-edgedetect"), strdup("output.png")};
  testing::internal::CaptureStdout();
  result_ = cmd_->ProcessCommandLine(4, arg);
  testing::internal::GetCapturedStdout();
  EXPECT_TRUE(result_ == 0);
}

TEST_F(CommandLineTest, ValidSyntax5Test) {
  char* arg[] = {strdup("./build/bin/mia"), strdup("input.png"),
      strdup("-blur 4"), strdup("-edgedetect"), strdup("output.png")};
  testing::internal::CaptureStdout();
  result_ = cmd_->ProcessCommandLine(5, arg);
  testing::internal::GetCapturedStdout();
  EXPECT_TRUE(result_ == 0);
}



