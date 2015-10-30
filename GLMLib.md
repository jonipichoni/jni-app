# Introduction #

GLM Lib: http://glm.g-truc.net/
OpenGL Mathematics (GLM) is a header only C++ mathematics library for graphics software based on the OpenGL Shading Language (GLSL) specification and released under the MIT license.

This will give us the suitable data structures to deal with OpenGL interface.

Examples [HERE](http://glm.g-truc.net/0.9.4/code.html)

# Lib #

Project Version: 0.9.4.6
File:  http://sourceforge.net/projects/ogl-math/files/glm-0.9.4.6/

## Folder Structure ##
```
~/jni-app/jni$ tree
.
├── Android.mk
├── Application.mk
├── GL2JNIActivity.cpp
├── gl_code.cpp
└── libs
    └── glm
        ├── core
        │   ├── _detail.hpp
        │   ├── dummy.cpp
        │   ├── _fixes.hpp
        │   ├── func_common.hpp
        │   ├── func_common.inl
...
```

# NDK #

## Android.mk ##
External libs files will be under libs folder on LOCAL\_PATH.
```
# 3rd party libs
LOCAL_C_INCLUDES := $(LOCAL_PATH)/libs
```

## Application.mk ##
We need to force the application to use gnustl\_static in order to
use glm lib as it has some dependencies in gnu stl. More info:
[gamedev-thread](http://gamedev.stackexchange.com/questions/47128/android-ndk-build-cant-find-glm-headers)
```
APP_STL := gnustl_static
```

## Eclipse ##
If we want to make this lib visible into the eclipse to clear include errors:
Go to project->properties->C/C++ General->Paths and Symbols
make sure the following directories are included:
$(LOCAL\_PATH)/libs  (replace LOCAL\_PATH)

## Git ##
Libs folder is included in gitignore so will no be added in the version control system.