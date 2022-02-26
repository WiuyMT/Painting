// <Copyright> Minh Tran 2018 CSCI 3081W

#ifndef MIA_COMMAND_LINE_PROCESSOR_H_
#define MIA_COMMAND_LINE_PROCESSOR_H_

#include <mingfx.h>
#include <string>
#include <vector>
#include <map>
#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"
#include "mia/image_editor_commands.h"
#include "imagetools/image_editor.h"

namespace image_tools {

/** @brief The base class for processing command lines with two main functions:
ProcessCommandLine(), which checks the valid syntax from stdin; and
HelpMessage(), which prints the information guide of how to use the
command line mode of MIA application. */
class CommandLineProcessor {
 public:
  /** The constructor and destructor for initialization */
  CommandLineProcessor();
  virtual ~CommandLineProcessor();

  /// Valid commandline: 0 for success and 1 for failure
  int ProcessCommandLine(int argc, char* argv[]);
  /// HelpMessage() prints all neccessary guidelines for using
  ///command lines syntax in MIA
  void HelpMessage();
  // void ToolDraw(); -> used for checking tools
 private:
  std::vector<ImageEditorCommand*> cmd_;
  ImageEditor image_editor_;
  static const std::map<MBlurDir, std::string> mblur_dir_names_;
};

}  // namespace image_tools

#endif  // MIA_COMMAND_LINE_PROCESSOR_H_
