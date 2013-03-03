#ifndef TRAININGEXAMPLE_H
#define TRAININGEXAMPLE_H

#include <eigen3/Eigen/Geometry>

using namespace Eigen;

struct TrainingExample {
    ArrayXf expectedOutput;
    ArrayXf inputs;
};

#endif//TRAININGEXAMPLE_H