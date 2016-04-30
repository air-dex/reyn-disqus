# python.pri

#--------------------------------------------#
# Python 3 Script with extra targets scripts #
#--------------------------------------------#

DISTFILES += extratargets.py

# Write your own path to python.exe here
win32 {
	PYTHON3_EXEC = C:\\Python32\\python.exe
} else:linux-g++ {
	PYTHON3_EXEC = /usr/bin/python3
}

PYTHON_SCRIPT_CMD = $${PYTHON3_EXEC} $$system_path($${PWD}/extratargets.py)
