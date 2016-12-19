include $(THEOS)/makefiles/common.mk

ARCHS = arm64

BUNDLE_NAME = wcreopt
wcreopt_FILES = WCRERootListController.m
wcreopt_INSTALL_PATH = /Library/PreferenceBundles
wcreopt_FRAMEWORKS = UIKit
wcreopt_PRIVATE_FRAMEWORKS = Preferences
wcreopt_EXTRA_FRAMEWORKS = Preferences
wcreopt_LDFLAGS=-stdlib=libc++

include $(THEOS_MAKE_PATH)/bundle.mk

internal-stage::
	$(ECHO_NOTHING)mkdir -p $(THEOS_STAGING_DIR)/Library/PreferenceLoader/Preferences$(ECHO_END)
	$(ECHO_NOTHING)cp entry.plist $(THEOS_STAGING_DIR)/Library/PreferenceLoader/Preferences/wcreopt.plist$(ECHO_END)
