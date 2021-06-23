#include <stdlib.h>
#include <python2.7/Python.h>
#include <psp2/gxm.h>
#include <psp2/display.h>
#include <psp2/kernel/modulemgr.h>
#include <psp2/kernel/clib.h>

typedef struct DisplayData {
	void *address;
} DisplayData;

void displayCallback(const void *callbackData)
{
	SceDisplayFrameBuf framebuf;

	const DisplayData *displayData = (const DisplayData *)callbackData;

	memset(&framebuf, 0x00, sizeof(SceDisplayFrameBuf));
	framebuf.size        = sizeof(SceDisplayFrameBuf);
	framebuf.base        = displayData->address;
	framebuf.pitch       = 1024;
	framebuf.pixelformat = SCE_DISPLAY_PIXELFORMAT_A8B8G8R8;
	framebuf.width       = 960;
	framebuf.height      = 544;
	sceDisplaySetFrameBuf(&framebuf, SCE_DISPLAY_SETBUF_NEXTFRAME);

	sceDisplayWaitVblankStart();
}

static PyObject *init(PyObject *self, PyObject* pArgs) {

    SceGxmInitializeParams initParams;
    sceClibMemset(&initParams, 0, sizeof(SceGxmInitializeParams));
    initParams.flags							= 0;
	initParams.displayQueueMaxPendingCount	    = 2;
	initParams.displayQueueCallback			    = displayCallback;
	initParams.displayQueueCallbackDataSize	    = sizeof(DisplayData);
	initParams.parameterBufferSize			    = SCE_GXM_DEFAULT_PARAMETER_BUFFER_SIZE;

    int ret = sceGxmInitialize(&initParams);
    if (ret)
        return PyErr_Format(PyExc_RuntimeError, "Failed to Initialize GXM: 0x%08x", ret);
    
    Py_RETURN_NONE;
}

static PyMethodDef gxm_methods[] = {
   { "init", (PyCFunction)init, METH_VARARGS, "Initialize GXM"},
   { NULL, NULL, 0, NULL }
};

PyMODINIT_FUNC
initppv_graphics_gxm(void)
{
    PyObject *m;
    m = Py_InitModule3("ppv.graphics.gxm", gxm_methods, "GXM Module");
    if (m == NULL)
        return;
}
