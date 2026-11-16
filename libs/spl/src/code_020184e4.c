#include "code_020184e4.h"

#include "code_02146d78.h"
#include "code_02147288.h"
#include "code_02147cd8.h"
#include "g3imm.h"
#include "gx_load3d.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02173000.h"
#include "code_0214d018.h"
#include "registers.h"
#include "code_0201c4e8.h"
#include "code_0201c528.h"
#include "code_02146cbc.h"
#include "Main/Unknown/code_02146000.h"
#include "code_021471bc.h"

void SPLRandom_VecFx32(Vec3 *vec) {
    vec->x = (s32) (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 8;
    vec->y = (s32) (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 8;
    vec->z = (s32) (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 8;
    VEC_Normalize(vec, vec);
}

void SPLRandom_VecFx32_XY(Vec3 *vec) {
    vec->x = (s32) (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 8;
    vec->y = (s32) (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 8;
    vec->z = 0;
    VEC_Normalize(vec, vec);
}

void SPLList_PushFront(Unk0201e494 *list, Unk0201e3c8 *node) {
    if (list->field0 == 0) {
        list->field0 = node;
        list->field8 = node;
        node->field0 = 0;
        node->field4 = node->field0;
    } else {
        node->field0 = list->field0;
        node->field4 = 0;
        list->field0->field4 = node;
        list->field0 = node;
    }
    list->field4++;
}

Unk0201e3c8 *SPLList_PopFront(Unk0201e494 *list) {
    Unk0201e3c8 *first;
    Unk0201e3c8 *node;

    node = 0;
    first = list->field0;
    if (first != 0) {
        node = first;
        list->field0 = first->field0;
        if (list->field0 != 0) {
            first->field0->field4 = 0;
        } else {
            list->field0 = 0;
            list->field8 = 0;
        }
        list->field4--;
    }
    return node;
}

Unk0201e3c8 *SPLList_Erase(Unk0201e494 *list, Unk0201e3c8 *node) {
    Unk0201e3c8 *next;

    next = node->field0;
    if (next == 0) {
        if (list->field0 == node) {
            list->field0 = 0;
            list->field8 = 0;
        } else {
            node->field4->field0 = 0;
            list->field8 = list->field8->field4;
        }
    } else {
        if (list->field0 == node) {
            list->field0 = next;
            list->field0->field4 = 0;
        } else {
            next->field4 = node->field4;
            node->field4->field0 = node->field0;
        }
    }
    list->field4--;
    return node;
}

void SPLBehavior_ApplyGravity(const Vec3s16 *gravity, Unk0201e3c8 *ptcl, Vec3 *acc, Unk0201ca6c *emtr) {
    acc->x = acc->x + gravity->x;
    acc->y = acc->y + gravity->y;
    acc->z = acc->z + gravity->z;
}

void SPLBehavior_ApplyRandom(const Unk0201e2cc *rng, Unk0201e3c8 *ptcl, Vec3 *acc, Unk0201ca6c *emtr) {
    if (ptcl->field26 % rng->field6 != 0) {
        return;
    }
    acc->x = acc->x + ((rng->field0 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) -
                        (rng->field0 << 8)) >>
                       8);
    acc->y = acc->y + ((rng->field2 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) -
                        (rng->field2 << 8)) >>
                       8);
    acc->z = acc->z + ((rng->field4 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) -
                        (rng->field4 << 8)) >>
                       8);
}

void SPLBehavior_ApplyMagnet(const Unk0201e248 *magnet, Unk0201e3c8 *ptcl, Vec3 *acc, Unk0201ca6c *emtr) {
    acc->x = acc->x + ((magnet->fieldC * (magnet->field0.x - ptcl->field8.x - ptcl->field14.x)) >> 12);
    acc->y = acc->y + ((magnet->fieldC * (magnet->field0.y - ptcl->field8.y - ptcl->field14.y)) >> 12);
    acc->z = acc->z + ((magnet->fieldC * (magnet->field0.z - ptcl->field8.z - ptcl->field14.z)) >> 12);
}

void SPLBehavior_ApplySpin(const Unk0201e170 *spin, Unk0201e3c8 *ptcl, Vec3 *acc, Unk0201ca6c *emtr) {
    s32 buf[9];

    switch (spin->field2) {
        case 0:
            MTX_RotX33_(buf, gPairsByAngle[(spin->field0 >> 4) * 2], gPairsByAngle[(spin->field0 >> 4) * 2 + 1]);
            break;
        case 1:
            MTX_RotY33_(buf, gPairsByAngle[(spin->field0 >> 4) * 2], gPairsByAngle[(spin->field0 >> 4) * 2 + 1]);
            break;
        case 2:
            MTX_RotZ33_(buf, gPairsByAngle[(spin->field0 >> 4) * 2], gPairsByAngle[(spin->field0 >> 4) * 2 + 1]);
            break;
    }
    MTX_MultVec33(&ptcl->field8, buf, &ptcl->field8);
}

void SPLBehavior_ApplyCollisionPlane(const Unk0201e054 *plane, Unk0201e3c8 *ptcl, Vec3 *acc, Unk0201ca6c *emtr) {
    s32 lim;
    s32 y;

    lim = plane->field0;
    if (emtr->field74 != 0x80000000) {
        lim = emtr->field74;
    }
    switch (plane->field6_0) {
        case 0:
            y = ptcl->field38.y;
            if (y < lim) {
                if (y + ptcl->field8.y > lim) {
                    ptcl->field8.y = lim - y;
                    ptcl->field26 = ptcl->field24;
                    return;
                }
            }
            if (y >= lim) {
                if (y + ptcl->field8.y < lim) {
                    ptcl->field8.y = lim - y;
                    ptcl->field26 = ptcl->field24;
                }
            }
            break;
        case 1:
            y = ptcl->field38.y;
            if (y < lim && y + ptcl->field8.y > lim) {
                ptcl->field8.y = lim - y;
                ptcl->field14.y = -(s32) (((s64) ptcl->field14.y * plane->field4 + 0x800) >> 12);
            } else if (y >= lim && y + ptcl->field8.y < lim) {
                ptcl->field8.y = lim - y;
                ptcl->field14.y = -(s32) (((s64) ptcl->field14.y * plane->field4 + 0x800) >> 12);
            }
            break;
    }
}

void SPLBehavior_ApplyConvergence(const Unk0201e248 *conv, Unk0201e3c8 *ptcl, Vec3 *acc, Unk0201ca6c *emtr) {
    ptcl->field8.x =
        ptcl->field8.x + (s32) (((s64) conv->fieldC * (conv->field0.x - ptcl->field8.x) + 0x800) >> 12);
    ptcl->field8.y =
        ptcl->field8.y + (s32) (((s64) conv->fieldC * (conv->field0.y - ptcl->field8.y) + 0x800) >> 12);
    ptcl->field8.z =
        ptcl->field8.z + (s32) (((s64) conv->fieldC * (conv->field0.z - ptcl->field8.z) + 0x800) >> 12);
}

void SPLAnim_Scale(Unk0201e3c8 *ptcl, Unk0201ca6c_20 *res, s32 lifeRate) {
    Unk0201ca6c_20_04 *scaleAnim;
    s32 a;
    s32 lo;
    s32 hi;

    scaleAnim = res->field4;
    lo = scaleAnim->field6;
    hi = scaleAnim->field7;
    if (lifeRate < lo) {
        a = scaleAnim->field0;
        ptcl->field34 = a + (lifeRate * (scaleAnim->field2 - a)) / lo;
        return;
    }
    if (lifeRate < hi) {
        ptcl->field34 = scaleAnim->field2;
        return;
    }
    a = scaleAnim->field4;
    ptcl->field34 = a + ((lifeRate - 0xff) * (a - scaleAnim->field2)) / (0xff - hi);
}

void SPLAnim_Color(Unk0201e3c8 *ptcl, Unk0201ca6c_20 *res, s32 lifeRate) {
    Unk0201ca6c_20_08 *colorAnim;
    Unk0201ca6c_20_00 *header;
    s32 lo;
    s32 mid;
    s32 hi;
    s32 br;
    s32 ar;
    s32 bg;
    s32 ag;
    s32 ab;
    s32 bb;
    s32 n;
    s32 m;

    colorAnim = res->field8;
    header = res->field0;
    lo = colorAnim->field4;
    mid = colorAnim->field5;
    hi = colorAnim->field6;
    if (lifeRate < lo) {
        ptcl->field36 = colorAnim->field0;
        return;
    }
    if (lifeRate < mid) {
        ar = colorAnim->field0 & 0x1f;
        ag = (colorAnim->field0 >> 5) & 0x1f;
        ab = (colorAnim->field0 >> 10) & 0x1f;
        br = header->field22 & 0x1f;
        bg = (header->field22 >> 5) & 0x1f;
        bb = (header->field22 >> 10) & 0x1f;
        if (colorAnim->field8_2 == 0) {
            ptcl->field36 = br | (bg << 5) | (bb << 10);
            return;
        }
        n = lifeRate - lo;
        m = mid - lo;
        ptcl->field36 =
            (ar + (n * (br - ar)) / m) | ((ag + (n * (bg - ag)) / m) << 5) | ((ab + (n * (bb - ab)) / m) << 10);
        return;
    }
    if (lifeRate < hi) {
        s32 cb; // PERM
        s32 er; // PERM
        s32 cr; // PERM
        s32 eg; // PERM
        s32 cg; // PERM
        s32 eb; // PERM
        er = header->field22 & 0x1f;
        eg = (header->field22 >> 5) & 0x1f;
        eb = (header->field22 >> 10) & 0x1f;
        cr = colorAnim->field2 & 0x1f;
        cg = (colorAnim->field2 >> 5) & 0x1f;
        cb = (colorAnim->field2 >> 10) & 0x1f;
        if (colorAnim->field8_2 == 0) {
            ptcl->field36 = cr | (cg << 5) | (cb << 10);
            return;
        }
        n = lifeRate - mid;
        m = hi - mid;
        ptcl->field36 =
            (er + (n * (cr - er)) / m) | ((eg + (n * (cg - eg)) / m) << 5) | ((eb + (n * (cb - eb)) / m) << 10);
        return;
    }
    ptcl->field36 = colorAnim->field2;
}

void SPLAnim_Alpha(Unk0201e3c8 *ptcl, Unk0201ca6c_20 *res, s32 lifeRate) {
    Unk0201ca6c_20_0c *alphaAnim;
    s32 a;
    s32 lo;
    s32 hi;

    alphaAnim = res->fieldC;
    lo = alphaAnim->field4;
    hi = alphaAnim->field5;
    if (lifeRate < lo) {
        a = alphaAnim->field0_0 + (lifeRate * (alphaAnim->field0_5 - alphaAnim->field0_0)) / lo;
    } else if (lifeRate < hi) {
        a = alphaAnim->field0_5;
    } else {
        a = alphaAnim->field0_10 + ((lifeRate - 0xff) * (alphaAnim->field0_10 - alphaAnim->field0_5)) / (0xff - hi);
    }
    ptcl->field2E_5 =
        (a *
         (0xff -
          ((alphaAnim->field2_0 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 24)) >> 8))) >>
        8;
}

void SPLAnim_Texture(Unk0201e3c8 *ptcl, Unk0201ca6c_20 *res, s32 lifeRate) {
    Unk0201ca6c_20_10 *texAnim;
    s32 i;
    s32 s;
    s32 w;
    s32 n;

    texAnim = res->field10;
    i = 0;
    n = texAnim->field8_0;
    if (n <= 0) {
        return;
    }
    w = texAnim->field8_8;
    s = 0;
    do {
        if (lifeRate < s + w) {
            ptcl->field2C = texAnim->field0[i];
            return;
        }
        s += texAnim->field8_8;
        i++;
    } while (i < n);
}

void SPLAnim_ChildScale(Unk0201e3c8 *ptcl, Unk0201ca6c_20 *res, s32 lifeRate) {
    s32 a;

    a = res->field14->field4;
    ptcl->field34 = a + ((a - 0x1000) * (lifeRate - 0xff)) / 0xff;
}

void SPLAnim_ChildAlpha(Unk0201e3c8 *ptcl, Unk0201ca6c_20 *res, s32 lifeRate) {
    ptcl->field2E_5 = ((0xff - lifeRate) * 0x1f) / 0xff;
}

void SPLEmitter_ComputeOrthogonalAxes(Unk0201ca6c *emtr) {
    Vec3s16 up;
    Vec3s16 axis;
    s32 dot;

    up = data_02161ad0;
    switch (emtr->field20->field0->field0.field0_6) {
        case 2:
            axis.x = 0x1000;
            axis.y = 0;
            axis.z = 0;
            break;
        case 1:
            axis.x = 0;
            axis.y = 0x1000;
            axis.z = 0;
            break;
        case 0:
            axis.x = 0;
            axis.y = 0;
            axis.z = 0x1000;
            break;
        default:
            VEC_Fx16Normalize(&emtr->field50, &axis);
            break;
    }
    dot = VEC_Fx16DotProduct(&up, &axis);
    if (dot == 0x1000 || dot == -0x1000) {
        up.x = 0x1000;
        up.y = 0;
        up.z = 0;
    }
    emtr->field84.x = (s32) (((s64) axis.y * up.z + 0x800) >> 12) - (s32) (((s64) axis.z * up.y + 0x800) >> 12);
    emtr->field84.y = (s32) (((s64) axis.z * up.x + 0x800) >> 12) - (s32) (((s64) axis.x * up.z + 0x800) >> 12);
    emtr->field84.z = (s32) (((s64) axis.x * up.y + 0x800) >> 12) - (s32) (((s64) axis.y * up.x + 0x800) >> 12);
    emtr->field8A.x =
        (s32) (((s64) axis.y * emtr->field84.z + 0x800) >> 12) - (s32) (((s64) axis.z * emtr->field84.y + 0x800) >> 12);
    emtr->field8A.y =
        (s32) (((s64) axis.z * emtr->field84.x + 0x800) >> 12) - (s32) (((s64) axis.x * emtr->field84.z + 0x800) >> 12);
    emtr->field8A.z =
        (s32) (((s64) axis.x * emtr->field84.y + 0x800) >> 12) - (s32) (((s64) axis.y * emtr->field84.x + 0x800) >> 12);
    VEC_Fx16Normalize(&emtr->field84, &emtr->field84);
    VEC_Fx16Normalize(&emtr->field8A, &emtr->field8A);
}

void SPLUtil_TiltCoordinates(Vec3 *ptclPos, const Vec3 *pos, Unk0201ca6c *emtr) {
    Vec3s16 cross;

    VEC_Fx16CrossProduct(&emtr->field84, &emtr->field8A, &cross);
    VEC_Fx16Normalize(&cross, &cross);
    ptclPos->x =
        (s32) (((s64) pos->z * cross.x + 0x800) >> 12) + ((s32) (((s64) pos->x * emtr->field84.x + 0x800) >> 12) +
                                                          (s32) (((s64) pos->y * emtr->field8A.x + 0x800) >> 12));
    ptclPos->y =
        (s32) (((s64) pos->z * cross.y + 0x800) >> 12) + ((s32) (((s64) pos->x * emtr->field84.y + 0x800) >> 12) +
                                                          (s32) (((s64) pos->y * emtr->field8A.y + 0x800) >> 12));
    ptclPos->z =
        (s32) (((s64) pos->z * cross.z + 0x800) >> 12) + ((s32) (((s64) pos->x * emtr->field84.z + 0x800) >> 12) +
                                                          (s32) (((s64) pos->y * emtr->field8A.z + 0x800) >> 12));
}

void SPLEmitter_EmitParticles(Unk0201ca6c *emtr, Unk0201e494 *list) {
    Unk0201ca6c_20 *c;
    Unk0201ca6c_20_00 *d;
    Unk0201e3c8 *n0;
    s32 i;
    s32 n;
    s32 t;
    s32 s1;
    s32 s2;
    s32 acc;
    Vec3 v2;
    Vec3 v3;
    Vec3 v5;
    Vec3s16 a8;
    Vec3 v8;
    Vec3s16 a9;
    Vec3 v9;
    Vec3 v6;
    Vec3 v7;
    u16 ch[3];
    Vec3 u;
    Vec3 w;

    c = emtr->field20;
    t = emtr->field58 + emtr->field4E;
    d = c->field0;
    emtr->field4E = t & 0xfff;
    n = t >> 12;
    if (d->field0.field0_0 == 2 || d->field0.field0_0 == 3 || d->field0.field0_0 == 5 ||
        d->field0.field0_0 == 6 || d->field0.field0_0 == 7 || d->field0.field0_0 == 8 ||
        d->field0.field0_0 == 9) {
        SPLEmitter_ComputeOrthogonalAxes(emtr);
    }
    i = 0;
    if (i < n) {
        acc = 0;
        do {
            n0 = SPLList_PopFront(list);
            if (n0 == 0) {
                return;
            }
            SPLList_PushFront(&emtr->field8, n0);
            switch (d->field0.field0_0) {
                case 0:
                    n0->field8.x = n0->field8.y = n0->field8.z = 0;
                    break;
                case 1:
                    SPLRandom_VecFx32(&n0->field8);
                    n0->field8.x = ((s64) n0->field8.x * emtr->field5C + 0x800) >> 12;
                    n0->field8.y = ((s64) n0->field8.y * emtr->field5C + 0x800) >> 12;
                    n0->field8.z = ((s64) n0->field8.z * emtr->field5C + 0x800) >> 12;
                    break;
                case 2: {
                    SPLRandom_VecFx32_XY(&v2);
                    v2.x = ((s64) v2.x * emtr->field5C + 0x800) >> 12;
                    v2.y = ((s64) v2.y * emtr->field5C + 0x800) >> 12;
                    v2.z = 0;
                    SPLUtil_TiltCoordinates(&n0->field8, &v2, emtr);
                    break;
                }
                case 3: {
                    s32 k;
                    s32 a;
                    s32 b;
                    k = acc / n;
                    acc += 0x10000;
                    k >>= 4;
                    a = gPairsByAngle[k * 2];
                    b = gPairsByAngle[k * 2 + 1];
                    v3.x = ((s64) a * emtr->field5C + 0x800) >> 12;
                    v3.y = ((s64) b * emtr->field5C + 0x800) >> 12;
                    v3.z = 0;
                    SPLUtil_TiltCoordinates(&n0->field8, &v3, emtr);
                    break;
                }
                case 4: {
                    SPLRandom_VecFx32(&n0->field8);
                    n0->field8.x =
                        ((s64) (s32) (((s64) n0->field8.x * emtr->field5C + 0x800) >> 12) *
                             ((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                     0x100000) >>
                              8) +
                         0x800) >>
                        12;
                    n0->field8.y =
                        ((s64) (s32) (((s64) n0->field8.y * emtr->field5C + 0x800) >> 12) *
                             ((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                     0x100000) >>
                              8) +
                         0x800) >>
                        12;
                    n0->field8.z =
                        ((s64) (s32) (((s64) n0->field8.z * emtr->field5C + 0x800) >> 12) *
                             ((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                     0x100000) >>
                              8) +
                         0x800) >>
                        12;
                    break;
                }
                case 5: {
                    SPLRandom_VecFx32_XY(&v5);
                    v5.x = ((s64) (s32) (((s64) v5.x * emtr->field5C + 0x800) >> 12) *
                                ((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                        0x100000) >>
                                 8) +
                            0x800) >>
                           12;
                    v5.y = ((s64) (s32) (((s64) v5.y * emtr->field5C + 0x800) >> 12) *
                                ((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                        0x100000) >>
                                 8) +
                            0x800) >>
                           12;
                    SPLUtil_TiltCoordinates(&n0->field8, &v5, emtr);
                    break;
                }
                case 8: {
                    SPLRandom_VecFx32(&n0->field8);
                    VEC_Fx16CrossProduct(&emtr->field84, &emtr->field8A, &a8);
                    v8.x = a8.x;
                    v8.y = a8.y;
                    v8.z = a8.z;
                    if (VEC_DotProduct(&v8, &n0->field8) <= 0) {
                        n0->field8.x = -n0->field8.x;
                        n0->field8.y = -n0->field8.y;
                        n0->field8.z = -n0->field8.z;
                    }
                    n0->field8.x = ((s64) n0->field8.x * emtr->field5C + 0x800) >> 12;
                    n0->field8.y = ((s64) n0->field8.y * emtr->field5C + 0x800) >> 12;
                    n0->field8.z = ((s64) n0->field8.z * emtr->field5C + 0x800) >> 12;
                    break;
                }
                case 9: {
                    SPLRandom_VecFx32(&n0->field8);
                    VEC_Fx16CrossProduct(&emtr->field84, &emtr->field8A, &a9);
                    v9.x = a9.x;
                    v9.y = a9.y;
                    v9.z = a9.z;
                    if (VEC_DotProduct(&v9, &n0->field8) < 0) {
                        n0->field8.x = -n0->field8.x;
                        n0->field8.y = -n0->field8.y;
                        n0->field8.z = -n0->field8.z;
                    }
                    n0->field8.x =
                        ((s64) (s32) (((s64) n0->field8.x * emtr->field5C + 0x800) >> 12) *
                             (((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                      0x100000) >>
                               9) +
                              0x800) +
                         0x800) >>
                        12;
                    n0->field8.y =
                        ((s64) (s32) (((s64) n0->field8.y * emtr->field5C + 0x800) >> 12) *
                             (((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                      0x100000) >>
                               9) +
                              0x800) +
                         0x800) >>
                        12;
                    n0->field8.z =
                        ((s64) (s32) (((s64) n0->field8.z * emtr->field5C + 0x800) >> 12) *
                             (((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                      0x100000) >>
                               9) +
                              0x800) +
                         0x800) >>
                        12;
                    break;
                }
                case 6: {
                    SPLRandom_VecFx32_XY(&n0->field14);
                    v6.x = ((s64) n0->field14.x * emtr->field5C + 0x800) >> 12;
                    v6.y = ((s64) n0->field14.y * emtr->field5C + 0x800) >> 12;
                    v6.z = (emtr->field60 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) -
                            emtr->field60 * 0x100) >>
                           8;
                    SPLUtil_TiltCoordinates(&n0->field8, &v6, emtr);
                    break;
                }
                case 7: {
                    SPLRandom_VecFx32_XY(&n0->field14);
                    v7.x = ((s64) (s32) (((s64) n0->field14.x * emtr->field5C + 0x800) >> 12) *
                                ((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                        0x100000) >>
                                 8) +
                            0x800) >>
                           12;
                    v7.y = ((s64) (s32) (((s64) n0->field14.y * emtr->field5C + 0x800) >> 12) *
                                ((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                        0x100000) >>
                                 8) +
                            0x800) >>
                           12;
                    v7.z = (emtr->field60 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) -
                            emtr->field60 * 0x100) >>
                           8;
                    SPLUtil_TiltCoordinates(&n0->field8, &v7, emtr);
                    break;
                }
            }

            s1 = ((d->field42 + 0xff -
                   ((d->field42 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 24)) >> 7)) *
                  emtr->field64) >>
                 8;
            s2 = ((d->field42 + 0xff -
                   ((d->field42 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 24)) >> 7)) *
                  emtr->field68) >>
                 8;

            if (d->field0.field0_0 == 6) {
                w.x = (s32) (((s64) n0->field14.x * emtr->field84.x + 0x800) >> 12) +
                      (s32) (((s64) n0->field14.y * emtr->field8A.x + 0x800) >> 12);
                w.y = (s32) (((s64) n0->field14.x * emtr->field84.y + 0x800) >> 12) +
                      (s32) (((s64) n0->field14.y * emtr->field8A.y + 0x800) >> 12);
                w.z = (s32) (((s64) n0->field14.x * emtr->field84.z + 0x800) >> 12) +
                      (s32) (((s64) n0->field14.y * emtr->field8A.z + 0x800) >> 12);
                VEC_Normalize(&w, &u);
            } else if (n0->field8.x == 0 && n0->field8.y == 0 && n0->field8.z == 0) {
                SPLRandom_VecFx32(&u);
            } else {
                VEC_Normalize(&n0->field8, &u);
            }

            n0->field14.x = emtr->field40.x + ((s32) (((s64) u.x * s1 + 0x800) >> 12) +
                                               (s32) (((s64) emtr->field50.x * s2 + 0x800) >> 12));
            n0->field14.y = emtr->field40.y + ((s32) (((s64) u.y * s1 + 0x800) >> 12) +
                                               (s32) (((s64) emtr->field50.y * s2 + 0x800) >> 12));
            n0->field14.z = emtr->field40.z + ((s32) (((s64) u.z * s1 + 0x800) >> 12) +
                                               (s32) (((s64) emtr->field50.z * s2 + 0x800) >> 12));
            n0->field38 = emtr->field28;

            n0->field30 =
                ((d->field40 + 0xff -
                  ((d->field40 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 24)) >> 7)) *
                 emtr->field6C) >>
                8;
            n0->field34 = 0x1000;

            if (d->field0.field0_9 && c->field8->field8_0) {
                Unk0201ca6c_20_08 *q;
                u32 r;
                r = (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 20;
                q = c->field8;
                ch[0] = q->field0;
                ch[1] = d->field22;
                ch[2] = q->field2;
                n0->field36 = ch[r % 3];
            } else {
                n0->field36 = d->field22;
            }

            n0->field2E_0 = emtr->field80_8;
            n0->field2E_5 = 0x1f;

            if (d->field0.field0_13) {
                n0->field20 = (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173);
            } else {
                n0->field20 = emtr->field56;
            }

            if (d->field0.field0_12) {
                n0->field22 =
                    ((d->field36 - d->field34) * ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 20) +
                     (d->field34 << 12)) >>
                    12;
            } else {
                n0->field22 = 0;
            }

            n0->field24 =
                (((0xff -
                   ((d->field41 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 24)) >> 8)) *
                  emtr->field70) >>
                 8) +
                1;
            n0->field26 = 0;

            if (d->field0.field0_11 && c->field10->field8_16) {
                Unk0201ca6c_20_10 *q;
                u32 r;
                r = (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 20;
                q = c->field10;
                n0->field2C = q->field0[r % q->field8_0];
            } else if (d->field0.field0_11 && !c->field10->field8_16) {
                n0->field2C = c->field10->field0[0];
            } else {
                n0->field2C = d->field47;
            }

            n0->field28 = 0xffff / c->field0->field48.field0_0;
            n0->field2A = 0xffff / n0->field24;
            n0->field2D = 0;
            if (d->field0.field0_20) {
                n0->field2D = (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 24;
            }
        } while (++i < n);
    }
}

