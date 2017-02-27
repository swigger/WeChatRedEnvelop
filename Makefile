THEOS_DEVICE_IP = localhost
THEOS_DEVICE_PORT = 2022
ARCHS = arm64
TARGET = iphone:latest:7.0
_THEOS_PLATFORM_DPKG_DEB_COMPRESSION=gzip

include theos/makefiles/common.mk

TWEAK_NAME = WeChatRedEnvelop
WeChatRedEnvelop_FILES = Tweak.xm Debug.mm info.cpp xpruntime.c
WeChatRedEnvelop_FRAMEWORKS = UIKit AudioToolbox
#WeChatRedEnvelop_CPPFLAGS=-std=c++11
CCFLAGS=-std=c++11

include $(THEOS_MAKE_PATH)/tweak.mk

after-install::
	- install.exec "killall -9 WeChat Preferences"
SUBPROJECTS += wcreopt
include $(THEOS_MAKE_PATH)/aggregate.mk
