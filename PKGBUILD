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
sha256sums=('e157ef9118c8c42baf446bbc7ed32c5640f7055e95f1f932aaf1c604fb89b394'
            '2359fa90026b3bb9ccfcda3ca522c51ee108fbdb41d7c63caa9447419e9e949b'
            '1993188e0dd723ebc553050ff6fe6441928c55fa9d4c08368f15a2ff49f2a8f1'
            '5c6ae2ad93b9eb2a04a56d6c6bfc3da06f92ea8775508c50b33acf3863a85b1d'
            'a568ae09c40e6e9da7c07be3e923565a285976fa42d3c433508716dbda99dcd0'
            'e83c387a97688b3367d610238f8cab2be735f79532e0756c72d43d3f22901372'
            'a59eee014cb2ad7c7004aed03447e23d3de29bc3a1ec2be7d565e7cf2c646d06'
            '2ddd12f67bd29a4801ab3ce2ca74c4701cbe8aed6196e564579a1547e5efd4f9'
            '1efd5c3a8d7d8dda153e8532466ec41c8bc426d46163919529dc8337fe4e5970'
            '65ee88f45dd3379d68d12c09f1249aafa3033c22ef8cbf8f253564fc03afd3f1'
            '56b89b157eddd1c6bd96498b691a22ec00cee2bc515d976bc65d4e556dd41e8a'
            '2cf30ce1abbd9f076201808bcb14df31accd3beb7265d7e3d02327141e573c6e'
            'f44e4ee4233ad38475eea4bf8415571c6017d02ed03dfd86fff37791c7b935f8'
            '6efd33c0e867ca2c9b93137bc5a67f677a4cab01a3d0a80809824c6966ca26fe'
            'e515ac0fa7ef6719dcc71f5fad30add43de25fe0540c277d11c45c4f7f2d15ab'
            'e4f9526a51b8cb3c47a446d121661592a832b5c74e51fe40b1796ed1dea499e2'
            '4e80287199f792dd2bda250c6723f3a1f30b1a3a8777e05a769fdb8d1e45ae19'
            '928b10da6c20fb7e86d0b02b41c31d46cabae93109a39571d98827494067be00'
            'b8c4489433a224ef23a1e9ee2fccd8f67f2e4960aa1ee97490e1e8554a6c5515'
            'c70af4e9a871e143c7843473aab3e6e4d392170365ac07e7a0b55512b9039977'
            '878a550d9fde9a58352b3a192fd9095019ebbeeae28ab24536ec3657c7be0311'
            '01eb5386bbca23a3eff79d91bf050e0252f24a9f38a0d3eebdb4d7dc05a02dfe')

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
