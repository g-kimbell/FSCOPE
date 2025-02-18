
//---------------------------------------------------------------------------
#ifndef AGMdataH
#define AGMdataH
//---------------------------------------------------------------------------
#include <math.h>

using namespace std;
//---------------------------------------------------------------------------


//custom complex copied from complex.h w/o div operation
template <class _Tp>
struct ccomplex {
  typedef _Tp value_type;
  typedef ccomplex<_Tp> _Self;
    // Data members.
  value_type re;
  value_type im;

  // Constructors, destructor, assignment operator.
  ccomplex() : re(0), im(0) {}
  ccomplex(const value_type& __x)
    : re(__x), im(0) {}
  ccomplex(const value_type& __x, const value_type& __y)
    : re(__x), im(__y) {}
  ccomplex(const _Self& __z)
    : re(__z.re), im(__z.im) {}

  _Self& operator=(const _Self& __z) {
    re = __z.re;
    im = __z.im;
    return *this;
  }

  // Arithmetic op= operations involving one real argument.

  _Self& operator= (const value_type& __x) {
    re = __x;
    im = 0;
    return *this;
  }
  _Self& operator+= (const value_type& __x) {
    re += __x;
    return *this;
  }
  _Self& operator-= (const value_type& __x) {
    re -= __x;
    return *this;
  }
  _Self& operator*= (const value_type& __x) {
    re *= __x;
    im *= __x;
    return *this;
  }
  _Self& operator/= (const value_type& __x) {
    re /= __x;
    im /= __x;
    return *this;
  }
 _Self& operator+= (const _Self& __z) {
    re += __z.re;
    im += __z.im;
    return *this;
  }

  _Self& operator-= (const _Self& __z) {
    re -= __z.re;
    im -= __z.im;
    return *this;
  }
  
  _Self& operator*= (const _Self& __z) {
    value_type __r = re * __z.re - im * __z.im;
    value_type __i = re * __z.im + im * __z.re;
    re = __r;
    im = __i;
    return *this;
  }
};

typedef ccomplex<double> dcomplex;

//simple structures: more sophisticated class are part of the linalg module

struct dmatrix {
 int rows,cols;
 double *data; //data[j*col+i]=element in row j and col i
 //double elem(int i,int j) {return data[j*col+i];}
};

struct cmatrix {
 int rows,cols;
 dcomplex *data; //data[j*col+i]=element in row j and col i
 //cdouble elem(int i,int j) {return data[j*col+i];}
};


struct darray {
 int l;
 double *data;
};

struct carray {
 int l;
 dcomplex *data;
};

#endif
