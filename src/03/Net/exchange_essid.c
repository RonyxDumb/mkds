#include "03/Net/exchange_essid.h"
#include "03/Net/exchange_wcm_state.h"
#include "03/Menu/slide_buttons.h"
#include "03/Graphics/nce_oam.h"
#include "03/Graphics/oam_range_set.h"
#include "03/Graphics/oam_range.h"
#include "03/System/exp_heap.h"
#include "03/System/tasks.h"
#include "03/Graphics/oam_buffer_entries.h"
#include "03/Net/exchange_result_records.h"
#include "03/Menu/wifi_menu_shared.h"
#include "reset_interrupts_halt.h"
#include "cpu_copy_fill.h"
#include "fixed_vector_math.h"
#include "03/Graphics/oam_range_entry.h"
#include "03/Graphics/nce_file.h"
#include "00/Lib/NitroWiFi/access_point_list.h"
#include "00/Lib/NitroWiFi/access_point_search_defaults.h"
#include "thread_scheduler.h"
#include "tick_counter.h"
#include "float_subtract_int64_muldiv.h"
#include "string.h"
#include "print_memory_multibyte_write.h"
#include "03/Net/essid_packet_socket.h"
#include "00/Lib/NitroWiFi/socket_api_prototypes.h"
#include "narrow_string_functions.h"
#include "03/Menu/wifi_menu_tables.h"
#include "00/Lib/NitroWiFi/socket_objects.h"
#include "00/Lib/NitroWiFi/socket_shutdown_all.h"
#include "alarm_timer.h"
#include "00/Lib/CPS/stack_globals.h"
#include "00/Lib/NitroWiFi/socket_library_startup.h"
#include "03/Net/call_status_callback.h"
#include "03/Menu/exchange_status_record.h"
#include "00/Lib/NitroWiFi/wireless_connection_manager.h"

SOCConfig gExchangeSocketConfig = {{0, 0, 0, 1},
                                   (SocketAllocFn) CallAllocFunctionWithMutex,
                                   (SocketFreeFn) CallFreeFunctionWithMutex,
                                   0,
                                   0xb000a8c0,
                                   0xffffff,
                                   0xc800a8c0,
                                   0x2000a8c0,
                                   0,
                                   0x1000,
                                   0x1000,
                                   0,
                                   0,
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                   "NINTENDO-DS",
                                   4,
                                   0,
                                   0};
const u32 gKeyRoundConstants[10] = {0x1000000,  0x2000000,  0x4000000,  0x8000000,  0x10000000,
                                    0x20000000, 0x40000000, 0x80000000, 0x1b000000, 0x36000000};
const u32 gReversedTableByte1[256] = {
    0xa75051f4, 0x65537e41, 0xa4c31a17, 0x5e963a27, 0x6bcb3bab, 0x45f11f9d, 0x58abacfa, 0x3934be3,  0xfa552030,
    0x6df6ad76, 0x769188cc, 0x4c25f502, 0xd7fc4fe5, 0xcbd7c52a, 0x44802635, 0xa38fb562, 0x5a49deb1, 0x1b6725ba,
    0xe9845ea,  0xc0e15dfe, 0x7502c32f, 0xf012814c, 0x97a38d46, 0xf9c66bd3, 0x5fe7038f, 0x9c951592, 0x7aebbf6d,
    0x59da9552, 0x832dd4be, 0x21d35874, 0x692949e0, 0xc8448ec9, 0x896a75c2, 0x7978f48e, 0x3e6b9958, 0x71dd27b9,
    0x4fb6bee1, 0xad17f088, 0xac66c920, 0x3ab47dce, 0x4a1863df, 0x3182e51a, 0x33609751, 0x7f456253, 0x77e0b164,
    0xae84bb6b, 0xa01cfe81, 0x2b94f908, 0x68587048, 0xfd198f45, 0x6c8794de, 0xf8b7527b, 0xd323ab73, 0x2e2724b,
    0x8f57e31f, 0xab2a6655, 0x2807b2eb, 0xc2032fb5, 0x7b9a86c5, 0x8a5d337,  0x87f23028, 0xa5b223bf, 0x6aba0203,
    0x825ced16, 0x1c2b8acf, 0xb492a779, 0xf2f0f307, 0xe2a14e69, 0xf4cd65da, 0xbed50605, 0x621fd134, 0xfe8ac4a6,
    0x539d342e, 0x55a0a2f3, 0xe132058a, 0xeb75a4f6, 0xec390b83, 0xefaa4060, 0x9f065e71, 0x1051bd6e, 0x8af93e21,
    0x63d96dd,  0x5aedd3e,  0xbd464de6, 0x8db59154, 0x5d0571c4, 0xd46f0406, 0x15ff6050, 0xfb241998, 0xe997d6bd,
    0x43cc8940, 0x9e7767d9, 0x42bdb0e8, 0x8b880789, 0x5b38e719, 0xeedb79c8, 0xa47a17c,  0xfe97c42,  0x1ec9f884,
    0,          0x86830980, 0xed48322b, 0x70ac1e11, 0x724e6c5a, 0xfffbfd0e, 0x38560f85, 0xd51e3dae, 0x3927362d,
    0xd9640a0f, 0xa621685c, 0x54d19b5b, 0x2e3a2436, 0x67b10c0a, 0xe70f9357, 0x96d2b4ee, 0x919e1b9b, 0xc54f80c0,
    0x20a261dc, 0x4b695a77, 0x1a161c12, 0xba0ae293, 0x2ae5c0a0, 0xe0433c22, 0x171d121b, 0xd0b0e09,  0xc7adf28b,
    0xa8b92db6, 0xa9c8141e, 0x198557f1, 0x74caf75,  0xddbbee99, 0x60fda37f, 0x269ff701, 0xf5bc5c72, 0x3bc54466,
    0x7e345bfb, 0x29768b43, 0xc6dccb23, 0xfc68b6ed, 0xf163b8e4, 0xdccad731, 0x85104263, 0x22401397, 0x112084c6,
    0x247d854a, 0x3df8d2bb, 0x3211aef9, 0xa16dc729, 0x2f4b1d9e, 0x30f3dcb2, 0x52ec0d86, 0xe3d077c1, 0x166c2bb3,
    0xb999a970, 0x48fa1194, 0x642247e9, 0x8cc4a8fc, 0x3f1aa0f0, 0x2cd8567d, 0x90ef2233, 0x4ec78749, 0xd1c1d938,
    0xa2fe8cca, 0xb3698d4,  0x81cfa6f5, 0xde28a57a, 0x8e26dab7, 0xbfa43fad, 0x9de42c3a, 0x920d5078, 0xcc9b6a5f,
    0x4662547e, 0x13c2f68d, 0xb8e890d8, 0xf75e2e39, 0xaff582c3, 0x80be9f5d, 0x937c69d0, 0x2da96fd5, 0x12b3cf25,
    0x993bc8ac, 0x7da71018, 0x636ee89c, 0xbb7bdb3b, 0x7809cd26, 0x18f46e59, 0xb701ec9a, 0x9aa8834f, 0x6e65e695,
    0xe67eaaff, 0xcf0821bc, 0xe8e6ef15, 0x9bd9bae7, 0x36ce4a6f, 0x9d4ea9f,  0x7cd629b0, 0xb2af31a4, 0x23312a3f,
    0x9430c6a5, 0x66c035a2, 0xbc37744e, 0xcaa6fc82, 0xd0b0e090, 0xd81533a7, 0x984af104, 0xdaf741ec, 0x500e7fcd,
    0xf62f1791, 0xd68d764d, 0xb04d43ef, 0x4d54ccaa, 0x4dfe496,  0xb5e39ed1, 0x881b4c6a, 0x1fb8c12c, 0x517f4665,
    0xea049d5e, 0x355d018c, 0x7473fa87, 0x412efb0b, 0x1d5ab367, 0xd25292db, 0x5633e910, 0x47136dd6, 0x618c9ad7,
    0xc7a37a1,  0x148e59f8, 0x3c89eb13, 0x27eecea9, 0xc935b761, 0xe5ede11c, 0xb13c7a47, 0xdf599cd2, 0x733f55f2,
    0xce791814, 0x37bf73c7, 0xcdea53f7, 0xaa5b5ffd, 0x6f14df3d, 0xdb867844, 0xf381caaf, 0xc43eb968, 0x342c3824,
    0x405fc2a3, 0xc372161d, 0x250cbce2, 0x498b283c, 0x9541ff0d, 0x17139a8,  0xb3de080c, 0xe49cd8b4, 0xc1906456,
    0x84617bcb, 0xb670d532, 0x5c74486c, 0x5742d0b8};
const u32 gReversedTableByte0[256] = {
    0xf4a75051, 0x4165537e, 0x17a4c31a, 0x275e963a, 0xab6bcb3b, 0x9d45f11f, 0xfa58abac, 0xe303934b, 0x30fa5520,
    0x766df6ad, 0xcc769188, 0x24c25f5,  0xe5d7fc4f, 0x2acbd7c5, 0x35448026, 0x62a38fb5, 0xb15a49de, 0xba1b6725,
    0xea0e9845, 0xfec0e15d, 0x2f7502c3, 0x4cf01281, 0x4697a38d, 0xd3f9c66b, 0x8f5fe703, 0x929c9515, 0x6d7aebbf,
    0x5259da95, 0xbe832dd4, 0x7421d358, 0xe0692949, 0xc9c8448e, 0xc2896a75, 0x8e7978f4, 0x583e6b99, 0xb971dd27,
    0xe14fb6be, 0x88ad17f0, 0x20ac66c9, 0xce3ab47d, 0xdf4a1863, 0x1a3182e5, 0x51336097, 0x537f4562, 0x6477e0b1,
    0x6bae84bb, 0x81a01cfe, 0x82b94f9,  0x48685870, 0x45fd198f, 0xde6c8794, 0x7bf8b752, 0x73d323ab, 0x4b02e272,
    0x1f8f57e3, 0x55ab2a66, 0xeb2807b2, 0xb5c2032f, 0xc57b9a86, 0x3708a5d3, 0x2887f230, 0xbfa5b223, 0x36aba02,
    0x16825ced, 0xcf1c2b8a, 0x79b492a7, 0x7f2f0f3,  0x69e2a14e, 0xdaf4cd65, 0x5bed506,  0x34621fd1, 0xa6fe8ac4,
    0x2e539d34, 0xf355a0a2, 0x8ae13205, 0xf6eb75a4, 0x83ec390b, 0x60efaa40, 0x719f065e, 0x6e1051bd, 0x218af93e,
    0xdd063d96, 0x3e05aedd, 0xe6bd464d, 0x548db591, 0xc45d0571, 0x6d46f04,  0x5015ff60, 0x98fb2419, 0xbde997d6,
    0x4043cc89, 0xd99e7767, 0xe842bdb0, 0x898b8807, 0x195b38e7, 0xc8eedb79, 0x7c0a47a1, 0x420fe97c, 0x841ec9f8,
    0,          0x80868309, 0x2bed4832, 0x1170ac1e, 0x5a724e6c, 0xefffbfd,  0x8538560f, 0xaed51e3d, 0x2d392736,
    0xfd9640a,  0x5ca62168, 0x5b54d19b, 0x362e3a24, 0xa67b10c,  0x57e70f93, 0xee96d2b4, 0x9b919e1b, 0xc0c54f80,
    0xdc20a261, 0x774b695a, 0x121a161c, 0x93ba0ae2, 0xa02ae5c0, 0x22e0433c, 0x1b171d12, 0x90d0b0e,  0x8bc7adf2,
    0xb6a8b92d, 0x1ea9c814, 0xf1198557, 0x75074caf, 0x99ddbbee, 0x7f60fda3, 0x1269ff7,  0x72f5bc5c, 0x663bc544,
    0xfb7e345b, 0x4329768b, 0x23c6dccb, 0xedfc68b6, 0xe4f163b8, 0x31dccad7, 0x63851042, 0x97224013, 0xc6112084,
    0x4a247d85, 0xbb3df8d2, 0xf93211ae, 0x29a16dc7, 0x9e2f4b1d, 0xb230f3dc, 0x8652ec0d, 0xc1e3d077, 0xb3166c2b,
    0x70b999a9, 0x9448fa11, 0xe9642247, 0xfc8cc4a8, 0xf03f1aa0, 0x7d2cd856, 0x3390ef22, 0x494ec787, 0x38d1c1d9,
    0xcaa2fe8c, 0xd40b3698, 0xf581cfa6, 0x7ade28a5, 0xb78e26da, 0xadbfa43f, 0x3a9de42c, 0x78920d50, 0x5fcc9b6a,
    0x7e466254, 0x8d13c2f6, 0xd8b8e890, 0x39f75e2e, 0xc3aff582, 0x5d80be9f, 0xd0937c69, 0xd52da96f, 0x2512b3cf,
    0xac993bc8, 0x187da710, 0x9c636ee8, 0x3bbb7bdb, 0x267809cd, 0x5918f46e, 0x9ab701ec, 0x4f9aa883, 0x956e65e6,
    0xffe67eaa, 0xbccf0821, 0x15e8e6ef, 0xe79bd9ba, 0x6f36ce4a, 0x9f09d4ea, 0xb07cd629, 0xa4b2af31, 0x3f23312a,
    0xa59430c6, 0xa266c035, 0x4ebc3774, 0x82caa6fc, 0x90d0b0e0, 0xa7d81533, 0x4984af1,  0xecdaf741, 0xcd500e7f,
    0x91f62f17, 0x4dd68d76, 0xefb04d43, 0xaa4d54cc, 0x9604dfe4, 0xd1b5e39e, 0x6a881b4c, 0x2c1fb8c1, 0x65517f46,
    0x5eea049d, 0x8c355d01, 0x877473fa, 0xb412efb,  0x671d5ab3, 0xdbd25292, 0x105633e9, 0xd647136d, 0xd7618c9a,
    0xa10c7a37, 0xf8148e59, 0x133c89eb, 0xa927eece, 0x61c935b7, 0x1ce5ede1, 0x47b13c7a, 0xd2df599c, 0xf2733f55,
    0x14ce7918, 0xc737bf73, 0xf7cdea53, 0xfdaa5b5f, 0x3d6f14df, 0x44db8678, 0xaff381ca, 0x68c43eb9, 0x24342c38,
    0xa3405fc2, 0x1dc37216, 0xe2250cbc, 0x3c498b28, 0xd9541ff,  0xa8017139, 0xcb3de08,  0xb4e49cd8, 0x56c19064,
    0xcb84617b, 0x32b670d5, 0x6c5c7448, 0xb85742d0};
const u32 gReversedSubstitutionTable[256] = {
    0x52525252, 0x9090909,  0x6a6a6a6a, 0xd5d5d5d5, 0x30303030, 0x36363636, 0xa5a5a5a5, 0x38383838, 0xbfbfbfbf,
    0x40404040, 0xa3a3a3a3, 0x9e9e9e9e, 0x81818181, 0xf3f3f3f3, 0xd7d7d7d7, 0xfbfbfbfb, 0x7c7c7c7c, 0xe3e3e3e3,
    0x39393939, 0x82828282, 0x9b9b9b9b, 0x2f2f2f2f, 0xffffffff, 0x87878787, 0x34343434, 0x8e8e8e8e, 0x43434343,
    0x44444444, 0xc4c4c4c4, 0xdededede, 0xe9e9e9e9, 0xcbcbcbcb, 0x54545454, 0x7b7b7b7b, 0x94949494, 0x32323232,
    0xa6a6a6a6, 0xc2c2c2c2, 0x23232323, 0x3d3d3d3d, 0xeeeeeeee, 0x4c4c4c4c, 0x95959595, 0xb0b0b0b,  0x42424242,
    0xfafafafa, 0xc3c3c3c3, 0x4e4e4e4e, 0x8080808,  0x2e2e2e2e, 0xa1a1a1a1, 0x66666666, 0x28282828, 0xd9d9d9d9,
    0x24242424, 0xb2b2b2b2, 0x76767676, 0x5b5b5b5b, 0xa2a2a2a2, 0x49494949, 0x6d6d6d6d, 0x8b8b8b8b, 0xd1d1d1d1,
    0x25252525, 0x72727272, 0xf8f8f8f8, 0xf6f6f6f6, 0x64646464, 0x86868686, 0x68686868, 0x98989898, 0x16161616,
    0xd4d4d4d4, 0xa4a4a4a4, 0x5c5c5c5c, 0xcccccccc, 0x5d5d5d5d, 0x65656565, 0xb6b6b6b6, 0x92929292, 0x6c6c6c6c,
    0x70707070, 0x48484848, 0x50505050, 0xfdfdfdfd, 0xedededed, 0xb9b9b9b9, 0xdadadada, 0x5e5e5e5e, 0x15151515,
    0x46464646, 0x57575757, 0xa7a7a7a7, 0x8d8d8d8d, 0x9d9d9d9d, 0x84848484, 0x90909090, 0xd8d8d8d8, 0xabababab,
    0,          0x8c8c8c8c, 0xbcbcbcbc, 0xd3d3d3d3, 0xa0a0a0a,  0xf7f7f7f7, 0xe4e4e4e4, 0x58585858, 0x5050505,
    0xb8b8b8b8, 0xb3b3b3b3, 0x45454545, 0x6060606,  0xd0d0d0d0, 0x2c2c2c2c, 0x1e1e1e1e, 0x8f8f8f8f, 0xcacacaca,
    0x3f3f3f3f, 0xf0f0f0f,  0x2020202,  0xc1c1c1c1, 0xafafafaf, 0xbdbdbdbd, 0x3030303,  0x1010101,  0x13131313,
    0x8a8a8a8a, 0x6b6b6b6b, 0x3a3a3a3a, 0x91919191, 0x11111111, 0x41414141, 0x4f4f4f4f, 0x67676767, 0xdcdcdcdc,
    0xeaeaeaea, 0x97979797, 0xf2f2f2f2, 0xcfcfcfcf, 0xcececece, 0xf0f0f0f0, 0xb4b4b4b4, 0xe6e6e6e6, 0x73737373,
    0x96969696, 0xacacacac, 0x74747474, 0x22222222, 0xe7e7e7e7, 0xadadadad, 0x35353535, 0x85858585, 0xe2e2e2e2,
    0xf9f9f9f9, 0x37373737, 0xe8e8e8e8, 0x1c1c1c1c, 0x75757575, 0xdfdfdfdf, 0x6e6e6e6e, 0x47474747, 0xf1f1f1f1,
    0x1a1a1a1a, 0x71717171, 0x1d1d1d1d, 0x29292929, 0xc5c5c5c5, 0x89898989, 0x6f6f6f6f, 0xb7b7b7b7, 0x62626262,
    0xe0e0e0e,  0xaaaaaaaa, 0x18181818, 0xbebebebe, 0x1b1b1b1b, 0xfcfcfcfc, 0x56565656, 0x3e3e3e3e, 0x4b4b4b4b,
    0xc6c6c6c6, 0xd2d2d2d2, 0x79797979, 0x20202020, 0x9a9a9a9a, 0xdbdbdbdb, 0xc0c0c0c0, 0xfefefefe, 0x78787878,
    0xcdcdcdcd, 0x5a5a5a5a, 0xf4f4f4f4, 0x1f1f1f1f, 0xdddddddd, 0xa8a8a8a8, 0x33333333, 0x88888888, 0x7070707,
    0xc7c7c7c7, 0x31313131, 0xb1b1b1b1, 0x12121212, 0x10101010, 0x59595959, 0x27272727, 0x80808080, 0xecececec,
    0x5f5f5f5f, 0x60606060, 0x51515151, 0x7f7f7f7f, 0xa9a9a9a9, 0x19191919, 0xb5b5b5b5, 0x4a4a4a4a, 0xd0d0d0d,
    0x2d2d2d2d, 0xe5e5e5e5, 0x7a7a7a7a, 0x9f9f9f9f, 0x93939393, 0xc9c9c9c9, 0x9c9c9c9c, 0xefefefef, 0xa0a0a0a0,
    0xe0e0e0e0, 0x3b3b3b3b, 0x4d4d4d4d, 0xaeaeaeae, 0x2a2a2a2a, 0xf5f5f5f5, 0xb0b0b0b0, 0xc8c8c8c8, 0xebebebeb,
    0xbbbbbbbb, 0x3c3c3c3c, 0x83838383, 0x53535353, 0x99999999, 0x61616161, 0x17171717, 0x2b2b2b2b, 0x4040404,
    0x7e7e7e7e, 0xbabababa, 0x77777777, 0xd6d6d6d6, 0x26262626, 0xe1e1e1e1, 0x69696969, 0x14141414, 0x63636363,
    0x55555555, 0x21212121, 0xc0c0c0c,  0x7d7d7d7d};
