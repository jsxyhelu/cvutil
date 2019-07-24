/*  Copyright (C) 2018-2019 Noble Research Institute, LLC

File: cvutil_bwskel.h

Author: Anand Seethepalli (aseethepalli@noble.org)
Principal Investigator: Larry York (lmyork@noble.org)
Root Phenomics Lab
Noble Research Institute, LLC

This file is part of Computer Vision UTILity toolkit (cvutil)

cvutil is free software: you can redistribute it and/or modify
it under the terms of the NOBLE RESEARCH INSTITUTE, GENERAL PUBLIC LICENSE.

cvutil is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
NOBLE RESEARCH INSTITUTE GENERAL PUBLIC LICENSE for more details.

You should have received a copy of the Noble Research Institute General Public License
along with cvutil.  If not, see <https://github.com/noble-research-institute/cvutil/blob/master/LICENSE>.
*/

#pragma once

#ifndef CVUTIL_BWSKEL_H
#define CVUTIL_BWSKEL_H

#include "stdproto.h"

namespace bwskel_helper
{
    cv::Mat bwskel(cv::Mat inputc, cv::Mat dist);
    void rectify_components(cv::Mat& skeleton, cv::Mat dist, cv::Mat inputc);
}

#endif
