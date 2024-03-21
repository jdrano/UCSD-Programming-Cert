//
// Jose Medrano, U09845800
// jcdrano@gmail.com
// C/C++ Programming II : Dynamic Memory and File I/O Concepts
// 177752, Prof. Mitchell
// 02/02/24
// C2A4E3_pointerArray4D.cpp
// Win10
// Visual Studio 2022
//
// The file contains the implementation for a pointer array for a 4D array
// structure.
//

extern const int DIM0 = 2, DIM1 = 3, DIM2 = 4, DIM3 = 5;

static float xa[DIM3], xb[DIM3], xc[DIM3], xd[DIM3], xe[DIM3], xf[DIM3], 
xg[DIM3], xh[DIM3], xi[DIM3], xj[DIM3], xk[DIM3], xl[DIM3], xm[DIM3], xn[DIM3], 
xo[DIM3], xp[DIM3], xq[DIM3], xr[DIM3], xs[DIM3], xt[DIM3], xu[DIM3], xv[DIM3], 
xw[DIM3], xx[DIM3];

static float *ya[DIM2] = {xa, xb, xc, xd}, *yb[DIM2] = {xe, xf, xg, xh}, 
*yc[DIM2] = {xi, xj, xk, xl}, *yd[DIM2] = {xm, xn, xo, xp}, 
*ye[DIM2] = {xq, xr, xs, xt}, *yf[DIM2] = {xu, xv, xw, xx};

static float **za[DIM1] = {ya, yb, yc}, **zb[DIM1] = {yd, ye, yf};

float ***pointerArray4D[DIM0] = {za, zb};