u32 gFormatAddressesFlag = 1;
u8 *gFirstReplyItemBuffer = gBodyBuffer + 8;
const u32 gTransformTableByte3[256] = {
    0xc66363a5, 0xf87c7c84, 0xee777799, 0xf67b7b8d, 0xfff2f20d, 0xd66b6bbd, 0xde6f6fb1, 0x91c5c554, 0x60303050,
    0x2010103,  0xce6767a9, 0x562b2b7d, 0xe7fefe19, 0xb5d7d762, 0x4dababe6, 0xec76769a, 0x8fcaca45, 0x1f82829d,
    0x89c9c940, 0xfa7d7d87, 0xeffafa15, 0xb25959eb, 0x8e4747c9, 0xfbf0f00b, 0x41adadec, 0xb3d4d467, 0x5fa2a2fd,
    0x45afafea, 0x239c9cbf, 0x53a4a4f7, 0xe4727296, 0x9bc0c05b, 0x75b7b7c2, 0xe1fdfd1c, 0x3d9393ae, 0x4c26266a,
    0x6c36365a, 0x7e3f3f41, 0xf5f7f702, 0x83cccc4f, 0x6834345c, 0x51a5a5f4, 0xd1e5e534, 0xf9f1f108, 0xe2717193,
    0xabd8d873, 0x62313153, 0x2a15153f, 0x804040c,  0x95c7c752, 0x46232365, 0x9dc3c35e, 0x30181828, 0x379696a1,
    0xa05050f,  0x2f9a9ab5, 0xe070709,  0x24121236, 0x1b80809b, 0xdfe2e23d, 0xcdebeb26, 0x4e272769, 0x7fb2b2cd,
    0xea75759f, 0x1209091b, 0x1d83839e, 0x582c2c74, 0x341a1a2e, 0x361b1b2d, 0xdc6e6eb2, 0xb45a5aee, 0x5ba0a0fb,
    0xa45252f6, 0x763b3b4d, 0xb7d6d661, 0x7db3b3ce, 0x5229297b, 0xdde3e33e, 0x5e2f2f71, 0x13848497, 0xa65353f5,
    0xb9d1d168, 0,          0xc1eded2c, 0x40202060, 0xe3fcfc1f, 0x79b1b1c8, 0xb65b5bed, 0xd46a6abe, 0x8dcbcb46,
    0x67bebed9, 0x7239394b, 0x944a4ade, 0x984c4cd4, 0xb05858e8, 0x85cfcf4a, 0xbbd0d06b, 0xc5efef2a, 0x4faaaae5,
    0xedfbfb16, 0x864343c5, 0x9a4d4dd7, 0x66333355, 0x11858594, 0x8a4545cf, 0xe9f9f910, 0x4020206,  0xfe7f7f81,
    0xa05050f0, 0x783c3c44, 0x259f9fba, 0x4ba8a8e3, 0xa25151f3, 0x5da3a3fe, 0x804040c0, 0x58f8f8a,  0x3f9292ad,
    0x219d9dbc, 0x70383848, 0xf1f5f504, 0x63bcbcdf, 0x77b6b6c1, 0xafdada75, 0x42212163, 0x20101030, 0xe5ffff1a,
    0xfdf3f30e, 0xbfd2d26d, 0x81cdcd4c, 0x180c0c14, 0x26131335, 0xc3ecec2f, 0xbe5f5fe1, 0x359797a2, 0x884444cc,
    0x2e171739, 0x93c4c457, 0x55a7a7f2, 0xfc7e7e82, 0x7a3d3d47, 0xc86464ac, 0xba5d5de7, 0x3219192b, 0xe6737395,
    0xc06060a0, 0x19818198, 0x9e4f4fd1, 0xa3dcdc7f, 0x44222266, 0x542a2a7e, 0x3b9090ab, 0xb888883,  0x8c4646ca,
    0xc7eeee29, 0x6bb8b8d3, 0x2814143c, 0xa7dede79, 0xbc5e5ee2, 0x160b0b1d, 0xaddbdb76, 0xdbe0e03b, 0x64323256,
    0x743a3a4e, 0x140a0a1e, 0x924949db, 0xc06060a,  0x4824246c, 0xb85c5ce4, 0x9fc2c25d, 0xbdd3d36e, 0x43acacef,
    0xc46262a6, 0x399191a8, 0x319595a4, 0xd3e4e437, 0xf279798b, 0xd5e7e732, 0x8bc8c843, 0x6e373759, 0xda6d6db7,
    0x18d8d8c,  0xb1d5d564, 0x9c4e4ed2, 0x49a9a9e0, 0xd86c6cb4, 0xac5656fa, 0xf3f4f407, 0xcfeaea25, 0xca6565af,
    0xf47a7a8e, 0x47aeaee9, 0x10080818, 0x6fbabad5, 0xf0787888, 0x4a25256f, 0x5c2e2e72, 0x381c1c24, 0x57a6a6f1,
    0x73b4b4c7, 0x97c6c651, 0xcbe8e823, 0xa1dddd7c, 0xe874749c, 0x3e1f1f21, 0x964b4bdd, 0x61bdbddc, 0xd8b8b86,
    0xf8a8a85,  0xe0707090, 0x7c3e3e42, 0x71b5b5c4, 0xcc6666aa, 0x904848d8, 0x6030305,  0xf7f6f601, 0x1c0e0e12,
    0xc26161a3, 0x6a35355f, 0xae5757f9, 0x69b9b9d0, 0x17868691, 0x99c1c158, 0x3a1d1d27, 0x279e9eb9, 0xd9e1e138,
    0xebf8f813, 0x2b9898b3, 0x22111133, 0xd26969bb, 0xa9d9d970, 0x78e8e89,  0x339494a7, 0x2d9b9bb6, 0x3c1e1e22,
    0x15878792, 0xc9e9e920, 0x87cece49, 0xaa5555ff, 0x50282878, 0xa5dfdf7a, 0x38c8c8f,  0x59a1a1f8, 0x9898980,
    0x1a0d0d17, 0x65bfbfda, 0xd7e6e631, 0x844242c6, 0xd06868b8, 0x824141c3, 0x299999b0, 0x5a2d2d77, 0x1e0f0f11,
    0x7bb0b0cb, 0xa85454fc, 0x6dbbbbd6, 0x2c16163a};
const u32 gTransformTableByte2[256] = {
    0xa5c66363, 0x84f87c7c, 0x99ee7777, 0x8df67b7b, 0xdfff2f2,  0xbdd66b6b, 0xb1de6f6f, 0x5491c5c5, 0x50603030,
    0x3020101,  0xa9ce6767, 0x7d562b2b, 0x19e7fefe, 0x62b5d7d7, 0xe64dabab, 0x9aec7676, 0x458fcaca, 0x9d1f8282,
    0x4089c9c9, 0x87fa7d7d, 0x15effafa, 0xebb25959, 0xc98e4747, 0xbfbf0f0,  0xec41adad, 0x67b3d4d4, 0xfd5fa2a2,
    0xea45afaf, 0xbf239c9c, 0xf753a4a4, 0x96e47272, 0x5b9bc0c0, 0xc275b7b7, 0x1ce1fdfd, 0xae3d9393, 0x6a4c2626,
    0x5a6c3636, 0x417e3f3f, 0x2f5f7f7,  0x4f83cccc, 0x5c683434, 0xf451a5a5, 0x34d1e5e5, 0x8f9f1f1,  0x93e27171,
    0x73abd8d8, 0x53623131, 0x3f2a1515, 0xc080404,  0x5295c7c7, 0x65462323, 0x5e9dc3c3, 0x28301818, 0xa1379696,
    0xf0a0505,  0xb52f9a9a, 0x90e0707,  0x36241212, 0x9b1b8080, 0x3ddfe2e2, 0x26cdebeb, 0x694e2727, 0xcd7fb2b2,
    0x9fea7575, 0x1b120909, 0x9e1d8383, 0x74582c2c, 0x2e341a1a, 0x2d361b1b, 0xb2dc6e6e, 0xeeb45a5a, 0xfb5ba0a0,
    0xf6a45252, 0x4d763b3b, 0x61b7d6d6, 0xce7db3b3, 0x7b522929, 0x3edde3e3, 0x715e2f2f, 0x97138484, 0xf5a65353,
    0x68b9d1d1, 0,          0x2cc1eded, 0x60402020, 0x1fe3fcfc, 0xc879b1b1, 0xedb65b5b, 0xbed46a6a, 0x468dcbcb,
    0xd967bebe, 0x4b723939, 0xde944a4a, 0xd4984c4c, 0xe8b05858, 0x4a85cfcf, 0x6bbbd0d0, 0x2ac5efef, 0xe54faaaa,
    0x16edfbfb, 0xc5864343, 0xd79a4d4d, 0x55663333, 0x94118585, 0xcf8a4545, 0x10e9f9f9, 0x6040202,  0x81fe7f7f,
    0xf0a05050, 0x44783c3c, 0xba259f9f, 0xe34ba8a8, 0xf3a25151, 0xfe5da3a3, 0xc0804040, 0x8a058f8f, 0xad3f9292,
    0xbc219d9d, 0x48703838, 0x4f1f5f5,  0xdf63bcbc, 0xc177b6b6, 0x75afdada, 0x63422121, 0x30201010, 0x1ae5ffff,
    0xefdf3f3,  0x6dbfd2d2, 0x4c81cdcd, 0x14180c0c, 0x35261313, 0x2fc3ecec, 0xe1be5f5f, 0xa2359797, 0xcc884444,
    0x392e1717, 0x5793c4c4, 0xf255a7a7, 0x82fc7e7e, 0x477a3d3d, 0xacc86464, 0xe7ba5d5d, 0x2b321919, 0x95e67373,
    0xa0c06060, 0x98198181, 0xd19e4f4f, 0x7fa3dcdc, 0x66442222, 0x7e542a2a, 0xab3b9090, 0x830b8888, 0xca8c4646,
    0x29c7eeee, 0xd36bb8b8, 0x3c281414, 0x79a7dede, 0xe2bc5e5e, 0x1d160b0b, 0x76addbdb, 0x3bdbe0e0, 0x56643232,
    0x4e743a3a, 0x1e140a0a, 0xdb924949, 0xa0c0606,  0x6c482424, 0xe4b85c5c, 0x5d9fc2c2, 0x6ebdd3d3, 0xef43acac,
    0xa6c46262, 0xa8399191, 0xa4319595, 0x37d3e4e4, 0x8bf27979, 0x32d5e7e7, 0x438bc8c8, 0x596e3737, 0xb7da6d6d,
    0x8c018d8d, 0x64b1d5d5, 0xd29c4e4e, 0xe049a9a9, 0xb4d86c6c, 0xfaac5656, 0x7f3f4f4,  0x25cfeaea, 0xafca6565,
    0x8ef47a7a, 0xe947aeae, 0x18100808, 0xd56fbaba, 0x88f07878, 0x6f4a2525, 0x725c2e2e, 0x24381c1c, 0xf157a6a6,
    0xc773b4b4, 0x5197c6c6, 0x23cbe8e8, 0x7ca1dddd, 0x9ce87474, 0x213e1f1f, 0xdd964b4b, 0xdc61bdbd, 0x860d8b8b,
    0x850f8a8a, 0x90e07070, 0x427c3e3e, 0xc471b5b5, 0xaacc6666, 0xd8904848, 0x5060303,  0x1f7f6f6,  0x121c0e0e,
    0xa3c26161, 0x5f6a3535, 0xf9ae5757, 0xd069b9b9, 0x91178686, 0x5899c1c1, 0x273a1d1d, 0xb9279e9e, 0x38d9e1e1,
    0x13ebf8f8, 0xb32b9898, 0x33221111, 0xbbd26969, 0x70a9d9d9, 0x89078e8e, 0xa7339494, 0xb62d9b9b, 0x223c1e1e,
    0x92158787, 0x20c9e9e9, 0x4987cece, 0xffaa5555, 0x78502828, 0x7aa5dfdf, 0x8f038c8c, 0xf859a1a1, 0x80098989,
    0x171a0d0d, 0xda65bfbf, 0x31d7e6e6, 0xc6844242, 0xb8d06868, 0xc3824141, 0xb0299999, 0x775a2d2d, 0x111e0f0f,
    0xcb7bb0b0, 0xfca85454, 0xd66dbbbb, 0x3a2c1616};
const u32 gTransformTableByte1[256] = {
    0x63a5c663, 0x7c84f87c, 0x7799ee77, 0x7b8df67b, 0xf20dfff2, 0x6bbdd66b, 0x6fb1de6f, 0xc55491c5, 0x30506030,
    0x1030201,  0x67a9ce67, 0x2b7d562b, 0xfe19e7fe, 0xd762b5d7, 0xabe64dab, 0x769aec76, 0xca458fca, 0x829d1f82,
    0xc94089c9, 0x7d87fa7d, 0xfa15effa, 0x59ebb259, 0x47c98e47, 0xf00bfbf0, 0xadec41ad, 0xd467b3d4, 0xa2fd5fa2,
    0xafea45af, 0x9cbf239c, 0xa4f753a4, 0x7296e472, 0xc05b9bc0, 0xb7c275b7, 0xfd1ce1fd, 0x93ae3d93, 0x266a4c26,
    0x365a6c36, 0x3f417e3f, 0xf702f5f7, 0xcc4f83cc, 0x345c6834, 0xa5f451a5, 0xe534d1e5, 0xf108f9f1, 0x7193e271,
    0xd873abd8, 0x31536231, 0x153f2a15, 0x40c0804,  0xc75295c7, 0x23654623, 0xc35e9dc3, 0x18283018, 0x96a13796,
    0x50f0a05,  0x9ab52f9a, 0x7090e07,  0x12362412, 0x809b1b80, 0xe23ddfe2, 0xeb26cdeb, 0x27694e27, 0xb2cd7fb2,
    0x759fea75, 0x91b1209,  0x839e1d83, 0x2c74582c, 0x1a2e341a, 0x1b2d361b, 0x6eb2dc6e, 0x5aeeb45a, 0xa0fb5ba0,
    0x52f6a452, 0x3b4d763b, 0xd661b7d6, 0xb3ce7db3, 0x297b5229, 0xe33edde3, 0x2f715e2f, 0x84971384, 0x53f5a653,
    0xd168b9d1, 0,          0xed2cc1ed, 0x20604020, 0xfc1fe3fc, 0xb1c879b1, 0x5bedb65b, 0x6abed46a, 0xcb468dcb,
    0xbed967be, 0x394b7239, 0x4ade944a, 0x4cd4984c, 0x58e8b058, 0xcf4a85cf, 0xd06bbbd0, 0xef2ac5ef, 0xaae54faa,
    0xfb16edfb, 0x43c58643, 0x4dd79a4d, 0x33556633, 0x85941185, 0x45cf8a45, 0xf910e9f9, 0x2060402,  0x7f81fe7f,
    0x50f0a050, 0x3c44783c, 0x9fba259f, 0xa8e34ba8, 0x51f3a251, 0xa3fe5da3, 0x40c08040, 0x8f8a058f, 0x92ad3f92,
    0x9dbc219d, 0x38487038, 0xf504f1f5, 0xbcdf63bc, 0xb6c177b6, 0xda75afda, 0x21634221, 0x10302010, 0xff1ae5ff,
    0xf30efdf3, 0xd26dbfd2, 0xcd4c81cd, 0xc14180c,  0x13352613, 0xec2fc3ec, 0x5fe1be5f, 0x97a23597, 0x44cc8844,
    0x17392e17, 0xc45793c4, 0xa7f255a7, 0x7e82fc7e, 0x3d477a3d, 0x64acc864, 0x5de7ba5d, 0x192b3219, 0x7395e673,
    0x60a0c060, 0x81981981, 0x4fd19e4f, 0xdc7fa3dc, 0x22664422, 0x2a7e542a, 0x90ab3b90, 0x88830b88, 0x46ca8c46,
    0xee29c7ee, 0xb8d36bb8, 0x143c2814, 0xde79a7de, 0x5ee2bc5e, 0xb1d160b,  0xdb76addb, 0xe03bdbe0, 0x32566432,
    0x3a4e743a, 0xa1e140a,  0x49db9249, 0x60a0c06,  0x246c4824, 0x5ce4b85c, 0xc25d9fc2, 0xd36ebdd3, 0xacef43ac,
    0x62a6c462, 0x91a83991, 0x95a43195, 0xe437d3e4, 0x798bf279, 0xe732d5e7, 0xc8438bc8, 0x37596e37, 0x6db7da6d,
    0x8d8c018d, 0xd564b1d5, 0x4ed29c4e, 0xa9e049a9, 0x6cb4d86c, 0x56faac56, 0xf407f3f4, 0xea25cfea, 0x65afca65,
    0x7a8ef47a, 0xaee947ae, 0x8181008,  0xbad56fba, 0x7888f078, 0x256f4a25, 0x2e725c2e, 0x1c24381c, 0xa6f157a6,
    0xb4c773b4, 0xc65197c6, 0xe823cbe8, 0xdd7ca1dd, 0x749ce874, 0x1f213e1f, 0x4bdd964b, 0xbddc61bd, 0x8b860d8b,
    0x8a850f8a, 0x7090e070, 0x3e427c3e, 0xb5c471b5, 0x66aacc66, 0x48d89048, 0x3050603,  0xf601f7f6, 0xe121c0e,
    0x61a3c261, 0x355f6a35, 0x57f9ae57, 0xb9d069b9, 0x86911786, 0xc15899c1, 0x1d273a1d, 0x9eb9279e, 0xe138d9e1,
    0xf813ebf8, 0x98b32b98, 0x11332211, 0x69bbd269, 0xd970a9d9, 0x8e89078e, 0x94a73394, 0x9bb62d9b, 0x1e223c1e,
    0x87921587, 0xe920c9e9, 0xce4987ce, 0x55ffaa55, 0x28785028, 0xdf7aa5df, 0x8c8f038c, 0xa1f859a1, 0x89800989,
    0xd171a0d,  0xbfda65bf, 0xe631d7e6, 0x42c68442, 0x68b8d068, 0x41c38241, 0x99b02999, 0x2d775a2d, 0xf111e0f,
    0xb0cb7bb0, 0x54fca854, 0xbbd66dbb, 0x163a2c16};
