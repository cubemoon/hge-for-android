LOCAL_PATH := $(call my-dir)

###########################
#
# SDL shared Lib
#
###########################

include $(CLEAR_VARS)

LOCAL_MODULE := SDL

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../../lib/SDL/include

LOCAL_SRC_FILES := \
	$(subst $(LOCAL_PATH)/,, \
	$(wildcard $(LOCAL_PATH)/../../../../lib/SDL/src/*.c) \
	$(wildcard $(LOCAL_PATH)/../../../../lib/SDL/src/audio/*.c) \
	$(wildcard $(LOCAL_PATH)/../../../../lib/SDL/src/audio/android/*.c) \
	$(wildcard $(LOCAL_PATH)/../../../../lib/SDL/src/audio/dummy/*.c) \
	$(LOCAL_PATH)/../../../../lib/SDL/src/atomic/SDL_atomic.c \
	$(LOCAL_PATH)/../../../../lib/SDL/src/atomic/SDL_spinlock.c.arm \
	$(wildcard $(LOCAL_PATH)/../../../../lib/SDL/src/core/android/*.cpp) \
	$(wildcard $(LOCAL_PATH)/../../../../lib/SDL/src/cpuinfo/*.c) \
	$(wildcard $(LOCAL_PATH)/../../../../lib/SDL/src/events/*.c) \
	$(wildcard $(LOCAL_PATH)/../../../../lib/SDL/src/file/*.c) \
	$(wildcard $(LOCAL_PATH)/../../../../lib/SDL/src/haptic/*.c) \
	$(wildcard $(LOCAL_PATH)/../../../../lib/SDL/src/haptic/dummy/*.c) \
	$(wildcard $(LOCAL_PATH)/../../../../lib/SDL/src/joystick/*.c) \
	$(wildcard $(LOCAL_PATH)/../../../../lib/SDL/src/joystick/android/*.c) \
	$(wildcard $(LOCAL_PATH)/../../../../lib/SDL/src/loadso/dlopen/*.c) \
	$(wildcard $(LOCAL_PATH)/../../../../lib/SDL/src/power/*.c) \
	$(wildcard $(LOCAL_PATH)/../../../../lib/SDL/src/render/*.c) \
	$(wildcard $(LOCAL_PATH)/../../../../lib/SDL/src/render/*/*.c) \
	$(wildcard $(LOCAL_PATH)/../../../../lib/SDL/src/stdlib/*.c) \
	$(wildcard $(LOCAL_PATH)/../../../../lib/SDL/src/thread/*.c) \
	$(wildcard $(LOCAL_PATH)/../../../../lib/SDL/src/thread/pthread/*.c) \
	$(wildcard $(LOCAL_PATH)/../../../../lib/SDL/src/timer/*.c) \
	$(wildcard $(LOCAL_PATH)/../../../../lib/SDL/src/timer/unix/*.c) \
	$(wildcard $(LOCAL_PATH)/../../../../lib/SDL/src/video/*.c) \
	$(wildcard $(LOCAL_PATH)/../../../../lib/SDL/src/video/android/*.c))

LOCAL_LDLIBS := -ldl -lGLESv1_CM -llog

include $(BUILD_SHARED_LIBRARY)
