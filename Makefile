THEOS_DEVICE_IP = localhost
THEOS_DEVICE_PORT = 2022
ARCHS = armv7 arm64
TARGET = iphone:latest:7.0

include theos/makefiles/common.mk

TWEAK_NAME = WeChatRedEnvelop
WeChatRedEnvelop_FILES = Tweak.xm Debug.mm info.cpp
WeChatRedEnvelop_FRAMEWORKS = UIKit AudioToolbox

include $(THEOS_MAKE_PATH)/tweak.mk

after-install::
	install.exec "killall -9 WeChat"
