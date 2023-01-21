// check the biome at a block position
//uwu
#include "isvillage.c"
#include <stdio.h>
#include <Python.h>
#include <string.h>

extern int cisvillage(long, int, int, int);

static PyObject* pyisvillage(PyObject* self, PyObject* args)
{
	long seed; 
	int xpos, ypos, zpos;
	int result;
	
	if (!PyArg_ParseTuple(args, "liii", &seed, &xpos, &ypos, &zpos))
        	return NULL;
	result = cisvillage( seed, xpos, ypos, zpos);
	
    return Py_BuildValue("i", result);

};

//meth>methods 
static PyMethodDef isvillagemethods[] = {
    { "isvillage", pyisvillage, METH_VARARGS},
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


