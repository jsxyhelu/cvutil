/*  Copyright (C) 2018-2019 Noble Research Institute, LLC

File: cvutil_figure.h

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

#ifndef CVUTIL_FIGURE_H
#define CVUTIL_FIGURE_H

#include "cvutil.h"

#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtWidgets/QGridLayout>

QT_CHARTS_USE_NAMESPACE;

using namespace cvutil;

namespace cvutil
{
    class figure_impl : public QMainWindow, public figure
    {
        static int figure_number;
        static int default_precision;

        int figno;
        int precision;
        bool holding;

        // UI controls
        
        enum class ViewTypes { ChartView, ImageView };

        // Stuff for charts
        QWidget *widget;
        QGridLayout *baseLayout;
        std::vector<QGraphicsView *> views;
        std::vector<ViewTypes> viewtypes;
        std::vector<QAbstractSeries *> serieslist;
        std::vector<QChart *> charts;
        std::vector<QImage *> images;
        std::vector<cv::Mat> cvimages;
        std::vector<double> xratio, yratio;

        // Mouse operating modes
        enum class MouseModes { Pointer, Pan, Zoom, Callout };
        MouseModes mode;

        // Current subplot size
        bool subplotenabled;
        int nrows;
        int ncols;
        int nsubplots, nsubplot;
        
        // To save chart(s) to image files
        QString saveFilename;

        // Bar plot data
        void barplot(cv::Mat x, std::vector<std::string> categories, cv::Mat y, std::vector<std::string> groups = std::vector<std::string>());
        
        void imshowplot(QImage &img);

        // To make window for plotting. Also creates basic signals & slots 
        // for common tasks.
        void makewindow();

        // Get ranges of y-values to be fit properly in a chart.
        std::pair<QVariant, QVariant> getRange(cv::Mat vals);

        // Save file from Save File Dialog
        bool saveFile(const QString &fileName);

        void adjustticks(QChart* chart, int idx);
    // Although the concept of "slots" is non-standard in C++ language
    // and is unnecessary when compiling code without using Qt make tools,
    // we can use this marker to signify that the functions declared in this 
    // section are for event handling.
    private slots:
        bool save();
        bool saveAs();

    protected:
        void resizeEvent(QResizeEvent* event);

    public:
        figure_impl();
        figure_impl(int n);
        ~figure_impl();

        // Configure how the plot should look before calling plotting
        // functions.
        void setprecision(int p);


        // Plotting functions
        void bar(cv::InputArray x, cv::InputArray y = cv::noArray(), std::vector<std::string> groups = std::vector<std::string>());
        void bar(std::vector<std::string> &x, cv::InputArray y, std::vector<std::string> groups = std::vector<std::string>());

        void scatter(cv::InputArray x, cv::InputArray y = cv::noArray(), std::vector<std::string> groups = std::vector<std::string>());
        
        void subplot(int rows, int cols, int nplot);

        // Display image
        void imshow(cv::Mat &img);

        // Titles and labels
        void title(std::string txt);
        void xlabel(std::string lab);
        void ylabel(std::string lab);
        void showgrid(bool on);
        // User event handler
        //virtual bool event(QEvent *ev);
        
        void wait();

        void release();
    };
}

#endif
