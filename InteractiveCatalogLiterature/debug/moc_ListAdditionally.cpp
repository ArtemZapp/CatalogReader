/****************************************************************************
** Meta object code from reading C++ file 'ListAdditionally.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ListAdditionally/ListAdditionally.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ListAdditionally.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ListAdditionally[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      41,   17,   17,   17, 0x08,
      67,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ListAdditionally[] = {
    "ListAdditionally\0\0on_pbAddFile_clicked()\0"
    "on_pbRemoveFile_clicked()\0slotRunFile()\0"
};

void ListAdditionally::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ListAdditionally *_t = static_cast<ListAdditionally *>(_o);
        switch (_id) {
        case 0: _t->on_pbAddFile_clicked(); break;
        case 1: _t->on_pbRemoveFile_clicked(); break;
        case 2: _t->slotRunFile(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ListAdditionally::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ListAdditionally::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ListAdditionally,
      qt_meta_data_ListAdditionally, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ListAdditionally::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ListAdditionally::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ListAdditionally::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ListAdditionally))
        return static_cast<void*>(const_cast< ListAdditionally*>(this));
    if (!strcmp(_clname, "Ui::ListAdditionally"))
        return static_cast< Ui::ListAdditionally*>(const_cast< ListAdditionally*>(this));
    return QDialog::qt_metacast(_clname);
}

int ListAdditionally::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
