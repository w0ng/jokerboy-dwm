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
source=("${pkgname}-${pkgver}.tar.gz::http://git.suckless.org/dwm/snapshot/dwm-master.tar.bz2"
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
sha256sums=('f03e601f9bd2accec72ebe1a7d35f0994a859b527a4be36fdbd11bb8774bb6df'
            'aa1ab98d9ab0de32337e7550c132860d39add78f22067f97ba04ca0e2a4d6413'
            'fddfa0154d942111f56d12eb20f9c9d2942c40373ba22c90c3431a1cc0499a8e'
            'cae33cda301b75306a381bf7acce4a4f596a887514c2a8fb39458cf4084bda7c'
            'db3b59de7b1240d40caa087f56fdf61542af3ffe7ed8287f82ced2df6ecf974e'
            '5c9a19f83b07467b40c7e2af145a5074782a6ee29b761a22717175badbf1b6d5'
            'e7a52355a2df3cd6a84bf44deb4ae85e9affd0c0a71d1131356d98c0c73b9791'
            '4446773a6d3d74e2525ac9d35ca2f7cccb071bc6894136cdb3c17abdf8fb799c'
            '500a0219119ecfa09a982a2b335ab4289ff3e65b8042f73aafbc42955e507658'
            '739a11a6432132fb839e844ca8287aa7d1c0f2b1bf5a418878cf8f2df58ac418'
            'a0801f59e9eea645d8e1d5d9e8b9ff247963e795dd5431e092238bcb9e78226b'
            'f0be6d13e9e5cae92c38b2ffe8071b4f7f5123e1463e55bcc5e0525a5d4fb96d'
            '23bcc5b5568c14140b1f45647648eb7392dc69b6ec9a799012f8b944b027feb2'
            'bb2a785082646c65719ce1fa3701c7b74dcbf11ecd559d3cd95470b6a88aeec4'
            '6ef302941bd0829ff36a1ba0ca7b44534f7172a09bfcbac10e675c3fe64d4861'
            '2d44e6a79bdd4e2c30a11dbffe5701574f3799ae5f6a15b6c82edab52c265769'
            'ffdff7f2c60378f46973be615a4df3aa41ed4d6aa3aa804e5eb6cda967d1bd54'
            'd7e9a5ca6f46c1e60d5fd6d3ec16162472ebd0b7be7567f861a542234bcfb8dc'
            'f2c81fde0f2b8c95d0e23a42d261a50038d453f33da8c98ff48a6bcd8bbd147a'
            '3a06767c1d2951b8e560c24538b39fbc59a4e140ef1e0f3faef2061ccc075ce3'
            '2a4b8aa626a16052637aff9b918f11c3262a03c70d421c9c5d1b90ceec9e3927'
            '0c2c198a604c46f7940355736bba9184f7e3b379720ce7e4e6d588c94e1aec90')

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
