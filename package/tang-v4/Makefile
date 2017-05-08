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
  DEPENDS:=+jose +http_parser +xinetd
  URL:=https://github.com/latchset/tang
endef

TARGET_CFLAGS += $(FPIC)

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Package/tang/description
	Tang is a small daemon for binding data to the presence of a third party.
endef

ifeq ($(CONFIG_x86_64),y)
  TANG_TARGET:=linux-x86_64
else
  ifeq ($(CONFIG_mips)$(CONFIG_mipsel),y)
    TANG_TARGET:=mips-openwrt-linux-uclibc
  else
    TANG_TARGET:=linux-generic-openwrt
  endif
endif

CONFIGURE_ARGS +=       \
                         --prefix=/usr/ \
                         --host=$(JOSE_TARGET)

define Build/Configure
	(cd $(PKG_BUILD_DIR); touch \
	include.m4 \
	Makefile.in \
	);
	$(call Build/Configure/Default)
endef


define Package/tang/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/$(PKG_NAME) $(1)/usr/bin/
endef

$(eval $(call BuildPackage,tang))
