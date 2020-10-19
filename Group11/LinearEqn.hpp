#ifndef LINEAREQN
#define LINEAREQN
#include "Eqn.hpp"

class LinearEqn : public Eqn{
  float a, b, c, d, e, f;
  public:
    LinearEqn(float p, float q, float r, float s, float t, float  u);
    string solve();
};

#endif
