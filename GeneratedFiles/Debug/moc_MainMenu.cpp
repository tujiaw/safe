/****************************************************************************
** Meta object code from reading C++ file 'MainMenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MainMenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainMenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainMenu_t {
    QByteArrayData data[11];
    char stringdata[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainMenu_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainMenu_t qt_meta_stringdata_MainMenu = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 10),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 15),
QT_MOC_LITERAL(4, 37, 14),
QT_MOC_LITERAL(5, 52, 15),
QT_MOC_LITERAL(6, 68, 10),
QT_MOC_LITERAL(7, 79, 14),
QT_MOC_LITERAL(8, 94, 13),
QT_MOC_LITERAL(9, 108, 14),
QT_MOC_LITERAL(10, 123, 21)
    },
    "MainMenu\0sigSetting\0\0sigNewCharacter\0"
    "sigCheckUpdate\0sigToEnterprise\0"
    "sigAboutUs\0slotOnlineHelp\0slotForumHelp\0"
    "slot360Website\0slotPrivacyProtection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainMenu *_t = static_cast<MainMenu *>(_o);
        switch (_id) {
        case 0: _t->sigSetting(); break;
        case 1: _t->sigNewCharacter(); break;
        case 2: _t->sigCheckUpdate(); break;
        case 3: _t->sigToEnterprise(); break;
        case 4: _t->sigAboutUs(); break;
        case 5: _t->slotOnlineHelp(); break;
        case 6: _t->slotForumHelp(); break;
        case 7: _t->slot360Website(); break;
        case 8: _t->slotPrivacyProtection(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainMenu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainMenu::sigSetting)) {
                *result = 0;
            }
        }
        {
            typedef void (MainMenu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainMenu::sigNewCharacter)) {
                *result = 1;
            }
        }
        {
            typedef void (MainMenu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainMenu::sigCheckUpdate)) {
                *result = 2;
            }
        }
        {
            typedef void (MainMenu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainMenu::sigToEnterprise)) {
                *result = 3;
            }
        }
        {
            typedef void (MainMenu::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainMenu::sigAboutUs)) {
                *result = 4;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MainMenu::staticMetaObject = {
    { &QMenu::staticMetaObject, qt_meta_stringdata_MainMenu.data,
      qt_meta_data_MainMenu,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainMenu.stringdata))
        return static_cast<void*>(const_cast< MainMenu*>(this));
    return QMenu::qt_metacast(_clname);
}

int MainMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MainMenu::sigSetting()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MainMenu::sigNewCharacter()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MainMenu::sigCheckUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MainMenu::sigToEnterprise()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MainMenu::sigAboutUs()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
