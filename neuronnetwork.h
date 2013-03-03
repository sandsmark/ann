#ifndef NEURONNETWORK_H
#define NEURONNETWORK_H

#include "neuronlayer.h"
#include <QtCore/QList>

class NeuronNetwork
{
public:
    NeuronNetwork(int inputSize, QList<int> layerSizes);
    void setInput(ArrayXf input);
    const ArrayXf &output();
    void train(ArrayXf expectedOutput);
    
private:
    QList<NeuronLayer> m_layers;
};

#endif//NEURONNETWORK_H