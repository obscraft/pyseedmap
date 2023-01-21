// check the biome at a block position
//uwu
#include "overworld.c"
#include <stdio.h>
#include <Python.h>
#include <string.h>
static PyObject* pyBiomeAtPos(PyObject* self, PyObject* args)
{
	int xpos, ypos, zpos;
	long seed; 
    
    if(!PyArg_ParseTuple(args, "liii", &seed, &xpos, &ypos, &zpos))
        return NULL;
	
    return Py_BuildValue("i", cBiomeAtPos( seed, xpos, ypos, zpos));

}
PyDoc_STRVAR(biomeAtPos_doc, "biomeAtPos(biome, seed, xpos, zpos, version)->Bool\n\n\
Returns True if the [biome] biome is at position (xpos, zpos). Otherwise returns False");

//meth>methods 
static PyMethodDef methods[] = {
    { "biome_at_pos", (PyCFunction) pyBiomeAtPos, METH_VARARGS, biomeAtPos_doc
	},
    { NULL, NULL, 0, NULL }
};



// Module Definition Shit
static struct PyModuleDef overworld = {
    PyModuleDef_HEAD_INIT,
    "overworld",
    "Search functions for Pyubiomes, a Python wrapper for cubiomes.",
    -1,
    methods
};

PyMODINIT_FUNC PyInit_overworld(void)
{
    return PyModule_Create(&overworld);
}


