/* File: creepmodule.c
 * This file is auto-generated with f2py (version:2).
 * f2py is a Fortran to Python Interface Generator (FPIG), Second Edition,
 * written by Pearu Peterson <pearu@cens.ioc.ee>.
 * Generation date: Fri May 17 14:27:02 2019
 * Do not edit this file directly unless you know what you are doing!!!
 */

#ifdef __cplusplus
extern "C" {
#endif

/*********************** See f2py2e/cfuncs.py: includes ***********************/
#include "Python.h"
#include <stdarg.h>
#include "fortranobject.h"
#include <math.h>

/**************** See f2py2e/rules.py: mod_rules['modulebody'] ****************/
static PyObject *creep_error;
static PyObject *creep_module;

/*********************** See f2py2e/cfuncs.py: typedefs ***********************/
/*need_typedefs*/

/****************** See f2py2e/cfuncs.py: typedefs_generated ******************/
/*need_typedefs_generated*/

/********************** See f2py2e/cfuncs.py: cppmacros **********************/
#if defined(PREPEND_FORTRAN)
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F
#else
#define F_FUNC(f,F) _##f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) _##F##_
#else
#define F_FUNC(f,F) _##f##_
#endif
#endif
#else
#if defined(NO_APPEND_FORTRAN)
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F
#else
#define F_FUNC(f,F) f
#endif
#else
#if defined(UPPERCASE_FORTRAN)
#define F_FUNC(f,F) F##_
#else
#define F_FUNC(f,F) f##_
#endif
#endif
#endif
#if defined(UNDERSCORE_G77)
#define F_FUNC_US(f,F) F_FUNC(f##_,F##_)
#else
#define F_FUNC_US(f,F) F_FUNC(f,F)
#endif

#define rank(var) var ## _Rank
#define shape(var,dim) var ## _Dims[dim]
#define old_rank(var) (PyArray_NDIM((PyArrayObject *)(capi_ ## var ## _tmp)))
#define old_shape(var,dim) PyArray_DIM(((PyArrayObject *)(capi_ ## var ## _tmp)),dim)
#define fshape(var,dim) shape(var,rank(var)-dim-1)
#define len(var) shape(var,0)
#define flen(var) fshape(var,0)
#define old_size(var) PyArray_SIZE((PyArrayObject *)(capi_ ## var ## _tmp))
/* #define index(i) capi_i ## i */
#define slen(var) capi_ ## var ## _len
#define size(var, ...) f2py_size((PyArrayObject *)(capi_ ## var ## _tmp), ## __VA_ARGS__, -1)

#define CHECKSCALAR(check,tcheck,name,show,var)\
    if (!(check)) {\
        char errstring[256];\
        sprintf(errstring, "%s: "show, "("tcheck") failed for "name, var);\
        PyErr_SetString(creep_error,errstring);\
        /*goto capi_fail;*/\
    } else 
#ifdef DEBUGCFUNCS
#define CFUNCSMESS(mess) fprintf(stderr,"debug-capi:"mess);
#define CFUNCSMESSPY(mess,obj) CFUNCSMESS(mess) \
    PyObject_Print((PyObject *)obj,stderr,Py_PRINT_RAW);\
    fprintf(stderr,"\n");
#else
#define CFUNCSMESS(mess)
#define CFUNCSMESSPY(mess,obj)
#endif

#ifndef max
#define max(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) ((a < b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a,b) ((a > b) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a,b) ((a < b) ? (a) : (b))
#endif


/************************ See f2py2e/cfuncs.py: cfuncs ************************/
static int f2py_size(PyArrayObject* var, ...)
{
  npy_int sz = 0;
  npy_int dim;
  npy_int rank;
  va_list argp;
  va_start(argp, var);
  dim = va_arg(argp, npy_int);
  if (dim==-1)
    {
      sz = PyArray_SIZE(var);
    }
  else
    {
      rank = PyArray_NDIM(var);
      if (dim>=1 && dim<=rank)
        sz = PyArray_DIM(var, dim-1);
      else
        fprintf(stderr, "f2py_size: 2nd argument value=%d fails to satisfy 1<=value<=%d. Result will be 0.\n", dim, rank);
    }
  va_end(argp);
  return sz;
}

static int double_from_pyobj(double* v,PyObject *obj,const char *errmess) {
    PyObject* tmp = NULL;
    if (PyFloat_Check(obj)) {
#ifdef __sgi
        *v = PyFloat_AsDouble(obj);
#else
        *v = PyFloat_AS_DOUBLE(obj);
#endif
        return 1;
    }
    tmp = PyNumber_Float(obj);
    if (tmp) {
#ifdef __sgi
        *v = PyFloat_AsDouble(tmp);
#else
        *v = PyFloat_AS_DOUBLE(tmp);
#endif
        Py_DECREF(tmp);
        return 1;
    }
    if (PyComplex_Check(obj))
        tmp = PyObject_GetAttrString(obj,"real");
    else if (PyString_Check(obj) || PyUnicode_Check(obj))
        /*pass*/;
    else if (PySequence_Check(obj))
        tmp = PySequence_GetItem(obj,0);
    if (tmp) {
        PyErr_Clear();
        if (double_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
        Py_DECREF(tmp);
    }
    {
        PyObject* err = PyErr_Occurred();
        if (err==NULL) err = creep_error;
        PyErr_SetString(err,errmess);
    }
    return 0;
}

static int int_from_pyobj(int* v,PyObject *obj,const char *errmess) {
    PyObject* tmp = NULL;
    if (PyInt_Check(obj)) {
        *v = (int)PyInt_AS_LONG(obj);
        return 1;
    }
    tmp = PyNumber_Int(obj);
    if (tmp) {
        *v = PyInt_AS_LONG(tmp);
        Py_DECREF(tmp);
        return 1;
    }
    if (PyComplex_Check(obj))
        tmp = PyObject_GetAttrString(obj,"real");
    else if (PyString_Check(obj) || PyUnicode_Check(obj))
        /*pass*/;
    else if (PySequence_Check(obj))
        tmp = PySequence_GetItem(obj,0);
    if (tmp) {
        PyErr_Clear();
        if (int_from_pyobj(v,tmp,errmess)) {Py_DECREF(tmp); return 1;}
        Py_DECREF(tmp);
    }
    {
        PyObject* err = PyErr_Occurred();
        if (err==NULL) err = creep_error;
        PyErr_SetString(err,errmess);
    }
    return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern void F_FUNC(cslf,CSLF)(double*,double*,double*,double*,int*,int*,double*);
extern void F_FUNC(smooth,SMOOTH)(double*,int*,int*,int*,double*);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/************************************ cslf ************************************/
static char doc_f2py_rout_creep_cslf[] = "\
varout = cslf(varin,spval,validmin,validmax,[nx,ny])\n\nWrapper for ``cslf``.\
\n\nParameters\n----------\n"
"varin : input rank-2 array('d') with bounds (nx,ny)\n"
"spval : input float\n"
"validmin : input float\n"
"validmax : input float\n"
"\nOther Parameters\n----------------\n"
"nx : input int, optional\n    Default: shape(varin,0)\n"
"ny : input int, optional\n    Default: shape(varin,1)\n"
"\nReturns\n-------\n"
"varout : rank-2 array('d') with bounds (nx,ny)";
/* extern void F_FUNC(cslf,CSLF)(double*,double*,double*,double*,int*,int*,double*); */
static PyObject *f2py_rout_creep_cslf(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(double*,double*,double*,double*,int*,int*,double*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  double *varin = NULL;
  npy_intp varin_Dims[2] = {-1, -1};
  const int varin_Rank = 2;
  PyArrayObject *capi_varin_tmp = NULL;
  int capi_varin_intent = 0;
  PyObject *varin_capi = Py_None;
  double spval = 0;
  PyObject *spval_capi = Py_None;
  double validmin = 0;
  PyObject *validmin_capi = Py_None;
  double validmax = 0;
  PyObject *validmax_capi = Py_None;
  int nx = 0;
  PyObject *nx_capi = Py_None;
  int ny = 0;
  PyObject *ny_capi = Py_None;
  double *varout = NULL;
  npy_intp varout_Dims[2] = {-1, -1};
  const int varout_Rank = 2;
  PyArrayObject *capi_varout_tmp = NULL;
  int capi_varout_intent = 0;
  static char *capi_kwlist[] = {"varin","spval","validmin","validmax","nx","ny",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOO|OO:creep.cslf",\
    capi_kwlist,&varin_capi,&spval_capi,&validmin_capi,&validmax_capi,&nx_capi,&ny_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable varin */
  ;
  capi_varin_intent |= F2PY_INTENT_IN;
  capi_varin_tmp = array_from_pyobj(NPY_DOUBLE,varin_Dims,varin_Rank,capi_varin_intent,varin_capi);
  if (capi_varin_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(creep_error,"failed in converting 1st argument `varin' of creep.cslf to C/Fortran array" );
  } else {
    varin = (double *)(PyArray_DATA(capi_varin_tmp));

  /* Processing variable spval */
    f2py_success = double_from_pyobj(&spval,spval_capi,"creep.cslf() 2nd argument (spval) can't be converted to double");
  if (f2py_success) {
  /* Processing variable validmin */
    f2py_success = double_from_pyobj(&validmin,validmin_capi,"creep.cslf() 3rd argument (validmin) can't be converted to double");
  if (f2py_success) {
  /* Processing variable validmax */
    f2py_success = double_from_pyobj(&validmax,validmax_capi,"creep.cslf() 4th argument (validmax) can't be converted to double");
  if (f2py_success) {
  /* Processing variable nx */
  if (nx_capi == Py_None) nx = shape(varin,0); else
    f2py_success = int_from_pyobj(&nx,nx_capi,"creep.cslf() 1st keyword (nx) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(varin,0)==nx,"shape(varin,0)==nx","1st keyword nx","cslf:nx=%d",nx) {
  /* Processing variable ny */
  if (ny_capi == Py_None) ny = shape(varin,1); else
    f2py_success = int_from_pyobj(&ny,ny_capi,"creep.cslf() 2nd keyword (ny) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(varin,1)==ny,"shape(varin,1)==ny","2nd keyword ny","cslf:ny=%d",ny) {
  /* Processing variable varout */
  varout_Dims[0]=nx,varout_Dims[1]=ny;
  capi_varout_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
  capi_varout_tmp = array_from_pyobj(NPY_DOUBLE,varout_Dims,varout_Rank,capi_varout_intent,Py_None);
  if (capi_varout_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(creep_error,"failed in converting hidden `varout' of creep.cslf to C/Fortran array" );
  } else {
    varout = (double *)(PyArray_DATA(capi_varout_tmp));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(varin,&spval,&validmin,&validmax,&nx,&ny,varout);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("N",capi_varout_tmp);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  }  /*if (capi_varout_tmp == NULL) ... else of varout*/
  /* End of cleaning variable varout */
  } /*CHECKSCALAR(shape(varin,1)==ny)*/
  } /*if (f2py_success) of ny*/
  /* End of cleaning variable ny */
  } /*CHECKSCALAR(shape(varin,0)==nx)*/
  } /*if (f2py_success) of nx*/
  /* End of cleaning variable nx */
  } /*if (f2py_success) of validmax*/
  /* End of cleaning variable validmax */
  } /*if (f2py_success) of validmin*/
  /* End of cleaning variable validmin */
  } /*if (f2py_success) of spval*/
  /* End of cleaning variable spval */
  if((PyObject *)capi_varin_tmp!=varin_capi) {
    Py_XDECREF(capi_varin_tmp); }
  }  /*if (capi_varin_tmp == NULL) ... else of varin*/
  /* End of cleaning variable varin */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/******************************** end of cslf ********************************/

/*********************************** smooth ***********************************/
static char doc_f2py_rout_creep_smooth[] = "\
varout = smooth(varin,mask,[nx,ny])\n\nWrapper for ``smooth``.\
\n\nParameters\n----------\n"
"varin : input rank-2 array('d') with bounds (nx,ny)\n"
"mask : input rank-2 array('i') with bounds (nx,ny)\n"
"\nOther Parameters\n----------------\n"
"nx : input int, optional\n    Default: shape(varin,0)\n"
"ny : input int, optional\n    Default: shape(varin,1)\n"
"\nReturns\n-------\n"
"varout : rank-2 array('d') with bounds (nx,ny)";
/* extern void F_FUNC(smooth,SMOOTH)(double*,int*,int*,int*,double*); */
static PyObject *f2py_rout_creep_smooth(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(double*,int*,int*,int*,double*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  double *varin = NULL;
  npy_intp varin_Dims[2] = {-1, -1};
  const int varin_Rank = 2;
  PyArrayObject *capi_varin_tmp = NULL;
  int capi_varin_intent = 0;
  PyObject *varin_capi = Py_None;
  int *mask = NULL;
  npy_intp mask_Dims[2] = {-1, -1};
  const int mask_Rank = 2;
  PyArrayObject *capi_mask_tmp = NULL;
  int capi_mask_intent = 0;
  PyObject *mask_capi = Py_None;
  int nx = 0;
  PyObject *nx_capi = Py_None;
  int ny = 0;
  PyObject *ny_capi = Py_None;
  double *varout = NULL;
  npy_intp varout_Dims[2] = {-1, -1};
  const int varout_Rank = 2;
  PyArrayObject *capi_varout_tmp = NULL;
  int capi_varout_intent = 0;
  static char *capi_kwlist[] = {"varin","mask","nx","ny",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OO|OO:creep.smooth",\
    capi_kwlist,&varin_capi,&mask_capi,&nx_capi,&ny_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable varin */
  ;
  capi_varin_intent |= F2PY_INTENT_IN;
  capi_varin_tmp = array_from_pyobj(NPY_DOUBLE,varin_Dims,varin_Rank,capi_varin_intent,varin_capi);
  if (capi_varin_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(creep_error,"failed in converting 1st argument `varin' of creep.smooth to C/Fortran array" );
  } else {
    varin = (double *)(PyArray_DATA(capi_varin_tmp));

  /* Processing variable nx */
  if (nx_capi == Py_None) nx = shape(varin,0); else
    f2py_success = int_from_pyobj(&nx,nx_capi,"creep.smooth() 1st keyword (nx) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(varin,0)==nx,"shape(varin,0)==nx","1st keyword nx","smooth:nx=%d",nx) {
  /* Processing variable ny */
  if (ny_capi == Py_None) ny = shape(varin,1); else
    f2py_success = int_from_pyobj(&ny,ny_capi,"creep.smooth() 2nd keyword (ny) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(varin,1)==ny,"shape(varin,1)==ny","2nd keyword ny","smooth:ny=%d",ny) {
  /* Processing variable mask */
  mask_Dims[0]=nx,mask_Dims[1]=ny;
  capi_mask_intent |= F2PY_INTENT_IN;
  capi_mask_tmp = array_from_pyobj(NPY_INT,mask_Dims,mask_Rank,capi_mask_intent,mask_capi);
  if (capi_mask_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(creep_error,"failed in converting 2nd argument `mask' of creep.smooth to C/Fortran array" );
  } else {
    mask = (int *)(PyArray_DATA(capi_mask_tmp));

  /* Processing variable varout */
  varout_Dims[0]=nx,varout_Dims[1]=ny;
  capi_varout_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
  capi_varout_tmp = array_from_pyobj(NPY_DOUBLE,varout_Dims,varout_Rank,capi_varout_intent,Py_None);
  if (capi_varout_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(creep_error,"failed in converting hidden `varout' of creep.smooth to C/Fortran array" );
  } else {
    varout = (double *)(PyArray_DATA(capi_varout_tmp));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(varin,mask,&nx,&ny,varout);
if (PyErr_Occurred())
  f2py_success = 0;
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_call_clock();
#endif
/*end of callfortranroutine*/
    if (f2py_success) {
/*pyobjfrom*/
/*end of pyobjfrom*/
    CFUNCSMESS("Building return value.\n");
    capi_buildvalue = Py_BuildValue("N",capi_varout_tmp);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  }  /*if (capi_varout_tmp == NULL) ... else of varout*/
  /* End of cleaning variable varout */
  if((PyObject *)capi_mask_tmp!=mask_capi) {
    Py_XDECREF(capi_mask_tmp); }
  }  /*if (capi_mask_tmp == NULL) ... else of mask*/
  /* End of cleaning variable mask */
  } /*CHECKSCALAR(shape(varin,1)==ny)*/
  } /*if (f2py_success) of ny*/
  /* End of cleaning variable ny */
  } /*CHECKSCALAR(shape(varin,0)==nx)*/
  } /*if (f2py_success) of nx*/
  /* End of cleaning variable nx */
  if((PyObject *)capi_varin_tmp!=varin_capi) {
    Py_XDECREF(capi_varin_tmp); }
  }  /*if (capi_varin_tmp == NULL) ... else of varin*/
  /* End of cleaning variable varin */
/*end of cleanupfrompyobj*/
  if (capi_buildvalue == NULL) {
/*routdebugfailure*/
  } else {
/*routdebugleave*/
  }
  CFUNCSMESS("Freeing memory.\n");
/*freemem*/
#ifdef F2PY_REPORT_ATEXIT
f2py_stop_clock();
#endif
  return capi_buildvalue;
}
/******************************* end of smooth *******************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
  {"cslf",-1,{{-1}},0,(char *)F_FUNC(cslf,CSLF),(f2py_init_func)f2py_rout_creep_cslf,doc_f2py_rout_creep_cslf},
  {"smooth",-1,{{-1}},0,(char *)F_FUNC(smooth,SMOOTH),(f2py_init_func)f2py_rout_creep_smooth,doc_f2py_rout_creep_smooth},

/*eof routine_defs*/
  {NULL}
};

static PyMethodDef f2py_module_methods[] = {

  {NULL,NULL}
};

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "creep",
  NULL,
  -1,
  f2py_module_methods,
  NULL,
  NULL,
  NULL,
  NULL
};
#endif

#if PY_VERSION_HEX >= 0x03000000
#define RETVAL m
PyMODINIT_FUNC PyInit_creep(void) {
#else
#define RETVAL
PyMODINIT_FUNC initcreep(void) {
#endif
  int i;
  PyObject *m,*d, *s;
#if PY_VERSION_HEX >= 0x03000000
  m = creep_module = PyModule_Create(&moduledef);
#else
  m = creep_module = Py_InitModule("creep", f2py_module_methods);
#endif
  Py_TYPE(&PyFortran_Type) = &PyType_Type;
  import_array();
  if (PyErr_Occurred())
    {PyErr_SetString(PyExc_ImportError, "can't initialize module creep (failed to import numpy)"); return RETVAL;}
  d = PyModule_GetDict(m);
  s = PyString_FromString("$Revision: $");
  PyDict_SetItemString(d, "__version__", s);
#if PY_VERSION_HEX >= 0x03000000
  s = PyUnicode_FromString(
#else
  s = PyString_FromString(
#endif
    "This module 'creep' is auto-generated with f2py (version:2).\nFunctions:\n"
"  varout = cslf(varin,spval,validmin,validmax,nx=shape(varin,0),ny=shape(varin,1))\n"
"  varout = smooth(varin,mask,nx=shape(varin,0),ny=shape(varin,1))\n"
".");
  PyDict_SetItemString(d, "__doc__", s);
  creep_error = PyErr_NewException ("creep.error", NULL, NULL);
  Py_DECREF(s);
  for(i=0;f2py_routine_defs[i].name!=NULL;i++)
    PyDict_SetItemString(d, f2py_routine_defs[i].name,PyFortranObject_NewAsAttr(&f2py_routine_defs[i]));


/*eof initf2pywraphooks*/
/*eof initf90modhooks*/

/*eof initcommonhooks*/


#ifdef F2PY_REPORT_ATEXIT
  if (! PyErr_Occurred())
    on_exit(f2py_report_on_exit,(void*)"creep");
#endif

  return RETVAL;
}
#ifdef __cplusplus
}
#endif
