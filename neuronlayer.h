#ifndef NEURONLAYER_H
#define NEURONLAYER_H

#include <eigen3/Eigen/Geometry>

using namespace Eigen;

class NeuronLayer
{
public:
    NeuronLayer(int size, int inputSize);
    void setInput(const ArrayXf &inputs);
    const ArrayXf &output();
    ArrayXf previousOutput(const ArrayXf expectedOutputs);

private:
    MatrixXf m_weights;
    ArrayXf m_values;
};

#endif//NEURONLAYER_H