#include <stdlib.h>
#include <python2.7/Python.h>
#include <vita2d.h>
#include <psp2/kernel/modulemgr.h>
#include <psp2/kernel/clib.h>


static PyObject *graphics_init(PyObject *self) {

    vita2d_init();
    vita2d_set_clear_color(RGBA8(0x00, 0x00, 0x00, 0xFF));
    
    Py_RETURN_NONE;
}

static PyObject *graphics_begin(PyObject *self) {

    vita2d_start_drawing();
    vita2d_clear_screen();
   
    Py_RETURN_NONE;
}

static PyObject *graphics_end(PyObject *self) {

    vita2d_end_drawing();
    vita2d_swap_buffers();
    
    Py_RETURN_NONE;
}

static PyObject *graphics_rectangle(PyObject *self, PyObject* pArgs) {

    float x, y, w, h;
    unsigned int color = 0xFF0000FF;
    if(!PyArg_ParseTuple(pArgs, "ffff|I", &x, &y, &w, &h, &color))
		  return NULL;
    sceClibPrintf("x %f\n", x);
    vita2d_draw_rectangle(x, y, w, h, color);
    
    Py_RETURN_NONE;
}



static PyMethodDef graphics_methods[] = {
   { "init", (PyCFunction)graphics_init, METH_NOARGS, "Initialize Graphics"},
   { "begin", (PyCFunction)graphics_begin, METH_NOARGS, "Begin Drawing"},
   { "end", (PyCFunction)graphics_end, METH_NOARGS, "End Drawing"},
   { "rectangle", (PyCFunction)graphics_rectangle, METH_VARARGS, "Draw Rectangle"},
   { NULL, NULL, 0, NULL }
};

PyMODINIT_FUNC
initppv_graphics(void)
{
    PyObject *m;
    m = Py_InitModule3("ppv_graphics", graphics_methods, "Vita Graphics Control Module");
    if (m == NULL)
        return;
}