#include <stdlib.h>
#include <python2.7/Python.h>
#include <psp2/net/net.h>
#include <sys/socket.h>
#include <psp2/sysmodule.h>
#include <psp2/net/netctl.h>

int _newlib_heap_size_user = 192 * 1024 * 1024;

PyMODINIT_FUNC initppv_graphics();

#define NET_MEMORY (16 * 1024)

static char *memory[NET_MEMORY];

static struct _inittab builtins[] = {

    {"ppv_graphics", initppv_graphics},
    {NULL, NULL}
};

int main(int argc, char *argv[]) {
	(void)argc;
	(void)argv;

	SceNetInitParam initparam;
    int netinit;

    initparam.memory = memory;
    initparam.size = sizeof(memory);
    initparam.flags = 0;

	sceSysmoduleLoadModule(SCE_SYSMODULE_NET);

    netinit = sceNetInit(&initparam);
    if (netinit < 0)
		return -2;

    netinit = sceNetCtlInit();
    if (netinit < 0)
		return -1;

	Py_NoSiteFlag = 1;
    Py_IgnoreEnvironmentFlag = 1;
    Py_NoUserSiteDirectory = 1;
    Py_OptimizeFlag = 2;

	Py_SetProgramName("app0:eboot.bin");
	setenv("PYTHONHOME", "app0:", 1);
	setenv("HOME", "app0:", 1);
	//setenv("PYTHONTHREADDEBUG", "1", 1);
	PyImport_ExtendInittab(builtins);
	Py_InitializeEx(0);

	PyRun_SimpleString("import sys\nsys.path.append('ux0:/data/lib/python2.7')\nsys.path.append('ux0:/data/lib/python27.zip')\n");  // Add support for External Modules
	PyRun_SimpleString("import os\n");
	PyRun_SimpleString("print os.name\n");
	PyRun_SimpleString("print sys.platform\n");
	PyRun_SimpleString("print sys.path\n");
	PyRun_SimpleString("print sys.builtin_module_names\n");

	FILE *fp;
    fp = fopen("app0:main.py", "r");
    PyRun_SimpleFile(fp, "main.py");

	Py_Finalize();
	return 0;
}
