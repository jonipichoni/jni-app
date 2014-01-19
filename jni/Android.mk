# Copyright (C) 2010 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH := $(call my-dir)

#Initialize LOCAL_ vars
include $(CLEAR_VARS)

LOCAL_MODULE    := native-activity
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include \
					$(LOCAL_PATH)/libs
                   # $(LOCAL_PATH)/include/glm
                

LOCAL_SRC_FILES := 	src/main.cpp \
					src/Configuration.cpp \
					src/ShaderFactory.cpp \
		   			src/GLESApplication.cpp \
                   	src/GLESDemo.cpp \
                   	src/Cube.cpp \
                   	src/res_texture.c

#LOCAL_LDFLAGS	:= -Wl,-Map=native-activity.map  


LOCAL_LDLIBS    := -llog  -landroid -lEGL -lGLESv2 

LOCAL_STATIC_LIBRARIES := android_native_app_glue

#INCLUDE LOCAL_ in the makefile target
include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/native_app_glue)

