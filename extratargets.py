#!/usr/bin/python3

# -*-coding:Utf-8 -*

import os
import os.path as ospath
import shutil
from sys import argv as argz
from fnmatch import fnmatch as extmatch

# Project root
projectpaths = {
	"root": os.getcwd(),
	"bin": "bin",
	"doc": "doc"
}
projectrootpath = os.getcwd()

# Internal script stuff

def rmdir(folder, keepGitkeep=True):
	return
# End rmdir()

# Actions for rules

# Actions map
actionz = {
	"cleanandroid": cleanAndroid,	# Cleans Android build
	"cleandoc":     cleanDoc     	# Cleans documentation
}

def cleanAndroid(profile):
	return
# End cleanAndroid()

def cleanDoc():
	return
# End cleanDoc()

def main():
	"""Main func for this script"""
	argc = len(argz)
	
	if argc < 2 :
		print("Usage : [python3] extratargets.py action arg1 [arg2 ... argN]")
	return

	action = argz[1]

	if action in actionz.keys():
		actionz[action](*argz[2:])
	else:
		print("Unknown action for '{0}'. Available actions are : {1}.".format(action, ", ".join(actionz.keys())))
# End main()

if __name__ == '__main__':
	main()
