/*
 This file is part of the CSCI-3081W Project Support Code, which was developed
 at the University of Minnesota.

 This code is to be used for student coursework.  It is not an open source
 project.
 Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
 Minnesota.

 Original Author(s) of this File:
 Daniel Keefe, 2018, University of Minnesota

 Author(s) of Significant Updates/Modifications to the File:
 ...
 */

#ifndef IMAGETOOLS_MASK_FACTORY_H_
#define IMAGETOOLS_MASK_FACTORY_H_

#include "imagetools/float_matrix.h"

namespace image_tools {

/** @brief This factory is used to create masks used by image editing tools. Some of
 the masks are used by more than one tool. */
class MaskFactory {
 public:
  /** Initialization for constant mask */
  static FloatMatrix* CreateConstantMask(float radius);\

  /** Initialization for oval mask */
  static FloatMatrix* CreateOvalMask(float radius, float angle_in_deg,
                                     float ratio);
  /** Initialization for linear fall-off mask */
  static FloatMatrix* CreateLinearFalloffMask(float radius);
  /** Initialization for bull eye mask */
  static FloatMatrix* CreateBullseyeMask(float radius, float linewidth);
};

}  // namespace image_tools

#endif  // IMAGETOOLS_MASK_FACTORY_H_

