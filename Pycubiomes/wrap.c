// check the biome at a block position
//uwu
#include "mclib.c"
#include <stdio.h>
#include <Python.h>
#include <string.h>

extern int isvillage(long, int, int, int);

static PyObject* pyisvillage(PyObject* self, PyObject* args)
{
	long seed; 
	int xpos, ypos, zpos;
	int result;
	
	if (!PyArg_ParseTuple(args, "liii", &seed, &xpos, &ypos, &zpos))
        	return NULL;
	result = isvillage( seed, xpos, ypos, zpos);
	
    return Py_BuildValue("i", result);

};

//meth>methods 
static PyMethodDef isvillagemethods[] = {
    { "isvillage", pyisvillage, METH_VARARGS},
    { NULL},
};



// Module Definition Shit
static struct PyModuleDef mclib = {
    PyModuleDef_HEAD_INIT,
    "mclib",
    "lib for mcbe?",
    -1,
   isvillagemethods
};

PyMODINIT_FUNC PyInit_mclib(void)
{
    return PyModule_Create(&mclib);
}