const u32 gTransformTableByte0[256] = {
    0x6363a5c6, 0x7c7c84f8, 0x777799ee, 0x7b7b8df6, 0xf2f20dff, 0x6b6bbdd6, 0x6f6fb1de, 0xc5c55491, 0x30305060,
    0x1010302,  0x6767a9ce, 0x2b2b7d56, 0xfefe19e7, 0xd7d762b5, 0xababe64d, 0x76769aec, 0xcaca458f, 0x82829d1f,
    0xc9c94089, 0x7d7d87fa, 0xfafa15ef, 0x5959ebb2, 0x4747c98e, 0xf0f00bfb, 0xadadec41, 0xd4d467b3, 0xa2a2fd5f,
    0xafafea45, 0x9c9cbf23, 0xa4a4f753, 0x727296e4, 0xc0c05b9b, 0xb7b7c275, 0xfdfd1ce1, 0x9393ae3d, 0x26266a4c,
    0x36365a6c, 0x3f3f417e, 0xf7f702f5, 0xcccc4f83, 0x34345c68, 0xa5a5f451, 0xe5e534d1, 0xf1f108f9, 0x717193e2,
    0xd8d873ab, 0x31315362, 0x15153f2a, 0x4040c08,  0xc7c75295, 0x23236546, 0xc3c35e9d, 0x18182830, 0x9696a137,
    0x5050f0a,  0x9a9ab52f, 0x707090e,  0x12123624, 0x80809b1b, 0xe2e23ddf, 0xebeb26cd, 0x2727694e, 0xb2b2cd7f,
    0x75759fea, 0x9091b12,  0x83839e1d, 0x2c2c7458, 0x1a1a2e34, 0x1b1b2d36, 0x6e6eb2dc, 0x5a5aeeb4, 0xa0a0fb5b,
    0x5252f6a4, 0x3b3b4d76, 0xd6d661b7, 0xb3b3ce7d, 0x29297b52, 0xe3e33edd, 0x2f2f715e, 0x84849713, 0x5353f5a6,
    0xd1d168b9, 0,          0xeded2cc1, 0x20206040, 0xfcfc1fe3, 0xb1b1c879, 0x5b5bedb6, 0x6a6abed4, 0xcbcb468d,
    0xbebed967, 0x39394b72, 0x4a4ade94, 0x4c4cd498, 0x5858e8b0, 0xcfcf4a85, 0xd0d06bbb, 0xefef2ac5, 0xaaaae54f,
    0xfbfb16ed, 0x4343c586, 0x4d4dd79a, 0x33335566, 0x85859411, 0x4545cf8a, 0xf9f910e9, 0x2020604,  0x7f7f81fe,
    0x5050f0a0, 0x3c3c4478, 0x9f9fba25, 0xa8a8e34b, 0x5151f3a2, 0xa3a3fe5d, 0x4040c080, 0x8f8f8a05, 0x9292ad3f,
    0x9d9dbc21, 0x38384870, 0xf5f504f1, 0xbcbcdf63, 0xb6b6c177, 0xdada75af, 0x21216342, 0x10103020, 0xffff1ae5,
    0xf3f30efd, 0xd2d26dbf, 0xcdcd4c81, 0xc0c1418,  0x13133526, 0xecec2fc3, 0x5f5fe1be, 0x9797a235, 0x4444cc88,
    0x1717392e, 0xc4c45793, 0xa7a7f255, 0x7e7e82fc, 0x3d3d477a, 0x6464acc8, 0x5d5de7ba, 0x19192b32, 0x737395e6,
    0x6060a0c0, 0x81819819, 0x4f4fd19e, 0xdcdc7fa3, 0x22226644, 0x2a2a7e54, 0x9090ab3b, 0x8888830b, 0x4646ca8c,
    0xeeee29c7, 0xb8b8d36b, 0x14143c28, 0xdede79a7, 0x5e5ee2bc, 0xb0b1d16,  0xdbdb76ad, 0xe0e03bdb, 0x32325664,
    0x3a3a4e74, 0xa0a1e14,  0x4949db92, 0x6060a0c,  0x24246c48, 0x5c5ce4b8, 0xc2c25d9f, 0xd3d36ebd, 0xacacef43,
    0x6262a6c4, 0x9191a839, 0x9595a431, 0xe4e437d3, 0x79798bf2, 0xe7e732d5, 0xc8c8438b, 0x3737596e, 0x6d6db7da,
    0x8d8d8c01, 0xd5d564b1, 0x4e4ed29c, 0xa9a9e049, 0x6c6cb4d8, 0x5656faac, 0xf4f407f3, 0xeaea25cf, 0x6565afca,
    0x7a7a8ef4, 0xaeaee947, 0x8081810,  0xbabad56f, 0x787888f0, 0x25256f4a, 0x2e2e725c, 0x1c1c2438, 0xa6a6f157,
    0xb4b4c773, 0xc6c65197, 0xe8e823cb, 0xdddd7ca1, 0x74749ce8, 0x1f1f213e, 0x4b4bdd96, 0xbdbddc61, 0x8b8b860d,
    0x8a8a850f, 0x707090e0, 0x3e3e427c, 0xb5b5c471, 0x6666aacc, 0x4848d890, 0x3030506,  0xf6f601f7, 0xe0e121c,
    0x6161a3c2, 0x35355f6a, 0x5757f9ae, 0xb9b9d069, 0x86869117, 0xc1c15899, 0x1d1d273a, 0x9e9eb927, 0xe1e138d9,
    0xf8f813eb, 0x9898b32b, 0x11113322, 0x6969bbd2, 0xd9d970a9, 0x8e8e8907, 0x9494a733, 0x9b9bb62d, 0x1e1e223c,
    0x87879215, 0xe9e920c9, 0xcece4987, 0x5555ffaa, 0x28287850, 0xdfdf7aa5, 0x8c8c8f03, 0xa1a1f859, 0x89898009,
    0xd0d171a,  0xbfbfda65, 0xe6e631d7, 0x4242c684, 0x6868b8d0, 0x4141c382, 0x9999b029, 0x2d2d775a, 0xf0f111e,
    0xb0b0cb7b, 0x5454fca8, 0xbbbbd66d, 0x16163a2c};
const u32 gSubstitutionTable[256] = {
    0x63636363, 0x7c7c7c7c, 0x77777777, 0x7b7b7b7b, 0xf2f2f2f2, 0x6b6b6b6b, 0x6f6f6f6f, 0xc5c5c5c5, 0x30303030,
    0x1010101,  0x67676767, 0x2b2b2b2b, 0xfefefefe, 0xd7d7d7d7, 0xabababab, 0x76767676, 0xcacacaca, 0x82828282,
    0xc9c9c9c9, 0x7d7d7d7d, 0xfafafafa, 0x59595959, 0x47474747, 0xf0f0f0f0, 0xadadadad, 0xd4d4d4d4, 0xa2a2a2a2,
    0xafafafaf, 0x9c9c9c9c, 0xa4a4a4a4, 0x72727272, 0xc0c0c0c0, 0xb7b7b7b7, 0xfdfdfdfd, 0x93939393, 0x26262626,
    0x36363636, 0x3f3f3f3f, 0xf7f7f7f7, 0xcccccccc, 0x34343434, 0xa5a5a5a5, 0xe5e5e5e5, 0xf1f1f1f1, 0x71717171,
    0xd8d8d8d8, 0x31313131, 0x15151515, 0x4040404,  0xc7c7c7c7, 0x23232323, 0xc3c3c3c3, 0x18181818, 0x96969696,
    0x5050505,  0x9a9a9a9a, 0x7070707,  0x12121212, 0x80808080, 0xe2e2e2e2, 0xebebebeb, 0x27272727, 0xb2b2b2b2,
    0x75757575, 0x9090909,  0x83838383, 0x2c2c2c2c, 0x1a1a1a1a, 0x1b1b1b1b, 0x6e6e6e6e, 0x5a5a5a5a, 0xa0a0a0a0,
    0x52525252, 0x3b3b3b3b, 0xd6d6d6d6, 0xb3b3b3b3, 0x29292929, 0xe3e3e3e3, 0x2f2f2f2f, 0x84848484, 0x53535353,
    0xd1d1d1d1, 0,          0xedededed, 0x20202020, 0xfcfcfcfc, 0xb1b1b1b1, 0x5b5b5b5b, 0x6a6a6a6a, 0xcbcbcbcb,
    0xbebebebe, 0x39393939, 0x4a4a4a4a, 0x4c4c4c4c, 0x58585858, 0xcfcfcfcf, 0xd0d0d0d0, 0xefefefef, 0xaaaaaaaa,
    0xfbfbfbfb, 0x43434343, 0x4d4d4d4d, 0x33333333, 0x85858585, 0x45454545, 0xf9f9f9f9, 0x2020202,  0x7f7f7f7f,
    0x50505050, 0x3c3c3c3c, 0x9f9f9f9f, 0xa8a8a8a8, 0x51515151, 0xa3a3a3a3, 0x40404040, 0x8f8f8f8f, 0x92929292,
    0x9d9d9d9d, 0x38383838, 0xf5f5f5f5, 0xbcbcbcbc, 0xb6b6b6b6, 0xdadadada, 0x21212121, 0x10101010, 0xffffffff,
    0xf3f3f3f3, 0xd2d2d2d2, 0xcdcdcdcd, 0xc0c0c0c,  0x13131313, 0xecececec, 0x5f5f5f5f, 0x97979797, 0x44444444,
    0x17171717, 0xc4c4c4c4, 0xa7a7a7a7, 0x7e7e7e7e, 0x3d3d3d3d, 0x64646464, 0x5d5d5d5d, 0x19191919, 0x73737373,
    0x60606060, 0x81818181, 0x4f4f4f4f, 0xdcdcdcdc, 0x22222222, 0x2a2a2a2a, 0x90909090, 0x88888888, 0x46464646,
    0xeeeeeeee, 0xb8b8b8b8, 0x14141414, 0xdededede, 0x5e5e5e5e, 0xb0b0b0b,  0xdbdbdbdb, 0xe0e0e0e0, 0x32323232,
    0x3a3a3a3a, 0xa0a0a0a,  0x49494949, 0x6060606,  0x24242424, 0x5c5c5c5c, 0xc2c2c2c2, 0xd3d3d3d3, 0xacacacac,
    0x62626262, 0x91919191, 0x95959595, 0xe4e4e4e4, 0x79797979, 0xe7e7e7e7, 0xc8c8c8c8, 0x37373737, 0x6d6d6d6d,
    0x8d8d8d8d, 0xd5d5d5d5, 0x4e4e4e4e, 0xa9a9a9a9, 0x6c6c6c6c, 0x56565656, 0xf4f4f4f4, 0xeaeaeaea, 0x65656565,
    0x7a7a7a7a, 0xaeaeaeae, 0x8080808,  0xbabababa, 0x78787878, 0x25252525, 0x2e2e2e2e, 0x1c1c1c1c, 0xa6a6a6a6,
    0xb4b4b4b4, 0xc6c6c6c6, 0xe8e8e8e8, 0xdddddddd, 0x74747474, 0x1f1f1f1f, 0x4b4b4b4b, 0xbdbdbdbd, 0x8b8b8b8b,
    0x8a8a8a8a, 0x70707070, 0x3e3e3e3e, 0xb5b5b5b5, 0x66666666, 0x48484848, 0x3030303,  0xf6f6f6f6, 0xe0e0e0e,
    0x61616161, 0x35353535, 0x57575757, 0xb9b9b9b9, 0x86868686, 0xc1c1c1c1, 0x1d1d1d1d, 0x9e9e9e9e, 0xe1e1e1e1,
    0xf8f8f8f8, 0x98989898, 0x11111111, 0x69696969, 0xd9d9d9d9, 0x8e8e8e8e, 0x94949494, 0x9b9b9b9b, 0x1e1e1e1e,
    0x87878787, 0xe9e9e9e9, 0xcececece, 0x55555555, 0x28282828, 0xdfdfdfdf, 0x8c8c8c8c, 0xa1a1a1a1, 0x89898989,
    0xd0d0d0d,  0xbfbfbfbf, 0xe6e6e6e6, 0x42424242, 0x68686868, 0x41414141, 0x99999999, 0x2d2d2d2d, 0xf0f0f0f,
    0xb0b0b0b0, 0x54545454, 0xbbbbbbbb, 0x16161616};
const u32 gReversedTableByte3[256] = {
    0x51f4a750, 0x7e416553, 0x1a17a4c3, 0x3a275e96, 0x3bab6bcb, 0x1f9d45f1, 0xacfa58ab, 0x4be30393, 0x2030fa55,
    0xad766df6, 0x88cc7691, 0xf5024c25, 0x4fe5d7fc, 0xc52acbd7, 0x26354480, 0xb562a38f, 0xdeb15a49, 0x25ba1b67,
    0x45ea0e98, 0x5dfec0e1, 0xc32f7502, 0x814cf012, 0x8d4697a3, 0x6bd3f9c6, 0x38f5fe7,  0x15929c95, 0xbf6d7aeb,
    0x955259da, 0xd4be832d, 0x587421d3, 0x49e06929, 0x8ec9c844, 0x75c2896a, 0xf48e7978, 0x99583e6b, 0x27b971dd,
    0xbee14fb6, 0xf088ad17, 0xc920ac66, 0x7dce3ab4, 0x63df4a18, 0xe51a3182, 0x97513360, 0x62537f45, 0xb16477e0,
    0xbb6bae84, 0xfe81a01c, 0xf9082b94, 0x70486858, 0x8f45fd19, 0x94de6c87, 0x527bf8b7, 0xab73d323, 0x724b02e2,
    0xe31f8f57, 0x6655ab2a, 0xb2eb2807, 0x2fb5c203, 0x86c57b9a, 0xd33708a5, 0x302887f2, 0x23bfa5b2, 0x2036aba,
    0xed16825c, 0x8acf1c2b, 0xa779b492, 0xf307f2f0, 0x4e69e2a1, 0x65daf4cd, 0x605bed5,  0xd134621f, 0xc4a6fe8a,
    0x342e539d, 0xa2f355a0, 0x58ae132,  0xa4f6eb75, 0xb83ec39,  0x4060efaa, 0x5e719f06, 0xbd6e1051, 0x3e218af9,
    0x96dd063d, 0xdd3e05ae, 0x4de6bd46, 0x91548db5, 0x71c45d05, 0x406d46f,  0x605015ff, 0x1998fb24, 0xd6bde997,
    0x894043cc, 0x67d99e77, 0xb0e842bd, 0x7898b88,  0xe7195b38, 0x79c8eedb, 0xa17c0a47, 0x7c420fe9, 0xf8841ec9,
    0,          0x9808683,  0x322bed48, 0x1e1170ac, 0x6c5a724e, 0xfd0efffb, 0xf853856,  0x3daed51e, 0x362d3927,
    0xa0fd964,  0x685ca621, 0x9b5b54d1, 0x24362e3a, 0xc0a67b1,  0x9357e70f, 0xb4ee96d2, 0x1b9b919e, 0x80c0c54f,
    0x61dc20a2, 0x5a774b69, 0x1c121a16, 0xe293ba0a, 0xc0a02ae5, 0x3c22e043, 0x121b171d, 0xe090d0b,  0xf28bc7ad,
    0x2db6a8b9, 0x141ea9c8, 0x57f11985, 0xaf75074c, 0xee99ddbb, 0xa37f60fd, 0xf701269f, 0x5c72f5bc, 0x44663bc5,
    0x5bfb7e34, 0x8b432976, 0xcb23c6dc, 0xb6edfc68, 0xb8e4f163, 0xd731dcca, 0x42638510, 0x13972240, 0x84c61120,
    0x854a247d, 0xd2bb3df8, 0xaef93211, 0xc729a16d, 0x1d9e2f4b, 0xdcb230f3, 0xd8652ec,  0x77c1e3d0, 0x2bb3166c,
    0xa970b999, 0x119448fa, 0x47e96422, 0xa8fc8cc4, 0xa0f03f1a, 0x567d2cd8, 0x223390ef, 0x87494ec7, 0xd938d1c1,
    0x8ccaa2fe, 0x98d40b36, 0xa6f581cf, 0xa57ade28, 0xdab78e26, 0x3fadbfa4, 0x2c3a9de4, 0x5078920d, 0x6a5fcc9b,
    0x547e4662, 0xf68d13c2, 0x90d8b8e8, 0x2e39f75e, 0x82c3aff5, 0x9f5d80be, 0x69d0937c, 0x6fd52da9, 0xcf2512b3,
    0xc8ac993b, 0x10187da7, 0xe89c636e, 0xdb3bbb7b, 0xcd267809, 0x6e5918f4, 0xec9ab701, 0x834f9aa8, 0xe6956e65,
    0xaaffe67e, 0x21bccf08, 0xef15e8e6, 0xbae79bd9, 0x4a6f36ce, 0xea9f09d4, 0x29b07cd6, 0x31a4b2af, 0x2a3f2331,
    0xc6a59430, 0x35a266c0, 0x744ebc37, 0xfc82caa6, 0xe090d0b0, 0x33a7d815, 0xf104984a, 0x41ecdaf7, 0x7fcd500e,
    0x1791f62f, 0x764dd68d, 0x43efb04d, 0xccaa4d54, 0xe49604df, 0x9ed1b5e3, 0x4c6a881b, 0xc12c1fb8, 0x4665517f,
    0x9d5eea04, 0x18c355d,  0xfa877473, 0xfb0b412e, 0xb3671d5a, 0x92dbd252, 0xe9105633, 0x6dd64713, 0x9ad7618c,
    0x37a10c7a, 0x59f8148e, 0xeb133c89, 0xcea927ee, 0xb761c935, 0xe11ce5ed, 0x7a47b13c, 0x9cd2df59, 0x55f2733f,
    0x1814ce79, 0x73c737bf, 0x53f7cdea, 0x5ffdaa5b, 0xdf3d6f14, 0x7844db86, 0xcaaff381, 0xb968c43e, 0x3824342c,
    0xc2a3405f, 0x161dc372, 0xbce2250c, 0x283c498b, 0xff0d9541, 0x39a80171, 0x80cb3de,  0xd8b4e49c, 0x6456c190,
    0x7bcb8461, 0xd532b670, 0x486c5c74, 0xd0b85742};
const u32 gReversedTableByte2[256] = {
    0x5051f4a7, 0x537e4165, 0xc31a17a4, 0x963a275e, 0xcb3bab6b, 0xf11f9d45, 0xabacfa58, 0x934be303, 0x552030fa,
    0xf6ad766d, 0x9188cc76, 0x25f5024c, 0xfc4fe5d7, 0xd7c52acb, 0x80263544, 0x8fb562a3, 0x49deb15a, 0x6725ba1b,
    0x9845ea0e, 0xe15dfec0, 0x2c32f75,  0x12814cf0, 0xa38d4697, 0xc66bd3f9, 0xe7038f5f, 0x9515929c, 0xebbf6d7a,
    0xda955259, 0x2dd4be83, 0xd3587421, 0x2949e069, 0x448ec9c8, 0x6a75c289, 0x78f48e79, 0x6b99583e, 0xdd27b971,
    0xb6bee14f, 0x17f088ad, 0x66c920ac, 0xb47dce3a, 0x1863df4a, 0x82e51a31, 0x60975133, 0x4562537f, 0xe0b16477,
    0x84bb6bae, 0x1cfe81a0, 0x94f9082b, 0x58704868, 0x198f45fd, 0x8794de6c, 0xb7527bf8, 0x23ab73d3, 0xe2724b02,
    0x57e31f8f, 0x2a6655ab, 0x7b2eb28,  0x32fb5c2,  0x9a86c57b, 0xa5d33708, 0xf2302887, 0xb223bfa5, 0xba02036a,
    0x5ced1682, 0x2b8acf1c, 0x92a779b4, 0xf0f307f2, 0xa14e69e2, 0xcd65daf4, 0xd50605be, 0x1fd13462, 0x8ac4a6fe,
    0x9d342e53, 0xa0a2f355, 0x32058ae1, 0x75a4f6eb, 0x390b83ec, 0xaa4060ef, 0x65e719f,  0x51bd6e10, 0xf93e218a,
    0x3d96dd06, 0xaedd3e05, 0x464de6bd, 0xb591548d, 0x571c45d,  0x6f0406d4, 0xff605015, 0x241998fb, 0x97d6bde9,
    0xcc894043, 0x7767d99e, 0xbdb0e842, 0x8807898b, 0x38e7195b, 0xdb79c8ee, 0x47a17c0a, 0xe97c420f, 0xc9f8841e,
    0,          0x83098086, 0x48322bed, 0xac1e1170, 0x4e6c5a72, 0xfbfd0eff, 0x560f8538, 0x1e3daed5, 0x27362d39,
    0x640a0fd9, 0x21685ca6, 0xd19b5b54, 0x3a24362e, 0xb10c0a67, 0xf9357e7,  0xd2b4ee96, 0x9e1b9b91, 0x4f80c0c5,
    0xa261dc20, 0x695a774b, 0x161c121a, 0xae293ba,  0xe5c0a02a, 0x433c22e0, 0x1d121b17, 0xb0e090d,  0xadf28bc7,
    0xb92db6a8, 0xc8141ea9, 0x8557f119, 0x4caf7507, 0xbbee99dd, 0xfda37f60, 0x9ff70126, 0xbc5c72f5, 0xc544663b,
    0x345bfb7e, 0x768b4329, 0xdccb23c6, 0x68b6edfc, 0x63b8e4f1, 0xcad731dc, 0x10426385, 0x40139722, 0x2084c611,
    0x7d854a24, 0xf8d2bb3d, 0x11aef932, 0x6dc729a1, 0x4b1d9e2f, 0xf3dcb230, 0xec0d8652, 0xd077c1e3, 0x6c2bb316,
    0x99a970b9, 0xfa119448, 0x2247e964, 0xc4a8fc8c, 0x1aa0f03f, 0xd8567d2c, 0xef223390, 0xc787494e, 0xc1d938d1,
    0xfe8ccaa2, 0x3698d40b, 0xcfa6f581, 0x28a57ade, 0x26dab78e, 0xa43fadbf, 0xe42c3a9d, 0xd507892,  0x9b6a5fcc,
    0x62547e46, 0xc2f68d13, 0xe890d8b8, 0x5e2e39f7, 0xf582c3af, 0xbe9f5d80, 0x7c69d093, 0xa96fd52d, 0xb3cf2512,
    0x3bc8ac99, 0xa710187d, 0x6ee89c63, 0x7bdb3bbb, 0x9cd2678,  0xf46e5918, 0x1ec9ab7,  0xa8834f9a, 0x65e6956e,
    0x7eaaffe6, 0x821bccf,  0xe6ef15e8, 0xd9bae79b, 0xce4a6f36, 0xd4ea9f09, 0xd629b07c, 0xaf31a4b2, 0x312a3f23,
    0x30c6a594, 0xc035a266, 0x37744ebc, 0xa6fc82ca, 0xb0e090d0, 0x1533a7d8, 0x4af10498, 0xf741ecda, 0xe7fcd50,
    0x2f1791f6, 0x8d764dd6, 0x4d43efb0, 0x54ccaa4d, 0xdfe49604, 0xe39ed1b5, 0x1b4c6a88, 0xb8c12c1f, 0x7f466551,
    0x49d5eea,  0x5d018c35, 0x73fa8774, 0x2efb0b41, 0x5ab3671d, 0x5292dbd2, 0x33e91056, 0x136dd647, 0x8c9ad761,
    0x7a37a10c, 0x8e59f814, 0x89eb133c, 0xeecea927, 0x35b761c9, 0xede11ce5, 0x3c7a47b1, 0x599cd2df, 0x3f55f273,
    0x791814ce, 0xbf73c737, 0xea53f7cd, 0x5b5ffdaa, 0x14df3d6f, 0x867844db, 0x81caaff3, 0x3eb968c4, 0x2c382434,
    0x5fc2a340, 0x72161dc3, 0xcbce225,  0x8b283c49, 0x41ff0d95, 0x7139a801, 0xde080cb3, 0x9cd8b4e4, 0x906456c1,
    0x617bcb84, 0x70d532b6, 0x74486c5c, 0x42d0b857};
