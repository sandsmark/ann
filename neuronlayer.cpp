#include "neuronlayer.h"
#include <QDebug>

NeuronLayer::NeuronLayer(int size, int inputSize) :
    m_weights(size, inputSize),
    m_values(size)
{
    qDebug() << "initializing layer";
    m_values.setZero();
    m_weights.setRandom();
}

void NeuronLayer::setInput(const ArrayXf& inputs)
{
    m_values = (m_weights * inputs.matrix() * -1);
    m_values = (m_values.exp() + 1).inverse();
}

const ArrayXf& NeuronLayer::output()
{
    return m_values;
}

ArrayXf NeuronLayer::previousOutput(const ArrayXf expectedOutput)
{
    ArrayXf delta = expectedOutput * m_values.array() * (ArrayXf::Ones(expectedOutput.SizeAtCompileTime) - m_values.array());
    m_weights += (m_values * delta * 0.1).matrix();
    
    return expectedOutput.matrix() * m_weights;
}
