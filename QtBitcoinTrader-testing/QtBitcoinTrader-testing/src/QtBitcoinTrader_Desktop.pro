QMAKE_CFLAGS_WARN_ON += -Wno-deprecated-declarations -Wno-unused-function
QMAKE_CXXFLAGS_WARN_ON += -Wno-deprecated-declarations -Wno-unused-function

TEMPLATE	= app
LANGUAGE        = C++
DEPENDPATH 	+= .
INCLUDEPATH 	+= .
INCLUDEPATH += $$[QT_INSTALL_PREFIX]/src/3rdparty/zlib


CONFIG	+= qt release

 win32 { TARGET = ../Bin/QtBitcoinTrader }
!win32 { TARGET = QtBitcoinTrader }

QT  += network script
greaterThan(QT_MAJOR_VERSION, 4): {
QT += widgets
!win32 { QT += multimedia }
}

exists("sapi.h"){ DEFINES += SAPI_ENABLED }

CONFIG(static) {
  greaterThan(QT_MAJOR_VERSION, 4): {
   QTPLUGIN.mediaservice=-
   QTPLUGIN.playlistformats=-
   QTPLUGIN.position=-
   QTPLUGIN.printsupport=-
   QTPLUGIN.bearer=-
   QTPLUGIN.accessible=-
   QTPLUGIN.sensors=-
   QTPLUGIN.sqldrivers=-
   QTPLUGIN.qmltooling=-
   QTPLUGIN.designer=-
   QTPLUGIN.iconengines=-
   QTPLUGIN.imageformats=-
   win32 { DEFINES += STATIC_QT5_BUILD }
  }
}

 win32 { LIBS += -lcrypt32 -llibeay32 -lssleay32 -luser32 -lgdi32 -ladvapi32 -lzlib }
!win32 { LIBS += -lcrypto -lz }

mac{
LIBS += -framework CoreFoundation
LIBS += -framework ApplicationServices
}

#
# Headers
#
HEADERS += aboutdialog.h \
           addrulegroup.h \
           currencyinfo.h \
           currencypairitem.h \
           datafolderchusedialog.h \
           debugviewer.h \
           depthitem.h \
           depthmodel.h \
           exchange.h \
           exchange_bitfinex.h \
           exchange_bitstamp.h \
           exchange_btcchina.h \
           exchange_btce.h \
           feecalculator.h \
           historyitem.h \
           historymodel.h \
           julyaes256.h \
           julyhttp.h \
           julylightchanges.h \
           julyrsa.h \
           julyscrolluponidle.h \
           julyspinboxfix.h \
           julyspinboxpicker.h \
           julytranslator.h \
           logthread.h \
           main.h \
           newpassworddialog.h \
           orderitem.h \
           ordersmodel.h \
           orderstablecancelbutton.h \
           passworddialog.h \
           percentpicker.h \
           qtbitcointrader.h \
           rulesmodel.h \
           rulewidget.h \
           thisfeatureunderdevelopment.h \
           tradesitem.h \
           tradesmodel.h \
           translationdialog.h \
           translationline.h \
           updaterdialog.h \
           apptheme.h \
           logobutton.h \
    networkmenu.h \
    julybuttonmenu.h \
    scriptwidget.h \
    scriptobject.h \
    addscriptwindow.h \
    julylockfile.h \
    exchange_gocio.h \
    featuredexchangesdialog.h \
    allexchangesdialog.h \
    allexchangesmodel.h \
    exchangebutton.h \
    addruledialog.h \
    rulescriptparser.h \
    ruleholder.h \
    exchange_indacoin.h \
    julymath.h \
           exchange_bitcurex.h

FORMS += addrulegroup.ui \
         datafolderchusedialog.ui \
         debugviewer.ui \
         feecalculator.ui \
         newpassworddialog.ui \
         passworddialog.ui \
         percentpicker.ui \
         qtbitcointrader.ui \
         rulewidget.ui \
         thisfeatureunderdevelopment.ui \
         translationabout.ui \
         translationdialog.ui \
         updaterdialog.ui \
         logobutton.ui \
    networkmenu.ui \
    scriptwidget.ui \
    addscriptwindow.ui \
    featuredexchangesdialog.ui \
    allexchangesdialog.ui \
    exchangebutton.ui \
    addruledialog.ui

SOURCES += aboutdialog.cpp \
           addrulegroup.cpp \
           currencypairitem.cpp \
           datafolderchusedialog.cpp \
           debugviewer.cpp \
           depthitem.cpp \
           depthmodel.cpp \
           exchange.cpp \
           exchange_bitfinex.cpp \
           exchange_bitstamp.cpp \
           exchange_btcchina.cpp \
           exchange_btce.cpp \
           feecalculator.cpp \
           historyitem.cpp \
           historymodel.cpp \
           julyaes256.cpp \
           julyhttp.cpp \
           julylightchanges.cpp \
           julyrsa.cpp \
           julyscrolluponidle.cpp \
           julyspinboxfix.cpp \
           julyspinboxpicker.cpp \
           julytranslator.cpp \
           logthread.cpp \
           main.cpp \
           newpassworddialog.cpp \
           orderitem.cpp \
           ordersmodel.cpp \
           orderstablecancelbutton.cpp \
           passworddialog.cpp \
           percentpicker.cpp \
           qtbitcointrader.cpp \
           rulesmodel.cpp \
           rulewidget.cpp \
           thisfeatureunderdevelopment.cpp \
           tradesitem.cpp \
           tradesmodel.cpp \
           translationdialog.cpp \
           translationline.cpp \
           updaterdialog.cpp \
           apptheme.cpp \
           logobutton.cpp \
    networkmenu.cpp \
    julybuttonmenu.cpp \
    scriptwidget.cpp \
    scriptobject.cpp \
    addscriptwindow.cpp \
    julylockfile.cpp \
    exchange_gocio.cpp \
    featuredexchangesdialog.cpp \
    allexchangesdialog.cpp \
    allexchangesmodel.cpp \
    exchangebutton.cpp \
    addruledialog.cpp \
    rulescriptparser.cpp \
    ruleholder.cpp \
    exchange_indacoin.cpp \
           exchange_bitcurex.cpp
#
# Resources
# 
RESOURCES += QtResource.qrc

#
# Platform dependent stuff
#
unix:!macx {
UI_DIR = .ui
MOC_DIR = .moc
OBJECTS_DIR = .obj
isEmpty( PREFIX ) {
    PREFIX=/usr
}
isEmpty( DESKTOPDIR ) {
    DESKTOPDIR=/usr/share/applications
}
isEmpty( ICONDIR ) {
    ICONDIR=/usr/share/pixmaps
}

target.path = $${PREFIX}/bin

INSTALLS = target

desktop.path = $${DESKTOPDIR}

desktop.files = QtBitcoinTrader.desktop
INSTALLS += desktop

icon.path = $${ICONDIR}

icon.files = QtBitcoinTrader.png
INSTALLS += icon
}
################################
win32 {
RC_FILE = WinResource.rc
}

macx:ICON = $${PWD}/QtBitcoinTrader.icns
