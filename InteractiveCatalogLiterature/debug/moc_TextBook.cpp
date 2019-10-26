/****************************************************************************
** Meta object code from reading C++ file 'TextBook.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TextBook/TextBook.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TextBook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TTextBook[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       6,  149, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      22,   10,   10,   10, 0x05,
      43,   37,   10,   10, 0x05,
      65,   10,   10,   10, 0x05,
      77,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      98,   91,   10,   10, 0x0a,
     125,  113,   10,   10, 0x0a,
     150,  144,   10,   10, 0x0a,
     176,  163,   10,   10, 0x0a,
     206,  196,   10,   10, 0x0a,
     235,  224,   10,   10, 0x0a,
     265,   10,  259,   10, 0x0a,
     288,   10,   10,   10, 0x0a,
     306,   10,   10,   10, 0x0a,
     326,   10,   10,   10, 0x0a,
     345,   10,   10,   10, 0x0a,
     363,   10,   10,   10, 0x0a,
     379,   10,   10,   10, 0x0a,
     395,   10,   10,   10, 0x0a,
     407,   10,   10,   10, 0x0a,
     422,   10,   10,   10, 0x0a,
     437,   10,   10,   10, 0x0a,
     456,   10,   10,   10, 0x0a,
     477,   10,   10,   10, 0x0a,
     495,   10,   10,   10, 0x0a,
     512,   10,   10,   10, 0x0a,
     530,   10,   10,   10, 0x0a,

 // properties: name, type, flags
     548,  543, 0x01095103,
     554,  543, 0x01095103,
     567,  563, 0x02095103,
     578,  563, 0x02095103,
     583,  563, 0x02095103,
     606,  595, 0x0c095103,

       0        // eod
};

static const char qt_meta_stringdata_TTextBook[] = {
    "TTextBook\0\0NextPage()\0PreviousPage()\0"
    "fText\0totbFindEdit(QString)\0slotClose()\0"
    "getModeWork()\0bSaved\0setSaved(bool)\0"
    "iNumberBook\0setNumberBook(int)\0iYear\0"
    "setYear(int)\0iCurrentPage\0setCurrentPage(int)\0"
    "bModeWork\0setModeWork(bool)\0baPassword\0"
    "setPassword(QByteArray)\0uchar\0"
    "slotEditPasswordBook()\0slotJustifyLeft()\0"
    "slotJustifyCenter()\0slotJustifyRight()\0"
    "slotJustifyFill()\0slotUppercase()\0"
    "slotLowercase()\0slotPrint()\0slotFindText()\0"
    "slotFindNext()\0slotFindPrevious()\0"
    "slotExportAllBooks()\0slotInsertImage()\0"
    "slotChangeFont()\0slotToPlainText()\0"
    "exportBook()\0bool\0saved\0modeWork\0int\0"
    "numberBook\0year\0currentPage\0QByteArray\0"
    "password\0"
};

void TTextBook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TTextBook *_t = static_cast<TTextBook *>(_o);
        switch (_id) {
        case 0: _t->NextPage(); break;
        case 1: _t->PreviousPage(); break;
        case 2: _t->totbFindEdit((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->slotClose(); break;
        case 4: _t->getModeWork(); break;
        case 5: _t->setSaved((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->setNumberBook((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setYear((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setCurrentPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->setModeWork((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->setPassword((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 11: { uchar _r = _t->slotEditPasswordBook();
            if (_a[0]) *reinterpret_cast< uchar*>(_a[0]) = _r; }  break;
        case 12: _t->slotJustifyLeft(); break;
        case 13: _t->slotJustifyCenter(); break;
        case 14: _t->slotJustifyRight(); break;
        case 15: _t->slotJustifyFill(); break;
        case 16: _t->slotUppercase(); break;
        case 17: _t->slotLowercase(); break;
        case 18: _t->slotPrint(); break;
        case 19: _t->slotFindText(); break;
        case 20: _t->slotFindNext(); break;
        case 21: _t->slotFindPrevious(); break;
        case 22: _t->slotExportAllBooks(); break;
        case 23: _t->slotInsertImage(); break;
        case 24: _t->slotChangeFont(); break;
        case 25: _t->slotToPlainText(); break;
        case 26: _t->exportBook(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TTextBook::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TTextBook::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_TTextBook,
      qt_meta_data_TTextBook, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TTextBook::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TTextBook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TTextBook::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TTextBook))
        return static_cast<void*>(const_cast< TTextBook*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int TTextBook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = isSaved(); break;
        case 1: *reinterpret_cast< bool*>(_v) = isModeWork(); break;
        case 2: *reinterpret_cast< int*>(_v) = numberBook(); break;
        case 3: *reinterpret_cast< int*>(_v) = year(); break;
        case 4: *reinterpret_cast< int*>(_v) = currentPage(); break;
        case 5: *reinterpret_cast< QByteArray*>(_v) = password(); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setSaved(*reinterpret_cast< bool*>(_v)); break;
        case 1: setModeWork(*reinterpret_cast< bool*>(_v)); break;
        case 2: setNumberBook(*reinterpret_cast< int*>(_v)); break;
        case 3: setYear(*reinterpret_cast< int*>(_v)); break;
        case 4: setCurrentPage(*reinterpret_cast< int*>(_v)); break;
        case 5: setPassword(*reinterpret_cast< QByteArray*>(_v)); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void TTextBook::NextPage()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void TTextBook::PreviousPage()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void TTextBook::totbFindEdit(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TTextBook::slotClose()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void TTextBook::getModeWork()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