u32 gThreadStackSize = 0x800;
s32 gStartEntryCount = 0x40;
s32 gTimeoutAtMs = -1;
ExchangeItem3Bytes gFirstReplyItem3Bytes = {{6, 0, 1, 2, 3, 4, 5}};
char gSixAsterisksString[7] = "******";
u8 gHashPadding[64] = {0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                       0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                       0,    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
u8 gPacketBuffer[0x800];
u8 gBodyBuffer[0x800];
ExchangeResultItems gExchangeResultItems;
ExchangeResult gExchangeResult;
OSThread gExchangeThread;
char gSelectedEntryName[36];
u8 gExchangeSearchEssidBytes[0x20];
u8 gSecondKeyHashedPart[24];
SecondKeyPart gSecondKeyReceivedPart;

void ExchangeWcmNotifyCallback(WcmNoticeHead *message) {
    if (message == NULL) {
        return;
    }
    switch (message->mNotify) {
        case WIFI_NOTIFY_STARTUP_REQUEST:
            if (message->mResult == 0) {
                if (gExchangeWcmState == EXCHANGE_WCM_STATE_STARTING_UP_OR_DISCONNECTING) {
                    gExchangeWcmState = EXCHANGE_WCM_STATE_IDLE;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(EXCHANGE_EVENT_STARTUP_DONE, 0);
                    }
                } else if (gExchangeWcmState == EXCHANGE_WCM_STATE_SEARCH_PENDING) {
                    if (WCM_SearchAsync(gExchangeSearchAddress, gExchangeSearchEssid, gExchangeSearchOption) == 3) {
                        return;
                    }
                    gExchangeWcmState = EXCHANGE_WCM_STATE_IDLE;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(EXCHANGE_EVENT_CHAINED_REQUEST_FAILED, 0);
                    }
                } else if (gExchangeWcmState == EXCHANGE_WCM_STATE_CONNECT_PENDING) {
                    if (WCM_ConnectAsync(gExchangeConnectRecord, gExchangeConnectBlock, gExchangeConnectOption) == 3) {
                        return;
                    }
                    gExchangeWcmState = EXCHANGE_WCM_STATE_IDLE;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(EXCHANGE_EVENT_CHAINED_REQUEST_FAILED, 0);
                    }
                }
            } else {
                gExchangeWcmState = EXCHANGE_WCM_STATE_INITIALIZED;
                if (gExchangeEventCallback != NULL) {
                    gExchangeEventCallback(EXCHANGE_EVENT_CHAINED_REQUEST_FAILED, 0);
                }
            }
            break;
        case WIFI_NOTIFY_SCAN_START_REQUEST:
            if (message->mResult == 0) {
                if (gExchangeWcmState == EXCHANGE_WCM_STATE_SEARCH_PENDING) {
                    gExchangeWcmState = EXCHANGE_WCM_STATE_SEARCHING;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(EXCHANGE_EVENT_SEARCH_STARTED, 0);
                    }
                }
            } else {
                gExchangeWcmState = EXCHANGE_WCM_STATE_IDLE;
                if (gExchangeEventCallback != NULL) {
                    gExchangeEventCallback(EXCHANGE_EVENT_SEARCH_START_FAILED, 0);
                }
            }
            break;
        case WIFI_NOTIFY_CONNECT_REQUEST:
            if (message->mResult == 0) {
                if (gExchangeWcmState == EXCHANGE_WCM_STATE_CONNECT_PENDING) {
                    gExchangeWcmState = EXCHANGE_WCM_STATE_CONNECTED;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(EXCHANGE_EVENT_CONNECTED, 0);
                    }
                }
            } else {
                gExchangeWcmState = EXCHANGE_WCM_STATE_IDLE;
                if (gExchangeEventCallback != NULL) {
                    gExchangeEventCallback(EXCHANGE_EVENT_CONNECT_FAILED, 0);
                }
            }
            break;
        case WIFI_NOTIFY_SCAN_STOP_REQUEST:
            if (message->mResult == 0) {
                if (gExchangeWcmState == EXCHANGE_WCM_STATE_STARTING_UP_OR_DISCONNECTING) {
                    gExchangeWcmState = EXCHANGE_WCM_STATE_IDLE;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(EXCHANGE_EVENT_SEARCH_STOPPED, 0);
                    }
                } else if (gExchangeWcmState == EXCHANGE_WCM_STATE_SEARCH_PENDING) {
                    if (WCM_SearchAsync(gExchangeSearchAddress, gExchangeSearchEssid, gExchangeSearchOption) == 3) {
                        return;
                    }
                    gExchangeWcmState = EXCHANGE_WCM_STATE_IDLE;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(EXCHANGE_EVENT_CHAINED_REQUEST_FAILED, 0);
                    }
                } else if (gExchangeWcmState == EXCHANGE_WCM_STATE_CLEANING_UP) {
                    if (WCM_CleanupAsync() == 3) {
                        return;
                    }
                    gExchangeWcmState = EXCHANGE_WCM_STATE_IDLE;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(EXCHANGE_EVENT_CHAINED_REQUEST_FAILED, 0);
                    }
                } else if (gExchangeWcmState == EXCHANGE_WCM_STATE_CONNECT_PENDING) {
                    if (WCM_ConnectAsync(gExchangeConnectRecord, gExchangeConnectBlock, gExchangeConnectOption) == 3) {
                        return;
                    }
                    gExchangeWcmState = EXCHANGE_WCM_STATE_IDLE;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(EXCHANGE_EVENT_CHAINED_REQUEST_FAILED, 0);
                    }
                }
            } else {
                gExchangeWcmState = EXCHANGE_WCM_STATE_IDLE;
                if (gExchangeEventCallback != NULL) {
                    gExchangeEventCallback(EXCHANGE_EVENT_SEARCH_STOP_FAILED, 0);
                }
            }
            break;
        case WIFI_NOTIFY_DISCONNECT_REQUEST:
            if (message->mResult == 0) {
                if (gExchangeWcmState == EXCHANGE_WCM_STATE_STARTING_UP_OR_DISCONNECTING) {
                    gExchangeWcmState = EXCHANGE_WCM_STATE_IDLE;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(EXCHANGE_EVENT_DISCONNECTED, 0);
                    }
                } else if (gExchangeWcmState == EXCHANGE_WCM_STATE_SEARCH_PENDING) {
                    if (WCM_SearchAsync(gExchangeSearchAddress, gExchangeSearchEssid, gExchangeSearchOption) == 3) {
                        return;
                    }
                    gExchangeWcmState = EXCHANGE_WCM_STATE_IDLE;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(EXCHANGE_EVENT_CHAINED_REQUEST_FAILED, 0);
                    }
                } else if (gExchangeWcmState == EXCHANGE_WCM_STATE_CLEANING_UP) {
                    if (WCM_CleanupAsync() == 3) {
                        return;
                    }
                    gExchangeWcmState = EXCHANGE_WCM_STATE_IDLE;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(EXCHANGE_EVENT_CHAINED_REQUEST_FAILED, 0);
                    }
                } else if (gExchangeWcmState == EXCHANGE_WCM_STATE_CONNECT_PENDING) {
                    if (WCM_ConnectAsync(gExchangeConnectRecord, gExchangeConnectBlock, gExchangeConnectOption) == 3) {
                        return;
                    }
                    gExchangeWcmState = EXCHANGE_WCM_STATE_IDLE;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(EXCHANGE_EVENT_CHAINED_REQUEST_FAILED, 0);
                    }
                } else if (gExchangeWcmState == EXCHANGE_WCM_STATE_CONNECTED) {
                    gExchangeWcmState = EXCHANGE_WCM_STATE_IDLE;
                }
            } else {
                gExchangeWcmState = EXCHANGE_WCM_STATE_IDLE;
                if (gExchangeEventCallback != NULL) {
                    gExchangeEventCallback(EXCHANGE_EVENT_DISCONNECT_FAILED, 0);
                }
            }
            break;
        case WIFI_NOTIFY_CLEANUP_REQUEST:
            if (message->mResult == 0) {
                if (gExchangeWcmState == EXCHANGE_WCM_STATE_CLEANING_UP) {
                    WCM_Finish();
                    gExchangeWcmState = EXCHANGE_WCM_STATE_STOPPED;
                    if (gExchangeEventCallback != NULL) {
                        gExchangeEventCallback(EXCHANGE_EVENT_CLEANUP_DONE, 0);
                    }
                }
            } else {
                gExchangeWcmState = EXCHANGE_WCM_STATE_IDLE;
                if (gExchangeEventCallback != NULL) {
                    gExchangeEventCallback(EXCHANGE_EVENT_CHAINED_REQUEST_FAILED, 0);
                }
            }
            break;
        case WIFI_NOTIFY_SEARCH_FOUND:
            if (gExchangeWcmState == EXCHANGE_WCM_STATE_SEARCHING) {
                if (gExchangeEventCallback != NULL) {
                    gExchangeEventCallback(EXCHANGE_EVENT_SEARCH_FOUND, 0);
                }
            }
            break;
        case WIFI_NOTIFY_SCAN_ROUND:
            if (gExchangeEventCallback != NULL) {
                gExchangeEventCallback(EXCHANGE_EVENT_SCAN_ROUND, 0);
            }
            break;
        case WIFI_NOTIFY_TERMINATE_REQUEST:
            gExchangeWcmState = EXCHANGE_WCM_STATE_STOPPED;
            if (gExchangeEventCallback != NULL) {
                gExchangeEventCallback(EXCHANGE_EVENT_LINK_TERMINATED, 0);
            }
            break;
        default:
            if (gExchangeEventCallback != NULL) {
                gExchangeEventCallback(EXCHANGE_EVENT_UNEXPECTED_NOTICE, 0);
            }
            break;
    }
}

BOOL StartExchangeReturnToIdle(void) {
    switch (gExchangeWcmState) {
        case EXCHANGE_WCM_STATE_SEARCHING:
            if (WCM_SearchAsync(NULL, NULL, 0) != 3) {
                return 0;
            }
            break;
        case EXCHANGE_WCM_STATE_CONNECTED:
            if (WCM_DisconnectAsync() != 3) {
                return 0;
            }
            break;
        case EXCHANGE_WCM_STATE_INITIALIZED:
            if (WCM_StartupAsync(gExchangeWcmConfig, (void (*)(WCMNotice *)) ExchangeWcmNotifyCallback) != 3) {
                return 0;
            }
            break;
        case EXCHANGE_WCM_STATE_STOPPED:
        case EXCHANGE_WCM_STATE_CLEANING_UP:
        case EXCHANGE_WCM_STATE_IDLE:
        case EXCHANGE_WCM_STATE_STARTING_UP_OR_DISCONNECTING:
        case EXCHANGE_WCM_STATE_SEARCH_PENDING:
        case EXCHANGE_WCM_STATE_CONNECT_PENDING:
        default:
            return 0;
    }
    return 1;
}

s32 CopyExchangeScanRecords(RawEntry *output, s32 maxCount) {
    s32 count;
    s32 recordIndex;

    WCM_LockApList(1);
    count = WCM_CountApList();
    if (count > 0) {
        recordIndex = 0;
        if (count > 0) {
            do {
                if (recordIndex >= maxCount) {
                    break;
                }
                MIi_CpuCopy32(WCM_PointApList(recordIndex), output, sizeof(RawEntry));
                recordIndex++;
                output++;
            } while (recordIndex < count);
        }
    }
    WCM_LockApList(0);
    return count;
}

BOOL StartExchangeSearch(u8 *address, u8 *name, s32 nameLength, u32 option) {
    u32 savedInterrupts = OS_DisableInterrupts();
    u8 *cursor;
    s32 byteIndex;

    gExchangeSearchOption = option;
    cursor = gExchangeSearchAddressBytes;
    gExchangeSearchAddress = cursor;
    if (address != NULL) {
        for (byteIndex = 0; byteIndex < 6; byteIndex++) {
            *cursor++ = *address++;
        }
    } else {
        MI_CpuFill8(cursor, 0xff, 6);
        gExchangeSearchAddress = WCM_Bssid_Any;
    }
    cursor = gExchangeSearchEssidBytes;
    gExchangeSearchEssid = cursor;
    if (name != NULL && nameLength > 0 && nameLength < 0x20) {
        byteIndex = 0;
        if (nameLength > 0) {
            do {
                *cursor++ = *name++;
                byteIndex++;
            } while (byteIndex < nameLength);
        }
        if (byteIndex < 0x20) {
            cursor = gExchangeSearchEssidBytes + byteIndex;
            do {
                *cursor++ = 0;
                byteIndex++;
            } while (byteIndex < 0x20);
        }
    } else {
        MI_CpuFill8(gExchangeSearchEssidBytes, 0xff, sizeof(gExchangeSearchEssidBytes));
        gExchangeSearchEssid = WCM_Essid_Any;
    }
    if (gExchangeWcmState == EXCHANGE_WCM_STATE_IDLE) {
        if (WCM_SearchAsync(gExchangeSearchAddressBytes, gExchangeSearchEssid, gExchangeSearchOption) == 3) {
            gExchangeWcmState = EXCHANGE_WCM_STATE_SEARCH_PENDING;
            OS_RestoreInterrupts(savedInterrupts);
            return 1;
        }
    } else if (StartExchangeReturnToIdle() == 1) {
        gExchangeWcmState = EXCHANGE_WCM_STATE_SEARCH_PENDING;
        OS_RestoreInterrupts(savedInterrupts);
        return 1;
    }
    OS_RestoreInterrupts(savedInterrupts);
    return 0;
}

BOOL DisconnectExchange(void) {
    u32 savedInterrupts = OS_DisableInterrupts();

    if (gExchangeWcmState == EXCHANGE_WCM_STATE_CONNECTED) {
        if (WCM_DisconnectAsync() == 3) {
            gExchangeWcmState = EXCHANGE_WCM_STATE_STARTING_UP_OR_DISCONNECTING;
            OS_RestoreInterrupts(savedInterrupts);
            return 1;
        }
    }
    OS_RestoreInterrupts(savedInterrupts);
    return 0;
}

BOOL CleanupExchangeWcm(void) {
    u32 savedInterrupts = OS_DisableInterrupts();

    if (gExchangeWcmState == EXCHANGE_WCM_STATE_IDLE) {
        if (WCM_CleanupAsync() != 3) {
            OS_RestoreInterrupts(savedInterrupts);
            return 0;
        }
        gExchangeWcmState = EXCHANGE_WCM_STATE_CLEANING_UP;
        OS_RestoreInterrupts(savedInterrupts);
        return 1;
    }
    if (StartExchangeReturnToIdle() == 1) {
        gExchangeWcmState = EXCHANGE_WCM_STATE_CLEANING_UP;
        OS_RestoreInterrupts(savedInterrupts);
        return 1;
    }
    OS_RestoreInterrupts(savedInterrupts);
    return 0;
}

BOOL ConnectExchangeToEntry(void *entry, void *optionalBytes, u32 option) {
    u32 savedInterrupts = OS_DisableInterrupts();

    gExchangeConnectOption = option;
    if (optionalBytes != NULL) {
        MI_CpuCopy8(optionalBytes, gExchangeConnectBlock, 0x60);
    } else {
        MI_CpuFill8(gExchangeConnectBlock, 0, 0x60);
    }
    MIi_CpuCopy32(entry, gExchangeConnectRecord, 0xc0);
    if (StartExchangeReturnToIdle() == 1) {
        gExchangeWcmState = EXCHANGE_WCM_STATE_CONNECT_PENDING;
        OS_RestoreInterrupts(savedInterrupts);
        return 1;
    }
    if (gExchangeWcmState == EXCHANGE_WCM_STATE_IDLE) {
        if (WCM_ConnectAsync(gExchangeConnectRecord, gExchangeConnectBlock, gExchangeConnectOption) == 3) {
            gExchangeWcmState = EXCHANGE_WCM_STATE_CONNECT_PENDING;
            OS_RestoreInterrupts(savedInterrupts);
            return 1;
        }
    }
    OS_RestoreInterrupts(savedInterrupts);
    return 0;
}

BOOL InitExchangeWcm(ExchangeEventCallback callback, void *buffer, u32 size) {
    u32 savedInterrupts = OS_DisableInterrupts();
    WCMConfig *alignedBlock;
    u32 cursor;

    gExchangeConnectBlock = buffer;
    alignedBlock = (WCMConfig *) (((u32) buffer + 0x63) & ~3);
    gExchangeWcmConfig = alignedBlock;
    cursor = ((u32) alignedBlock + 0x2f) & ~0x1f;
    gExchangeWcmWork = (void *) cursor;
    cursor = (cursor + 0x231f) & ~0x1f;
    gExchangeConnectRecord = (WMBssDesc *) cursor;
    cursor = (cursor + 0xdf) & ~0x1f;
    alignedBlock->mPbdBuffer = (u8 *) cursor;
    gExchangeWcmConfig->mNbdBuffer = (u32) buffer + size - (u32) gExchangeWcmConfig->mPbdBuffer;
    gExchangeWcmConfig->mNbdMode = 0;
    gExchangeWcmConfig->mDmaNo = EXCHANGE_WCM_DMA_NO;
    gExchangeEventCallback = callback;
    if (gExchangeWcmState == EXCHANGE_WCM_STATE_STOPPED) {
        if (WCM_Init(gExchangeWcmWork, 0x2300) != 0) {
            OS_RestoreInterrupts(savedInterrupts);
            return 0;
        }
        gExchangeWcmState = EXCHANGE_WCM_STATE_INITIALIZED;
    }
    if (gExchangeWcmState == EXCHANGE_WCM_STATE_INITIALIZED) {
        if (WCM_StartupAsync(gExchangeWcmConfig, (void (*)(WCMNotice *)) ExchangeWcmNotifyCallback) != 3) {
            OS_RestoreInterrupts(savedInterrupts);
            return 0;
        }
        gExchangeWcmState = EXCHANGE_WCM_STATE_STARTING_UP_OR_DISCONNECTING;
        OS_RestoreInterrupts(savedInterrupts);
        return 1;
    }
    OS_RestoreInterrupts(savedInterrupts);
    return 0;
}

u32 GetExchangeWcmState(void) {
    return gExchangeWcmState;
}

u32 CallAllocFunctionWithMutex(u32 unused, s32 size) {
    u32 result;
    if (size > 0) {
        OS_LockMutex(&gAllocMutex);
        result = gAllocFunction(size);
        OS_UnlockMutex(&gAllocMutex);
        return result;
    }
    return 0;
}

void CallFreeFunctionWithMutex(u32 unused, void *block, s32 size) {
    if (block != 0 && size > 0) {
        OS_LockMutex(&gAllocMutex);
        gFreeFunction(block);
        OS_UnlockMutex(&gAllocMutex);
    }
}

void ClearEventQueue(void) {
    u32 savedInterrupts = OS_DisableInterrupts();
    s32 eventIndex;

    gEventWriteIndex = 0;
    gEventReadIndex = 0;
    for (eventIndex = 0; eventIndex < 4; eventIndex++) {
        gEvents[eventIndex] = 0;
    }
    OS_RestoreInterrupts(savedInterrupts);
}

u32 DequeueEvent(void) {
    u32 savedInterrupts = OS_DisableInterrupts();
    s32 readIndex = gEventReadIndex;
    u32 event;

    if (gEventWriteIndex == readIndex) {
        event = 0;
    } else {
        event = gEvents[readIndex];
        readIndex++;
        gEventReadIndex = readIndex;
        if (readIndex >= 4) {
            gEventReadIndex = 0;
        }
    }
    OS_RestoreInterrupts(savedInterrupts);
    return event;
}

