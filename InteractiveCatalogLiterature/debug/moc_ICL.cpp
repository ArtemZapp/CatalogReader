/****************************************************************************
** Meta object code from reading C++ file 'ICL.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../InteractiveCatalogLiterature/ICL.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ICL.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ICL[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      54,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    4,    5,    4, 0x0a,
      27,    4,    5,    4, 0x0a,
      51,   45,    4,    4, 0x0a,
      69,    4,    4,    4, 0x08,
      86,    4,    4,    4, 0x08,
     106,    4,    4,    4, 0x08,
     126,    4,    4,    4, 0x08,
     147,    4,    4,    4, 0x08,
     164,    4,    4,    4, 0x08,
     180,    4,    4,    4, 0x08,
     200,    4,    5,    4, 0x08,
     219,    4,    4,    4, 0x08,
     237,    4,    4,    4, 0x08,
     252,    4,    5,    4, 0x08,
     264,    4,    4,    4, 0x08,
     275,    4,    4,    4, 0x08,
     286,    4,    4,    4, 0x08,
     301,    4,    4,    4, 0x08,
     320,    4,    4,    4, 0x08,
     341,    4,    4,    4, 0x08,
     362,    4,    4,    4, 0x08,
     379,    4,    4,    4, 0x08,
     397,    4,    5,    4, 0x08,
     435,  422,  417,    4, 0x08,
     461,    4,    4,    4, 0x08,
     474,    4,    4,    4, 0x08,
     502,  488,  417,    4, 0x08,
     528,    4,    4,    4, 0x08,
     552,    4,    4,    4, 0x08,
     572,    4,    4,    4, 0x08,
     594,  488,  417,    4, 0x08,
     634,    4,  628,    4, 0x08,
     652,    4,  417,    4, 0x08,
     672,    4,    4,    4, 0x08,
     695,    4,    4,    4, 0x08,
     718,    4,    4,    4, 0x08,
     740,    4,    4,    4, 0x08,
     763,    4,    4,    4, 0x08,
     778,    4,    4,    4, 0x08,
     789,    4,    4,    4, 0x08,
     817,    4,    4,    4, 0x08,
     834,  832,    4,    4, 0x08,
     858,  832,    4,    4, 0x08,
     882,  832,    4,    4, 0x08,
     912,  906,    4,    4, 0x08,
     934,    4,    4,    4, 0x08,
     953,    4,    4,    4, 0x08,
     971,  906,    4,    4, 0x08,
    1002,    4,    4,    4, 0x08,
    1031, 1024,    4,    4, 0x08,
    1058,    4,    4,    4, 0x08,
    1077,    4,    4,    4, 0x08,
    1095,    4,    4,    4, 0x08,
    1129,    4,    4,    4, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ICL[] = {
    "ICL\0\0int\0slotModeEditing()\0slotModeViewing()\0"
    "bOpen\0openLibrary(bool)\0slotOpenDonate()\0"
    "slotOpenGetSource()\0slotBackupLibrary()\0"
    "slotRestoreLibrary()\0slotGetSupport()\0"
    "slotReportBug()\0slotCreateLibrary()\0"
    "slotCloseLibrary()\0slotExitProgram()\0"
    "slotOpenBook()\0slotClose()\0slotSave()\0"
    "openBook()\0slotNextPage()\0slotPreviousPage()\0"
    "slotSetModeViewing()\0slotSetModeEditing()\0"
    "slotNumberPage()\0slotTextChanged()\0"
    "messageChangeText()\0bool\0FileNameBook\0"
    "slotOpenBookFile(QString)\0slotCreate()\0"
    "showOptions()\0sFileNameBook\0"
    "slotOpenHTMLFile(QString)\0"
    "slotDeleteCurrentPage()\0slotInsertNewPage()\0"
    "slotPanelNumberPage()\0"
    "slotOpenEncodedPlainText(QString)\0"
    "uchar\0setModePassword()\0checkModePassword()\0"
    "slotEditModePassword()\0slotShowAdditionally()\0"
    "openMenuEditActions()\0closeMenuEditActions()\0"
    "slotOpenTest()\0userStat()\0"
    "slotCursorPositionChanged()\0slotFontNext()\0"
    "b\0slotUndoAvailable(bool)\0"
    "slotRedoAvailable(bool)\0slotCopyAvailable(bool)\0"
    "fText\0totbFindEdit(QString)\0"
    "slotToolFindText()\0slotGetModeWork()\0"
    "slotEnableFindButtons(QString)\0"
    "slotCheckForUpdates()\0bError\0"
    "slotMakeCheckUpdates(bool)\0"
    "slotBeforeExport()\0slotOpenLibrary()\0"
    "on_actionImportFolder_triggered()\0"
    "on_actionImportOneBook_triggered()\0"
};

void ICL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ICL *_t = static_cast<ICL *>(_o);
        switch (_id) {
        case 0: { int _r = _t->slotModeEditing();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { int _r = _t->slotModeViewing();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: _t->openLibrary((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->slotOpenDonate(); break;
        case 4: _t->slotOpenGetSource(); break;
        case 5: _t->slotBackupLibrary(); break;
        case 6: _t->slotRestoreLibrary(); break;
        case 7: _t->slotGetSupport(); break;
        case 8: _t->slotReportBug(); break;
        case 9: _t->slotCreateLibrary(); break;
        case 10: { int _r = _t->slotCloseLibrary();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: _t->slotExitProgram(); break;
        case 12: _t->slotOpenBook(); break;
        case 13: { int _r = _t->slotClose();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 14: _t->slotSave(); break;
        case 15: _t->openBook(); break;
        case 16: _t->slotNextPage(); break;
        case 17: _t->slotPreviousPage(); break;
        case 18: _t->slotSetModeViewing(); break;
        case 19: _t->slotSetModeEditing(); break;
        case 20: _t->slotNumberPage(); break;
        case 21: _t->slotTextChanged(); break;
        case 22: { int _r = _t->messageChangeText();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 23: { bool _r = _t->slotOpenBookFile((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 24: _t->slotCreate(); break;
        //case 25: _t->showOptions(); break;
        case 26: { bool _r = _t->slotOpenHTMLFile((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 27: _t->slotDeleteCurrentPage(); break;
        case 28: _t->slotInsertNewPage(); break;
        case 29: _t->slotPanelNumberPage(); break;
        case 30: { bool _r = _t->slotOpenEncodedPlainText((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 31: { uchar _r = _t->setModePassword();
            if (_a[0]) *reinterpret_cast< uchar*>(_a[0]) = _r; }  break;
        case 32: { bool _r = _t->checkModePassword();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 33: _t->slotEditModePassword(); break;
        case 34: _t->slotShowAdditionally(); break;
        case 35: _t->openMenuEditActions(); break;
        case 36: _t->closeMenuEditActions(); break;
        case 37: _t->slotOpenTest(); break;
        case 38: _t->userStat(); break;
        //case 39: _t->slotCursorPositionChanged(); break;
        case 40: _t->slotFontNext(); break;
        case 41: _t->slotUndoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 42: _t->slotRedoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 43: _t->slotCopyAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 44: _t->totbFindEdit((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 45: _t->slotToolFindText(); break;
        case 46: _t->slotGetModeWork(); break;
        case 47: _t->slotEnableFindButtons((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 48: _t->slotCheckForUpdates(); break;
        case 49: _t->slotMakeCheckUpdates((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 50: _t->slotBeforeExport(); break;
        case 51: _t->slotOpenLibrary(); break;
        case 52: _t->on_actionImportFolder_triggered(); break;
        case 53: _t->on_actionImportOneBook_triggered(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ICL::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ICL::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ICL,
      qt_meta_data_ICL, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ICL::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ICL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ICL::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ICL))
        return static_cast<void*>(const_cast< ICL*>(this));
    if (!strcmp(_clname, "Ui::ICL"))
        return static_cast< Ui::ICL*>(const_cast< ICL*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ICL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 54)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 54;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
