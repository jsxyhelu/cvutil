/*  Copyright (C) 2018-2019 Noble Research Institute, LLC

File: profiler.h

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

#ifndef PROFILER_H
#define PROFILER_H

#include "cvutil.h"

//using namespace std;

namespace cvutil
{
    CVUTILAPI void tic();
    CVUTILAPI void toc();
    CVUTILAPI void toc(std::string message, int line = -1);
    CVUTILAPI void toc(double& timeelapsed);
}

#endif