void EnqueueEventEx(u32 event, u32 unused) {
    s32 readIndex = gEventReadIndex;
    s32 writeIndex = gEventWriteIndex;
    s32 nextIndex = writeIndex + 1;

    if (nextIndex == readIndex) {
        return;
    }
    if (writeIndex == readIndex + 3) {
        return;
    }
    gEvents[writeIndex] = event;
    gEventWriteIndex = nextIndex;
    if (nextIndex >= 4) {
        gEventWriteIndex = 0;
    }
}

void EnqueueEvent(u32 event) {
    EnqueueEventEx(event, 0);
}

s32 InitExchangeWiFi(u32 entryCount) {
    u32 waiting = 1;
    s32 result;
    u32 event;
    u32 alignedBuffer;
    u32 entriesSize;
    u32 bufferSize;
    enum { ALIGN_MASK_UNSET } alignMask;
    u32 bufferEnd;

    gEntryCountMax = entryCount;
    ClearEventQueue();
    entriesSize = entryCount * 0xd0;
    gAllocatedBuffer = (void *) gAllocFunction(entriesSize + 0x24d0 + entryCount * 0xc0);
    if (gAllocatedBuffer == NULL) {
        return -1;
    }
    alignMask = 0x1f;
    alignedBuffer = ((u32) gAllocatedBuffer + alignMask) & ~0x1f;
    gAlignedBuffer = (void *) alignedBuffer;
    bufferSize = entriesSize + 0x2490;
    bufferEnd = alignedBuffer + bufferSize;
    gRawEntries = (RawEntry *) ((bufferEnd + alignMask) & ~0x1f);
    if (InitExchangeWcm(EnqueueEventEx, (void *) alignedBuffer, bufferSize) == 0) {
        return -2;
    }
    do {
        OS_Sleep(10);
        while ((event = DequeueEvent()) != 0) {
            if (event == 4 || event == 5) {
            } else if (event == 6) {
                waiting = 0;
                result = 1;
            } else {
                waiting = 0;
                result = -2;
            }
        }
    } while (waiting != 0);
    return result;
}

u32 ReleaseExchangeWiFi(void) {
    u32 waiting = 1;
    u32 event;

    if (CleanupExchangeWcm() != 0) {
        do {
            OS_Sleep(10);
            while ((event = DequeueEvent()) != 0) {
                switch (event) {
                    case EXCHANGE_EVENT_SCAN_ROUND:
                    case EXCHANGE_EVENT_SEARCH_FOUND:
                        break;
                    case EXCHANGE_EVENT_CLEANUP_DONE:
                        waiting = 0;
                        break;
                    default:
                        waiting = 0;
                        break;
                }
            }
        } while (waiting != 0);
    }
    if (gAllocatedBuffer != NULL) {
        gFreeFunction(gAllocatedBuffer);
        gAllocatedBuffer = NULL;
    }
    return 1;
}

s32 ConnectExchangeAndStartSockets(void) {
    OSAlarm alarm;
    RawEntry *entry;
    s32 waiting = 1;
    s32 result = -2;
    BOOL notWaiting;
    s32 event;

    entry = gRawEntries + gSelectedEntryIndex;
    if (entry == NULL) {
        return 0;
    }
    if (ConnectExchangeToEntry(entry, NULL, 0x30000) == 0) {
        return -2;
    }
    OS_CreateAlarm(&alarm);
    OS_SetAlarm(&alarm, 0x3fec42, (void (*)(void *)) EnqueueEvent, (void *) EXCHANGE_EVENT_CONNECT_TIMEOUT);
    notWaiting = FALSE;
    do {
        if (GetTickMilliseconds() >= gTimeoutAtMs) {
            result = -3;
            break;
        }
        if (gStopRequested != 0) {
            result = -8;
            break;
        }
        OS_Sleep(10);
        while ((event = DequeueEvent()) != 0) {
            switch (event) {
                case EXCHANGE_EVENT_CONNECTED:
                    waiting = notWaiting;
                    result = 1;
                    break;
                case EXCHANGE_EVENT_CONNECT_FAILED:
                    if (gStopRequested != 0) {
                        waiting = notWaiting;
                        result = -8;
                    } else if (ConnectExchangeToEntry(entry, NULL, 0x30000) == 0) {
                        return result;
                    }
                    break;
                case EXCHANGE_EVENT_SCAN_ROUND:
                case EXCHANGE_EVENT_SEARCH_FOUND:
                case EXCHANGE_EVENT_CONNECT_TIMEOUT:
                case EXCHANGE_EVENT_SEARCH_TIMEOUT:
                    break;
                default:
                    waiting = notWaiting;
                    break;
            }
        }
    } while (waiting != 0);
    OS_CancelAlarm(&alarm);
    while (DequeueEvent() != 0) {
    }
    if (result > 0) {
        gExchangeConnected = 1;
        if (SOC_Startup(&gExchangeSocketConfig) < 0) {
            result = -2;
        } else {
            gSocketsStarted = 1;
        }
    }
    return result;
}

void DisconnectExchangeAndStopSockets(void) {
    BOOL waiting;
    u32 event;
    waiting = TRUE;
    if (gExchangeConnected != 0) {
        if (DisconnectExchange() != 0) {
            do {
                OS_Sleep(10);
                while ((event = DequeueEvent()) != 0) {
                    switch (event) {
                        case EXCHANGE_EVENT_SCAN_ROUND:
                        case EXCHANGE_EVENT_SEARCH_FOUND:
                            break;
                        case EXCHANGE_EVENT_DISCONNECTED:
                            waiting = FALSE;
                            break;
                        default:
                            waiting = FALSE;
                            break;
                    }
                }
            } while (waiting != FALSE);
        }
        gExchangeConnected = 0;
    }
    if (gSocketsStarted != 0) {
        gSocketsStarted = 0;
        SOC_Cleanup();
    }
}

// Finds an entry of current with mBit4Set 0 that matches a previous entry (same name prefix, same first four address
// bytes) with a different mBit4Set, else an unencrypted six-asterisk entry in current when previous has none; stores
// its index.
s32 FindEntryWithBit4NewlyCleared(EntrySummaryList *current, EntrySummaryList *previous, u32 *foundIndex) {
    BOOL found;
    BOOL result;
    BOOL currentHasUnencryptedSixAsterisks;
    BOOL previousHasUnencryptedSixAsterisks;
    EntrySummary *currentEntry;
    EntrySummary *previousEntry;
    u32 previousCount;
    u32 index;
    u32 previousIndex;
    u32 nameLength;
    found = FALSE;
    result = FALSE;
    currentEntry = current->mEntries;
    previousEntry = previous->mEntries;
    index = 0;
    for (; index < current->mCount; index++) {
        char currentName[0x22] = {0};
        memcpy(currentName, currentEntry->mSsid, sizeof(currentEntry->mSsid));
        currentName[currentEntry->mSsidLength] = 0;
        previousIndex = 0;
        previousCount = previous->mCount;
        if (previousIndex < previousCount) {
            nameLength = currentEntry->mSsidLength;
            do {
                if (nameLength == 0 || nameLength > 0x20) {
                    break;
                }
                if (nameLength == 1 &&
                    (currentEntry->mSsid[0] == 0 || currentEntry->mSsid[0] == EXCHANGE_SSID_BLANK_CHAR)) {
                    break;
                }
                if (memcmp(currentName, previousEntry->mSsid, strlen(currentName)) == 0 &&
                    memcmp(currentEntry->mAddress.mBytes, previousEntry->mAddress.mBytes, 4) == 0 &&
                    currentEntry->mBit4Set != previousEntry->mBit4Set && currentEntry->mBit4Set == 0) {
                    found = TRUE;
                    break;
                }
                previousEntry++;
                previousIndex++;
            } while (previousIndex < previousCount);
        }
        if (found != FALSE) {
            break;
        }
        currentEntry++;
        previousEntry = previous->mEntries;
    }
    if (found == FALSE) {
        char entryName[0x22] = {0};
        currentHasUnencryptedSixAsterisks = FALSE;
        previousHasUnencryptedSixAsterisks = FALSE;
        currentEntry = current->mEntries;
        previousEntry = previous->mEntries;
        previousIndex = 0;
        for (; previousIndex < previous->mCount; previousIndex++) {
            memcpy(entryName, previousEntry->mSsid, sizeof(previousEntry->mSsid));
            entryName[previousEntry->mSsidLength] = 0;
            if (memcmp(entryName, gSixAsterisksString, strlen(gSixAsterisksString)) == 0 &&
                previousEntry->mBit4Set == 0) {
                previousHasUnencryptedSixAsterisks = TRUE;
                break;
            }
            previousEntry++;
        }
        index = 0;
        for (; index < current->mCount; index++) {
            memcpy(entryName, currentEntry->mSsid, sizeof(currentEntry->mSsid));
            entryName[currentEntry->mSsidLength] = 0;
            if (strlen(entryName) == strlen(gSixAsterisksString) &&
                memcmp(entryName, gSixAsterisksString, strlen(gSixAsterisksString)) == 0 &&
                currentEntry->mBit4Set == 0) {
                currentHasUnencryptedSixAsterisks = TRUE;
                break;
            }
            currentEntry++;
        }
        if (currentHasUnencryptedSixAsterisks != FALSE && previousHasUnencryptedSixAsterisks == FALSE) {
            found = TRUE;
        }
    }
    if (found != FALSE) {
        *foundIndex = index;
        result = TRUE;
    }
    return result;
}

// Searches up to 30 rounds, comparing each round's entry list with the previous round's, until
// FindEntryWithBit4NewlyCleared reports an entry (not asked while gExchangeStatus is EXCHANGE_STATUS_STARTED) or the
// timeout or a stop request ends it; stores its index, name and address in gSelectedEntryIndex, gSelectedEntryName and
// gSelectedEntryAddress.
s32 SearchEntriesAndStoreEntryWithBit4NewlyCleared(void) {
    s32 result;
    s32 round;
    s32 copied;
    s32 index;
    BOOL waiting;
    s32 collected;
    u32 summarySize;
    u32 event;
    EntrySummaryList *currentList;
    EntrySummaryList *previousList;
    RawEntry *rawEntry;
    EntrySummary *entry;
    u8 *source;
    u8 *target;
    u32 changedIndex;
    u8 addressText[0x20];
    OSAlarm alarm;
    result = 0;
    currentList = NULL;
    result = -1;
    previousList = NULL;
    changedIndex = 0;
    summarySize = gEntryCountMax * 0x30 + 0x34;
    currentList = CallAllocFunctionAndClear(1, summarySize);
    if (currentList == NULL) {
        goto end;
    }
    previousList = CallAllocFunctionAndClear(1, summarySize);
    if (previousList == NULL) {
        goto end;
    }
    round = 0;
    while (round < 30 && gStopRequested == 0) {
        if (GetTickMilliseconds() >= gTimeoutAtMs) {
            break;
        }
        if (StartExchangeSearch(NULL, NULL, 0, 0x30bffe) == 0) {
            result = -2;
            goto end;
        }
        OS_CreateAlarm(&alarm);
        OS_SetAlarm(&alarm, 0xffb10, (void (*)(void *)) EnqueueEvent, (void *) EXCHANGE_EVENT_SEARCH_TIMEOUT);
        waiting = TRUE;
        result = 0;
        do {
            OS_Sleep(10);
            if (GetTickMilliseconds() >= gTimeoutAtMs || gStopRequested != 0) {
                break;
            }
            while ((event = DequeueEvent()) != 0) {
                switch (event) {
                    case EXCHANGE_EVENT_SEARCH_TIMEOUT:
                        waiting = FALSE;
                        break;
                    case EXCHANGE_EVENT_SEARCH_FOUND:
                        collected = CopyExchangeScanRecords(gRawEntries, gEntryCountMax);
                        if (collected > result) {
                            result = collected;
                            OS_CancelAlarm(&alarm);
                            OS_SetAlarm(&alarm, 0xffb10, (void (*)(void *)) EnqueueEvent,
                                        (void *) EXCHANGE_EVENT_SEARCH_TIMEOUT);
                        }
                        break;
                    case EXCHANGE_EVENT_SEARCH_STOPPED:
                        waiting = FALSE;
                        break;
                    case EXCHANGE_EVENT_SCAN_ROUND:
                    case EXCHANGE_EVENT_SEARCH_STARTED:
                    case EXCHANGE_EVENT_CONNECT_TIMEOUT:
                        break;
                    case 0:
                    case EXCHANGE_EVENT_UNEXPECTED_NOTICE:
                    case EXCHANGE_EVENT_CHAINED_REQUEST_FAILED:
                    case EXCHANGE_EVENT_LINK_TERMINATED:
                    case EXCHANGE_EVENT_STARTUP_DONE:
                    case EXCHANGE_EVENT_UNUSED_AFTER_STARTUP_DONE:
                    case EXCHANGE_EVENT_SEARCH_START_FAILED:
                    case EXCHANGE_EVENT_SEARCH_STOP_FAILED:
                    case EXCHANGE_EVENT_CONNECTED:
                    case EXCHANGE_EVENT_CONNECT_FAILED:
                    case EXCHANGE_EVENT_DISCONNECTED:
                    case EXCHANGE_EVENT_DISCONNECT_FAILED:
                    case EXCHANGE_EVENT_UNUSED_AFTER_DISCONNECT_FAILED:
                    case EXCHANGE_EVENT_UNUSED_BEFORE_CONNECT_TIMEOUT:
                    default:
                        waiting = FALSE;
                        break;
                }
            }
        } while (waiting != FALSE);
        OS_CancelAlarm(&alarm);
        while (DequeueEvent() != 0) {
        }
        if (gStopRequested != 0) {
            break;
        }
        index = 0;
        if (result >= gEntryCountMax) {
            result = -6;
            goto end;
        }
        copied = 0;
        rawEntry = gRawEntries;
        if (result > 0) {
            do {
                memcpy(currentList->mEntries[index].mSsid, rawEntry->mSsid, sizeof(currentList->mEntries[index].mSsid));
                currentList->mEntries[index].mSsidLength = rawEntry->mSsidLength;
                currentList->mEntries[index].mSsid[rawEntry->mSsidLength] = 0;
                currentList->mEntries[index].mBit4Set = (rawEntry->mFlags & RAW_ENTRY_FLAG_ENCRYPTED) ? 1 : 0;
                source = (u8 *) &rawEntry->mAddress;
                target = (u8 *) &currentList->mEntries[index].mAddress;
                target[0] = source[0];
                target[1] = source[1];
                target[2] = source[2];
                target[3] = source[3];
                target[4] = source[4];
                target[5] = source[5];
                index++;
                copied++;
                rawEntry++;
            } while (copied < result);
        }
        currentList->mCount = result;
        if (gExchangeStatus != EXCHANGE_STATUS_STARTED) {
            index = FindEntryWithBit4NewlyCleared(currentList, previousList, &changedIndex);
            if (index != 0) {
                entry = &currentList->mEntries[changedIndex];
                gSelectedEntryIndex = changedIndex;
                strcpy(gSelectedEntryName, entry->mSsid);
                target = (u8 *) &gSelectedEntryAddress;
                source = (u8 *) &entry->mAddress;
                target[0] = source[0];
                target[1] = source[1];
                target[2] = source[2];
                target[3] = source[3];
                target[4] = source[4];
                target[5] = source[5];
                FormatMacAddress(addressText, (const s8 *) &gSelectedEntryAddress);
                break;
            }
        }
        memcpy(previousList, currentList, summarySize);
        gExchangeStatus = EXCHANGE_STATUS_SEARCH_ROUND_DONE;
        CallStatusCallback();
        round++;
    }
    if (round >= 30 || GetTickMilliseconds() > gTimeoutAtMs) {
        result = -3;
    } else if (gStopRequested != 0) {
        result = -8;
    } else {
        result = 1;
    }
end:
    if (currentList != NULL) {
        CallFreeFunction(currentList);
    }
    if (previousList != NULL) {
        CallFreeFunction(previousList);
    }
    return result;
}

s32 SendBytesToAddress(s32 descriptor, const SocketAddress *address, const u8 *unused, const void *data, u32 size) {
    s32 result;
    result = SOC_SendTo(descriptor, data, size, 0, address);
    if (result < 0) {
        result = -4;
    }
    return result;
}

s32 SendBytesToAllOnesAddress(s32 descriptor, const void *data, u32 size) {
    SocketAddress address;
    u8 unused[4];
    address.mLength = sizeof(SocketAddress);
    address.mFamily = SOCKET_FAMILY_IPV4;
    address.mAddress = -1;
    address.mPort = EXCHANGE_SOCKET_PORT;
    SOC_U32to4U8(SOCL_GetHostID(), unused);
    return SendBytesToAddress(descriptor, &address, unused, data, size);
}

s32 SendBytesToAllOnesAddressWrapper(s32 descriptor, const void *unused, const void *data, u32 size) {
    return SendBytesToAllOnesAddress(descriptor, data, size);
}

// Returns the payload when the byte sum at its end matches, else NULL; stores the kind and length.
u8 *ReadExchangePacketAndCheckSum(const u8 *packet, u32 *kind, s32 *length) {
    u32 sum;
    const u8 *end;
    const u8 *cursor;
    sum = 0;
    *kind = SwapBytes16_inline(*(u16 *) packet);
    *length = SwapBytes16_inline(*OFFSET_PTR(u16, packet, 2));
    end = packet + 6 + *length;
    for (cursor = packet; cursor < end; cursor++) {
        sum += *cursor;
    }
    if ((u16) sum != SwapBytes16_inline(*(u16 *) end)) {
        return NULL;
    }
    return OFFSET_PTR(u8, packet, 6);
}

// Items are a big-endian type and length, then the value padded so the item is a multiple of 8 bytes.
u8 *ReadNextItem(u8 **cursor, u8 *end, u32 *type, s32 *length) {
    u8 *item;
    item = *cursor;
    if (item >= end) {
        return NULL;
    }
    *type = SwapBytes16_inline(*(u16 *) item);
    *length = SwapBytes16_inline(*OFFSET_PTR(u16, item, 2));
    item += 4;
    *cursor = item + (((*length + 0xb) & ~7) - 4);
    return item;
}

u8 *ReadFirstItem(const u8 *body, u32 *type, s32 *length) {
    u8 *cursor;
    cursor = OFFSET_PTR(u8, body, 8);
    return ReadNextItem(&cursor, cursor + SwapBytes16_inline(*(u16 *) body), type, length);
}

// Frames a body: six header bytes, the body (copied or transformed with the key), then the byte sum.
s32 BuildExchangePacket(u8 *packet, u32 kind, u8 *body, u32 length, const void *key) {
    u8 *end;
    u8 *cursor;
    u32 sum;
    end = packet;
    sum = 0;
    body[0] = 0;
    body[1] = 0;
    body[2] = 0;
    body[3] = 0;
    body[4] = 0;
    body[5] = 0;
    body[6] = 0;
    body[7] = 0;
    *(u16 *) body = SwapBytes16_inline(length - 8);
    if (key != NULL) {
        TransformBodyWithKey(packet + 6, body, length, key, 0x10);
        length += 8;
    } else {
        memcpy(packet + 6, body, length);
    }
    packet[0] = 0;
    packet[1] = 0;
    packet[2] = 0;
    packet[3] = 0;
    packet[4] = 0;
    packet[5] = 0;
    *(u16 *) packet = SwapBytes16_inline(kind);
    *OFFSET_PTR(u16, packet, 2) = SwapBytes16_inline(length);
    end += 6;
    end += length;
    for (cursor = packet; cursor < end; cursor++) {
        sum += *cursor;
    }
    *(u16 *) end = SwapBytes16_inline(sum);
    return end + 2 - packet;
}

u8 *AppendItem(u8 *out, u32 type, const void *value, u32 length) {
    u32 paddedSize;
    out[0] = 0;
    out[1] = 0;
    out[2] = 0;
    out[3] = 0;
    *(u16 *) out = SwapBytes16_inline(type);
    paddedSize = ((length + 0xb) & ~7) - 4;
    *OFFSET_PTR(u16, out, 2) = SwapBytes16_inline(length);
    out = OFFSET_PTR(u8, out, 4);
    memset(out, 0, paddedSize);
    memcpy(out, value, length);
    return out + paddedSize;
}

s32 BuildSingleItemBody(u8 *out, u32 type, const void *value, u32 length) {
    s32 size;
    out[0] = 0;
    out[1] = 0;
    out[2] = 0;
    out[3] = 0;
    out[4] = 0;
    out[5] = 0;
    out[6] = 0;
    out[7] = 0;
    size = AppendItem(out + 8, type, value, length) - out;
    *(u16 *) out = size - 8;
    return size;
}

typedef struct FirstReplyValues {
    /* 0 */ u16 mHalfword;
    /* 2 */ ExchangeItem3Bytes mSevenBytes;
} FirstReplyValues;

