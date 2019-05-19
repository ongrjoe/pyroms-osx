/* File: _averagemodule.c
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
static PyObject *_average_error;
static PyObject *_average_module;

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
        PyErr_SetString(_average_error,errstring);\
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
        if (err==NULL) err = _average_error;
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
        if (err==NULL) err = _average_error;
        PyErr_SetString(err,errmess);
    }
    return 0;
}


/********************* See f2py2e/cfuncs.py: userincludes *********************/
/*need_userincludes*/

/********************* See f2py2e/capi_rules.py: usercode *********************/


/* See f2py2e/rules.py */
extern void F_FUNC(avg3d,AVG3D)(double*,double*,double*,double*,double*,int*,int*,int*);
extern void F_FUNC(avg2d,AVG2D)(double*,double*,double*,double*,double*,int*,int*);
/*eof externroutines*/

/******************** See f2py2e/capi_rules.py: usercode1 ********************/


/******************* See f2py2e/cb_rules.py: buildcallback *******************/
/*need_callbacks*/

/*********************** See f2py2e/rules.py: buildapi ***********************/

/*********************************** avg3d ***********************************/
static char doc_f2py_rout__average_avg3d[] = "\
avg = avg3d(dataset,incavg,counter,spval,[dim1,dim2,dim3])\n\nWrapper for ``avg3d``.\
\n\nParameters\n----------\n"
"dataset : input rank-3 array('d') with bounds (dim1,dim2,dim3)\n"
"incavg : input rank-3 array('d') with bounds (dim1,dim2,dim3)\n"
"counter : input float\n"
"spval : input float\n"
"\nOther Parameters\n----------------\n"
"dim1 : input int, optional\n    Default: shape(dataset,0)\n"
"dim2 : input int, optional\n    Default: shape(dataset,1)\n"
"dim3 : input int, optional\n    Default: shape(dataset,2)\n"
"\nReturns\n-------\n"
"avg : rank-3 array('d') with bounds (dim1,dim2,dim3)";
/* extern void F_FUNC(avg3d,AVG3D)(double*,double*,double*,double*,double*,int*,int*,int*); */
static PyObject *f2py_rout__average_avg3d(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(double*,double*,double*,double*,double*,int*,int*,int*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  double *avg = NULL;
  npy_intp avg_Dims[3] = {-1, -1, -1};
  const int avg_Rank = 3;
  PyArrayObject *capi_avg_tmp = NULL;
  int capi_avg_intent = 0;
  double *dataset = NULL;
  npy_intp dataset_Dims[3] = {-1, -1, -1};
  const int dataset_Rank = 3;
  PyArrayObject *capi_dataset_tmp = NULL;
  int capi_dataset_intent = 0;
  PyObject *dataset_capi = Py_None;
  double *incavg = NULL;
  npy_intp incavg_Dims[3] = {-1, -1, -1};
  const int incavg_Rank = 3;
  PyArrayObject *capi_incavg_tmp = NULL;
  int capi_incavg_intent = 0;
  PyObject *incavg_capi = Py_None;
  double counter = 0;
  PyObject *counter_capi = Py_None;
  double spval = 0;
  PyObject *spval_capi = Py_None;
  int dim1 = 0;
  PyObject *dim1_capi = Py_None;
  int dim2 = 0;
  PyObject *dim2_capi = Py_None;
  int dim3 = 0;
  PyObject *dim3_capi = Py_None;
  static char *capi_kwlist[] = {"dataset","incavg","counter","spval","dim1","dim2","dim3",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOO|OOO:_average.avg3d",\
    capi_kwlist,&dataset_capi,&incavg_capi,&counter_capi,&spval_capi,&dim1_capi,&dim2_capi,&dim3_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable dataset */
  ;
  capi_dataset_intent |= F2PY_INTENT_IN;
  capi_dataset_tmp = array_from_pyobj(NPY_DOUBLE,dataset_Dims,dataset_Rank,capi_dataset_intent,dataset_capi);
  if (capi_dataset_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_average_error,"failed in converting 1st argument `dataset' of _average.avg3d to C/Fortran array" );
  } else {
    dataset = (double *)(PyArray_DATA(capi_dataset_tmp));

  /* Processing variable counter */
    f2py_success = double_from_pyobj(&counter,counter_capi,"_average.avg3d() 3rd argument (counter) can't be converted to double");
  if (f2py_success) {
  /* Processing variable spval */
    f2py_success = double_from_pyobj(&spval,spval_capi,"_average.avg3d() 4th argument (spval) can't be converted to double");
  if (f2py_success) {
  /* Processing variable dim1 */
  if (dim1_capi == Py_None) dim1 = shape(dataset,0); else
    f2py_success = int_from_pyobj(&dim1,dim1_capi,"_average.avg3d() 1st keyword (dim1) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(dataset,0)==dim1,"shape(dataset,0)==dim1","1st keyword dim1","avg3d:dim1=%d",dim1) {
  /* Processing variable dim2 */
  if (dim2_capi == Py_None) dim2 = shape(dataset,1); else
    f2py_success = int_from_pyobj(&dim2,dim2_capi,"_average.avg3d() 2nd keyword (dim2) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(dataset,1)==dim2,"shape(dataset,1)==dim2","2nd keyword dim2","avg3d:dim2=%d",dim2) {
  /* Processing variable dim3 */
  if (dim3_capi == Py_None) dim3 = shape(dataset,2); else
    f2py_success = int_from_pyobj(&dim3,dim3_capi,"_average.avg3d() 3rd keyword (dim3) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(dataset,2)==dim3,"shape(dataset,2)==dim3","3rd keyword dim3","avg3d:dim3=%d",dim3) {
  /* Processing variable incavg */
  incavg_Dims[0]=dim1,incavg_Dims[1]=dim2,incavg_Dims[2]=dim3;
  capi_incavg_intent |= F2PY_INTENT_IN;
  capi_incavg_tmp = array_from_pyobj(NPY_DOUBLE,incavg_Dims,incavg_Rank,capi_incavg_intent,incavg_capi);
  if (capi_incavg_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_average_error,"failed in converting 2nd argument `incavg' of _average.avg3d to C/Fortran array" );
  } else {
    incavg = (double *)(PyArray_DATA(capi_incavg_tmp));

  /* Processing variable avg */
  avg_Dims[0]=dim1,avg_Dims[1]=dim2,avg_Dims[2]=dim3;
  capi_avg_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
  capi_avg_tmp = array_from_pyobj(NPY_DOUBLE,avg_Dims,avg_Rank,capi_avg_intent,Py_None);
  if (capi_avg_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_average_error,"failed in converting hidden `avg' of _average.avg3d to C/Fortran array" );
  } else {
    avg = (double *)(PyArray_DATA(capi_avg_tmp));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(avg,dataset,incavg,&counter,&spval,&dim1,&dim2,&dim3);
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
    capi_buildvalue = Py_BuildValue("N",capi_avg_tmp);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  }  /*if (capi_avg_tmp == NULL) ... else of avg*/
  /* End of cleaning variable avg */
  if((PyObject *)capi_incavg_tmp!=incavg_capi) {
    Py_XDECREF(capi_incavg_tmp); }
  }  /*if (capi_incavg_tmp == NULL) ... else of incavg*/
  /* End of cleaning variable incavg */
  } /*CHECKSCALAR(shape(dataset,2)==dim3)*/
  } /*if (f2py_success) of dim3*/
  /* End of cleaning variable dim3 */
  } /*CHECKSCALAR(shape(dataset,1)==dim2)*/
  } /*if (f2py_success) of dim2*/
  /* End of cleaning variable dim2 */
  } /*CHECKSCALAR(shape(dataset,0)==dim1)*/
  } /*if (f2py_success) of dim1*/
  /* End of cleaning variable dim1 */
  } /*if (f2py_success) of spval*/
  /* End of cleaning variable spval */
  } /*if (f2py_success) of counter*/
  /* End of cleaning variable counter */
  if((PyObject *)capi_dataset_tmp!=dataset_capi) {
    Py_XDECREF(capi_dataset_tmp); }
  }  /*if (capi_dataset_tmp == NULL) ... else of dataset*/
  /* End of cleaning variable dataset */
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
/******************************** end of avg3d ********************************/

