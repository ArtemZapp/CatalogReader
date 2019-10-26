/****************************************************************************
** Meta object code from reading C++ file 'ListBooks.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ListBooks/ListBooks.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ListBooks.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ListBooks[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      29,   10,   10,   10, 0x0a,
      43,   10,   10,   10, 0x0a,
      57,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ListBooks[] = {
    "ListBooks\0\0slotCellClicked()\0slotAddBook()\0"
    "slotDelBook()\0slotbSave()\0"
};

void ListBooks::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ListBooks *_t = static_cast<ListBooks *>(_o);
        switch (_id) {
        case 0: _t->slotCellClicked(); break;
        case 1: _t->slotAddBook(); break;
        case 2: _t->slotDelBook(); break;
        case 3: _t->slotbSave(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ListBooks::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ListBooks::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ListBooks,
      qt_meta_data_ListBooks, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ListBooks::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ListBooks::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ListBooks::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ListBooks))
        return static_cast<void*>(const_cast< ListBooks*>(this));
    if (!strcmp(_clname, "Ui::ListBooks"))
        return static_cast< Ui::ListBooks*>(const_cast< ListBooks*>(this));
    return QDialog::qt_metacast(_clname);
}

int ListBooks::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
