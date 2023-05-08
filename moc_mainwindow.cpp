/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[71];
    char stringdata0[1879];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "on_UPDATE_UI"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 9), // "Update_UI"
QT_MOC_LITERAL(4, 35, 10), // "Update_Log"
QT_MOC_LITERAL(5, 46, 13), // "mouse_clicked"
QT_MOC_LITERAL(6, 60, 1), // "x"
QT_MOC_LITERAL(7, 62, 1), // "y"
QT_MOC_LITERAL(8, 64, 14), // "mouse_released"
QT_MOC_LITERAL(9, 79, 30), // "on_BTN_CONNECT_GRIPPER_clicked"
QT_MOC_LITERAL(10, 110, 28), // "on_BTN_CONNECT_OMRON_clicked"
QT_MOC_LITERAL(11, 139, 27), // "on_BTN_CONNECT_LIFT_clicked"
QT_MOC_LITERAL(12, 167, 26), // "on_BTN_CONNECT_RB5_clicked"
QT_MOC_LITERAL(13, 194, 29), // "on_BTN_CONNECT_VISION_clicked"
QT_MOC_LITERAL(14, 224, 26), // "on_BTN_GLOBAL_INIT_clicked"
QT_MOC_LITERAL(15, 251, 34), // "on_BTN_CHECK_SOCKET_STATUS_cl..."
QT_MOC_LITERAL(16, 286, 28), // "on_BTN_RB5_MOVE_INIT_clicked"
QT_MOC_LITERAL(17, 315, 30), // "on_BTN_RB5_MOVE_VISION_clicked"
QT_MOC_LITERAL(18, 346, 37), // "on_BTN_RB5_MOVE_GRIPPER_READY..."
QT_MOC_LITERAL(19, 384, 37), // "on_BTN_RB5_MOVE_GRIPPER_GRAPS..."
QT_MOC_LITERAL(20, 422, 31), // "on_BTN_RB5_MOVE_EXTRA_1_clicked"
QT_MOC_LITERAL(21, 454, 31), // "on_BTN_RB5_MOVE_EXTRA_2_clicked"
QT_MOC_LITERAL(22, 486, 28), // "on_BTN_RB5_SAVE_INIT_clicked"
QT_MOC_LITERAL(23, 515, 30), // "on_BTN_RB5_SAVE_VISION_clicked"
QT_MOC_LITERAL(24, 546, 37), // "on_BTN_RB5_SAVE_GRIPPER_READY..."
QT_MOC_LITERAL(25, 584, 37), // "on_BTN_RB5_SAVE_GRIPPER_GRAPS..."
QT_MOC_LITERAL(26, 622, 31), // "on_BTN_RB5_SAVE_EXTRA_1_clicked"
QT_MOC_LITERAL(27, 654, 31), // "on_BTN_RB5_SAVE_EXTRA_2_clicked"
QT_MOC_LITERAL(28, 686, 24), // "on_BTN_RB5_PASUE_clicked"
QT_MOC_LITERAL(29, 711, 25), // "on_BTN_RB5_RESUME_clicked"
QT_MOC_LITERAL(30, 737, 23), // "on_BTN_RB5_HOLT_clicked"
QT_MOC_LITERAL(31, 761, 32), // "on_SLIDER_RB5_SPEED_valueChanged"
QT_MOC_LITERAL(32, 794, 5), // "value"
QT_MOC_LITERAL(33, 800, 28), // "on_SB_RB5_SPEED_valueChanged"
QT_MOC_LITERAL(34, 829, 4), // "arg1"
QT_MOC_LITERAL(35, 834, 23), // "on_BTN_RB5_MODE_clicked"
QT_MOC_LITERAL(36, 858, 33), // "on_BTN_SENARIO_CUSTOM_ADD_cli..."
QT_MOC_LITERAL(37, 892, 33), // "on_BTN_SENARIO_CUSTOM_DEL_cli..."
QT_MOC_LITERAL(38, 926, 38), // "on_BTN_SENARIO_EXECUTION_BASI..."
QT_MOC_LITERAL(39, 965, 39), // "on_BTN_SENARIO_EXECUTION_CUST..."
QT_MOC_LITERAL(40, 1005, 31), // "on_BTN_VISION_CMD_WRITE_clicked"
QT_MOC_LITERAL(41, 1037, 32), // "on_BTN_GRIPPER_CMD_WRITE_clicked"
QT_MOC_LITERAL(42, 1070, 29), // "on_BTN_GRIPPER_UNFOLD_clicked"
QT_MOC_LITERAL(43, 1100, 27), // "on_BTN_GRIPPER_GRAP_clicked"
QT_MOC_LITERAL(44, 1128, 29), // "on_BTN_GRIPPER_VISION_clicked"
QT_MOC_LITERAL(45, 1158, 34), // "on_CB_GRIPPER_GE_CMD_WRITE_cl..."
QT_MOC_LITERAL(46, 1193, 31), // "on_BTN_SET_IP_PORT_KETI_clicked"
QT_MOC_LITERAL(47, 1225, 33), // "on_BTN_SET_IP_PORT_KITECH_cli..."
QT_MOC_LITERAL(48, 1259, 30), // "on_BTN_SET_CALIB_T_V2N_clicked"
QT_MOC_LITERAL(49, 1290, 30), // "on_BTN_SET_CALIB_T_N2E_clicked"
QT_MOC_LITERAL(50, 1321, 30), // "on_BTN_VISION_OUT_SAVE_clicked"
QT_MOC_LITERAL(51, 1352, 31), // "on_BTN_LIFT_SERIAL_OPEN_clicked"
QT_MOC_LITERAL(52, 1384, 24), // "on_BTN_OMRON_ADD_clicked"
QT_MOC_LITERAL(53, 1409, 26), // "on_BTN_LIFT_HOMING_clicked"
QT_MOC_LITERAL(54, 1436, 30), // "on_BTN_VISION_OUT_LOAD_clicked"
QT_MOC_LITERAL(55, 1467, 35), // "on_BTN_RB5_MOVE_GRAPS_POINT_c..."
QT_MOC_LITERAL(56, 1503, 35), // "on_BTN_RB5_CALC_GRAPS_POINT_c..."
QT_MOC_LITERAL(57, 1539, 30), // "on_BTN_SET_GRAPS_POINT_clicked"
QT_MOC_LITERAL(58, 1570, 31), // "on_BTN_LOAD_GRAPS_POINT_clicked"
QT_MOC_LITERAL(59, 1602, 30), // "on_BTN_TE_GLOBAL_CLEAR_clicked"
QT_MOC_LITERAL(60, 1633, 29), // "on_BTN_VISION_OUT_SET_clicked"
QT_MOC_LITERAL(61, 1663, 28), // "on_BTN_LIFT_REQ_DATA_clicked"
QT_MOC_LITERAL(62, 1692, 18), // "on_btn_say_clicked"
QT_MOC_LITERAL(63, 1711, 20), // "on_BTN_SH_11_clicked"
QT_MOC_LITERAL(64, 1732, 20), // "on_BTN_SH_12_clicked"
QT_MOC_LITERAL(65, 1753, 20), // "on_BTN_SH_13_clicked"
QT_MOC_LITERAL(66, 1774, 20), // "on_BTN_SH_14_clicked"
QT_MOC_LITERAL(67, 1795, 20), // "on_BTN_SH_21_clicked"
QT_MOC_LITERAL(68, 1816, 20), // "on_BTN_SH_22_clicked"
QT_MOC_LITERAL(69, 1837, 20), // "on_BTN_SH_23_clicked"
QT_MOC_LITERAL(70, 1858, 20) // "on_BTN_SH_24_clicked"

    },
    "MainWindow\0on_UPDATE_UI\0\0Update_UI\0"
    "Update_Log\0mouse_clicked\0x\0y\0"
    "mouse_released\0on_BTN_CONNECT_GRIPPER_clicked\0"
    "on_BTN_CONNECT_OMRON_clicked\0"
    "on_BTN_CONNECT_LIFT_clicked\0"
    "on_BTN_CONNECT_RB5_clicked\0"
    "on_BTN_CONNECT_VISION_clicked\0"
    "on_BTN_GLOBAL_INIT_clicked\0"
    "on_BTN_CHECK_SOCKET_STATUS_clicked\0"
    "on_BTN_RB5_MOVE_INIT_clicked\0"
    "on_BTN_RB5_MOVE_VISION_clicked\0"
    "on_BTN_RB5_MOVE_GRIPPER_READY_clicked\0"
    "on_BTN_RB5_MOVE_GRIPPER_GRAPS_clicked\0"
    "on_BTN_RB5_MOVE_EXTRA_1_clicked\0"
    "on_BTN_RB5_MOVE_EXTRA_2_clicked\0"
    "on_BTN_RB5_SAVE_INIT_clicked\0"
    "on_BTN_RB5_SAVE_VISION_clicked\0"
    "on_BTN_RB5_SAVE_GRIPPER_READY_clicked\0"
    "on_BTN_RB5_SAVE_GRIPPER_GRAPS_clicked\0"
    "on_BTN_RB5_SAVE_EXTRA_1_clicked\0"
    "on_BTN_RB5_SAVE_EXTRA_2_clicked\0"
    "on_BTN_RB5_PASUE_clicked\0"
    "on_BTN_RB5_RESUME_clicked\0"
    "on_BTN_RB5_HOLT_clicked\0"
    "on_SLIDER_RB5_SPEED_valueChanged\0value\0"
    "on_SB_RB5_SPEED_valueChanged\0arg1\0"
    "on_BTN_RB5_MODE_clicked\0"
    "on_BTN_SENARIO_CUSTOM_ADD_clicked\0"
    "on_BTN_SENARIO_CUSTOM_DEL_clicked\0"
    "on_BTN_SENARIO_EXECUTION_BASIC_clicked\0"
    "on_BTN_SENARIO_EXECUTION_CUSTOM_clicked\0"
    "on_BTN_VISION_CMD_WRITE_clicked\0"
    "on_BTN_GRIPPER_CMD_WRITE_clicked\0"
    "on_BTN_GRIPPER_UNFOLD_clicked\0"
    "on_BTN_GRIPPER_GRAP_clicked\0"
    "on_BTN_GRIPPER_VISION_clicked\0"
    "on_CB_GRIPPER_GE_CMD_WRITE_clicked\0"
    "on_BTN_SET_IP_PORT_KETI_clicked\0"
    "on_BTN_SET_IP_PORT_KITECH_clicked\0"
    "on_BTN_SET_CALIB_T_V2N_clicked\0"
    "on_BTN_SET_CALIB_T_N2E_clicked\0"
    "on_BTN_VISION_OUT_SAVE_clicked\0"
    "on_BTN_LIFT_SERIAL_OPEN_clicked\0"
    "on_BTN_OMRON_ADD_clicked\0"
    "on_BTN_LIFT_HOMING_clicked\0"
    "on_BTN_VISION_OUT_LOAD_clicked\0"
    "on_BTN_RB5_MOVE_GRAPS_POINT_clicked\0"
    "on_BTN_RB5_CALC_GRAPS_POINT_clicked\0"
    "on_BTN_SET_GRAPS_POINT_clicked\0"
    "on_BTN_LOAD_GRAPS_POINT_clicked\0"
    "on_BTN_TE_GLOBAL_CLEAR_clicked\0"
    "on_BTN_VISION_OUT_SET_clicked\0"
    "on_BTN_LIFT_REQ_DATA_clicked\0"
    "on_btn_say_clicked\0on_BTN_SH_11_clicked\0"
    "on_BTN_SH_12_clicked\0on_BTN_SH_13_clicked\0"
    "on_BTN_SH_14_clicked\0on_BTN_SH_21_clicked\0"
    "on_BTN_SH_22_clicked\0on_BTN_SH_23_clicked\0"
    "on_BTN_SH_24_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      65,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  339,    2, 0x08 /* Private */,
       3,    0,  340,    2, 0x08 /* Private */,
       4,    0,  341,    2, 0x08 /* Private */,
       5,    2,  342,    2, 0x08 /* Private */,
       8,    2,  347,    2, 0x08 /* Private */,
       9,    0,  352,    2, 0x08 /* Private */,
      10,    0,  353,    2, 0x08 /* Private */,
      11,    0,  354,    2, 0x08 /* Private */,
      12,    0,  355,    2, 0x08 /* Private */,
      13,    0,  356,    2, 0x08 /* Private */,
      14,    0,  357,    2, 0x08 /* Private */,
      15,    0,  358,    2, 0x08 /* Private */,
      16,    0,  359,    2, 0x08 /* Private */,
      17,    0,  360,    2, 0x08 /* Private */,
      18,    0,  361,    2, 0x08 /* Private */,
      19,    0,  362,    2, 0x08 /* Private */,
      20,    0,  363,    2, 0x08 /* Private */,
      21,    0,  364,    2, 0x08 /* Private */,
      22,    0,  365,    2, 0x08 /* Private */,
      23,    0,  366,    2, 0x08 /* Private */,
      24,    0,  367,    2, 0x08 /* Private */,
      25,    0,  368,    2, 0x08 /* Private */,
      26,    0,  369,    2, 0x08 /* Private */,
      27,    0,  370,    2, 0x08 /* Private */,
      28,    0,  371,    2, 0x08 /* Private */,
      29,    0,  372,    2, 0x08 /* Private */,
      30,    0,  373,    2, 0x08 /* Private */,
      31,    1,  374,    2, 0x08 /* Private */,
      33,    1,  377,    2, 0x08 /* Private */,
      35,    0,  380,    2, 0x08 /* Private */,
      36,    0,  381,    2, 0x08 /* Private */,
      37,    0,  382,    2, 0x08 /* Private */,
      38,    0,  383,    2, 0x08 /* Private */,
      39,    0,  384,    2, 0x08 /* Private */,
      40,    0,  385,    2, 0x08 /* Private */,
      41,    0,  386,    2, 0x08 /* Private */,
      42,    0,  387,    2, 0x08 /* Private */,
      43,    0,  388,    2, 0x08 /* Private */,
      44,    0,  389,    2, 0x08 /* Private */,
      45,    0,  390,    2, 0x08 /* Private */,
      46,    0,  391,    2, 0x08 /* Private */,
      47,    0,  392,    2, 0x08 /* Private */,
      48,    0,  393,    2, 0x08 /* Private */,
      49,    0,  394,    2, 0x08 /* Private */,
      50,    0,  395,    2, 0x08 /* Private */,
      51,    0,  396,    2, 0x08 /* Private */,
      52,    0,  397,    2, 0x08 /* Private */,
      53,    0,  398,    2, 0x08 /* Private */,
      54,    0,  399,    2, 0x08 /* Private */,
      55,    0,  400,    2, 0x08 /* Private */,
      56,    0,  401,    2, 0x08 /* Private */,
      57,    0,  402,    2, 0x08 /* Private */,
      58,    0,  403,    2, 0x08 /* Private */,
      59,    0,  404,    2, 0x08 /* Private */,
      60,    0,  405,    2, 0x08 /* Private */,
      61,    0,  406,    2, 0x08 /* Private */,
      62,    0,  407,    2, 0x08 /* Private */,
      63,    0,  408,    2, 0x08 /* Private */,
      64,    0,  409,    2, 0x08 /* Private */,
      65,    0,  410,    2, 0x08 /* Private */,
      66,    0,  411,    2, 0x08 /* Private */,
      67,    0,  412,    2, 0x08 /* Private */,
      68,    0,  413,    2, 0x08 /* Private */,
      69,    0,  414,    2, 0x08 /* Private */,
      70,    0,  415,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    6,    7,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   32,
    QMetaType::Void, QMetaType::Int,   34,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_UPDATE_UI(); break;
        case 1: _t->Update_UI(); break;
        case 2: _t->Update_Log(); break;
        case 3: _t->mouse_clicked((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 4: _t->mouse_released((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 5: _t->on_BTN_CONNECT_GRIPPER_clicked(); break;
        case 6: _t->on_BTN_CONNECT_OMRON_clicked(); break;
        case 7: _t->on_BTN_CONNECT_LIFT_clicked(); break;
        case 8: _t->on_BTN_CONNECT_RB5_clicked(); break;
        case 9: _t->on_BTN_CONNECT_VISION_clicked(); break;
        case 10: _t->on_BTN_GLOBAL_INIT_clicked(); break;
        case 11: _t->on_BTN_CHECK_SOCKET_STATUS_clicked(); break;
        case 12: _t->on_BTN_RB5_MOVE_INIT_clicked(); break;
        case 13: _t->on_BTN_RB5_MOVE_VISION_clicked(); break;
        case 14: _t->on_BTN_RB5_MOVE_GRIPPER_READY_clicked(); break;
        case 15: _t->on_BTN_RB5_MOVE_GRIPPER_GRAPS_clicked(); break;
        case 16: _t->on_BTN_RB5_MOVE_EXTRA_1_clicked(); break;
        case 17: _t->on_BTN_RB5_MOVE_EXTRA_2_clicked(); break;
        case 18: _t->on_BTN_RB5_SAVE_INIT_clicked(); break;
        case 19: _t->on_BTN_RB5_SAVE_VISION_clicked(); break;
        case 20: _t->on_BTN_RB5_SAVE_GRIPPER_READY_clicked(); break;
        case 21: _t->on_BTN_RB5_SAVE_GRIPPER_GRAPS_clicked(); break;
        case 22: _t->on_BTN_RB5_SAVE_EXTRA_1_clicked(); break;
        case 23: _t->on_BTN_RB5_SAVE_EXTRA_2_clicked(); break;
        case 24: _t->on_BTN_RB5_PASUE_clicked(); break;
        case 25: _t->on_BTN_RB5_RESUME_clicked(); break;
        case 26: _t->on_BTN_RB5_HOLT_clicked(); break;
        case 27: _t->on_SLIDER_RB5_SPEED_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->on_SB_RB5_SPEED_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->on_BTN_RB5_MODE_clicked(); break;
        case 30: _t->on_BTN_SENARIO_CUSTOM_ADD_clicked(); break;
        case 31: _t->on_BTN_SENARIO_CUSTOM_DEL_clicked(); break;
        case 32: _t->on_BTN_SENARIO_EXECUTION_BASIC_clicked(); break;
        case 33: _t->on_BTN_SENARIO_EXECUTION_CUSTOM_clicked(); break;
        case 34: _t->on_BTN_VISION_CMD_WRITE_clicked(); break;
        case 35: _t->on_BTN_GRIPPER_CMD_WRITE_clicked(); break;
        case 36: _t->on_BTN_GRIPPER_UNFOLD_clicked(); break;
        case 37: _t->on_BTN_GRIPPER_GRAP_clicked(); break;
        case 38: _t->on_BTN_GRIPPER_VISION_clicked(); break;
        case 39: _t->on_CB_GRIPPER_GE_CMD_WRITE_clicked(); break;
        case 40: _t->on_BTN_SET_IP_PORT_KETI_clicked(); break;
        case 41: _t->on_BTN_SET_IP_PORT_KITECH_clicked(); break;
        case 42: _t->on_BTN_SET_CALIB_T_V2N_clicked(); break;
        case 43: _t->on_BTN_SET_CALIB_T_N2E_clicked(); break;
        case 44: _t->on_BTN_VISION_OUT_SAVE_clicked(); break;
        case 45: _t->on_BTN_LIFT_SERIAL_OPEN_clicked(); break;
        case 46: _t->on_BTN_OMRON_ADD_clicked(); break;
        case 47: _t->on_BTN_LIFT_HOMING_clicked(); break;
        case 48: _t->on_BTN_VISION_OUT_LOAD_clicked(); break;
        case 49: _t->on_BTN_RB5_MOVE_GRAPS_POINT_clicked(); break;
        case 50: _t->on_BTN_RB5_CALC_GRAPS_POINT_clicked(); break;
        case 51: _t->on_BTN_SET_GRAPS_POINT_clicked(); break;
        case 52: _t->on_BTN_LOAD_GRAPS_POINT_clicked(); break;
        case 53: _t->on_BTN_TE_GLOBAL_CLEAR_clicked(); break;
        case 54: _t->on_BTN_VISION_OUT_SET_clicked(); break;
        case 55: _t->on_BTN_LIFT_REQ_DATA_clicked(); break;
        case 56: _t->on_btn_say_clicked(); break;
        case 57: _t->on_BTN_SH_11_clicked(); break;
        case 58: _t->on_BTN_SH_12_clicked(); break;
        case 59: _t->on_BTN_SH_13_clicked(); break;
        case 60: _t->on_BTN_SH_14_clicked(); break;
        case 61: _t->on_BTN_SH_21_clicked(); break;
        case 62: _t->on_BTN_SH_22_clicked(); break;
        case 63: _t->on_BTN_SH_23_clicked(); break;
        case 64: _t->on_BTN_SH_24_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 65)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 65;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 65)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 65;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