/*********************************** avg2d ***********************************/
static char doc_f2py_rout__average_avg2d[] = "\
avg = avg2d(dataset,incavg,counter,spval,[dim1,dim2])\n\nWrapper for ``avg2d``.\
\n\nParameters\n----------\n"
"dataset : input rank-2 array('d') with bounds (dim1,dim2)\n"
"incavg : input rank-2 array('d') with bounds (dim1,dim2)\n"
"counter : input float\n"
"spval : input float\n"
"\nOther Parameters\n----------------\n"
"dim1 : input int, optional\n    Default: shape(dataset,0)\n"
"dim2 : input int, optional\n    Default: shape(dataset,1)\n"
"\nReturns\n-------\n"
"avg : rank-2 array('d') with bounds (dim1,dim2)";
/* extern void F_FUNC(avg2d,AVG2D)(double*,double*,double*,double*,double*,int*,int*); */
static PyObject *f2py_rout__average_avg2d(const PyObject *capi_self,
                           PyObject *capi_args,
                           PyObject *capi_keywds,
                           void (*f2py_func)(double*,double*,double*,double*,double*,int*,int*)) {
  PyObject * volatile capi_buildvalue = NULL;
  volatile int f2py_success = 1;
/*decl*/

  double *avg = NULL;
  npy_intp avg_Dims[2] = {-1, -1};
  const int avg_Rank = 2;
  PyArrayObject *capi_avg_tmp = NULL;
  int capi_avg_intent = 0;
  double *dataset = NULL;
  npy_intp dataset_Dims[2] = {-1, -1};
  const int dataset_Rank = 2;
  PyArrayObject *capi_dataset_tmp = NULL;
  int capi_dataset_intent = 0;
  PyObject *dataset_capi = Py_None;
  double *incavg = NULL;
  npy_intp incavg_Dims[2] = {-1, -1};
  const int incavg_Rank = 2;
  PyArrayObject *capi_incavg_tmp = NULL;
  int capi_incavg_intent = 0;
  PyObject *incavg_capi = Py_None;
  double counter = 0;
  PyObject *counter_capi = Py_None;
  double spval = 0;
  PyObject *spval_capi = Py_None;
  int dim1 = 0;
  PyObject *dim1_capi = Py_None;
  int dim2 = 0;
  PyObject *dim2_capi = Py_None;
  static char *capi_kwlist[] = {"dataset","incavg","counter","spval","dim1","dim2",NULL};

/*routdebugenter*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_clock();
#endif
  if (!PyArg_ParseTupleAndKeywords(capi_args,capi_keywds,\
    "OOOO|OO:_average.avg2d",\
    capi_kwlist,&dataset_capi,&incavg_capi,&counter_capi,&spval_capi,&dim1_capi,&dim2_capi))
    return NULL;
/*frompyobj*/
  /* Processing variable dataset */
  ;
  capi_dataset_intent |= F2PY_INTENT_IN;
  capi_dataset_tmp = array_from_pyobj(NPY_DOUBLE,dataset_Dims,dataset_Rank,capi_dataset_intent,dataset_capi);
  if (capi_dataset_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_average_error,"failed in converting 1st argument `dataset' of _average.avg2d to C/Fortran array" );
  } else {
    dataset = (double *)(PyArray_DATA(capi_dataset_tmp));

  /* Processing variable counter */
    f2py_success = double_from_pyobj(&counter,counter_capi,"_average.avg2d() 3rd argument (counter) can't be converted to double");
  if (f2py_success) {
  /* Processing variable spval */
    f2py_success = double_from_pyobj(&spval,spval_capi,"_average.avg2d() 4th argument (spval) can't be converted to double");
  if (f2py_success) {
  /* Processing variable dim1 */
  if (dim1_capi == Py_None) dim1 = shape(dataset,0); else
    f2py_success = int_from_pyobj(&dim1,dim1_capi,"_average.avg2d() 1st keyword (dim1) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(dataset,0)==dim1,"shape(dataset,0)==dim1","1st keyword dim1","avg2d:dim1=%d",dim1) {
  /* Processing variable dim2 */
  if (dim2_capi == Py_None) dim2 = shape(dataset,1); else
    f2py_success = int_from_pyobj(&dim2,dim2_capi,"_average.avg2d() 2nd keyword (dim2) can't be converted to int");
  if (f2py_success) {
  CHECKSCALAR(shape(dataset,1)==dim2,"shape(dataset,1)==dim2","2nd keyword dim2","avg2d:dim2=%d",dim2) {
  /* Processing variable incavg */
  incavg_Dims[0]=dim1,incavg_Dims[1]=dim2;
  capi_incavg_intent |= F2PY_INTENT_IN;
  capi_incavg_tmp = array_from_pyobj(NPY_DOUBLE,incavg_Dims,incavg_Rank,capi_incavg_intent,incavg_capi);
  if (capi_incavg_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_average_error,"failed in converting 2nd argument `incavg' of _average.avg2d to C/Fortran array" );
  } else {
    incavg = (double *)(PyArray_DATA(capi_incavg_tmp));

  /* Processing variable avg */
  avg_Dims[0]=dim1,avg_Dims[1]=dim2;
  capi_avg_intent |= F2PY_INTENT_OUT|F2PY_INTENT_HIDE;
  capi_avg_tmp = array_from_pyobj(NPY_DOUBLE,avg_Dims,avg_Rank,capi_avg_intent,Py_None);
  if (capi_avg_tmp == NULL) {
    if (!PyErr_Occurred())
      PyErr_SetString(_average_error,"failed in converting hidden `avg' of _average.avg2d to C/Fortran array" );
  } else {
    avg = (double *)(PyArray_DATA(capi_avg_tmp));

/*end of frompyobj*/
#ifdef F2PY_REPORT_ATEXIT
f2py_start_call_clock();
#endif
/*callfortranroutine*/
        (*f2py_func)(avg,dataset,incavg,&counter,&spval,&dim1,&dim2);
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
    capi_buildvalue = Py_BuildValue("N",capi_avg_tmp);
/*closepyobjfrom*/
/*end of closepyobjfrom*/
    } /*if (f2py_success) after callfortranroutine*/
/*cleanupfrompyobj*/
  }  /*if (capi_avg_tmp == NULL) ... else of avg*/
  /* End of cleaning variable avg */
  if((PyObject *)capi_incavg_tmp!=incavg_capi) {
    Py_XDECREF(capi_incavg_tmp); }
  }  /*if (capi_incavg_tmp == NULL) ... else of incavg*/
  /* End of cleaning variable incavg */
  } /*CHECKSCALAR(shape(dataset,1)==dim2)*/
  } /*if (f2py_success) of dim2*/
  /* End of cleaning variable dim2 */
  } /*CHECKSCALAR(shape(dataset,0)==dim1)*/
  } /*if (f2py_success) of dim1*/
  /* End of cleaning variable dim1 */
  } /*if (f2py_success) of spval*/
  /* End of cleaning variable spval */
  } /*if (f2py_success) of counter*/
  /* End of cleaning variable counter */
  if((PyObject *)capi_dataset_tmp!=dataset_capi) {
    Py_XDECREF(capi_dataset_tmp); }
  }  /*if (capi_dataset_tmp == NULL) ... else of dataset*/
  /* End of cleaning variable dataset */
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
/******************************** end of avg2d ********************************/
/*eof body*/

