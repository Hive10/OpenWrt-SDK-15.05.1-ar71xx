
include $(TOPDIR)/rules.mk

# Name and release number of this package
PKG_NAME:=jansson
PKG_VERSION:=2.10
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://www.digip.org/jansson/releases/
PKG_MD5SUM:=16a2c4e84c0a80ca61bd6e619a0f9358

PKG_INSTALL:=1
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk

define Package/jansson
	SECTION:=libs
	CATEGORY:=Libraries
	TITLE:=JSON library
endef

define Package/jansson-v2.10/description
	Jansson is a C library for encoding, decoding and manipulating JSON data.
endef

CONFIGURE_ARGS+= LIBS="-Wl,-rpath-link=$(STAGING_DIR)/usr/lib"

TARGET_CFLAGS += $(FPIC)


define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/{lib,include}
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libjansson* $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/include/* $(1)/usr/include/
endef


define Package/jansson/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libjansson*so* $(1)/usr/lib/
endef

$(eval $(call BuildPackage,jansson))

