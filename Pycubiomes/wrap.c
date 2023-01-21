// check the biome at a block position
//uwu
#include "isvillage.c"
#include <stdio.h>
#include <Python.h>
#include <string.h>
static PyObject* isvillage(PyObject* self, PyObject* args)
{
	int xpos, ypos, zpos;
	long seed; 
    
    if(!PyArg_ParseTuple(args, "liii", &seed, &xpos, &ypos, &zpos))
        return NULL;
	
    return Py_BuildValue("i", isvillage( seed, xpos, ypos, zpos));

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