/******************* See f2py2e/f90mod_rules.py: buildhooks *******************/
/*need_f90modhooks*/

/************** See f2py2e/rules.py: module_rules['modulebody'] **************/

/******************* See f2py2e/common_rules.py: buildhooks *******************/

/*need_commonhooks*/

/**************************** See f2py2e/rules.py ****************************/

static FortranDataDef f2py_routine_defs[] = {
  {"avg3d",-1,{{-1}},0,(char *)F_FUNC(avg3d,AVG3D),(f2py_init_func)f2py_rout__average_avg3d,doc_f2py_rout__average_avg3d},
  {"avg2d",-1,{{-1}},0,(char *)F_FUNC(avg2d,AVG2D),(f2py_init_func)f2py_rout__average_avg2d,doc_f2py_rout__average_avg2d},

/*eof routine_defs*/
  {NULL}
};

static PyMethodDef f2py_module_methods[] = {

  {NULL,NULL}
};

#if PY_VERSION_HEX >= 0x03000000
static struct PyModuleDef moduledef = {
  PyModuleDef_HEAD_INIT,
  "_average",
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
PyMODINIT_FUNC PyInit__average(void) {
#else
#define RETVAL
PyMODINIT_FUNC init_average(void) {
#endif
  int i;
  PyObject *m,*d, *s;
#if PY_VERSION_HEX >= 0x03000000
  m = _average_module = PyModule_Create(&moduledef);
#else
  m = _average_module = Py_InitModule("_average", f2py_module_methods);
#endif
  Py_TYPE(&PyFortran_Type) = &PyType_Type;
  import_array();
  if (PyErr_Occurred())
    {PyErr_SetString(PyExc_ImportError, "can't initialize module _average (failed to import numpy)"); return RETVAL;}
  d = PyModule_GetDict(m);
  s = PyString_FromString("$Revision: $");
  PyDict_SetItemString(d, "__version__", s);
#if PY_VERSION_HEX >= 0x03000000
  s = PyUnicode_FromString(
#else
  s = PyString_FromString(
#endif
    "This module '_average' is auto-generated with f2py (version:2).\nFunctions:\n"
"  avg = avg3d(dataset,incavg,counter,spval,dim1=shape(dataset,0),dim2=shape(dataset,1),dim3=shape(dataset,2))\n"
"  avg = avg2d(dataset,incavg,counter,spval,dim1=shape(dataset,0),dim2=shape(dataset,1))\n"
".");
  PyDict_SetItemString(d, "__doc__", s);
  _average_error = PyErr_NewException ("_average.error", NULL, NULL);
  Py_DECREF(s);
  for(i=0;f2py_routine_defs[i].name!=NULL;i++)
    PyDict_SetItemString(d, f2py_routine_defs[i].name,PyFortranObject_NewAsAttr(&f2py_routine_defs[i]));


/*eof initf2pywraphooks*/
/*eof initf90modhooks*/

/*eof initcommonhooks*/


#ifdef F2PY_REPORT_ATEXIT
  if (! PyErr_Occurred())
    on_exit(f2py_report_on_exit,(void*)"_average");
#endif

  return RETVAL;
}
#ifdef __cplusplus
}
#endif
