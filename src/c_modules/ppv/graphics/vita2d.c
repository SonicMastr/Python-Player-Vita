#include <stdlib.h>
#include <python2.7/Python.h>
#include <vita2d.h>
#include <psp2/kernel/modulemgr.h>
#include <psp2/kernel/clib.h>


static PyObject *init(PyObject *self) {

    vita2d_init();
    vita2d_set_clear_color(RGBA8(0x00, 0x00, 0x00, 0xFF));
    
    Py_RETURN_NONE;
}

static PyObject *begin(PyObject *self) {

    vita2d_start_drawing();
    vita2d_clear_screen();
   
    Py_RETURN_NONE;
}

static PyObject *end(PyObject *self) {

    vita2d_end_drawing();
    vita2d_swap_buffers();
    
    Py_RETURN_NONE;
}

static PyObject *rectangle(PyObject *self, PyObject* pArgs) {

    float x, y, w, h;
    unsigned int color = 0xFFFFFFFF; // Default Color (White)
    if(!PyArg_ParseTuple(pArgs, "ffff|I", &x, &y, &w, &h, &color))
		return NULL;
    vita2d_draw_rectangle(x, y, w, h, color);
    
    Py_RETURN_NONE;
}

static PyObject *circle(PyObject *self, PyObject* pArgs) {

    float x, y, r;
    unsigned int color = 0xFFFFFFFF; // Default Color (White)
    if(!PyArg_ParseTuple(pArgs, "fff|I", &x, &y, &r, &color))
		return NULL;
    vita2d_draw_fill_circle(x, y, r, color);
    Py_RETURN_NONE;
}



static PyMethodDef graphics_methods[] = {
   { "init", (PyCFunction)init, METH_NOARGS, "Initialize Graphics"},
   { "begin", (PyCFunction)begin, METH_NOARGS, "Begin Drawing"},
   { "end", (PyCFunction)end, METH_NOARGS, "End Drawing"},
   { "rectangle", (PyCFunction)rectangle, METH_VARARGS, "Draw Rectangle"},
   { "circle", (PyCFunction)circle, METH_VARARGS, "Draw Circle"},
   { NULL, NULL, 0, NULL }
};

PyMODINIT_FUNC
initppv_graphics_vita2d(void)
{
    PyObject *m;
    m = Py_InitModule3("ppv.graphics.vita2d", graphics_methods, "Vita2D Module");
    if (m == NULL)
        return;
}