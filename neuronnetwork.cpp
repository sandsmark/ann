#include "neuronnetwork.h"

#include <QDebug>

NeuronNetwork::NeuronNetwork(int inputSize, QList< int > layerSizes)
{
    int oldSize = inputSize;
    foreach(int layerSize, layerSizes) {
        m_layers.append(NeuronLayer(layerSize, oldSize));
        qDebug() << m_layers.size();
        oldSize = layerSize;
    }
}

void NeuronNetwork::setInput(ArrayXf input)
{
    for(int i=0; i<m_layers.size(); i++) {
        //qDebug() << "using layer:" << i;
        m_layers[i].setInput(input);
        input = m_layers[i].output();
    }
}

const ArrayXf& NeuronNetwork::output()
{
    return m_layers.last().output();
}

void NeuronNetwork::train(ArrayXf expectedOutput)
{
    for (int i=m_layers.size()-1; i>=0; --i) {
        //qDebug() << "training layer:" << i;
        expectedOutput = m_layers[i].previousOutput(expectedOutput);
    }
}
