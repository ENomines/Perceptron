#include "CNeuron.h"

class CLayer
{
  public:
  	CLayer(const int size, const int dataSize);
  	~CLayer();

    void SetData(double data[]);
    void Count();

  	CNeuron& Get(int index) const;
  	CNeuron& operator[](int index) const;
  private:
    CNeuron* m_neurons = nullptr;

    int m_iSize = 0;
};