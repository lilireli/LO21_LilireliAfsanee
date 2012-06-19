/****************************************************************************
** Meta object code from reading C++ file 'CalculatriceModele.h'
**
** Created: Tue 19. Jun 16:09:01 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Projet_GIT/Projet_LO21_v3_1/CalculatriceModele.h"
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
      41,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   20,   19,   19, 0x05,
      39,   20,   19,   19, 0x05,
      55,   19,   19,   19, 0x05,
      66,   64,   19,   19, 0x05,
      83,   64,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
     117,  106,   19,   19, 0x0a,
     141,   19,   19,   19, 0x0a,
     157,   20,   19,   19, 0x0a,
     181,   19,   19,   19, 0x0a,
     191,   19,   19,   19, 0x0a,
     202,   19,   19,   19, 0x0a,
     220,   19,   19,   19, 0x0a,
     234,   19,   19,   19, 0x0a,
     248,   19,   19,   19, 0x0a,
     271,  266,   19,   19, 0x0a,
     297,  292,   19,   19, 0x0a,
     309,  292,   19,   19, 0x0a,
     322,  292,   19,   19, 0x0a,
     335,  292,   19,   19, 0x0a,
     347,  292,   19,   19, 0x0a,
     359,   19,   19,   19, 0x0a,
     368,   19,   19,   19, 0x0a,
     378,  292,   19,   19, 0x0a,
     397,  391,   19,   19, 0x0a,
     410,  391,   19,   19, 0x0a,
     423,  391,   19,   19, 0x0a,
     436,  391,   19,   19, 0x0a,
     450,  391,   19,   19, 0x0a,
     464,  391,   19,   19, 0x0a,
     478,   19,   19,   19, 0x0a,
     486,   19,   19,   19, 0x0a,
     495,  292,   19,   19, 0x0a,
     507,   19,   19,   19, 0x0a,
     517,  292,   19,   19, 0x0a,
     529,  292,   19,   19, 0x0a,
     542,   19,   19,   19, 0x0a,
     552,  292,   19,   19, 0x0a,
     564,  292,   19,   19, 0x0a,
     577,   19,   19,   19, 0x0a,
     588,   19,   19,   19, 0x0a,
     597,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CalculatriceModele[] = {
    "CalculatriceModele\0\0pile\0finOp(Stack*)\0"
    "finAnRe(Stack*)\0compVF()\0s\0evalExp(QString)\0"
    "raffraichirUi(QString)\0s,complexe\0"
    "getNombre(QString,bool)\0getExpression()\0"
    "ajoutHistorique(Stack*)\0annuler()\0"
    "retablir()\0ecritureFichier()\0lireFichier()\0"
    "effacerPile()\0transformerPile()\0Comp\0"
    "actualiserPile(bool)\0type\0getAdd(int)\0"
    "getSous(int)\0getMult(int)\0getDiv(int)\0"
    "getPow(int)\0getMod()\0getFact()\0"
    "getSign(int)\0degre\0getSin(bool)\0"
    "getCos(bool)\0getTan(bool)\0getSinh(bool)\0"
    "getCosh(bool)\0getTanh(bool)\0getLn()\0"
    "getLog()\0getInv(int)\0getSqrt()\0"
    "getSqr(int)\0getCube(int)\0getSwap()\0"
    "getSum(int)\0getMean(int)\0getClear()\0"
    "getDup()\0getDrop()\0"
};

void CalculatriceModele::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CalculatriceModele *_t = static_cast<CalculatriceModele *>(_o);
        switch (_id) {
        case 0: _t->finOp((*reinterpret_cast< Stack*(*)>(_a[1]))); break;
        case 1: _t->finAnRe((*reinterpret_cast< Stack*(*)>(_a[1]))); break;
        case 2: _t->compVF(); break;
        case 3: _t->evalExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->raffraichirUi((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->getNombre((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->getExpression(); break;
        case 7: _t->ajoutHistorique((*reinterpret_cast< Stack*(*)>(_a[1]))); break;
        case 8: _t->annuler(); break;
        case 9: _t->retablir(); break;
        case 10: _t->ecritureFichier(); break;
        case 11: _t->lireFichier(); break;
        case 12: _t->effacerPile(); break;
        case 13: _t->transformerPile(); break;
        case 14: _t->actualiserPile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->getAdd((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->getSous((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->getMult((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->getDiv((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->getPow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->getMod(); break;
        case 21: _t->getFact(); break;
        case 22: _t->getSign((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->getSin((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->getCos((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->getTan((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->getSinh((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->getCosh((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->getTanh((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->getLn(); break;
        case 30: _t->getLog(); break;
        case 31: _t->getInv((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->getSqrt(); break;
        case 33: _t->getSqr((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->getCube((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->getSwap(); break;
        case 36: _t->getSum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->getMean((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->getClear(); break;
        case 39: _t->getDup(); break;
        case 40: _t->getDrop(); break;
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
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    }
    return _id;
}

// SIGNAL 0
void CalculatriceModele::finOp(Stack * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CalculatriceModele::finAnRe(Stack * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CalculatriceModele::compVF()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void CalculatriceModele::evalExp(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CalculatriceModele::raffraichirUi(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
