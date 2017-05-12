#
# Copyright (C) 2017 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=tang
PKG_VERSION:=4
PKG_RELEASE:=1

#PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
#PKG_SOURCE_URL:=https://github.com/latchset/$(PKG_NAME)/releases/download/v$(PKG_VERSION)/

PKG_INSTALL:=1
PKG_BUILD_PARALLEL:=1

PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/tang
  SECTION:=utils
  TITLE:=tang v$(PKG_VERSION) - daemon for binding data to the presence of a third party
  DEPENDS:=+http-parser +xinetd +jose
  URL:=https://github.com/latchset/tang
endef

CFLAGS += -fhonour-copts 
TARGET_CFLAGS += $(FPIC) -std=gnu99 -I$(1)/usr/include 
TARGET_LDFLAGS += -Wl,-rpath-link=$(1)/usr/lib

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Package/tang/description
	Tang is a small daemon for binding data to the presence of a third party.
endef

define Build/Configure
	(cd $(PKG_BUILD_DIR); touch \
	include.m4 \
	Makefile.in \
	);
	$(call Build/Configure/Default)
endef

define Package/tang/install
	$(INSTALL_DIR) $(1)/usr/libexec
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/$(PKG_NAME)d 		$(1)/usr/libexec/
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/$(PKG_NAME)d-update	$(1)/usr/libexec/
	mkdir -p $(1)/etc/xinetd.d/
	$(CP) $(PKG_BUILD_DIR)/tangd.xinetd 				$(1)/etc/xinetd.d/
	mkdir -p $(1)/var/db/tang/
endef

$(eval $(call BuildPackage,tang))
