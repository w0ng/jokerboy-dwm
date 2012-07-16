dwm_patch=${dwm_patch:-1}

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
        "19-${pkgname}-${pkgver}-hasborder.diff")
sha256sums=('dd933101f2108019a9aa4b117ed6137077e2292791f11c348caf4431ea84326c'
            'd1da36682d749580c0d7a3216f3d61b84b37de18b06da694269b3d9a637bdc05'
            '0dd29c9dc647312fb98445f64b0434fe063fd3327848e1c26050c689a95cb4e8'
            'b2e7d373ae9c4fc78d4367af115283675269458b1d9578cc185827d108916806'
            'aab3e12f450602b1ffa243e22f64b12f954ab0d1f8982e9cc831111f8b763261'
            '85c6ed2f303b85d94f6314100cd3d8e3247b461e1e8d96f4a61c4dac8333ca6f'
            '71a29f0c006c33814ec5f087b2ea7a1335cffad1034bd95984076a4ee161b6fc'
            'bcd8478adf8b9b14b006286411cb9c0d8508b1fa1cd5f7b4f920249577d1400c'
            'aac869dc6fb2dd08f26d40aaddf10d461ab8dfa2ff5546ca09266153920a1714'
            'fe4042782f98ca296bcd434e89ea43ff80abec746f8ccb0a5668fa2e3c4ddeee'
            'b60f5adadb448785d4ee84edb34a2421f200bad1b64f166b6043a5b96749ddd4'
            '10b36d6d36570881e4504af50fcfcc3fa6356cdb0e5ecf627dfca84bab84eb64'
            '1caeee472b3440b9c47aed57ab46e1bbb0408e2148e2383e4941cd79d8e86d7a'
            'a159d17c61d29b8607c3857bea1e9edd011f82b8a463abe15847f54a81f5498a'
            '61354392e2737506924cce85fce25c540bb9404bc63407266a1e79d5b12ddead'
            '0d19e5309af5e3b04810b6dea214da206cf7736816e29aa23bd073b0465842cd'
            'b1cd0f32fae0425ec49a02cffb8a64cde427d8a03201400cb1758d60763caf2d'
            '7bd1a03bec1e30813d74540161b8cae47b0ee610bb43930f5b4e689acb3af696'
            'da6d519c6ce95eb6517d9b88d2338ff6cdf3ef5f8c46dbc5136eab7ebaef8712'
            '6114f2d15954b2179ef2487b78a43bea94361a6c35561699f905e35493cff536'
            '68a79688b05fe97e4630ce89d28a5872af9ae91b8a1ee6d2a790cdda1c550b9c')

build() {
  cd "${srcdir}" && cd "`find . -type d -name dwm-\*`"
  if [ "${dwm_patch}" == 1 ]; then
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