static inline s32 func_0201c74c_inline(s32 k0, Unk0201e3c8 *a) {
    return ((s64) a->field14.z * (s64) k0 + 0x800) >> 12;
}

static inline s32 func_0201c74c_inline2(s32 k0, Unk0201e3c8 *a) {
    return ((s64) a->field14.y * (s64) k0 + 0x800) >> 12;
}

static inline s32 func_0201c74c_inline3(s32 k0, Unk0201e3c8 *a) {
    return ((s64) a->field14.x * (s64) k0 + 0x800) >> 12;
}

static inline s32 func_0201c74c_inline4(Unk0201ca6c_20_14 *e) {
    return e->field9 + 1;
}

void SPLEmitter_EmitChildren(Unk0201e3c8 *ptcl, Unk0201ca6c *emtr, Unk0201e494 *list) {
    s32 k0;
    Unk0201e3c8 *n;
    s32 i;
    Unk0201ca6c_20_14 *e;
    Vec3 *d;
    u32 b;

    e = emtr->field20->field14;
    k0 = ((s64) (e->field8 << 12) * 16 + 0x800) >> 12;
    for (i = 0; i < e->fieldC; i++) {
        {
            n = SPLList_PopFront(list);
            if (n == NULL) {
                return;
            }
            SPLList_PushFront(&emtr->field14, n);
            d = &n->field38;
            n->field8 = ptcl->field8;
            n->field14.x = func_0201c74c_inline3(k0, ptcl) +
                           ((e->field2 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) -
                             (e->field2 << 8)) >>
                            8);
            n->field14.y = func_0201c74c_inline2(k0, ptcl) +
                           ((e->field2 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) -
                             (e->field2 << 8)) >>
                            8);
            n->field14.z = func_0201c74c_inline(k0, ptcl) +
                           ((e->field2 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) -
                             (e->field2 << 8)) >>
                            8);
            *d = ptcl->field38;
            n->field30 = (((ptcl->field30 * ptcl->field34) >> 12) * func_0201c74c_inline4(e)) >> 6;
            n->field34 = 0x1000;
            if (e->field0_6) {
                n->field36 = e->fieldA;
            } else {
                n->field36 = ptcl->field36;
            }
            n->field2E_0 = (ptcl->field2E_0 * (ptcl->field2E_5 + 1)) >> 5;
            n->field2E_5 = 0x1f;
            switch (e->field0_3) {
                case 2:
                    n->field20 = ptcl->field20;
                    n->field22 = ptcl->field22;
                    break;
                case 0:
                    n->field20 = 0;
                    n->field22 = 0;
                    break;
                case 1:
                    n->field20 = ptcl->field20;
                    n->field22 = 0;
                    break;
            }
            n->field24 = e->field6;
            n->field26 = 0;
            n->field2C = e->fieldF;
            b = ptcl->field24;
            n->field28 = 0xffff / (s32) (b >> 1);
            n->field2A = 0xffff / ptcl->field24;
            n->field2D = 0;
        }
    }
}

