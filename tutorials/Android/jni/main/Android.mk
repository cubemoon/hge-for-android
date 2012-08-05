LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := main
LOCAL_CFLAGS := -DOS_ANDROID
LOCAL_CFLAGS := \
	-DPLAY_MOD

SRC_PATH := ../../../tutorial01
INC_PATH := $(LOCAL_PATH)../../../tutorial01	
	
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../../Lib/SDL/include \
					$(LOCAL_PATH)/../../../../include \
					$(INC_PATH)
					
# Add your application source files here...
LOCAL_SRC_FILES := 	common.c \
					SDL_android_main.cpp \
					$(SRC_PATH)/hge_tut01.cpp \
					$(SRC_PATH)/../../src/core/graphics.cpp \
					$(SRC_PATH)/../../src/core/ini.cpp \
					$(SRC_PATH)/../../src/core/input.cpp \
					$(SRC_PATH)/../../src/core/power.cpp \
					$(SRC_PATH)/../../src/core/random.cpp \
					$(SRC_PATH)/../../src/core/resource.cpp \
					$(SRC_PATH)/../../src/core/sound.cpp \
					$(SRC_PATH)/../../src/core/system.cpp \
					$(SRC_PATH)/../../src/core/target.cpp \
					$(SRC_PATH)/../../src/core/timer.cpp \
					$(SRC_PATH)/../../src/core/ZLIB/adler32.c \
					$(SRC_PATH)/../../src/core/ZLIB/crc32.c \
					$(SRC_PATH)/../../src/core/ZLIB/inffast.c \
					$(SRC_PATH)/../../src/core/ZLIB/inflate.c \
					$(SRC_PATH)/../../src/core/ZLIB/inftrees.c \
					$(SRC_PATH)/../../src/core/ZLIB/ioapi.c \
					$(SRC_PATH)/../../src/core/ZLIB/trees.c \
					$(SRC_PATH)/../../src/core/ZLIB/uncompr.c \
					$(SRC_PATH)/../../src/core/ZLIB/unzip.c \
					$(SRC_PATH)/../../src/core/ZLIB/zutil.c \
					$(SRC_PATH)/../../src/core/soil/image_DXT.cpp \
					$(SRC_PATH)/../../src/core/soil/image_helper.cpp \
					$(SRC_PATH)/../../src/core/soil/SOIL.cpp \
					$(SRC_PATH)/../../src/core/soil/stb_image_aug.cpp \
					$(SRC_PATH)/../../src/helpers/hgeanim.cpp \
					$(SRC_PATH)/../../src/helpers/hgecolor.cpp \
					$(SRC_PATH)/../../src/helpers/hgedistort.cpp \
					$(SRC_PATH)/../../src/helpers/hgefont.cpp \
					$(SRC_PATH)/../../src/helpers/hgegui.cpp \
					$(SRC_PATH)/../../src/helpers/hgeguictrls.cpp \
					$(SRC_PATH)/../../src/helpers/hgeparticle.cpp \
					$(SRC_PATH)/../../src/helpers/hgepmanager.cpp \
					$(SRC_PATH)/../../src/helpers/hgerect.cpp \
					$(SRC_PATH)/../../src/helpers/hgeresource.cpp \
					$(SRC_PATH)/../../src/helpers/hgesprite.cpp \
					$(SRC_PATH)/../../src/helpers/hgestrings.cpp \
					$(SRC_PATH)/../../src/helpers/hgevector.cpp \
					$(SRC_PATH)/../../src/helpers/parser.cpp \
					$(SRC_PATH)/../../src/helpers/resources.cpp
					
					
LOCAL_SHARED_LIBRARIES := SDL

LOCAL_LDLIBS := -lGLESv1_CM -llog


include $(BUILD_SHARED_LIBRARY)




