ReynDisqus

Disqus Qt App

Project content :
	- /bin folder: For project compilation.
	- /qml folder: QML sources (for UI).
		- qml.pri: Project subfile for UI stuff.
	- /res folder: Resources.
		- res.pri: Project subfile for resources stuff
	- /src foler: C++ sources.
		- sources.pri: Project subfile where C++ source files are registered.
	- README.md: This README.

Building project :

Be careful about tokens. I do not put my own tokens in the sources.

For Windows:

The targeted compiler is MSVC 2013.

```
qmake.exe ReynDisqus.pro -r -spec win32-msvc2013
# add "CONFIG+=debug" "CONFIG+=qml_debug" for debug
# add "CONFIG+=qml_debug" "CONFIG+=force_debug_info" "CONFIG+=separate_debug_info" for profiling
cd bin\Desktop
jom.exe # Or make.exe
cd ..\..
```

Building doc:

TODO


Images (CC 3.0 license):

"Map Marker" by Naomi Atkinson: https://thenounproject.com/term/map-marker/5624
"Clock" by James Rainsford: https://thenounproject.com/term/clock/17709
