#include "code_0214a748.h"
#include "g3x.h"
#include "code_02147cd8.h"
#include "Main/Kart/kart_drift.h"
#include "code_0214d018.h"
#include "registers.h"

// Builds a perspective projection matrix from the six edge values, scaled by scaleW (0x1000 = 1.0). With draw
// nonzero it sets the projection matrix mode and loads the 16 words with the 4x4 load command; with mtx not null it
// stores them there.
void G3i_FrustumW_(s32 top, s32 bottom, s32 left, s32 right, s32 nearPlane, s32 farPlane, s32 scaleW, int draw,
                   MtxFx44 *mtx) {
    s64 invWidth;
    s64 invHeight;
    s64 invDepth;
    s32 dblNear;
    s32 xScale;
    s32 yScale;
    s32 zScale;
    s32 zTranslate;
    s32 nearFar;
    vu32 *fifo;

    FX_InvAsync(right - left);
    if (draw != 0) {
        reg_G3_MTX_MODE = 0;
        fifo = &reg_G3_MTX_LOAD_4x4;
    }
    if (mtx != 0) {
        mtx->mRows[0].y = 0;
        mtx->mRows[0].z = 0;
        mtx->mRows[0].wComponent = 0;
        mtx->mRows[1].x = 0;
        mtx->mRows[1].z = 0;
        mtx->mRows[1].wComponent = 0;
        mtx->mRows[2].wComponent = -scaleW;
        mtx->mRows[3].x = 0;
        mtx->mRows[3].y = 0;
        mtx->mRows[3].wComponent = 0;
    }
    dblNear = nearPlane << 1;
    invWidth = FX_GetDivResultFx64c();
    reg_CP_DIV_NUMER = 0x100000000000ULL;
    reg_CP_DIV_DENOM = (u32) (top - bottom);
    if (scaleW != 0x1000) {
        invWidth = invWidth * scaleW / 0x1000;
    }
    xScale = (invWidth * dblNear + 0x80000000) >> 32;
    if (draw != 0) {
        *fifo = xScale;
        *fifo = 0;
        *fifo = 0;
        *fifo = 0;
    }
    if (mtx != 0) {
        mtx->mRows[0].x = xScale;
    }
    invHeight = FX_GetDivResultFx64c();
    reg_CP_DIV_NUMER = 0x100000000000ULL;
    reg_CP_DIV_DENOM = (u32) (nearPlane - farPlane);
    if (scaleW != 0x1000) {
        invHeight = invHeight * scaleW / 0x1000;
    }
    yScale = (invHeight * dblNear + 0x80000000) >> 32;
    if (draw != 0) {
        *fifo = 0;
        *fifo = yScale;
        *fifo = 0;
        *fifo = 0;
    }
    if (mtx != 0) {
        mtx->mRows[1].y = yScale;
    }
    {
        s32 sumLR = right + left;
        s32 sumTB = top + bottom;
        s32 xShift = (invWidth * sumLR + 0x80000000) >> 32;
        s32 yShift = (invHeight * sumTB + 0x80000000) >> 32;
        if (draw != 0) {
            *fifo = xShift;
            *fifo = yShift;
        }
        if (mtx != 0) {
            mtx->mRows[2].x = xShift;
            mtx->mRows[2].y = yShift;
        }
    }
    invDepth = FX_GetDivResultFx64c();
    if (scaleW != 0x1000) {
        invDepth = invDepth * scaleW / 0x1000;
    }
    nearFar = MUL_FIXED12_ROUNDED(dblNear, farPlane);
    zScale = (invDepth * (farPlane + nearPlane) + 0x80000000) >> 32;
    zTranslate = (invDepth * nearFar + 0x80000000) >> 32;
    if (draw != 0) {
        *fifo = zScale;
        *fifo = -scaleW;
        *fifo = 0;
        *fifo = 0;
        *fifo = zTranslate;
        *fifo = 0;
    }
    if (mtx != 0) {
        mtx->mRows[2].z = zScale;
        mtx->mRows[3].z = zTranslate;
    }
}

