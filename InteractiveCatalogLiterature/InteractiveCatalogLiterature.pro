# Подключение модулей
QT += sql \
    network \
    webkit

# Название программы и путь месторасположения
TARGET = ../usr/bin/CatalogReader

# Путь для переносимой версии
# TARGET = Каталог Литературы
# Конфигурация сборки - выпуск(исключён отладочный код)
CONFIG += RELEASE

SOURCES += main.cpp \
    TextBook/TextBook.cpp \
    ListBooks/ListBooks.cpp \
    Create/Create.cpp \
    InteractiveCatalogLiterature/ICL.cpp \
    ListAdditionally/ListAdditionally.cpp \
    fileoptions/fileoptions.cpp
HEADERS += ListBooks/ListBooks.h \
    const.h \
    TextBook/TextBook.h \
    Create/Create.h \
    InteractiveCatalogLiterature/ICL.h \
    ListAdditionally/ListAdditionally.h \
    version.h \
    fileoptions/fileoptions.h
FORMS += InteractiveCatalogLiterature/ICL.ui \
    ListBooks/ListBooks.ui \
    Create/Create.ui \
    ListAdditionally/ListAdditionally.ui
RESOURCES += images.qrc
OTHER_FILES += 

# install. Путь установки программы
target.path = /usr/bin
INSTALLS += target
