#include "01/code_02187684.h"
#include "01/code_021a1bb8.h"
#include "Main/Unknown/code_02061808.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d3000.h"

// Writes to param_3 a point for entry param_2 of param_1->mUnk_0bc: param_1->mUnk_004 plus the entry's mUnk_08
// combined with the pair of data_0215d4b4 values selected by param_1->mUnk_184. The entry's mUnk_00 (1-5) selects
// the variant; other values write nothing.
void func_ov001_02187684(Unk02188950 *param_1, int param_2, Vec3 *param_3) {
    Unk02061808 *obj;
    s32 x;
    s32 y;
    s32 z;
    s32 t;

    switch (param_1->mUnk_0bc[param_2].mUnk_00) {
        case 1:
            param_3->x = param_1->mUnk_004.x +
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.z *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2]) >>
                                12) +
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.x *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2 + 1]) >>
                                12);
            param_3->y = param_1->mUnk_004.y + param_1->mUnk_0bc[param_2].mUnk_08.y;
            param_3->z = param_1->mUnk_004.z +
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.z *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2 + 1]) >>
                                12) -
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.x *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2]) >>
                                12);
            break;
        case 3:
            // As case 1 with mUnk_024 of the object from func_02061808 added, then halved.
            obj = func_02061808();
            param_3->x = param_1->mUnk_004.x + obj->mUnk_024.x +
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.z *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2]) >>
                                12) +
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.x *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2 + 1]) >>
                                12);
            param_3->y = param_1->mUnk_004.y + obj->mUnk_024.y + param_1->mUnk_0bc[param_2].mUnk_08.y;
            param_3->z = param_1->mUnk_004.z + obj->mUnk_024.z +
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.z *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2 + 1]) >>
                                12) -
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.x *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2]) >>
                                12);
            param_3->x >>= 1;
            param_3->y >>= 1;
            param_3->z >>= 1;
            break;
        case 2:
            // The entry's mUnk_08 is first multiplied per component by param_1->mUnk_01c, mUnk_020 and mUnk_024.
            t = param_1->mUnk_0bc[param_2].mUnk_08.y;
            y = (s32) (((s64) t * param_1->mUnk_020) >> 12);
            t = param_1->mUnk_0bc[param_2].mUnk_08.x;
            x = (s32) (((s64) t * param_1->mUnk_01c) >> 12);
            t = param_1->mUnk_0bc[param_2].mUnk_08.z;
            z = (s32) (((s64) t * param_1->mUnk_024) >> 12);
            param_3->x = param_1->mUnk_004.x +
                         (s32) (((s64) z * data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2]) >> 12) +
                         (s32) (((s64) x * data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2 + 1]) >> 12);
            param_3->y = param_1->mUnk_004.y + y;
            param_3->z = param_1->mUnk_004.z +
                         (s32) (((s64) z * data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2 + 1]) >> 12) -
                         (s32) (((s64) x * data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2]) >> 12);
            break;
        case 4:
            param_3->x = param_1->mUnk_004.x +
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.z *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2]) >>
                                12) +
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.x *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2 + 1]) >>
                                12);
            param_3->y = param_1->mUnk_09c->mUnk_00.y + param_1->mUnk_0bc[param_2].mUnk_08.y;
            param_3->z = param_1->mUnk_004.z +
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.z *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2 + 1]) >>
                                12) -
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.x *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2]) >>
                                12);
            break;
        case 5:
            param_3->x = param_1->mUnk_004.x +
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.z *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2]) >>
                                12) +
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.x *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2 + 1]) >>
                                12);
            param_3->y = param_1->mUnk_0bc[param_2].mUnk_08.y - func_020d3d48(0);
            param_3->z = param_1->mUnk_004.z +
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.z *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2 + 1]) >>
                                12) -
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.x *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2]) >>
                                12);
            break;
    }
}
