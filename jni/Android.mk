LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

# Local App
LOCAL_MODULE    := libgl2jni
LOCAL_CFLAGS    := -Werror
LOCAL_SRC_FILES := gl_code.cpp
LOCAL_LDLIBS    := -llog -lGLESv2

# 3rd party libs
LOCAL_C_INCLUDES := $(LOCAL_PATH)/libs

# for native asset manager
LOCAL_LDLIBS += -landroid

include $(BUILD_SHARED_LIBRARY)