// Builds an orthographic projection matrix from the six edge values, scaled by scaleW. With draw nonzero it sets the
// projection matrix mode and loads the 16 words with the 4x4 load command; with mtx not null it stores them there.
void G3i_OrthoW_(s32 top, s32 bottom, s32 left, s32 right, s32 nearPlane, s32 farPlane, s32 scaleW, int draw,
                 MtxFx44 *mtx) {
    s64 invWidth;
    s64 invHeight;
    s64 invDepth;
    s32 xScale;
    s32 yScale;
    s32 zScale;
    vu32 *fifo;

    FX_InvAsync(right - left);
    if (draw != 0) {
        reg_G3_MTX_MODE = 0;
        fifo = &reg_G3_MTX_LOAD_4x4;
    }
    if (mtx != 0) {
        mtx->mRows[0].y = 0;
        mtx->mRows[0].z = 0;
        mtx->mRows[0].wComponent = 0;
        mtx->mRows[1].x = 0;
        mtx->mRows[1].z = 0;
        mtx->mRows[1].wComponent = 0;
        mtx->mRows[2].x = 0;
        mtx->mRows[2].y = 0;
        mtx->mRows[2].wComponent = 0;
        mtx->mRows[3].wComponent = scaleW;
    }
    invWidth = FX_GetDivResultFx64c();
    reg_CP_DIV_NUMER = 0x100000000000ULL;
    reg_CP_DIV_DENOM = (u32) (top - bottom);
    if (scaleW != 0x1000) {
        invWidth = invWidth * scaleW / 0x1000;
    }
    xScale = ((invWidth << 13) + 0x80000000) >> 32;
    if (draw != 0) {
        *fifo = xScale;
        *fifo = 0;
        *fifo = 0;
        *fifo = 0;
        *fifo = 0;
    }
    if (mtx != 0) {
        mtx->mRows[0].x = xScale;
    }
    invHeight = FX_GetDivResultFx64c();
    reg_CP_DIV_NUMER = 0x100000000000ULL;
    reg_CP_DIV_DENOM = (u32) (nearPlane - farPlane);
    if (scaleW != 0x1000) {
        invHeight = invHeight * scaleW / 0x1000;
    }
    yScale = ((invHeight << 13) + 0x80000000) >> 32;
    if (draw != 0) {
        *fifo = yScale;
        *fifo = 0;
        *fifo = 0;
        *fifo = 0;
        *fifo = 0;
    }
    if (mtx != 0) {
        mtx->mRows[1].y = yScale;
    }
    invDepth = FX_GetDivResultFx64c();
    if (scaleW != 0x1000) {
        invDepth = invDepth * scaleW / 0x1000;
    }
    zScale = ((invDepth << 13) + 0x80000000) >> 32;
    if (draw != 0) {
        *fifo = zScale;
        *fifo = 0;
    }
    if (mtx != 0) {
        mtx->mRows[2].z = zScale;
    }
    {
        s32 negSumLR = -(right + left);
        s32 negSumTB = -(top + bottom);
        s32 sumNF = farPlane + nearPlane;
        s32 xTranslate = (invWidth * negSumLR + 0x80000000) >> 32;
        s32 yTranslate = (invHeight * negSumTB + 0x80000000) >> 32;
        s32 zTranslate = (invDepth * sumNF + 0x80000000) >> 32;
        if (draw != 0) {
            *fifo = xTranslate;
            *fifo = yTranslate;
            *fifo = zTranslate;
            *fifo = scaleW;
        }
        if (mtx != 0) {
            mtx->mRows[3].x = xTranslate;
            mtx->mRows[3].y = yTranslate;
            mtx->mRows[3].z = zTranslate;
        }
    }
}

