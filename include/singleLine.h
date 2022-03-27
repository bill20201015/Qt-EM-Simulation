//
// MATLAB Compiler: 8.2 (R2021a)
// Date: Tue Mar 22 15:05:30 2022
// Arguments:
// "-B""macro_default""-W""cpplib:singleLine,all,version=1.0""-T""link:lib""-d""
// E:\Matlab\projects\simple\singleLine\for_testing""-v""E:\Matlab\projects\simp
// le\singleLine.m"
//

#ifndef singleLine_h
#define singleLine_h 1

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
#ifndef LIB_singleLine_C_API 
#define LIB_singleLine_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_singleLine_C_API 
bool MW_CALL_CONV singleLineInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_singleLine_C_API 
bool MW_CALL_CONV singleLineInitialize(void);

extern LIB_singleLine_C_API 
void MW_CALL_CONV singleLineTerminate(void);

extern LIB_singleLine_C_API 
void MW_CALL_CONV singleLinePrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_singleLine_C_API 
bool MW_CALL_CONV mlxSingleLine(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_singleLine
#define PUBLIC_singleLine_CPP_API __declspec(dllexport)
#else
#define PUBLIC_singleLine_CPP_API __declspec(dllimport)
#endif

#define LIB_singleLine_CPP_API PUBLIC_singleLine_CPP_API

#else

#if !defined(LIB_singleLine_CPP_API)
#if defined(LIB_singleLine_C_API)
#define LIB_singleLine_CPP_API LIB_singleLine_C_API
#else
#define LIB_singleLine_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_singleLine_CPP_API void MW_CALL_CONV singleLine(int nargout, mwArray& x, mwArray& y, const mwArray& u0, const mwArray& epsi, const mwArray& c0, const mwArray& h, const mwArray& rw, const mwArray& L, const mwArray& Zsh_SL, const mwArray& Zsh_SR, const mwArray& E0, const mwArray& thetaP, const mwArray& phiP, const mwArray& thetaE, const mwArray& acc);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
