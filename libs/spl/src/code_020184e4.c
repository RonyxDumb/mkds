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
    vec->x = (s32) (gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 8;
    vec->y = (s32) (gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 8;
    vec->z = (s32) (gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 8;
    VEC_Normalize(vec, vec);
}

void SPLRandom_VecFx32_XY(Vec3 *vec) {
    vec->x = (s32) (gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 8;
    vec->y = (s32) (gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 8;
    vec->z = 0;
    VEC_Normalize(vec, vec);
}

void SPLList_PushFront(Unk0201e494 *list, Unk0201e3c8 *node) {
    if (list->mUnk_00 == 0) {
        list->mUnk_00 = node;
        list->mUnk_08 = node;
        node->mUnk_00 = 0;
        node->mUnk_04 = node->mUnk_00;
    } else {
        node->mUnk_00 = list->mUnk_00;
        node->mUnk_04 = 0;
        list->mUnk_00->mUnk_04 = node;
        list->mUnk_00 = node;
    }
    list->mUnk_04++;
}

Unk0201e3c8 *SPLList_PopFront(Unk0201e494 *list) {
    Unk0201e3c8 *first;
    Unk0201e3c8 *node;

    node = 0;
    first = list->mUnk_00;
    if (first != 0) {
        node = first;
        list->mUnk_00 = first->mUnk_00;
        if (list->mUnk_00 != 0) {
            first->mUnk_00->mUnk_04 = 0;
        } else {
            list->mUnk_00 = 0;
            list->mUnk_08 = 0;
        }
        list->mUnk_04--;
    }
    return node;
}

Unk0201e3c8 *SPLList_Erase(Unk0201e494 *list, Unk0201e3c8 *node) {
    Unk0201e3c8 *next;

    next = node->mUnk_00;
    if (next == 0) {
        if (list->mUnk_00 == node) {
            list->mUnk_00 = 0;
            list->mUnk_08 = 0;
        } else {
            node->mUnk_04->mUnk_00 = 0;
            list->mUnk_08 = list->mUnk_08->mUnk_04;
        }
    } else {
        if (list->mUnk_00 == node) {
            list->mUnk_00 = next;
            list->mUnk_00->mUnk_04 = 0;
        } else {
            next->mUnk_04 = node->mUnk_04;
            node->mUnk_04->mUnk_00 = node->mUnk_00;
        }
    }
    list->mUnk_04--;
    return node;
}

void SPLBehavior_ApplyGravity(const Vec3s16 *gravity, Unk0201e3c8 *ptcl, Vec3 *acc, Unk0201ca6c *emtr) {
    acc->x = acc->x + gravity->x;
    acc->y = acc->y + gravity->y;
    acc->z = acc->z + gravity->z;
}

void SPLBehavior_ApplyRandom(const Unk0201e2cc *rng, Unk0201e3c8 *ptcl, Vec3 *acc, Unk0201ca6c *emtr) {
    if (ptcl->mUnk_26 % rng->mUnk_06 != 0) {
        return;
    }
    acc->x = acc->x + ((rng->mUnk_00 * (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) -
                        (rng->mUnk_00 << 8)) >>
                       8);
    acc->y = acc->y + ((rng->mUnk_02 * (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) -
                        (rng->mUnk_02 << 8)) >>
                       8);
    acc->z = acc->z + ((rng->mUnk_04 * (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) -
                        (rng->mUnk_04 << 8)) >>
                       8);
}

void SPLBehavior_ApplyMagnet(const Unk0201e248 *magnet, Unk0201e3c8 *ptcl, Vec3 *acc, Unk0201ca6c *emtr) {
    acc->x = acc->x + ((magnet->mUnk_0c * (magnet->mUnk_00.x - ptcl->mUnk_08.x - ptcl->mUnk_14.x)) >> 12);
    acc->y = acc->y + ((magnet->mUnk_0c * (magnet->mUnk_00.y - ptcl->mUnk_08.y - ptcl->mUnk_14.y)) >> 12);
    acc->z = acc->z + ((magnet->mUnk_0c * (magnet->mUnk_00.z - ptcl->mUnk_08.z - ptcl->mUnk_14.z)) >> 12);
}

void SPLBehavior_ApplySpin(const Unk0201e170 *spin, Unk0201e3c8 *ptcl, Vec3 *acc, Unk0201ca6c *emtr) {
    MtxFx33 buf;

    switch (spin->mUnk_02) {
        case 0:
            MTX_RotX33_(&buf, FX_SinIdx(spin->mUnk_00), FX_CosIdx(spin->mUnk_00));
            break;
        case 1:
            MTX_RotY33_(&buf, FX_SinIdx(spin->mUnk_00), FX_CosIdx(spin->mUnk_00));
            break;
        case 2:
            MTX_RotZ33_(&buf, FX_SinIdx(spin->mUnk_00), FX_CosIdx(spin->mUnk_00));
            break;
    }
    MTX_MultVec33(&ptcl->mUnk_08, &buf, &ptcl->mUnk_08);
}

void SPLBehavior_ApplyCollisionPlane(const Unk0201e054 *plane, Unk0201e3c8 *ptcl, Vec3 *acc, Unk0201ca6c *emtr) {
    s32 lim;
    s32 particleY;

    lim = plane->mUnk_00;
    if (emtr->mUnk_74 != 0x80000000) {
        lim = emtr->mUnk_74;
    }
    switch (plane->mUnk_06_0) {
        case 0:
            particleY = ptcl->mUnk_38.y;
            if (particleY < lim) {
                if (particleY + ptcl->mUnk_08.y > lim) {
                    ptcl->mUnk_08.y = lim - particleY;
                    ptcl->mUnk_26 = ptcl->mUnk_24;
                    return;
                }
            }
            if (particleY >= lim) {
                if (particleY + ptcl->mUnk_08.y < lim) {
                    ptcl->mUnk_08.y = lim - particleY;
                    ptcl->mUnk_26 = ptcl->mUnk_24;
                }
            }
            break;
        case 1:
            particleY = ptcl->mUnk_38.y;
            if (particleY < lim && particleY + ptcl->mUnk_08.y > lim) {
                ptcl->mUnk_08.y = lim - particleY;
                ptcl->mUnk_14.y = -MUL_FIXED12_ROUNDED(ptcl->mUnk_14.y, plane->mUnk_04);
            } else if (particleY >= lim && particleY + ptcl->mUnk_08.y < lim) {
                ptcl->mUnk_08.y = lim - particleY;
                ptcl->mUnk_14.y = -MUL_FIXED12_ROUNDED(ptcl->mUnk_14.y, plane->mUnk_04);
            }
            break;
    }
}

void SPLBehavior_ApplyConvergence(const Unk0201e248 *conv, Unk0201e3c8 *ptcl, Vec3 *acc, Unk0201ca6c *emtr) {
    ptcl->mUnk_08.x = ptcl->mUnk_08.x + MUL_FIXED12_ROUNDED(conv->mUnk_0c, conv->mUnk_00.x - ptcl->mUnk_08.x);
    ptcl->mUnk_08.y = ptcl->mUnk_08.y + MUL_FIXED12_ROUNDED(conv->mUnk_0c, conv->mUnk_00.y - ptcl->mUnk_08.y);
    ptcl->mUnk_08.z = ptcl->mUnk_08.z + MUL_FIXED12_ROUNDED(conv->mUnk_0c, conv->mUnk_00.z - ptcl->mUnk_08.z);
}

void SPLAnim_Scale(Unk0201e3c8 *ptcl, Unk0201ca6c_20 *res, s32 lifeRate) {
    Unk0201ca6c_20_04 *scaleAnim;
    s32 scale;
    s32 lo;
    s32 hi;

    scaleAnim = res->mUnk_04;
    lo = scaleAnim->mUnk_06;
    hi = scaleAnim->mUnk_07;
    if (lifeRate < lo) {
        scale = scaleAnim->mUnk_00;
        ptcl->mUnk_34 = scale + (lifeRate * (scaleAnim->mUnk_02 - scale)) / lo;
        return;
    }
    if (lifeRate < hi) {
        ptcl->mUnk_34 = scaleAnim->mUnk_02;
        return;
    }
    scale = scaleAnim->mUnk_04;
    ptcl->mUnk_34 = scale + ((lifeRate - 0xff) * (scale - scaleAnim->mUnk_02)) / (0xff - hi);
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
    s32 elapsed;
    s32 span;

    colorAnim = res->mUnk_08;
    header = res->mUnk_00;
    lo = colorAnim->mUnk_04;
    mid = colorAnim->mUnk_05;
    hi = colorAnim->mUnk_06;
    if (lifeRate < lo) {
        ptcl->mUnk_36 = colorAnim->mUnk_00;
        return;
    }
    if (lifeRate < mid) {
        ar = colorAnim->mUnk_00 & 0x1f;
        ag = (colorAnim->mUnk_00 >> 5) & 0x1f;
        ab = (colorAnim->mUnk_00 >> 10) & 0x1f;
        br = header->mUnk_22 & 0x1f;
        bg = (header->mUnk_22 >> 5) & 0x1f;
        bb = (header->mUnk_22 >> 10) & 0x1f;
        if (colorAnim->mUnk_08_2 == 0) {
            ptcl->mUnk_36 = br | (bg << 5) | (bb << 10);
            return;
        }
        elapsed = lifeRate - lo;
        span = mid - lo;
        ptcl->mUnk_36 = (ar + (elapsed * (br - ar)) / span) | ((ag + (elapsed * (bg - ag)) / span) << 5) |
                        ((ab + (elapsed * (bb - ab)) / span) << 10);
        return;
    }
    if (lifeRate < hi) {
        s32 cb; // PERM
        s32 er; // PERM
        s32 cr; // PERM
        s32 eg; // PERM
        s32 cg; // PERM
        s32 eb; // PERM
        er = header->mUnk_22 & 0x1f;
        eg = (header->mUnk_22 >> 5) & 0x1f;
        eb = (header->mUnk_22 >> 10) & 0x1f;
        cr = colorAnim->mUnk_02 & 0x1f;
        cg = (colorAnim->mUnk_02 >> 5) & 0x1f;
        cb = (colorAnim->mUnk_02 >> 10) & 0x1f;
        if (colorAnim->mUnk_08_2 == 0) {
            ptcl->mUnk_36 = cr | (cg << 5) | (cb << 10);
            return;
        }
        elapsed = lifeRate - mid;
        span = hi - mid;
        ptcl->mUnk_36 = (er + (elapsed * (cr - er)) / span) | ((eg + (elapsed * (cg - eg)) / span) << 5) |
                        ((eb + (elapsed * (cb - eb)) / span) << 10);
        return;
    }
    ptcl->mUnk_36 = colorAnim->mUnk_02;
}

void SPLAnim_Alpha(Unk0201e3c8 *ptcl, Unk0201ca6c_20 *res, s32 lifeRate) {
    Unk0201ca6c_20_0c *alphaAnim;
    s32 alpha;
    s32 lo;
    s32 hi;

    alphaAnim = res->mUnk_0c;
    lo = alphaAnim->mUnk_04;
    hi = alphaAnim->mUnk_05;
    if (lifeRate < lo) {
        alpha = alphaAnim->mUnk_00_0 + (lifeRate * (alphaAnim->mUnk_00_5 - alphaAnim->mUnk_00_0)) / lo;
    } else if (lifeRate < hi) {
        alpha = alphaAnim->mUnk_00_5;
    } else {
        alpha =
            alphaAnim->mUnk_00_10 + ((lifeRate - 0xff) * (alphaAnim->mUnk_00_10 - alphaAnim->mUnk_00_5)) / (0xff - hi);
    }
    ptcl->mUnk_2e_5 = (alpha * (0xff - ((alphaAnim->mUnk_02_0 *
                                         (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 24)) >>
                                        8))) >>
                      8;
}

void SPLAnim_Texture(Unk0201e3c8 *ptcl, Unk0201ca6c_20 *res, s32 lifeRate) {
    Unk0201ca6c_20_10 *texAnim;
    s32 frameIndex;
    s32 frameEnd;
    s32 frameLength;
    s32 frameCount;

    texAnim = res->mUnk_10;
    frameIndex = 0;
    frameCount = texAnim->mUnk_08_0;
    if (frameCount <= 0) {
        return;
    }
    frameLength = texAnim->mUnk_08_8;
    frameEnd = 0;
    do {
        if (lifeRate < frameEnd + frameLength) {
            ptcl->mUnk_2c = texAnim->mUnk_00[frameIndex];
            return;
        }
        frameEnd += texAnim->mUnk_08_8;
        frameIndex++;
    } while (frameIndex < frameCount);
}

void SPLAnim_ChildScale(Unk0201e3c8 *ptcl, Unk0201ca6c_20 *res, s32 lifeRate) {
    s32 scale;

    scale = res->mUnk_14->mUnk_04;
    ptcl->mUnk_34 = scale + ((scale - 0x1000) * (lifeRate - 0xff)) / 0xff;
}

void SPLAnim_ChildAlpha(Unk0201e3c8 *ptcl, Unk0201ca6c_20 *res, s32 lifeRate) {
    ptcl->mUnk_2e_5 = ((0xff - lifeRate) * 0x1f) / 0xff;
}

void SPLEmitter_ComputeOrthogonalAxes(Unk0201ca6c *emtr) {
    Vec3s16 up;
    Vec3s16 axis;
    s32 dot;

    up = data_02161ad0;
    switch (emtr->mUnk_20->mUnk_00->mUnk_00.mUnk_00_6) {
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
            VEC_Fx16Normalize(&emtr->mUnk_50, &axis);
            break;
    }
    dot = VEC_Fx16DotProduct(&up, &axis);
    if (dot == 0x1000 || dot == -0x1000) {
        up.x = 0x1000;
        up.y = 0;
        up.z = 0;
    }
    emtr->mUnk_84.x = MUL_FIXED12_ROUNDED(axis.y, up.z) - MUL_FIXED12_ROUNDED(axis.z, up.y);
    emtr->mUnk_84.y = MUL_FIXED12_ROUNDED(axis.z, up.x) - MUL_FIXED12_ROUNDED(axis.x, up.z);
    emtr->mUnk_84.z = MUL_FIXED12_ROUNDED(axis.x, up.y) - MUL_FIXED12_ROUNDED(axis.y, up.x);
    emtr->mUnk_8a.x = MUL_FIXED12_ROUNDED(axis.y, emtr->mUnk_84.z) - MUL_FIXED12_ROUNDED(axis.z, emtr->mUnk_84.y);
    emtr->mUnk_8a.y = MUL_FIXED12_ROUNDED(axis.z, emtr->mUnk_84.x) - MUL_FIXED12_ROUNDED(axis.x, emtr->mUnk_84.z);
    emtr->mUnk_8a.z = MUL_FIXED12_ROUNDED(axis.x, emtr->mUnk_84.y) - MUL_FIXED12_ROUNDED(axis.y, emtr->mUnk_84.x);
    VEC_Fx16Normalize(&emtr->mUnk_84, &emtr->mUnk_84);
    VEC_Fx16Normalize(&emtr->mUnk_8a, &emtr->mUnk_8a);
}

void SPLUtil_TiltCoordinates(Vec3 *ptclPos, const Vec3 *pos, Unk0201ca6c *emtr) {
    Vec3s16 cross;

    VEC_Fx16CrossProduct(&emtr->mUnk_84, &emtr->mUnk_8a, &cross);
    VEC_Fx16Normalize(&cross, &cross);
    ptclPos->x = MUL_FIXED12_ROUNDED(pos->z, cross.x) +
                 (MUL_FIXED12_ROUNDED(pos->x, emtr->mUnk_84.x) + MUL_FIXED12_ROUNDED(pos->y, emtr->mUnk_8a.x));
    ptclPos->y = MUL_FIXED12_ROUNDED(pos->z, cross.y) +
                 (MUL_FIXED12_ROUNDED(pos->x, emtr->mUnk_84.y) + MUL_FIXED12_ROUNDED(pos->y, emtr->mUnk_8a.y));
    ptclPos->z = MUL_FIXED12_ROUNDED(pos->z, cross.z) +
                 (MUL_FIXED12_ROUNDED(pos->x, emtr->mUnk_84.z) + MUL_FIXED12_ROUNDED(pos->y, emtr->mUnk_8a.z));
}

void SPLEmitter_EmitParticles(Unk0201ca6c *emtr, Unk0201e494 *list) {
    Unk0201ca6c_20 *resource;
    Unk0201ca6c_20_00 *header;
    Unk0201e3c8 *particle;
    s32 emitIndex;
    s32 emitCount;
    s32 emitTotal;
    s32 directionSpeed;
    s32 axisSpeed;
    s32 acc;
    Vec3 offset2;
    Vec3 offset3;
    Vec3 offset5;
    Vec3s16 normalFx16A;
    Vec3 normalA;
    Vec3s16 normalFx16B;
    Vec3 normalB;
    Vec3 offset6;
    Vec3 offset7;
    u16 colorChoices[3];
    Vec3 direction;
    Vec3 tiltedOffset;

    resource = emtr->mUnk_20;
    emitTotal = emtr->mUnk_58 + emtr->mUnk_4e;
    header = resource->mUnk_00;
    emtr->mUnk_4e = emitTotal & 0xfff;
    emitCount = emitTotal >> 12;
    if (header->mUnk_00.mUnk_00_0 == 2 || header->mUnk_00.mUnk_00_0 == 3 || header->mUnk_00.mUnk_00_0 == 5 ||
        header->mUnk_00.mUnk_00_0 == 6 || header->mUnk_00.mUnk_00_0 == 7 || header->mUnk_00.mUnk_00_0 == 8 ||
        header->mUnk_00.mUnk_00_0 == 9) {
        SPLEmitter_ComputeOrthogonalAxes(emtr);
    }
    emitIndex = 0;
    if (emitIndex < emitCount) {
        acc = 0;
        do {
            particle = SPLList_PopFront(list);
            if (particle == 0) {
                return;
            }
            SPLList_PushFront(&emtr->mUnk_08, particle);
            switch (header->mUnk_00.mUnk_00_0) {
                case 0:
                    particle->mUnk_08.x = particle->mUnk_08.y = particle->mUnk_08.z = 0;
                    break;
                case 1:
                    SPLRandom_VecFx32(&particle->mUnk_08);
                    particle->mUnk_08.x = MUL_FIXED12_ROUNDED(particle->mUnk_08.x, emtr->mUnk_5c);
                    particle->mUnk_08.y = MUL_FIXED12_ROUNDED(particle->mUnk_08.y, emtr->mUnk_5c);
                    particle->mUnk_08.z = MUL_FIXED12_ROUNDED(particle->mUnk_08.z, emtr->mUnk_5c);
                    break;
                case 2: {
                    SPLRandom_VecFx32_XY(&offset2);
                    offset2.x = MUL_FIXED12_ROUNDED(offset2.x, emtr->mUnk_5c);
                    offset2.y = MUL_FIXED12_ROUNDED(offset2.y, emtr->mUnk_5c);
                    offset2.z = 0;
                    SPLUtil_TiltCoordinates(&particle->mUnk_08, &offset2, emtr);
                    break;
                }
                case 3: {
                    s32 angle;
                    s32 sinValue;
                    s32 cosValue;
                    angle = acc / emitCount;
                    acc += 0x10000;
                    sinValue = SIN_OF_ANGLE(angle);
                    cosValue = COS_OF_ANGLE(angle);
                    offset3.x = MUL_FIXED12_ROUNDED(sinValue, emtr->mUnk_5c);
                    offset3.y = MUL_FIXED12_ROUNDED(cosValue, emtr->mUnk_5c);
                    offset3.z = 0;
                    SPLUtil_TiltCoordinates(&particle->mUnk_08, &offset3, emtr);
                    break;
                }
                case 4: {
                    SPLRandom_VecFx32(&particle->mUnk_08);
                    particle->mUnk_08.x = MUL_FIXED12_ROUNDED(
                        MUL_FIXED12_ROUNDED(particle->mUnk_08.x, emtr->mUnk_5c),
                        ((s32) (((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                0x100000) >>
                         8));
                    particle->mUnk_08.y = MUL_FIXED12_ROUNDED(
                        MUL_FIXED12_ROUNDED(particle->mUnk_08.y, emtr->mUnk_5c),
                        ((s32) (((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                0x100000) >>
                         8));
                    particle->mUnk_08.z = MUL_FIXED12_ROUNDED(
                        MUL_FIXED12_ROUNDED(particle->mUnk_08.z, emtr->mUnk_5c),
                        ((s32) (((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                0x100000) >>
                         8));
                    break;
                }
                case 5: {
                    SPLRandom_VecFx32_XY(&offset5);
                    offset5.x = MUL_FIXED12_ROUNDED(
                        MUL_FIXED12_ROUNDED(offset5.x, emtr->mUnk_5c),
                        ((s32) (((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                0x100000) >>
                         8));
                    offset5.y = MUL_FIXED12_ROUNDED(
                        MUL_FIXED12_ROUNDED(offset5.y, emtr->mUnk_5c),
                        ((s32) (((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                0x100000) >>
                         8));
                    SPLUtil_TiltCoordinates(&particle->mUnk_08, &offset5, emtr);
                    break;
                }
                case 8: {
                    SPLRandom_VecFx32(&particle->mUnk_08);
                    VEC_Fx16CrossProduct(&emtr->mUnk_84, &emtr->mUnk_8a, &normalFx16A);
                    normalA.x = normalFx16A.x;
                    normalA.y = normalFx16A.y;
                    normalA.z = normalFx16A.z;
                    if (VEC_DotProduct(&normalA, &particle->mUnk_08) <= 0) {
                        particle->mUnk_08.x = -particle->mUnk_08.x;
                        particle->mUnk_08.y = -particle->mUnk_08.y;
                        particle->mUnk_08.z = -particle->mUnk_08.z;
                    }
                    particle->mUnk_08.x = MUL_FIXED12_ROUNDED(particle->mUnk_08.x, emtr->mUnk_5c);
                    particle->mUnk_08.y = MUL_FIXED12_ROUNDED(particle->mUnk_08.y, emtr->mUnk_5c);
                    particle->mUnk_08.z = MUL_FIXED12_ROUNDED(particle->mUnk_08.z, emtr->mUnk_5c);
                    break;
                }
                case 9: {
                    SPLRandom_VecFx32(&particle->mUnk_08);
                    VEC_Fx16CrossProduct(&emtr->mUnk_84, &emtr->mUnk_8a, &normalFx16B);
                    normalB.x = normalFx16B.x;
                    normalB.y = normalFx16B.y;
                    normalB.z = normalFx16B.z;
                    if (VEC_DotProduct(&normalB, &particle->mUnk_08) < 0) {
                        particle->mUnk_08.x = -particle->mUnk_08.x;
                        particle->mUnk_08.y = -particle->mUnk_08.y;
                        particle->mUnk_08.z = -particle->mUnk_08.z;
                    }
                    particle->mUnk_08.x = MUL_FIXED12_ROUNDED(
                        MUL_FIXED12_ROUNDED(particle->mUnk_08.x, emtr->mUnk_5c),
                        (((s32) (((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                 0x100000) >>
                          9) +
                         0x800));
                    particle->mUnk_08.y = MUL_FIXED12_ROUNDED(
                        MUL_FIXED12_ROUNDED(particle->mUnk_08.y, emtr->mUnk_5c),
                        (((s32) (((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                 0x100000) >>
                          9) +
                         0x800));
                    particle->mUnk_08.z = MUL_FIXED12_ROUNDED(
                        MUL_FIXED12_ROUNDED(particle->mUnk_08.z, emtr->mUnk_5c),
                        (((s32) (((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                 0x100000) >>
                          9) +
                         0x800));
                    break;
                }
                case 6: {
                    SPLRandom_VecFx32_XY(&particle->mUnk_14);
                    offset6.x = MUL_FIXED12_ROUNDED(particle->mUnk_14.x, emtr->mUnk_5c);
                    offset6.y = MUL_FIXED12_ROUNDED(particle->mUnk_14.y, emtr->mUnk_5c);
                    offset6.z =
                        (emtr->mUnk_60 * (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) -
                         emtr->mUnk_60 * 0x100) >>
                        8;
                    SPLUtil_TiltCoordinates(&particle->mUnk_08, &offset6, emtr);
                    break;
                }
                case 7: {
                    SPLRandom_VecFx32_XY(&particle->mUnk_14);
                    offset7.x = MUL_FIXED12_ROUNDED(
                        MUL_FIXED12_ROUNDED(particle->mUnk_14.x, emtr->mUnk_5c),
                        ((s32) (((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                0x100000) >>
                         8));
                    offset7.y = MUL_FIXED12_ROUNDED(
                        MUL_FIXED12_ROUNDED(particle->mUnk_14.y, emtr->mUnk_5c),
                        ((s32) (((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                0x100000) >>
                         8));
                    offset7.z =
                        (emtr->mUnk_60 * (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) -
                         emtr->mUnk_60 * 0x100) >>
                        8;
                    SPLUtil_TiltCoordinates(&particle->mUnk_08, &offset7, emtr);
                    break;
                }
            }

            directionSpeed =
                ((header->mUnk_42 + 0xff -
                  ((header->mUnk_42 * (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 24)) >>
                   7)) *
                 emtr->mUnk_64) >>
                8;
            axisSpeed =
                ((header->mUnk_42 + 0xff -
                  ((header->mUnk_42 * (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 24)) >>
                   7)) *
                 emtr->mUnk_68) >>
                8;

            if (header->mUnk_00.mUnk_00_0 == 6) {
                tiltedOffset.x = MUL_FIXED12_ROUNDED(particle->mUnk_14.x, emtr->mUnk_84.x) +
                                 MUL_FIXED12_ROUNDED(particle->mUnk_14.y, emtr->mUnk_8a.x);
                tiltedOffset.y = MUL_FIXED12_ROUNDED(particle->mUnk_14.x, emtr->mUnk_84.y) +
                                 MUL_FIXED12_ROUNDED(particle->mUnk_14.y, emtr->mUnk_8a.y);
                tiltedOffset.z = MUL_FIXED12_ROUNDED(particle->mUnk_14.x, emtr->mUnk_84.z) +
                                 MUL_FIXED12_ROUNDED(particle->mUnk_14.y, emtr->mUnk_8a.z);
                VEC_Normalize(&tiltedOffset, &direction);
            } else if (particle->mUnk_08.x == 0 && particle->mUnk_08.y == 0 && particle->mUnk_08.z == 0) {
                SPLRandom_VecFx32(&direction);
            } else {
                VEC_Normalize(&particle->mUnk_08, &direction);
            }

            particle->mUnk_14.x = emtr->mUnk_40.x + (MUL_FIXED12_ROUNDED(direction.x, directionSpeed) +
                                                     MUL_FIXED12_ROUNDED(emtr->mUnk_50.x, axisSpeed));
            particle->mUnk_14.y = emtr->mUnk_40.y + (MUL_FIXED12_ROUNDED(direction.y, directionSpeed) +
                                                     MUL_FIXED12_ROUNDED(emtr->mUnk_50.y, axisSpeed));
            particle->mUnk_14.z = emtr->mUnk_40.z + (MUL_FIXED12_ROUNDED(direction.z, directionSpeed) +
                                                     MUL_FIXED12_ROUNDED(emtr->mUnk_50.z, axisSpeed));
            particle->mUnk_38 = emtr->mUnk_28;

            particle->mUnk_30 =
                ((header->mUnk_40 + 0xff -
                  ((header->mUnk_40 * (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 24)) >>
                   7)) *
                 emtr->mUnk_6c) >>
                8;
            particle->mUnk_34 = 0x1000;

            if (header->mUnk_00.mUnk_00_9 && resource->mUnk_08->mUnk_08_0) {
                Unk0201ca6c_20_08 *colorAnim;
                u32 randomIndex;
                randomIndex = (gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 20;
                colorAnim = resource->mUnk_08;
                colorChoices[0] = colorAnim->mUnk_00;
                colorChoices[1] = header->mUnk_22;
                colorChoices[2] = colorAnim->mUnk_02;
                particle->mUnk_36 = colorChoices[randomIndex % 3];
            } else {
                particle->mUnk_36 = header->mUnk_22;
            }

            particle->mUnk_2e_0 = emtr->mUnk_80_8;
            particle->mUnk_2e_5 = 0x1f;

            if (header->mUnk_00.mUnk_00_13) {
                particle->mUnk_20 = (gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173);
            } else {
                particle->mUnk_20 = emtr->mUnk_56;
            }

            if (header->mUnk_00.mUnk_00_12) {
                particle->mUnk_22 = ((header->mUnk_36 - header->mUnk_34) *
                                         ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 20) +
                                     (header->mUnk_34 << 12)) >>
                                    12;
            } else {
                particle->mUnk_22 = 0;
            }

            particle->mUnk_24 =
                (((0xff -
                   ((header->mUnk_41 * (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 24)) >>
                    8)) *
                  emtr->mUnk_70) >>
                 8) +
                1;
            particle->mUnk_26 = 0;

            if (header->mUnk_00.mUnk_00_11 && resource->mUnk_10->mUnk_08_16) {
                Unk0201ca6c_20_10 *texAnim;
                u32 randomIndex;
                randomIndex = (gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 20;
                texAnim = resource->mUnk_10;
                particle->mUnk_2c = texAnim->mUnk_00[randomIndex % texAnim->mUnk_08_0];
            } else if (header->mUnk_00.mUnk_00_11 && !resource->mUnk_10->mUnk_08_16) {
                particle->mUnk_2c = resource->mUnk_10->mUnk_00[0];
            } else {
                particle->mUnk_2c = header->mUnk_47;
            }

            particle->mUnk_28 = 0xffff / resource->mUnk_00->mUnk_48.mUnk_00_0;
            particle->mUnk_2a = 0xffff / particle->mUnk_24;
            particle->mUnk_2d = 0;
            if (header->mUnk_00.mUnk_00_20) {
                particle->mUnk_2d = (gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 24;
            }
        } while (++emitIndex < emitCount);
    }
}

static inline s32 GetScaledParticleZ(s32 scale, Unk0201e3c8 *particle) {
    return MUL_FIXED12_ROUNDED(particle->mUnk_14.z, scale);
}

static inline s32 GetScaledParticleY(s32 scale, Unk0201e3c8 *particle) {
    return MUL_FIXED12_ROUNDED(particle->mUnk_14.y, scale);
}

static inline s32 GetScaledParticleX(s32 scale, Unk0201e3c8 *particle) {
    return MUL_FIXED12_ROUNDED(particle->mUnk_14.x, scale);
}

static inline s32 AddOneToChildValue(Unk0201ca6c_20_14 *childAnim) {
    return childAnim->mUnk_09 + 1;
}

void SPLEmitter_EmitChildren(Unk0201e3c8 *ptcl, Unk0201ca6c *emtr, Unk0201e494 *list) {
    s32 velocityScale;
    Unk0201e3c8 *child;
    s32 childIndex;
    Unk0201ca6c_20_14 *childAnim;
    Vec3 *childVec;
    u32 parentLife;

    childAnim = emtr->mUnk_20->mUnk_14;
    velocityScale = MUL_FIXED12_ROUNDED(childAnim->mUnk_08 << 12, 16);
    for (childIndex = 0; childIndex < childAnim->mUnk_0c; childIndex++) {
        {
            child = SPLList_PopFront(list);
            if (child == NULL) {
                return;
            }
            SPLList_PushFront(&emtr->mUnk_14, child);
            childVec = &child->mUnk_38;
            child->mUnk_08 = ptcl->mUnk_08;
            child->mUnk_14.x =
                GetScaledParticleX(velocityScale, ptcl) +
                ((childAnim->mUnk_02 * (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) -
                  (childAnim->mUnk_02 << 8)) >>
                 8);
            child->mUnk_14.y =
                GetScaledParticleY(velocityScale, ptcl) +
                ((childAnim->mUnk_02 * (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) -
                  (childAnim->mUnk_02 << 8)) >>
                 8);
            child->mUnk_14.z =
                GetScaledParticleZ(velocityScale, ptcl) +
                ((childAnim->mUnk_02 * (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) -
                  (childAnim->mUnk_02 << 8)) >>
                 8);
            *childVec = ptcl->mUnk_38;
            child->mUnk_30 = (((ptcl->mUnk_30 * ptcl->mUnk_34) >> 12) * AddOneToChildValue(childAnim)) >> 6;
            child->mUnk_34 = 0x1000;
            if (childAnim->mUnk_00_6) {
                child->mUnk_36 = childAnim->mUnk_0a;
            } else {
                child->mUnk_36 = ptcl->mUnk_36;
            }
            child->mUnk_2e_0 = (ptcl->mUnk_2e_0 * (ptcl->mUnk_2e_5 + 1)) >> 5;
            child->mUnk_2e_5 = 0x1f;
            switch (childAnim->mUnk_00_3) {
                case 2:
                    child->mUnk_20 = ptcl->mUnk_20;
                    child->mUnk_22 = ptcl->mUnk_22;
                    break;
                case 0:
                    child->mUnk_20 = 0;
                    child->mUnk_22 = 0;
                    break;
                case 1:
                    child->mUnk_20 = ptcl->mUnk_20;
                    child->mUnk_22 = 0;
                    break;
            }
            child->mUnk_24 = childAnim->mUnk_06;
            child->mUnk_26 = 0;
            child->mUnk_2c = childAnim->mUnk_0f;
            parentLife = ptcl->mUnk_24;
            child->mUnk_28 = 0xffff / (s32) (parentLife >> 1);
            child->mUnk_2a = 0xffff / ptcl->mUnk_24;
            child->mUnk_2d = 0;
        }
    }
}

void SPLUtil_DrawXYPlane(u32 texCoordU, u32 texCoordV, s32 centerX, s32 centerY) {
    u32 texVBits;
    s32 lowYBits;

    reg_G3_BEGIN_VTXS = 1;
    lowYBits = ((s16) (centerY - 0x1000) >> 6) & 0x3ff;
    reg_G3_TEXCOORD = 0;
    reg_G3_VTX_10 = (((s16) (centerX - 0x1000) >> 6) & 0x3ff) | ((((s16) (centerY + 0x1000) >> 6) & 0x3ff) << 10);
    reg_G3_TEXCOORD = (texCoordU << 8) >> 16;
    texVBits = (texCoordV << 8) >> 16;
    reg_G3_VTX_10 = (((s16) (centerX + 0x1000) >> 6) & 0x3ff) | ((((s16) (centerY + 0x1000) >> 6) & 0x3ff) << 10);
    reg_G3_TEXCOORD = ((texCoordU << 8) >> 16) | (texVBits << 16);
    reg_G3_VTX_10 = (((s16) (centerX + 0x1000) >> 6) & 0x3ff) | (lowYBits << 10);
    reg_G3_TEXCOORD = texVBits << 16;
    reg_G3_VTX_10 = (((s16) (centerX - 0x1000) >> 6) & 0x3ff) | (lowYBits << 10);
    reg_G3_END_VTXS = 0;
}

void SPLUtil_DrawXZPlane(u32 texCoordU, u32 texCoordV, s32 centerX, s32 centerZ) {
    s32 highXBits;
    u32 lowZBits;
    u32 texUBits;
    u32 texVBits;
    s32 highZBits;
    s32 lowXBits;

    reg_G3_BEGIN_VTXS = 1;
    reg_G3_TEXCOORD = 0;
    lowXBits = ((s16) (centerX - 0x1000) >> 6) & 0x3ff;
    texUBits = (texCoordU << 8) >> 16;
    texVBits = (texCoordV << 8) >> 16;
    lowZBits = ((s16) (centerZ - 0x1000) >> 6) & 0x3ff;
    highZBits = ((s16) (centerZ + 0x1000) >> 6) & 0x3ff;
    reg_G3_VTX_10 = lowXBits | (highZBits << 20);
    reg_G3_TEXCOORD = texUBits;
    highXBits = ((s16) (centerX + 0x1000) >> 6) & 0x3ff;
    reg_G3_VTX_10 = highXBits | (highZBits << 20);
    reg_G3_TEXCOORD = texUBits | (texVBits << 16);
    reg_G3_VTX_10 = highXBits | (lowZBits << 20);
    reg_G3_TEXCOORD = texVBits << 16;
    reg_G3_VTX_10 = lowXBits | (lowZBits << 20);
    reg_G3_END_VTXS = 0;
}

void SPLUtil_RotateXYZ(s32 sinValue, s32 cosValue, MtxFx43 *mtx) {
    s32 cosTerm;
    s32 sinTerm;
    s32 diagonal;
    s32 sumTerm;
    s32 diffTerm;

    cosTerm = MUL_FIXED12_ROUNDED(0x1000 - cosValue, 0x555);
    sinTerm = MUL_FIXED12_ROUNDED(sinValue, 0x93d);
    sumTerm = cosTerm + sinTerm;
    diffTerm = cosTerm - sinTerm;
    diagonal = cosTerm + cosValue;
    mtx->mRows[0].x = diagonal;
    mtx->mRows[1].x = sumTerm;
    mtx->mRows[2].x = diffTerm;
    mtx->mRows[3].x = 0;
    mtx->mRows[0].y = diffTerm;
    mtx->mRows[1].y = diagonal;
    mtx->mRows[2].y = sumTerm;
    mtx->mRows[3].y = 0;
    mtx->mRows[0].z = sumTerm;
    mtx->mRows[1].z = diffTerm;
    mtx->mRows[2].z = diagonal;
    mtx->mRows[3].z = 0;
}

void SPLUtil_RotateY(s32 sinValue, s32 cosValue, MtxFx43 *mtx) {
    mtx->mRows[0].x = cosValue;
    mtx->mRows[1].x = 0;
    mtx->mRows[2].x = sinValue;
    mtx->mRows[3].x = 0;
    mtx->mRows[0].y = 0;
    mtx->mRows[1].y = 0x1000;
    mtx->mRows[2].y = 0;
    mtx->mRows[3].y = 0;
    mtx->mRows[0].z = -sinValue;
    mtx->mRows[1].z = 0;
    mtx->mRows[2].z = cosValue;
    mtx->mRows[3].z = 0;
}

void SPLDraw_Billboard(SPLManager *mgr, Unk0201e3c8 *ptcl) {
    Vec3 viewPos;
    MtxFx43 billboardMtx;
    s32 alpha;
    s32 width;
    s32 height;
    s32 sinAngle;
    s32 cosAngle;
    u16 particleColor;
    u16 emitterColor;
    s32 originX;
    s32 originY;
    s32 originZ;
    s32 baseScale;
    MtxFx43 *viewMtx;
    u8 scaleMode;
    s32 particleScale;

    baseScale = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_30;
    viewMtx = mgr->mRenderStateViewMatrix;
    scaleMode = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_48.mUnk_00_28;
    particleScale = ptcl->mUnk_34;
    particleColor = ptcl->mUnk_36;
    emitterColor = mgr->mRenderStateEmitter->mUnk_72;
    alpha = (ptcl->mUnk_2e_0 * (ptcl->mUnk_2e_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->mUnk_2e_10 << 24) | (mgr->mMiscPolygonAttr | 0xc0) | (alpha << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (alpha == 0) {
        return;
    }
    height = ptcl->mUnk_30;
    width = MUL_FIXED12_ROUNDED(height, baseScale);
    if (scaleMode == 0) {
        width = MUL_FIXED12_ROUNDED(width, particleScale);
        height = MUL_FIXED12_ROUNDED(height, particleScale);
    } else if (scaleMode == 1) {
        width = MUL_FIXED12_ROUNDED(width, particleScale);
    } else {
        height = MUL_FIXED12_ROUNDED(height, particleScale);
    }
    if (mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_00.mUnk_00_23 == 0) {
        viewPos.x = ptcl->mUnk_08.x + ptcl->mUnk_38.x;
        viewPos.y = ptcl->mUnk_08.y + ptcl->mUnk_38.y;
        viewPos.z = ptcl->mUnk_08.z + ptcl->mUnk_38.z;
        MTX_MultVec43(&viewPos, viewMtx, &viewPos);
        sinAngle = FX_SinIdx(ptcl->mUnk_20);
        cosAngle = FX_CosIdx(ptcl->mUnk_20);
        billboardMtx.mRows[0].x = MUL_FIXED12_ROUNDED(cosAngle, width);
        billboardMtx.mRows[0].y = MUL_FIXED12_ROUNDED(sinAngle, width);
        billboardMtx.mRows[0].z = 0;
        billboardMtx.mRows[1].x = MUL_FIXED12_ROUNDED(-sinAngle, height);
        billboardMtx.mRows[1].y = MUL_FIXED12_ROUNDED(cosAngle, height);
        billboardMtx.mRows[1].z = 0;
        billboardMtx.mRows[2].x = 0;
        billboardMtx.mRows[2].y = 0;
        billboardMtx.mRows[2].z = 0x1000;
        billboardMtx.mRows[3].x = viewPos.x;
        billboardMtx.mRows[3].y = viewPos.y;
        billboardMtx.mRows[3].z = viewPos.z;
        reg_G3_MTX_IDENTITY = 0;
        G3_MultMtx43(&billboardMtx);
    } else {
        viewPos.x = ptcl->mUnk_08.x + ptcl->mUnk_38.x - mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.x;
        viewPos.y = ptcl->mUnk_08.y + ptcl->mUnk_38.y - mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.y;
        viewPos.z = ptcl->mUnk_08.z + ptcl->mUnk_38.z - mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.z;
        MTX_MultVec43(&viewPos, viewMtx, &viewPos);
        sinAngle = FX_SinIdx(ptcl->mUnk_20);
        cosAngle = FX_CosIdx(ptcl->mUnk_20);
        billboardMtx.mRows[0].x = MUL_FIXED12_ROUNDED(cosAngle, width);
        billboardMtx.mRows[0].y = MUL_FIXED12_ROUNDED(sinAngle, width);
        billboardMtx.mRows[0].z = 0;
        billboardMtx.mRows[1].x = MUL_FIXED12_ROUNDED(-sinAngle, height);
        billboardMtx.mRows[1].y = MUL_FIXED12_ROUNDED(cosAngle, height);
        billboardMtx.mRows[1].z = 0;
        billboardMtx.mRows[2].x = 0;
        billboardMtx.mRows[2].y = 0;
        billboardMtx.mRows[2].z = 0x1000;
        billboardMtx.mRows[3].x = viewPos.x;
        billboardMtx.mRows[3].y = viewPos.y;
        billboardMtx.mRows[3].z = viewPos.z;
        reg_G3_MTX_IDENTITY = 0;
        originZ = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.z;
        originY = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.y;
        originX = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.x;
        reg_G3_MTX_TRANS = originX;
        reg_G3_MTX_TRANS = originY;
        reg_G3_MTX_TRANS = originZ;
        G3_MultMtx43(&billboardMtx);
    }
    reg_G3_COLOR = (u16) ((((particleColor & 0x1f) * (emitterColor & 0x1f)) >> 5) |
                          ((((particleColor & 0x3e0) * (emitterColor & 0x3e0)) >> 15) << 5) |
                          ((((particleColor & 0x7c00) * (emitterColor & 0x7c00)) >> 25) << 10));
    SPLUtil_DrawXYPlane(mgr->mRenderStateEmitter->mUnk_78, mgr->mRenderStateEmitter->mUnk_7a,
                        mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_50,
                        mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_52);
}

void SPLDraw_Child_Billboard(SPLManager *mgr, Unk0201e3c8 *ptcl) {
    Vec3 viewPos;
    MtxFx43 billboardMtx;
    s32 alpha;
    s32 width;
    s32 height;
    s32 sinAngle;
    s32 cosAngle;
    u16 particleColor;
    u16 emitterColor;
    s32 originX;
    s32 originY;
    s32 originZ;
    s32 baseScale;
    MtxFx43 *viewMtx;

    baseScale = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_30;
    viewMtx = mgr->mRenderStateViewMatrix;
    alpha = (ptcl->mUnk_2e_0 * (ptcl->mUnk_2e_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->mUnk_2e_10 << 24) | (mgr->mMiscPolygonAttr | 0xc0) | (alpha << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (alpha == 0) {
        return;
    }
    height = ptcl->mUnk_30;
    width = MUL_FIXED12_ROUNDED(height, baseScale);
    switch (mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_48.mUnk_00_28) {
        case 0:
            width = MUL_FIXED12_ROUNDED(width, ptcl->mUnk_34);
            height = MUL_FIXED12_ROUNDED(height, ptcl->mUnk_34);
            break;
        case 1:
            width = MUL_FIXED12_ROUNDED(width, ptcl->mUnk_34);
            break;
        case 2:
            height = MUL_FIXED12_ROUNDED(height, ptcl->mUnk_34);
            break;
    }
    if (mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_00.mUnk_00_23 == 0) {
        viewPos.x = ptcl->mUnk_08.x + ptcl->mUnk_38.x;
        viewPos.y = ptcl->mUnk_08.y + ptcl->mUnk_38.y;
        viewPos.z = ptcl->mUnk_08.z + ptcl->mUnk_38.z;
        MTX_MultVec43(&viewPos, viewMtx, &viewPos);
        sinAngle = FX_SinIdx(ptcl->mUnk_20);
        cosAngle = FX_CosIdx(ptcl->mUnk_20);
        billboardMtx.mRows[0].x = MUL_FIXED12_ROUNDED(cosAngle, width);
        billboardMtx.mRows[0].y = MUL_FIXED12_ROUNDED(sinAngle, width);
        billboardMtx.mRows[0].z = 0;
        billboardMtx.mRows[1].x = MUL_FIXED12_ROUNDED(-sinAngle, height);
        billboardMtx.mRows[1].y = MUL_FIXED12_ROUNDED(cosAngle, height);
        billboardMtx.mRows[1].z = 0;
        billboardMtx.mRows[2].x = 0;
        billboardMtx.mRows[2].y = 0;
        billboardMtx.mRows[2].z = 0x1000;
        billboardMtx.mRows[3].x = viewPos.x;
        billboardMtx.mRows[3].y = viewPos.y;
        billboardMtx.mRows[3].z = viewPos.z;
        reg_G3_MTX_IDENTITY = 0;
        G3_MultMtx43(&billboardMtx);
    } else {
        viewPos.x = ptcl->mUnk_08.x + ptcl->mUnk_38.x - mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.x;
        viewPos.y = ptcl->mUnk_08.y + ptcl->mUnk_38.y - mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.y;
        viewPos.z = ptcl->mUnk_08.z + ptcl->mUnk_38.z - mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.z;
        MTX_MultVec43(&viewPos, viewMtx, &viewPos);
        sinAngle = FX_SinIdx(ptcl->mUnk_20);
        cosAngle = FX_CosIdx(ptcl->mUnk_20);
        billboardMtx.mRows[0].x = MUL_FIXED12_ROUNDED(cosAngle, width);
        billboardMtx.mRows[0].y = MUL_FIXED12_ROUNDED(sinAngle, width);
        billboardMtx.mRows[0].z = 0;
        billboardMtx.mRows[1].x = MUL_FIXED12_ROUNDED(-sinAngle, height);
        billboardMtx.mRows[1].y = MUL_FIXED12_ROUNDED(cosAngle, height);
        billboardMtx.mRows[1].z = 0;
        billboardMtx.mRows[2].x = 0;
        billboardMtx.mRows[2].y = 0;
        billboardMtx.mRows[2].z = 0x1000;
        billboardMtx.mRows[3].x = viewPos.x;
        billboardMtx.mRows[3].y = viewPos.y;
        billboardMtx.mRows[3].z = viewPos.z;
        reg_G3_MTX_IDENTITY = 0;
        originZ = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.z;
        originY = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.y;
        originX = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.x;
        reg_G3_MTX_TRANS = originX;
        reg_G3_MTX_TRANS = originY;
        reg_G3_MTX_TRANS = originZ;
        G3_MultMtx43(&billboardMtx);
    }
    particleColor = ptcl->mUnk_36;
    emitterColor = mgr->mRenderStateEmitter->mUnk_72;
    reg_G3_COLOR = (u16) ((((particleColor & 0x1f) * (emitterColor & 0x1f)) >> 5) |
                          ((((particleColor & 0x3e0) * (emitterColor & 0x3e0)) >> 15) << 5) |
                          ((((particleColor & 0x7c00) * (emitterColor & 0x7c00)) >> 25) << 10));
    SPLUtil_DrawXYPlane(mgr->mRenderStateEmitter->mUnk_7c, mgr->mRenderStateEmitter->mUnk_7e, 0, 0);
}

void SPLDraw_DirectionalBillboard(SPLManager *mgr, Unk0201e3c8 *ptcl) {
    Vec3 dirNorm;
    Vec3 pos;
    Vec3 sideVec;
    Vec3 viewForward;
    MtxFx33 viewMtx33;
    MtxFx43 buf;
    MtxFx43 *viewMtx;
    s32 alpha;
    s32 height;
    s32 width;
    s32 facing;
    s32 stretch;
    s32 stretchedWidth;
    u16 emitterColor;
    u16 particleColor;
    s16 baseScale;
    s32 originX;
    s32 originY;
    s32 originZ;

    viewMtx = mgr->mRenderStateViewMatrix;
    baseScale = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_30;
    alpha = (ptcl->mUnk_2e_0 * (ptcl->mUnk_2e_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->mUnk_2e_10 << 24) | (mgr->mMiscPolygonAttr | 0xc0) | (alpha << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (alpha == 0) {
        return;
    }
    width = ptcl->mUnk_30;
    height = MUL_FIXED12_ROUNDED(width, baseScale);
    switch (mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_48.mUnk_00_28) {
        case 0:
            height = MUL_FIXED12_ROUNDED(height, ptcl->mUnk_34);
            width = MUL_FIXED12_ROUNDED(width, ptcl->mUnk_34);
            break;
        case 1:
            height = MUL_FIXED12_ROUNDED(height, ptcl->mUnk_34);
            break;
        case 2:
            width = MUL_FIXED12_ROUNDED(width, ptcl->mUnk_34);
            break;
    }
    if (!mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_00.mUnk_00_23) {
        pos.x = ptcl->mUnk_08.x + ptcl->mUnk_38.x;
        pos.y = ptcl->mUnk_08.y + ptcl->mUnk_38.y;
        pos.z = ptcl->mUnk_08.z + ptcl->mUnk_38.z;
        sideVec = ptcl->mUnk_14;
        viewForward.x = viewMtx->mRows[0].z;
        viewForward.y = viewMtx->mRows[1].z;
        viewForward.z = viewMtx->mRows[2].z;
        VEC_CrossProduct(&sideVec, &viewForward, &sideVec);
        if (sideVec.x == 0 && sideVec.y == 0 && sideVec.z == 0) {
            return;
        }
        VEC_Normalize(&sideVec, &sideVec);
        MI_Copy36B(viewMtx, &viewMtx33);
        MTX_MultVec33(&sideVec, &viewMtx33, &sideVec);
        MTX_MultVec43(&pos, viewMtx, &pos);
        dirNorm = ptcl->mUnk_14;
        VEC_Normalize(&dirNorm, &dirNorm);
        facing = MUL_FIXED12_ROUNDED(dirNorm.x, -viewMtx->mRows[0].z) +
                 MUL_FIXED12_ROUNDED(dirNorm.y, -viewMtx->mRows[1].z) +
                 MUL_FIXED12_ROUNDED(dirNorm.z, -viewMtx->mRows[2].z);
        if (facing < 0) {
            facing = -facing;
        }
        stretch =
            MUL_FIXED12_ROUNDED(0x1000 - facing, (s32) mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_48.mUnk_00_8);
        stretchedWidth = MUL_FIXED12_ROUNDED(width, stretch + 0x1000);
        buf.mRows[0].x = MUL_FIXED12_ROUNDED(sideVec.x, height);
        buf.mRows[1].x = MUL_FIXED12_ROUNDED(-sideVec.y, stretchedWidth);
        buf.mRows[2].x = 0;
        buf.mRows[3].x = pos.x;
        buf.mRows[0].y = MUL_FIXED12_ROUNDED(sideVec.y, height);
        buf.mRows[1].y = MUL_FIXED12_ROUNDED(sideVec.x, stretchedWidth);
        buf.mRows[2].y = 0;
        buf.mRows[3].y = pos.y;
        buf.mRows[0].z = 0;
        buf.mRows[1].z = 0;
        buf.mRows[2].z = 0x1000;
        buf.mRows[3].z = pos.z;
        reg_G3_MTX_IDENTITY = 0;
        G3_MultMtx43(&buf);
    } else {
        pos.x = ptcl->mUnk_08.x + ptcl->mUnk_38.x - mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.x;
        pos.y = ptcl->mUnk_08.y + ptcl->mUnk_38.y - mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.y;
        pos.z = ptcl->mUnk_08.z + ptcl->mUnk_38.z - mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.z;
        sideVec = ptcl->mUnk_14;
        viewForward.x = viewMtx->mRows[0].z;
        viewForward.y = viewMtx->mRows[1].z;
        viewForward.z = viewMtx->mRows[2].z;
        VEC_CrossProduct(&sideVec, &viewForward, &sideVec);
        if (sideVec.x == 0 && sideVec.y == 0 && sideVec.z == 0) {
            return;
        }
        VEC_Normalize(&sideVec, &sideVec);
        MI_Copy36B(viewMtx, &viewMtx33);
        MTX_MultVec33(&sideVec, &viewMtx33, &sideVec);
        MTX_MultVec43(&pos, viewMtx, &pos);
        dirNorm = ptcl->mUnk_14;
        VEC_Normalize(&dirNorm, &dirNorm);
        facing = MUL_FIXED12_ROUNDED(dirNorm.x, -viewMtx->mRows[0].z) +
                 MUL_FIXED12_ROUNDED(dirNorm.y, -viewMtx->mRows[1].z) +
                 MUL_FIXED12_ROUNDED(dirNorm.z, -viewMtx->mRows[2].z);
        if (facing < 0) {
            facing = -facing;
        }
        stretch =
            MUL_FIXED12_ROUNDED(0x1000 - facing, (s32) mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_48.mUnk_00_8);
        stretchedWidth = MUL_FIXED12_ROUNDED(width, stretch + 0x1000);
        buf.mRows[0].x = MUL_FIXED12_ROUNDED(sideVec.x, height);
        buf.mRows[1].x = MUL_FIXED12_ROUNDED(-sideVec.y, stretchedWidth);
        buf.mRows[2].x = 0;
        buf.mRows[3].x = pos.x;
        buf.mRows[0].y = MUL_FIXED12_ROUNDED(sideVec.y, height);
        buf.mRows[1].y = MUL_FIXED12_ROUNDED(sideVec.x, stretchedWidth);
        buf.mRows[2].y = 0;
        buf.mRows[3].y = pos.y;
        buf.mRows[0].z = 0;
        buf.mRows[1].z = 0;
        buf.mRows[2].z = 0x1000;
        buf.mRows[3].z = pos.z;
        reg_G3_MTX_IDENTITY = 0;
        originZ = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.z;
        originY = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.y;
        originX = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.x;
        reg_G3_MTX_TRANS = originX;
        reg_G3_MTX_TRANS = originY;
        reg_G3_MTX_TRANS = originZ;
        G3_MultMtx43(&buf);
    }
    particleColor = ptcl->mUnk_36;
    emitterColor = mgr->mRenderStateEmitter->mUnk_72;
    reg_G3_COLOR = (u16) ((((particleColor & 0x1f) * (emitterColor & 0x1f)) >> 5) |
                          ((((particleColor & 0x3e0) * (emitterColor & 0x3e0)) >> 15) << 5) |
                          ((((particleColor & 0x7c00) * (emitterColor & 0x7c00)) >> 25) << 10));
    SPLUtil_DrawXYPlane(mgr->mRenderStateEmitter->mUnk_78, mgr->mRenderStateEmitter->mUnk_7a,
                        mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_50,
                        mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_52);
}

void SPLDraw_Child_DirectionalBillboard(SPLManager *mgr, Unk0201e3c8 *ptcl) {
    Vec3 dirNorm;
    Vec3 pos;
    Vec3 sideVec;
    Vec3 viewForward;
    MtxFx33 viewMtx33;
    MtxFx43 buf;
    MtxFx43 *viewMtx;
    s32 alpha;
    s32 height;
    s32 width;
    s32 facing;
    s32 stretch;
    s32 stretchedWidth;
    u16 emitterColor;
    u16 particleColor;
    s16 baseScale;
    s32 originX;
    s32 originY;
    s32 originZ;

    viewMtx = mgr->mRenderStateViewMatrix;
    baseScale = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_30;
    alpha = (ptcl->mUnk_2e_0 * (ptcl->mUnk_2e_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->mUnk_2e_10 << 24) | (mgr->mMiscPolygonAttr | 0xc0) | (alpha << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (alpha == 0) {
        return;
    }
    width = ptcl->mUnk_30;
    height = MUL_FIXED12_ROUNDED(width, baseScale);
    switch (mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_48.mUnk_00_28) {
        case 0:
            height = MUL_FIXED12_ROUNDED(height, ptcl->mUnk_34);
            width = MUL_FIXED12_ROUNDED(width, ptcl->mUnk_34);
            break;
        case 1:
            height = MUL_FIXED12_ROUNDED(height, ptcl->mUnk_34);
            break;
        case 2:
            width = MUL_FIXED12_ROUNDED(width, ptcl->mUnk_34);
            break;
    }
    if (!mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_00.mUnk_00_23) {
        pos.x = ptcl->mUnk_08.x + ptcl->mUnk_38.x;
        pos.y = ptcl->mUnk_08.y + ptcl->mUnk_38.y;
        pos.z = ptcl->mUnk_08.z + ptcl->mUnk_38.z;
        sideVec = ptcl->mUnk_14;
        viewForward.x = viewMtx->mRows[0].z;
        viewForward.y = viewMtx->mRows[1].z;
        viewForward.z = viewMtx->mRows[2].z;
        VEC_CrossProduct(&sideVec, &viewForward, &sideVec);
        if (sideVec.x == 0 && sideVec.y == 0 && sideVec.z == 0) {
            return;
        }
        VEC_Normalize(&sideVec, &sideVec);
        MI_Copy36B(viewMtx, &viewMtx33);
        MTX_MultVec33(&sideVec, &viewMtx33, &sideVec);
        MTX_MultVec43(&pos, viewMtx, &pos);
        dirNorm = ptcl->mUnk_14;
        VEC_Normalize(&dirNorm, &dirNorm);
        facing = MUL_FIXED12_ROUNDED(dirNorm.x, -viewMtx->mRows[0].z) +
                 MUL_FIXED12_ROUNDED(dirNorm.y, -viewMtx->mRows[1].z) +
                 MUL_FIXED12_ROUNDED(dirNorm.z, -viewMtx->mRows[2].z);
        if (facing < 0) {
            facing = -facing;
        }
        stretch =
            MUL_FIXED12_ROUNDED(0x1000 - facing, (s32) mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_48.mUnk_00_8);
        stretchedWidth = MUL_FIXED12_ROUNDED(width, stretch + 0x1000);
        buf.mRows[0].x = MUL_FIXED12_ROUNDED(sideVec.x, height);
        buf.mRows[1].x = MUL_FIXED12_ROUNDED(-sideVec.y, stretchedWidth);
        buf.mRows[2].x = 0;
        buf.mRows[3].x = pos.x;
        buf.mRows[0].y = MUL_FIXED12_ROUNDED(sideVec.y, height);
        buf.mRows[1].y = MUL_FIXED12_ROUNDED(sideVec.x, stretchedWidth);
        buf.mRows[2].y = 0;
        buf.mRows[3].y = pos.y;
        buf.mRows[0].z = 0;
        buf.mRows[1].z = 0;
        buf.mRows[2].z = 0x1000;
        buf.mRows[3].z = pos.z;
        reg_G3_MTX_IDENTITY = 0;
        G3_MultMtx43(&buf);
    } else {
        pos.x = ptcl->mUnk_08.x + ptcl->mUnk_38.x - mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.x;
        pos.y = ptcl->mUnk_08.y + ptcl->mUnk_38.y - mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.y;
        pos.z = ptcl->mUnk_08.z + ptcl->mUnk_38.z - mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.z;
        sideVec = ptcl->mUnk_14;
        viewForward.x = viewMtx->mRows[0].z;
        viewForward.y = viewMtx->mRows[1].z;
        viewForward.z = viewMtx->mRows[2].z;
        VEC_CrossProduct(&sideVec, &viewForward, &sideVec);
        if (sideVec.x == 0 && sideVec.y == 0 && sideVec.z == 0) {
            return;
        }
        VEC_Normalize(&sideVec, &sideVec);
        MI_Copy36B(viewMtx, &viewMtx33);
        MTX_MultVec33(&sideVec, &viewMtx33, &sideVec);
        MTX_MultVec43(&pos, viewMtx, &pos);
        dirNorm = ptcl->mUnk_14;
        VEC_Normalize(&dirNorm, &dirNorm);
        facing = MUL_FIXED12_ROUNDED(dirNorm.x, -viewMtx->mRows[0].z) +
                 MUL_FIXED12_ROUNDED(dirNorm.y, -viewMtx->mRows[1].z) +
                 MUL_FIXED12_ROUNDED(dirNorm.z, -viewMtx->mRows[2].z);
        if (facing < 0) {
            facing = -facing;
        }
        stretch =
            MUL_FIXED12_ROUNDED(0x1000 - facing, (s32) mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_48.mUnk_00_8);
        stretchedWidth = MUL_FIXED12_ROUNDED(width, stretch + 0x1000);
        buf.mRows[0].x = MUL_FIXED12_ROUNDED(sideVec.x, height);
        buf.mRows[1].x = MUL_FIXED12_ROUNDED(-sideVec.y, stretchedWidth);
        buf.mRows[2].x = 0;
        buf.mRows[3].x = pos.x;
        buf.mRows[0].y = MUL_FIXED12_ROUNDED(sideVec.y, height);
        buf.mRows[1].y = MUL_FIXED12_ROUNDED(sideVec.x, stretchedWidth);
        buf.mRows[2].y = 0;
        buf.mRows[3].y = pos.y;
        buf.mRows[0].z = 0;
        buf.mRows[1].z = 0;
        buf.mRows[2].z = 0x1000;
        buf.mRows[3].z = pos.z;
        reg_G3_MTX_IDENTITY = 0;
        originZ = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.z;
        originY = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.y;
        originX = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.x;
        reg_G3_MTX_TRANS = originX;
        reg_G3_MTX_TRANS = originY;
        reg_G3_MTX_TRANS = originZ;
        G3_MultMtx43(&buf);
    }
    particleColor = ptcl->mUnk_36;
    emitterColor = mgr->mRenderStateEmitter->mUnk_72;
    reg_G3_COLOR = (u16) ((((particleColor & 0x1f) * (emitterColor & 0x1f)) >> 5) |
                          ((((particleColor & 0x3e0) * (emitterColor & 0x3e0)) >> 15) << 5) |
                          ((((particleColor & 0x7c00) * (emitterColor & 0x7c00)) >> 25) << 10));
    SPLUtil_DrawXYPlane(mgr->mRenderStateEmitter->mUnk_7c, mgr->mRenderStateEmitter->mUnk_7e, 0, 0);
}

void SPLDraw_Polygon(SPLManager *mgr, Unk0201e3c8 *ptcl) {
    MtxFx43 worldMtx;
    MtxFx43 rotationMtx;
    MtxFx43 scaleMtx;
    s32 alpha;
    s32 width;
    s32 height;
    u16 particleColor;
    u16 emitterColor;
    s32 originX;
    s32 originY;
    s32 originZ;

    alpha = (ptcl->mUnk_2e_0 * (ptcl->mUnk_2e_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->mUnk_2e_10 << 24) | (mgr->mMiscPolygonAttr | 0xc0) | (alpha << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (alpha == 0) {
        return;
    }
    data_02161ac8[mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_00.mUnk_00_17](
        FX_SinIdx(ptcl->mUnk_20), FX_CosIdx(ptcl->mUnk_20), &rotationMtx);
    height = ptcl->mUnk_30;
    width = MUL_FIXED12_ROUNDED(height, mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_30);
    switch (mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_48.mUnk_00_28) {
        case 0:
            width = MUL_FIXED12_ROUNDED(width, ptcl->mUnk_34);
            height = MUL_FIXED12_ROUNDED(height, ptcl->mUnk_34);
            break;
        case 1:
            width = MUL_FIXED12_ROUNDED(width, ptcl->mUnk_34);
            break;
        case 2:
            height = MUL_FIXED12_ROUNDED(height, ptcl->mUnk_34);
            break;
    }
    MTX_Scale43_(&scaleMtx, width, height, height);
    MTX_Concat43(&scaleMtx, &rotationMtx, &worldMtx);
    if (mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_00.mUnk_00_23 == 0) {
        worldMtx.mRows[3].x = ptcl->mUnk_08.x + ptcl->mUnk_38.x;
        worldMtx.mRows[3].y = ptcl->mUnk_08.y + ptcl->mUnk_38.y;
        worldMtx.mRows[3].z = ptcl->mUnk_08.z + ptcl->mUnk_38.z;
        G3_LoadMtx43(mgr->mRenderStateViewMatrix);
        G3_MultMtx43(&worldMtx);
    } else {
        worldMtx.mRows[3].x = ptcl->mUnk_08.x + ptcl->mUnk_38.x - mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.x;
        worldMtx.mRows[3].y = ptcl->mUnk_08.y + ptcl->mUnk_38.y - mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.y;
        worldMtx.mRows[3].z = ptcl->mUnk_08.z + ptcl->mUnk_38.z - mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.z;
        reg_G3_MTX_IDENTITY = 0;
        originZ = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.z;
        originY = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.y;
        originX = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.x;
        reg_G3_MTX_TRANS = originX;
        reg_G3_MTX_TRANS = originY;
        reg_G3_MTX_TRANS = originZ;
        G3_MultMtx43(mgr->mRenderStateViewMatrix);
        G3_MultMtx43(&worldMtx);
    }
    particleColor = ptcl->mUnk_36;
    emitterColor = mgr->mRenderStateEmitter->mUnk_72;
    reg_G3_COLOR = (u16) ((((particleColor & 0x1f) * (emitterColor & 0x1f)) >> 5) |
                          ((((particleColor & 0x3e0) * (emitterColor & 0x3e0)) >> 15) << 5) |
                          ((((particleColor & 0x7c00) * (emitterColor & 0x7c00)) >> 25) << 10));
    data_02161ac0[mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_00.mUnk_00_19](
        mgr->mRenderStateEmitter->mUnk_78, mgr->mRenderStateEmitter->mUnk_7a,
        mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_50, mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_52);
}

void SPLDraw_Child_Polygon(SPLManager *mgr, Unk0201e3c8 *ptcl) {
    MtxFx43 worldMtx;
    MtxFx43 rotationMtx;
    MtxFx43 scaleMtx;
    s32 alpha;
    s32 width;
    s32 height;
    u16 particleColor;
    u16 emitterColor;
    s32 originX;
    s32 originY;
    s32 originZ;

    alpha = (ptcl->mUnk_2e_0 * (ptcl->mUnk_2e_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->mUnk_2e_10 << 24) | (mgr->mMiscPolygonAttr | 0xc0) | (alpha << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (alpha == 0) {
        return;
    }
    data_02161ac8[mgr->mRenderStateEmitter->mUnk_20->mUnk_14->mUnk_00_9](FX_SinIdx(ptcl->mUnk_20),
                                                                         FX_CosIdx(ptcl->mUnk_20), &rotationMtx);
    height = ptcl->mUnk_30;
    width = MUL_FIXED12_ROUNDED(height, mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_30);
    switch (mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_48.mUnk_00_28) {
        case 0:
            width = MUL_FIXED12_ROUNDED(width, ptcl->mUnk_34);
            height = MUL_FIXED12_ROUNDED(height, ptcl->mUnk_34);
            break;
        case 1:
            width = MUL_FIXED12_ROUNDED(width, ptcl->mUnk_34);
            break;
        case 2:
            height = MUL_FIXED12_ROUNDED(height, ptcl->mUnk_34);
            break;
    }
    MTX_Scale43_(&scaleMtx, width, height, height);
    MTX_Concat43(&rotationMtx, &scaleMtx, &worldMtx);
    if (mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_00.mUnk_00_23 == 0) {
        worldMtx.mRows[3].x = ptcl->mUnk_08.x + ptcl->mUnk_38.x;
        worldMtx.mRows[3].y = ptcl->mUnk_08.y + ptcl->mUnk_38.y;
        worldMtx.mRows[3].z = ptcl->mUnk_08.z + ptcl->mUnk_38.z;
        G3_LoadMtx43(mgr->mRenderStateViewMatrix);
        G3_MultMtx43(&worldMtx);
    } else {
        worldMtx.mRows[3].x = ptcl->mUnk_08.x + ptcl->mUnk_38.x - mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.x;
        worldMtx.mRows[3].y = ptcl->mUnk_08.y + ptcl->mUnk_38.y - mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.y;
        worldMtx.mRows[3].z = ptcl->mUnk_08.z + ptcl->mUnk_38.z - mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.z;
        reg_G3_MTX_IDENTITY = 0;
        originZ = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.z;
        originY = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.y;
        originX = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.x;
        reg_G3_MTX_TRANS = originX;
        reg_G3_MTX_TRANS = originY;
        reg_G3_MTX_TRANS = originZ;
        G3_MultMtx43(mgr->mRenderStateViewMatrix);
        G3_MultMtx43(&worldMtx);
    }
    particleColor = ptcl->mUnk_36;
    emitterColor = mgr->mRenderStateEmitter->mUnk_72;
    reg_G3_COLOR = (u16) ((((particleColor & 0x1f) * (emitterColor & 0x1f)) >> 5) |
                          ((((particleColor & 0x3e0) * (emitterColor & 0x3e0)) >> 15) << 5) |
                          ((((particleColor & 0x7c00) * (emitterColor & 0x7c00)) >> 25) << 10));
    data_02161ac0[mgr->mRenderStateEmitter->mUnk_20->mUnk_14->mUnk_00_11](mgr->mRenderStateEmitter->mUnk_7c,
                                                                          mgr->mRenderStateEmitter->mUnk_7e, 0, 0);
}

void SPLDraw_DirectionalPolygon(SPLManager *mgr, Unk0201e3c8 *ptcl) {
    MtxFx43 worldMtx;
    MtxFx43 rotationMtx;
    MtxFx43 scaleMtx;
    Vec3 forward;
    Vec3 sideAxis;
    Vec3 upAxis;
    Vec3 refAxis;
    MtxFx43 axisMtx;
    s32 alpha;
    s32 width;
    s32 height;
    s32 facing;
    u16 particleColor;
    u16 emitterColor;
    s32 originX;
    s32 originY;
    s32 originZ;

    alpha = (ptcl->mUnk_2e_0 * (ptcl->mUnk_2e_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->mUnk_2e_10 << 24) | (mgr->mMiscPolygonAttr | 0xc0) | (alpha << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (alpha == 0) {
        return;
    }
    data_02161ac8[mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_00.mUnk_00_17](
        FX_SinIdx(ptcl->mUnk_20), FX_CosIdx(ptcl->mUnk_20), &rotationMtx);
    MTX_Identity43_(&axisMtx);
    if (mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_48.mUnk_00_31 == 0) {
        VEC_Normalize(&ptcl->mUnk_14, &forward);
    } else {
        VEC_Normalize(&ptcl->mUnk_08, &forward);
        forward.x = -forward.x;
        forward.y = -forward.y;
        forward.z = -forward.z;
    }
    refAxis.x = 0;
    refAxis.y = 0x1000;
    refAxis.z = 0;
    facing = VEC_DotProduct(&forward, &refAxis);
    if (facing > 0xccd || facing < -0xccd) {
        refAxis.x = 0x1000;
        refAxis.y = 0;
        refAxis.z = 0;
    }
    VEC_CrossProduct(&forward, &refAxis, &sideAxis);
    VEC_CrossProduct(&forward, &sideAxis, &upAxis);
    axisMtx.mRows[0].x = sideAxis.x;
    axisMtx.mRows[0].y = sideAxis.y;
    axisMtx.mRows[0].z = sideAxis.z;
    axisMtx.mRows[1].x = forward.x;
    axisMtx.mRows[1].y = forward.y;
    axisMtx.mRows[1].z = forward.z;
    axisMtx.mRows[2].x = upAxis.x;
    axisMtx.mRows[2].y = upAxis.y;
    axisMtx.mRows[2].z = upAxis.z;
    MTX_Concat43(&rotationMtx, &axisMtx, &rotationMtx);
    height = ptcl->mUnk_30;
    width = MUL_FIXED12_ROUNDED(height, mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_30);
    switch (mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_48.mUnk_00_28) {
        case 0:
            width = MUL_FIXED12_ROUNDED(width, ptcl->mUnk_34);
            height = MUL_FIXED12_ROUNDED(height, ptcl->mUnk_34);
            break;
        case 1:
            width = MUL_FIXED12_ROUNDED(width, ptcl->mUnk_34);
            break;
        case 2:
            height = MUL_FIXED12_ROUNDED(height, ptcl->mUnk_34);
            break;
    }
    MTX_Scale43_(&scaleMtx, width, height, height);
    MTX_Concat43(&scaleMtx, &rotationMtx, &worldMtx);
    if (mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_00.mUnk_00_23 == 0) {
        worldMtx.mRows[3].x = ptcl->mUnk_08.x + ptcl->mUnk_38.x;
        worldMtx.mRows[3].y = ptcl->mUnk_08.y + ptcl->mUnk_38.y;
        worldMtx.mRows[3].z = ptcl->mUnk_08.z + ptcl->mUnk_38.z;
        G3_LoadMtx43(mgr->mRenderStateViewMatrix);
        G3_MultMtx43(&worldMtx);
    } else {
        worldMtx.mRows[3].x = ptcl->mUnk_08.x + ptcl->mUnk_38.x - mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.x;
        worldMtx.mRows[3].y = ptcl->mUnk_08.y + ptcl->mUnk_38.y - mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.y;
        worldMtx.mRows[3].z = ptcl->mUnk_08.z + ptcl->mUnk_38.z - mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.z;
        reg_G3_MTX_IDENTITY = 0;
        originZ = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.z;
        originY = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.y;
        originX = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.x;
        reg_G3_MTX_TRANS = originX;
        reg_G3_MTX_TRANS = originY;
        reg_G3_MTX_TRANS = originZ;
        G3_MultMtx43(mgr->mRenderStateViewMatrix);
        G3_MultMtx43(&worldMtx);
    }
    particleColor = ptcl->mUnk_36;
    emitterColor = mgr->mRenderStateEmitter->mUnk_72;
    reg_G3_COLOR = (u16) ((((particleColor & 0x1f) * (emitterColor & 0x1f)) >> 5) |
                          ((((particleColor & 0x3e0) * (emitterColor & 0x3e0)) >> 15) << 5) |
                          ((((particleColor & 0x7c00) * (emitterColor & 0x7c00)) >> 25) << 10));
    data_02161ac0[mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_00.mUnk_00_19](
        mgr->mRenderStateEmitter->mUnk_78, mgr->mRenderStateEmitter->mUnk_7a,
        mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_50, mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_52);
}

void SPLDraw_Child_DirectionalPolygon(SPLManager *mgr, Unk0201e3c8 *ptcl) {
    MtxFx43 worldMtx;
    MtxFx43 rotationMtx;
    MtxFx43 scaleMtx;
    Vec3 forward;
    Vec3 sideAxis;
    Vec3 upAxis;
    Vec3 refAxis;
    MtxFx43 axisMtx;
    s32 alpha;
    s32 width;
    s32 height;
    s32 facing;
    u16 particleColor;
    u16 emitterColor;
    s32 originX;
    s32 originY;
    s32 originZ;

    alpha = (ptcl->mUnk_2e_0 * (ptcl->mUnk_2e_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->mUnk_2e_10 << 24) | (mgr->mMiscPolygonAttr | 0xc0) | (alpha << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (alpha == 0) {
        return;
    }
    data_02161ac8[mgr->mRenderStateEmitter->mUnk_20->mUnk_14->mUnk_00_9](FX_SinIdx(ptcl->mUnk_20),
                                                                         FX_CosIdx(ptcl->mUnk_20), &rotationMtx);
    MTX_Identity43_(&axisMtx);
    if (mgr->mRenderStateEmitter->mUnk_20->mUnk_14->mUnk_10.mUnk_00_6 == 0) {
        VEC_Normalize(&ptcl->mUnk_14, &forward);
    } else {
        VEC_Normalize(&ptcl->mUnk_08, &forward);
        forward.x = -forward.x;
        forward.y = -forward.y;
        forward.z = -forward.z;
    }
    refAxis.x = 0;
    refAxis.y = 0x1000;
    refAxis.z = 0;
    facing = VEC_DotProduct(&forward, &refAxis);
    if (facing > 0xccd || facing < -0xccd) {
        refAxis.x = 0x1000;
        refAxis.y = 0;
        refAxis.z = 0;
    }
    VEC_CrossProduct(&forward, &refAxis, &sideAxis);
    VEC_CrossProduct(&forward, &sideAxis, &upAxis);
    axisMtx.mRows[0].x = sideAxis.x;
    axisMtx.mRows[0].y = sideAxis.y;
    axisMtx.mRows[0].z = sideAxis.z;
    axisMtx.mRows[1].x = forward.x;
    axisMtx.mRows[1].y = forward.y;
    axisMtx.mRows[1].z = forward.z;
    axisMtx.mRows[2].x = upAxis.x;
    axisMtx.mRows[2].y = upAxis.y;
    axisMtx.mRows[2].z = upAxis.z;
    MTX_Concat43(&rotationMtx, &axisMtx, &rotationMtx);
    height = ptcl->mUnk_30;
    width = MUL_FIXED12_ROUNDED(height, mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_30);
    switch (mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_48.mUnk_00_28) {
        case 0:
            width = MUL_FIXED12_ROUNDED(width, ptcl->mUnk_34);
            height = MUL_FIXED12_ROUNDED(height, ptcl->mUnk_34);
            break;
        case 1:
            width = MUL_FIXED12_ROUNDED(width, ptcl->mUnk_34);
            break;
        case 2:
            height = MUL_FIXED12_ROUNDED(height, ptcl->mUnk_34);
            break;
    }
    MTX_Scale43_(&scaleMtx, width, height, height);
    MTX_Concat43(&rotationMtx, &scaleMtx, &worldMtx);
    if (mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_00.mUnk_00_23 == 0) {
        worldMtx.mRows[3].x = ptcl->mUnk_08.x + ptcl->mUnk_38.x;
        worldMtx.mRows[3].y = ptcl->mUnk_08.y + ptcl->mUnk_38.y;
        worldMtx.mRows[3].z = ptcl->mUnk_08.z + ptcl->mUnk_38.z;
        G3_LoadMtx43(mgr->mRenderStateViewMatrix);
        G3_MultMtx43(&worldMtx);
    } else {
        worldMtx.mRows[3].x = ptcl->mUnk_08.x + ptcl->mUnk_38.x - mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.x;
        worldMtx.mRows[3].y = ptcl->mUnk_08.y + ptcl->mUnk_38.y - mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.y;
        worldMtx.mRows[3].z = ptcl->mUnk_08.z + ptcl->mUnk_38.z - mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.z;
        reg_G3_MTX_IDENTITY = 0;
        originZ = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.z;
        originY = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.y;
        originX = mgr->mRenderStateEmitter->mUnk_20->mUnk_00->mUnk_04.x;
        reg_G3_MTX_TRANS = originX;
        reg_G3_MTX_TRANS = originY;
        reg_G3_MTX_TRANS = originZ;
        G3_MultMtx43(mgr->mRenderStateViewMatrix);
        G3_MultMtx43(&worldMtx);
    }
    particleColor = ptcl->mUnk_36;
    emitterColor = mgr->mRenderStateEmitter->mUnk_72;
    reg_G3_COLOR = (u16) ((((particleColor & 0x1f) * (emitterColor & 0x1f)) >> 5) |
                          ((((particleColor & 0x3e0) * (emitterColor & 0x3e0)) >> 15) << 5) |
                          ((((particleColor & 0x7c00) * (emitterColor & 0x7c00)) >> 25) << 10));
    data_02161ac0[mgr->mRenderStateEmitter->mUnk_20->mUnk_14->mUnk_00_11](mgr->mRenderStateEmitter->mUnk_7c,
                                                                          mgr->mRenderStateEmitter->mUnk_7e, 0, 0);
}

typedef enum { UNK_02019DF8_KIND_0 } Unk02019df8_Kind;

static inline void SetTexImageParam(u32 addr, Unk02019df8_Kind format, Unk02019df8_Kind sizeS, Unk02019df8_Kind sizeT,
                                    Unk02019df8_Kind wrapS, Unk02019df8_Kind wrapT,
                                    Unk02019df8_Kind color0Transparent) {
    reg_G3_TEXIMAGE_PARAM = (addr >> 3) | (format << 26) | 0x40000000 | (sizeS << 20) | (sizeT << 23) | (wrapS << 16) |
                            (wrapT << 18) | (color0Transparent << 29);
}

void SPLUtil_SetTexture(Unk020184e4_2c *tex) {
    Unk020184e4_2c_0c texParam;
    u32 scaleX;
    u32 scaleY;

    texParam = tex->mUnk_0c;
    SetTexImageParam(tex->mUnk_04, texParam.mUnk_00_0, texParam.mUnk_00_4, texParam.mUnk_00_8, texParam.mUnk_00_12,
                     texParam.mUnk_00_14, texParam.mUnk_00_16);
    reg_G3_PLTT_BASE = tex->mUnk_08 >> (4 - (texParam.mUnk_00_0 == 2 ? 1 : 0));
    reg_G3_MTX_MODE = 3;
    reg_G3_MTX_IDENTITY = 0;
    scaleX = tex->mUnk_10 << 12;
    scaleY = tex->mUnk_12 << 12;
    reg_G3_MTX_SCALE = scaleX;
    reg_G3_MTX_SCALE = scaleY;
    reg_G3_MTX_SCALE = 0;
    reg_G3_MTX_MODE = 1;
}

void SPLUtil_SetTexture_Stub(Unk020184e4_2c *tex) {}

void SPLEmitter_Init(Unk0201ca6c *emtr, Unk0201ca6c_20 *res, Vec3 *pos) {
    Unk0201ca6c_20_00 *header;

    emtr->mUnk_20 = res;
    *(u32 *) &emtr->mUnk_24 = 0;
    emtr->mUnk_28.x = pos->x + emtr->mUnk_20->mUnk_00->mUnk_04.x;
    emtr->mUnk_28.y = pos->y + emtr->mUnk_20->mUnk_00->mUnk_04.y;
    emtr->mUnk_28.z = pos->z + emtr->mUnk_20->mUnk_00->mUnk_04.z;
    emtr->mUnk_40.x = 0;
    emtr->mUnk_40.y = 0;
    emtr->mUnk_40.z = 0;
    emtr->mUnk_34.x = emtr->mUnk_34.y = emtr->mUnk_34.z = 0;
    emtr->mUnk_4c = 0;
    emtr->mUnk_4e = 0;
    header = emtr->mUnk_20->mUnk_00;
    emtr->mUnk_50 = header->mUnk_1c;
    emtr->mUnk_56 = emtr->mUnk_20->mUnk_00->mUnk_38;
    emtr->mUnk_58 = emtr->mUnk_20->mUnk_00->mUnk_10;
    emtr->mUnk_5c = emtr->mUnk_20->mUnk_00->mUnk_14;
    emtr->mUnk_60 = emtr->mUnk_20->mUnk_00->mUnk_18;
    emtr->mUnk_64 = emtr->mUnk_20->mUnk_00->mUnk_24;
    emtr->mUnk_68 = emtr->mUnk_20->mUnk_00->mUnk_28;
    emtr->mUnk_6c = emtr->mUnk_20->mUnk_00->mUnk_2c;
    emtr->mUnk_70 = emtr->mUnk_20->mUnk_00->mUnk_3e;
    emtr->mUnk_72 = 0x7fff;
    emtr->mUnk_80_0 = emtr->mUnk_20->mUnk_00->mUnk_44;
    emtr->mUnk_80_8 = emtr->mUnk_20->mUnk_00->mUnk_45;
    emtr->mUnk_80_16 = 0;
    emtr->mUnk_80_19 = 0;
    emtr->mUnk_74 = 0x80000000;
    emtr->mUnk_78 = 0x1000 << emtr->mUnk_20->mUnk_00->mUnk_48.mUnk_00_24;
    emtr->mUnk_7a = 0x1000 << emtr->mUnk_20->mUnk_00->mUnk_48.mUnk_00_26;
    if (emtr->mUnk_20->mUnk_00->mUnk_4c_0) {
        emtr->mUnk_78 *= -1;
    }
    if (emtr->mUnk_20->mUnk_00->mUnk_4c_1) {
        emtr->mUnk_7a *= -1;
    }
    if (emtr->mUnk_20->mUnk_00->mUnk_00.mUnk_00_16) {
        emtr->mUnk_7c = 0x1000 << emtr->mUnk_20->mUnk_14->mUnk_10.mUnk_00_0;
        emtr->mUnk_7e = 0x1000 << emtr->mUnk_20->mUnk_14->mUnk_10.mUnk_00_2;
        if (emtr->mUnk_20->mUnk_14->mUnk_10.mUnk_00_4) {
            emtr->mUnk_7c *= -1;
        }
        if (emtr->mUnk_20->mUnk_14->mUnk_10.mUnk_00_5) {
            emtr->mUnk_7e *= -1;
        }
    }
    emtr->mUnk_00 = emtr->mUnk_04 = 0;
    emtr->mUnk_08.mUnk_00 = emtr->mUnk_14.mUnk_00 = 0;
    emtr->mUnk_08.mUnk_04 = emtr->mUnk_14.mUnk_04 = 0;
    emtr->mUnk_90 = 0;
    emtr->mUnk_94 = 0;
    emtr->mUnk_98 = 0;
}

void SPLEmitter_Update(SPLManager *mgr, Unk0201ca6c *emtr) {
    Unk0201ca6c_20 *resource;
    s32 cnt;
    Unk0201e3c8 *particle;
    s32 index;
    s32 animCount;
    Unk0201e3c8 *next;
    Unk0201ca6c_20_14 *childAnim;
    Unk0201ca6c_20_00 *header;
    Unk0201ca6c_20_00_00 flags;
    s32 dragFactor;
    s32 childAge;
    u8 animTime[2];
    Unk020192e0_28 tbl[4];
    Unk020192e0_28 tbl2[4];
    Vec3 accel;

    resource = emtr->mUnk_20;
    childAnim = resource->mUnk_14;
    header = resource->mUnk_00;
    flags = header->mUnk_00;
    animCount = 0;
    dragFactor = header->mUnk_46 + 0x180;
    cnt = resource->mUnk_1c;

    if (emtr->mUnk_90) {
        emtr->mUnk_90(emtr, 0);
    }

    if (header->mUnk_3c == 0 || emtr->mUnk_4c < header->mUnk_3c) {
        if (emtr->mUnk_4c % emtr->mUnk_80_0 == 0 && !emtr->mUnk_24.mUnk_00_0 && !emtr->mUnk_24.mUnk_00_1 &&
            emtr->mUnk_24.mUnk_00_4) {
            SPLEmitter_EmitParticles(emtr, &mgr->mUnk_04[2]);
        }
    }

    if (flags.mUnk_00_8) {
        tbl[animCount].mUnk_00 = SPLAnim_Scale;
        tbl[animCount++].mUnk_04 = resource->mUnk_04->mUnk_08_0;
    }
    if (flags.mUnk_00_9 && !resource->mUnk_08->mUnk_08_0) {
        tbl[animCount].mUnk_00 = SPLAnim_Color;
        tbl[animCount++].mUnk_04 = resource->mUnk_08->mUnk_08_1;
    }
    if (flags.mUnk_00_10) {
        tbl[animCount].mUnk_00 = SPLAnim_Alpha;
        tbl[animCount++].mUnk_04 = resource->mUnk_0c->mUnk_02_8;
    }
    if (flags.mUnk_00_11 && !resource->mUnk_10->mUnk_08_16) {
        tbl[animCount].mUnk_00 = SPLAnim_Texture;
        tbl[animCount++].mUnk_04 = resource->mUnk_10->mUnk_08_17;
    }

    for (particle = emtr->mUnk_08.mUnk_00; particle; particle = next) {
        next = particle->mUnk_00;
        animTime[0] = (particle->mUnk_2a * particle->mUnk_26) >> 8;
        animTime[1] = particle->mUnk_2d + ((particle->mUnk_28 * particle->mUnk_26) >> 8);
        for (index = 0; index < animCount; index++) {
            tbl[index].mUnk_00(particle, resource, animTime[tbl[index].mUnk_04]);
        }
        accel.x = accel.y = accel.z = 0;
        if (flags.mUnk_00_15) {
            particle->mUnk_38 = emtr->mUnk_28;
        }
        for (index = 0; index < cnt; index++) {
            resource->mUnk_18[index].mUnk_00(resource->mUnk_18[index].mUnk_04, particle, &accel, emtr);
        }
        particle->mUnk_20 += particle->mUnk_22;
        particle->mUnk_14.x = (particle->mUnk_14.x * dragFactor) >> 9;
        particle->mUnk_14.y = (particle->mUnk_14.y * dragFactor) >> 9;
        particle->mUnk_14.z = (particle->mUnk_14.z * dragFactor) >> 9;
        particle->mUnk_14.x += accel.x;
        particle->mUnk_14.y += accel.y;
        particle->mUnk_14.z += accel.z;
        particle->mUnk_08.x += particle->mUnk_14.x + emtr->mUnk_34.x;
        particle->mUnk_08.y += particle->mUnk_14.y + emtr->mUnk_34.y;
        particle->mUnk_08.z += particle->mUnk_14.z + emtr->mUnk_34.z;
        if (flags.mUnk_00_16) {
            childAge = (particle->mUnk_26 << 12) -
                       (MUL_FIXED12_ROUNDED(particle->mUnk_24 << 12, childAnim->mUnk_0d << 12) >> 8);
            if (childAge >= 0 && (childAge >> 12) % childAnim->mUnk_0e == 0) {
                SPLEmitter_EmitChildren(particle, emtr, &mgr->mUnk_04[2]);
            }
        }
        if (emtr->mUnk_20->mUnk_00->mUnk_00.mUnk_00_30) {
            particle->mUnk_2e_10 = mgr->mPolygonIDFix;
        } else {
            particle->mUnk_2e_10 = mgr->mPolygonIDCurrent;
            mgr->mPolygonIDCurrent++;
            if (mgr->mPolygonIDCurrent > mgr->mPolygonIDMax) {
                mgr->mPolygonIDCurrent = mgr->mPolygonIDMin;
            }
        }
        particle->mUnk_26++;
        if (particle->mUnk_26 > particle->mUnk_24) {
            SPLList_PushFront(&mgr->mUnk_04[2], SPLList_Erase(&emtr->mUnk_08, particle));
        }
    }

    if (flags.mUnk_00_16) {
        animCount = 0;
        if (childAnim->mUnk_00_1) {
            tbl2[animCount].mUnk_00 = SPLAnim_ChildScale;
            tbl2[animCount++].mUnk_04 = 0;
        }
        if (childAnim->mUnk_00_2) {
            tbl2[animCount].mUnk_00 = SPLAnim_ChildAlpha;
            tbl2[animCount++].mUnk_04 = 0;
        }
        if (!childAnim->mUnk_00_0) {
            cnt = 0;
        }
        for (particle = emtr->mUnk_14.mUnk_00; particle; particle = next) {
            next = particle->mUnk_00;
            animTime[0] = (particle->mUnk_26 << 8) / particle->mUnk_24;
            for (index = 0; index < animCount; index++) {
                tbl2[index].mUnk_00(particle, resource, animTime[0]);
            }
            accel.x = accel.y = accel.z = 0;
            if (childAnim->mUnk_00_5) {
                particle->mUnk_38 = emtr->mUnk_28;
            }
            for (index = 0; index < cnt; index++) {
                resource->mUnk_18[index].mUnk_00(resource->mUnk_18[index].mUnk_04, particle, &accel, emtr);
            }
            particle->mUnk_20 += particle->mUnk_22;
            particle->mUnk_14.x = (particle->mUnk_14.x * dragFactor) >> 9;
            particle->mUnk_14.y = (particle->mUnk_14.y * dragFactor) >> 9;
            particle->mUnk_14.z = (particle->mUnk_14.z * dragFactor) >> 9;
            particle->mUnk_14.x += accel.x;
            particle->mUnk_14.y += accel.y;
            particle->mUnk_14.z += accel.z;
            particle->mUnk_08.x += particle->mUnk_14.x + emtr->mUnk_34.x;
            particle->mUnk_08.y += particle->mUnk_14.y + emtr->mUnk_34.y;
            particle->mUnk_08.z += particle->mUnk_14.z + emtr->mUnk_34.z;
            if (emtr->mUnk_20->mUnk_00->mUnk_00.mUnk_00_31) {
                particle->mUnk_2e_10 = mgr->mPolygonIDFix;
            } else {
                particle->mUnk_2e_10 = mgr->mPolygonIDCurrent;
                mgr->mPolygonIDCurrent++;
                if (mgr->mPolygonIDCurrent > mgr->mPolygonIDMax) {
                    mgr->mPolygonIDCurrent = mgr->mPolygonIDMin;
                }
            }
            particle->mUnk_26++;
            if (particle->mUnk_26 > particle->mUnk_24) {
                SPLList_PushFront(&mgr->mUnk_04[2], SPLList_Erase(&emtr->mUnk_14, particle));
            }
        }
    }

    emtr->mUnk_4c++;
    if (emtr->mUnk_90) {
        emtr->mUnk_90(emtr, 1);
    }
}

void SPLManager_DrawParticles(SPLManager *mgr) {
    Unk0201ca6c *emitter;
    Unk0201ca6c_20_00 *header;
    void (*drawFunc)(SPLManager *mgr, Unk0201e3c8 *b);
    void (*textureFunc)(Unk020184e4_2c *mgr);
    Unk0201e3c8 *particle;

    emitter = mgr->mRenderStateEmitter;
    header = emitter->mUnk_20->mUnk_00;
    drawFunc = 0;
    SPLUtil_SetTexture(mgr->mTextures + header->mUnk_47);
    switch (header->mUnk_00.mUnk_00_4) {
        case 0:
            drawFunc = SPLDraw_Billboard;
            break;
        case 1:
            drawFunc = SPLDraw_DirectionalBillboard;
            break;
        case 2:
            drawFunc = SPLDraw_Polygon;
            break;
        case 3:
            drawFunc = SPLDraw_DirectionalPolygon;
            break;
        case 4:
            drawFunc = SPLDraw_DirectionalPolygon;
            break;
    }
    if (header->mUnk_00.mUnk_00_11) {
        textureFunc = SPLUtil_SetTexture;
    } else {
        textureFunc = SPLUtil_SetTexture_Stub;
    }
    for (particle = emitter->mUnk_08.mUnk_00; particle != 0; particle = particle->mUnk_00) {
        textureFunc(mgr->mTextures + particle->mUnk_2c);
        drawFunc(mgr, particle);
    }
}

void SPLManager_DrawChildParticles(SPLManager *mgr) {
    Unk0201ca6c *emitter;
    Unk0201ca6c_20 *resource;
    void (*drawFunc)(SPLManager *mgr, Unk0201e3c8 *b);
    Unk0201e3c8 *particle;

    emitter = mgr->mRenderStateEmitter;
    drawFunc = 0;
    resource = emitter->mUnk_20;
    if (resource->mUnk_00->mUnk_00.mUnk_00_16 == 0) {
        return;
    }
    SPLUtil_SetTexture(mgr->mTextures + resource->mUnk_14->mUnk_0f);
    switch (resource->mUnk_14->mUnk_00_7) {
        case 0:
            drawFunc = SPLDraw_Child_Billboard;
            break;
        case 1:
            drawFunc = SPLDraw_Child_DirectionalBillboard;
            break;
        case 2:
            drawFunc = SPLDraw_Child_Polygon;
            break;
        case 3:
            drawFunc = SPLDraw_Child_DirectionalPolygon;
            break;
        case 4:
            drawFunc = SPLDraw_Child_DirectionalPolygon;
            break;
    }
    for (particle = emitter->mUnk_14.mUnk_00; particle != 0; particle = particle->mUnk_00) {
        drawFunc(mgr, particle);
    }
}

void SPLManager_DoDraw(SPLManager *mgr) {
    Unk0201ca6c_20_00 *header;

    header = mgr->mRenderStateEmitter->mUnk_20->mUnk_00;
    if (header->mUnk_00.mUnk_00_21) {
        SPLManager_DrawChildParticles(mgr);
        if (header->mUnk_00.mUnk_00_22) {
            return;
        }
        SPLManager_DrawParticles(mgr);
    } else {
        if (header->mUnk_00.mUnk_00_22 == 0) {
            SPLManager_DrawParticles(mgr);
        }
        SPLManager_DrawChildParticles(mgr);
    }
}

void SPLUtil_SetCylinderEmitterDir(Unk0201ca6c *emtr, Vec3 *pointA, Vec3 *pointB) {
    Vec3 dir;

    if (emtr->mUnk_20->mUnk_00->mUnk_00.mUnk_00_0 - 6 > 1) {
        return;
    }
    emtr->mUnk_28.x = (pointB->x + pointA->x) / 2;
    emtr->mUnk_28.y = (pointB->y + pointA->y) / 2;
    emtr->mUnk_28.z = (pointB->z + pointA->z) / 2;
    emtr->mUnk_60 = VEC_Distance(pointA, pointB) / 2;
    dir.x = pointB->x - pointA->x;
    dir.y = pointB->y - pointA->y;
    dir.z = pointB->z - pointA->z;
    VEC_Normalize(&dir, &dir);
    emtr->mUnk_50.x = dir.x;
    emtr->mUnk_50.y = dir.y;
    emtr->mUnk_50.z = dir.z;
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
    s32 index;
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
    mgr->mUnk_38_25 = 0;
    mgr->mAlloc = alloc;
    mgr->mUnk_04[0].mUnk_04 = 0;
    mgr->mUnk_04[1].mUnk_04 = 0;
    mgr->mUnk_04[2].mUnk_04 = 0;
    mgr->mUnk_04[0].mUnk_00 = 0;
    mgr->mUnk_04[1].mUnk_00 = 0;
    mgr->mUnk_04[2].mUnk_00 = 0;
    mgr->mMiscPolygonAttr = 0;
    mgr->mCurrentCycle = 0;
    block = alloc(maxEmitters * 0x9c);
    MI_CpuFill8(block, 0, maxEmitters * 0x9c);
    for (index = 0; index < maxEmitters; index++) {
        SPLList_PushFront(&mgr->mUnk_04[1], (Unk0201e3c8 *) block);
        block += 0x9c;
    }
    block = alloc(maxParticles * 0x44);
    MI_CpuFill8(block, 0, maxParticles * 0x44);
    for (index = 0; index < maxParticles; index++) {
        SPLList_PushFront(&mgr->mUnk_04[2], (Unk0201e3c8 *) block);
        block += 0x44;
    }
    mgr->mResources = 0;
    mgr->mTextures = 0;
    mgr->mTexCount = 0;
    mgr->mResCount = mgr->mTexCount;
    return mgr;
}

void SPLManager_LoadResources(SPLManager *mgr, Unk02018a1c *data) {
    s32 index;
    s32 off;
    Unk0201ca6c_20 *resource;
    Unk0201ca6c_20_00_00 flags;
    Unk0201ca6c_20_18 *behaviorEntry;
    Unk020184e4_2c *texture;
    Unk020184e4_2c_00 *textureHeader;

    off = 0x20;
    mgr->mResCount = data->mUnk_08;
    mgr->mTexCount = data->mUnk_0a;
    mgr->mResources = mgr->mAlloc(mgr->mResCount << 5);
    MI_CpuFill8(mgr->mResources, 0, mgr->mResCount << 5);
    for (index = 0; index < mgr->mResCount; index++) {
        resource = mgr->mResources + index;
        resource->mUnk_00 = OFFSET_PTR(Unk0201ca6c_20_00, data, off);
        off += 0x58;
        flags = resource->mUnk_00->mUnk_00;
        if (flags.mUnk_00_8) {
            resource->mUnk_04 = OFFSET_PTR(Unk0201ca6c_20_04, data, off);
            off += 0xc;
        } else {
            resource->mUnk_04 = 0;
        }
        if (flags.mUnk_00_9) {
            resource->mUnk_08 = OFFSET_PTR(Unk0201ca6c_20_08, data, off);
            off += 0xc;
        } else {
            resource->mUnk_08 = 0;
        }
        if (flags.mUnk_00_10) {
            resource->mUnk_0c = OFFSET_PTR(Unk0201ca6c_20_0c, data, off);
            off += 8;
        } else {
            resource->mUnk_0c = 0;
        }
        if (flags.mUnk_00_11) {
            resource->mUnk_10 = OFFSET_PTR(Unk0201ca6c_20_10, data, off);
            off += 0xc;
        } else {
            resource->mUnk_10 = 0;
        }
        if (flags.mUnk_00_16) {
            resource->mUnk_14 = OFFSET_PTR(Unk0201ca6c_20_14, data, off);
            off += 0x14;
        } else {
            resource->mUnk_14 = 0;
        }
        resource->mUnk_1c = flags.mUnk_00_24 + flags.mUnk_00_25 + flags.mUnk_00_26 + flags.mUnk_00_27 +
                            flags.mUnk_00_28 + flags.mUnk_00_29;
        if (resource->mUnk_1c != 0) {
            resource->mUnk_18 = mgr->mAlloc(resource->mUnk_1c << 3);
            behaviorEntry = resource->mUnk_18;
            if (flags.mUnk_00_24) {
                behaviorEntry->mUnk_04 = (u8 *) data + off;
                behaviorEntry->mUnk_00 = SPLBehavior_ApplyGravity;
                off += 8;
                behaviorEntry++;
            }
            if (flags.mUnk_00_25) {
                behaviorEntry->mUnk_04 = (u8 *) data + off;
                behaviorEntry->mUnk_00 = SPLBehavior_ApplyRandom;
                off += 8;
                behaviorEntry++;
            }
            if (flags.mUnk_00_26) {
                behaviorEntry->mUnk_04 = (u8 *) data + off;
                behaviorEntry->mUnk_00 = SPLBehavior_ApplyMagnet;
                off += 0x10;
                behaviorEntry++;
            }
            if (flags.mUnk_00_27) {
                behaviorEntry->mUnk_04 = (u8 *) data + off;
                behaviorEntry->mUnk_00 = SPLBehavior_ApplySpin;
                off += 4;
                behaviorEntry++;
            }
            if (flags.mUnk_00_28) {
                behaviorEntry->mUnk_04 = (u8 *) data + off;
                behaviorEntry->mUnk_00 = SPLBehavior_ApplyCollisionPlane;
                off += 8;
                behaviorEntry++;
            }
            if (flags.mUnk_00_29) {
                behaviorEntry->mUnk_04 = (u8 *) data + off;
                behaviorEntry->mUnk_00 = SPLBehavior_ApplyConvergence;
                off += 0x10;
            }
        } else {
            resource->mUnk_18 = 0;
        }
    }
    mgr->mTextures = mgr->mAlloc(mgr->mTexCount * 0x14);
    MI_CpuFill8(mgr->mTextures, 0, mgr->mTexCount * 0x14);
    for (index = 0; index < mgr->mTexCount; index++) {
        texture = mgr->mTextures + index;
        textureHeader = OFFSET_PTR(Unk020184e4_2c_00, data, off);
        texture->mUnk_00 = textureHeader;
        texture->mUnk_10 = 1 << (textureHeader->mUnk_04.mUnk_00_4 + 3);
        texture->mUnk_12 = 1 << (textureHeader->mUnk_04.mUnk_00_8 + 3);
        texture->mUnk_0c = textureHeader->mUnk_04;
        off += textureHeader->mUnk_1c;
    }
}

s32 SPLManager_UploadTexturesEx(SPLManager *mgr, u32 (*vramAlloc)(s32 size, s32 isSpecial)) {
    s32 index;
    Unk020184e4_2c *texture;
    Unk020184e4_2c_00 *textureHeader;
    u32 vramAddr;

    GX_BeginLoadTex();
    for (index = 0; index < mgr->mTexCount; index++) {
        texture = mgr->mTextures + index;
        textureHeader = texture->mUnk_00;
        if (textureHeader->mUnk_04.mUnk_00_17) {
            texture->mUnk_04 = mgr->mTextures[textureHeader->mUnk_04.mUnk_00_18].mUnk_04;
        } else {
            vramAddr = vramAlloc(textureHeader->mUnk_08, textureHeader->mUnk_04.mUnk_00_0 == 5 ? 1 : 0);
            GX_LoadTex((u8 *) texture->mUnk_00 + 0x20, vramAddr, textureHeader->mUnk_08);
            texture->mUnk_04 = vramAddr;
        }
    }
    GX_EndLoadTex();
    return 1;
}

s32 SPLManager_UploadPalettesEx(SPLManager *mgr, u32 (*vramAlloc)(s32 size, s32 isSpecial)) {
    s32 index;
    Unk020184e4_2c *texture;
    Unk020184e4_2c_00 *textureHeader;
    u32 vramAddr;

    GX_BeginLoadTexPltt();
    for (index = 0; index < mgr->mTexCount; index++) {
        texture = mgr->mTextures + index;
        textureHeader = texture->mUnk_00;
        vramAddr = 0;
        if (textureHeader->mUnk_10 != 0) {
            vramAddr = vramAlloc(textureHeader->mUnk_10, textureHeader->mUnk_04.mUnk_00_0 == 2 ? 1 : 0);
            GX_LoadTexPltt((u8 *) texture->mUnk_00 + textureHeader->mUnk_0c, vramAddr, textureHeader->mUnk_10);
        }
        texture->mUnk_08 = vramAddr;
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

    for (emtr = (Unk0201ca6c *) mgr->mUnk_04[0].mUnk_00; emtr != 0; emtr = next) {
        header = emtr->mUnk_20->mUnk_00;
        next = emtr->mUnk_00;
        if (emtr->mUnk_24.mUnk_00_4 == 0) {
            if (emtr->mUnk_4c >= header->mUnk_32) {
                emtr->mUnk_24.mUnk_00_4 = 1;
                emtr->mUnk_4c = 0;
            }
        }
        if (emtr->mUnk_24.mUnk_00_2 == 0) {
            if (emtr->mUnk_80_16 == 0 || mgr->mCurrentCycle == emtr->mUnk_80_16 - 1) {
                SPLEmitter_Update(mgr, emtr);
            }
        }
        if ((header->mUnk_00.mUnk_00_14 && header->mUnk_3c != 0 && emtr->mUnk_24.mUnk_00_4 != 0 &&
             emtr->mUnk_4c > header->mUnk_3c) ||
            emtr->mUnk_24.mUnk_00_0 != 0) {
            if (emtr->mUnk_08.mUnk_04 == 0 && emtr->mUnk_14.mUnk_04 == 0) {
                SPLList_PushFront(&mgr->mUnk_04[1], SPLList_Erase(&mgr->mUnk_04[0], (Unk0201e3c8 *) emtr));
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
        for (emtr = (Unk0201ca6c *) mgr->mUnk_04[0].mUnk_00; emtr != 0; emtr = emtr->mUnk_00) {
            mgr->mRenderStateEmitter = emtr;
            if (emtr->mUnk_24.mUnk_00_3 == 0) {
                SPLManager_DoDraw(mgr);
            }
        }
    } else {
        for (emtr = (Unk0201ca6c *) mgr->mUnk_04[0].mUnk_08; emtr != 0; emtr = emtr->mUnk_04) {
            mgr->mRenderStateEmitter = emtr;
            if (emtr->mUnk_24.mUnk_00_3 == 0) {
                SPLManager_DoDraw(mgr);
            }
        }
    }
}

Unk0201ca6c *SPLManager_CreateEmitter(SPLManager *mgr, s32 resourceId, Vec3 *pos) {
    Unk0201ca6c *emtr;

    emtr = 0;
    if (mgr->mUnk_04[1].mUnk_00 != 0) {
        emtr = (Unk0201ca6c *) SPLList_PopFront(&mgr->mUnk_04[1]);
        SPLEmitter_Init(emtr, mgr->mResources + resourceId, pos);
        SPLList_PushFront(&mgr->mUnk_04[0], (Unk0201e3c8 *) emtr);
        if (emtr->mUnk_20->mUnk_00->mUnk_00.mUnk_00_14) {
            emtr = 0;
        }
    }
    return emtr;
}

Unk0201ca6c *SPLManager_CreateEmitterWithCallbackEx(SPLManager *mgr, s32 resourceId, Vec3 *pos, s32 param,
                                                    void (*initCallback)(Unk0201ca6c *emtr, s32 param)) {
    Unk0201ca6c *emtr;

    emtr = 0;
    if (mgr->mUnk_04[1].mUnk_00 != 0) {
        emtr = (Unk0201ca6c *) SPLList_PopFront(&mgr->mUnk_04[1]);
        SPLEmitter_Init(emtr, mgr->mResources + resourceId, pos);
        if (initCallback != 0) {
            initCallback(emtr, param);
        }
        SPLList_PushFront(&mgr->mUnk_04[0], (Unk0201e3c8 *) emtr);
        if (emtr->mUnk_20->mUnk_00->mUnk_00.mUnk_00_14) {
            emtr = 0;
        }
    }
    return emtr;
}

void SPLManager_DeleteEmitter(SPLManager *mgr, Unk0201ca6c *emtr) {
    Unk0201e3c8 *particle;

    while ((particle = SPLList_PopFront(&emtr->mUnk_08)) != 0) {
        SPLList_PushFront(&mgr->mUnk_04[2], particle);
    }
    while ((particle = SPLList_PopFront(&emtr->mUnk_14)) != 0) {
        SPLList_PushFront(&mgr->mUnk_04[2], particle);
    }
    SPLList_Erase(&mgr->mUnk_04[0], (Unk0201e3c8 *) emtr);
    SPLList_PushFront(&mgr->mUnk_04[1], (Unk0201e3c8 *) emtr);
}