BOOL ParseAndCheckFirstExchangePacket(const u8 *packet, u32 *item5Flag) {
    u32 item1Value;
    u32 item2Value;
    s32 item5Value;
    u32 kind;
    s32 length;
    u32 type;
    s32 itemLength;
    u8 *payload;
    u8 *end;
    u8 *item;
    payload = ReadExchangePacketAndCheckSum(packet, &kind, &length);
    item1Value = 0;
    item2Value = 0;
    item5Value = 0;
    if (payload == NULL) {
        return FALSE;
    }
    if (kind != 1) {
        return FALSE;
    }
    end = payload + length;
    payload += 8;
    item = ReadNextItem(&payload, end, &type, &itemLength);
    if (item != NULL) {
        do {
            switch (type) {
                case 1:
                    item1Value = SwapBytes16_inline(*(u16 *) item);
                    break;
                case 2:
                    item2Value = SwapBytes16_inline(*(u16 *) item);
                    break;
                case 5:
                    item5Value = SwapBytes16_inline(*(u16 *) item);
                    break;
            }
            item = ReadNextItem(&payload, end, &type, &itemLength);
        } while (item != NULL);
    }
    if (item1Value != 1 || item2Value != 1) {
        return FALSE;
    }
    if (item5Value >= 1) {
        *item5Flag = 1;
    } else {
        *item5Flag = 0;
    }
    return TRUE;
}

s32 ReadExchangePacketPayloadOfKind(const u8 *packet, u32 kind, u8 *output, const void *key) {
    u32 packetKind;
    s32 length;
    u8 *payload;
    payload = ReadExchangePacketAndCheckSum(packet, &packetKind, &length);
    if (payload == NULL) {
        return 0;
    }
    if (packetKind != kind) {
        return 0;
    }
    if (key != NULL) {
        TransformBodyReversedWithKey(output, payload, length, key, 0x10);
        length -= 8;
    } else {
        memcpy(output, payload, length);
    }
    return length;
}

s32 BuildFirstReplyPacket(u8 *packet) {
    FirstReplyValues values;
    u8 *cursor;
    values.mHalfword = 0x100;
    values.mSevenBytes = gFirstReplyItem3Bytes;
    cursor = AppendItem(gFirstReplyItemBuffer, 1, &values, 2);
    cursor = AppendItem(cursor, 2, &values, 2);
    if (gReplyIncludesMacAddress != 0) {
        cursor = AppendItem(cursor, 5, &values, 2);
    }
    cursor = AppendItem(cursor, 3, &values.mSevenBytes, 7);
    if (gReplyIncludesMacAddress != 0) {
        cursor = AppendItem(cursor, 4, &gMacAddress, 6);
    }
    return BuildExchangePacket(packet, 2, gBodyBuffer, cursor - gFirstReplyItemBuffer + 8, NULL);
}

u32 GetMacAddress(void *address) {
    OS_GetMacAddress(address);
    return 0x1u;
}

// Stores this machine's address, then writes the higher then the lower of it and the entry's address, then four fixed
// bytes, as the 16-byte key.
s32 StoreMacAddressAndBuildKey(u8 *key, void *unused) {
    u8 peerAddress[6];
    u8 ownAddress[6];
    u8 ownText[0x20];
    u8 peerText[0x20];
    __memcpy(key + 0xc, "WARP", 4);
    __memcpy(peerAddress, &gSelectedEntryAddress, sizeof(MacAddress));
    peerAddress[0] &= 0xfd;
    GetMacAddress(ownAddress);
    __memcpy(&gMacAddress, ownAddress, sizeof(MacAddress));
    if (memcmp(peerAddress, ownAddress, 6) <= 0) {
        __memcpy(key, ownAddress, sizeof(MacAddress));
        __memcpy(key + 6, peerAddress, sizeof(MacAddress));
    } else {
        __memcpy(key, peerAddress, sizeof(MacAddress));
        __memcpy(key + 6, ownAddress, sizeof(MacAddress));
    }
    if (gFormatAddressesFlag != 0) {
        FormatMacAddress(ownText, (const s8 *) ownAddress);
        FormatMacAddress(peerText, (const s8 *) peerAddress);
    }
    return 1;
}

// Stores the items of types 0x201 to 0x20a in the record, the 0x203 and 0x204 words, the values and the item 0x20a of
// gExchangeResultItems.
s32 ParseExchangeResultPacketItems(u8 *body) {
    u8 *end;
    BOOL found;
    u8 *cursor;
    u32 type;
    s32 length;
    u8 *value;
    u8 *slot0x204;
    cursor = body + 8;
    found = FALSE;
    end = cursor + SwapBytes16_inline(*(u16 *) body);
    value = ReadNextItem(&cursor, end, &type, &length);
    while (value != NULL) {
        switch (type) {
            case 0x201:
                __clear(&gExchangeResultItems.mRecord, 0x20);
                memcpy(&gExchangeResultItems.mRecord, value, length);
                found = TRUE;
                break;
            case 0x202:
                gExchangeResultItems.mRecord.mItem202Value = SwapBytes16_inline(*(u16 *) value);
                break;
            case 0x203: {
                s32 value0x203;
                s32 index0x203;
                u8 *slot0x203;
                value0x203 = SwapBytes16_inline(*(u16 *) value);
                index0x203 = 0;
                slot0x203 = (u8 *) &gExchangeResultItems;
                for (; index0x203 < 4; index0x203++) {
                    *OFFSET_PTR(u32, slot0x203, 0x15c) = value0x203;
                    slot0x203 += 0x28;
                }
                break;
            }
            case 0x204: {
                u32 value0x204;
                s32 index0x203;
                value0x204 = SwapBytes16_inline(*(u16 *) value);
                index0x203 = 0;
                slot0x204 = (u8 *) &gExchangeResultItems;
                for (; index0x203 < 4; index0x203++) {
                    *OFFSET_PTR(u32, slot0x204, 0x160) = value0x204;
                    slot0x204 += 0x28;
                }
                break;
            }
                {
                    u32 value0x203;
                    s32 index0x204;
                    value0x203 = SwapBytes16_inline(*(u16 *) value);
                    index0x204 = 0;
                    slot0x204 = (u8 *) &gExchangeResultItems;
                    for (; index0x204 < 4; index0x204++) {
                        *OFFSET_PTR(u32, slot0x204, 0x160) = value0x203;
                        slot0x204 += 0x28;
                    }
                    break;
                }
            case 0x205:
                gExchangeResultItems.mRecord.mItem205Value = SwapBytes16_inline(*(u16 *) value);
                break;
            case 0x206:
            case 0x207:
            case 0x208:
            case 0x209:
                memset(gExchangeResultItems.mValues + (type - 0x206) * 0x28, 0, 0x20);
                if (gExchangeResultItems.mRecord.mStoreValuesAsHex == 1) {
                    u8 *hexCursor;
                    s32 byteIndex;
                    hexCursor = gExchangeResultItems.mValues + (type - 0x206) * 0x28;
                    for (byteIndex = 0; byteIndex < length; byteIndex++) {
                        hexCursor += FormatByteAsHex(hexCursor, *value++);
                    }
                } else {
                    memcpy(gExchangeResultItems.mValues + (type - 0x206) * 0x28, value, length);
                }
                break;
            case 0x20a:
                __clear(&gExchangeResultItems.mItem20a, 0x48);
                memcpy(&gExchangeResultItems.mItem20a, value, length);
                break;
        }
        value = ReadNextItem(&cursor, end, &type, &length);
    }
    return found;
}

BOOL ParseHexText(u8 *output, const s8 *text, s32 length) {
    u32 value;
    s32 index;
    value = 0;
    index = 0;
    for (; index < length; index++) {
        switch (text[index]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                value += text[index] - '0';
                break;
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
                value += text[index] - 'W';
                break;
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
                value += text[index] - '7';
                break;
            default:
                return FALSE;
        }
        if (index % 2 == 0) {
            value <<= 4;
        } else {
            output[index / 2] = value;
            value = 0;
        }
    }
    return TRUE;
}

// Builds gExchangeResult from gExchangeResultItems; returns 1, or -7 for an unknown item 0x202 value; for the
// value-texts one also for a zero item 0x205 value or a value text that is not empty, a WEP key size or twice one
// (hex).
s32 FillExchangeResultFromItems(void) {
    s32 result;
    s32 valueIndex;
    char valueBuffer[0x21];
    char *valueText;
    u8 *valueSource;
    u8 *resultBytes;
    result = 1;
    strcpy(gExchangeResult.mText, gExchangeResultItems.mRecord.mText);
    switch (gExchangeResultItems.mRecord.mItem202Value) {
        case KIND5_ITEM202_NONE:
            gExchangeResult.mKind = EXCHANGE_RESULT_KIND_NONE;
            break;
        case KIND5_ITEM202_VALUE_TEXTS:
            if (gExchangeResultItems.mRecord.mItem205Value == 0) {
                result = -7;
                break;
            }
            gExchangeResult.mItem205Value = gExchangeResultItems.mRecord.mItem205Value;
            valueIndex = 0;
            valueText = valueBuffer;
            valueSource = gExchangeResultItems.mValues;
            resultBytes = gExchangeResult.mValueBytes[0];
            for (; valueIndex < 4; valueIndex++) {
                memcpy(valueText, valueSource, 0x20);
                valueBuffer[0x20] = 0;
                switch (strlen(valueText)) {
                    case 0:
                        break;
                    case sizeof(WepKey5):
                        gExchangeResult.mKind = EXCHANGE_RESULT_KIND_WEP_KEY_5_BYTES;
                        *(WepKey5 *) resultBytes = *(WepKey5 *) valueText;
                        break;
                    case sizeof(WepKey5) * 2:
                        gExchangeResult.mKind = EXCHANGE_RESULT_KIND_WEP_KEY_5_BYTES;
                        ParseHexText(resultBytes, (s8 *) valueText, 10);
                        break;
                    case sizeof(WepKey13):
                        gExchangeResult.mKind = EXCHANGE_RESULT_KIND_WEP_KEY_13_BYTES;
                        *(WepKey13 *) resultBytes = *(WepKey13 *) valueText;
                        break;
                    case sizeof(WepKey13) * 2:
                        gExchangeResult.mKind = EXCHANGE_RESULT_KIND_WEP_KEY_13_BYTES;
                        ParseHexText(resultBytes, (s8 *) valueText, 26);
                        break;
                    case sizeof(WepKey16):
                        gExchangeResult.mKind = EXCHANGE_RESULT_KIND_WEP_KEY_16_BYTES;
                        *(WepKey16 *) resultBytes = *(WepKey16 *) valueText;
                        break;
                    case sizeof(WepKey16) * 2:
                        gExchangeResult.mKind = EXCHANGE_RESULT_KIND_WEP_KEY_16_BYTES;
                        ParseHexText(resultBytes, (s8 *) valueText, 32);
                        break;
                    default:
                        result = -7;
                        break;
                }
                valueSource += 0x28;
                resultBytes += 0x20;
            }
            break;
        case KIND5_ITEM202_WORDS_A:
            gExchangeResult.mKind = EXCHANGE_RESULT_KIND_WORDS_A;
            __memcpy(&gExchangeResult.mItem20aWords, &gExchangeResultItems.mItem20a.mBytes,
                     sizeof(gExchangeResult.mItem20aWords));
            break;
        case KIND5_ITEM202_WORDS_B:
            gExchangeResult.mKind = EXCHANGE_RESULT_KIND_WORDS_B;
            __memcpy(&gExchangeResult.mItem20aWords, &gExchangeResultItems.mItem20a.mBytes,
                     sizeof(gExchangeResult.mItem20aWords));
            break;
        default:
            result = -7;
            break;
    }
    return result;
}

// Steps 1 to 10: find an entry, connect, open a socket, then trade packets of kind 1 to 6; returns 1 or a negative
// error.
s32 RunExchange(void) {
    u32 stamp;
    s32 descriptor;
    s32 result;
    s32 retryCount;
    BOOL done;
    u8 *value;
    SocketAddress bindAddress;
    SocketAddress peerAddress;
    u32 itemType;
    s32 itemLength;
    u32 now;
    descriptor = 0;
    result = -5;
    stamp = 0;
    retryCount = 0;
    done = FALSE;
    gExchangeState = EXCHANGE_STEP_SEARCH_ENTRY;
    while (done == FALSE && gStopRequested == 0) {
        OS_Sleep(500);
        switch (gExchangeState) {
            case EXCHANGE_STEP_SEARCH_ENTRY:
                result = SearchEntriesAndStoreEntryWithBit4NewlyCleared();
                if (result != 1) {
                    done = TRUE;
                } else {
                    gExchangeStatus = EXCHANGE_STATUS_ENTRY_FOUND;
                    CallStatusCallback();
                    gExchangeState = EXCHANGE_STEP_CONNECT;
                }
                break;
            case EXCHANGE_STEP_CONNECT:
                result = ConnectExchangeAndStartSockets();
                if (result != 1) {
                    done = TRUE;
                } else {
                    gExchangeState = EXCHANGE_STEP_OPEN_SOCKET;
                }
                break;
            case EXCHANGE_STEP_OPEN_SOCKET:
                descriptor = SOC_Socket(2, 2, 0);
                if (descriptor < 0) {
                    result = -2;
                    done = TRUE;
                    break;
                }
                __clear(&bindAddress, sizeof(SocketAddress));
                bindAddress.mLength = sizeof(SocketAddress);
                bindAddress.mFamily = SOCKET_FAMILY_IPV4;
                bindAddress.mPort = EXCHANGE_SOCKET_PORT;
                bindAddress.mAddress = 0;
                result = SOC_Bind(descriptor, &bindAddress);
                if (result < 0) {
                    result = -2;
                    done = TRUE;
                } else {
                    gExchangeState = EXCHANGE_STEP_WAIT_FIRST_PACKET;
                }
                break;
            case EXCHANGE_STEP_WAIT_FIRST_PACKET:
                if (GetTickMilliseconds() >= gTimeoutAtMs) {
                    SOC_Close(descriptor);
                    result = -3;
                    done = TRUE;
                    break;
                }
                peerAddress.mLength = sizeof(SocketAddress);
                StoreMacAddressAndBuildKey(gFirstKey, &peerAddress);
                if (SOC_RecvFrom(descriptor, gPacketBuffer, 0x800, 4, &peerAddress) > 0) {
                    if (ParseAndCheckFirstExchangePacket(gPacketBuffer, &gReplyIncludesMacAddress) != FALSE) {
                        gTimeoutAtMs = GetTickMilliseconds() + 30000;
                        gExchangeState = EXCHANGE_STEP_SEND_FIRST_REPLY;
                        gExchangeStatus = EXCHANGE_STATUS_FIRST_PACKET_ACCEPTED;
                        CallStatusCallback();
                    }
                }
                break;
            case EXCHANGE_STEP_SEND_FIRST_REPLY:
                gPacketLength = BuildFirstReplyPacket(gPacketBuffer);
                SendBytesToAllOnesAddressWrapper(descriptor, &peerAddress, gPacketBuffer, gPacketLength);
                stamp = GetTickMilliseconds();
                gExchangeState = EXCHANGE_STEP_WAIT_SECOND_KEY;
                break;
            case EXCHANGE_STEP_WAIT_SECOND_KEY:
                if (GetTickMilliseconds() >= gTimeoutAtMs) {
                    SOC_Close(descriptor);
                    result = -4;
                    done = TRUE;
                    break;
                }
                if (SOC_RecvFrom(descriptor, gPacketBuffer, 0x800, 4, &peerAddress) > 0 &&
                    ReadExchangePacketPayloadOfKind(gPacketBuffer, 3, gBodyBuffer, gFirstKey) != 0) {
                    value = ReadFirstItem(gBodyBuffer, &itemType, &itemLength);
                    if (itemType == 0x101) {
                        now = GetTickMilliseconds();
                        gSecondKeyReceivedPart = *(SecondKeyPart *) value;
                        ComputeHash(gSecondKeyHashedPart, (const u8 *) &now, 4);
                        retryCount = 0;
                        gExchangeState = EXCHANGE_STEP_SEND_KEY_HASH;
                        gExchangeStatus = EXCHANGE_STATUS_SECOND_KEY_RECEIVED;
                        gTimeoutAtMs = -1;
                        CallStatusCallback();
                    }
                } else if (GetTickMilliseconds() >= stamp + 1000) {
                    gExchangeState = EXCHANGE_STEP_SEND_FIRST_REPLY;
                }
                break;
            case EXCHANGE_STEP_SEND_KEY_HASH:
                gBodyLength = BuildSingleItemBody(gBodyBuffer, 0x102, gSecondKeyHashedPart, 8);
                gPacketLength = BuildExchangePacket(gPacketBuffer, 4, gBodyBuffer, gBodyLength, gFirstKey);
                SendBytesToAllOnesAddressWrapper(descriptor, &peerAddress, gPacketBuffer, gPacketLength);
                stamp = GetTickMilliseconds();
                __clear(&gExchangeResultItems, sizeof(ExchangeResultItems));
                gExchangeState = EXCHANGE_STEP_WAIT_RESULT;
                break;
            case EXCHANGE_STEP_WAIT_RESULT:
                if (SOC_RecvFrom(descriptor, gPacketBuffer, 0x800, 4, &peerAddress) > 0) {
                    gBodyLength =
                        ReadExchangePacketPayloadOfKind(gPacketBuffer, 5, gBodyBuffer, &gSecondKeyReceivedPart);
                    if (gBodyLength != 0 && ParseExchangeResultPacketItems(gBodyBuffer) != 0) {
                        if (*(s8 *) gExchangeResultItems.mRecord.mText != 0) {
                            gReceivedTextNonEmpty = 1;
                        } else {
                            gReceivedTextNonEmpty = 0;
                        }
                        retryCount = 0;
                        gExchangeState = EXCHANGE_STEP_SEND_RESULT_ACK;
                        break;
                    }
                }
                if (GetTickMilliseconds() >= stamp + 1000) {
                    retryCount++;
                    if (retryCount >= 10) {
                        SOC_Close(descriptor);
                        result = -2;
                        done = TRUE;
                    } else {
                        gExchangeState = EXCHANGE_STEP_SEND_KEY_HASH;
                    }
                }
                break;
            case EXCHANGE_STEP_SEND_RESULT_ACK:
                gBodyLength = BuildSingleItemBody(gBodyBuffer, 0x301, &gReceivedTextNonEmpty, 1);
                gPacketLength =
                    BuildExchangePacket(gPacketBuffer, 6, gBodyBuffer, gBodyLength, &gSecondKeyReceivedPart);
                if (GetExchangeWcmState() != 7) {
                    stamp = GetTickMilliseconds() + 1000;
                    retryCount = 10;
                    gExchangeState = EXCHANGE_STEP_WAIT_ACK_RESEND;
                } else {
                    SendBytesToAllOnesAddressWrapper(descriptor, &peerAddress, gPacketBuffer, gPacketLength);
                    stamp = GetTickMilliseconds();
                    gExchangeState = EXCHANGE_STEP_WAIT_ACK_RESEND;
                }
                break;
            case EXCHANGE_STEP_WAIT_ACK_RESEND:
                if (GetTickMilliseconds() >= stamp + 1000) {
                    retryCount++;
                    if (retryCount >= 10) {
                        done = TRUE;
                        result = FillExchangeResultFromItems();
                    } else {
                        gExchangeState = EXCHANGE_STEP_SEND_RESULT_ACK;
                    }
                }
                break;
        }
    }
    if (descriptor != 0) {
        SOC_Close(descriptor);
    }
    if (gStopRequested != 0) {
        result = -8;
    }
    return result;
}

void RunExchangeThread(void) {
    int result;

    result = RunExchange();
    gExchangeResultCode = result;
    DisconnectExchangeAndStopSockets();
    if (result == 1) {
        gExchangeStatus = EXCHANGE_STATUS_SUCCEEDED;
    } else {
        gExchangeStatus = EXCHANGE_STATUS_ENDED_WITHOUT_RESULT;
    }
    gTimeoutAtMs = -1;
    CallStatusCallback();
}

typedef struct BodyBlock {
    /* 0 */ u8 mUnk_00[8];
} BodyBlock;

