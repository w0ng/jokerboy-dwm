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
            '0aaacdcc9862530c00ed2e871bc9184696083bf23d77b6adda2142ce7ac62d2b'
            '3f75f08692af6be293dc5c2218094b550409c3d8045243ccee6e0e33d043c157'
            '2ba86ae4b9c8004dc13e5fe38f30fb3ac471b2e86f3a998796171739574678f8'
            'a6c9ab6cba332f08f3ca4672507e5804c8fc1855816c44abb799762c7677ba86'
            '3b3ca4efaca91ac2d7c307e4510fe26585a49b3eb6cb3505f277e3ed7507f665'
            '7899bb947553c3b21b472ad4e9401271f93d04d0b5759a3f28701570bd791f56'
            '774e08339285fa79059999895e8b2419346329572fc1f43ad07a467c69afd71c'
            '9057914c3fa9a13fb395e906bd8e91b4755367e8cbd64bb433a0cf4b3612859b'
            '8604aa3e7f043f47620e993179b12754d893c050d25b2c08190bd139e7594ce4'
            'f26501e4f8b5938dee886b03fb8d71235c5974cefdb61a604f7deab20b709d3c'
            '7ee5185dd709e9160427014e13adabf2ea2a80b02259ac91ebb41b52ea05d14d'
            '3dfb565f11279dc7cf2aedc650ff4fca5f0ae04a9d0db1713167aac8569ebc99'
            '588d275073c5085947567175296bebe11d1b8bd2866305bafc2a38204c288273'
            'b5db8bb78f63f1973e87448608b849f6784f8182a3528051244b7f794f209d1b'
            '92bc5d65a4065a4fce637cce563d171a9d1c77d0586fd6b274b0b8a9302d15aa'
            '4eb72a5a9c0cba6c275847b7f6b2d6a8b57fcc017f1fd25178c67eaaa4a68ebc'
            'e80fd59d2f9f1e2dd43946c4a8a6db60f834db4bad45d8f5dbf48ad7f3b6446b'
            'eb713f35bd9501c1520e3d7d0149c0be10274b6fce2ac551350e0e8cf4d7ec12'
            'c721221925c7ab006dd59721154e28ed462e43fe29b9616f3c95a99831020f96'
            'c4396840993717ba33aaaf98c4b7f7fe9064237667cc6e4e1dade1e8d24f0988'
            '7fa2486acd6ed6b8388bd476c7daaa403ae56e3dc9bbd1bcc62233585ed1e1ca')

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
