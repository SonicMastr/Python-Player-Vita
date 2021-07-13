#include <stdlib.h>
#include <python2.7/Python.h>

int _newlib_heap_size_user = 192 * 1024 * 1024;
unsigned int sceLibcHeapSize = 2 * 1024 * 1024;

PyMODINIT_FUNC init_audiodec();
PyMODINIT_FUNC init_audioenc();
PyMODINIT_FUNC init_audioin();
PyMODINIT_FUNC init_audioout();
PyMODINIT_FUNC init_avplayer();
PyMODINIT_FUNC init_camera();
PyMODINIT_FUNC init_common_dialog();
PyMODINIT_FUNC init_ctrl();
PyMODINIT_FUNC init_display();
PyMODINIT_FUNC init_EGL();
PyMODINIT_FUNC init_GLES2();
PyMODINIT_FUNC init_gxm();
PyMODINIT_FUNC init_modulemgr();
PyMODINIT_FUNC init_motion();
PyMODINIT_FUNC init_net();
PyMODINIT_FUNC init_netctl();
PyMODINIT_FUNC init_pib();
PyMODINIT_FUNC init_power();
PyMODINIT_FUNC init_pspnet_adhoc();
PyMODINIT_FUNC init_pspnet_adhocctl();
PyMODINIT_FUNC init_SDL2_image();
PyMODINIT_FUNC init_SDL2_mixer();
PyMODINIT_FUNC init_SDL2_net();
PyMODINIT_FUNC init_SDL2_ttf();
PyMODINIT_FUNC init_SDL2();
PyMODINIT_FUNC init_sysmodule();
PyMODINIT_FUNC init_touch();
PyMODINIT_FUNC init_vita2d();

static struct _inittab builtins[] = {
	{"_audiodec", init_audiodec},
	{"_audioenc", init_audioenc},
	{"_audioin", init_audioin},
	{"_audioout", init_audioout},
	{"_avplayer", init_avplayer},
	{"_camera", init_camera},
	{"_common_dialog", init_common_dialog},
	{"_ctrl", init_ctrl},
	{"_display", init_display},
	{"_EGL", init_EGL},
	{"_GLES2", init_GLES2},
	{"_gxm", init_gxm},
	{"_modulemgr", init_modulemgr},
	{"_motion", init_motion},
	{"_net", init_net},
	{"_netctl", init_netctl},
	{"_pib", init_pib},
	{"_power", init_power},
	{"_pspnet_adhoc", init_pspnet_adhoc},
	{"_pspnet_adhocctl", init_pspnet_adhocctl},
	{"_SDL2_image", init_SDL2_image},
	{"_SDL2_mixer", init_SDL2_mixer},
	{"_SDL2_net", init_SDL2_net},
	{"_SDL2_ttf", init_SDL2_ttf},
	{"_SDL2", init_SDL2},
	{"_sysmodule", init_sysmodule},
	{"_touch", init_touch},
	{"_vita2d", init_vita2d},
	{NULL, NULL}};

int SDL_main()
{
}

int main()
{

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

	PySys_SetPath("app0:lib/python27.zip;app0:lib/python2.7;ux0:/data/lib/python27.zip;ux0:/data/lib/python2.7"); // Set the Paths for our Modules

	PyRun_SimpleString("import sys\n");
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