BOOL TransformBodyWithKey(u8 *output, u8 *input, u32 inputLength, u8 *key, int keyLength) {
    u8 workBuffer[16];
    u64 counterBytes;
    u32 keyWords[80];
    u32 fixedBytes[2];
    int blockIndex;
    int pass;
    int blockCount;
    int lastGroup;
    u64 counter;
    u8 *cursor;
    u8 *source;
    enum { BYTES_LEFT_DONE } bytesLeft;

    fixedBytes[0] = 0xa6a6a6a6;
    fixedBytes[1] = 0xa6a6a6a6;
    if ((inputLength & 7) != 0 || (keyLength & 7) != 0) {
        return FALSE;
    }
    blockCount = inputLength >> 3;
    if (blockCount < 2) {
        return FALSE;
    }
    lastGroup = ExpandKey(keyWords, key, keyLength << 3);
    memcpy(output + 8, input, inputLength);
    cursor = workBuffer;
    source = (u8 *) fixedBytes;
    bytesLeft = 8;
    do {
        *cursor++ = *source++;
    } while (--bytesLeft != 0);
    for (pass = 0; pass < 6; pass++) {
        for (blockIndex = 1; blockIndex <= blockCount; blockIndex++) {
            cursor = output + (u32) blockIndex * 8;
            *(BodyBlock *) (workBuffer + 8) = *(BodyBlock *) cursor;
            TransformBlock(keyWords, lastGroup, workBuffer, workBuffer);
            counter = (s64) blockCount * (s32) pass + (s32) blockIndex;
            counterBytes = (((counter & 0x00000000000000ffULL) << 56) | ((counter & 0x000000000000ff00ULL) << 40) |
                            ((counter & 0x0000000000ff0000ULL) << 24) | ((counter & 0x00000000ff000000ULL) << 8) |
                            ((counter & 0x000000ff00000000ULL) >> 8) | ((counter & 0x0000ff0000000000ULL) >> 24) |
                            ((counter & 0x00ff000000000000ULL) >> 40) | ((counter & 0xff00000000000000ULL) >> 56));
            XorEightBytes(workBuffer, (u8 *) &counterBytes, workBuffer);
            *(BodyBlock *) cursor = *(BodyBlock *) (workBuffer + 8);
        }
    }
    *(BodyBlock *) output = *(BodyBlock *) workBuffer;
    return TRUE;
}

BOOL TransformBodyReversedWithKey(u8 *output, u8 *input, u32 inputLength, u8 *key, int keyLength) {
    u8 workBuffer[16];
    u64 counterBytes;
    u32 keyWords[80];
    u32 fixedBytes[2];
    int blockIndex;
    int pass;
    int blockCount;
    int lastGroup;
    BOOL valid;
    u64 counter;
    u8 *cursor;
    u8 *copyCursor;
    enum { BYTES_LEFT_DONE } bytesLeft;

    valid = TRUE;
    fixedBytes[0] = 0xa6a6a6a6;
    fixedBytes[1] = 0xa6a6a6a6;
    if ((inputLength & 7) != 0 || (keyLength & 7) != 0) {
        return FALSE;
    }
    blockCount = (inputLength - 1) >> 3;
    if (blockCount < 2) {
        return FALSE;
    }
    lastGroup = ExpandKeyReversedWithTables(keyWords, key, keyLength << 3);
    cursor = workBuffer;
    copyCursor = input;
    bytesLeft = 8;
    do {
        *cursor++ = *copyCursor++;
    } while (--bytesLeft != 0);
    memcpy(output, input + 8, inputLength - 1);
    for (pass = 5; pass >= 0; pass--) {
        for (blockIndex = blockCount; blockIndex > 0; blockIndex--) {
            counter = (s64) blockCount * (s32) pass + (s32) blockIndex;
            counterBytes = (((counter & 0x00000000000000ffULL) << 56) | ((counter & 0x000000000000ff00ULL) << 40) |
                            ((counter & 0x0000000000ff0000ULL) << 24) | ((counter & 0x00000000ff000000ULL) << 8) |
                            ((counter & 0x000000ff00000000ULL) >> 8) | ((counter & 0x0000ff0000000000ULL) >> 24) |
                            ((counter & 0x00ff000000000000ULL) >> 40) | ((counter & 0xff00000000000000ULL) >> 56));
            XorEightBytes(workBuffer, (u8 *) &counterBytes, workBuffer);
            cursor = output + (blockIndex - 1) * 8;
            {
                u8 *source = cursor;
                copyCursor = workBuffer + 8;
                bytesLeft = 8;
                do {
                    *copyCursor++ = *source++;
                } while (--bytesLeft != 0);
            }
            TransformBlockReversed(keyWords, lastGroup, workBuffer, workBuffer);
            {
                u8 *source = workBuffer + 8;
                bytesLeft = 8;
                do {
                    *cursor++ = *source++;
                } while (--bytesLeft != 0);
            }
        }
    }
    if (memcmp((u8 *) fixedBytes, workBuffer, 8) != 0) {
        valid = FALSE;
    }
    return valid;
}

void XorEightBytes(u8 *first, u8 *second, u8 *output) {
    *output = *first ^ *second;
    output[1] = first[1] ^ second[1];
    output[2] = first[2] ^ second[2];
    output[3] = first[3] ^ second[3];
    output[4] = first[4] ^ second[4];
    output[5] = first[5] ^ second[5];
    output[6] = first[6] ^ second[6];
    output[7] = first[7] ^ second[7];
}

// Expands the key into 4 * (n + 1) words and returns n: 10, 12 or 14 for 128, 192 or 256 bits.
int ExpandKey(u32 *words, u8 *key, int keyBits) {
    int roundIndex = 0;
    u32 lastWord;

    words[0] = (key[0] << 24) ^ (key[1] << 16) ^ (key[2] << 8) ^ key[3];
    words[1] = (key[4] << 24) ^ (key[5] << 16) ^ (key[6] << 8) ^ key[7];
    words[2] = (key[8] << 24) ^ (key[9] << 16) ^ (key[10] << 8) ^ key[11];
    words[3] = (key[12] << 24) ^ (key[13] << 16) ^ (key[14] << 8) ^ key[15];
    if (keyBits == 128) {
        for (;;) {
            lastWord = words[3];
            words[4] = words[0] ^ (gSubstitutionTable[(lastWord >> 16) & 0xff] & 0xff000000) ^
                       (gSubstitutionTable[(lastWord >> 8) & 0xff] & 0x00ff0000) ^
                       (gSubstitutionTable[lastWord & 0xff] & 0x0000ff00) ^
                       (gSubstitutionTable[lastWord >> 24] & 0x000000ff) ^ gKeyRoundConstants[roundIndex];
            words[5] = words[1] ^ words[4];
            words[6] = words[2] ^ words[5];
            words[7] = words[3] ^ words[6];
            if (++roundIndex == 10) {
                return 10;
            }
            words += 4;
        }
    }
    words[4] = (key[16] << 24) ^ (key[17] << 16) ^ (key[18] << 8) ^ key[19];
    words[5] = (key[20] << 24) ^ (key[21] << 16) ^ (key[22] << 8) ^ key[23];
    if (keyBits == 192) {
        for (;;) {
            lastWord = words[5];
            words[6] = words[0] ^ (gSubstitutionTable[(lastWord >> 16) & 0xff] & 0xff000000) ^
                       (gSubstitutionTable[(lastWord >> 8) & 0xff] & 0x00ff0000) ^
                       (gSubstitutionTable[lastWord & 0xff] & 0x0000ff00) ^
                       (gSubstitutionTable[lastWord >> 24] & 0x000000ff) ^ gKeyRoundConstants[roundIndex];
            words[7] = words[1] ^ words[6];
            words[8] = words[2] ^ words[7];
            words[9] = words[3] ^ words[8];
            if (++roundIndex == 8) {
                return 12;
            }
            words[10] = words[4] ^ words[9];
            words[11] = words[5] ^ words[10];
            words += 6;
        }
    }
    words[6] = (key[24] << 24) ^ (key[25] << 16) ^ (key[26] << 8) ^ key[27];
    words[7] = (key[28] << 24) ^ (key[29] << 16) ^ (key[30] << 8) ^ key[31];
    if (keyBits == 256) {
        for (;;) {
            lastWord = words[7];
            words[8] = words[0] ^ (gSubstitutionTable[(lastWord >> 16) & 0xff] & 0xff000000) ^
                       (gSubstitutionTable[(lastWord >> 8) & 0xff] & 0x00ff0000) ^
                       (gSubstitutionTable[lastWord & 0xff] & 0x0000ff00) ^
                       (gSubstitutionTable[lastWord >> 24] & 0x000000ff) ^ gKeyRoundConstants[roundIndex];
            words[9] = words[1] ^ words[8];
            words[10] = words[2] ^ words[9];
            words[11] = words[3] ^ words[10];
            if (++roundIndex == 7) {
                return 14;
            }
            lastWord = words[11];
            words[12] = words[4] ^ (gSubstitutionTable[lastWord >> 24] & 0xff000000) ^
                        (gSubstitutionTable[(lastWord >> 16) & 0xff] & 0x00ff0000) ^
                        (gSubstitutionTable[(lastWord >> 8) & 0xff] & 0x0000ff00) ^
                        (gSubstitutionTable[lastWord & 0xff] & 0x000000ff);
            words[13] = words[5] ^ words[12];
            words[14] = words[6] ^ words[13];
            words[15] = words[7] ^ words[14];
            words += 8;
        }
    }
    return roundIndex;
}

// Expands the key, reverses the order of its four-word groups and passes the inner ones through tables.
int ExpandKeyReversedWithTables(u32 *words, u8 *key, int keyBits) {
    int i, highIndex, lastGroup;
    u32 swapWord;

    lastGroup = ExpandKey(words, key, keyBits);
    for (i = 0, highIndex = 4 * lastGroup; i < highIndex; i += 4, highIndex -= 4) {
        swapWord = words[i];
        words[i] = words[highIndex];
        words[highIndex] = swapWord;
        swapWord = words[i + 1];
        words[i + 1] = words[highIndex + 1];
        words[highIndex + 1] = swapWord;
        swapWord = words[i + 2];
        words[i + 2] = words[highIndex + 2];
        words[highIndex + 2] = swapWord;
        swapWord = words[i + 3];
        words[i + 3] = words[highIndex + 3];
        words[highIndex + 3] = swapWord;
    }
    for (i = 1; i < lastGroup; i++) {
        words += 4;
        words[0] = gReversedTableByte3[gSubstitutionTable[words[0] >> 24] & 0xff] ^
                   gReversedTableByte2[gSubstitutionTable[(words[0] >> 16) & 0xff] & 0xff] ^
                   gReversedTableByte1[gSubstitutionTable[(words[0] >> 8) & 0xff] & 0xff] ^
                   gReversedTableByte0[gSubstitutionTable[words[0] & 0xff] & 0xff];
        words[1] = gReversedTableByte3[gSubstitutionTable[words[1] >> 24] & 0xff] ^
                   gReversedTableByte2[gSubstitutionTable[(words[1] >> 16) & 0xff] & 0xff] ^
                   gReversedTableByte1[gSubstitutionTable[(words[1] >> 8) & 0xff] & 0xff] ^
                   gReversedTableByte0[gSubstitutionTable[words[1] & 0xff] & 0xff];
        words[2] = gReversedTableByte3[gSubstitutionTable[words[2] >> 24] & 0xff] ^
                   gReversedTableByte2[gSubstitutionTable[(words[2] >> 16) & 0xff] & 0xff] ^
                   gReversedTableByte1[gSubstitutionTable[(words[2] >> 8) & 0xff] & 0xff] ^
                   gReversedTableByte0[gSubstitutionTable[words[2] & 0xff] & 0xff];
        words[3] = gReversedTableByte3[gSubstitutionTable[words[3] >> 24] & 0xff] ^
                   gReversedTableByte2[gSubstitutionTable[(words[3] >> 16) & 0xff] & 0xff] ^
                   gReversedTableByte1[gSubstitutionTable[(words[3] >> 8) & 0xff] & 0xff] ^
                   gReversedTableByte0[gSubstitutionTable[words[3] & 0xff] & 0xff];
    }
    return lastGroup;
}

void TransformBlock(u32 *keyWords, int lastGroup, u8 *input, u8 *output) {
    u32 s0, s1, s2, s3, nextFirst, nextSecond, nextThird, nextFourth;
    int passesLeft;

    s0 = ((input[0] << 24) ^ (input[1] << 16) ^ (input[2] << 8) ^ input[3]) ^ keyWords[0];
    s1 = ((input[4] << 24) ^ (input[5] << 16) ^ (input[6] << 8) ^ input[7]) ^ keyWords[1];
    s2 = ((input[8] << 24) ^ (input[9] << 16) ^ (input[10] << 8) ^ input[11]) ^ keyWords[2];
    s3 = ((input[12] << 24) ^ (input[13] << 16) ^ (input[14] << 8) ^ input[15]) ^ keyWords[3];
    passesLeft = lastGroup >> 1;
    for (;;) {
        nextFirst = gTransformTableByte3[s0 >> 24] ^ gTransformTableByte2[(s1 >> 16) & 0xff] ^
             gTransformTableByte1[(s2 >> 8) & 0xff] ^ gTransformTableByte0[s3 & 0xff] ^ keyWords[4];
        nextSecond = gTransformTableByte3[s1 >> 24] ^ gTransformTableByte2[(s2 >> 16) & 0xff] ^
             gTransformTableByte1[(s3 >> 8) & 0xff] ^ gTransformTableByte0[s0 & 0xff] ^ keyWords[5];
        nextThird = gTransformTableByte3[s2 >> 24] ^ gTransformTableByte2[(s3 >> 16) & 0xff] ^
             gTransformTableByte1[(s0 >> 8) & 0xff] ^ gTransformTableByte0[s1 & 0xff] ^ keyWords[6];
        nextFourth = gTransformTableByte3[s3 >> 24] ^ gTransformTableByte2[(s0 >> 16) & 0xff] ^
             gTransformTableByte1[(s1 >> 8) & 0xff] ^ gTransformTableByte0[s2 & 0xff] ^ keyWords[7];
        keyWords += 8;
        if (--passesLeft == 0) {
            break;
        }
        s0 = gTransformTableByte3[nextFirst >> 24] ^ gTransformTableByte2[(nextSecond >> 16) & 0xff] ^
             gTransformTableByte1[(nextThird >> 8) & 0xff] ^ gTransformTableByte0[nextFourth & 0xff] ^ keyWords[0];
        s1 = gTransformTableByte3[nextSecond >> 24] ^ gTransformTableByte2[(nextThird >> 16) & 0xff] ^
             gTransformTableByte1[(nextFourth >> 8) & 0xff] ^ gTransformTableByte0[nextFirst & 0xff] ^ keyWords[1];
        s2 = gTransformTableByte3[nextThird >> 24] ^ gTransformTableByte2[(nextFourth >> 16) & 0xff] ^
             gTransformTableByte1[(nextFirst >> 8) & 0xff] ^ gTransformTableByte0[nextSecond & 0xff] ^ keyWords[2];
        s3 = gTransformTableByte3[nextFourth >> 24] ^ gTransformTableByte2[(nextFirst >> 16) & 0xff] ^
             gTransformTableByte1[(nextSecond >> 8) & 0xff] ^ gTransformTableByte0[nextThird & 0xff] ^ keyWords[3];
    }
    s0 = (gSubstitutionTable[nextFirst >> 24] & 0xff000000) ^
         (gSubstitutionTable[(nextSecond >> 16) & 0xff] & 0x00ff0000) ^
         (gSubstitutionTable[(nextThird >> 8) & 0xff] & 0x0000ff00) ^
         (gSubstitutionTable[nextFourth & 0xff] & 0x000000ff) ^ keyWords[0];
    output[0] = s0 >> 24;
    output[1] = s0 >> 16;
    output[2] = s0 >> 8;
    output[3] = s0;
    s1 = (gSubstitutionTable[nextSecond >> 24] & 0xff000000) ^
         (gSubstitutionTable[(nextThird >> 16) & 0xff] & 0x00ff0000) ^
         (gSubstitutionTable[(nextFourth >> 8) & 0xff] & 0x0000ff00) ^
         (gSubstitutionTable[nextFirst & 0xff] & 0x000000ff) ^ keyWords[1];
    output[4] = s1 >> 24;
    output[5] = s1 >> 16;
    output[6] = s1 >> 8;
    output[7] = s1;
    s2 = (gSubstitutionTable[nextThird >> 24] & 0xff000000) ^
         (gSubstitutionTable[(nextFourth >> 16) & 0xff] & 0x00ff0000) ^
         (gSubstitutionTable[(nextFirst >> 8) & 0xff] & 0x0000ff00) ^
         (gSubstitutionTable[nextSecond & 0xff] & 0x000000ff) ^ keyWords[2];
    output[8] = s2 >> 24;
    output[9] = s2 >> 16;
    output[10] = s2 >> 8;
    output[11] = s2;
    s3 = (gSubstitutionTable[nextFourth >> 24] & 0xff000000) ^
         (gSubstitutionTable[(nextFirst >> 16) & 0xff] & 0x00ff0000) ^
         (gSubstitutionTable[(nextSecond >> 8) & 0xff] & 0x0000ff00) ^
         (gSubstitutionTable[nextThird & 0xff] & 0x000000ff) ^ keyWords[3];
    output[12] = s3 >> 24;
    output[13] = s3 >> 16;
    output[14] = s3 >> 8;
    output[15] = s3;
}

void TransformBlockReversed(u32 *keyWords, int lastGroup, u8 *input, u8 *output) {
    u32 s0, s1, s2, s3, nextFirst, nextSecond, nextThird, nextFourth;
    int passesLeft;

    s0 = ((input[0] << 24) ^ (input[1] << 16) ^ (input[2] << 8) ^ input[3]) ^ keyWords[0];
    s1 = ((input[4] << 24) ^ (input[5] << 16) ^ (input[6] << 8) ^ input[7]) ^ keyWords[1];
    s2 = ((input[8] << 24) ^ (input[9] << 16) ^ (input[10] << 8) ^ input[11]) ^ keyWords[2];
    s3 = ((input[12] << 24) ^ (input[13] << 16) ^ (input[14] << 8) ^ input[15]) ^ keyWords[3];
    passesLeft = lastGroup >> 1;
    for (;;) {
        nextFirst = gReversedTableByte3[s0 >> 24] ^ gReversedTableByte2[(s3 >> 16) & 0xff] ^
             gReversedTableByte1[(s2 >> 8) & 0xff] ^ gReversedTableByte0[s1 & 0xff] ^ keyWords[4];
        nextSecond = gReversedTableByte3[s1 >> 24] ^ gReversedTableByte2[(s0 >> 16) & 0xff] ^
             gReversedTableByte1[(s3 >> 8) & 0xff] ^ gReversedTableByte0[s2 & 0xff] ^ keyWords[5];
        nextThird = gReversedTableByte3[s2 >> 24] ^ gReversedTableByte2[(s1 >> 16) & 0xff] ^
             gReversedTableByte1[(s0 >> 8) & 0xff] ^ gReversedTableByte0[s3 & 0xff] ^ keyWords[6];
        nextFourth = gReversedTableByte3[s3 >> 24] ^ gReversedTableByte2[(s2 >> 16) & 0xff] ^
             gReversedTableByte1[(s1 >> 8) & 0xff] ^ gReversedTableByte0[s0 & 0xff] ^ keyWords[7];
        keyWords += 8;
        if (--passesLeft == 0) {
            break;
        }
        s0 = gReversedTableByte3[nextFirst >> 24] ^ gReversedTableByte2[(nextFourth >> 16) & 0xff] ^
             gReversedTableByte1[(nextThird >> 8) & 0xff] ^ gReversedTableByte0[nextSecond & 0xff] ^ keyWords[0];
        s1 = gReversedTableByte3[nextSecond >> 24] ^ gReversedTableByte2[(nextFirst >> 16) & 0xff] ^
             gReversedTableByte1[(nextFourth >> 8) & 0xff] ^ gReversedTableByte0[nextThird & 0xff] ^ keyWords[1];
        s2 = gReversedTableByte3[nextThird >> 24] ^ gReversedTableByte2[(nextSecond >> 16) & 0xff] ^
             gReversedTableByte1[(nextFirst >> 8) & 0xff] ^ gReversedTableByte0[nextFourth & 0xff] ^ keyWords[2];
        s3 = gReversedTableByte3[nextFourth >> 24] ^ gReversedTableByte2[(nextThird >> 16) & 0xff] ^
             gReversedTableByte1[(nextSecond >> 8) & 0xff] ^ gReversedTableByte0[nextFirst & 0xff] ^ keyWords[3];
    }
    s0 = (gReversedSubstitutionTable[nextFirst >> 24] & 0xff000000) ^
         (gReversedSubstitutionTable[(nextFourth >> 16) & 0xff] & 0x00ff0000) ^
         (gReversedSubstitutionTable[(nextThird >> 8) & 0xff] & 0x0000ff00) ^
         (gReversedSubstitutionTable[nextSecond & 0xff] & 0x000000ff) ^ keyWords[0];
    output[0] = s0 >> 24;
    output[1] = s0 >> 16;
    output[2] = s0 >> 8;
    output[3] = s0;
    s1 = (gReversedSubstitutionTable[nextSecond >> 24] & 0xff000000) ^
         (gReversedSubstitutionTable[(nextFirst >> 16) & 0xff] & 0x00ff0000) ^
         (gReversedSubstitutionTable[(nextFourth >> 8) & 0xff] & 0x0000ff00) ^
         (gReversedSubstitutionTable[nextThird & 0xff] & 0x000000ff) ^ keyWords[1];
    output[4] = s1 >> 24;
    output[5] = s1 >> 16;
    output[6] = s1 >> 8;
    output[7] = s1;
    s2 = (gReversedSubstitutionTable[nextThird >> 24] & 0xff000000) ^
         (gReversedSubstitutionTable[(nextSecond >> 16) & 0xff] & 0x00ff0000) ^
         (gReversedSubstitutionTable[(nextFirst >> 8) & 0xff] & 0x0000ff00) ^
         (gReversedSubstitutionTable[nextFourth & 0xff] & 0x000000ff) ^ keyWords[2];
    output[8] = s2 >> 24;
    output[9] = s2 >> 16;
    output[10] = s2 >> 8;
    output[11] = s2;
    s3 = (gReversedSubstitutionTable[nextFourth >> 24] & 0xff000000) ^
         (gReversedSubstitutionTable[(nextThird >> 16) & 0xff] & 0x00ff0000) ^
         (gReversedSubstitutionTable[(nextSecond >> 8) & 0xff] & 0x0000ff00) ^
         (gReversedSubstitutionTable[nextFirst & 0xff] & 0x000000ff) ^ keyWords[3];
    output[12] = s3 >> 24;
    output[13] = s3 >> 16;
    output[14] = s3 >> 8;
    output[15] = s3;
}

