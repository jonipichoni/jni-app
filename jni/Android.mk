LOCAL_PATH := $(call my-dir)
TOP_PATH := $(call my-dir)

# Print on build - remove on deploy
#$(warning $(BT_PATH))
#$(warning $(LOCAL_PATH))
#$(warning $(TOP_PATH))

# Load bluetooth lib
include $(LOCAL_PATH)/bt_lib/Android.mk

#Initialize LOCAL_ vars
include $(CLEAR_VARS)

# LOCAL_CFLAGS                  # A set of C compiler flags passed when compiling any C or C++ source code of any of the module
#-Wextra                        # turn on extra warnings
#-Werror                        # treat warnings as errors
#-Wno-unused-parameter  # unused-parameter not as warning
#-Wno-unused-function   # unused-function not as warning                                
LOCAL_CFLAGS := -Wextra \
                -Werror \
                -Wno-unused-parameter \
                -Wno-unused-function  
LOCAL_PATH := $(TOP_PATH)
LOCAL_MODULE    := libBBgame
LOCAL_C_INCLUDES := $(TOP_PATH)/include \
					$(TOP_PATH)/libs \
					$(TOP_PATH)/bt_lib 

FILE_LIST := $(wildcard $(TOP_PATH)/*.cpp)
FILE_LIST += $(wildcard $(TOP_PATH)/src/*.cpp)
LOCAL_SRC_FILES := $(FILE_LIST:$(TOP_PATH)/%=%)
                      
LOCAL_LDLIBS    := -llog -landroid -lGLESv2 -lz
LOCAL_STATIC_LIBRARIES := libpng libbt

#INCLUDE LOCAL_ in the makefile target
include $(BUILD_SHARED_LIBRARY)

# Android Sources
$(call import-module,libpng)
