#include "triangles_from_strip.h"
#include <iostream>

template <typename DerivedS, typename DerivedF>
IGL_INLINE void igl::triangles_from_strip(
  const Eigen::MatrixBase<DerivedS>& S,
  Eigen::PlainObjectBase<DerivedF>& F)
{
  using namespace std;
  F.resize(S.size()-2,3);
  for(int s = 0;s < S.size()-2;s++)
  {
    if(s%2 == 0)
    {
      F(s,0) = S(s+2);
      F(s,1) = S(s+1);
      F(s,2) = S(s+0);
    }else
    {
      F(s,0) = S(s+0);
      F(s,1) = S(s+1);
      F(s,2) = S(s+2);
    }
  }
}

#ifdef IGL_STATIC_LIBRARY
// Explicit template specialization
#endif