void ResetHashContext(HashContext *context) {
    context->mBitCountHigh = 0;
    context->mBitCountLow = context->mBitCountHigh;
    context->mHashWords[0] = 0x67452301;
    context->mHashWords[1] = 0xefcdab89;
    context->mHashWords[2] = 0x98badcfe;
    context->mHashWords[3] = 0x10325476;
}

void AddBytesToHash(HashContext *context, const u8 *bytes, u32 count) {
    u32 offset;
    u32 used;
    u32 room;
    used = (context->mBitCountLow >> 3) & 0x3f;
    context->mBitCountLow += count << 3;
    if (context->mBitCountLow < (count << 3)) {
        context->mBitCountHigh++;
    }
    context->mBitCountHigh += count >> 29;
    room = 0x40 - used;
    if (count >= room) {
        CopyBytesWithLoop(context->mBuffer + used, bytes, room);
        ProcessHashBlock(context, context->mBuffer);
        for (offset = room; offset + 63 < count; offset += 64) {
            ProcessHashBlock(context, bytes + offset);
        }
        used = 0;
    } else {
        offset = 0;
    }
    CopyBytesWithLoop(context->mBuffer + used, bytes + offset, count - offset);
}

// Pads the data, writes the 16 digest bytes and zeroes the context.
void FinishHash(u8 *digest, HashContext *context) {
    u8 countBytes[8];
    u32 used;
    u32 padLength;
    CopyWordsToBytesLittleEndian(countBytes, &context->mBitCountLow, 8);
    used = (context->mBitCountLow >> 3) & 0x3f;
    if (used < 0x38) {
        padLength = 0x38 - used;
    } else {
        padLength = 0x78 - used;
    }
    AddBytesToHash(context, gHashPadding, padLength);
    AddBytesToHash(context, countBytes, 8);
    CopyWordsToBytesLittleEndian(digest, context->mHashWords, 0x10);
    FillBytesWithLoop(context, 0, 0x58);
}

void ProcessHashBlock(HashContext *context, const u8 *block) {
    u32 hashA = context->mHashWords[0];
    u32 hashB = context->mHashWords[1];
    u32 hashC = context->mHashWords[2];
    u32 hashD = context->mHashWords[3];
    u32 words[16];

    CopyBytesToWordsLittleEndian(words, block, 64);
    hashA += ((hashB & hashC) | (~hashB & hashD)) + words[0] + 0xd76aa478;
    hashA = (hashA << 7) | (hashA >> 25);
    hashA += hashB;
    hashD += ((hashA & hashB) | (~hashA & hashC)) + words[1] + 0xe8c7b756;
    hashD = (hashD << 12) | (hashD >> 20);
    hashD += hashA;
    hashC += ((hashD & hashA) | (~hashD & hashB)) + words[2] + 0x242070db;
    hashC = (hashC << 17) | (hashC >> 15);
    hashC += hashD;
    hashB += ((hashC & hashD) | (~hashC & hashA)) + words[3] + 0xc1bdceee;
    hashB = (hashB << 22) | (hashB >> 10);
    hashB += hashC;
    hashA += ((hashB & hashC) | (~hashB & hashD)) + words[4] + 0xf57c0faf;
    hashA = (hashA << 7) | (hashA >> 25);
    hashA += hashB;
    hashD += ((hashA & hashB) | (~hashA & hashC)) + words[5] + 0x4787c62a;
    hashD = (hashD << 12) | (hashD >> 20);
    hashD += hashA;
    hashC += ((hashD & hashA) | (~hashD & hashB)) + words[6] + 0xa8304613;
    hashC = (hashC << 17) | (hashC >> 15);
    hashC += hashD;
    hashB += ((hashC & hashD) | (~hashC & hashA)) + words[7] + 0xfd469501;
    hashB = (hashB << 22) | (hashB >> 10);
    hashB += hashC;
    hashA += ((hashB & hashC) | (~hashB & hashD)) + words[8] + 0x698098d8;
    hashA = (hashA << 7) | (hashA >> 25);
    hashA += hashB;
    hashD += ((hashA & hashB) | (~hashA & hashC)) + words[9] + 0x8b44f7af;
    hashD = (hashD << 12) | (hashD >> 20);
    hashD += hashA;
    hashC += ((hashD & hashA) | (~hashD & hashB)) + words[10] + 0xffff5bb1;
    hashC = (hashC << 17) | (hashC >> 15);
    hashC += hashD;
    hashB += ((hashC & hashD) | (~hashC & hashA)) + words[11] + 0x895cd7be;
    hashB = (hashB << 22) | (hashB >> 10);
    hashB += hashC;
    hashA += ((hashB & hashC) | (~hashB & hashD)) + words[12] + 0x6b901122;
    hashA = (hashA << 7) | (hashA >> 25);
    hashA += hashB;
    hashD += ((hashA & hashB) | (~hashA & hashC)) + words[13] + 0xfd987193;
    hashD = (hashD << 12) | (hashD >> 20);
    hashD += hashA;
    hashC += ((hashD & hashA) | (~hashD & hashB)) + words[14] + 0xa679438e;
    hashC = (hashC << 17) | (hashC >> 15);
    hashC += hashD;
    hashB += ((hashC & hashD) | (~hashC & hashA)) + words[15] + 0x49b40821;
    hashB = (hashB << 22) | (hashB >> 10);
    hashB += hashC;
    hashA += ((hashB & hashD) | (hashC & ~hashD)) + words[1] + 0xf61e2562;
    hashA = (hashA << 5) | (hashA >> 27);
    hashA += hashB;
    hashD += ((hashA & hashC) | (hashB & ~hashC)) + words[6] + 0xc040b340;
    hashD = (hashD << 9) | (hashD >> 23);
    hashD += hashA;
    hashC += ((hashD & hashB) | (hashA & ~hashB)) + words[11] + 0x265e5a51;
    hashC = (hashC << 14) | (hashC >> 18);
    hashC += hashD;
    hashB += ((hashC & hashA) | (hashD & ~hashA)) + words[0] + 0xe9b6c7aa;
    hashB = (hashB << 20) | (hashB >> 12);
    hashB += hashC;
    hashA += ((hashB & hashD) | (hashC & ~hashD)) + words[5] + 0xd62f105d;
    hashA = (hashA << 5) | (hashA >> 27);
    hashA += hashB;
    hashD += ((hashA & hashC) | (hashB & ~hashC)) + words[10] + 0x02441453;
    hashD = (hashD << 9) | (hashD >> 23);
    hashD += hashA;
    hashC += ((hashD & hashB) | (hashA & ~hashB)) + words[15] + 0xd8a1e681;
    hashC = (hashC << 14) | (hashC >> 18);
    hashC += hashD;
    hashB += ((hashC & hashA) | (hashD & ~hashA)) + words[4] + 0xe7d3fbc8;
    hashB = (hashB << 20) | (hashB >> 12);
    hashB += hashC;
    hashA += ((hashB & hashD) | (hashC & ~hashD)) + words[9] + 0x21e1cde6;
    hashA = (hashA << 5) | (hashA >> 27);
    hashA += hashB;
    hashD += ((hashA & hashC) | (hashB & ~hashC)) + words[14] + 0xc33707d6;
    hashD = (hashD << 9) | (hashD >> 23);
    hashD += hashA;
    hashC += ((hashD & hashB) | (hashA & ~hashB)) + words[3] + 0xf4d50d87;
    hashC = (hashC << 14) | (hashC >> 18);
    hashC += hashD;
    hashB += ((hashC & hashA) | (hashD & ~hashA)) + words[8] + 0x455a14ed;
    hashB = (hashB << 20) | (hashB >> 12);
    hashB += hashC;
    hashA += ((hashB & hashD) | (hashC & ~hashD)) + words[13] + 0xa9e3e905;
    hashA = (hashA << 5) | (hashA >> 27);
    hashA += hashB;
    hashD += ((hashA & hashC) | (hashB & ~hashC)) + words[2] + 0xfcefa3f8;
    hashD = (hashD << 9) | (hashD >> 23);
    hashD += hashA;
    hashC += ((hashD & hashB) | (hashA & ~hashB)) + words[7] + 0x676f02d9;
    hashC = (hashC << 14) | (hashC >> 18);
    hashC += hashD;
    hashB += ((hashC & hashA) | (hashD & ~hashA)) + words[12] + 0x8d2a4c8a;
    hashB = (hashB << 20) | (hashB >> 12);
    hashB += hashC;
    hashA += (hashB ^ hashC ^ hashD) + words[5] + 0xfffa3942;
    hashA = (hashA << 4) | (hashA >> 28);
    hashA += hashB;
    hashD += (hashA ^ hashB ^ hashC) + words[8] + 0x8771f681;
    hashD = (hashD << 11) | (hashD >> 21);
    hashD += hashA;
    hashC += (hashD ^ hashA ^ hashB) + words[11] + 0x6d9d6122;
    hashC = (hashC << 16) | (hashC >> 16);
    hashC += hashD;
    hashB += (hashC ^ hashD ^ hashA) + words[14] + 0xfde5380c;
    hashB = (hashB << 23) | (hashB >> 9);
    hashB += hashC;
    hashA += (hashB ^ hashC ^ hashD) + words[1] + 0xa4beea44;
    hashA = (hashA << 4) | (hashA >> 28);
    hashA += hashB;
    hashD += (hashA ^ hashB ^ hashC) + words[4] + 0x4bdecfa9;
    hashD = (hashD << 11) | (hashD >> 21);
    hashD += hashA;
    hashC += (hashD ^ hashA ^ hashB) + words[7] + 0xf6bb4b60;
    hashC = (hashC << 16) | (hashC >> 16);
    hashC += hashD;
    hashB += (hashC ^ hashD ^ hashA) + words[10] + 0xbebfbc70;
    hashB = (hashB << 23) | (hashB >> 9);
    hashB += hashC;
    hashA += (hashB ^ hashC ^ hashD) + words[13] + 0x289b7ec6;
    hashA = (hashA << 4) | (hashA >> 28);
    hashA += hashB;
    hashD += (hashA ^ hashB ^ hashC) + words[0] + 0xeaa127fa;
    hashD = (hashD << 11) | (hashD >> 21);
    hashD += hashA;
    hashC += (hashD ^ hashA ^ hashB) + words[3] + 0xd4ef3085;
    hashC = (hashC << 16) | (hashC >> 16);
    hashC += hashD;
    hashB += (hashC ^ hashD ^ hashA) + words[6] + 0x04881d05;
    hashB = (hashB << 23) | (hashB >> 9);
    hashB += hashC;
    hashA += (hashB ^ hashC ^ hashD) + words[9] + 0xd9d4d039;
    hashA = (hashA << 4) | (hashA >> 28);
    hashA += hashB;
    hashD += (hashA ^ hashB ^ hashC) + words[12] + 0xe6db99e5;
    hashD = (hashD << 11) | (hashD >> 21);
    hashD += hashA;
    hashC += (hashD ^ hashA ^ hashB) + words[15] + 0x1fa27cf8;
    hashC = (hashC << 16) | (hashC >> 16);
    hashC += hashD;
    hashB += (hashC ^ hashD ^ hashA) + words[2] + 0xc4ac5665;
    hashB = (hashB << 23) | (hashB >> 9);
    hashB += hashC;
    hashA += (hashC ^ (hashB | ~hashD)) + words[0] + 0xf4292244;
    hashA = (hashA << 6) | (hashA >> 26);
    hashA += hashB;
    hashD += (hashB ^ (hashA | ~hashC)) + words[7] + 0x432aff97;
    hashD = (hashD << 10) | (hashD >> 22);
    hashD += hashA;
    hashC += (hashA ^ (hashD | ~hashB)) + words[14] + 0xab9423a7;
    hashC = (hashC << 15) | (hashC >> 17);
    hashC += hashD;
    hashB += (hashD ^ (hashC | ~hashA)) + words[5] + 0xfc93a039;
    hashB = (hashB << 21) | (hashB >> 11);
    hashB += hashC;
    hashA += (hashC ^ (hashB | ~hashD)) + words[12] + 0x655b59c3;
    hashA = (hashA << 6) | (hashA >> 26);
    hashA += hashB;
    hashD += (hashB ^ (hashA | ~hashC)) + words[3] + 0x8f0ccc92;
    hashD = (hashD << 10) | (hashD >> 22);
    hashD += hashA;
    hashC += (hashA ^ (hashD | ~hashB)) + words[10] + 0xffeff47d;
    hashC = (hashC << 15) | (hashC >> 17);
    hashC += hashD;
    hashB += (hashD ^ (hashC | ~hashA)) + words[1] + 0x85845dd1;
    hashB = (hashB << 21) | (hashB >> 11);
    hashB += hashC;
    hashA += (hashC ^ (hashB | ~hashD)) + words[8] + 0x6fa87e4f;
    hashA = (hashA << 6) | (hashA >> 26);
    hashA += hashB;
    hashD += (hashB ^ (hashA | ~hashC)) + words[15] + 0xfe2ce6e0;
    hashD = (hashD << 10) | (hashD >> 22);
    hashD += hashA;
    hashC += (hashA ^ (hashD | ~hashB)) + words[6] + 0xa3014314;
    hashC = (hashC << 15) | (hashC >> 17);
    hashC += hashD;
    hashB += (hashD ^ (hashC | ~hashA)) + words[13] + 0x4e0811a1;
    hashB = (hashB << 21) | (hashB >> 11);
    hashB += hashC;
    hashA += (hashC ^ (hashB | ~hashD)) + words[4] + 0xf7537e82;
    hashA = (hashA << 6) | (hashA >> 26);
    hashA += hashB;
    hashD += (hashB ^ (hashA | ~hashC)) + words[11] + 0xbd3af235;
    hashD = (hashD << 10) | (hashD >> 22);
    hashD += hashA;
    hashC += (hashA ^ (hashD | ~hashB)) + words[2] + 0x2ad7d2bb;
    hashC = (hashC << 15) | (hashC >> 17);
    hashC += hashD;
    hashB += (hashD ^ (hashC | ~hashA)) + words[9] + 0xeb86d391;
    hashB = (hashB << 21) | (hashB >> 11);
    hashB += hashC;
    context->mHashWords[0] += hashA;
    context->mHashWords[1] += hashB;
    context->mHashWords[2] += hashC;
    context->mHashWords[3] += hashD;
    FillBytesWithLoop(words, 0, sizeof(words));
}

void CopyWordsToBytesLittleEndian(u8 *output, const u32 *input, u32 size) {
    u32 byteIndex;
    for (byteIndex = 0; byteIndex < size; byteIndex += 4) {
        output[byteIndex] = *input;
        output[byteIndex + 1] = *input >> 8;
        output[byteIndex + 2] = *input >> 16;
        output[byteIndex + 3] = *input >> 24;
        input++;
    }
}

void CopyBytesToWordsLittleEndian(u32 *output, const u8 *input, u32 size) {
    u32 byteIndex;
    for (byteIndex = 0; byteIndex < size; byteIndex += 4) {
        *output++ = (input[byteIndex + 3] << 24) |
                    ((input[byteIndex + 2] << 16) | (input[byteIndex] | (input[byteIndex + 1] << 8)));
    }
}

void CopyBytesWithLoop(void *destination, const void *source, u32 count) {
    u8 *destinationBytes = destination;
    const u8 *sourceBytes = source;
    u32 byteIndex;
    for (byteIndex = 0; byteIndex < count; byteIndex++) {
        destinationBytes[byteIndex] = sourceBytes[byteIndex];
    }
}

void FillBytesWithLoop(void *buffer, s32 value, u32 count) {
    s8 *cursor = buffer;
    u32 byteIndex = 0;
    for (byteIndex = 0; byteIndex < count; byteIndex++) {
        *cursor++ = value;
    }
}

void ComputeHash(u8 *digest, const u8 *input, u32 size) {
    HashContext context;
    ResetHashContext(&context);
    AddBytesToHash(&context, input, size);
    FinishHash(digest, &context);
}

u32 GetTickMilliseconds(void) {
    return _ll_udiv(OS_GetTick() << 6, 0x82ea);
}

void *CallAllocFunctionAndClear(s32 count, s32 size) {
    s32 total = count * size;
    void *block = (void *) gAllocFunction(total);
    if (block != NULL) {
        memset(block, 0, total);
    }
    return block;
}

void CallFreeFunction(void *block) {
    u32 functionSlot = ((u32) (&gFreeFunction));
    u32 freeFunction = (*(u32 *) ((functionSlot) + (0)));
    u32 result = ((u32(*)(void *))(freeFunction))(block);
}

s32 FormatByteAsHex(u8 *output, s8 value) {
    u8 *cursor = output;
    u8 byte = value;
    s32 digitIndex;
    s32 digit;
    s32 lowDigit;
    digit = (byte & 0xf0) >> 4;
    digitIndex = 0;
    lowDigit = byte & 0xf;
    for (; digitIndex < 2; digitIndex++) {
        if (digit <= 9) {
            *cursor++ = digit + 0x30;
        } else {
            *cursor++ = digit + 0x37;
        }
        digit = lowDigit;
    }
    *cursor = 0;
    return cursor - output;
}

s32 FormatMacAddress(u8 *output, const s8 *address) {
    u8 *cursor = output;
    s32 byteIndex;
    for (byteIndex = 0; byteIndex < 6; byteIndex++) {
        cursor += FormatByteAsHex(cursor, *address++);
        if (byteIndex < 5) {
            *cursor++ = ':';
        }
    }
    *cursor = 0;
    return cursor - output;
}

// Starts the thread that runs RunExchange; returns 1, or -10 while a run is under way.
s32 StartExchange(u32 priority, s32 entryCount, ExchangeStatusCallback callback, ExchangeAllocFunc allocFunction,
                  ExchangeFreeFunc freeFunction, u32 stackSize) {
    s32 result;
    if (gExchangeStatus >= EXCHANGE_STATUS_STARTED && gExchangeStatus <= EXCHANGE_STATUS_SECOND_KEY_RECEIVED) {
        return -10;
    }
    gStartEntryCount = entryCount;
    gExchangeStatus = EXCHANGE_STATUS_ENDED_WITHOUT_RESULT;
    gStatusCallback = callback;
    gAllocFunction = allocFunction;
    gFreeFunction = freeFunction;
    gThreadStackSize = stackSize;
    result = InitExchangeWiFi(entryCount);
    gExchangeWiFiInitCalled = 1;
    if (result < 0) {
        gExchangeResultCode = result;
        return result;
    }
    gThreadStack = (void *) gAllocFunction(gThreadStackSize);
    if (gThreadStack == NULL) {
        gExchangeResultCode = -1;
        return -1;
    }
    if (OS_IsThreadAvailable() != 1) {
        gExchangeResultCode = -9;
        return -9;
    }
    OS_CreateThread(&gExchangeThread, (void (*)(void *)) RunExchangeThread, NULL,
                    (u8 *) gThreadStack + (gThreadStackSize & ~7), gThreadStackSize, priority);
    gExchangeStatus = EXCHANGE_STATUS_STARTED;
    gTimeoutAtMs = GetTickMilliseconds() + 60000;
    gStopRequested = 0;
    __clear(&gExchangeResult, 0xe8);
    CallStatusCallback();
    OS_WakeupThreadDirect(&gExchangeThread);
    gThreadStarted = 1;
    return 1;
}
