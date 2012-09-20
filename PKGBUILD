#Homepage: http://hg.punctweb.ro

pkgname=dwm
pkgver=6.0
pkgrel=1
pkgdesc='A dynamic window manager for X'
url='http://dwm.suckless.org'
arch=('i686' 'x86_64')
license=('MIT')
options=('zipman')
depends=('libx11' 'libxinerama' 'dmenu')
source=("${pkgname}-${pkgver}.tar.gz::http://hg.suckless.org/${pkgname}/archive/tip.tar.gz"
        "config.h"
        "01-${pkgname}-${pkgver}-pertag2.diff"
        "02-${pkgname}-${pkgver}-push.diff"
        "03-${pkgname}-${pkgver}-cycle.diff"
        "04-${pkgname}-${pkgver}-gaplessgrid.diff"
        "05-${pkgname}-${pkgver}-pidgin.diff"
        "06-${pkgname}-${pkgver}-monocle_count.diff"
        "07-${pkgname}-${pkgver}-monocle_borderless.diff"
        "08-${pkgname}-${pkgver}-clicktofocus.diff"
        "09-${pkgname}-${pkgver}-viewontag.diff"
        "10-${pkgname}-${pkgver}-scratchpad.diff"
        "11-${pkgname}-${pkgver}-togglemax.diff"
        "12-${pkgname}-${pkgver}-autoresize.diff"
        "13-${pkgname}-${pkgver}-increase_mfact_limit.diff"
        "14-${pkgname}-${pkgver}-remember-tags.diff"
        "15-${pkgname}-${pkgver}-centred-floating.diff"
        "16-${pkgname}-${pkgver}-focusurgent.diff"
        "17-${pkgname}-${pkgver}-statuscolors.diff"
        "18-${pkgname}-${pkgver}-save_floats.diff"
        "19-${pkgname}-${pkgver}-systray.diff"
        "20-${pkgname}-${pkgver}-centerwindow.diff")
sha256sums=('bb5c4bb7ba052a5498118eeb571165997f7dae62580c1be1a5cdf11e03bc8127'
            '6513684846202bc99dcfb9b3e5cb10c9940703abfda464b649e5ba4cf22fd37e'
            '9a24dd83b6dbf66807f4c5eaff5e308cdcfbdb19491bf5a9a3c5d968bbac856e'
            '4b133507f4b477f7a294d070169c363baf9366779e33c6b1ea1dc33e61b14979'
            '31adb170989315b20e820933a239f688331b931a242544c0650127fba926579e'
            '60c13c3de317077e4c59889060fe980276bb29ee9923d9684d1ffb297b1fe7a5'
            '825d7d81648c0151d9129e260ba6e5bd746be0aba66ad2d8682a0465269e05d0'
            'dcf6898c1695410d2a513beebe94d034e45f7414362c46e53802c5152bb0839c'
            '65fce4568887913c5af34e0dc22fca17b5eaac8075644748bfdef6dcf61937c4'
            '42d2a1c8ffdecdecfd0185fd98da8096b5a417dfcdf4874bb4c50594fae9712c'
            '5f2fa14cd829dd780341d33b695201a739969d0fe77866244c6bff6c55e11c9f'
            '328578d3e53c1ec4110c1927b5d7dc3eb38d66d9b96f3aa22ca19f1203eaf4d0'
            '1036125769ce44b2116e76f0cfae65cab921ca08b88521b15b37a280fd4cc666'
            '69b4f62297860b7a2d5afe563e3d9eacdcb913f96cb97cc1ec920168de59150a'
            'e7c0ea64be99c9f8dfadec13e1cacdb1fa5624477db18a2e670cd81ff4941fa1'
            'f5b0f051897249abfadba43357385b2f880693a7b301871c2827a63b8f3f9cfe'
            'ad3f6ca7d05922a463eeb6cc31772ae509d5624ecf738ba50219bd74ce4e7da8'
            '77f494f11e1b1c6c7037a1a7385ee4c1fa0d1e8d689d57d7e196203bc9ff74e6'
            '871e9d7113a5a63edae75762c351214dc6496347eb0c6bdaa1f76d3759b8e4c5'
            '2d5de1197e20a4c12b06b38effa03a69c6022e2b6a4483c37ccb5b4430dfd36a'
            'd8cf91eac06b51aef6c6343546378b4fd021290f529119455e6debe583aaea27'
            'fb1dcef708397e1372e4a5e6733136189053d7b4dfc689accfd85246f314e704')

build() {
  cd "${srcdir}" && cd "`find . -type d -name dwm-\*`"
  if [ "${dwm_patch:-1}" == 1 ]; then
    cp "${srcdir}/config.h" config.h
    for PATCH in "${source[@]:2}"; do
      msg "${PATCH##*/}" && patch -Np1 -i "${srcdir}/${PATCH##*/}"
    done
  fi
  sed -i \
    -e 's/^CPPFLAGS =/CPPFLAGS +=/g' \
    -e 's/^CFLAGS   =/CFLAGS   +=/g' \
    -e 's/^LDFLAGS  =/LDFLAGS  +=/g' \
    -e 's/-O[s0-3]/-O2/g' \
    config.mk
  make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11
}

package() {
  cd "${srcdir}" && cd "`find . -type d -name dwm-\*`"
  make PREFIX=/usr DESTDIR="${pkgdir}" install
  install -m644 -D LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
  install -m644 -D README "${pkgdir}/usr/share/doc/${pkgname}/README"
}
