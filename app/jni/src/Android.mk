LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_CPP_FEATURES := rtti
LOCAL_MODULE := main
LOCAL_C_INCLUDES := ../SDL/include ../SDL_image/

LOCAL_SRC_FILES := main.cpp

LOCAL_SHARED_LIBRARIES := SDL2 SDL2_image
LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog
include $(BUILD_SHARED_LIBRARY)
