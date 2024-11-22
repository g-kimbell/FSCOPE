#ifndef FLUCTUOSCOPE_EXT_C_H
#define FLUCTUOSCOPE_EXT_C_H

extern "C" {
    double* MC_sigma_array(double t,double h,double Tctau,double Tctauphi);
}
extern "C" {
    double* hc2_array(double t);
}

#endif