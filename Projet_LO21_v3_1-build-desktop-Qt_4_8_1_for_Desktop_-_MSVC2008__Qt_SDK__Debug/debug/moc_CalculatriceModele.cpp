/****************************************************************************
** Meta object code from reading C++ file 'CalculatriceModele.h'
**
** Created: Thu 7. Jun 23:23:31 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Projet_LO21_v3_1/CalculatriceModele.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CalculatriceModele.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CalculatriceModele[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   20,   19,   19, 0x0a,
      50,   19,   19,   19, 0x0a,
      59,   19,   19,   19, 0x0a,
      69,   19,   19,   19, 0x0a,
      79,   19,   19,   19, 0x0a,
      88,   19,   19,   19, 0x0a,
      97,   19,   19,   19, 0x0a,
     106,   19,   19,   19, 0x0a,
     116,   19,   19,   19, 0x0a,
     126,   19,   19,   19, 0x0a,
     135,   19,   19,   19, 0x0a,
     144,   19,   19,   19, 0x0a,
     153,   19,   19,   19, 0x0a,
     163,   19,   19,   19, 0x0a,
     173,   19,   19,   19, 0x0a,
     183,   19,   19,   19, 0x0a,
     191,   19,   19,   19, 0x0a,
     200,   19,   19,   19, 0x0a,
     209,   19,   19,   19, 0x0a,
     219,   19,   19,   19, 0x0a,
     228,   19,   19,   19, 0x0a,
     238,   19,   19,   19, 0x0a,
     248,   19,   19,   19, 0x0a,
     257,   19,   19,   19, 0x0a,
     267,   19,   19,   19, 0x0a,
     278,   19,   19,   19, 0x0a,
     287,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CalculatriceModele[] = {
    "CalculatriceModele\0\0s,type\0"
    "getNombre(QString,int)\0getAdd()\0"
    "getSous()\0getMult()\0getDiv()\0getPow()\0"
    "getMod()\0getFact()\0getSign()\0getSin()\0"
    "getCos()\0getTan()\0getSinh()\0getCosh()\0"
    "getTanh()\0getLn()\0getLog()\0getInv()\0"
    "getSqrt()\0getSqr()\0getCube()\0getSwap()\0"
    "getSum()\0getMean()\0getClear()\0getDup()\0"
    "getDrop()\0"
};

void CalculatriceModele::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CalculatriceModele *_t = static_cast<CalculatriceModele *>(_o);
        switch (_id) {
        case 0: _t->getNombre((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->getAdd(); break;
        case 2: _t->getSous(); break;
        case 3: _t->getMult(); break;
        case 4: _t->getDiv(); break;
        case 5: _t->getPow(); break;
        case 6: _t->getMod(); break;
        case 7: _t->getFact(); break;
        case 8: _t->getSign(); break;
        case 9: _t->getSin(); break;
        case 10: _t->getCos(); break;
        case 11: _t->getTan(); break;
        case 12: _t->getSinh(); break;
        case 13: _t->getCosh(); break;
        case 14: _t->getTanh(); break;
        case 15: _t->getLn(); break;
        case 16: _t->getLog(); break;
        case 17: _t->getInv(); break;
        case 18: _t->getSqrt(); break;
        case 19: _t->getSqr(); break;
        case 20: _t->getCube(); break;
        case 21: _t->getSwap(); break;
        case 22: _t->getSum(); break;
        case 23: _t->getMean(); break;
        case 24: _t->getClear(); break;
        case 25: _t->getDup(); break;
        case 26: _t->getDrop(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CalculatriceModele::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CalculatriceModele::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CalculatriceModele,
      qt_meta_data_CalculatriceModele, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CalculatriceModele::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CalculatriceModele::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CalculatriceModele::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CalculatriceModele))
        return static_cast<void*>(const_cast< CalculatriceModele*>(this));
    return QObject::qt_metacast(_clname);
}

int CalculatriceModele::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
