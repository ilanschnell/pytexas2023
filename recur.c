#include <Python.h>


static PyObject *
recur_tuple(PyObject *module)
{
    PyObject *tuple;

    if ((tuple = PyTuple_New(1)) == NULL)
        return NULL;

    PyTuple_SET_ITEM(tuple, 0, tuple);

    return tuple;
}


static PyObject *
r_frozenset(PyObject *module, PyObject *arg)
{
    PyObject *result, *element;

    element = PyList_GET_ITEM(arg, 0);

    if ((result = PyFrozenSet_New(arg)) == NULL)
        return NULL;

    element = result;

    return result;
}


static PyMethodDef module_functions[] = {
    {"recur_tuple",  (PyCFunction) recur_tuple,  METH_NOARGS,  0},
    {"r_frozenset",  (PyCFunction) r_frozenset,  METH_O,       0},
    {NULL, NULL}  /* sentinel */
};

static PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT, "recur", 0, -1, module_functions,
};

PyMODINIT_FUNC PyInit_recur(void)
{
    return PyModule_Create(&moduledef);
}
