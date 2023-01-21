// check the biome at a block position
//uwu
#include "isvillage.c"
#include <stdio.h>
#include <Python.h>
#include <string.h>

extern int isvillage(long, int, int, int);

static PyObject* isvillage(PyObject* self, PyObject* args)
{
	long seed; 
	int xpos, ypos, zpos;
	int result
	result = isvillage( seed, xpos, ypos, zpos)
	
    return Py_BuildValue("i", result);

};

//meth>methods 
static PyMethodDef isvillagemethods[] = {
    { "isvillage", isvillage, METH_VARARGS},
    { NULL},
};



// Module Definition Shit
static struct PyModuleDef isvillage = {
    PyModuleDef_HEAD_INIT,
    "isvillage",
    "is village?",
    -1,
    isvillagemethods
};

PyMODINIT_FUNC PyInit_isvillage(void)
{
    return PyModule_Create(&isvillage);
}