void SPLUtil_DrawXYPlane(u32 a, u32 b, s32 c, s32 d) {
    u32 f;
    s32 s;

    reg_G3_BEGIN_VTXS = 1;
    s = ((s16) (d - 0x1000) >> 6) & 0x3ff;
    reg_G3_TEXCOORD = 0;
    reg_G3_VTX_10 = (((s16) (c - 0x1000) >> 6) & 0x3ff) | ((((s16) (d + 0x1000) >> 6) & 0x3ff) << 10);
    reg_G3_TEXCOORD = (a << 8) >> 16;
    f = (b << 8) >> 16;
    reg_G3_VTX_10 = (((s16) (c + 0x1000) >> 6) & 0x3ff) | ((((s16) (d + 0x1000) >> 6) & 0x3ff) << 10);
    reg_G3_TEXCOORD = ((a << 8) >> 16) | (f << 16);
    reg_G3_VTX_10 = (((s16) (c + 0x1000) >> 6) & 0x3ff) | (s << 10);
    reg_G3_TEXCOORD = f << 16;
    reg_G3_VTX_10 = (((s16) (c - 0x1000) >> 6) & 0x3ff) | (s << 10);
    reg_G3_END_VTXS = 0;
}

void SPLUtil_DrawXZPlane(u32 a, u32 b, s32 c, s32 d) {
    s32 r;
    u32 s;
    u32 e;
    u32 f;
    s32 p;
    s32 q;

    reg_G3_BEGIN_VTXS = 1;
    reg_G3_TEXCOORD = 0;
    q = ((s16) (c - 0x1000) >> 6) & 0x3ff;
    e = (a << 8) >> 16;
    f = (b << 8) >> 16;
    s = ((s16) (d - 0x1000) >> 6) & 0x3ff;
    p = ((s16) (d + 0x1000) >> 6) & 0x3ff;
    reg_G3_VTX_10 = q | (p << 20);
    reg_G3_TEXCOORD = e;
    r = ((s16) (c + 0x1000) >> 6) & 0x3ff;
    reg_G3_VTX_10 = r | (p << 20);
    reg_G3_TEXCOORD = e | (f << 16);
    reg_G3_VTX_10 = r | (s << 20);
    reg_G3_TEXCOORD = f << 16;
    reg_G3_VTX_10 = q | (s << 20);
    reg_G3_END_VTXS = 0;
}

void SPLUtil_RotateXYZ(s32 sinValue, s32 cosValue, MtxFx43 *mtx) {
    s32 t1;
    s32 t2;
    s32 x;
    s32 y;
    s32 z;

    t1 = ((s64) (0x1000 - cosValue) * (s64) 0x555 + 0x800) >> 12;
    t2 = ((s64) sinValue * (s64) 0x93d + 0x800) >> 12;
    y = t1 + t2;
    z = t1 - t2;
    x = t1 + cosValue;
    mtx->field0[0].x = x;
    mtx->field0[1].x = y;
    mtx->field0[2].x = z;
    mtx->field0[3].x = 0;
    mtx->field0[0].y = z;
    mtx->field0[1].y = x;
    mtx->field0[2].y = y;
    mtx->field0[3].y = 0;
    mtx->field0[0].z = y;
    mtx->field0[1].z = z;
    mtx->field0[2].z = x;
    mtx->field0[3].z = 0;
}

void SPLUtil_RotateY(s32 sinValue, s32 cosValue, MtxFx43 *mtx) {
    mtx->field0[0].x = cosValue;
    mtx->field0[1].x = 0;
    mtx->field0[2].x = sinValue;
    mtx->field0[3].x = 0;
    mtx->field0[0].y = 0;
    mtx->field0[1].y = 0x1000;
    mtx->field0[2].y = 0;
    mtx->field0[3].y = 0;
    mtx->field0[0].z = -sinValue;
    mtx->field0[1].z = 0;
    mtx->field0[2].z = cosValue;
    mtx->field0[3].z = 0;
}

