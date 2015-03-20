LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../../../Libs/SDL2-2.0.3
SDL_IMAGE_PATH := ../../../Libs/SDL2_image-2.0.0
SDL_MIXER_PATH := ../../../Libs/SDL2_mixer-2.0.0
SDL_TTF_PATH := ../../../Libs/SDL2_ttf-2.0.12

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(SDL_IMAGE_PATH)
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(SDL_MIXER_PATH)
LOCAL_C_INCLUDES += $(LOCAL_PATH)/$(SDL_TTF_PATH)
LOCAL_C_INCLUDES += $(LOCAL_PATH)/AGameEngineCore
LOCAL_C_INCLUDES += $(LOCAL_PATH)/AGame
LOCAL_C_INCLUDES += ${ANDROID_NDK_ROOT}\sources\cxx-stl\stlport\stlport

# Add your application source files here...
LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.c \
$(patsubst $(LOCAL_PATH)/%, %, $(wildcard $(LOCAL_PATH)/*.cpp)) \
$(patsubst $(LOCAL_PATH)/%, %, $(wildcard $(LOCAL_PATH)/**/*.cpp)) \
$(patsubst $(LOCAL_PATH)/%, %, $(wildcard $(LOCAL_PATH)/*.c))\
	main.c


LOCAL_SHARED_LIBRARIES := SDL2 SDL2_image SDL2_mixer SDL2_ttf

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog

include $(BUILD_SHARED_LIBRARY)
