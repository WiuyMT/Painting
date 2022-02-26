// <Copyright> Minh Tran 2018 CSCI3081W

#include "mia/command_line_processor.h"

#include <string>
#include <iostream>
#include <map>
#include "imagetools/image_editor.h"
#include "mia/image_editor_commands.h"

namespace image_tools {

CommandLineProcessor::CommandLineProcessor() {
  PixelBuffer *buf = new PixelBuffer(1280.0, 720.0, ColorData(1.0, 1.0, 1.0));
  image_editor_.set_pixel_buffer(buf);
}
CommandLineProcessor::~CommandLineProcessor() {}

const std::map<MBlurDir, std::string>
  CommandLineProcessor::mblur_dir_names_ = {
    {MBLUR_DIR_N_S,   "North/South"},
    {MBLUR_DIR_E_W,   "East/West"},
    {MBLUR_DIR_NE_SW, "Northeast/Southwest"},
    {MBLUR_DIR_NW_SE, "Northwest/Southeast"}
};

int CommandLineProcessor::ProcessCommandLine(int argc, char* argv[]) {
  if (argc < 3 || strcmp(argv[1], "-h") == 0) {
    HelpMessage();
    return 1;
  }

  if (argc == 3) {
    if (mingfx::Platform::FileExists(argv[1])) {
      cmd_.push_back(new LoadCommand(&image_editor_, argv[1]));
      cmd_[0]->Execute();
      std::string out = argv[argc-1];
      if (out.find(".png") == std::string::npos) {
        HelpMessage();
        return 1;
      } else {
        cmd_.push_back(new SaveCommand(&image_editor_, argv[2]));
        cmd_[1]->Execute();
      }
    } else {
      HelpMessage();
      return 1;
    }
    cmd_.clear();
  }

  if (argc > 3) {
    if (mingfx::Platform::FileExists(argv[1])) {
      cmd_.push_back(new LoadCommand(&image_editor_, argv[1]));
      for (int i=2; i < argc - 1 ; i++) {
        if (strcmp("-blur", argv[i]) == 0) {
          cmd_.push_back(new BlurFilterCommand(&image_editor_,
                                               atof(argv[++i])));
        } else if (strcmp("-edgedetect", argv[i]) == 0) {
          cmd_.push_back(new EdgeFilterCommand(&image_editor_));
        } else if (strcmp("-sharpen", argv[i]) == 0) {
          cmd_.push_back(new SharpenFilterCommand(&image_editor_,
                                                  atof(argv[++i])));
        } else if (strcmp("-quantize", argv[i]) == 0) {
          cmd_.push_back(new QuantizeFilterCommand(&image_editor_,
                                                   atof(argv[++i])));
        } else if (strcmp("-saturate", argv[i]) == 0) {
          cmd_.push_back(new SaturateFilterCommand(&image_editor_,
                                                   atof(argv[++i])));
        } else if (strcmp("-threshold", argv[i]) == 0) {
          cmd_.push_back(new ThresholdFilterCommand(&image_editor_,
                                                    atof(argv[++i])));
        } else if (strcmp("-red", argv[i]) == 0) {
          cmd_.push_back(new ChannelsFilterCommand(&image_editor_,
                          atof(argv[++i]), 1.0, 1.0));
        } else if (strcmp("-green", argv[i]) == 0) {
          cmd_.push_back(new ChannelsFilterCommand(&image_editor_,
                          1.0, atof(argv[++i]), 1.0));
        } else if (strcmp("-blue", argv[i]) == 0) {
          cmd_.push_back(new ChannelsFilterCommand(&image_editor_,
                          1.0, 1.0, atof(argv[++i])));
        } else if (strcmp("-motionblur-n-s", argv[i]) == 0) {
          cmd_.push_back(new MotionBlurFilterCommand(&image_editor_,
                         atof(argv[++i]), MBLUR_DIR_N_S));
        } else if (strcmp("-motionblur-e-w", argv[i]) == 0) {
          cmd_.push_back(new MotionBlurFilterCommand(&image_editor_,
                         atof(argv[++i]), MBLUR_DIR_E_W));
        } else if (strcmp("-motionblur-ne-sw", argv[i]) == 0) {
          cmd_.push_back(new MotionBlurFilterCommand(&image_editor_,
                         atof(argv[++i]), MBLUR_DIR_NE_SW));
        } else if (strcmp("-motionblur-nw-se", argv[i]) == 0) {
          cmd_.push_back(new MotionBlurFilterCommand(&image_editor_,
                         atof(argv[++i]), MBLUR_DIR_NW_SE));
        } else {
          HelpMessage();
          return 1;
        }
      }
      cmd_.push_back(new SaveCommand(&image_editor_, argv[argc-1]));
      std::string out = argv[argc-1];
      if (out.find(".png") == std::string::npos) {
        HelpMessage();
        return 1;
      }
      for (unsigned i = 0; i < cmd_.size(); i++) {
        cmd_[i]->Execute();
      }
    cmd_.clear();
    }
  }
  return 0;
}

void CommandLineProcessor::HelpMessage() {
  std::cout << "Usage: mia infile.png <image processing commands> outfile.png"
            << std::endl;
  std::cout << "infile.png:          input image file in png format"
           << std::endl;
  std::cout << "outfile.png:         filename to use for saving the result"
           << std::endl;
  std::cout << "\n";
  std::cout << "Image processing commands:" << std::endl;
  std::cout << "-blur r:             apply a gaussian blur of radius r"
           << std::endl;
  std::cout << "-edgedetect:         apply an edge detection filter"
           << std::endl;
  std::cout << "-sharpen r:          apply a sharpening filter of radius r"
           << std::endl;
  std::cout << "-red s:              scale the red channel by factor r"
           << std::endl;
  std::cout << "-green s:            scale the green channel by factor r"
           << std::endl;
  std::cout << "-blue s:             scale the blue channel by factor r"
           << std::endl;
  std::cout << "-quantize n:         quantize each color channel into n bins"
           << std::endl;
  std::cout << "-saturate s:         saturate colors by scale factor s"
            << std::endl;
  std::cout << "-threshold c:        threshold using cutoff value c"
           << std::endl;
  std::cout << "-motionblur-n-s r:   north-south motion blur with" <<
               "kernel radius r" << std::endl;
  std::cout << "-motionblur-e-w r:   east-west motion blur with" <<
               "kernel radius r" << std::endl;
  std::cout << "-motionblur-ne-sw r: northeast-southwest motion blur" <<
               "with kernel radius r" << std::endl;
  std::cout << "-motionblur-nw-se r:   northwest-southeast motion blur" <<
               "with kernel radius r" << std::endl;
}

/* The following is for creating images with Toolis

  void CommandLineProcessor::ToolDraw() {
  std::string file = <"in.png">;
  image_editor_.LoadFromFile(file);
  int x = 1;
  float rad = 8.0;
  ColorData black = ColorData(0,0,0);
  image_editor_.StartStroke(<"nameoftool">, black, rad, x, x);
  while (x<1000) {
    image_editor_.AddToStroke(x,x);
    x++;
  }
  image_editor_.EndStroke(x+1, x+1);
  std::string output = <"out.png">;
  image_editor_.SaveToFile(output); 
} */

}  // namespace image_tools
