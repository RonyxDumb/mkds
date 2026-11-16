#include "fixed_arctangent.h"
#include "fixed_vector_math.h"
#include "Main/Graphics/animation_function_pointers.h"

const s16 FX_AtanTable_[129] = {
    0,    32,   64,   96,   128,  160,  192,  224,  256,  288,  319,  351,  383,  415,  446,  478,  509,
    541,  572,  604,  635,  666,  697,  728,  759,  790,  821,  852,  882,  913,  943,  973,  1003, 1033,
    1063, 1093, 1123, 1153, 1182, 1211, 1241, 1270, 1299, 1327, 1356, 1385, 1413, 1441, 1470, 1498, 1525,
    1553, 1581, 1608, 1635, 1662, 1689, 1716, 1743, 1769, 1795, 1822, 1848, 1873, 1899, 1925, 1950, 1975,
    2000, 2025, 2050, 2074, 2099, 2123, 2147, 2171, 2195, 2218, 2242, 2265, 2288, 2311, 2334, 2356, 2379,
    2401, 2423, 2445, 2467, 2489, 2510, 2531, 2553, 2574, 2595, 2615, 2636, 2656, 2676, 2697, 2716, 2736,
    2756, 2775, 2795, 2814, 2833, 2852, 2871, 2889, 2908, 2926, 2944, 2962, 2980, 2998, 3016, 3033, 3051,
    3068, 3085, 3102, 3119, 3135, 3152, 3168, 3185, 3201, 3217,
};

const s16 g_Fx_AtanTable[129] = {
    0,    81,   163,  244,  326,  407,  489,  570,  651,  732,  813,  894,  975,  1056, 1136, 1217, 1297,
    1377, 1457, 1537, 1617, 1696, 1775, 1854, 1933, 2012, 2090, 2168, 2246, 2324, 2401, 2478, 2555, 2632,
    2708, 2784, 2860, 2935, 3010, 3085, 3159, 3233, 3307, 3380, 3453, 3526, 3599, 3670, 3742, 3813, 3884,
    3955, 4025, 4095, 4164, 4233, 4302, 4370, 4438, 4505, 4572, 4639, 4705, 4771, 4836, 4901, 4966, 5030,
    5094, 5157, 5220, 5282, 5344, 5406, 5467, 5528, 5589, 5649, 5708, 5768, 5826, 5885, 5943, 6000, 6058,
    6114, 6171, 6227, 6282, 6337, 6392, 6446, 6500, 6554, 6607, 6660, 6712, 6764, 6815, 6867, 6917, 6968,
    7018, 7068, 7117, 7166, 7214, 7262, 7310, 7358, 7405, 7451, 7498, 7544, 7589, 7635, 7679, 7724, 7768,
    7812, 7856, 7899, 7942, 7984, 8026, 8068, 8110, 8151, 8192,
};

// Angle of the point (x, y) as a 16-bit angle index, using the arctangent table. Returns 0 when both are 0.
u16 FX_Atan2(s32 y, s32 x) {
    s32 small;
    s32 large;
    s32 base;
    s32 add;

    if (y > 0) {
        if (x > 0) {
            if (x > y) {
                small = y;
                large = x;
                base = 0;
                add = 1;
            } else if (x < y) {
                small = x;
                large = y;
                base = 0x4000;
                add = 0;
            } else {
                return 0x2000;
            }
        } else if (x < 0) {
            x = -x;
            if (x < y) {
                small = x;
                large = y;
                base = 0x4000;
                add = 1;
            } else if (x > y) {
                small = y;
                large = x;
                base = 0x8000;
                add = 0;
            } else {
                return 0x6000;
            }
        } else {
            return 0x4000;
        }
    } else if (y < 0) {
        y = -y;
        if (x < 0) {
            x = -x;
            if (x > y) {
                small = y;
                large = x;
                base = -0x8000;
                add = 1;
            } else if (x < y) {
                small = x;
                large = y;
                base = -0x4000;
                add = 0;
            } else {
                return 0xa000;
            }
        } else if (x > 0) {
            if (x < y) {
                small = x;
                large = y;
                base = -0x4000;
                add = 1;
            } else if (x > y) {
                base = 0;
                small = y;
                large = x;
                add = base;
            } else {
                return 0xe000;
            }
        } else {
            return 0xc000;
        }
    } else {
        if (x >= 0) {
            return 0;
        }
        return 0x8000;
    }
    if (large == 0) {
        return 0;
    }
    if (add != 0) {
        return base + g_Fx_AtanTable[FX_Div(small, large) >> 5];
    }
    return base - g_Fx_AtanTable[FX_Div(small, large) >> 5];
}

// Angle of the point (x, y) in radians with 12 fractional bits, using the arctangent table. Returns 0 when both are 0.
s16 FX_Atan2(s32 y, s32 x) {
    s32 small;
    s32 large;
    s32 base;
    s32 add;

    if (y > 0) {
        if (x > 0) {
            if (x > y) {
                small = y;
                large = x;
                base = 0;
                add = 1;
            } else if (x < y) {
                small = x;
                large = y;
                base = 0x1922;
                add = 0;
            } else {
                return 0xc91;
            }
        } else if (x < 0) {
            x = -x;
            if (x < y) {
                small = x;
                large = y;
                base = 0x1922;
                add = 1;
            } else if (x > y) {
                small = y;
                large = x;
                base = 0x3244;
                add = 0;
            } else {
                return 0x25b3;
            }
        } else {
            return 0x1922;
        }
    } else if (y < 0) {
        y = -y;
        if (x < 0) {
            x = -x;
            if (x > y) {
                small = y;
                large = x;
                base = -0x3244;
                add = 1;
            } else if (x < y) {
                small = x;
                large = y;
                base = -0x1922;
                add = 0;
            } else {
                return -0x25b3;
            }
        } else if (x > 0) {
            if (x < y) {
                small = x;
                large = y;
                base = -0x1922;
                add = 1;
            } else if (x > y) {
                base = 0;
                small = y;
                large = x;
                add = base;
            } else {
                return -0xc91;
            }
        } else {
            return -0x1922;
        }
    } else {
        if (x >= 0) {
            return 0;
        }
        return 0x3244;
    }
    if (large == 0) {
        return 0;
    }
    if (add != 0) {
        return base + FX_AtanTable_[FX_Div(small, large) >> 5];
    }
    return base - FX_AtanTable_[FX_Div(small, large) >> 5];
}