// Builds a view matrix from the camera position, the up vector and the target. With draw nonzero it sets the position
// vector matrix mode and loads the 12 words with the 4x3 load command; with mtx not null it stores them there.
void G3i_LookAt_(const Vec3 *camPos, const Vec3 *camUp, const Vec3 *target, int draw, MtxFx43 *mtx) {
    Vec3 look;
    Vec3 right;
    Vec3 up;
    s32 transX;
    s32 transY;
    s32 transZ;
    vu32 *fifo;

    look.x = camPos->x - target->x;
    look.y = camPos->y - target->y;
    look.z = camPos->z - target->z;
    VEC_Normalize(&look, &look);
    VEC_CrossProduct(camUp, &look, &right);
    VEC_Normalize(&right, &right);
    VEC_CrossProduct(&look, &right, &up);
    if (draw != 0) {
        reg_G3_MTX_MODE = 2;
        fifo = &reg_G3_MTX_LOAD_4x3;
        *fifo = right.x;
        *fifo = up.x;
        *fifo = look.x;
        *fifo = right.y;
        *fifo = up.y;
        *fifo = look.y;
        *fifo = right.z;
        *fifo = up.z;
        *fifo = look.z;
    }
    transX = -VEC_DotProduct(camPos, &right);
    transY = -VEC_DotProduct(camPos, &up);
    transZ = -VEC_DotProduct(camPos, &look);
    if (draw != 0) {
        *fifo = transX;
        *fifo = transY;
        *fifo = transZ;
    }
    if (mtx != 0) {
        mtx->mRows[0].x = right.x;
        mtx->mRows[0].y = up.x;
        mtx->mRows[0].z = look.x;
        mtx->mRows[1].x = right.y;
        mtx->mRows[1].y = up.y;
        mtx->mRows[1].z = look.y;
        mtx->mRows[2].x = right.z;
        mtx->mRows[2].y = up.z;
        mtx->mRows[2].z = look.z;
        mtx->mRows[3].x = transX;
        mtx->mRows[3].y = transY;
        mtx->mRows[3].z = transZ;
    }
}

// Resets the geometry engine and its registers to the start state: clears the FIFO and the matrix stacks, sets the
// clear color, depth, fog and BG0 registers, clears the tables and sets the default polygon attributes.
void G3X_Init(void) {
    G3X_ClearFifo();
    reg_G3_END_VTXS = 0;
    while (reg_G3X_GXSTAT & 0x8000000) {
    }
    reg_G3X_DISP3DCNT = 0;
    reg_G3X_GXSTAT = 0;
    reg_G2_BG0OFS = 0;
    reg_G3X_DISP3DCNT |= REG_G3X_DISP3DCNT_GO_MASK;
    reg_G3X_DISP3DCNT |= REG_G3X_DISP3DCNT_RO_MASK;
    reg_G3X_DISP3DCNT &= ~(REG_G3X_DISP3DCNT_GO_MASK | REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_THS_MASK);
    reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~(REG_G3X_DISP3DCNT_GO_MASK | REG_G3X_DISP3DCNT_RO_MASK)) | 0x10;
    reg_G3X_DISP3DCNT &= (u16) ~(REG_G3X_DISP3DCNT_GO_MASK | REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_ATE_MASK);
    reg_G3X_GXSTAT |= 0x8000;
    reg_G3X_GXSTAT = (reg_G3X_GXSTAT & ~0xc0000000) | 0x80000000;
    G3X_InitMtxStack();
    reg_G3X_CLEAR_COLOR = 0;
    reg_G3X_CLEAR_DEPTH = 0x7fff;
    reg_G3X_CLRIMAGE_OFFSET = 0;
    reg_G3X_FOG_COLOR = 0;
    reg_G3X_FOG_OFFSET = 0;
    reg_G2_BG0CNT &= ~REG_G2_BG0CNT_PRIORITY_MASK;
    G3X_InitTable();
    reg_G3_POLYGON_ATTR = 0x1f0080;
    reg_G3_TEXIMAGE_PARAM = 0;
    reg_G3_PLTT_BASE = 0;
}

// Waits for the geometry engine, resets the matrix stacks and sets the default polygon attributes, texture
// parameters and palette base.
void G3X_Reset(void) {
    while (reg_G3X_GXSTAT & 0x8000000) {
    }
    reg_G3X_GXSTAT |= 0x8000;
    reg_G3X_DISP3DCNT |= REG_G3X_DISP3DCNT_GO_MASK;
    reg_G3X_DISP3DCNT |= REG_G3X_DISP3DCNT_RO_MASK;
    G3X_ResetMtxStack();
    reg_G3_POLYGON_ATTR = 0x1f0080;
    reg_G3_TEXIMAGE_PARAM = 0;
    reg_G3_PLTT_BASE = 0;
}

