//
// MATLAB Compiler: 8.2 (R2021a)
// Date: Wed Mar 23 15:44:13 2022
// Arguments:
// "-B""macro_default""-W""cpplib:near_field_electric_dipole,all,version=1.0""-T
// ""link:lib""-d""D:\Application\???\Data\WeChat
// Files\wxid_xjbrugsx9acs22\FileStorage\File\2022-03\nearField\near_field_elect
// ric_dipole\for_testing""-v""D:\Application\???\Data\WeChat
// Files\wxid_xjbrugsx9acs22\FileStorage\File\2022-03\nearField\near_field_elect
// ric_dipole.m""D:\Application\???\Data\WeChat
// Files\wxid_xjbrugsx9acs22\FileStorage\File\2022-03\nearField\near_field_facto
// rs.m""D:\Application\???\Data\WeChat
// Files\wxid_xjbrugsx9acs22\FileStorage\File\2022-03\nearField\nearField.m"
//

#ifndef near_field_electric_dipole_h
#define near_field_electric_dipole_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#include "mclcppclass.h"
#ifdef __cplusplus
extern "C" { // sbcheck:ok:extern_c
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_near_field_electric_dipole_C_API 
#define LIB_near_field_electric_dipole_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_near_field_electric_dipole_C_API 
bool MW_CALL_CONV near_field_electric_dipoleInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_near_field_electric_dipole_C_API 
bool MW_CALL_CONV near_field_electric_dipoleInitialize(void);

extern LIB_near_field_electric_dipole_C_API 
void MW_CALL_CONV near_field_electric_dipoleTerminate(void);

extern LIB_near_field_electric_dipole_C_API 
void MW_CALL_CONV near_field_electric_dipolePrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_near_field_electric_dipole_C_API 
bool MW_CALL_CONV mlxNear_field_electric_dipole(int nlhs, mxArray *plhs[], int nrhs, 
                                                mxArray *prhs[]);

extern LIB_near_field_electric_dipole_C_API 
bool MW_CALL_CONV mlxNear_field_factors(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                        *prhs[]);

extern LIB_near_field_electric_dipole_C_API 
bool MW_CALL_CONV mlxNearField(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_near_field_electric_dipole
#define PUBLIC_near_field_electric_dipole_CPP_API __declspec(dllexport)
#else
#define PUBLIC_near_field_electric_dipole_CPP_API __declspec(dllimport)
#endif

#define LIB_near_field_electric_dipole_CPP_API PUBLIC_near_field_electric_dipole_CPP_API

#else

#if !defined(LIB_near_field_electric_dipole_CPP_API)
#if defined(LIB_near_field_electric_dipole_C_API)
#define LIB_near_field_electric_dipole_CPP_API LIB_near_field_electric_dipole_C_API
#else
#define LIB_near_field_electric_dipole_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_near_field_electric_dipole_CPP_API void MW_CALL_CONV near_field_electric_dipole(int nargout, mwArray& Ex, mwArray& Ey, mwArray& Ez, mwArray& p, const mwArray& P0, const mwArray& x0, const mwArray& y0, const mwArray& z0, const mwArray& x, const mwArray& y, const mwArray& z, const mwArray& theta, const mwArray& phi, const mwArray& etta0, const mwArray& c0, const mwArray& f);

extern LIB_near_field_electric_dipole_CPP_API void MW_CALL_CONV near_field_factors(int nargout, mwArray& F, mwArray& G, const mwArray& R, const mwArray& f, const mwArray& c0);

extern LIB_near_field_electric_dipole_CPP_API void MW_CALL_CONV nearField(int nargout, mwArray& f, mwArray& ICM, mwArray& IDM, const mwArray& u0, const mwArray& epsi, const mwArray& c0, const mwArray& s, const mwArray& h, const mwArray& rw1, const mwArray& rw2, const mwArray& L, const mwArray& Ra, const mwArray& Rb, const mwArray& Rc, const mwArray& x0, const mwArray& y0, const mwArray& z0, const mwArray& acc, const mwArray& P0, const mwArray& theta, const mwArray& phi);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
