/*  Copyright (C) 2018-2019 Noble Research Institute, LLC

File: cvutil_bwdist.h

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

#ifndef CVUTIL_BWTHIN_H
#define CVUTIL_BWTHIN_H

#include "stdproto.h"

namespace bwdist_helper
{
    cv::Mat bwdist_st_no_avx(cv::Mat inputc);
    cv::Mat bwdist_st_avx(cv::Mat inputc);
    cv::Mat bwdist_mt(cv::Mat inputc);
}

#endif