// Writes 128 zero words to the geometry FIFO, then waits for the geometry engine.
void G3X_ClearFifo(void) {
    GXi_NopClearFifo128_((void *) &reg_G3X_GXFIFO);
    while (reg_G3X_GXSTAT & 0x8000000) {
    }
}

// Pops the projection and position vector stacks to their bottom and loads the identity matrix into the texture,
// projection and position vector matrices.
void G3X_InitMtxStack(void) {
    s32 positionLevel;
    s32 projectionLevel;

    reg_G3X_GXSTAT |= 0x8000;
    while (G3X_GetMtxStackLevelPV(&positionLevel) != 0) {
    }
    while (G3X_GetMtxStackLevelPJ(&projectionLevel) != 0) {
    }
    reg_G3_MTX_MODE = 3;
    reg_G3_MTX_IDENTITY = 0;
    reg_G3_MTX_MODE = 0;
    if (projectionLevel != 0) {
        reg_G3_MTX_POP = projectionLevel;
    }
    reg_G3_MTX_IDENTITY = 0;
    reg_G3_MTX_MODE = 2;
    reg_G3_MTX_POP = positionLevel;
    reg_G3_MTX_IDENTITY = 0;
}

// As G3X_InitMtxStack, except that the projection matrix does not get the identity matrix.
void G3X_ResetMtxStack(void) {
    s32 positionLevel;
    s32 projectionLevel;

    reg_G3X_GXSTAT |= 0x8000;
    while (G3X_GetMtxStackLevelPV(&positionLevel) != 0) {
    }
    while (G3X_GetMtxStackLevelPJ(&projectionLevel) != 0) {
    }
    reg_G3_MTX_MODE = 3;
    reg_G3_MTX_IDENTITY = 0;
    reg_G3_MTX_MODE = 0;
    if (projectionLevel != 0) {
        reg_G3_MTX_POP = projectionLevel;
    }
    reg_G3_MTX_MODE = 2;
    reg_G3_MTX_POP = positionLevel;
    reg_G3_MTX_IDENTITY = 0;
}

// With enable nonzero, sets the fog offset and the fog mode and slope bits of DISP3DCNT and turns the fog on;
// otherwise clears the fog bits.
void G3X_SetFog(s32 enable, u32 fogMode, u32 fogSlope, u32 fogOffset) {
    if (enable != 0) {
        reg_G3X_FOG_OFFSET = fogOffset;
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~(REG_G3X_DISP3DCNT_GO_MASK | REG_G3X_DISP3DCNT_RO_MASK |
                                                   REG_G3X_DISP3DCNT_FOG_SHIFT_MASK | REG_G3X_DISP3DCNT_FMOD_MASK)) |
                            ((fogSlope << 8) | (fogMode << 6) | 0x80);
    } else {
        reg_G3X_DISP3DCNT = reg_G3X_DISP3DCNT &
                            (u16) ~(REG_G3X_DISP3DCNT_GO_MASK | REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_FME_MASK);
    }
}

// Copies the 16 words of the clip matrix to dest. Returns -1 while the geometry engine is busy, 0 otherwise.
s32 G3X_GetClipMtx(void *dest) {
    if (reg_G3X_GXSTAT & 0x8000000) {
        return -1;
    }
    MI_Copy64B((const void *) 0x4000640, dest);
    return 0;
}

// Copies the 9 words of the vector matrix to dest. Returns -1 while the geometry engine is busy, 0 otherwise.
s32 G3X_GetVectorMtx(void *dest) {
    if (reg_G3X_GXSTAT & 0x8000000) {
        return -1;
    }
    MI_Copy36B((const void *) 0x4000680, dest);
    return 0;
}

// Copies the 8 words of fogTable to the fog table registers.
void G3X_SetFogTable(const void *fogTable) {
    MI_Copy32B(fogTable, (void *) 0x4000360);
}
