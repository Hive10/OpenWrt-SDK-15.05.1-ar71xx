#
# Copyright (C) 2017 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=jose
PKG_VERSION:=7
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://github.com/latchset/$(PKG_NAME)/releases/download/v$(PKG_VERSION)/
PKG_HASH:=2bb1d228944de62140403aacb874fe2cfbfbf979d6362fedb39427f1b1d2a702

PKG_INSTALL:=1
PKG_BUILD_PARALLEL:=1

PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/jose
  SECTION:=libs
  TITLE:=Provides a full crypto stack including key generation, signing and encryption.
  DEPENDS:=+zlib +jansson +libopenssl +libpthread
  URL:=https://github.com/latchset/jose
  MAINTAINER:=Tibor Dudlák <tibor.dudlak@gmail.com>
endef

define Package/jose/description
	José is a command line utility for performing various tasks on JSON
	Object Signing and Encryption (JOSE) objects. José provides a full
	crypto stack including key generation, signing and encryption.
endef

CFLAGS += -fhonour-copts
TARGET_CFLAGS += -std=gnu99 $(FPIC)
TARGET_LDFLAGS += -Wl,-rpath-link=$(1)/usr/lib

MAKE_FLAGS += LD="$(TARGET_CC) -o"

define Build/Configure
	cd $(PKG_BUILD_DIR);
	$(call Build/Configure/Default)
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/{lib,include}
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/lib$(PKG_NAME).so* 			$(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/lib$(PKG_NAME)-openssl.so* 		$(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/lib$(PKG_NAME)-zlib.so* 		$(1)/usr/lib
	$(INSTALL_DIR)	$(1)/usr/include/$(PKG_NAME)/
	$(CP) $(PKG_INSTALL_DIR)/usr/include/$(PKG_NAME)/*.h			$(1)/usr/include/$(PKG_NAME)/
	$(INSTALL_DIR)	$(1)/usr/lib/pkgconfig
	$(CP) $(PKG_BUILD_DIR)/*.pc						$(1)/usr/lib/pkgconfig
endef


define Package/joselib/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/lib$(PKG_NAME).so* 			$(1)/usr/lib/
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/lib$(PKG_NAME)-openssl.so* 		$(1)/usr/lib/
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/lib$(PKG_NAME)-zlib.so* 		$(1)/usr/lib/
endef

define Package/josetool/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/$(PKG_NAME) 			$(1)/usr/bin/
endef

$(eval $(call BuildPackage,jose))
