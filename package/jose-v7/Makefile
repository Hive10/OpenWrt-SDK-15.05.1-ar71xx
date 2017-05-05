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

PKG_INSTALL:=1
PKG_BUILD_PARALLEL:=1

CFLAGS += -std=c99 -fhonour-copts $(FPICS)  
TARGET_CFLAGS += 
TARGET_LDFLAGS+=-Wl,-rpath-link=$(1)/usr/lib

PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/jose
  SECTION:=utils
  TITLE:=jose v$(PKG_VERSION)
  DEPENDS:=+zlib +jansson-2.9 +openssl
  URL:=https://github.com/latchset/jose
endef


define Package/jose/description
	José is a command line utility for performing various tasks on JSON
	Object Signing and Encryption (JOSE) objects. José provides a full
	crypto stack including key generation, signing and encryption.
endef

ifeq ($(CONFIG_x86_64),y)
  JOSE_TARGET:=linux-x86_64
else
  ifeq ($(CONFIG_mips)$(CONFIG_mipsel),y)
    JOSE_TARGET:=mips-openwrt-linux-uclibc
  else
    JOSE_TARGET:=linux-generic-openwrt
  endif
endif

define Build/Configure
(	cd $(PKG_BUILD_DIR); \
		./configure \
			--host=$(JOSE_TARGET) \
			--prefix=/usr/ ; \
)
endef


define Package/jose/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/bin/$(PKG_NAME) $(1)/usr/bin/
endef

$(eval $(call BuildPackage,jose))
