#include "ITCM/code_01ffdee4.h"
#include "ITCM/code_01ffcf7c.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "ITCM/code_01fff000.h"

#include "Main/Unknown/code_020e0680.h"
#include "ITCM/code_01ffd000.h"
#include "ITCM/code_01fff434.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02147cd8.h"
#include "registers.h"

BOOL func_01ffdee4(Vec3 *a, Vec3 *b, Vec3 *c, int r, u16 fl, short e, Vec3 *f, Vec3 *g, Vec3 *h, u32 *o, Vec3 *j,
                   Vec3 *k, u16 *l, u32 *m) {
    u16 *pl;
    Unk0217b614_08 *ta;
    s64 ss;
    Vec3 *tb;
    Vec3s16 *tc;
    u16 hw;
    s64 qq;
    s64 tq;
    Unk0217b614_08 tr;
    Vec3 pa;
    Vec3 pb;
    Vec3 ua;
    Vec3 ub;
    BOOL rv = FALSE;
    Vec3 uc = {0, 0, 0};
    BOOL fa = f != NULL || g != NULL || h != NULL;
    u32 ra = 0;
    CollisionHitRecord wa = data_0216b8c4;
    CollisionHitRecord wb = data_0216b8ec;
    Vec3 ca = {0, 0, 0};
    Vec3 cb = {0, 0, 0};
    Vec3 cc = {0, 0, 0};
    Vec3 cd = {0, 0, 0};
    Vec3 vt;
    Vec3 n[4];
    Vec3 ud;
    CourseCollision *kp;
    u32 x;
    u32 y;
    u32 z;
    u32 sh;
    u8 *p;
    s32 v;
    u16 ix;
    s32 pe;
    s32 d0;
    s32 d1;
    s32 d2;
    s32 d3;
    u16 at;
    s32 dt;
    u32 bt;
    s32 i;
    s32 ct;
    void *ob;
    u32 bi;

    if (j != NULL) {
        ud.x = 0;
        ud.z = 0;
        ud.y = r * 2;
    }
    gCollisionHitCount = 0;
    kp = &gCourseCollision;
    pa = *a;
    if (b != NULL) {
        pb = *b;
    }
    x = (pa.x - kp->mUnk_14) >> 12;
    ss = (s64) r * r;
    if (x & kp->mUnk_20) {
        return FALSE;
    }
    y = (pa.y - kp->mUnk_18) >> 12;
    if (y & kp->mUnk_24) {
        return FALSE;
    }
    z = (pa.z - kp->mUnk_1c) >> 12;
    if (z & kp->mUnk_28) {
        return FALSE;
    }
    sh = kp->mUnk_2c;
    v = ((z >> sh) << kp->mUnk_34) | ((y >> sh) << kp->mUnk_30) | (x >> sh);
    p = kp->mUnk_0c;
    v = ((s32 *) p)[v];
    while (v >= 0) {
        p += v;
        sh--;
        v = ((s32 *) p)[((x >> sh) & 1) | ((((z >> sh) & 1) << 2) | (((y >> sh) & 1) << 1))];
    }
    p += v & 0x7fffffff;
    ta = kp->mUnk_08;
    tb = kp->mUnk_00;
    tc = kp->mUnk_04;
    pl = (u16 *) p;
    while ((ix = *++pl) != 0) {
        tr = ta[ix];
        vt = tb[tr.mUnk_04];
        VEC_Subtract(&pa, &vt, &ua);
        n[3].x = tc[tr.mUnk_0c].x;
        n[3].y = tc[tr.mUnk_0c].y;
        n[3].z = tc[tr.mUnk_0c].z;
        dt = Vec3DotUnrounded(&ua, &n[3]);
        if (dt < -r) {
            continue;
        }
        d3 = dt - tr.mUnk_00;
        if (d3 >= r) {
            continue;
        }
        n[1].x = tc[tr.mUnk_08].x;
        n[1].y = tc[tr.mUnk_08].y;
        n[1].z = tc[tr.mUnk_08].z;
        d1 = Vec3DotUnrounded(&ua, &n[1]);
        if (d1 >= r) {
            continue;
        }
        n[2].x = tc[tr.mUnk_0a].x;
        n[2].y = tc[tr.mUnk_0a].y;
        n[2].z = tc[tr.mUnk_0a].z;
        d2 = Vec3DotUnrounded(&ua, &n[2]);
        if (d2 >= r) {
            continue;
        }
        n[0].x = tc[tr.mUnk_06].x;
        n[0].y = tc[tr.mUnk_06].y;
        n[0].z = tc[tr.mUnk_06].z;
        d0 = Vec3DotUnrounded(&ua, &n[0]);
        pe = r - d0;
        if (pe >= 0 && pe <= 0x1e000) {
            at = tr.mUnk_0e;
            if (at & 0x2010) {
                if ((fl & 4) && (at & 0x2000)) {
                    continue;
                }
                if ((fl & 1) && (at & 0x10)) {
                    continue;
                }
            }
            if ((fl & 0x10) && (at & 0xa000)) {
                continue;
            }
            uc.y = -(s32) (((s64) d0 * n[0].y) >> 12);
            uc.x = -(s32) (((s64) d0 * n[0].x) >> 12);
            uc.z = -(s32) (((s64) d0 * n[0].z) >> 12);
            v = 1;
            if (d1 > d2) {
                if (d1 > d3) {
                    goto la;
                } else {
                    goto lc;
                }
            } else {
                if (d2 > d3) {
                    goto lb;
                } else {
                    goto lc;
                }
            }
        la:
            if (d1 <= 0) {
                goto lm;
            }
            if (d0 < 0) {
                if (b == NULL) {
                    continue;
                }
                VEC_Subtract(&pb, &vt, &ub);
                if (Vec3DotUnrounded(&ub, &n[0]) < 0) {
                    continue;
                }
                if (Vec3DotUnrounded(&ub, &n[1]) > 0) {
                    continue;
                }
            }
            if (d2 > d3) {
                dt = Vec3DotUnrounded(&n[1], &n[2]);
                if ((s32) (((s64) dt * d1) >> 12) > d2) {
                    goto ld;
                } else {
                    goto lg;
                }
            } else {
                dt = Vec3DotUnrounded(&n[1], &n[3]);
                if ((s32) (((s64) dt * d1) >> 12) > d3) {
                    goto ld;
                } else {
                    goto li;
                }
            }
        lb:
            if (d2 <= 0) {
                goto lm;
            }
            if (d0 < 0) {
                if (b == NULL) {
                    continue;
                }
                VEC_Subtract(&pb, &vt, &ub);
                if (Vec3DotUnrounded(&ub, &n[0]) < 0) {
                    continue;
                }
                if (Vec3DotUnrounded(&ub, &n[2]) > 0) {
                    continue;
                }
            }
            if (d3 > d1) {
                dt = Vec3DotUnrounded(&n[2], &n[3]);
                if ((s32) (((s64) dt * d2) >> 12) > d3) {
                    goto le;
                } else {
                    goto lh;
                }
            } else {
                dt = Vec3DotUnrounded(&n[2], &n[1]);
                if ((s32) (((s64) dt * d2) >> 12) > d1) {
                    goto le;
                } else {
                    goto lg;
                }
            }
        lc:
            if (d3 <= 0) {
                goto lm;
            }
            if (d0 < 0) {
                if (b == NULL) {
                    continue;
                }
                VEC_Subtract(&pb, &vt, &ub);
                if (Vec3DotUnrounded(&ub, &n[0]) < 0) {
                    continue;
                }
                if (Vec3DotUnrounded(&ub, &n[3]) > tr.mUnk_00) {
                    continue;
                }
            }
            if (d1 > d2) {
                dt = Vec3DotUnrounded(&n[3], &n[1]);
                if ((s32) (((s64) dt * d3) >> 12) > d1) {
                    goto lf;
                } else {
                    goto li;
                }
            } else {
                dt = Vec3DotUnrounded(&n[3], &n[2]);
                if ((s32) (((s64) dt * d3) >> 12) > d2) {
                    goto lf;
                } else {
                    goto lh;
                }
            }
        ld:
            qq = ss - (s64) d1 * d1;
            if (n[1].y > 0x424 || n[1].y < -0x424) {
                v = 0;
            }
            if (j != NULL) {
                VEC_MultAdd(-d1, &n[1], &uc, &uc);
            }
            goto lk;
        le:
            qq = ss - (s64) d2 * d2;
            if (n[2].y > 0x424 || n[2].y < -0x424) {
                v = 0;
            }
            if (j != NULL) {
                VEC_MultAdd(-d2, &n[2], &uc, &uc);
            }
            goto lk;
        lf:
            qq = ss - (s64) d3 * d3;
            if (n[3].y > 0x424 || n[3].y < -0x424) {
                v = 0;
            }
            if (j != NULL) {
                VEC_MultAdd(-d3, &n[3], &uc, &uc);
            }
            goto lk;
        lg:
            func_01fff434(dt, d2, d1, &ua, &n[1], &n[2], &qq);
            goto lj;
        lh:
            func_01fff434(dt, d3, d2, &ua, &n[2], &n[3], &qq);
            goto lj;
        li:
            func_01fff434(dt, d1, d3, &ua, &n[3], &n[1], &qq);
        lj:
            qq = ss - qq;
            if (qq <= 0) {
                continue;
            }
            if (j != NULL) {
                VEC_Subtract(&uc, &ua, &uc);
            }
            v = 0;
        lk:
            tq = qq;
            reg_CP_SQRTCNT = 1;
            reg_CP_SQRT_PARAM = tq;
            while (reg_CP_SQRTCNT & 0x8000) {
            }
            pe = reg_CP_SQRT_RESULT - d0;
            if (pe < 0) {
                continue;
            }
            goto ln;
        lm:
            if (d0 < 0 && b != NULL) {
                VEC_Subtract(&pb, &vt, &ub);
                if (Vec3DotUnrounded(&ub, &n[0]) < 0) {
                    if (fl & 0x20) {
                        continue;
                    }
                    if (Vec3DotUnrounded(&ub, &n[1]) > 0) {
                        continue;
                    }
                    if (Vec3DotUnrounded(&ub, &n[2]) > 0) {
                        continue;
                    }
                    if (Vec3DotUnrounded(&ub, &n[3]) > tr.mUnk_00) {
                        continue;
                    }
                }
            }
            v = 0;
        ln:
            bt = 1 << ((at & 0x1f00) >> 8);
            bt |= 1 << (((at & 0xc) >> 2) + 0x1a);
            bt |= (at & 2) << 0x17;
            if (b != NULL) {
                VEC_Subtract(&pb, &vt, &ub);
                dt = Vec3DotUnrounded(&ub, &n[0]);
                if (dt < 0) {
                    if (v && (bt & 0x214300) && c != 0) {
                        ua.x = ((s64) pe * n[0].x) >> 2;
                        ua.z = ((s64) pe * n[0].z) >> 2;
                        if (ua.x > cc.x) {
                            cc.x = ua.x;
                        } else if (ua.x < cd.x) {
                            cd.x = ua.x;
                        }
                        if (ua.z > cc.z) {
                            cc.z = ua.z;
                        } else if (ua.z < cd.z) {
                            cd.z = ua.z;
                        }
                    }
                    if (fl & 0x3b) {
                        continue;
                    }
                    if (dt < -0xa000) {
                        continue;
                    }
                }
                VEC_Subtract(&pa, &pb, &ub);
                if (Vec3DotUnrounded(&ub, &n[0]) > 0x333) {
                    if (v && (bt & 0x214300) && c != 0) {
                        ua.x = ((s64) pe * n[0].x) >> 2;
                        ua.z = ((s64) pe * n[0].z) >> 2;
                        if (ua.x > cc.x) {
                            cc.x = ua.x;
                        } else if (ua.x < cd.x) {
                            cd.x = ua.x;
                        }
                        if (ua.z > cc.z) {
                            cc.z = ua.z;
                        } else if (ua.z < cd.z) {
                            cd.z = ua.z;
                        }
                    }
                    continue;
                }
            }
            if ((fl & 2) && (bt & 0x200)) {
                continue;
            }
            if (j != NULL && uc.y < ud.y) {
                ud = uc;
            }
            if (fa) {
                uc.x = ((s64) pe * n[0].x) >> 2;
                uc.y = ((s64) pe * n[0].y) >> 2;
                uc.z = ((s64) pe * n[0].z) >> 2;
                if (bt & 0x1e34ef) {
                    if (uc.x > wa.mMaxOffset.x) {
                        wa.mMaxOffset.x = uc.x;
                    } else if (uc.x < wa.mMinOffset.x) {
                        wa.mMinOffset.x = uc.x;
                    }
                    if (uc.y > wa.mMaxOffset.y) {
                        wa.mMaxOffset.y = uc.y;
                    } else if (uc.y < wa.mMinOffset.y) {
                        wa.mMinOffset.y = uc.y;
                    }
                    if (uc.z > wa.mMaxOffset.z) {
                        wa.mMaxOffset.z = uc.z;
                    } else if (uc.z < wa.mMinOffset.z) {
                        wa.mMinOffset.z = uc.z;
                    }
                    if (g != NULL && pe >= wa.mDeepestDepth) {
                        wa.mDeepestDepth = pe;
                        wa.mDeepestNormal.x = n[0].x;
                        wa.mDeepestNormal.y = n[0].y;
                        wa.mDeepestNormal.z = n[0].z;
                    }
                } else if (bt & 0x214300) {
                    if (bt & 0x10000) {
                        bt |= data_02156904;
                        if (uc.x > ca.x) {
                            ca.x = uc.x;
                        } else if (uc.x < cb.x) {
                            cb.x = uc.x;
                        }
                        if (uc.y > ca.y) {
                            ca.y = uc.y;
                        } else if (uc.y < cb.y) {
                            cb.y = uc.y;
                        }
                        if (uc.z > ca.z) {
                            ca.z = uc.z;
                        } else if (uc.z < cb.z) {
                            cb.z = uc.z;
                        }
                    } else {
                        if (uc.x > wb.mMaxOffset.x) {
                            wb.mMaxOffset.x = uc.x;
                        } else if (uc.x < wb.mMinOffset.x) {
                            wb.mMinOffset.x = uc.x;
                        }
                        if (uc.y > wb.mMaxOffset.y) {
                            wb.mMaxOffset.y = uc.y;
                        } else if (uc.y < wb.mMinOffset.y) {
                            wb.mMinOffset.y = uc.y;
                        }
                        if (uc.z > wb.mMaxOffset.z) {
                            wb.mMaxOffset.z = uc.z;
                        } else if (uc.z < wb.mMinOffset.z) {
                            wb.mMinOffset.z = uc.z;
                        }
                    }
                    if (h != NULL && pe >= wb.mDeepestDepth) {
                        wb.mDeepestDepth = pe;
                        wb.mDeepestNormal.x = n[0].x;
                        wb.mDeepestNormal.y = n[0].y;
                        wb.mDeepestNormal.z = n[0].z;
                    }
                    if (c != 0) {
                        if (((s32 *) &uc)[0] > cc.x) {
                            cc.x = ((s32 *) &uc)[0];
                        } else if (((s32 *) &uc)[0] < cd.x) {
                            cd.x = ((s32 *) &uc)[0];
                        }
                        if (((s32 *) &uc)[2] > cc.z) {
                            cc.z = ((s32 *) &uc)[2];
                        } else if (((s32 *) &uc)[2] < cd.z) {
                            cd.z = ((s32 *) &uc)[2];
                        }
                    }
                }
            }
            ra |= data_02156908;
            ra |= bt;
            if (gCollisionHitCount == 16) {
                gCollisionHitCount--;
            }
            gCollisionHitBits[gCollisionHitCount] = bt;
            rv = TRUE;
            gCollisionHitValues[gCollisionHitCount] = at;
            gCollisionHitCount++;
        }
    }
    if (k != NULL) {
        k->x = 0;
        k->y = 0;
        k->z = 0;
    }
    if (l != NULL) {
        *l = 0;
    }
    if (m != NULL) {
        *(void ***) m = data_0217b5d0;
        data_0217b5d0[1] = NULL;
        data_0217b5d0[0] = NULL;
    }
    if (data_0217b610 != 0 && e != -2) {
        ct = 0;
        if (e == -1) {
            FindCollisionSlotsAroundPos(a, r, 0x1000);
        } else {
            FindCollisionSlotsOverlappingSlot(e, 0x1000);
        }
        for (i = 0; i < gFoundCollisionSlotCount; i++) {
            ob = gFoundCollisionSlotObjects[i];
            if (ComputeSphereHitOnCollisionData(ob, a, r, fl, &wa, &wb, j != NULL ? &ud : 0, &hw, k, l)) {
                ra |= data_0215690c;
                ra |= 1 << hw;
                if (gCollisionHitCount == 16) {
                    gCollisionHitCount--;
                }
                bi = 1 << hw;
                gCollisionHitBits[gCollisionHitCount] = bi;
                gCollisionHitValues[gCollisionHitCount] = hw << 8;
                gCollisionHitCount++;
                if (m != NULL) {
                    if (bi & 0x1e34ef) {
                        data_0217b5d0[ct++] = data_0217b5d0[0];
                        data_0217b5d0[0] = ob;
                    } else {
                        data_0217b5d0[ct++] = ob;
                    }
                    data_0217b5d0[ct] = NULL;
                    if (ct >= 15) {
                        ct--;
                    }
                }
                rv = TRUE;
            }
        }
    }
    if (rv == FALSE) {
        return rv;
    }
    if (g != NULL) {
        *g = wa.mDeepestNormal;
    }
    if (h != NULL) {
        *h = wb.mDeepestNormal;
    }
    if (j != NULL) {
        *j = ud;
    }
    if (f != NULL) {
        uc.y = wa.mMaxOffset.y > wb.mMaxOffset.y ? wa.mMaxOffset.y : wb.mMaxOffset.y;
        uc.y += wa.mMinOffset.y < wb.mMinOffset.y ? wa.mMinOffset.y : wb.mMinOffset.y;
        if (ra & 0x10000) {
            if (j != NULL && (ra & 0x1e34ef) && !(ra & 0x400) && !(ra & 0x800)) {
                ud.x >>= 4;
                ud.y >>= 4;
                ud.z >>= 4;
                if (ud.y * ud.y < ud.x * ud.x + ud.z * ud.z) {
                    uc.y = 0;
                    ra = (ra & 0xffe1cb10) | data_02156910;
                    if (g != NULL) {
                        g->x = 0;
                        g->y = 0;
                        g->z = 0;
                    }
                } else {
                    ra &= ~0x10000;
                    goto lo;
                }
            } else {
                ra = (ra & ~0x10000) | data_02156910;
            }
            if (ca.y > uc.y) {
                uc.y = ca.y;
            }
            if (ca.x > wb.mMaxOffset.x) {
                wb.mMaxOffset.x = ca.x;
            }
            if (cb.x < wb.mMinOffset.x) {
                wb.mMinOffset.x = cb.x;
            }
            if (ca.z > wb.mMaxOffset.z) {
                wb.mMaxOffset.z = ca.z;
            }
            if (cb.z < wb.mMinOffset.z) {
                wb.mMinOffset.z = cb.z;
            }
        }
    lo:
        uc.x = wa.mMaxOffset.x > wb.mMaxOffset.x ? wa.mMaxOffset.x : wb.mMaxOffset.x;
        uc.x += wa.mMinOffset.x < wb.mMinOffset.x ? wa.mMinOffset.x : wb.mMinOffset.x;
        uc.z = wa.mMaxOffset.z > wb.mMaxOffset.z ? wa.mMaxOffset.z : wb.mMaxOffset.z;
        uc.z += wa.mMinOffset.z < wb.mMinOffset.z ? wa.mMinOffset.z : wb.mMinOffset.z;
        f->x = uc.x >> 10;
        f->y = uc.y >> 10;
        f->z = uc.z >> 10;
        if ((ra & 0x214300) && c != 0 && k != NULL && h != NULL) {
            cc.x = cc.x + cd.x;
            cc.z = cc.z + cd.z;
            qq = (s64) cc.x * h->z - (s64) cc.z * h->x;
            if (qq < -16 || qq > 16) {
                cd.x = ((s64) cc.x * (c)->x) >> 12;
                cd.z = ((s64) cc.z * (c)->z) >> 12;
                cc.x = cc.x - (s32) (((s64) cd.x * (c)->x) >> 12);
                cc.z = cc.z - (s32) (((s64) cd.z * (c)->z) >> 12);
                VEC_Add(&wa.mMaxOffset, &wa.mMinOffset, &ua);
                if (Vec3DotUnrounded(&cc, &ua) >= 0) {
                    if ((s64) cc.x * cc.x + (s64) cc.y * cc.y + (s64) cc.z * cc.z >= 16) {
                        Vec3NormalizeAndGetLengthUnchecked(&cc, &cc);
                    }
                    cc.x = ((s64) cc.x * (r >> 5)) >> 12;
                    cc.y = ((s64) cc.y * (r >> 5)) >> 12;
                    cc.z = ((s64) cc.z * (r >> 5)) >> 12;
                    k->x += cc.x;
                    k->z += cc.z;
                }
            }
        }
    }
    if (o != NULL) {
        *o = ra;
    }
    return rv;
}
