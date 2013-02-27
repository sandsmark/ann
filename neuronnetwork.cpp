#include "neuronnetwork.h"

NeuronNetwork::NeuronNetwork(int inputSize, QList<int> layerSizes)
{
    int oldSize = layerSizes.takeFirst();
    m_layers.append(NeuronLayer(oldSize, inputSize));
    foreach(int layerSize, layerSizes) {
        m_layers.append(NeuronLayer(layerSize, oldSize));
        oldSize = layerSize;
    }
}

void NeuronNetwork::setInput(ArrayXf input)
{
    for(int i=0; i<m_layers.size(); i++) {
        m_layers[i].setInput(input);
        input = m_layers[i].output();
    }
}

const ArrayXf NeuronNetwork::output()
{
    return m_layers.last().output();
}

void NeuronNetwork::train(ArrayXf expectedOutput)
{
    for (int i=m_layers.size(); i>=0; --i) {
        expectedOutput = m_layers[i].previousOutput(expectedOutput);
    }
}
