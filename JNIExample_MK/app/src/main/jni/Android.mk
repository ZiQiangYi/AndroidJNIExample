LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := jniMain

LOCAL_SRC_FILES := jniMain.cpp

LOCAL_LDLIBS := -llog

LOADL_LDFLAGS += -Wl, --export-dynamic

include $(BUILD_SHARED_LIBRARY)
