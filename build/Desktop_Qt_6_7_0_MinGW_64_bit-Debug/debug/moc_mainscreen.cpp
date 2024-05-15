/****************************************************************************
** Meta object code from reading C++ file 'mainscreen.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainscreen.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainScreenENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainScreenENDCLASS = QtMocHelpers::stringData(
    "MainScreen",
    "on_play_pause_clicked",
    "",
    "checked",
    "SetDuration",
    "durationMilliseconds",
    "SetCurrentTime",
    "updateVolumeSlider",
    "volume",
    "setVolume",
    "value",
    "on_actionLog_Out_triggered",
    "on_Volume_Mute_clicked",
    "on_powerButton_clicked",
    "InitialView",
    "onPlaylistSelected",
    "QItemSelection",
    "selected",
    "deselected",
    "onSongSelected",
    "onSearchTextChanged",
    "query",
    "on_newPlaylist_clicked",
    "on_addToPlaylist_currentIndexChanged",
    "index",
    "newPlaylistSlot",
    "name",
    "songFinished",
    "QMediaPlayer::MediaStatus",
    "status",
    "shuffledPlay",
    "on_Next_clicked",
    "on_Previous_clicked",
    "on_Repeat_clicked",
    "on_Shuffle_clicked",
    "on_Liked_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainScreenENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  152,    2, 0x08,    1 /* Private */,
       4,    1,  155,    2, 0x08,    3 /* Private */,
       6,    0,  158,    2, 0x08,    5 /* Private */,
       7,    1,  159,    2, 0x08,    6 /* Private */,
       9,    1,  162,    2, 0x08,    8 /* Private */,
      11,    0,  165,    2, 0x08,   10 /* Private */,
      12,    1,  166,    2, 0x08,   11 /* Private */,
      13,    1,  169,    2, 0x08,   13 /* Private */,
      14,    0,  172,    2, 0x08,   15 /* Private */,
      15,    2,  173,    2, 0x08,   16 /* Private */,
      19,    2,  178,    2, 0x08,   19 /* Private */,
      20,    1,  183,    2, 0x08,   22 /* Private */,
      22,    0,  186,    2, 0x08,   24 /* Private */,
      23,    1,  187,    2, 0x08,   25 /* Private */,
      25,    1,  190,    2, 0x08,   27 /* Private */,
      27,    1,  193,    2, 0x08,   29 /* Private */,
      30,    0,  196,    2, 0x08,   31 /* Private */,
      31,    1,  197,    2, 0x08,   32 /* Private */,
      31,    0,  200,    2, 0x28,   34 /* Private | MethodCloned */,
      32,    0,  201,    2, 0x08,   35 /* Private */,
      33,    1,  202,    2, 0x08,   36 /* Private */,
      34,    1,  205,    2, 0x08,   38 /* Private */,
      35,    1,  208,    2, 0x08,   40 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::LongLong,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 16,   17,   18,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 16,   17,   18,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainScreen::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainScreenENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainScreenENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainScreenENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainScreen, std::true_type>,
        // method 'on_play_pause_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'SetDuration'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'SetCurrentTime'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateVolumeSlider'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qreal, std::false_type>,
        // method 'setVolume'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_actionLog_Out_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Volume_Mute_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_powerButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'InitialView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onPlaylistSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QItemSelection &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QItemSelection &, std::false_type>,
        // method 'onSongSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QItemSelection &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QItemSelection &, std::false_type>,
        // method 'onSearchTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_newPlaylist_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addToPlaylist_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'newPlaylistSlot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'songFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMediaPlayer::MediaStatus, std::false_type>,
        // method 'shuffledPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Next_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_Next_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Previous_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Repeat_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_Shuffle_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_Liked_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void MainScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainScreen *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_play_pause_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->SetDuration((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 2: _t->SetCurrentTime(); break;
        case 3: _t->updateVolumeSlider((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 4: _t->setVolume((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->on_actionLog_Out_triggered(); break;
        case 6: _t->on_Volume_Mute_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->on_powerButton_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->InitialView(); break;
        case 9: _t->onPlaylistSelected((*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[2]))); break;
        case 10: _t->onSongSelected((*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[2]))); break;
        case 11: _t->onSearchTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->on_newPlaylist_clicked(); break;
        case 13: _t->on_addToPlaylist_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->newPlaylistSlot((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 15: _t->songFinished((*reinterpret_cast< std::add_pointer_t<QMediaPlayer::MediaStatus>>(_a[1]))); break;
        case 16: _t->shuffledPlay(); break;
        case 17: _t->on_Next_clicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->on_Next_clicked(); break;
        case 19: _t->on_Previous_clicked(); break;
        case 20: _t->on_Repeat_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 21: _t->on_Shuffle_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        //case 22: _t->on_Liked_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QItemSelection >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QItemSelection >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MainScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainScreenENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}
QT_WARNING_POP
