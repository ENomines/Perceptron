#include "CLayer.h"

void TrainNeuron(CNeuron &neuron, double output);
void ErrorBackPropogation(CLayer &hiddenLayer, CLayer &outputLayer, double output);

int main()
{
  double data[4][2] = 
  { 
  	{ 0.0, 0.0 },
    { 1.0, 0.0 },
    { 0.0, 1.0 },
    { 1.0, 1.0 }
  };

  CLayer hiddenLayer(2, 2);
  CLayer outputLayer(1, 2);

  for(int i = 0; i < 15; i++)
  {
    hiddenLayer.SetData(data[1]);
    hiddenLayer.Count();

    static double hiddenData[2];
    hiddenData[0] = hiddenLayer[0].GetOutput();
    hiddenData[1] = hiddenLayer[1].GetOutput();

    outputLayer.SetData(hiddenData);
    outputLayer.Count();

    ErrorBackPropogation(hiddenLayer, outputLayer, 1.0);
  }

  hiddenLayer.SetData(data[1]);
  hiddenLayer.Count();

  static double hiddenData[2];
  hiddenData[0] = hiddenLayer[0].GetOutput();
  hiddenData[1] = hiddenLayer[1].GetOutput();

  outputLayer.SetData(hiddenData);
  outputLayer.Count();

  

  return 0;
}

void ErrorBackPropogation(CLayer &hiddenLayer, CLayer &outputLayer, double output)
{
	static double outputError = output - outputLayer[0].GetOutput();
	outputLayer[0].m_dWeights[0] += outputError * outputLayer[0].m_dInputs[0];
	outputLayer[0].m_dWeights[1] += outputError * outputLayer[0].m_dInputs[1];

	static double hiddenError = outputError * outputLayer[0].m_dWeights[0];
	hiddenLayer[0].m_dWeights[0] += hiddenError * hiddenLayer[0].m_dInputs[0];
	hiddenLayer[0].m_dWeights[1] += hiddenError * hiddenLayer[0].m_dInputs[1];

	hiddenError = outputError * outputLayer[0].m_dWeights[1];
	hiddenLayer[1].m_dWeights[0] += hiddenError * hiddenLayer[1].m_dInputs[0];
	hiddenLayer[1].m_dWeights[1] += hiddenError * hiddenLayer[1].m_dInputs[1];
}

void TrainNeuron(CNeuron &neuron, double output)
{
  neuron.Count();
  double error = output - neuron.GetOutput();;

  for(int i = 0; i < 2; i++)
  {
    neuron.m_dWeights[i] += neuron.m_dInputs[i] * error;
  }
}''