#include <iostream>
#include <cmath>
#include <cstdlib>

class CNeuron
{
  public:
    CNeuron();
    CNeuron(const int size);
    ~CNeuron();

  	double *m_dInputs = nullptr;
  	double *m_dWeights = nullptr;
  	double m_dOutput = 0;
  
    void Initialize(const int size);
    void SetData(double data[]);
    void Count();

    double GetOutput() const;
  private:
	  int m_iSize = 0;
    double m_dSum = 0;

	  const double m_dBias = 1.0;
};