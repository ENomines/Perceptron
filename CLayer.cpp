#include "CLayer.h"

CLayer::CLayer(const int size, const int dataSize)
{
  m_iSize = size;

  m_neurons = new CNeuron[size];

  for(int i = 0; i < size; i++)
  	m_neurons[i].Initialize(dataSize);
}

void CLayer::SetData(double data[])
{
	for(int i = 0; i < m_iSize; i++)
	{
    m_neurons[i].SetData(data);
	}
}

void CLayer::Count()
{
	for(int i = 0; i < m_iSize; i++)
	{
    m_neurons[i].Count();
	}
}

CNeuron& CLayer::Get(int index) const
{
  return m_neurons[index];
}

CNeuron& CLayer::operator[](int index) const
{
  return Get(index);
}

CLayer::~CLayer()
{
  delete[] m_neurons;
}
