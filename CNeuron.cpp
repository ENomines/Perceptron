#include "CNeuron.h"

CNeuron::CNeuron() {}

CNeuron::CNeuron(const int size)
{
  Initialize(size);
}

void CNeuron::Initialize(const int size)
{
  m_iSize = size;

  m_dInputs = new double[size];
  m_dWeights = new double[size];

  for(int i = 0; i < size; i++)
    m_dWeights[i] = 0.1;
}

void CNeuron::SetData(double data[])
{
  for(int i = 0; i < m_iSize; i++)
  {
  	m_dInputs[i] = data[i];
  }
}

void CNeuron::Count()
{
  m_dSum = 0;

  for(int i = 0; i < m_iSize; i++)
  {
  	m_dSum += m_dInputs[i] * m_dWeights[i];
  }

  m_dOutput = m_dSum >= m_dBias ? 1.0 : 0.0;
}

double CNeuron::GetOutput() const
{
  return m_dOutput;
}

CNeuron::~CNeuron()
{
  delete[] m_dWeights;
  delete[] m_dInputs;
}


