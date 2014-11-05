LOCAL_PATH := $(call my-dir)

#Initialize LOCAL_ vars
include $(CLEAR_VARS)
# LOCAL_CFLAGS			# A set of C compiler flags passed when compiling any C or C++ source code of any of the module
#-Wextra        		# turn on extra warnings
#-Werror        		# treat warnings as errors
#-Wno-unused-parameter 	# unused-parameter not as warning
#-Wno-unused-function 	# unused-function not as warning 				
LOCAL_CFLAGS := -Wextra \
				-Wno-unused-parameter \
				-Wno-unused-function  \
				-frtti
LOCAL_MODULE    := libBBgame
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include \
					$(LOCAL_PATH)/libs

FILE_LIST := $(wildcard $(LOCAL_PATH)/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/src/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/src/*/*.cpp)
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)
                   	
LOCAL_LDLIBS    := -llog -landroid -lGLESv2 -lz
LOCAL_STATIC_LIBRARIES := libpng

#INCLUDE LOCAL_ in the makefile target
include $(BUILD_SHARED_LIBRARY)

# Android Sources
$(call import-module,libpng)

