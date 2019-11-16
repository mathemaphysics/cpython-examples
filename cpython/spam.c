#include <python3.6m/Python.h>

static PyObject *SpamError;

static PyObject *
spam_system(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = system(command);
    if (sts < 0)
    {
        PyErr_SetString(SpamError, "Extension command failed");
        return NULL;
    }
    return PyLong_FromLong(sts);
}

static PyObject *
spam_divide(PyObject *self, PyObject *args)
{
    int one, two, out;
    if(!PyArg_ParseTuple(args, "ii", &one, &two))
        return NULL;
    out = one + two;
    return PyLong_FromLong(out);
}

static PyMethodDef SpamMethods[] = {
    {"system", spam_system, METH_VARARGS,
     "Execute a bloody shell command!"},
    {"divide", spam_divide, METH_VARARGS,
     "Compute a division"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef spammodule = {
    PyModuleDef_HEAD_INIT,
    "spam",
    "A module to make spam!",
    -1,
    SpamMethods
};

PyMODINIT_FUNC
PyInit_spam(void)
{
    PyObject *m;

    m = PyModule_Create(&spammodule);
    if (m == NULL)
        return;

    SpamError = PyErr_NewException("spam.error", NULL, NULL);
    Py_INCREF(SpamError);
    PyModule_AddObject(m, "error", SpamError);
    return m;
}

// vim: tw=65:ts=4:sts=4:sw=4:et:sta
