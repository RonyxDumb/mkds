#include "particle_system.h"

#include "matrix_3x3_basic.h"
#include "matrix_4x3_basic.h"
#include "fixed_vector_math.h"
#include "geometry_matrix_commands.h"
#include "vram_load_3d_graphics.h"
#include "cpu_copy_clear_16.h"
#include "model_material_set.h"
#include "Main/Graphics/animation_function_pointers.h"
#include "particle_random_state.h"
#include "linked_palette_vram_alloc.h"
#include "microphone_sampling.h"
#include "linked_texture_vram_alloc.h"
#include "cpu_copy_fill.h"
#include "registers.h"
#include "particle_rotate_matrix.h"
#include "particle_instance.h"
#include "frame_texture_vram_alloc.h"

u32 gSplRandomState;
void (*gSplPlaneDrawFunctions[2])(u32 texCoordU, u32 texCoordV, s32 centerA, s32 centerB) = {SPLUtil_DrawXYPlane,
                                                                                    SPLUtil_DrawXZPlane};
void (*gSplRotateFunctions[2])(s32 sinValue, s32 cosValue, MtxFx43 *mtx) = {SPLUtil_RotateY, SPLUtil_RotateXYZ};

void SPLRandom_VecFx32(Vec3 *vec) {
    vec->x = (s32) (gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 8;
    vec->y = (s32) (gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 8;
    vec->z = (s32) (gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 8;
    VecFx32_Normalize(vec, vec);
}

void SPLRandom_VecFx32_XY(Vec3 *vec) {
    vec->x = (s32) (gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 8;
    vec->y = (s32) (gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 8;
    vec->z = 0;
    VecFx32_Normalize(vec, vec);
}

void SPLList_PushFront(ParticleList *list, ParticleInstance *node) {
    if (list->mFront == 0) {
        list->mFront = node;
        list->mBack = node;
        node->mNext = 0;
        node->mPrev = node->mNext;
    } else {
        node->mNext = list->mFront;
        node->mPrev = 0;
        list->mFront->mPrev = node;
        list->mFront = node;
    }
    list->mCount++;
}

ParticleInstance *SPLList_PopFront(ParticleList *list) {
    ParticleInstance *first;
    ParticleInstance *node;

    node = 0;
    first = list->mFront;
    if (first != 0) {
        node = first;
        list->mFront = first->mNext;
        if (list->mFront != 0) {
            first->mNext->mPrev = 0;
        } else {
            list->mFront = 0;
            list->mBack = 0;
        }
        list->mCount--;
    }
    return node;
}

ParticleInstance *SPLList_Erase(ParticleList *list, ParticleInstance *node) {
    ParticleInstance *next;

    next = node->mNext;
    if (next == 0) {
        if (list->mFront == node) {
            list->mFront = 0;
            list->mBack = 0;
        } else {
            node->mPrev->mNext = 0;
            list->mBack = list->mBack->mPrev;
        }
    } else {
        if (list->mFront == node) {
            list->mFront = next;
            list->mFront->mPrev = 0;
        } else {
            next->mPrev = node->mPrev;
            node->mPrev->mNext = node->mNext;
        }
    }
    list->mCount--;
    return node;
}

void SPLBehavior_ApplyGravity(const Vec3s16 *gravity, ParticleInstance *ptcl, Vec3 *acc, ParticleEmitter *emtr) {
    acc->x = acc->x + gravity->x;
    acc->y = acc->y + gravity->y;
    acc->z = acc->z + gravity->z;
}

void SPLBehavior_ApplyRandom(const ParticleBehaviorRandom *rng, ParticleInstance *ptcl, Vec3 *acc,
                             ParticleEmitter *emtr) {
    if (ptcl->mAge % rng->mInterval != 0) {
        return;
    }
    acc->x = acc->x + ((rng->mRangeX * (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) -
                        (rng->mRangeX << 8)) >>
                       8);
    acc->y = acc->y + ((rng->mRangeY * (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) -
                        (rng->mRangeY << 8)) >>
                       8);
    acc->z = acc->z + ((rng->mRangeZ * (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) -
                        (rng->mRangeZ << 8)) >>
                       8);
}

void SPLBehavior_ApplyMagnet(const ParticleBehaviorPoint *magnet, ParticleInstance *ptcl, Vec3 *acc,
                             ParticleEmitter *emtr) {
    acc->x = acc->x + ((magnet->mFactor * (magnet->mPoint.x - ptcl->mOffset.x - ptcl->mVelocity.x)) >> 12);
    acc->y = acc->y + ((magnet->mFactor * (magnet->mPoint.y - ptcl->mOffset.y - ptcl->mVelocity.y)) >> 12);
    acc->z = acc->z + ((magnet->mFactor * (magnet->mPoint.z - ptcl->mOffset.z - ptcl->mVelocity.z)) >> 12);
}

void SPLBehavior_ApplySpin(const ParticleBehaviorSpin *spin, ParticleInstance *ptcl, Vec3 *acc, ParticleEmitter *emtr) {
    MtxFx33 buf;

    switch (spin->mAxis) {
        case PARTICLE_SPIN_AXIS_X:
            MTX_RotX33__from_thumb(&buf, FX_SinIdx(spin->mAngle), FX_CosIdx(spin->mAngle));
            break;
        case PARTICLE_SPIN_AXIS_Y:
            MTX_RotY33__from_thumb(&buf, FX_SinIdx(spin->mAngle), FX_CosIdx(spin->mAngle));
            break;
        case PARTICLE_SPIN_AXIS_Z:
            MTX_RotZ33__from_thumb(&buf, FX_SinIdx(spin->mAngle), FX_CosIdx(spin->mAngle));
            break;
    }
    MTX_MultVec33(&ptcl->mOffset, &buf, &ptcl->mOffset);
}

void SPLBehavior_ApplyCollisionPlane(const ParticleBehaviorCollisionPlane *plane, ParticleInstance *ptcl, Vec3 *acc,
                                     ParticleEmitter *emtr) {
    s32 lim;
    s32 particleY;

    lim = plane->mPlaneY;
    if (emtr->mPlaneY != SPL_UNSET_PLANE) {
        lim = emtr->mPlaneY;
    }
    switch (plane->mMode) {
        case 0:
            particleY = ptcl->mEmitterPosition.y;
            if (particleY < lim) {
                if (particleY + ptcl->mOffset.y > lim) {
                    ptcl->mOffset.y = lim - particleY;
                    ptcl->mAge = ptcl->mLife;
                    return;
                }
            }
            if (particleY >= lim) {
                if (particleY + ptcl->mOffset.y < lim) {
                    ptcl->mOffset.y = lim - particleY;
                    ptcl->mAge = ptcl->mLife;
                }
            }
            break;
        case 1:
            particleY = ptcl->mEmitterPosition.y;
            if (particleY < lim && particleY + ptcl->mOffset.y > lim) {
                ptcl->mOffset.y = lim - particleY;
                ptcl->mVelocity.y = -MUL_FIXED12_ROUNDED(ptcl->mVelocity.y, plane->mBounceFactor);
            } else if (particleY >= lim && particleY + ptcl->mOffset.y < lim) {
                ptcl->mOffset.y = lim - particleY;
                ptcl->mVelocity.y = -MUL_FIXED12_ROUNDED(ptcl->mVelocity.y, plane->mBounceFactor);
            }
            break;
    }
}

void SPLBehavior_ApplyConvergence(const ParticleBehaviorPoint *conv, ParticleInstance *ptcl, Vec3 *acc,
                                  ParticleEmitter *emtr) {
    ptcl->mOffset.x = ptcl->mOffset.x + MUL_FIXED12_ROUNDED(conv->mFactor, conv->mPoint.x - ptcl->mOffset.x);
    ptcl->mOffset.y = ptcl->mOffset.y + MUL_FIXED12_ROUNDED(conv->mFactor, conv->mPoint.y - ptcl->mOffset.y);
    ptcl->mOffset.z = ptcl->mOffset.z + MUL_FIXED12_ROUNDED(conv->mFactor, conv->mPoint.z - ptcl->mOffset.z);
}

void SPLAnim_Scale(ParticleInstance *ptcl, ParticleResource *res, s32 lifeRate) {
    ParticleScaleAnim *scaleAnim;
    s32 scale;
    s32 lo;
    s32 hi;

    scaleAnim = res->mScaleAnim;
    lo = scaleAnim->mMidStart;
    hi = scaleAnim->mMidEnd;
    if (lifeRate < lo) {
        scale = scaleAnim->mStartScale;
        ptcl->mScale = scale + (lifeRate * (scaleAnim->mMidScale - scale)) / lo;
        return;
    }
    if (lifeRate < hi) {
        ptcl->mScale = scaleAnim->mMidScale;
        return;
    }
    scale = scaleAnim->mEndScale;
    ptcl->mScale = scale + ((lifeRate - 0xff) * (scale - scaleAnim->mMidScale)) / (0xff - hi);
}

void SPLAnim_Color(ParticleInstance *ptcl, ParticleResource *res, s32 lifeRate) {
    ParticleColorAnim *colorAnim;
    ParticleResourceHeader *header;
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

    colorAnim = res->mColorAnim;
    header = res->mHeader;
    lo = colorAnim->mFirstBlendStart;
    mid = colorAnim->mFirstBlendEnd;
    hi = colorAnim->mSecondBlendEnd;
    if (lifeRate < lo) {
        ptcl->mColor = colorAnim->mStartColor;
        return;
    }
    if (lifeRate < mid) {
        ar = colorAnim->mStartColor & SPL_COLOR_CHANNEL_MASK;
        ag = (colorAnim->mStartColor >> 5) & SPL_COLOR_CHANNEL_MASK;
        ab = (colorAnim->mStartColor >> 10) & SPL_COLOR_CHANNEL_MASK;
        br = header->mColor & SPL_COLOR_CHANNEL_MASK;
        bg = (header->mColor >> 5) & SPL_COLOR_CHANNEL_MASK;
        bb = (header->mColor >> 10) & SPL_COLOR_CHANNEL_MASK;
        if (colorAnim->mBlend == 0) {
            ptcl->mColor = br | (bg << 5) | (bb << 10);
            return;
        }
        elapsed = lifeRate - lo;
        span = mid - lo;
        ptcl->mColor = (ar + (elapsed * (br - ar)) / span) | ((ag + (elapsed * (bg - ag)) / span) << 5) |
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
        er = header->mColor & SPL_COLOR_CHANNEL_MASK;
        eg = (header->mColor >> 5) & SPL_COLOR_CHANNEL_MASK;
        eb = (header->mColor >> 10) & SPL_COLOR_CHANNEL_MASK;
        cr = colorAnim->mEndColor & SPL_COLOR_CHANNEL_MASK;
        cg = (colorAnim->mEndColor >> 5) & SPL_COLOR_CHANNEL_MASK;
        cb = (colorAnim->mEndColor >> 10) & SPL_COLOR_CHANNEL_MASK;
        if (colorAnim->mBlend == 0) {
            ptcl->mColor = cr | (cg << 5) | (cb << 10);
            return;
        }
        elapsed = lifeRate - mid;
        span = hi - mid;
        ptcl->mColor = (er + (elapsed * (cr - er)) / span) | ((eg + (elapsed * (cg - eg)) / span) << 5) |
                       ((eb + (elapsed * (cb - eb)) / span) << 10);
        return;
    }
    ptcl->mColor = colorAnim->mEndColor;
}

void SPLAnim_Alpha(ParticleInstance *ptcl, ParticleResource *res, s32 lifeRate) {
    ParticleAlphaAnim *alphaAnim;
    s32 alpha;
    s32 lo;
    s32 hi;

    alphaAnim = res->mAlphaAnim;
    lo = alphaAnim->mMidStartRate;
    hi = alphaAnim->mMidEndRate;
    if (lifeRate < lo) {
        alpha = alphaAnim->mStartAlpha + (lifeRate * (alphaAnim->mMidAlpha - alphaAnim->mStartAlpha)) / lo;
    } else if (lifeRate < hi) {
        alpha = alphaAnim->mMidAlpha;
    } else {
        alpha =
            alphaAnim->mEndAlpha + ((lifeRate - 0xff) * (alphaAnim->mEndAlpha - alphaAnim->mMidAlpha)) / (0xff - hi);
    }
    ptcl->mAnimAlpha =
        (alpha * (0xff - ((alphaAnim->mAlphaRandom *
                           (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 24)) >>
                          8))) >>
        8;
}

void SPLAnim_Texture(ParticleInstance *ptcl, ParticleResource *res, s32 lifeRate) {
    ParticleTextureAnim *texAnim;
    s32 frameIndex;
    s32 frameEnd;
    s32 frameLength;
    s32 frameCount;

    texAnim = res->mTextureAnim;
    frameIndex = 0;
    frameCount = texAnim->mFrameCount;
    if (frameCount <= 0) {
        return;
    }
    frameLength = texAnim->mFrameLength;
    frameEnd = 0;
    do {
        if (lifeRate < frameEnd + frameLength) {
            ptcl->mTextureIndex = texAnim->mTextureIndices[frameIndex];
            return;
        }
        frameEnd += texAnim->mFrameLength;
        frameIndex++;
    } while (frameIndex < frameCount);
}

void SPLAnim_ChildScale(ParticleInstance *ptcl, ParticleResource *res, s32 lifeRate) {
    s32 scale;

    scale = res->mChildAnim->mEndScale;
    ptcl->mScale = scale + ((scale - 0x1000) * (lifeRate - 0xff)) / 0xff;
}

void SPLAnim_ChildAlpha(ParticleInstance *ptcl, ParticleResource *res, s32 lifeRate) {
    ptcl->mAnimAlpha = ((0xff - lifeRate) * SPL_ALPHA_MAX) / 0xff;
}

void SPLEmitter_ComputeOrthogonalAxes(ParticleEmitter *emtr) {
    Vec3s16 up;
    Vec3s16 axis;
    s32 dot;

    up = gSplEmitterUpAxis;
    switch (emtr->mResource->mHeader->mFlags.mAxis) {
        case PARTICLE_EMIT_AXIS_X:
            axis.x = 0x1000;
            axis.y = 0;
            axis.z = 0;
            break;
        case PARTICLE_EMIT_AXIS_Y:
            axis.x = 0;
            axis.y = 0x1000;
            axis.z = 0;
            break;
        case PARTICLE_EMIT_AXIS_Z:
            axis.x = 0;
            axis.y = 0;
            axis.z = 0x1000;
            break;
        default:
            VecFx16_Normalize(&emtr->mDirection, &axis);
            break;
    }
    dot = VecFx16_DotProduct(&up, &axis);
    if (dot == 0x1000 || dot == -0x1000) {
        up.x = 0x1000;
        up.y = 0;
        up.z = 0;
    }
    emtr->mAxisX.x = MUL_FIXED12_ROUNDED(axis.y, up.z) - MUL_FIXED12_ROUNDED(axis.z, up.y);
    emtr->mAxisX.y = MUL_FIXED12_ROUNDED(axis.z, up.x) - MUL_FIXED12_ROUNDED(axis.x, up.z);
    emtr->mAxisX.z = MUL_FIXED12_ROUNDED(axis.x, up.y) - MUL_FIXED12_ROUNDED(axis.y, up.x);
    emtr->mAxisY.x = MUL_FIXED12_ROUNDED(axis.y, emtr->mAxisX.z) - MUL_FIXED12_ROUNDED(axis.z, emtr->mAxisX.y);
    emtr->mAxisY.y = MUL_FIXED12_ROUNDED(axis.z, emtr->mAxisX.x) - MUL_FIXED12_ROUNDED(axis.x, emtr->mAxisX.z);
    emtr->mAxisY.z = MUL_FIXED12_ROUNDED(axis.x, emtr->mAxisX.y) - MUL_FIXED12_ROUNDED(axis.y, emtr->mAxisX.x);
    VecFx16_Normalize(&emtr->mAxisX, &emtr->mAxisX);
    VecFx16_Normalize(&emtr->mAxisY, &emtr->mAxisY);
}

void SPLUtil_TiltCoordinates(Vec3 *ptclPos, const Vec3 *pos, ParticleEmitter *emtr) {
    Vec3s16 cross;

    VecFx16_CrossProduct(&emtr->mAxisX, &emtr->mAxisY, &cross);
    VecFx16_Normalize(&cross, &cross);
    ptclPos->x = MUL_FIXED12_ROUNDED(pos->z, cross.x) +
                 (MUL_FIXED12_ROUNDED(pos->x, emtr->mAxisX.x) + MUL_FIXED12_ROUNDED(pos->y, emtr->mAxisY.x));
    ptclPos->y = MUL_FIXED12_ROUNDED(pos->z, cross.y) +
                 (MUL_FIXED12_ROUNDED(pos->x, emtr->mAxisX.y) + MUL_FIXED12_ROUNDED(pos->y, emtr->mAxisY.y));
    ptclPos->z = MUL_FIXED12_ROUNDED(pos->z, cross.z) +
                 (MUL_FIXED12_ROUNDED(pos->x, emtr->mAxisX.z) + MUL_FIXED12_ROUNDED(pos->y, emtr->mAxisY.z));
}

void SPLEmitter_EmitParticles(ParticleEmitter *emtr, ParticleList *list) {
    ParticleResource *resource;
    ParticleResourceHeader *header;
    ParticleInstance *particle;
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

    resource = emtr->mResource;
    emitTotal = emtr->mEmitRate + emtr->mEmitFraction;
    header = resource->mHeader;
    emtr->mEmitFraction = emitTotal & 0xfff;
    emitCount = FROM_FIXED12(emitTotal);
    if (header->mFlags.mEmitShape == PARTICLE_EMIT_SHAPE_CIRCLE_RANDOM ||
        header->mFlags.mEmitShape == PARTICLE_EMIT_SHAPE_CIRCLE_EVEN ||
        header->mFlags.mEmitShape == PARTICLE_EMIT_SHAPE_DISC_FILLED ||
        header->mFlags.mEmitShape == PARTICLE_EMIT_SHAPE_CYLINDER_SURFACE ||
        header->mFlags.mEmitShape == PARTICLE_EMIT_SHAPE_CYLINDER_FILLED ||
        header->mFlags.mEmitShape == PARTICLE_EMIT_SHAPE_HEMISPHERE_SURFACE ||
        header->mFlags.mEmitShape == PARTICLE_EMIT_SHAPE_HEMISPHERE_FILLED) {
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
            SPLList_PushFront(&emtr->mParticles, particle);
            switch (header->mFlags.mEmitShape) {
                case PARTICLE_EMIT_SHAPE_POINT:
                    particle->mOffset.x = particle->mOffset.y = particle->mOffset.z = 0;
                    break;
                case PARTICLE_EMIT_SHAPE_SPHERE_SURFACE:
                    SPLRandom_VecFx32(&particle->mOffset);
                    particle->mOffset.x = MUL_FIXED12_ROUNDED(particle->mOffset.x, emtr->mRadius);
                    particle->mOffset.y = MUL_FIXED12_ROUNDED(particle->mOffset.y, emtr->mRadius);
                    particle->mOffset.z = MUL_FIXED12_ROUNDED(particle->mOffset.z, emtr->mRadius);
                    break;
                case PARTICLE_EMIT_SHAPE_CIRCLE_RANDOM: {
                    SPLRandom_VecFx32_XY(&offset2);
                    offset2.x = MUL_FIXED12_ROUNDED(offset2.x, emtr->mRadius);
                    offset2.y = MUL_FIXED12_ROUNDED(offset2.y, emtr->mRadius);
                    offset2.z = 0;
                    SPLUtil_TiltCoordinates(&particle->mOffset, &offset2, emtr);
                    break;
                }
                case PARTICLE_EMIT_SHAPE_CIRCLE_EVEN: {
                    s32 angle;
                    s32 sinValue;
                    s32 cosValue;
                    angle = acc / emitCount;
                    acc += 0x10000;
                    sinValue = SIN_OF_ANGLE(angle);
                    cosValue = COS_OF_ANGLE(angle);
                    offset3.x = MUL_FIXED12_ROUNDED(sinValue, emtr->mRadius);
                    offset3.y = MUL_FIXED12_ROUNDED(cosValue, emtr->mRadius);
                    offset3.z = 0;
                    SPLUtil_TiltCoordinates(&particle->mOffset, &offset3, emtr);
                    break;
                }
                case PARTICLE_EMIT_SHAPE_SPHERE_FILLED: {
                    SPLRandom_VecFx32(&particle->mOffset);
                    particle->mOffset.x = MUL_FIXED12_ROUNDED(
                        MUL_FIXED12_ROUNDED(particle->mOffset.x, emtr->mRadius),
                        ((s32) (((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                0x100000) >>
                         8));
                    particle->mOffset.y = MUL_FIXED12_ROUNDED(
                        MUL_FIXED12_ROUNDED(particle->mOffset.y, emtr->mRadius),
                        ((s32) (((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                0x100000) >>
                         8));
                    particle->mOffset.z = MUL_FIXED12_ROUNDED(
                        MUL_FIXED12_ROUNDED(particle->mOffset.z, emtr->mRadius),
                        ((s32) (((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                0x100000) >>
                         8));
                    break;
                }
                case PARTICLE_EMIT_SHAPE_DISC_FILLED: {
                    SPLRandom_VecFx32_XY(&offset5);
                    offset5.x = MUL_FIXED12_ROUNDED(
                        MUL_FIXED12_ROUNDED(offset5.x, emtr->mRadius),
                        ((s32) (((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                0x100000) >>
                         8));
                    offset5.y = MUL_FIXED12_ROUNDED(
                        MUL_FIXED12_ROUNDED(offset5.y, emtr->mRadius),
                        ((s32) (((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                0x100000) >>
                         8));
                    SPLUtil_TiltCoordinates(&particle->mOffset, &offset5, emtr);
                    break;
                }
                case PARTICLE_EMIT_SHAPE_HEMISPHERE_SURFACE: {
                    SPLRandom_VecFx32(&particle->mOffset);
                    VecFx16_CrossProduct(&emtr->mAxisX, &emtr->mAxisY, &normalFx16A);
                    normalA.x = normalFx16A.x;
                    normalA.y = normalFx16A.y;
                    normalA.z = normalFx16A.z;
                    if (Vector3_DotProduct(&normalA, &particle->mOffset) <= 0) {
                        particle->mOffset.x = -particle->mOffset.x;
                        particle->mOffset.y = -particle->mOffset.y;
                        particle->mOffset.z = -particle->mOffset.z;
                    }
                    particle->mOffset.x = MUL_FIXED12_ROUNDED(particle->mOffset.x, emtr->mRadius);
                    particle->mOffset.y = MUL_FIXED12_ROUNDED(particle->mOffset.y, emtr->mRadius);
                    particle->mOffset.z = MUL_FIXED12_ROUNDED(particle->mOffset.z, emtr->mRadius);
                    break;
                }
                case PARTICLE_EMIT_SHAPE_HEMISPHERE_FILLED: {
                    SPLRandom_VecFx32(&particle->mOffset);
                    VecFx16_CrossProduct(&emtr->mAxisX, &emtr->mAxisY, &normalFx16B);
                    normalB.x = normalFx16B.x;
                    normalB.y = normalFx16B.y;
                    normalB.z = normalFx16B.z;
                    if (Vector3_DotProduct(&normalB, &particle->mOffset) < 0) {
                        particle->mOffset.x = -particle->mOffset.x;
                        particle->mOffset.y = -particle->mOffset.y;
                        particle->mOffset.z = -particle->mOffset.z;
                    }
                    particle->mOffset.x = MUL_FIXED12_ROUNDED(
                        MUL_FIXED12_ROUNDED(particle->mOffset.x, emtr->mRadius),
                        (((s32) (((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                 0x100000) >>
                          9) +
                         0x800));
                    particle->mOffset.y = MUL_FIXED12_ROUNDED(
                        MUL_FIXED12_ROUNDED(particle->mOffset.y, emtr->mRadius),
                        (((s32) (((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                 0x100000) >>
                          9) +
                         0x800));
                    particle->mOffset.z = MUL_FIXED12_ROUNDED(
                        MUL_FIXED12_ROUNDED(particle->mOffset.z, emtr->mRadius),
                        (((s32) (((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                 0x100000) >>
                          9) +
                         0x800));
                    break;
                }
                case PARTICLE_EMIT_SHAPE_CYLINDER_SURFACE: {
                    SPLRandom_VecFx32_XY(&particle->mVelocity);
                    offset6.x = MUL_FIXED12_ROUNDED(particle->mVelocity.x, emtr->mRadius);
                    offset6.y = MUL_FIXED12_ROUNDED(particle->mVelocity.y, emtr->mRadius);
                    offset6.z = (emtr->mHalfLength *
                                     (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) -
                                 emtr->mHalfLength * 0x100) >>
                                8;
                    SPLUtil_TiltCoordinates(&particle->mOffset, &offset6, emtr);
                    break;
                }
                case PARTICLE_EMIT_SHAPE_CYLINDER_FILLED: {
                    SPLRandom_VecFx32_XY(&particle->mVelocity);
                    offset7.x = MUL_FIXED12_ROUNDED(
                        MUL_FIXED12_ROUNDED(particle->mVelocity.x, emtr->mRadius),
                        ((s32) (((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                0x100000) >>
                         8));
                    offset7.y = MUL_FIXED12_ROUNDED(
                        MUL_FIXED12_ROUNDED(particle->mVelocity.y, emtr->mRadius),
                        ((s32) (((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                0x100000) >>
                         8));
                    offset7.z = (emtr->mHalfLength *
                                     (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) -
                                 emtr->mHalfLength * 0x100) >>
                                8;
                    SPLUtil_TiltCoordinates(&particle->mOffset, &offset7, emtr);
                    break;
                }
            }

            directionSpeed = ((header->mSpeedRandom + 0xff -
                               ((header->mSpeedRandom *
                                 (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 24)) >>
                                7)) *
                              emtr->mDirectionSpeed) >>
                             8;
            axisSpeed = ((header->mSpeedRandom + 0xff -
                          ((header->mSpeedRandom *
                            (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 24)) >>
                           7)) *
                         emtr->mAxisSpeed) >>
                        8;

            if (header->mFlags.mEmitShape == PARTICLE_EMIT_SHAPE_CYLINDER_SURFACE) {
                tiltedOffset.x = MUL_FIXED12_ROUNDED(particle->mVelocity.x, emtr->mAxisX.x) +
                                 MUL_FIXED12_ROUNDED(particle->mVelocity.y, emtr->mAxisY.x);
                tiltedOffset.y = MUL_FIXED12_ROUNDED(particle->mVelocity.x, emtr->mAxisX.y) +
                                 MUL_FIXED12_ROUNDED(particle->mVelocity.y, emtr->mAxisY.y);
                tiltedOffset.z = MUL_FIXED12_ROUNDED(particle->mVelocity.x, emtr->mAxisX.z) +
                                 MUL_FIXED12_ROUNDED(particle->mVelocity.y, emtr->mAxisY.z);
                VecFx32_Normalize(&tiltedOffset, &direction);
            } else if (particle->mOffset.x == 0 && particle->mOffset.y == 0 && particle->mOffset.z == 0) {
                SPLRandom_VecFx32(&direction);
            } else {
                VecFx32_Normalize(&particle->mOffset, &direction);
            }

            particle->mVelocity.x = emtr->mVelocity.x + (MUL_FIXED12_ROUNDED(direction.x, directionSpeed) +
                                                         MUL_FIXED12_ROUNDED(emtr->mDirection.x, axisSpeed));
            particle->mVelocity.y = emtr->mVelocity.y + (MUL_FIXED12_ROUNDED(direction.y, directionSpeed) +
                                                         MUL_FIXED12_ROUNDED(emtr->mDirection.y, axisSpeed));
            particle->mVelocity.z = emtr->mVelocity.z + (MUL_FIXED12_ROUNDED(direction.z, directionSpeed) +
                                                         MUL_FIXED12_ROUNDED(emtr->mDirection.z, axisSpeed));
            particle->mEmitterPosition = emtr->mPosition;

            particle->mSize = ((header->mSizeRandom + 0xff -
                                ((header->mSizeRandom *
                                  (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 24)) >>
                                 7)) *
                               emtr->mSizeScale) >>
                              8;
            particle->mScale = FIXED12_UNIT;

            if (header->mFlags.mHasColorAnim && resource->mColorAnim->mRandomColor) {
                ParticleColorAnim *colorAnim;
                u32 randomIndex;
                randomIndex = (gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 20;
                colorAnim = resource->mColorAnim;
                colorChoices[0] = colorAnim->mStartColor;
                colorChoices[1] = header->mColor;
                colorChoices[2] = colorAnim->mEndColor;
                particle->mColor = colorChoices[randomIndex % 3];
            } else {
                particle->mColor = header->mColor;
            }

            particle->mBaseAlpha = emtr->mAlpha;
            particle->mAnimAlpha = SPL_ALPHA_MAX;

            if (header->mFlags.mRandomAngle) {
                particle->mAngle = (gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173);
            } else {
                particle->mAngle = emtr->mAngle;
            }

            if (header->mFlags.mRandomAngleSpeed) {
                particle->mAngleSpeed = ((header->mAngleSpeedMax - header->mAngleSpeedMin) *
                                             ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 20) +
                                         TO_FIXED12(header->mAngleSpeedMin)) >>
                                        12;
            } else {
                particle->mAngleSpeed = 0;
            }

            particle->mLife =
                (((0xff - ((header->mLifeRandom *
                            (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 24)) >>
                           8)) *
                  emtr->mLife) >>
                 8) +
                1;
            particle->mAge = 0;

            if (header->mFlags.mHasTextureAnim && resource->mTextureAnim->mRandomTexture) {
                ParticleTextureAnim *texAnim;
                u32 randomIndex;
                randomIndex = (gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 20;
                texAnim = resource->mTextureAnim;
                particle->mTextureIndex = texAnim->mTextureIndices[randomIndex % texAnim->mFrameCount];
            } else if (header->mFlags.mHasTextureAnim && !resource->mTextureAnim->mRandomTexture) {
                particle->mTextureIndex = resource->mTextureAnim->mTextureIndices[0];
            } else {
                particle->mTextureIndex = header->mTextureIndex;
            }

            particle->mSecondTimeScale = SPL_TIME_SCALE_END / resource->mHeader->mDrawParams.mSecondTimeLength;
            particle->mFirstTimeScale = SPL_TIME_SCALE_END / particle->mLife;
            particle->mSecondTimeOffset = 0;
            if (header->mFlags.mRandomSecondTimeOffset) {
                particle->mSecondTimeOffset = (gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 24;
            }
        } while (++emitIndex < emitCount);
    }
}

static inline s32 GetScaledParticleZ(s32 scale, ParticleInstance *particle) {
    return MUL_FIXED12_ROUNDED(particle->mVelocity.z, scale);
}

static inline s32 GetScaledParticleY(s32 scale, ParticleInstance *particle) {
    return MUL_FIXED12_ROUNDED(particle->mVelocity.y, scale);
}

static inline s32 GetScaledParticleX(s32 scale, ParticleInstance *particle) {
    return MUL_FIXED12_ROUNDED(particle->mVelocity.x, scale);
}

static inline s32 AddOneToChildValue(ParticleChildAnim *childAnim) {
    return childAnim->mSizeScale + 1;
}

void SPLEmitter_EmitChildren(ParticleInstance *ptcl, ParticleEmitter *emtr, ParticleList *list) {
    s32 velocityScale;
    ParticleInstance *child;
    s32 childIndex;
    ParticleChildAnim *childAnim;
    Vec3 *childVec;
    u32 parentLife;

    childAnim = emtr->mResource->mChildAnim;
    velocityScale = MUL_FIXED12_ROUNDED(TO_FIXED12(childAnim->mVelocityScale), 16);
    for (childIndex = 0; childIndex < childAnim->mChildCount; childIndex++) {
        {
            child = SPLList_PopFront(list);
            if (child == NULL) {
                return;
            }
            SPLList_PushFront(&emtr->mChildParticles, child);
            childVec = &child->mEmitterPosition;
            child->mOffset = ptcl->mOffset;
            child->mVelocity.x = GetScaledParticleX(velocityScale, ptcl) +
                                 ((childAnim->mVelocityRandom *
                                       (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) -
                                   (childAnim->mVelocityRandom << 8)) >>
                                  8);
            child->mVelocity.y = GetScaledParticleY(velocityScale, ptcl) +
                                 ((childAnim->mVelocityRandom *
                                       (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) -
                                   (childAnim->mVelocityRandom << 8)) >>
                                  8);
            child->mVelocity.z = GetScaledParticleZ(velocityScale, ptcl) +
                                 ((childAnim->mVelocityRandom *
                                       (s32) ((gSplRandomState = gSplRandomState * 0x5eedf715 + 0x1b0cb173) >> 23) -
                                   (childAnim->mVelocityRandom << 8)) >>
                                  8);
            *childVec = ptcl->mEmitterPosition;
            child->mSize = (((ptcl->mSize * ptcl->mScale) >> 12) * AddOneToChildValue(childAnim)) >> 6;
            child->mScale = FIXED12_UNIT;
            if (childAnim->mOwnColor) {
                child->mColor = childAnim->mColor;
            } else {
                child->mColor = ptcl->mColor;
            }
            child->mBaseAlpha = (ptcl->mBaseAlpha * (ptcl->mAnimAlpha + 1)) >> 5;
            child->mAnimAlpha = SPL_ALPHA_MAX;
            switch (childAnim->mInheritAngle) {
                case PARTICLE_INHERIT_ANGLE_AND_SPEED:
                    child->mAngle = ptcl->mAngle;
                    child->mAngleSpeed = ptcl->mAngleSpeed;
                    break;
                case PARTICLE_INHERIT_NOTHING:
                    child->mAngle = 0;
                    child->mAngleSpeed = 0;
                    break;
                case PARTICLE_INHERIT_ANGLE:
                    child->mAngle = ptcl->mAngle;
                    child->mAngleSpeed = 0;
                    break;
            }
            child->mLife = childAnim->mLife;
            child->mAge = 0;
            child->mTextureIndex = childAnim->mTextureIndex;
            parentLife = ptcl->mLife;
            child->mSecondTimeScale = SPL_TIME_SCALE_END / (s32) (parentLife >> 1);
            child->mFirstTimeScale = SPL_TIME_SCALE_END / ptcl->mLife;
            child->mSecondTimeOffset = 0;
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

void SPLDraw_Billboard(SPLManager *mgr, ParticleInstance *ptcl) {
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

    baseScale = mgr->mRenderStateEmitter->mResource->mHeader->mBaseScale;
    viewMtx = mgr->mRenderStateViewMatrix;
    scaleMode = mgr->mRenderStateEmitter->mResource->mHeader->mDrawParams.mScaleMode;
    particleScale = ptcl->mScale;
    particleColor = ptcl->mColor;
    emitterColor = mgr->mRenderStateEmitter->mColor;
    alpha = (ptcl->mBaseAlpha * (ptcl->mAnimAlpha + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->mPolygonId << 24) | (mgr->mMiscPolygonAttr | 0xc0) | (alpha << 16);
    reg_G3_POLYGON_ATTR;
    if (alpha == 0) {
        return;
    }
    height = ptcl->mSize;
    width = MUL_FIXED12_ROUNDED(height, baseScale);
    if (scaleMode == PARTICLE_SCALE_BOTH) {
        width = MUL_FIXED12_ROUNDED(width, particleScale);
        height = MUL_FIXED12_ROUNDED(height, particleScale);
    } else if (scaleMode == PARTICLE_SCALE_WIDTH) {
        width = MUL_FIXED12_ROUNDED(width, particleScale);
    } else {
        height = MUL_FIXED12_ROUNDED(height, particleScale);
    }
    if (mgr->mRenderStateEmitter->mResource->mHeader->mFlags.mTranslateByOffset == 0) {
        viewPos.x = ptcl->mOffset.x + ptcl->mEmitterPosition.x;
        viewPos.y = ptcl->mOffset.y + ptcl->mEmitterPosition.y;
        viewPos.z = ptcl->mOffset.z + ptcl->mEmitterPosition.z;
        MTX_MultVec43(&viewPos, viewMtx, &viewPos);
        sinAngle = FX_SinIdx(ptcl->mAngle);
        cosAngle = FX_CosIdx(ptcl->mAngle);
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
        viewPos.x = ptcl->mOffset.x + ptcl->mEmitterPosition.x -
                    mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.x;
        viewPos.y = ptcl->mOffset.y + ptcl->mEmitterPosition.y -
                    mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.y;
        viewPos.z = ptcl->mOffset.z + ptcl->mEmitterPosition.z -
                    mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.z;
        MTX_MultVec43(&viewPos, viewMtx, &viewPos);
        sinAngle = FX_SinIdx(ptcl->mAngle);
        cosAngle = FX_CosIdx(ptcl->mAngle);
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
        originZ = mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.z;
        originY = mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.y;
        originX = mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.x;
        reg_G3_MTX_TRANS = originX;
        reg_G3_MTX_TRANS = originY;
        reg_G3_MTX_TRANS = originZ;
        G3_MultMtx43(&billboardMtx);
    }
    reg_G3_COLOR = (u16) ((((particleColor & SPL_COLOR_CHANNEL_MASK) * (emitterColor & SPL_COLOR_CHANNEL_MASK)) >> 5) |
                          ((((particleColor & 0x3e0) * (emitterColor & 0x3e0)) >> 15) << 5) |
                          ((((particleColor & 0x7c00) * (emitterColor & 0x7c00)) >> 25) << 10));
    SPLUtil_DrawXYPlane(mgr->mRenderStateEmitter->mTexCoordU, mgr->mRenderStateEmitter->mTexCoordV,
                        mgr->mRenderStateEmitter->mResource->mHeader->mPlaneCenterX,
                        mgr->mRenderStateEmitter->mResource->mHeader->mPlaneCenterY);
}

void SPLDraw_Child_Billboard(SPLManager *mgr, ParticleInstance *ptcl) {
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

    baseScale = mgr->mRenderStateEmitter->mResource->mHeader->mBaseScale;
    viewMtx = mgr->mRenderStateViewMatrix;
    alpha = (ptcl->mBaseAlpha * (ptcl->mAnimAlpha + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->mPolygonId << 24) | (mgr->mMiscPolygonAttr | 0xc0) | (alpha << 16);
    reg_G3_POLYGON_ATTR;
    if (alpha == 0) {
        return;
    }
    height = ptcl->mSize;
    width = MUL_FIXED12_ROUNDED(height, baseScale);
    switch (mgr->mRenderStateEmitter->mResource->mHeader->mDrawParams.mScaleMode) {
        case PARTICLE_SCALE_BOTH:
            width = MUL_FIXED12_ROUNDED(width, ptcl->mScale);
            height = MUL_FIXED12_ROUNDED(height, ptcl->mScale);
            break;
        case PARTICLE_SCALE_WIDTH:
            width = MUL_FIXED12_ROUNDED(width, ptcl->mScale);
            break;
        case PARTICLE_SCALE_HEIGHT:
            height = MUL_FIXED12_ROUNDED(height, ptcl->mScale);
            break;
    }
    if (mgr->mRenderStateEmitter->mResource->mHeader->mFlags.mTranslateByOffset == 0) {
        viewPos.x = ptcl->mOffset.x + ptcl->mEmitterPosition.x;
        viewPos.y = ptcl->mOffset.y + ptcl->mEmitterPosition.y;
        viewPos.z = ptcl->mOffset.z + ptcl->mEmitterPosition.z;
        MTX_MultVec43(&viewPos, viewMtx, &viewPos);
        sinAngle = FX_SinIdx(ptcl->mAngle);
        cosAngle = FX_CosIdx(ptcl->mAngle);
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
        viewPos.x = ptcl->mOffset.x + ptcl->mEmitterPosition.x -
                    mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.x;
        viewPos.y = ptcl->mOffset.y + ptcl->mEmitterPosition.y -
                    mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.y;
        viewPos.z = ptcl->mOffset.z + ptcl->mEmitterPosition.z -
                    mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.z;
        MTX_MultVec43(&viewPos, viewMtx, &viewPos);
        sinAngle = FX_SinIdx(ptcl->mAngle);
        cosAngle = FX_CosIdx(ptcl->mAngle);
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
        originZ = mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.z;
        originY = mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.y;
        originX = mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.x;
        reg_G3_MTX_TRANS = originX;
        reg_G3_MTX_TRANS = originY;
        reg_G3_MTX_TRANS = originZ;
        G3_MultMtx43(&billboardMtx);
    }
    particleColor = ptcl->mColor;
    emitterColor = mgr->mRenderStateEmitter->mColor;
    reg_G3_COLOR = (u16) ((((particleColor & SPL_COLOR_CHANNEL_MASK) * (emitterColor & SPL_COLOR_CHANNEL_MASK)) >> 5) |
                          ((((particleColor & 0x3e0) * (emitterColor & 0x3e0)) >> 15) << 5) |
                          ((((particleColor & 0x7c00) * (emitterColor & 0x7c00)) >> 25) << 10));
    SPLUtil_DrawXYPlane(mgr->mRenderStateEmitter->mChildTexCoordU, mgr->mRenderStateEmitter->mChildTexCoordV, 0, 0);
}

void SPLDraw_DirectionalBillboard(SPLManager *mgr, ParticleInstance *ptcl) {
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
    baseScale = mgr->mRenderStateEmitter->mResource->mHeader->mBaseScale;
    alpha = (ptcl->mBaseAlpha * (ptcl->mAnimAlpha + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->mPolygonId << 24) | (mgr->mMiscPolygonAttr | 0xc0) | (alpha << 16);
    reg_G3_POLYGON_ATTR;
    if (alpha == 0) {
        return;
    }
    width = ptcl->mSize;
    height = MUL_FIXED12_ROUNDED(width, baseScale);
    switch (mgr->mRenderStateEmitter->mResource->mHeader->mDrawParams.mScaleMode) {
        case PARTICLE_SCALE_BOTH:
            height = MUL_FIXED12_ROUNDED(height, ptcl->mScale);
            width = MUL_FIXED12_ROUNDED(width, ptcl->mScale);
            break;
        case PARTICLE_SCALE_WIDTH:
            height = MUL_FIXED12_ROUNDED(height, ptcl->mScale);
            break;
        case PARTICLE_SCALE_HEIGHT:
            width = MUL_FIXED12_ROUNDED(width, ptcl->mScale);
            break;
    }
    if (!mgr->mRenderStateEmitter->mResource->mHeader->mFlags.mTranslateByOffset) {
        pos.x = ptcl->mOffset.x + ptcl->mEmitterPosition.x;
        pos.y = ptcl->mOffset.y + ptcl->mEmitterPosition.y;
        pos.z = ptcl->mOffset.z + ptcl->mEmitterPosition.z;
        sideVec = ptcl->mVelocity;
        viewForward.x = viewMtx->mRows[0].z;
        viewForward.y = viewMtx->mRows[1].z;
        viewForward.z = viewMtx->mRows[2].z;
        VecFx32_CrossProduct(&sideVec, &viewForward, &sideVec);
        if (sideVec.x == 0 && sideVec.y == 0 && sideVec.z == 0) {
            return;
        }
        VecFx32_Normalize(&sideVec, &sideVec);
        asm_MI_Copy36B(viewMtx, &viewMtx33);
        MTX_MultVec33(&sideVec, &viewMtx33, &sideVec);
        MTX_MultVec43(&pos, viewMtx, &pos);
        dirNorm = ptcl->mVelocity;
        VecFx32_Normalize(&dirNorm, &dirNorm);
        facing = MUL_FIXED12_ROUNDED(dirNorm.x, -viewMtx->mRows[0].z) +
                 MUL_FIXED12_ROUNDED(dirNorm.y, -viewMtx->mRows[1].z) +
                 MUL_FIXED12_ROUNDED(dirNorm.z, -viewMtx->mRows[2].z);
        if (facing < 0) {
            facing = -facing;
        }
        stretch = MUL_FIXED12_ROUNDED(0x1000 - facing,
                                      (s32) mgr->mRenderStateEmitter->mResource->mHeader->mDrawParams.mStretchFactor);
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
        pos.x = ptcl->mOffset.x + ptcl->mEmitterPosition.x -
                mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.x;
        pos.y = ptcl->mOffset.y + ptcl->mEmitterPosition.y -
                mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.y;
        pos.z = ptcl->mOffset.z + ptcl->mEmitterPosition.z -
                mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.z;
        sideVec = ptcl->mVelocity;
        viewForward.x = viewMtx->mRows[0].z;
        viewForward.y = viewMtx->mRows[1].z;
        viewForward.z = viewMtx->mRows[2].z;
        VecFx32_CrossProduct(&sideVec, &viewForward, &sideVec);
        if (sideVec.x == 0 && sideVec.y == 0 && sideVec.z == 0) {
            return;
        }
        VecFx32_Normalize(&sideVec, &sideVec);
        asm_MI_Copy36B(viewMtx, &viewMtx33);
        MTX_MultVec33(&sideVec, &viewMtx33, &sideVec);
        MTX_MultVec43(&pos, viewMtx, &pos);
        dirNorm = ptcl->mVelocity;
        VecFx32_Normalize(&dirNorm, &dirNorm);
        facing = MUL_FIXED12_ROUNDED(dirNorm.x, -viewMtx->mRows[0].z) +
                 MUL_FIXED12_ROUNDED(dirNorm.y, -viewMtx->mRows[1].z) +
                 MUL_FIXED12_ROUNDED(dirNorm.z, -viewMtx->mRows[2].z);
        if (facing < 0) {
            facing = -facing;
        }
        stretch = MUL_FIXED12_ROUNDED(0x1000 - facing,
                                      (s32) mgr->mRenderStateEmitter->mResource->mHeader->mDrawParams.mStretchFactor);
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
        originZ = mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.z;
        originY = mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.y;
        originX = mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.x;
        reg_G3_MTX_TRANS = originX;
        reg_G3_MTX_TRANS = originY;
        reg_G3_MTX_TRANS = originZ;
        G3_MultMtx43(&buf);
    }
    particleColor = ptcl->mColor;
    emitterColor = mgr->mRenderStateEmitter->mColor;
    reg_G3_COLOR = (u16) ((((particleColor & SPL_COLOR_CHANNEL_MASK) * (emitterColor & SPL_COLOR_CHANNEL_MASK)) >> 5) |
                          ((((particleColor & 0x3e0) * (emitterColor & 0x3e0)) >> 15) << 5) |
                          ((((particleColor & 0x7c00) * (emitterColor & 0x7c00)) >> 25) << 10));
    SPLUtil_DrawXYPlane(mgr->mRenderStateEmitter->mTexCoordU, mgr->mRenderStateEmitter->mTexCoordV,
                        mgr->mRenderStateEmitter->mResource->mHeader->mPlaneCenterX,
                        mgr->mRenderStateEmitter->mResource->mHeader->mPlaneCenterY);
}

void SPLDraw_Child_DirectionalBillboard(SPLManager *mgr, ParticleInstance *ptcl) {
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
    baseScale = mgr->mRenderStateEmitter->mResource->mHeader->mBaseScale;
    alpha = (ptcl->mBaseAlpha * (ptcl->mAnimAlpha + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->mPolygonId << 24) | (mgr->mMiscPolygonAttr | 0xc0) | (alpha << 16);
    reg_G3_POLYGON_ATTR;
    if (alpha == 0) {
        return;
    }
    width = ptcl->mSize;
    height = MUL_FIXED12_ROUNDED(width, baseScale);
    switch (mgr->mRenderStateEmitter->mResource->mHeader->mDrawParams.mScaleMode) {
        case PARTICLE_SCALE_BOTH:
            height = MUL_FIXED12_ROUNDED(height, ptcl->mScale);
            width = MUL_FIXED12_ROUNDED(width, ptcl->mScale);
            break;
        case PARTICLE_SCALE_WIDTH:
            height = MUL_FIXED12_ROUNDED(height, ptcl->mScale);
            break;
        case PARTICLE_SCALE_HEIGHT:
            width = MUL_FIXED12_ROUNDED(width, ptcl->mScale);
            break;
    }
    if (!mgr->mRenderStateEmitter->mResource->mHeader->mFlags.mTranslateByOffset) {
        pos.x = ptcl->mOffset.x + ptcl->mEmitterPosition.x;
        pos.y = ptcl->mOffset.y + ptcl->mEmitterPosition.y;
        pos.z = ptcl->mOffset.z + ptcl->mEmitterPosition.z;
        sideVec = ptcl->mVelocity;
        viewForward.x = viewMtx->mRows[0].z;
        viewForward.y = viewMtx->mRows[1].z;
        viewForward.z = viewMtx->mRows[2].z;
        VecFx32_CrossProduct(&sideVec, &viewForward, &sideVec);
        if (sideVec.x == 0 && sideVec.y == 0 && sideVec.z == 0) {
            return;
        }
        VecFx32_Normalize(&sideVec, &sideVec);
        asm_MI_Copy36B(viewMtx, &viewMtx33);
        MTX_MultVec33(&sideVec, &viewMtx33, &sideVec);
        MTX_MultVec43(&pos, viewMtx, &pos);
        dirNorm = ptcl->mVelocity;
        VecFx32_Normalize(&dirNorm, &dirNorm);
        facing = MUL_FIXED12_ROUNDED(dirNorm.x, -viewMtx->mRows[0].z) +
                 MUL_FIXED12_ROUNDED(dirNorm.y, -viewMtx->mRows[1].z) +
                 MUL_FIXED12_ROUNDED(dirNorm.z, -viewMtx->mRows[2].z);
        if (facing < 0) {
            facing = -facing;
        }
        stretch = MUL_FIXED12_ROUNDED(0x1000 - facing,
                                      (s32) mgr->mRenderStateEmitter->mResource->mHeader->mDrawParams.mStretchFactor);
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
        pos.x = ptcl->mOffset.x + ptcl->mEmitterPosition.x -
                mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.x;
        pos.y = ptcl->mOffset.y + ptcl->mEmitterPosition.y -
                mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.y;
        pos.z = ptcl->mOffset.z + ptcl->mEmitterPosition.z -
                mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.z;
        sideVec = ptcl->mVelocity;
        viewForward.x = viewMtx->mRows[0].z;
        viewForward.y = viewMtx->mRows[1].z;
        viewForward.z = viewMtx->mRows[2].z;
        VecFx32_CrossProduct(&sideVec, &viewForward, &sideVec);
        if (sideVec.x == 0 && sideVec.y == 0 && sideVec.z == 0) {
            return;
        }
        VecFx32_Normalize(&sideVec, &sideVec);
        asm_MI_Copy36B(viewMtx, &viewMtx33);
        MTX_MultVec33(&sideVec, &viewMtx33, &sideVec);
        MTX_MultVec43(&pos, viewMtx, &pos);
        dirNorm = ptcl->mVelocity;
        VecFx32_Normalize(&dirNorm, &dirNorm);
        facing = MUL_FIXED12_ROUNDED(dirNorm.x, -viewMtx->mRows[0].z) +
                 MUL_FIXED12_ROUNDED(dirNorm.y, -viewMtx->mRows[1].z) +
                 MUL_FIXED12_ROUNDED(dirNorm.z, -viewMtx->mRows[2].z);
        if (facing < 0) {
            facing = -facing;
        }
        stretch = MUL_FIXED12_ROUNDED(0x1000 - facing,
                                      (s32) mgr->mRenderStateEmitter->mResource->mHeader->mDrawParams.mStretchFactor);
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
        originZ = mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.z;
        originY = mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.y;
        originX = mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.x;
        reg_G3_MTX_TRANS = originX;
        reg_G3_MTX_TRANS = originY;
        reg_G3_MTX_TRANS = originZ;
        G3_MultMtx43(&buf);
    }
    particleColor = ptcl->mColor;
    emitterColor = mgr->mRenderStateEmitter->mColor;
    reg_G3_COLOR = (u16) ((((particleColor & SPL_COLOR_CHANNEL_MASK) * (emitterColor & SPL_COLOR_CHANNEL_MASK)) >> 5) |
                          ((((particleColor & 0x3e0) * (emitterColor & 0x3e0)) >> 15) << 5) |
                          ((((particleColor & 0x7c00) * (emitterColor & 0x7c00)) >> 25) << 10));
    SPLUtil_DrawXYPlane(mgr->mRenderStateEmitter->mChildTexCoordU, mgr->mRenderStateEmitter->mChildTexCoordV, 0, 0);
}

void SPLDraw_Polygon(SPLManager *mgr, ParticleInstance *ptcl) {
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

    alpha = (ptcl->mBaseAlpha * (ptcl->mAnimAlpha + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->mPolygonId << 24) | (mgr->mMiscPolygonAttr | 0xc0) | (alpha << 16);
    reg_G3_POLYGON_ATTR;
    if (alpha == 0) {
        return;
    }
    gSplRotateFunctions[mgr->mRenderStateEmitter->mResource->mHeader->mFlags.mRotateKind](
        FX_SinIdx(ptcl->mAngle), FX_CosIdx(ptcl->mAngle), &rotationMtx);
    height = ptcl->mSize;
    width = MUL_FIXED12_ROUNDED(height, mgr->mRenderStateEmitter->mResource->mHeader->mBaseScale);
    switch (mgr->mRenderStateEmitter->mResource->mHeader->mDrawParams.mScaleMode) {
        case PARTICLE_SCALE_BOTH:
            width = MUL_FIXED12_ROUNDED(width, ptcl->mScale);
            height = MUL_FIXED12_ROUNDED(height, ptcl->mScale);
            break;
        case PARTICLE_SCALE_WIDTH:
            width = MUL_FIXED12_ROUNDED(width, ptcl->mScale);
            break;
        case PARTICLE_SCALE_HEIGHT:
            height = MUL_FIXED12_ROUNDED(height, ptcl->mScale);
            break;
    }
    MTX_Scale43__from_thumb(&scaleMtx, width, height, height);
    MTX_Concat43(&scaleMtx, &rotationMtx, &worldMtx);
    if (mgr->mRenderStateEmitter->mResource->mHeader->mFlags.mTranslateByOffset == 0) {
        worldMtx.mRows[3].x = ptcl->mOffset.x + ptcl->mEmitterPosition.x;
        worldMtx.mRows[3].y = ptcl->mOffset.y + ptcl->mEmitterPosition.y;
        worldMtx.mRows[3].z = ptcl->mOffset.z + ptcl->mEmitterPosition.z;
        G3_LoadMtx43(mgr->mRenderStateViewMatrix);
        G3_MultMtx43(&worldMtx);
    } else {
        worldMtx.mRows[3].x = ptcl->mOffset.x + ptcl->mEmitterPosition.x -
                              mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.x;
        worldMtx.mRows[3].y = ptcl->mOffset.y + ptcl->mEmitterPosition.y -
                              mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.y;
        worldMtx.mRows[3].z = ptcl->mOffset.z + ptcl->mEmitterPosition.z -
                              mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.z;
        reg_G3_MTX_IDENTITY = 0;
        originZ = mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.z;
        originY = mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.y;
        originX = mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.x;
        reg_G3_MTX_TRANS = originX;
        reg_G3_MTX_TRANS = originY;
        reg_G3_MTX_TRANS = originZ;
        G3_MultMtx43(mgr->mRenderStateViewMatrix);
        G3_MultMtx43(&worldMtx);
    }
    particleColor = ptcl->mColor;
    emitterColor = mgr->mRenderStateEmitter->mColor;
    reg_G3_COLOR = (u16) ((((particleColor & SPL_COLOR_CHANNEL_MASK) * (emitterColor & SPL_COLOR_CHANNEL_MASK)) >> 5) |
                          ((((particleColor & 0x3e0) * (emitterColor & 0x3e0)) >> 15) << 5) |
                          ((((particleColor & 0x7c00) * (emitterColor & 0x7c00)) >> 25) << 10));
    gSplPlaneDrawFunctions[mgr->mRenderStateEmitter->mResource->mHeader->mFlags.mPlaneKind](
        mgr->mRenderStateEmitter->mTexCoordU, mgr->mRenderStateEmitter->mTexCoordV,
        mgr->mRenderStateEmitter->mResource->mHeader->mPlaneCenterX,
        mgr->mRenderStateEmitter->mResource->mHeader->mPlaneCenterY);
}

void SPLDraw_Child_Polygon(SPLManager *mgr, ParticleInstance *ptcl) {
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

    alpha = (ptcl->mBaseAlpha * (ptcl->mAnimAlpha + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->mPolygonId << 24) | (mgr->mMiscPolygonAttr | 0xc0) | (alpha << 16);
    reg_G3_POLYGON_ATTR;
    if (alpha == 0) {
        return;
    }
    gSplRotateFunctions[mgr->mRenderStateEmitter->mResource->mChildAnim->mRotateKind](FX_SinIdx(ptcl->mAngle),
                                                                         FX_CosIdx(ptcl->mAngle), &rotationMtx);
    height = ptcl->mSize;
    width = MUL_FIXED12_ROUNDED(height, mgr->mRenderStateEmitter->mResource->mHeader->mBaseScale);
    switch (mgr->mRenderStateEmitter->mResource->mHeader->mDrawParams.mScaleMode) {
        case PARTICLE_SCALE_BOTH:
            width = MUL_FIXED12_ROUNDED(width, ptcl->mScale);
            height = MUL_FIXED12_ROUNDED(height, ptcl->mScale);
            break;
        case PARTICLE_SCALE_WIDTH:
            width = MUL_FIXED12_ROUNDED(width, ptcl->mScale);
            break;
        case PARTICLE_SCALE_HEIGHT:
            height = MUL_FIXED12_ROUNDED(height, ptcl->mScale);
            break;
    }
    MTX_Scale43__from_thumb(&scaleMtx, width, height, height);
    MTX_Concat43(&rotationMtx, &scaleMtx, &worldMtx);
    if (mgr->mRenderStateEmitter->mResource->mHeader->mFlags.mTranslateByOffset == 0) {
        worldMtx.mRows[3].x = ptcl->mOffset.x + ptcl->mEmitterPosition.x;
        worldMtx.mRows[3].y = ptcl->mOffset.y + ptcl->mEmitterPosition.y;
        worldMtx.mRows[3].z = ptcl->mOffset.z + ptcl->mEmitterPosition.z;
        G3_LoadMtx43(mgr->mRenderStateViewMatrix);
        G3_MultMtx43(&worldMtx);
    } else {
        worldMtx.mRows[3].x = ptcl->mOffset.x + ptcl->mEmitterPosition.x -
                              mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.x;
        worldMtx.mRows[3].y = ptcl->mOffset.y + ptcl->mEmitterPosition.y -
                              mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.y;
        worldMtx.mRows[3].z = ptcl->mOffset.z + ptcl->mEmitterPosition.z -
                              mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.z;
        reg_G3_MTX_IDENTITY = 0;
        originZ = mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.z;
        originY = mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.y;
        originX = mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.x;
        reg_G3_MTX_TRANS = originX;
        reg_G3_MTX_TRANS = originY;
        reg_G3_MTX_TRANS = originZ;
        G3_MultMtx43(mgr->mRenderStateViewMatrix);
        G3_MultMtx43(&worldMtx);
    }
    particleColor = ptcl->mColor;
    emitterColor = mgr->mRenderStateEmitter->mColor;
    reg_G3_COLOR = (u16) ((((particleColor & SPL_COLOR_CHANNEL_MASK) * (emitterColor & SPL_COLOR_CHANNEL_MASK)) >> 5) |
                          ((((particleColor & 0x3e0) * (emitterColor & 0x3e0)) >> 15) << 5) |
                          ((((particleColor & 0x7c00) * (emitterColor & 0x7c00)) >> 25) << 10));
    gSplPlaneDrawFunctions[mgr->mRenderStateEmitter->mResource->mChildAnim->mPlaneKind](
        mgr->mRenderStateEmitter->mChildTexCoordU, mgr->mRenderStateEmitter->mChildTexCoordV, 0, 0);
}

void SPLDraw_DirectionalPolygon(SPLManager *mgr, ParticleInstance *ptcl) {
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

    alpha = (ptcl->mBaseAlpha * (ptcl->mAnimAlpha + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->mPolygonId << 24) | (mgr->mMiscPolygonAttr | 0xc0) | (alpha << 16);
    reg_G3_POLYGON_ATTR;
    if (alpha == 0) {
        return;
    }
    gSplRotateFunctions[mgr->mRenderStateEmitter->mResource->mHeader->mFlags.mRotateKind](
        FX_SinIdx(ptcl->mAngle), FX_CosIdx(ptcl->mAngle), &rotationMtx);
    MTX_Identity43_(&axisMtx);
    if (mgr->mRenderStateEmitter->mResource->mHeader->mDrawParams.mForwardFromOffset == 0) {
        VecFx32_Normalize(&ptcl->mVelocity, &forward);
    } else {
        VecFx32_Normalize(&ptcl->mOffset, &forward);
        forward.x = -forward.x;
        forward.y = -forward.y;
        forward.z = -forward.z;
    }
    refAxis.x = 0;
    refAxis.y = 0x1000;
    refAxis.z = 0;
    facing = Vector3_DotProduct(&forward, &refAxis);
    if (facing > 0xccd || facing < -0xccd) {
        refAxis.x = 0x1000;
        refAxis.y = 0;
        refAxis.z = 0;
    }
    VecFx32_CrossProduct(&forward, &refAxis, &sideAxis);
    VecFx32_CrossProduct(&forward, &sideAxis, &upAxis);
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
    height = ptcl->mSize;
    width = MUL_FIXED12_ROUNDED(height, mgr->mRenderStateEmitter->mResource->mHeader->mBaseScale);
    switch (mgr->mRenderStateEmitter->mResource->mHeader->mDrawParams.mScaleMode) {
        case PARTICLE_SCALE_BOTH:
            width = MUL_FIXED12_ROUNDED(width, ptcl->mScale);
            height = MUL_FIXED12_ROUNDED(height, ptcl->mScale);
            break;
        case PARTICLE_SCALE_WIDTH:
            width = MUL_FIXED12_ROUNDED(width, ptcl->mScale);
            break;
        case PARTICLE_SCALE_HEIGHT:
            height = MUL_FIXED12_ROUNDED(height, ptcl->mScale);
            break;
    }
    MTX_Scale43__from_thumb(&scaleMtx, width, height, height);
    MTX_Concat43(&scaleMtx, &rotationMtx, &worldMtx);
    if (mgr->mRenderStateEmitter->mResource->mHeader->mFlags.mTranslateByOffset == 0) {
        worldMtx.mRows[3].x = ptcl->mOffset.x + ptcl->mEmitterPosition.x;
        worldMtx.mRows[3].y = ptcl->mOffset.y + ptcl->mEmitterPosition.y;
        worldMtx.mRows[3].z = ptcl->mOffset.z + ptcl->mEmitterPosition.z;
        G3_LoadMtx43(mgr->mRenderStateViewMatrix);
        G3_MultMtx43(&worldMtx);
    } else {
        worldMtx.mRows[3].x = ptcl->mOffset.x + ptcl->mEmitterPosition.x -
                              mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.x;
        worldMtx.mRows[3].y = ptcl->mOffset.y + ptcl->mEmitterPosition.y -
                              mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.y;
        worldMtx.mRows[3].z = ptcl->mOffset.z + ptcl->mEmitterPosition.z -
                              mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.z;
        reg_G3_MTX_IDENTITY = 0;
        originZ = mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.z;
        originY = mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.y;
        originX = mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.x;
        reg_G3_MTX_TRANS = originX;
        reg_G3_MTX_TRANS = originY;
        reg_G3_MTX_TRANS = originZ;
        G3_MultMtx43(mgr->mRenderStateViewMatrix);
        G3_MultMtx43(&worldMtx);
    }
    particleColor = ptcl->mColor;
    emitterColor = mgr->mRenderStateEmitter->mColor;
    reg_G3_COLOR = (u16) ((((particleColor & SPL_COLOR_CHANNEL_MASK) * (emitterColor & SPL_COLOR_CHANNEL_MASK)) >> 5) |
                          ((((particleColor & 0x3e0) * (emitterColor & 0x3e0)) >> 15) << 5) |
                          ((((particleColor & 0x7c00) * (emitterColor & 0x7c00)) >> 25) << 10));
    gSplPlaneDrawFunctions[mgr->mRenderStateEmitter->mResource->mHeader->mFlags.mPlaneKind](
        mgr->mRenderStateEmitter->mTexCoordU, mgr->mRenderStateEmitter->mTexCoordV,
        mgr->mRenderStateEmitter->mResource->mHeader->mPlaneCenterX,
        mgr->mRenderStateEmitter->mResource->mHeader->mPlaneCenterY);
}

void SPLDraw_Child_DirectionalPolygon(SPLManager *mgr, ParticleInstance *ptcl) {
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

    alpha = (ptcl->mBaseAlpha * (ptcl->mAnimAlpha + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->mPolygonId << 24) | (mgr->mMiscPolygonAttr | 0xc0) | (alpha << 16);
    reg_G3_POLYGON_ATTR;
    if (alpha == 0) {
        return;
    }
    gSplRotateFunctions[mgr->mRenderStateEmitter->mResource->mChildAnim->mRotateKind](FX_SinIdx(ptcl->mAngle),
                                                                         FX_CosIdx(ptcl->mAngle), &rotationMtx);
    MTX_Identity43_(&axisMtx);
    if (mgr->mRenderStateEmitter->mResource->mChildAnim->mTexParams.mForwardFromOffset == 0) {
        VecFx32_Normalize(&ptcl->mVelocity, &forward);
    } else {
        VecFx32_Normalize(&ptcl->mOffset, &forward);
        forward.x = -forward.x;
        forward.y = -forward.y;
        forward.z = -forward.z;
    }
    refAxis.x = 0;
    refAxis.y = 0x1000;
    refAxis.z = 0;
    facing = Vector3_DotProduct(&forward, &refAxis);
    if (facing > 0xccd || facing < -0xccd) {
        refAxis.x = 0x1000;
        refAxis.y = 0;
        refAxis.z = 0;
    }
    VecFx32_CrossProduct(&forward, &refAxis, &sideAxis);
    VecFx32_CrossProduct(&forward, &sideAxis, &upAxis);
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
    height = ptcl->mSize;
    width = MUL_FIXED12_ROUNDED(height, mgr->mRenderStateEmitter->mResource->mHeader->mBaseScale);
    switch (mgr->mRenderStateEmitter->mResource->mHeader->mDrawParams.mScaleMode) {
        case PARTICLE_SCALE_BOTH:
            width = MUL_FIXED12_ROUNDED(width, ptcl->mScale);
            height = MUL_FIXED12_ROUNDED(height, ptcl->mScale);
            break;
        case PARTICLE_SCALE_WIDTH:
            width = MUL_FIXED12_ROUNDED(width, ptcl->mScale);
            break;
        case PARTICLE_SCALE_HEIGHT:
            height = MUL_FIXED12_ROUNDED(height, ptcl->mScale);
            break;
    }
    MTX_Scale43__from_thumb(&scaleMtx, width, height, height);
    MTX_Concat43(&rotationMtx, &scaleMtx, &worldMtx);
    if (mgr->mRenderStateEmitter->mResource->mHeader->mFlags.mTranslateByOffset == 0) {
        worldMtx.mRows[3].x = ptcl->mOffset.x + ptcl->mEmitterPosition.x;
        worldMtx.mRows[3].y = ptcl->mOffset.y + ptcl->mEmitterPosition.y;
        worldMtx.mRows[3].z = ptcl->mOffset.z + ptcl->mEmitterPosition.z;
        G3_LoadMtx43(mgr->mRenderStateViewMatrix);
        G3_MultMtx43(&worldMtx);
    } else {
        worldMtx.mRows[3].x = ptcl->mOffset.x + ptcl->mEmitterPosition.x -
                              mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.x;
        worldMtx.mRows[3].y = ptcl->mOffset.y + ptcl->mEmitterPosition.y -
                              mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.y;
        worldMtx.mRows[3].z = ptcl->mOffset.z + ptcl->mEmitterPosition.z -
                              mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.z;
        reg_G3_MTX_IDENTITY = 0;
        originZ = mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.z;
        originY = mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.y;
        originX = mgr->mRenderStateEmitter->mResource->mHeader->mPositionOffset.x;
        reg_G3_MTX_TRANS = originX;
        reg_G3_MTX_TRANS = originY;
        reg_G3_MTX_TRANS = originZ;
        G3_MultMtx43(mgr->mRenderStateViewMatrix);
        G3_MultMtx43(&worldMtx);
    }
    particleColor = ptcl->mColor;
    emitterColor = mgr->mRenderStateEmitter->mColor;
    reg_G3_COLOR = (u16) ((((particleColor & SPL_COLOR_CHANNEL_MASK) * (emitterColor & SPL_COLOR_CHANNEL_MASK)) >> 5) |
                          ((((particleColor & 0x3e0) * (emitterColor & 0x3e0)) >> 15) << 5) |
                          ((((particleColor & 0x7c00) * (emitterColor & 0x7c00)) >> 25) << 10));
    gSplPlaneDrawFunctions[mgr->mRenderStateEmitter->mResource->mChildAnim->mPlaneKind](
        mgr->mRenderStateEmitter->mChildTexCoordU, mgr->mRenderStateEmitter->mChildTexCoordV, 0, 0);
}

typedef enum { TEX_IMAGE_PARAM_FIELD_0 } TexImageParamField;

static inline void SetTexImageParam(u32 addr, TexImageParamField format, TexImageParamField sizeS,
                                    TexImageParamField sizeT, TexImageParamField wrapS, TexImageParamField wrapT,
                                    TexImageParamField color0Transparent) {
    reg_G3_TEXIMAGE_PARAM = (addr >> 3) | (format << 26) | 0x40000000 | (sizeS << 20) | (sizeT << 23) | (wrapS << 16) |
                            (wrapT << 18) | (color0Transparent << 29);
}

void SPLUtil_SetTexture(ParticleTexture *tex) {
    ParticleTextureParam texParam;
    u32 scaleX;
    u32 scaleY;

    texParam = tex->mParam;
    SetTexImageParam(tex->mTextureVramAddr, texParam.mFormat, texParam.mSizeS, texParam.mSizeT, texParam.mWrapS,
                     texParam.mWrapT, texParam.mColor0Transparent);
    reg_G3_PLTT_BASE = tex->mPaletteVramAddr >> (4 - (texParam.mFormat == PARTICLE_TEXTURE_FORMAT_FOUR_COLOR ? 1 : 0));
    reg_G3_MTX_MODE = 3;
    reg_G3_MTX_IDENTITY = 0;
    scaleX = TO_FIXED12(tex->mWidth);
    scaleY = TO_FIXED12(tex->mHeight);
    reg_G3_MTX_SCALE = scaleX;
    reg_G3_MTX_SCALE = scaleY;
    reg_G3_MTX_SCALE = 0;
    reg_G3_MTX_MODE = 1;
}

void nullsub_3(ParticleTexture *tex) {}

void SPLEmitter_Init(ParticleEmitter *emtr, ParticleResource *res, Vec3 *pos) {
    ParticleResourceHeader *header;

    emtr->mResource = res;
    *(u32 *) &emtr->mFlags = 0;
    emtr->mPosition.x = pos->x + emtr->mResource->mHeader->mPositionOffset.x;
    emtr->mPosition.y = pos->y + emtr->mResource->mHeader->mPositionOffset.y;
    emtr->mPosition.z = pos->z + emtr->mResource->mHeader->mPositionOffset.z;
    emtr->mVelocity.x = 0;
    emtr->mVelocity.y = 0;
    emtr->mVelocity.z = 0;
    emtr->mParticleShift.x = emtr->mParticleShift.y = emtr->mParticleShift.z = 0;
    emtr->mAge = 0;
    emtr->mEmitFraction = 0;
    header = emtr->mResource->mHeader;
    emtr->mDirection = header->mDirection;
    emtr->mAngle = emtr->mResource->mHeader->mAngle;
    emtr->mEmitRate = emtr->mResource->mHeader->mEmitRate;
    emtr->mRadius = emtr->mResource->mHeader->mRadius;
    emtr->mHalfLength = emtr->mResource->mHeader->mHalfLength;
    emtr->mDirectionSpeed = emtr->mResource->mHeader->mDirectionSpeed;
    emtr->mAxisSpeed = emtr->mResource->mHeader->mAxisSpeed;
    emtr->mSizeScale = emtr->mResource->mHeader->mSizeScale;
    emtr->mLife = emtr->mResource->mHeader->mLife;
    emtr->mColor = COLOR15_WHITE;
    emtr->mEmitInterval = emtr->mResource->mHeader->mEmitInterval;
    emtr->mAlpha = emtr->mResource->mHeader->mAlpha;
    emtr->mUpdateCycle = 0;
    emtr->mUnk_80_19 = 0;
    emtr->mPlaneY = SPL_UNSET_PLANE;
    emtr->mTexCoordU = FIXED12_UNIT << emtr->mResource->mHeader->mDrawParams.mTexCoordUShift;
    emtr->mTexCoordV = FIXED12_UNIT << emtr->mResource->mHeader->mDrawParams.mTexCoordVShift;
    if (emtr->mResource->mHeader->mFlipU) {
        emtr->mTexCoordU *= -1;
    }
    if (emtr->mResource->mHeader->mFlipV) {
        emtr->mTexCoordV *= -1;
    }
    if (emtr->mResource->mHeader->mFlags.mHasChildAnim) {
        emtr->mChildTexCoordU = FIXED12_UNIT << emtr->mResource->mChildAnim->mTexParams.mTexCoordUShift;
        emtr->mChildTexCoordV = FIXED12_UNIT << emtr->mResource->mChildAnim->mTexParams.mTexCoordVShift;
        if (emtr->mResource->mChildAnim->mTexParams.mFlipU) {
            emtr->mChildTexCoordU *= -1;
        }
        if (emtr->mResource->mChildAnim->mTexParams.mFlipV) {
            emtr->mChildTexCoordV *= -1;
        }
    }
    emtr->mNext = emtr->mPrev = 0;
    emtr->mParticles.mFront = emtr->mChildParticles.mFront = 0;
    emtr->mParticles.mCount = emtr->mChildParticles.mCount = 0;
    emtr->mCallback = 0;
    emtr->mCallbackData = 0;
    emtr->mCallbackState = 0;
}

void SPLEmitter_Update(SPLManager *mgr, ParticleEmitter *emtr) {
    ParticleResource *resource;
    s32 cnt;
    ParticleInstance *particle;
    s32 index;
    s32 animCount;
    ParticleInstance *next;
    ParticleChildAnim *childAnim;
    ParticleResourceHeader *header;
    ParticleResourceFlags flags;
    s32 dragFactor;
    s32 childAge;
    u8 animTime[2];
    ParticleAnimEntry tbl[4];
    ParticleAnimEntry tbl2[4];
    Vec3 accel;

    resource = emtr->mResource;
    childAnim = resource->mChildAnim;
    header = resource->mHeader;
    flags = header->mFlags;
    animCount = 0;
    dragFactor = header->mDragFactor + 0x180;
    cnt = resource->mBehaviorCount;

    if (emtr->mCallback) {
        emtr->mCallback(emtr, 0);
    }

    if (header->mEmitFrameCount == 0 || emtr->mAge < header->mEmitFrameCount) {
        if (emtr->mAge % emtr->mEmitInterval == 0 && !emtr->mFlags.mEnding && !emtr->mFlags.mEmissionStopped &&
            emtr->mFlags.mStarted) {
            SPLEmitter_EmitParticles(emtr, &mgr->mLists[2]);
        }
    }

    if (flags.mHasScaleAnim) {
        tbl[animCount].mAnimate = SPLAnim_Scale;
        tbl[animCount++].mTimeIndex = resource->mScaleAnim->mTimeIndex;
    }
    if (flags.mHasColorAnim && !resource->mColorAnim->mRandomColor) {
        tbl[animCount].mAnimate = SPLAnim_Color;
        tbl[animCount++].mTimeIndex = resource->mColorAnim->mTimeIndex;
    }
    if (flags.mHasAlphaAnim) {
        tbl[animCount].mAnimate = SPLAnim_Alpha;
        tbl[animCount++].mTimeIndex = resource->mAlphaAnim->mTimeIndex;
    }
    if (flags.mHasTextureAnim && !resource->mTextureAnim->mRandomTexture) {
        tbl[animCount].mAnimate = SPLAnim_Texture;
        tbl[animCount++].mTimeIndex = resource->mTextureAnim->mTimeIndex;
    }

    for (particle = emtr->mParticles.mFront; particle; particle = next) {
        next = particle->mNext;
        animTime[0] = (particle->mFirstTimeScale * particle->mAge) >> 8;
        animTime[1] = particle->mSecondTimeOffset + ((particle->mSecondTimeScale * particle->mAge) >> 8);
        for (index = 0; index < animCount; index++) {
            tbl[index].mAnimate(particle, resource, animTime[tbl[index].mTimeIndex]);
        }
        accel.x = accel.y = accel.z = 0;
        if (flags.mFollowEmitter) {
            particle->mEmitterPosition = emtr->mPosition;
        }
        for (index = 0; index < cnt; index++) {
            resource->mBehaviors[index].mApply(resource->mBehaviors[index].mData, particle, &accel, emtr);
        }
        particle->mAngle += particle->mAngleSpeed;
        particle->mVelocity.x = (particle->mVelocity.x * dragFactor) >> 9;
        particle->mVelocity.y = (particle->mVelocity.y * dragFactor) >> 9;
        particle->mVelocity.z = (particle->mVelocity.z * dragFactor) >> 9;
        particle->mVelocity.x += accel.x;
        particle->mVelocity.y += accel.y;
        particle->mVelocity.z += accel.z;
        particle->mOffset.x += particle->mVelocity.x + emtr->mParticleShift.x;
        particle->mOffset.y += particle->mVelocity.y + emtr->mParticleShift.y;
        particle->mOffset.z += particle->mVelocity.z + emtr->mParticleShift.z;
        if (flags.mHasChildAnim) {
            childAge = TO_FIXED12(particle->mAge) -
                       (MUL_FIXED12_ROUNDED(TO_FIXED12(particle->mLife), TO_FIXED12(childAnim->mStartLifeRate)) >> 8);
            if (childAge >= 0 && FROM_FIXED12(childAge) % childAnim->mInterval == 0) {
                SPLEmitter_EmitChildren(particle, emtr, &mgr->mLists[2]);
            }
        }
        if (emtr->mResource->mHeader->mFlags.mFixedPolygonId) {
            particle->mPolygonId = mgr->mPolygonIDFix;
        } else {
            particle->mPolygonId = mgr->mPolygonIDCurrent;
            mgr->mPolygonIDCurrent++;
            if (mgr->mPolygonIDCurrent > mgr->mPolygonIDMax) {
                mgr->mPolygonIDCurrent = mgr->mPolygonIDMin;
            }
        }
        particle->mAge++;
        if (particle->mAge > particle->mLife) {
            SPLList_PushFront(&mgr->mLists[2], SPLList_Erase(&emtr->mParticles, particle));
        }
    }

    if (flags.mHasChildAnim) {
        animCount = 0;
        if (childAnim->mHasScaleAnim) {
            tbl2[animCount].mAnimate = SPLAnim_ChildScale;
            tbl2[animCount++].mTimeIndex = 0;
        }
        if (childAnim->mHasAlphaAnim) {
            tbl2[animCount].mAnimate = SPLAnim_ChildAlpha;
            tbl2[animCount++].mTimeIndex = 0;
        }
        if (!childAnim->mUseBehaviors) {
            cnt = 0;
        }
        for (particle = emtr->mChildParticles.mFront; particle; particle = next) {
            next = particle->mNext;
            animTime[0] = (particle->mAge << 8) / particle->mLife;
            for (index = 0; index < animCount; index++) {
                tbl2[index].mAnimate(particle, resource, animTime[0]);
            }
            accel.x = accel.y = accel.z = 0;
            if (childAnim->mFollowEmitter) {
                particle->mEmitterPosition = emtr->mPosition;
            }
            for (index = 0; index < cnt; index++) {
                resource->mBehaviors[index].mApply(resource->mBehaviors[index].mData, particle, &accel, emtr);
            }
            particle->mAngle += particle->mAngleSpeed;
            particle->mVelocity.x = (particle->mVelocity.x * dragFactor) >> 9;
            particle->mVelocity.y = (particle->mVelocity.y * dragFactor) >> 9;
            particle->mVelocity.z = (particle->mVelocity.z * dragFactor) >> 9;
            particle->mVelocity.x += accel.x;
            particle->mVelocity.y += accel.y;
            particle->mVelocity.z += accel.z;
            particle->mOffset.x += particle->mVelocity.x + emtr->mParticleShift.x;
            particle->mOffset.y += particle->mVelocity.y + emtr->mParticleShift.y;
            particle->mOffset.z += particle->mVelocity.z + emtr->mParticleShift.z;
            if (emtr->mResource->mHeader->mFlags.mFixedChildPolygonId) {
                particle->mPolygonId = mgr->mPolygonIDFix;
            } else {
                particle->mPolygonId = mgr->mPolygonIDCurrent;
                mgr->mPolygonIDCurrent++;
                if (mgr->mPolygonIDCurrent > mgr->mPolygonIDMax) {
                    mgr->mPolygonIDCurrent = mgr->mPolygonIDMin;
                }
            }
            particle->mAge++;
            if (particle->mAge > particle->mLife) {
                SPLList_PushFront(&mgr->mLists[2], SPLList_Erase(&emtr->mChildParticles, particle));
            }
        }
    }

    emtr->mAge++;
    if (emtr->mCallback) {
        emtr->mCallback(emtr, 1);
    }
}

void SPLManager_DrawParticles(SPLManager *mgr) {
    ParticleEmitter *emitter;
    ParticleResourceHeader *header;
    void (*drawFunc)(SPLManager *mgr, ParticleInstance *particle);
    void (*textureFunc)(ParticleTexture *mgr);
    ParticleInstance *particle;

    emitter = mgr->mRenderStateEmitter;
    header = emitter->mResource->mHeader;
    drawFunc = 0;
    SPLUtil_SetTexture(mgr->mTextures + header->mTextureIndex);
    switch (header->mFlags.mDrawKind) {
        case PARTICLE_DRAW_BILLBOARD:
            drawFunc = SPLDraw_Billboard;
            break;
        case PARTICLE_DRAW_DIRECTIONAL_BILLBOARD:
            drawFunc = SPLDraw_DirectionalBillboard;
            break;
        case PARTICLE_DRAW_POLYGON:
            drawFunc = SPLDraw_Polygon;
            break;
        case PARTICLE_DRAW_DIRECTIONAL_POLYGON:
            drawFunc = SPLDraw_DirectionalPolygon;
            break;
        case PARTICLE_DRAW_DIRECTIONAL_POLYGON_ALIAS:
            drawFunc = SPLDraw_DirectionalPolygon;
            break;
    }
    if (header->mFlags.mHasTextureAnim) {
        textureFunc = SPLUtil_SetTexture;
    } else {
        textureFunc = nullsub_3;
    }
    for (particle = emitter->mParticles.mFront; particle != 0; particle = particle->mNext) {
        textureFunc(mgr->mTextures + particle->mTextureIndex);
        drawFunc(mgr, particle);
    }
}

void SPLManager_DrawChildParticles(SPLManager *mgr) {
    ParticleEmitter *emitter;
    ParticleResource *resource;
    void (*drawFunc)(SPLManager *mgr, ParticleInstance *particle);
    ParticleInstance *particle;

    emitter = mgr->mRenderStateEmitter;
    drawFunc = 0;
    resource = emitter->mResource;
    if (resource->mHeader->mFlags.mHasChildAnim == 0) {
        return;
    }
    SPLUtil_SetTexture(mgr->mTextures + resource->mChildAnim->mTextureIndex);
    switch (resource->mChildAnim->mDrawKind) {
        case PARTICLE_DRAW_BILLBOARD:
            drawFunc = SPLDraw_Child_Billboard;
            break;
        case PARTICLE_DRAW_DIRECTIONAL_BILLBOARD:
            drawFunc = SPLDraw_Child_DirectionalBillboard;
            break;
        case PARTICLE_DRAW_POLYGON:
            drawFunc = SPLDraw_Child_Polygon;
            break;
        case PARTICLE_DRAW_DIRECTIONAL_POLYGON:
            drawFunc = SPLDraw_Child_DirectionalPolygon;
            break;
        case PARTICLE_DRAW_DIRECTIONAL_POLYGON_ALIAS:
            drawFunc = SPLDraw_Child_DirectionalPolygon;
            break;
    }
    for (particle = emitter->mChildParticles.mFront; particle != 0; particle = particle->mNext) {
        drawFunc(mgr, particle);
    }
}

void SPLManager_DoDraw(SPLManager *mgr) {
    ParticleResourceHeader *header;

    header = mgr->mRenderStateEmitter->mResource->mHeader;
    if (header->mFlags.mChildrenFirst) {
        SPLManager_DrawChildParticles(mgr);
        if (header->mFlags.mHideParticles) {
            return;
        }
        SPLManager_DrawParticles(mgr);
    } else {
        if (header->mFlags.mHideParticles == 0) {
            SPLManager_DrawParticles(mgr);
        }
        SPLManager_DrawChildParticles(mgr);
    }
}

void SPLUtil_SetCylinderEmitterDir(ParticleEmitter *emtr, Vec3 *pointA, Vec3 *pointB) {
    Vec3 dir;

    if (emtr->mResource->mHeader->mFlags.mEmitShape - PARTICLE_EMIT_SHAPE_CYLINDER_SURFACE > 1) {
        return;
    }
    emtr->mPosition.x = (pointB->x + pointA->x) / 2;
    emtr->mPosition.y = (pointB->y + pointA->y) / 2;
    emtr->mPosition.z = (pointB->z + pointA->z) / 2;
    emtr->mHalfLength = VecFx32_Distance(pointA, pointB) / 2;
    dir.x = pointB->x - pointA->x;
    dir.y = pointB->y - pointA->y;
    dir.z = pointB->z - pointA->z;
    VecFx32_Normalize(&dir, &dir);
    emtr->mDirection.x = dir.x;
    emtr->mDirection.y = dir.y;
    emtr->mDirection.z = dir.z;
}

u32 SPLUtil_AllocTextureVRAM(s32 size, s32 is4x4) {
    return (NNS_GfdDefaultFuncAllocTexVram(size, is4x4, 0) & 0xffff) << 3;
}

u32 SPLUtil_AllocPaletteVRAM(s32 size, s32 is4Pltt) {
    return (NNS_GfdDefaultFuncAllocPlttVram(size, is4Pltt, 0) & 0xffff) << 3;
}

SPLManager *SPLManager_New(void *(*alloc)(u32 size), u16 maxEmitters, u16 maxParticles, s32 fixPolyId, u16 minPolyId,
                           u16 maxPolyId) {
    SPLManager *mgr;
    s32 index;
    u8 *block;

    mgr = alloc(sizeof(SPLManager));
    Mem_CpuFill8(mgr, 0, sizeof(SPLManager));
    mgr->mMaxEmitters = maxEmitters;
    mgr->mMaxParticles = maxParticles;
    mgr->mPolygonIDMin = minPolyId;
    mgr->mPolygonIDMax = maxPolyId;
    mgr->mPolygonIDCurrent = mgr->mPolygonIDMin;
    mgr->mPolygonIDFix = fixPolyId;
    mgr->mPolygonIDDrawOrder = 0;
    mgr->mUnk_38_25 = 0;
    mgr->mAlloc = alloc;
    mgr->mLists[0].mCount = 0;
    mgr->mLists[1].mCount = 0;
    mgr->mLists[2].mCount = 0;
    mgr->mLists[0].mFront = 0;
    mgr->mLists[1].mFront = 0;
    mgr->mLists[2].mFront = 0;
    mgr->mMiscPolygonAttr = 0;
    mgr->mCurrentCycle = 0;
    block = alloc(maxEmitters * sizeof(ParticleEmitter));
    Mem_CpuFill8(block, 0, maxEmitters * sizeof(ParticleEmitter));
    for (index = 0; index < maxEmitters; index++) {
        SPLList_PushFront(&mgr->mLists[1], (ParticleInstance *) block);
        block += sizeof(ParticleEmitter);
    }
    block = alloc(maxParticles * sizeof(ParticleInstance));
    Mem_CpuFill8(block, 0, maxParticles * sizeof(ParticleInstance));
    for (index = 0; index < maxParticles; index++) {
        SPLList_PushFront(&mgr->mLists[2], (ParticleInstance *) block);
        block += 0x44;
    }
    mgr->mResources = 0;
    mgr->mTextures = 0;
    mgr->mTexCount = 0;
    mgr->mResCount = mgr->mTexCount;
    return mgr;
}

void SPLManager_LoadResources(SPLManager *mgr, ParticleFileHeader *data) {
    s32 index;
    s32 off;
    ParticleResource *resource;
    ParticleResourceFlags flags;
    ParticleBehaviorEntry *behaviorEntry;
    ParticleTexture *texture;
    ParticleTextureHeader *textureHeader;

    off = 0x20;
    mgr->mResCount = data->mResCount;
    mgr->mTexCount = data->mTexCount;
    mgr->mResources = mgr->mAlloc(mgr->mResCount << 5);
    Mem_CpuFill8(mgr->mResources, 0, mgr->mResCount << 5);
    for (index = 0; index < mgr->mResCount; index++) {
        resource = mgr->mResources + index;
        resource->mHeader = OFFSET_PTR(ParticleResourceHeader, data, off);
        off += 0x58;
        flags = resource->mHeader->mFlags;
        if (flags.mHasScaleAnim) {
            resource->mScaleAnim = OFFSET_PTR(ParticleScaleAnim, data, off);
            off += 0xc;
        } else {
            resource->mScaleAnim = 0;
        }
        if (flags.mHasColorAnim) {
            resource->mColorAnim = OFFSET_PTR(ParticleColorAnim, data, off);
            off += 0xc;
        } else {
            resource->mColorAnim = 0;
        }
        if (flags.mHasAlphaAnim) {
            resource->mAlphaAnim = OFFSET_PTR(ParticleAlphaAnim, data, off);
            off += 8;
        } else {
            resource->mAlphaAnim = 0;
        }
        if (flags.mHasTextureAnim) {
            resource->mTextureAnim = OFFSET_PTR(ParticleTextureAnim, data, off);
            off += 0xc;
        } else {
            resource->mTextureAnim = 0;
        }
        if (flags.mHasChildAnim) {
            resource->mChildAnim = OFFSET_PTR(ParticleChildAnim, data, off);
            off += 0x14;
        } else {
            resource->mChildAnim = 0;
        }
        resource->mBehaviorCount = flags.mHasGravity + flags.mHasRandom + flags.mHasMagnet + flags.mHasSpin +
                                   flags.mHasCollisionPlane + flags.mHasConvergence;
        if (resource->mBehaviorCount != 0) {
            resource->mBehaviors = mgr->mAlloc(resource->mBehaviorCount << 3);
            behaviorEntry = resource->mBehaviors;
            if (flags.mHasGravity) {
                behaviorEntry->mData = (u8 *) data + off;
                behaviorEntry->mApply = SPLBehavior_ApplyGravity;
                off += 8;
                behaviorEntry++;
            }
            if (flags.mHasRandom) {
                behaviorEntry->mData = (u8 *) data + off;
                behaviorEntry->mApply = SPLBehavior_ApplyRandom;
                off += 8;
                behaviorEntry++;
            }
            if (flags.mHasMagnet) {
                behaviorEntry->mData = (u8 *) data + off;
                behaviorEntry->mApply = SPLBehavior_ApplyMagnet;
                off += 0x10;
                behaviorEntry++;
            }
            if (flags.mHasSpin) {
                behaviorEntry->mData = (u8 *) data + off;
                behaviorEntry->mApply = SPLBehavior_ApplySpin;
                off += 4;
                behaviorEntry++;
            }
            if (flags.mHasCollisionPlane) {
                behaviorEntry->mData = (u8 *) data + off;
                behaviorEntry->mApply = SPLBehavior_ApplyCollisionPlane;
                off += 8;
                behaviorEntry++;
            }
            if (flags.mHasConvergence) {
                behaviorEntry->mData = (u8 *) data + off;
                behaviorEntry->mApply = SPLBehavior_ApplyConvergence;
                off += 0x10;
            }
        } else {
            resource->mBehaviors = 0;
        }
    }
    mgr->mTextures = mgr->mAlloc(mgr->mTexCount * sizeof(ParticleTexture));
    Mem_CpuFill8(mgr->mTextures, 0, mgr->mTexCount * sizeof(ParticleTexture));
    for (index = 0; index < mgr->mTexCount; index++) {
        texture = mgr->mTextures + index;
        textureHeader = OFFSET_PTR(ParticleTextureHeader, data, off);
        texture->mHeader = textureHeader;
        texture->mWidth = 1 << (textureHeader->mImageParam.mSizeS + 3);
        texture->mHeight = 1 << (textureHeader->mImageParam.mSizeT + 3);
        texture->mParam = textureHeader->mImageParam;
        off += textureHeader->mBlockSize;
    }
}

s32 SPLManager_UploadTexturesEx(SPLManager *mgr, u32 (*vramAlloc)(s32 size, s32 isSpecial)) {
    s32 index;
    ParticleTexture *texture;
    ParticleTextureHeader *textureHeader;
    u32 vramAddr;

    GX_BeginLoadTex();
    for (index = 0; index < mgr->mTexCount; index++) {
        texture = mgr->mTextures + index;
        textureHeader = texture->mHeader;
        if (textureHeader->mImageParam.mSharesTexture) {
            texture->mTextureVramAddr = mgr->mTextures[textureHeader->mImageParam.mSharedTextureIndex].mTextureVramAddr;
        } else {
            vramAddr = vramAlloc(textureHeader->mTextureSize,
                                 textureHeader->mImageParam.mFormat == PARTICLE_TEXTURE_FORMAT_COMPRESSED ? 1 : 0);
            GX_LoadTex(texture->mHeader->mTextureData, vramAddr, textureHeader->mTextureSize);
            texture->mTextureVramAddr = vramAddr;
        }
    }
    GX_EndLoadTex();
    return 1;
}

s32 SPLManager_UploadPalettesEx(SPLManager *mgr, u32 (*vramAlloc)(s32 size, s32 isSpecial)) {
    s32 index;
    ParticleTexture *texture;
    ParticleTextureHeader *textureHeader;
    u32 vramAddr;

    GX_BeginLoadTexPltt();
    for (index = 0; index < mgr->mTexCount; index++) {
        texture = mgr->mTextures + index;
        textureHeader = texture->mHeader;
        vramAddr = 0;
        if (textureHeader->mPaletteSize != 0) {
            vramAddr = vramAlloc(textureHeader->mPaletteSize,
                                 textureHeader->mImageParam.mFormat == PARTICLE_TEXTURE_FORMAT_FOUR_COLOR ? 1 : 0);
            SomeDmaCopy_0((u8 *) texture->mHeader + textureHeader->mPaletteOffset, vramAddr,
                           textureHeader->mPaletteSize);
        }
        texture->mPaletteVramAddr = vramAddr;
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
    ParticleEmitter *emtr;
    ParticleEmitter *next;
    ParticleResourceHeader *header;

    for (emtr = (ParticleEmitter *) mgr->mLists[0].mFront; emtr != 0; emtr = next) {
        header = emtr->mResource->mHeader;
        next = emtr->mNext;
        if (emtr->mFlags.mStarted == 0) {
            if (emtr->mAge >= header->mDelayFrameCount) {
                emtr->mFlags.mStarted = 1;
                emtr->mAge = 0;
            }
        }
        if (emtr->mFlags.mPaused == 0) {
            if (emtr->mUpdateCycle == 0 || mgr->mCurrentCycle == emtr->mUpdateCycle - 1) {
                SPLEmitter_Update(mgr, emtr);
            }
        }
        if ((header->mFlags.mEndAfterEmit && header->mEmitFrameCount != 0 && emtr->mFlags.mStarted != 0 &&
             emtr->mAge > header->mEmitFrameCount) ||
            emtr->mFlags.mEnding != 0) {
            if (emtr->mParticles.mCount == 0 && emtr->mChildParticles.mCount == 0) {
                SPLList_PushFront(&mgr->mLists[1], SPLList_Erase(&mgr->mLists[0], (ParticleInstance *) emtr));
            }
        }
    }
    mgr->mCurrentCycle++;
    if (mgr->mCurrentCycle > 1) {
        mgr->mCurrentCycle = 0;
    }
}

void SPLManager_Draw(SPLManager *mgr, MtxFx43 *viewMatrix) {
    ParticleEmitter *emtr;

    reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~(REG_G3X_DISP3DCNT_GO_MASK | REG_G3X_DISP3DCNT_RO_MASK)) | 8;
    mgr->mRenderStateViewMatrix = viewMatrix;
    if (mgr->mPolygonIDDrawOrder == 0) {
        for (emtr = (ParticleEmitter *) mgr->mLists[0].mFront; emtr != 0; emtr = emtr->mNext) {
            mgr->mRenderStateEmitter = emtr;
            if (emtr->mFlags.mHidden == 0) {
                SPLManager_DoDraw(mgr);
            }
        }
    } else {
        for (emtr = (ParticleEmitter *) mgr->mLists[0].mBack; emtr != 0; emtr = emtr->mPrev) {
            mgr->mRenderStateEmitter = emtr;
            if (emtr->mFlags.mHidden == 0) {
                SPLManager_DoDraw(mgr);
            }
        }
    }
}

ParticleEmitter *SPLManager_CreateEmitter(SPLManager *mgr, s32 resourceId, Vec3 *pos) {
    ParticleEmitter *emtr;

    emtr = 0;
    if (mgr->mLists[1].mFront != 0) {
        emtr = (ParticleEmitter *) SPLList_PopFront(&mgr->mLists[1]);
        SPLEmitter_Init(emtr, mgr->mResources + resourceId, pos);
        SPLList_PushFront(&mgr->mLists[0], (ParticleInstance *) emtr);
        if (emtr->mResource->mHeader->mFlags.mEndAfterEmit) {
            emtr = 0;
        }
    }
    return emtr;
}

ParticleEmitter *SPLManager_CreateEmitterWithCallbackEx(SPLManager *mgr, s32 resourceId, Vec3 *pos, s32 param,
                                                   void (*initCallback)(ParticleEmitter *emtr, s32 param)) {
    ParticleEmitter *emtr;

    emtr = 0;
    if (mgr->mLists[1].mFront != 0) {
        emtr = (ParticleEmitter *) SPLList_PopFront(&mgr->mLists[1]);
        SPLEmitter_Init(emtr, mgr->mResources + resourceId, pos);
        if (initCallback != 0) {
            initCallback(emtr, param);
        }
        SPLList_PushFront(&mgr->mLists[0], (ParticleInstance *) emtr);
        if (emtr->mResource->mHeader->mFlags.mEndAfterEmit) {
            emtr = 0;
        }
    }
    return emtr;
}

void SPLManager_DeleteEmitter(SPLManager *mgr, ParticleEmitter *emtr) {
    ParticleInstance *particle;

    while ((particle = SPLList_PopFront(&emtr->mParticles)) != 0) {
        SPLList_PushFront(&mgr->mLists[2], particle);
    }
    while ((particle = SPLList_PopFront(&emtr->mChildParticles)) != 0) {
        SPLList_PushFront(&mgr->mLists[2], particle);
    }
    SPLList_Erase(&mgr->mLists[0], (ParticleInstance *) emtr);
    SPLList_PushFront(&mgr->mLists[1], (ParticleInstance *) emtr);
}
