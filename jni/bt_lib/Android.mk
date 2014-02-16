# Local path is now this android.mk path
LOCAL_PATH := $(call my-dir)

# CLEAR LOCAL_* vars
include $(CLEAR_VARS)
LOCAL_MODULE := libbt

# @TODO we need to share my_log.h, best way? common include folder?
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../include

FILE_LIST_BT := $(wildcard $(LOCAL_PATH)/*.cpp)
FILE_LIST_BT += $(wildcard $(LOCAL_PATH)/src/*.cpp)
LOCAL_SRC_FILES := $(FILE_LIST_BT:$(LOCAL_PATH)/%=%)

LOCAL_LDLIBS    := -llog -landroid
include $(BUILD_SHARED_LIBRARY)