void SPLDraw_Billboard(SPLManager *mgr, Unk0201e3c8 *ptcl) {
    Vec3 t;
    MtxFx43 m;
    s32 k;
    s32 f0;
    s32 f1;
    s32 t0;
    s32 t1;
    u16 c0;
    u16 c1;
    s32 x;
    s32 y;
    s32 z;
    s32 s;
    MtxFx43 *q;
    u8 w;
    s32 h;

    s = mgr->mRenderStateEmitter->field20->field0->field30;
    q = mgr->mRenderStateViewMatrix;
    w = mgr->mRenderStateEmitter->field20->field0->field48.field0_28;
    h = ptcl->field34;
    c0 = ptcl->field36;
    c1 = mgr->mRenderStateEmitter->field72;
    k = (ptcl->field2E_0 * (ptcl->field2E_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->field2E_10 << 24) | (mgr->mMiscPolygonAttr | 0xc0) | (k << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (k == 0) {
        return;
    }
    f1 = ptcl->field30;
    f0 = ((s64) f1 * s + 0x800) >> 12;
    if (w == 0) {
        f0 = ((s64) f0 * h + 0x800) >> 12;
        f1 = ((s64) f1 * h + 0x800) >> 12;
    } else if (w == 1) {
        f0 = ((s64) f0 * h + 0x800) >> 12;
    } else {
        f1 = ((s64) f1 * h + 0x800) >> 12;
    }
    if (mgr->mRenderStateEmitter->field20->field0->field0.field0_23 == 0) {
        t.x = ptcl->field8.x + ptcl->field38.x;
        t.y = ptcl->field8.y + ptcl->field38.y;
        t.z = ptcl->field8.z + ptcl->field38.z;
        MTX_MultVec43(&t, q, &t);
        t0 = gPairsByAngle[(ptcl->field20 >> 4) * 2];
        t1 = gPairsByAngle[(ptcl->field20 >> 4) * 2 + 1];
        m.field0[0].x = ((s64) t1 * f0 + 0x800) >> 12;
        m.field0[0].y = ((s64) t0 * f0 + 0x800) >> 12;
        m.field0[0].z = 0;
        m.field0[1].x = ((s64) -t0 * f1 + 0x800) >> 12;
        m.field0[1].y = ((s64) t1 * f1 + 0x800) >> 12;
        m.field0[1].z = 0;
        m.field0[2].x = 0;
        m.field0[2].y = 0;
        m.field0[2].z = 0x1000;
        m.field0[3].x = t.x;
        m.field0[3].y = t.y;
        m.field0[3].z = t.z;
        reg_G3_MTX_IDENTITY = 0;
        G3_MultMtx43(&m);
    } else {
        t.x = ptcl->field8.x + ptcl->field38.x - mgr->mRenderStateEmitter->field20->field0->field4.x;
        t.y = ptcl->field8.y + ptcl->field38.y - mgr->mRenderStateEmitter->field20->field0->field4.y;
        t.z = ptcl->field8.z + ptcl->field38.z - mgr->mRenderStateEmitter->field20->field0->field4.z;
        MTX_MultVec43(&t, q, &t);
        t0 = gPairsByAngle[(ptcl->field20 >> 4) * 2];
        t1 = gPairsByAngle[(ptcl->field20 >> 4) * 2 + 1];
        m.field0[0].x = ((s64) t1 * f0 + 0x800) >> 12;
        m.field0[0].y = ((s64) t0 * f0 + 0x800) >> 12;
        m.field0[0].z = 0;
        m.field0[1].x = ((s64) -t0 * f1 + 0x800) >> 12;
        m.field0[1].y = ((s64) t1 * f1 + 0x800) >> 12;
        m.field0[1].z = 0;
        m.field0[2].x = 0;
        m.field0[2].y = 0;
        m.field0[2].z = 0x1000;
        m.field0[3].x = t.x;
        m.field0[3].y = t.y;
        m.field0[3].z = t.z;
        reg_G3_MTX_IDENTITY = 0;
        z = mgr->mRenderStateEmitter->field20->field0->field4.z;
        y = mgr->mRenderStateEmitter->field20->field0->field4.y;
        x = mgr->mRenderStateEmitter->field20->field0->field4.x;
        reg_G3_MTX_TRANS = x;
        reg_G3_MTX_TRANS = y;
        reg_G3_MTX_TRANS = z;
        G3_MultMtx43(&m);
    }
    reg_G3_COLOR = (u16) ((((c0 & 0x1f) * (c1 & 0x1f)) >> 5) | ((((c0 & 0x3e0) * (c1 & 0x3e0)) >> 15) << 5) |
                          ((((c0 & 0x7c00) * (c1 & 0x7c00)) >> 25) << 10));
    SPLUtil_DrawXYPlane(mgr->mRenderStateEmitter->field78, mgr->mRenderStateEmitter->field7A,
                        mgr->mRenderStateEmitter->field20->field0->field50,
                        mgr->mRenderStateEmitter->field20->field0->field52);
}

void SPLDraw_Child_Billboard(SPLManager *mgr, Unk0201e3c8 *ptcl) {
    Vec3 t;
    MtxFx43 m;
    s32 k;
    s32 f0;
    s32 f1;
    s32 t0;
    s32 t1;
    u16 c0;
    u16 c1;
    s32 x;
    s32 y;
    s32 z;
    s32 s;
    MtxFx43 *q;

    s = mgr->mRenderStateEmitter->field20->field0->field30;
    q = mgr->mRenderStateViewMatrix;
    k = (ptcl->field2E_0 * (ptcl->field2E_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->field2E_10 << 24) | (mgr->mMiscPolygonAttr | 0xc0) | (k << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (k == 0) {
        return;
    }
    f1 = ptcl->field30;
    f0 = ((s64) f1 * s + 0x800) >> 12;
    switch (mgr->mRenderStateEmitter->field20->field0->field48.field0_28) {
        case 0:
            f0 = ((s64) f0 * ptcl->field34 + 0x800) >> 12;
            f1 = ((s64) f1 * ptcl->field34 + 0x800) >> 12;
            break;
        case 1:
            f0 = ((s64) f0 * ptcl->field34 + 0x800) >> 12;
            break;
        case 2:
            f1 = ((s64) f1 * ptcl->field34 + 0x800) >> 12;
            break;
    }
    if (mgr->mRenderStateEmitter->field20->field0->field0.field0_23 == 0) {
        t.x = ptcl->field8.x + ptcl->field38.x;
        t.y = ptcl->field8.y + ptcl->field38.y;
        t.z = ptcl->field8.z + ptcl->field38.z;
        MTX_MultVec43(&t, q, &t);
        t0 = gPairsByAngle[(ptcl->field20 >> 4) * 2];
        t1 = gPairsByAngle[(ptcl->field20 >> 4) * 2 + 1];
        m.field0[0].x = ((s64) t1 * f0 + 0x800) >> 12;
        m.field0[0].y = ((s64) t0 * f0 + 0x800) >> 12;
        m.field0[0].z = 0;
        m.field0[1].x = ((s64) -t0 * f1 + 0x800) >> 12;
        m.field0[1].y = ((s64) t1 * f1 + 0x800) >> 12;
        m.field0[1].z = 0;
        m.field0[2].x = 0;
        m.field0[2].y = 0;
        m.field0[2].z = 0x1000;
        m.field0[3].x = t.x;
        m.field0[3].y = t.y;
        m.field0[3].z = t.z;
        reg_G3_MTX_IDENTITY = 0;
        G3_MultMtx43(&m);
    } else {
        t.x = ptcl->field8.x + ptcl->field38.x - mgr->mRenderStateEmitter->field20->field0->field4.x;
        t.y = ptcl->field8.y + ptcl->field38.y - mgr->mRenderStateEmitter->field20->field0->field4.y;
        t.z = ptcl->field8.z + ptcl->field38.z - mgr->mRenderStateEmitter->field20->field0->field4.z;
        MTX_MultVec43(&t, q, &t);
        t0 = gPairsByAngle[(ptcl->field20 >> 4) * 2];
        t1 = gPairsByAngle[(ptcl->field20 >> 4) * 2 + 1];
        m.field0[0].x = ((s64) t1 * f0 + 0x800) >> 12;
        m.field0[0].y = ((s64) t0 * f0 + 0x800) >> 12;
        m.field0[0].z = 0;
        m.field0[1].x = ((s64) -t0 * f1 + 0x800) >> 12;
        m.field0[1].y = ((s64) t1 * f1 + 0x800) >> 12;
        m.field0[1].z = 0;
        m.field0[2].x = 0;
        m.field0[2].y = 0;
        m.field0[2].z = 0x1000;
        m.field0[3].x = t.x;
        m.field0[3].y = t.y;
        m.field0[3].z = t.z;
        reg_G3_MTX_IDENTITY = 0;
        z = mgr->mRenderStateEmitter->field20->field0->field4.z;
        y = mgr->mRenderStateEmitter->field20->field0->field4.y;
        x = mgr->mRenderStateEmitter->field20->field0->field4.x;
        reg_G3_MTX_TRANS = x;
        reg_G3_MTX_TRANS = y;
        reg_G3_MTX_TRANS = z;
        G3_MultMtx43(&m);
    }
    c0 = ptcl->field36;
    c1 = mgr->mRenderStateEmitter->field72;
    reg_G3_COLOR = (u16) ((((c0 & 0x1f) * (c1 & 0x1f)) >> 5) | ((((c0 & 0x3e0) * (c1 & 0x3e0)) >> 15) << 5) |
                          ((((c0 & 0x7c00) * (c1 & 0x7c00)) >> 25) << 10));
    SPLUtil_DrawXYPlane(mgr->mRenderStateEmitter->field7C, mgr->mRenderStateEmitter->field7E, 0, 0);
}

void SPLDraw_DirectionalBillboard(SPLManager *mgr, Unk0201e3c8 *ptcl) {
    Vec3 c;
    Vec3 pos;
    Vec3 v;
    Vec3 col;
    s32 m33[9];
    s32 buf[12];
    MtxFx43 *m;
    s32 a;
    s32 h;
    s32 w;
    s32 t;
    s32 u;
    s32 x;
    u16 k;
    u16 q;
    s16 s;
    s32 i;
    s32 j;
    s32 n;

    m = mgr->mRenderStateViewMatrix;
    s = mgr->mRenderStateEmitter->field20->field0->field30;
    a = (ptcl->field2E_0 * (ptcl->field2E_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->field2E_10 << 24) | (mgr->mMiscPolygonAttr | 0xc0) | (a << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (a == 0) {
        return;
    }
    w = ptcl->field30;
    h = ((s64) w * s + 0x800) >> 12;
    switch (mgr->mRenderStateEmitter->field20->field0->field48.field0_28) {
        case 0:
            h = ((s64) h * ptcl->field34 + 0x800) >> 12;
            w = ((s64) w * ptcl->field34 + 0x800) >> 12;
            break;
        case 1:
            h = ((s64) h * ptcl->field34 + 0x800) >> 12;
            break;
        case 2:
            w = ((s64) w * ptcl->field34 + 0x800) >> 12;
            break;
    }
    if (!mgr->mRenderStateEmitter->field20->field0->field0.field0_23) {
        pos.x = ptcl->field8.x + ptcl->field38.x;
        pos.y = ptcl->field8.y + ptcl->field38.y;
        pos.z = ptcl->field8.z + ptcl->field38.z;
        v = ptcl->field14;
        col.x = m->field0[0].z;
        col.y = m->field0[1].z;
        col.z = m->field0[2].z;
        VEC_CrossProduct(&v, &col, &v);
        if (v.x == 0 && v.y == 0 && v.z == 0) {
            return;
        }
        VEC_Normalize(&v, &v);
        MI_Copy36B(m, m33);
        MTX_MultVec33(&v, m33, &v);
        MTX_MultVec43(&pos, m, &pos);
        c = ptcl->field14;
        VEC_Normalize(&c, &c);
        t = (s32) (((s64) c.x * -m->field0[0].z + 0x800) >> 12) +
            (s32) (((s64) c.y * -m->field0[1].z + 0x800) >> 12) + (s32) (((s64) c.z * -m->field0[2].z + 0x800) >> 12);
        if (t < 0) {
            t = -t;
        }
        u = ((s64) (0x1000 - t) * (s32) mgr->mRenderStateEmitter->field20->field0->field48.field0_8 + 0x800) >> 12;
        x = ((s64) w * (u + 0x1000) + 0x800) >> 12;
        buf[0] = ((s64) v.x * h + 0x800) >> 12;
        buf[3] = ((s64) -v.y * x + 0x800) >> 12;
        buf[6] = 0;
        buf[9] = pos.x;
        buf[1] = ((s64) v.y * h + 0x800) >> 12;
        buf[4] = ((s64) v.x * x + 0x800) >> 12;
        buf[7] = 0;
        buf[10] = pos.y;
        buf[2] = 0;
        buf[5] = 0;
        buf[8] = 0x1000;
        buf[11] = pos.z;
        reg_G3_MTX_IDENTITY = 0;
        G3_MultMtx43(buf);
    } else {
        pos.x = ptcl->field8.x + ptcl->field38.x - mgr->mRenderStateEmitter->field20->field0->field4.x;
        pos.y = ptcl->field8.y + ptcl->field38.y - mgr->mRenderStateEmitter->field20->field0->field4.y;
        pos.z = ptcl->field8.z + ptcl->field38.z - mgr->mRenderStateEmitter->field20->field0->field4.z;
        v = ptcl->field14;
        col.x = m->field0[0].z;
        col.y = m->field0[1].z;
        col.z = m->field0[2].z;
        VEC_CrossProduct(&v, &col, &v);
        if (v.x == 0 && v.y == 0 && v.z == 0) {
            return;
        }
        VEC_Normalize(&v, &v);
        MI_Copy36B(m, m33);
        MTX_MultVec33(&v, m33, &v);
        MTX_MultVec43(&pos, m, &pos);
        c = ptcl->field14;
        VEC_Normalize(&c, &c);
        t = (s32) (((s64) c.x * -m->field0[0].z + 0x800) >> 12) +
            (s32) (((s64) c.y * -m->field0[1].z + 0x800) >> 12) + (s32) (((s64) c.z * -m->field0[2].z + 0x800) >> 12);
        if (t < 0) {
            t = -t;
        }
        u = ((s64) (0x1000 - t) * (s32) mgr->mRenderStateEmitter->field20->field0->field48.field0_8 + 0x800) >> 12;
        x = ((s64) w * (u + 0x1000) + 0x800) >> 12;
        buf[0] = ((s64) v.x * h + 0x800) >> 12;
        buf[3] = ((s64) -v.y * x + 0x800) >> 12;
        buf[6] = 0;
        buf[9] = pos.x;
        buf[1] = ((s64) v.y * h + 0x800) >> 12;
        buf[4] = ((s64) v.x * x + 0x800) >> 12;
        buf[7] = 0;
        buf[10] = pos.y;
        buf[2] = 0;
        buf[5] = 0;
        buf[8] = 0x1000;
        buf[11] = pos.z;
        reg_G3_MTX_IDENTITY = 0;
        n = mgr->mRenderStateEmitter->field20->field0->field4.z;
        j = mgr->mRenderStateEmitter->field20->field0->field4.y;
        i = mgr->mRenderStateEmitter->field20->field0->field4.x;
        reg_G3_MTX_TRANS = i;
        reg_G3_MTX_TRANS = j;
        reg_G3_MTX_TRANS = n;
        G3_MultMtx43(buf);
    }
    q = ptcl->field36;
    k = mgr->mRenderStateEmitter->field72;
    reg_G3_COLOR = (u16) ((((q & 0x1f) * (k & 0x1f)) >> 5) | ((((q & 0x3e0) * (k & 0x3e0)) >> 15) << 5) |
                          ((((q & 0x7c00) * (k & 0x7c00)) >> 25) << 10));
    SPLUtil_DrawXYPlane(mgr->mRenderStateEmitter->field78, mgr->mRenderStateEmitter->field7A,
                        mgr->mRenderStateEmitter->field20->field0->field50,
                        mgr->mRenderStateEmitter->field20->field0->field52);
}

void SPLDraw_Child_DirectionalBillboard(SPLManager *mgr, Unk0201e3c8 *ptcl) {
    Vec3 c;
    Vec3 pos;
    Vec3 v;
    Vec3 col;
    s32 m33[9];
    s32 buf[12];
    MtxFx43 *m;
    s32 a;
    s32 h;
    s32 w;
    s32 t;
    s32 u;
    s32 x;
    u16 k;
    u16 q;
    s16 s;
    s32 i;
    s32 j;
    s32 n;

    m = mgr->mRenderStateViewMatrix;
    s = mgr->mRenderStateEmitter->field20->field0->field30;
    a = (ptcl->field2E_0 * (ptcl->field2E_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->field2E_10 << 24) | (mgr->mMiscPolygonAttr | 0xc0) | (a << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (a == 0) {
        return;
    }
    w = ptcl->field30;
    h = ((s64) w * s + 0x800) >> 12;
    switch (mgr->mRenderStateEmitter->field20->field0->field48.field0_28) {
        case 0:
            h = ((s64) h * ptcl->field34 + 0x800) >> 12;
            w = ((s64) w * ptcl->field34 + 0x800) >> 12;
            break;
        case 1:
            h = ((s64) h * ptcl->field34 + 0x800) >> 12;
            break;
        case 2:
            w = ((s64) w * ptcl->field34 + 0x800) >> 12;
            break;
    }
    if (!mgr->mRenderStateEmitter->field20->field0->field0.field0_23) {
        pos.x = ptcl->field8.x + ptcl->field38.x;
        pos.y = ptcl->field8.y + ptcl->field38.y;
        pos.z = ptcl->field8.z + ptcl->field38.z;
        v = ptcl->field14;
        col.x = m->field0[0].z;
        col.y = m->field0[1].z;
        col.z = m->field0[2].z;
        VEC_CrossProduct(&v, &col, &v);
        if (v.x == 0 && v.y == 0 && v.z == 0) {
            return;
        }
        VEC_Normalize(&v, &v);
        MI_Copy36B(m, m33);
        MTX_MultVec33(&v, m33, &v);
        MTX_MultVec43(&pos, m, &pos);
        c = ptcl->field14;
        VEC_Normalize(&c, &c);
        t = (s32) (((s64) c.x * -m->field0[0].z + 0x800) >> 12) +
            (s32) (((s64) c.y * -m->field0[1].z + 0x800) >> 12) + (s32) (((s64) c.z * -m->field0[2].z + 0x800) >> 12);
        if (t < 0) {
            t = -t;
        }
        u = ((s64) (0x1000 - t) * (s32) mgr->mRenderStateEmitter->field20->field0->field48.field0_8 + 0x800) >> 12;
        x = ((s64) w * (u + 0x1000) + 0x800) >> 12;
        buf[0] = ((s64) v.x * h + 0x800) >> 12;
        buf[3] = ((s64) -v.y * x + 0x800) >> 12;
        buf[6] = 0;
        buf[9] = pos.x;
        buf[1] = ((s64) v.y * h + 0x800) >> 12;
        buf[4] = ((s64) v.x * x + 0x800) >> 12;
        buf[7] = 0;
        buf[10] = pos.y;
        buf[2] = 0;
        buf[5] = 0;
        buf[8] = 0x1000;
        buf[11] = pos.z;
        reg_G3_MTX_IDENTITY = 0;
        G3_MultMtx43(buf);
    } else {
        pos.x = ptcl->field8.x + ptcl->field38.x - mgr->mRenderStateEmitter->field20->field0->field4.x;
        pos.y = ptcl->field8.y + ptcl->field38.y - mgr->mRenderStateEmitter->field20->field0->field4.y;
        pos.z = ptcl->field8.z + ptcl->field38.z - mgr->mRenderStateEmitter->field20->field0->field4.z;
        v = ptcl->field14;
        col.x = m->field0[0].z;
        col.y = m->field0[1].z;
        col.z = m->field0[2].z;
        VEC_CrossProduct(&v, &col, &v);
        if (v.x == 0 && v.y == 0 && v.z == 0) {
            return;
        }
        VEC_Normalize(&v, &v);
        MI_Copy36B(m, m33);
        MTX_MultVec33(&v, m33, &v);
        MTX_MultVec43(&pos, m, &pos);
        c = ptcl->field14;
        VEC_Normalize(&c, &c);
        t = (s32) (((s64) c.x * -m->field0[0].z + 0x800) >> 12) +
            (s32) (((s64) c.y * -m->field0[1].z + 0x800) >> 12) + (s32) (((s64) c.z * -m->field0[2].z + 0x800) >> 12);
        if (t < 0) {
            t = -t;
        }
        u = ((s64) (0x1000 - t) * (s32) mgr->mRenderStateEmitter->field20->field0->field48.field0_8 + 0x800) >> 12;
        x = ((s64) w * (u + 0x1000) + 0x800) >> 12;
        buf[0] = ((s64) v.x * h + 0x800) >> 12;
        buf[3] = ((s64) -v.y * x + 0x800) >> 12;
        buf[6] = 0;
        buf[9] = pos.x;
        buf[1] = ((s64) v.y * h + 0x800) >> 12;
        buf[4] = ((s64) v.x * x + 0x800) >> 12;
        buf[7] = 0;
        buf[10] = pos.y;
        buf[2] = 0;
        buf[5] = 0;
        buf[8] = 0x1000;
        buf[11] = pos.z;
        reg_G3_MTX_IDENTITY = 0;
        n = mgr->mRenderStateEmitter->field20->field0->field4.z;
        j = mgr->mRenderStateEmitter->field20->field0->field4.y;
        i = mgr->mRenderStateEmitter->field20->field0->field4.x;
        reg_G3_MTX_TRANS = i;
        reg_G3_MTX_TRANS = j;
        reg_G3_MTX_TRANS = n;
        G3_MultMtx43(buf);
    }
    q = ptcl->field36;
    k = mgr->mRenderStateEmitter->field72;
    reg_G3_COLOR = (u16) ((((q & 0x1f) * (k & 0x1f)) >> 5) | ((((q & 0x3e0) * (k & 0x3e0)) >> 15) << 5) |
                          ((((q & 0x7c00) * (k & 0x7c00)) >> 25) << 10));
    SPLUtil_DrawXYPlane(mgr->mRenderStateEmitter->field7C, mgr->mRenderStateEmitter->field7E, 0, 0);
}

void SPLDraw_Polygon(SPLManager *mgr, Unk0201e3c8 *ptcl) {
    MtxFx43 a;
    MtxFx43 b;
    MtxFx43 c;
    s32 k;
    s32 f0;
    s32 f1;
    u16 c0;
    u16 c1;
    s32 x;
    s32 y;
    s32 z;

    k = (ptcl->field2E_0 * (ptcl->field2E_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->field2E_10 << 24) | (mgr->mMiscPolygonAttr | 0xc0) | (k << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (k == 0) {
        return;
    }
    data_02161ac8[mgr->mRenderStateEmitter->field20->field0->field0.field0_17](
        gPairsByAngle[(ptcl->field20 >> 4) * 2], gPairsByAngle[(ptcl->field20 >> 4) * 2 + 1], &b);
    f1 = ptcl->field30;
    f0 = ((s64) f1 * mgr->mRenderStateEmitter->field20->field0->field30 + 0x800) >> 12;
    switch (mgr->mRenderStateEmitter->field20->field0->field48.field0_28) {
        case 0:
            f0 = ((s64) f0 * ptcl->field34 + 0x800) >> 12;
            f1 = ((s64) f1 * ptcl->field34 + 0x800) >> 12;
            break;
        case 1:
            f0 = ((s64) f0 * ptcl->field34 + 0x800) >> 12;
            break;
        case 2:
            f1 = ((s64) f1 * ptcl->field34 + 0x800) >> 12;
            break;
    }
    MTX_Scale43_(&c, f0, f1, f1);
    MTX_Concat43(&c, &b, &a);
    if (mgr->mRenderStateEmitter->field20->field0->field0.field0_23 == 0) {
        a.field0[3].x = ptcl->field8.x + ptcl->field38.x;
        a.field0[3].y = ptcl->field8.y + ptcl->field38.y;
        a.field0[3].z = ptcl->field8.z + ptcl->field38.z;
        G3_LoadMtx43(mgr->mRenderStateViewMatrix);
        G3_MultMtx43(&a);
    } else {
        a.field0[3].x = ptcl->field8.x + ptcl->field38.x - mgr->mRenderStateEmitter->field20->field0->field4.x;
        a.field0[3].y = ptcl->field8.y + ptcl->field38.y - mgr->mRenderStateEmitter->field20->field0->field4.y;
        a.field0[3].z = ptcl->field8.z + ptcl->field38.z - mgr->mRenderStateEmitter->field20->field0->field4.z;
        reg_G3_MTX_IDENTITY = 0;
        z = mgr->mRenderStateEmitter->field20->field0->field4.z;
        y = mgr->mRenderStateEmitter->field20->field0->field4.y;
        x = mgr->mRenderStateEmitter->field20->field0->field4.x;
        reg_G3_MTX_TRANS = x;
        reg_G3_MTX_TRANS = y;
        reg_G3_MTX_TRANS = z;
        G3_MultMtx43(mgr->mRenderStateViewMatrix);
        G3_MultMtx43(&a);
    }
    c0 = ptcl->field36;
    c1 = mgr->mRenderStateEmitter->field72;
    reg_G3_COLOR = (u16) ((((c0 & 0x1f) * (c1 & 0x1f)) >> 5) | ((((c0 & 0x3e0) * (c1 & 0x3e0)) >> 15) << 5) |
                          ((((c0 & 0x7c00) * (c1 & 0x7c00)) >> 25) << 10));
    data_02161ac0[mgr->mRenderStateEmitter->field20->field0->field0.field0_19](
        mgr->mRenderStateEmitter->field78, mgr->mRenderStateEmitter->field7A,
        mgr->mRenderStateEmitter->field20->field0->field50, mgr->mRenderStateEmitter->field20->field0->field52);
}

void SPLDraw_Child_Polygon(SPLManager *mgr, Unk0201e3c8 *ptcl) {
    MtxFx43 a;
    MtxFx43 b;
    MtxFx43 c;
    s32 k;
    s32 f0;
    s32 f1;
    u16 c0;
    u16 c1;
    s32 x;
    s32 y;
    s32 z;

    k = (ptcl->field2E_0 * (ptcl->field2E_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->field2E_10 << 24) | (mgr->mMiscPolygonAttr | 0xc0) | (k << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (k == 0) {
        return;
    }
    data_02161ac8[mgr->mRenderStateEmitter->field20->field14->field0_9](
        gPairsByAngle[(ptcl->field20 >> 4) * 2], gPairsByAngle[(ptcl->field20 >> 4) * 2 + 1], &b);
    f1 = ptcl->field30;
    f0 = ((s64) f1 * mgr->mRenderStateEmitter->field20->field0->field30 + 0x800) >> 12;
    switch (mgr->mRenderStateEmitter->field20->field0->field48.field0_28) {
        case 0:
            f0 = ((s64) f0 * ptcl->field34 + 0x800) >> 12;
            f1 = ((s64) f1 * ptcl->field34 + 0x800) >> 12;
            break;
        case 1:
            f0 = ((s64) f0 * ptcl->field34 + 0x800) >> 12;
            break;
        case 2:
            f1 = ((s64) f1 * ptcl->field34 + 0x800) >> 12;
            break;
    }
    MTX_Scale43_(&c, f0, f1, f1);
    MTX_Concat43(&b, &c, &a);
    if (mgr->mRenderStateEmitter->field20->field0->field0.field0_23 == 0) {
        a.field0[3].x = ptcl->field8.x + ptcl->field38.x;
        a.field0[3].y = ptcl->field8.y + ptcl->field38.y;
        a.field0[3].z = ptcl->field8.z + ptcl->field38.z;
        G3_LoadMtx43(mgr->mRenderStateViewMatrix);
        G3_MultMtx43(&a);
    } else {
        a.field0[3].x = ptcl->field8.x + ptcl->field38.x - mgr->mRenderStateEmitter->field20->field0->field4.x;
        a.field0[3].y = ptcl->field8.y + ptcl->field38.y - mgr->mRenderStateEmitter->field20->field0->field4.y;
        a.field0[3].z = ptcl->field8.z + ptcl->field38.z - mgr->mRenderStateEmitter->field20->field0->field4.z;
        reg_G3_MTX_IDENTITY = 0;
        z = mgr->mRenderStateEmitter->field20->field0->field4.z;
        y = mgr->mRenderStateEmitter->field20->field0->field4.y;
        x = mgr->mRenderStateEmitter->field20->field0->field4.x;
        reg_G3_MTX_TRANS = x;
        reg_G3_MTX_TRANS = y;
        reg_G3_MTX_TRANS = z;
        G3_MultMtx43(mgr->mRenderStateViewMatrix);
        G3_MultMtx43(&a);
    }
    c0 = ptcl->field36;
    c1 = mgr->mRenderStateEmitter->field72;
    reg_G3_COLOR = (u16) ((((c0 & 0x1f) * (c1 & 0x1f)) >> 5) | ((((c0 & 0x3e0) * (c1 & 0x3e0)) >> 15) << 5) |
                          ((((c0 & 0x7c00) * (c1 & 0x7c00)) >> 25) << 10));
    data_02161ac0[mgr->mRenderStateEmitter->field20->field14->field0_11](mgr->mRenderStateEmitter->field7C,
                                                                          mgr->mRenderStateEmitter->field7E, 0, 0);
}

void SPLDraw_DirectionalPolygon(SPLManager *mgr, Unk0201e3c8 *ptcl) {
    MtxFx43 a;
    MtxFx43 b;
    MtxFx43 c;
    Vec3 v;
    Vec3 u;
    Vec3 w;
    Vec3 e;
    MtxFx43 d;
    s32 k;
    s32 f0;
    s32 f1;
    s32 s;
    u16 c0;
    u16 c1;
    s32 x;
    s32 y;
    s32 z;

    k = (ptcl->field2E_0 * (ptcl->field2E_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->field2E_10 << 24) | (mgr->mMiscPolygonAttr | 0xc0) | (k << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (k == 0) {
        return;
    }
    data_02161ac8[mgr->mRenderStateEmitter->field20->field0->field0.field0_17](
        gPairsByAngle[(ptcl->field20 >> 4) * 2], gPairsByAngle[(ptcl->field20 >> 4) * 2 + 1], &b);
    MTX_Identity43_(&d);
    if (mgr->mRenderStateEmitter->field20->field0->field48.field0_31 == 0) {
        VEC_Normalize(&ptcl->field14, &v);
    } else {
        VEC_Normalize(&ptcl->field8, &v);
        v.x = -v.x;
        v.y = -v.y;
        v.z = -v.z;
    }
    e.x = 0;
    e.y = 0x1000;
    e.z = 0;
    s = VEC_DotProduct(&v, &e);
    if (s > 0xccd || s < -0xccd) {
        e.x = 0x1000;
        e.y = 0;
        e.z = 0;
    }
    VEC_CrossProduct(&v, &e, &u);
    VEC_CrossProduct(&v, &u, &w);
    d.field0[0].x = u.x;
    d.field0[0].y = u.y;
    d.field0[0].z = u.z;
    d.field0[1].x = v.x;
    d.field0[1].y = v.y;
    d.field0[1].z = v.z;
    d.field0[2].x = w.x;
    d.field0[2].y = w.y;
    d.field0[2].z = w.z;
    MTX_Concat43(&b, &d, &b);
    f1 = ptcl->field30;
    f0 = ((s64) f1 * mgr->mRenderStateEmitter->field20->field0->field30 + 0x800) >> 12;
    switch (mgr->mRenderStateEmitter->field20->field0->field48.field0_28) {
        case 0:
            f0 = ((s64) f0 * ptcl->field34 + 0x800) >> 12;
            f1 = ((s64) f1 * ptcl->field34 + 0x800) >> 12;
            break;
        case 1:
            f0 = ((s64) f0 * ptcl->field34 + 0x800) >> 12;
            break;
        case 2:
            f1 = ((s64) f1 * ptcl->field34 + 0x800) >> 12;
            break;
    }
    MTX_Scale43_(&c, f0, f1, f1);
    MTX_Concat43(&c, &b, &a);
    if (mgr->mRenderStateEmitter->field20->field0->field0.field0_23 == 0) {
        a.field0[3].x = ptcl->field8.x + ptcl->field38.x;
        a.field0[3].y = ptcl->field8.y + ptcl->field38.y;
        a.field0[3].z = ptcl->field8.z + ptcl->field38.z;
        G3_LoadMtx43(mgr->mRenderStateViewMatrix);
        G3_MultMtx43(&a);
    } else {
        a.field0[3].x = ptcl->field8.x + ptcl->field38.x - mgr->mRenderStateEmitter->field20->field0->field4.x;
        a.field0[3].y = ptcl->field8.y + ptcl->field38.y - mgr->mRenderStateEmitter->field20->field0->field4.y;
        a.field0[3].z = ptcl->field8.z + ptcl->field38.z - mgr->mRenderStateEmitter->field20->field0->field4.z;
        reg_G3_MTX_IDENTITY = 0;
        z = mgr->mRenderStateEmitter->field20->field0->field4.z;
        y = mgr->mRenderStateEmitter->field20->field0->field4.y;
        x = mgr->mRenderStateEmitter->field20->field0->field4.x;
        reg_G3_MTX_TRANS = x;
        reg_G3_MTX_TRANS = y;
        reg_G3_MTX_TRANS = z;
        G3_MultMtx43(mgr->mRenderStateViewMatrix);
        G3_MultMtx43(&a);
    }
    c0 = ptcl->field36;
    c1 = mgr->mRenderStateEmitter->field72;
    reg_G3_COLOR = (u16) ((((c0 & 0x1f) * (c1 & 0x1f)) >> 5) | ((((c0 & 0x3e0) * (c1 & 0x3e0)) >> 15) << 5) |
                          ((((c0 & 0x7c00) * (c1 & 0x7c00)) >> 25) << 10));
    data_02161ac0[mgr->mRenderStateEmitter->field20->field0->field0.field0_19](
        mgr->mRenderStateEmitter->field78, mgr->mRenderStateEmitter->field7A,
        mgr->mRenderStateEmitter->field20->field0->field50, mgr->mRenderStateEmitter->field20->field0->field52);
}

void SPLDraw_Child_DirectionalPolygon(SPLManager *mgr, Unk0201e3c8 *ptcl) {
    MtxFx43 a;
    MtxFx43 b;
    MtxFx43 c;
    Vec3 v;
    Vec3 u;
    Vec3 w;
    Vec3 e;
    MtxFx43 d;
    s32 k;
    s32 f0;
    s32 f1;
    s32 s;
    u16 c0;
    u16 c1;
    s32 x;
    s32 y;
    s32 z;

    k = (ptcl->field2E_0 * (ptcl->field2E_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->field2E_10 << 24) | (mgr->mMiscPolygonAttr | 0xc0) | (k << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (k == 0) {
        return;
    }
    data_02161ac8[mgr->mRenderStateEmitter->field20->field14->field0_9](
        gPairsByAngle[(ptcl->field20 >> 4) * 2], gPairsByAngle[(ptcl->field20 >> 4) * 2 + 1], &b);
    MTX_Identity43_(&d);
    if (mgr->mRenderStateEmitter->field20->field14->field10.field0_6 == 0) {
        VEC_Normalize(&ptcl->field14, &v);
    } else {
        VEC_Normalize(&ptcl->field8, &v);
        v.x = -v.x;
        v.y = -v.y;
        v.z = -v.z;
    }
    e.x = 0;
    e.y = 0x1000;
    e.z = 0;
    s = VEC_DotProduct(&v, &e);
    if (s > 0xccd || s < -0xccd) {
        e.x = 0x1000;
        e.y = 0;
        e.z = 0;
    }
    VEC_CrossProduct(&v, &e, &u);
    VEC_CrossProduct(&v, &u, &w);
    d.field0[0].x = u.x;
    d.field0[0].y = u.y;
    d.field0[0].z = u.z;
    d.field0[1].x = v.x;
    d.field0[1].y = v.y;
    d.field0[1].z = v.z;
    d.field0[2].x = w.x;
    d.field0[2].y = w.y;
    d.field0[2].z = w.z;
    MTX_Concat43(&b, &d, &b);
    f1 = ptcl->field30;
    f0 = ((s64) f1 * mgr->mRenderStateEmitter->field20->field0->field30 + 0x800) >> 12;
    switch (mgr->mRenderStateEmitter->field20->field0->field48.field0_28) {
        case 0:
            f0 = ((s64) f0 * ptcl->field34 + 0x800) >> 12;
            f1 = ((s64) f1 * ptcl->field34 + 0x800) >> 12;
            break;
        case 1:
            f0 = ((s64) f0 * ptcl->field34 + 0x800) >> 12;
            break;
        case 2:
            f1 = ((s64) f1 * ptcl->field34 + 0x800) >> 12;
            break;
    }
    MTX_Scale43_(&c, f0, f1, f1);
    MTX_Concat43(&b, &c, &a);
    if (mgr->mRenderStateEmitter->field20->field0->field0.field0_23 == 0) {
        a.field0[3].x = ptcl->field8.x + ptcl->field38.x;
        a.field0[3].y = ptcl->field8.y + ptcl->field38.y;
        a.field0[3].z = ptcl->field8.z + ptcl->field38.z;
        G3_LoadMtx43(mgr->mRenderStateViewMatrix);
        G3_MultMtx43(&a);
    } else {
        a.field0[3].x = ptcl->field8.x + ptcl->field38.x - mgr->mRenderStateEmitter->field20->field0->field4.x;
        a.field0[3].y = ptcl->field8.y + ptcl->field38.y - mgr->mRenderStateEmitter->field20->field0->field4.y;
        a.field0[3].z = ptcl->field8.z + ptcl->field38.z - mgr->mRenderStateEmitter->field20->field0->field4.z;
        reg_G3_MTX_IDENTITY = 0;
        z = mgr->mRenderStateEmitter->field20->field0->field4.z;
        y = mgr->mRenderStateEmitter->field20->field0->field4.y;
        x = mgr->mRenderStateEmitter->field20->field0->field4.x;
        reg_G3_MTX_TRANS = x;
        reg_G3_MTX_TRANS = y;
        reg_G3_MTX_TRANS = z;
        G3_MultMtx43(mgr->mRenderStateViewMatrix);
        G3_MultMtx43(&a);
    }
    c0 = ptcl->field36;
    c1 = mgr->mRenderStateEmitter->field72;
    reg_G3_COLOR = (u16) ((((c0 & 0x1f) * (c1 & 0x1f)) >> 5) | ((((c0 & 0x3e0) * (c1 & 0x3e0)) >> 15) << 5) |
                          ((((c0 & 0x7c00) * (c1 & 0x7c00)) >> 25) << 10));
    data_02161ac0[mgr->mRenderStateEmitter->field20->field14->field0_11](mgr->mRenderStateEmitter->field7C,
                                                                          mgr->mRenderStateEmitter->field7E, 0, 0);
}

typedef enum { UNK_02019DF8_KIND_0 } Unk02019df8_Kind;

static inline void func_02019df8_inline(u32 addr, Unk02019df8_Kind b0, Unk02019df8_Kind b4, Unk02019df8_Kind b8,
                                        Unk02019df8_Kind b12, Unk02019df8_Kind b14, Unk02019df8_Kind b16) {
    reg_G3_TEXIMAGE_PARAM =
        (addr >> 3) | (b0 << 26) | 0x40000000 | (b4 << 20) | (b8 << 23) | (b12 << 16) | (b14 << 18) | (b16 << 29);
}

void SPLUtil_SetTexture(Unk020184e4_2c *tex) {
    Unk020184e4_2c_0c w;
    u32 sx;
    u32 sy;

    w = tex->fieldC;
    func_02019df8_inline(tex->field4, w.field0_0, w.field0_4, w.field0_8, w.field0_12, w.field0_14, w.field0_16);
    reg_G3_PLTT_BASE = tex->field8 >> (4 - (w.field0_0 == 2 ? 1 : 0));
    reg_G3_MTX_MODE = 3;
    reg_G3_MTX_IDENTITY = 0;
    sx = tex->field10 << 12;
    sy = tex->field12 << 12;
    reg_G3_MTX_SCALE = sx;
    reg_G3_MTX_SCALE = sy;
    reg_G3_MTX_SCALE = 0;
    reg_G3_MTX_MODE = 1;
}

void SPLUtil_SetTexture_Stub(Unk020184e4_2c *tex) {}

void SPLEmitter_Init(Unk0201ca6c *emtr, Unk0201ca6c_20 *res, Vec3 *pos) {
    Unk0201ca6c_20_00 *d;

    emtr->field20 = res;
    *(u32 *) &emtr->field24 = 0;
    emtr->field28.x = pos->x + emtr->field20->field0->field4.x;
    emtr->field28.y = pos->y + emtr->field20->field0->field4.y;
    emtr->field28.z = pos->z + emtr->field20->field0->field4.z;
    emtr->field40.x = 0;
    emtr->field40.y = 0;
    emtr->field40.z = 0;
    emtr->field34.x = emtr->field34.y = emtr->field34.z = 0;
    emtr->field4C = 0;
    emtr->field4E = 0;
    d = emtr->field20->field0;
    emtr->field50 = d->field1C;
    emtr->field56 = emtr->field20->field0->field38;
    emtr->field58 = emtr->field20->field0->field10;
    emtr->field5C = emtr->field20->field0->field14;
    emtr->field60 = emtr->field20->field0->field18;
    emtr->field64 = emtr->field20->field0->field24;
    emtr->field68 = emtr->field20->field0->field28;
    emtr->field6C = emtr->field20->field0->field2C;
    emtr->field70 = emtr->field20->field0->field3E;
    emtr->field72 = 0x7fff;
    emtr->field80_0 = emtr->field20->field0->field44;
    emtr->field80_8 = emtr->field20->field0->field45;
    emtr->field80_16 = 0;
    emtr->field80_19 = 0;
    emtr->field74 = 0x80000000;
    emtr->field78 = 0x1000 << emtr->field20->field0->field48.field0_24;
    emtr->field7A = 0x1000 << emtr->field20->field0->field48.field0_26;
    if (emtr->field20->field0->field4C_0) {
        emtr->field78 *= -1;
    }
    if (emtr->field20->field0->field4C_1) {
        emtr->field7A *= -1;
    }
    if (emtr->field20->field0->field0.field0_16) {
        emtr->field7C = 0x1000 << emtr->field20->field14->field10.field0_0;
        emtr->field7E = 0x1000 << emtr->field20->field14->field10.field0_2;
        if (emtr->field20->field14->field10.field0_4) {
            emtr->field7C *= -1;
        }
        if (emtr->field20->field14->field10.field0_5) {
            emtr->field7E *= -1;
        }
    }
    emtr->field0 = emtr->field4 = 0;
    emtr->field8.field0 = emtr->field14.field0 = 0;
    emtr->field8.field4 = emtr->field14.field4 = 0;
    emtr->field90 = 0;
    emtr->field94 = 0;
    emtr->field98 = 0;
}

void SPLEmitter_Update(SPLManager *mgr, Unk0201ca6c *emtr) {
    Unk0201ca6c_20 *c;
    s32 cnt;
    Unk0201e3c8 *n0;
    s32 i;
    s32 n;
    Unk0201e3c8 *next;
    Unk0201ca6c_20_14 *e;
    Unk0201ca6c_20_00 *d;
    Unk0201ca6c_20_00_00 flags;
    s32 k0;
    s32 t;
    u8 b[2];
    Unk020192e0_28 tbl[4];
    Unk020192e0_28 tbl2[4];
    Vec3 v;

    c = emtr->field20;
    e = c->field14;
    d = c->field0;
    flags = d->field0;
    n = 0;
    k0 = d->field46 + 0x180;
    cnt = c->field1C;

    if (emtr->field90) {
        emtr->field90(emtr, 0);
    }

    if (d->field3C == 0 || emtr->field4C < d->field3C) {
        if (emtr->field4C % emtr->field80_0 == 0 && !emtr->field24.field0_0 && !emtr->field24.field0_1 &&
            emtr->field24.field0_4) {
            SPLEmitter_EmitParticles(emtr, &mgr->field4[2]);
        }
    }

    if (flags.field0_8) {
        tbl[n].field0 = SPLAnim_Scale;
        tbl[n++].field4 = c->field4->field8_0;
    }
    if (flags.field0_9 && !c->field8->field8_0) {
        tbl[n].field0 = SPLAnim_Color;
        tbl[n++].field4 = c->field8->field8_1;
    }
    if (flags.field0_10) {
        tbl[n].field0 = SPLAnim_Alpha;
        tbl[n++].field4 = c->fieldC->field2_8;
    }
    if (flags.field0_11 && !c->field10->field8_16) {
        tbl[n].field0 = SPLAnim_Texture;
        tbl[n++].field4 = c->field10->field8_17;
    }

    for (n0 = emtr->field8.field0; n0; n0 = next) {
        next = n0->field0;
        b[0] = (n0->field2A * n0->field26) >> 8;
        b[1] = n0->field2D + ((n0->field28 * n0->field26) >> 8);
        for (i = 0; i < n; i++) {
            tbl[i].field0(n0, c, b[tbl[i].field4]);
        }
        v.x = v.y = v.z = 0;
        if (flags.field0_15) {
            n0->field38 = emtr->field28;
        }
        for (i = 0; i < cnt; i++) {
            c->field18[i].field0(c->field18[i].field4, n0, &v, emtr);
        }
        n0->field20 += n0->field22;
        n0->field14.x = (n0->field14.x * k0) >> 9;
        n0->field14.y = (n0->field14.y * k0) >> 9;
        n0->field14.z = (n0->field14.z * k0) >> 9;
        n0->field14.x += v.x;
        n0->field14.y += v.y;
        n0->field14.z += v.z;
        n0->field8.x += n0->field14.x + emtr->field34.x;
        n0->field8.y += n0->field14.y + emtr->field34.y;
        n0->field8.z += n0->field14.z + emtr->field34.z;
        if (flags.field0_16) {
            t = (n0->field26 << 12) - ((s32) (((s64) (n0->field24 << 12) * (e->fieldD << 12) + 0x800) >> 12) >> 8);
            if (t >= 0 && (t >> 12) % e->fieldE == 0) {
                SPLEmitter_EmitChildren(n0, emtr, &mgr->field4[2]);
            }
        }
        if (emtr->field20->field0->field0.field0_30) {
            n0->field2E_10 = mgr->mPolygonIDFix;
        } else {
            n0->field2E_10 = mgr->mPolygonIDCurrent;
            mgr->mPolygonIDCurrent++;
            if (mgr->mPolygonIDCurrent > mgr->mPolygonIDMax) {
                mgr->mPolygonIDCurrent = mgr->mPolygonIDMin;
            }
        }
        n0->field26++;
        if (n0->field26 > n0->field24) {
            SPLList_PushFront(&mgr->field4[2], SPLList_Erase(&emtr->field8, n0));
        }
    }

    if (flags.field0_16) {
        n = 0;
        if (e->field0_1) {
            tbl2[n].field0 = SPLAnim_ChildScale;
            tbl2[n++].field4 = 0;
        }
        if (e->field0_2) {
            tbl2[n].field0 = SPLAnim_ChildAlpha;
            tbl2[n++].field4 = 0;
        }
        if (!e->field0_0) {
            cnt = 0;
        }
        for (n0 = emtr->field14.field0; n0; n0 = next) {
            next = n0->field0;
            b[0] = (n0->field26 << 8) / n0->field24;
            for (i = 0; i < n; i++) {
                tbl2[i].field0(n0, c, b[0]);
            }
            v.x = v.y = v.z = 0;
            if (e->field0_5) {
                n0->field38 = emtr->field28;
            }
            for (i = 0; i < cnt; i++) {
                c->field18[i].field0(c->field18[i].field4, n0, &v, emtr);
            }
            n0->field20 += n0->field22;
            n0->field14.x = (n0->field14.x * k0) >> 9;
            n0->field14.y = (n0->field14.y * k0) >> 9;
            n0->field14.z = (n0->field14.z * k0) >> 9;
            n0->field14.x += v.x;
            n0->field14.y += v.y;
            n0->field14.z += v.z;
            n0->field8.x += n0->field14.x + emtr->field34.x;
            n0->field8.y += n0->field14.y + emtr->field34.y;
            n0->field8.z += n0->field14.z + emtr->field34.z;
            if (emtr->field20->field0->field0.field0_31) {
                n0->field2E_10 = mgr->mPolygonIDFix;
            } else {
                n0->field2E_10 = mgr->mPolygonIDCurrent;
                mgr->mPolygonIDCurrent++;
                if (mgr->mPolygonIDCurrent > mgr->mPolygonIDMax) {
                    mgr->mPolygonIDCurrent = mgr->mPolygonIDMin;
                }
            }
            n0->field26++;
            if (n0->field26 > n0->field24) {
                SPLList_PushFront(&mgr->field4[2], SPLList_Erase(&emtr->field14, n0));
            }
        }
    }

    emtr->field4C++;
    if (emtr->field90) {
        emtr->field90(emtr, 1);
    }
}

void SPLManager_DrawParticles(SPLManager *mgr) {
    Unk0201ca6c *n;
    Unk0201ca6c_20_00 *d;
    void (*f)(SPLManager *mgr, Unk0201e3c8 *b);
    void (*g)(Unk020184e4_2c *mgr);
    Unk0201e3c8 *e;

    n = mgr->mRenderStateEmitter;
    d = n->field20->field0;
    f = 0;
    SPLUtil_SetTexture(mgr->mTextures + d->field47);
    switch (d->field0.field0_4) {
        case 0:
            f = SPLDraw_Billboard;
            break;
        case 1:
            f = SPLDraw_DirectionalBillboard;
            break;
        case 2:
            f = SPLDraw_Polygon;
            break;
        case 3:
            f = SPLDraw_DirectionalPolygon;
            break;
        case 4:
            f = SPLDraw_DirectionalPolygon;
            break;
    }
    if (d->field0.field0_11) {
        g = SPLUtil_SetTexture;
    } else {
        g = SPLUtil_SetTexture_Stub;
    }
    for (e = n->field8.field0; e != 0; e = e->field0) {
        g(mgr->mTextures + e->field2C);
        f(mgr, e);
    }
}

void SPLManager_DrawChildParticles(SPLManager *mgr) {
    Unk0201ca6c *n;
    Unk0201ca6c_20 *c;
    void (*f)(SPLManager *mgr, Unk0201e3c8 *b);
    Unk0201e3c8 *e;

    n = mgr->mRenderStateEmitter;
    f = 0;
    c = n->field20;
    if (c->field0->field0.field0_16 == 0) {
        return;
    }
    SPLUtil_SetTexture(mgr->mTextures + c->field14->fieldF);
    switch (c->field14->field0_7) {
        case 0:
            f = SPLDraw_Child_Billboard;
            break;
        case 1:
            f = SPLDraw_Child_DirectionalBillboard;
            break;
        case 2:
            f = SPLDraw_Child_Polygon;
            break;
        case 3:
            f = SPLDraw_Child_DirectionalPolygon;
            break;
        case 4:
            f = SPLDraw_Child_DirectionalPolygon;
            break;
    }
    for (e = n->field14.field0; e != 0; e = e->field0) {
        f(mgr, e);
    }
}

void SPLManager_DoDraw(SPLManager *mgr) {
    Unk0201ca6c_20_00 *d;

    d = mgr->mRenderStateEmitter->field20->field0;
    if (d->field0.field0_21) {
        SPLManager_DrawChildParticles(mgr);
        if (d->field0.field0_22) {
            return;
        }
        SPLManager_DrawParticles(mgr);
    } else {
        if (d->field0.field0_22 == 0) {
            SPLManager_DrawParticles(mgr);
        }
        SPLManager_DrawChildParticles(mgr);
    }
}

void SPLUtil_SetCylinderEmitterDir(Unk0201ca6c *emtr, Vec3 *p1, Vec3 *p2) {
    Vec3 dir;

    if (emtr->field20->field0->field0.field0_0 - 6 > 1) {
        return;
    }
    emtr->field28.x = (p2->x + p1->x) / 2;
    emtr->field28.y = (p2->y + p1->y) / 2;
    emtr->field28.z = (p2->z + p1->z) / 2;
    emtr->field60 = VEC_Distance(p1, p2) / 2;
    dir.x = p2->x - p1->x;
    dir.y = p2->y - p1->y;
    dir.z = p2->z - p1->z;
    VEC_Normalize(&dir, &dir);
    emtr->field50.x = dir.x;
    emtr->field50.y = dir.y;
    emtr->field50.z = dir.z;
}

u32 SPLUtil_AllocTextureVRAM(s32 size, s32 is4x4) {
    return (data_021619ec(size, is4x4, 0) & 0xffff) << 3;
}

u32 SPLUtil_AllocPaletteVRAM(s32 size, s32 is4Pltt) {
    return (data_021619f4(size, is4Pltt, 0) & 0xffff) << 3;
}

SPLManager *SPLManager_New(void *(*alloc)(u32 size), u16 maxEmitters, u16 maxParticles, s32 fixPolyId, u16 minPolyId,
                           u16 maxPolyId) {
    SPLManager *mgr;
    s32 i;
    u8 *block;

    mgr = alloc(0x4c);
    MI_CpuFill8(mgr, 0, 0x4c);
    mgr->mMaxEmitters = maxEmitters;
    mgr->mMaxParticles = maxParticles;
    mgr->mPolygonIDMin = minPolyId;
    mgr->mPolygonIDMax = maxPolyId;
    mgr->mPolygonIDCurrent = mgr->mPolygonIDMin;
    mgr->mPolygonIDFix = fixPolyId;
    mgr->mPolygonIDDrawOrder = 0;
    mgr->field38_25 = 0;
    mgr->mAlloc = alloc;
    mgr->field4[0].field4 = 0;
    mgr->field4[1].field4 = 0;
    mgr->field4[2].field4 = 0;
    mgr->field4[0].field0 = 0;
    mgr->field4[1].field0 = 0;
    mgr->field4[2].field0 = 0;
    mgr->mMiscPolygonAttr = 0;
    mgr->mCurrentCycle = 0;
    block = alloc(maxEmitters * 0x9c);
    MI_CpuFill8(block, 0, maxEmitters * 0x9c);
    for (i = 0; i < maxEmitters; i++) {
        SPLList_PushFront(&mgr->field4[1], (Unk0201e3c8 *) block);
        block += 0x9c;
    }
    block = alloc(maxParticles * 0x44);
    MI_CpuFill8(block, 0, maxParticles * 0x44);
    for (i = 0; i < maxParticles; i++) {
        SPLList_PushFront(&mgr->field4[2], (Unk0201e3c8 *) block);
        block += 0x44;
    }
    mgr->mResources = 0;
    mgr->mTextures = 0;
    mgr->mTexCount = 0;
    mgr->mResCount = mgr->mTexCount;
    return mgr;
}

void SPLManager_LoadResources(SPLManager *mgr, Unk02018a1c *data) {
    s32 i;
    s32 off;
    Unk0201ca6c_20 *e;
    Unk0201ca6c_20_00_00 flags;
    Unk0201ca6c_20_18 *g;
    Unk020184e4_2c *h;
    Unk020184e4_2c_00 *d;

    off = 0x20;
    mgr->mResCount = data->field8;
    mgr->mTexCount = data->fieldA;
    mgr->mResources = mgr->mAlloc(mgr->mResCount << 5);
    MI_CpuFill8(mgr->mResources, 0, mgr->mResCount << 5);
    for (i = 0; i < mgr->mResCount; i++) {
        e = mgr->mResources + i;
        e->field0 = OFFSET_PTR(Unk0201ca6c_20_00, data, off);
        off += 0x58;
        flags = e->field0->field0;
        if (flags.field0_8) {
            e->field4 = OFFSET_PTR(Unk0201ca6c_20_04, data, off);
            off += 0xc;
        } else {
            e->field4 = 0;
        }
        if (flags.field0_9) {
            e->field8 = OFFSET_PTR(Unk0201ca6c_20_08, data, off);
            off += 0xc;
        } else {
            e->field8 = 0;
        }
        if (flags.field0_10) {
            e->fieldC = OFFSET_PTR(Unk0201ca6c_20_0c, data, off);
            off += 8;
        } else {
            e->fieldC = 0;
        }
        if (flags.field0_11) {
            e->field10 = OFFSET_PTR(Unk0201ca6c_20_10, data, off);
            off += 0xc;
        } else {
            e->field10 = 0;
        }
        if (flags.field0_16) {
            e->field14 = OFFSET_PTR(Unk0201ca6c_20_14, data, off);
            off += 0x14;
        } else {
            e->field14 = 0;
        }
        e->field1C = flags.field0_24 + flags.field0_25 + flags.field0_26 + flags.field0_27 + flags.field0_28 +
                     flags.field0_29;
        if (e->field1C != 0) {
            e->field18 = mgr->mAlloc(e->field1C << 3);
            g = e->field18;
            if (flags.field0_24) {
                g->field4 = (u8 *) data + off;
                g->field0 = SPLBehavior_ApplyGravity;
                off += 8;
                g++;
            }
            if (flags.field0_25) {
                g->field4 = (u8 *) data + off;
                g->field0 = SPLBehavior_ApplyRandom;
                off += 8;
                g++;
            }
            if (flags.field0_26) {
                g->field4 = (u8 *) data + off;
                g->field0 = SPLBehavior_ApplyMagnet;
                off += 0x10;
                g++;
            }
            if (flags.field0_27) {
                g->field4 = (u8 *) data + off;
                g->field0 = SPLBehavior_ApplySpin;
                off += 4;
                g++;
            }
            if (flags.field0_28) {
                g->field4 = (u8 *) data + off;
                g->field0 = SPLBehavior_ApplyCollisionPlane;
                off += 8;
                g++;
            }
            if (flags.field0_29) {
                g->field4 = (u8 *) data + off;
                g->field0 = SPLBehavior_ApplyConvergence;
                off += 0x10;
            }
        } else {
            e->field18 = 0;
        }
    }
    mgr->mTextures = mgr->mAlloc(mgr->mTexCount * 0x14);
    MI_CpuFill8(mgr->mTextures, 0, mgr->mTexCount * 0x14);
    for (i = 0; i < mgr->mTexCount; i++) {
        h = mgr->mTextures + i;
        d = OFFSET_PTR(Unk020184e4_2c_00, data, off);
        h->field0 = d;
        h->field10 = 1 << (d->field4.field0_4 + 3);
        h->field12 = 1 << (d->field4.field0_8 + 3);
        h->fieldC = d->field4;
        off += d->field1C;
    }
}

s32 SPLManager_UploadTexturesEx(SPLManager *mgr, u32 (*vramAlloc)(s32 size, s32 isSpecial)) {
    s32 i;
    Unk020184e4_2c *e;
    Unk020184e4_2c_00 *d;
    u32 t;

    GX_BeginLoadTex();
    for (i = 0; i < mgr->mTexCount; i++) {
        e = mgr->mTextures + i;
        d = e->field0;
        if (d->field4.field0_17) {
            e->field4 = mgr->mTextures[d->field4.field0_18].field4;
        } else {
            t = vramAlloc(d->field8, d->field4.field0_0 == 5 ? 1 : 0);
            GX_LoadTex((u8 *) e->field0 + 0x20, t, d->field8);
            e->field4 = t;
        }
    }
    GX_EndLoadTex();
    return 1;
}

s32 SPLManager_UploadPalettesEx(SPLManager *mgr, u32 (*vramAlloc)(s32 size, s32 isSpecial)) {
    s32 i;
    Unk020184e4_2c *e;
    Unk020184e4_2c_00 *d;
    u32 t;

    GX_BeginLoadTexPltt();
    for (i = 0; i < mgr->mTexCount; i++) {
        e = mgr->mTextures + i;
        d = e->field0;
        t = 0;
        if (d->field10 != 0) {
            t = vramAlloc(d->field10, d->field4.field0_0 == 2 ? 1 : 0);
            GX_LoadTexPltt((u8 *) e->field0 + d->fieldC, t, d->field10);
        }
        e->field8 = t;
    }
    GX_EndLoadTexPltt();
    return 1;
}

s32 SPLManager_UploadTextures(SPLManager *mgr) {
    return SPLManager_UploadTexturesEx(mgr, SPLUtil_AllocTextureVRAM);
}

s32 SPLManager_UploadPalettes(SPLManager *mgr) {
    return SPLManager_UploadPalettesEx(mgr, SPLUtil_AllocPaletteVRAM);
}

void SPLManager_Update(SPLManager *mgr) {
    Unk0201ca6c *emtr;
    Unk0201ca6c *next;
    Unk0201ca6c_20_00 *header;

    for (emtr = (Unk0201ca6c *) mgr->field4[0].field0; emtr != 0; emtr = next) {
        header = emtr->field20->field0;
        next = emtr->field0;
        if (emtr->field24.field0_4 == 0) {
            if (emtr->field4C >= header->field32) {
                emtr->field24.field0_4 = 1;
                emtr->field4C = 0;
            }
        }
        if (emtr->field24.field0_2 == 0) {
            if (emtr->field80_16 == 0 || mgr->mCurrentCycle == emtr->field80_16 - 1) {
                SPLEmitter_Update(mgr, emtr);
            }
        }
        if ((header->field0.field0_14 && header->field3C != 0 && emtr->field24.field0_4 != 0 &&
             emtr->field4C > header->field3C) ||
            emtr->field24.field0_0 != 0) {
            if (emtr->field8.field4 == 0 && emtr->field14.field4 == 0) {
                SPLList_PushFront(&mgr->field4[1], SPLList_Erase(&mgr->field4[0], (Unk0201e3c8 *) emtr));
            }
        }
    }
    mgr->mCurrentCycle++;
    if (mgr->mCurrentCycle > 1) {
        mgr->mCurrentCycle = 0;
    }
}

void SPLManager_Draw(SPLManager *mgr, MtxFx43 *viewMatrix) {
    Unk0201ca6c *emtr;

    reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 8;
    mgr->mRenderStateViewMatrix = viewMatrix;
    if (mgr->mPolygonIDDrawOrder == 0) {
        for (emtr = (Unk0201ca6c *) mgr->field4[0].field0; emtr != 0; emtr = emtr->field0) {
            mgr->mRenderStateEmitter = emtr;
            if (emtr->field24.field0_3 == 0) {
                SPLManager_DoDraw(mgr);
            }
        }
    } else {
        for (emtr = (Unk0201ca6c *) mgr->field4[0].field8; emtr != 0; emtr = emtr->field4) {
            mgr->mRenderStateEmitter = emtr;
            if (emtr->field24.field0_3 == 0) {
                SPLManager_DoDraw(mgr);
            }
        }
    }
}

Unk0201ca6c *SPLManager_CreateEmitter(SPLManager *mgr, s32 resourceId, Vec3 *pos) {
    Unk0201ca6c *emtr;

    emtr = 0;
    if (mgr->field4[1].field0 != 0) {
        emtr = (Unk0201ca6c *) SPLList_PopFront(&mgr->field4[1]);
        SPLEmitter_Init(emtr, mgr->mResources + resourceId, pos);
        SPLList_PushFront(&mgr->field4[0], (Unk0201e3c8 *) emtr);
        if (emtr->field20->field0->field0.field0_14) {
            emtr = 0;
        }
    }
    return emtr;
}

Unk0201ca6c *SPLManager_CreateEmitterWithCallbackEx(SPLManager *mgr, s32 resourceId, Vec3 *pos, s32 param,
                                                    void (*initCallback)(Unk0201ca6c *emtr, s32 param)) {
    Unk0201ca6c *emtr;

    emtr = 0;
    if (mgr->field4[1].field0 != 0) {
        emtr = (Unk0201ca6c *) SPLList_PopFront(&mgr->field4[1]);
        SPLEmitter_Init(emtr, mgr->mResources + resourceId, pos);
        if (initCallback != 0) {
            initCallback(emtr, param);
        }
        SPLList_PushFront(&mgr->field4[0], (Unk0201e3c8 *) emtr);
        if (emtr->field20->field0->field0.field0_14) {
            emtr = 0;
        }
    }
    return emtr;
}

void SPLManager_DeleteEmitter(SPLManager *mgr, Unk0201ca6c *emtr) {
    Unk0201e3c8 *particle;

    while ((particle = SPLList_PopFront(&emtr->field8)) != 0) {
        SPLList_PushFront(&mgr->field4[2], particle);
    }
    while ((particle = SPLList_PopFront(&emtr->field14)) != 0) {
        SPLList_PushFront(&mgr->field4[2], particle);
    }
    SPLList_Erase(&mgr->field4[0], (Unk0201e3c8 *) emtr);
    SPLList_PushFront(&mgr->field4[1], (Unk0201e3c8 *) emtr);
}
