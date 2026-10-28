#include "Main/Unknown/code_020f36d8.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f5008.h"
#include "Main/Unknown/code_020fe4b4.h"

void func_020f4884(Unk020f40dc *rec) {
    s32 i;
    u32 k;
    Unk020f40dc_Kind kind;
    s32 t;

    func_020f49bc(rec);
    if (rec->mUnk_0c == 0) {
        return;
    }
    if (rec->mUnk_10 == 0) {
        return;
    }
    if (rec->mUnk_20 != 0) {
        return;
    }
    rec->mUnk_10 -= 1;
    if (rec->mUnk_10 != 0) {
        return;
    }
    if (data_021759c0->mUnk_08 == 5) {
        if (data_021759c0->mUnk_62 == rec->mUnk_04->mUnk_1f8) {
            kind = (Unk020f40dc_Kind) rec->mUnk_00;
            func_020fe958(data_0217bc48[kind].mUnk_08);
        }
    }
    rec->mUnk_08 -= 1;
    k = data_0217bc48[rec->mUnk_00].mUnk_08;
    t = data_027e00cc[k].mUnk_1c;
    data_027e00cc[(int) k].mUnk_1c = t - 1;
    if (rec->mUnk_08 == 0) {
        rec->mUnk_00 = 0x13;
        rec->mUnk_08 = 0;
        rec->mUnk_20 = 0;
        rec->mUnk_0c = 0;
        rec->mUnk_10 = 0;
        rec->mUnk_12 = 0;
        for (i = 0; i < 3; i++) {
            rec->mUnk_14[i] = 0;
        }
    }
}

void func_020f47e4(Unk020f40dc *rec, s32 kind) {
    u32 k;
    s32 t;

    k = data_0217bc48[kind].mUnk_0c;
    rec->mUnk_00 = kind;
    rec->mUnk_08 = k;
    rec->mUnk_20 = 0;
    func_0206c14c(rec->mUnk_04->mUnk_1fc);
    rec->mUnk_0c = data_0217bc48[kind].mUnk_10;
    rec->mUnk_10 = 0;
    rec->mUnk_12 = 0;
    k = data_0217bc48[kind].mUnk_08;
    t = data_027e00cc[k].mUnk_1c;
    data_027e00cc[(int) k].mUnk_1c = t + rec->mUnk_08;
}

void func_020f4754(Unk020f40dc *rec, s32 n) {
    s32 i;
    int k;

    rec->mUnk_08 -= n;
    k = data_0217bc48[rec->mUnk_00].mUnk_08;
    data_027e00cc[(int) k].mUnk_1c = data_027e00cc[k].mUnk_1c - n;
    if (rec->mUnk_08 == 0) {
        rec->mUnk_00 = 0x13;
        rec->mUnk_08 = 0;
        rec->mUnk_20 = 0;
        rec->mUnk_0c = 0;
        rec->mUnk_10 = 0;
        rec->mUnk_12 = 0;
        for (i = 0; i < 3; i++) {
            rec->mUnk_14[i] = 0;
        }
    }
}

void func_020f4718(Unk020f40dc *rec) {
    s32 i;

    rec->mUnk_00 = 0x13;
    rec->mUnk_08 = 0;
    rec->mUnk_20 = 0;
    rec->mUnk_0c = 0;
    rec->mUnk_10 = 0;
    rec->mUnk_12 = 0;
    for (i = 0; i < 3; i++) {
        rec->mUnk_14[i] = 0;
    }
}

void func_020f45f0(Unk020f40dc *rec, s32 keep) {
    s32 t;
    s32 i;
    s32 n;
    s32 j;
    s32 m;
    Unk020f40dc_Kind kind = (Unk020f40dc_Kind) rec->mUnk_00;
    u32 tab = data_0217bc48[kind].mUnk_08;

    if (data_021759c0->mUnk_08 == 5) {
        n = rec->mUnk_08;
        if (rec->mUnk_24 == 0) {
            for (i = 0; i < n; i++) {
                func_020fe828(tab);
            }
        }
    }
    if (rec->mUnk_20 != 0) {
        m = rec->mUnk_08;
        for (j = 0; j < m; j++) {
            func_020f0f70(&data_027e00cc[rec->mUnk_14[j]->mUnk_44], rec->mUnk_14[j]);
        }
    } else if (keep == 0) {
        t = data_027e00cc[tab].mUnk_1c;
        data_027e00cc[(int) tab].mUnk_1c = t - rec->mUnk_08;
    }
    rec->mUnk_00 = 0x13;
    rec->mUnk_08 = 0;
    rec->mUnk_20 = 0;
    rec->mUnk_0c = 0;
    rec->mUnk_10 = 0;
    rec->mUnk_12 = 0;
    for (i = 0; i < 3; i++) {
        rec->mUnk_14[i] = 0;
    }
}

// non-matching: 0x43c bytes vs 0x42c; in the original the rec kind is loaded right after the mode compare (before the
// generator pointer is chosen) and the per-element block is four instructions shorter (register assignment and
// scheduling of the 64-bit products).
void func_020f41c4(Unk020f40dc *rec) {
    Unk0206bcb0 *owner = rec->mUnk_04->mUnk_1fc;
    Unk020f41c4_C *halves = (Unk020f41c4_C *) ((u8 *) owner->mUnk_590 + 0x40);
    Vec3 *dir = &owner->mUnk_168;
    Vec3 *axis = &owner->mUnk_150;
    Unk020f41c4_B *st;
    Unk020f41c4_Row *row;
    Unk020f41c4_A *elem;
    s32 count;
    s32 kind = rec->mUnk_00;
    s32 tab;
    s32 radius;
    s32 angle;
    s32 va;
    s32 vb;
    s32 w1;
    s32 w2;
    s32 d;
    s32 i;

    if (data_021759c0->mUnk_08 == 1) {
        st = &data_0217561c->mUnk_498;
    } else {
        st = &data_0217561c->mUnk_47c;
    }
    st->mUnk_00 = st->mUnk_00 * st->mUnk_08 + st->mUnk_10;
    tab = data_0217bc48[kind].mUnk_08;
    if (data_0217bc34[tab].mUnk_80 != 0) {
        radius = 0x2000;
    } else {
        radius = 0x1800;
    }
    angle = (u16) (st->mUnk_00 >> 48) >> 4;
    count = rec->mUnk_08;
    va = (s32) (((s64) radius * data_0215d4b4[angle * 2]) >> 12);
    vb = (s32) (((s64) radius * data_0215d4b4[angle * 2 + 1]) >> 12);
    func_020f1048(&data_027e00cc[tab], count, rec->mUnk_14, owner->mUnk_74, &owner->mUnk_98);
    if (count <= 0) {
        return;
    }
    row = &data_0215961c[count - 1];
    for (i = 0; i < count; i++) {
        st->mUnk_00 = st->mUnk_00 * st->mUnk_08 + st->mUnk_10;
        w1 = (s32) (((s64) row->mUnk_00[i].mUnk_00 * (0x1000 + (s32) (((st->mUnk_00 >> 32) * 0x333) >> 32))) >> 12);
        st->mUnk_00 = st->mUnk_00 * st->mUnk_08 + st->mUnk_10;
        w2 = (s32) (((s64) row->mUnk_00[i].mUnk_04 * (0x1000 + (s32) (((st->mUnk_00 >> 32) * 0x333) >> 32))) >> 12);
        elem = rec->mUnk_14[i];
        d = (s32) (((s64) w1 * vb) >> 12) - (s32) (((s64) w2 * va) >> 12);
        elem->mUnk_5c.x = (s32) (((s64) dir->x * d) >> 12);
        elem->mUnk_5c.y = (s32) (((s64) dir->y * d) >> 12);
        elem->mUnk_5c.z = (s32) (((s64) dir->z * d) >> 12);
        func_02147fd8((s32) (((s64) w2 * vb) >> 12) + (s32) (((s64) d * va) >> 12), axis, &elem->mUnk_5c,
                      &elem->mUnk_5c);
        elem->mUnk_68.x = 0xcd;
        elem->mUnk_68.y = 0xcd;
        elem->mUnk_68.z = 0xcd;
        elem->mUnk_7c = *halves;
    }
}

void func_020f41b0(Unk020f40dc *rec) {
    rec->mUnk_20 = 10;
    func_020f41c4(rec);
}

s32 func_020f4198(Unk020f40dc *rec, s32 v) {
    if (rec->mUnk_10 != 0) {
        return 0;
    }
    rec->mUnk_10 = v;
    return 1;
}

void func_020f4188(Unk020f40dc *rec, s32 v) {
    rec->mUnk_12 = rec->mUnk_10 - v;
}

void func_020f413c(Unk020f40dc *rec, s32 *kind, s32 *count) {
    s32 i;

    *kind = rec->mUnk_00;
    *count = rec->mUnk_08;
    rec->mUnk_00 = 0x13;
    rec->mUnk_08 = 0;
    rec->mUnk_20 = 0;
    rec->mUnk_0c = 0;
    rec->mUnk_10 = 0;
    rec->mUnk_12 = 0;
    for (i = 0; i < 3; i++) {
        rec->mUnk_14[i] = 0;
    }
}

void func_020f40dc(Unk020f40dc *rec, s32 kind, s32 count) {
    rec->mUnk_00 = kind;
    rec->mUnk_08 = count;
    rec->mUnk_20 = 0;
    func_0206c14c(rec->mUnk_04->mUnk_1fc);
    rec->mUnk_0c = data_0217bc48[kind].mUnk_10;
    rec->mUnk_10 = 0;
    rec->mUnk_12 = 0;
}

void func_020f40a0(s32 idx, s32 amount) {
    int i = data_0217bc48[idx].mUnk_08;

    data_027e00cc[(int) i].mUnk_1c = data_027e00cc[i].mUnk_1c - amount;
}

s32 func_020f4090(s32 idx) {
    return data_0217bc38[idx];
}

void func_020f4020(Unk020f3fa8 *p, Vec3 *points, s32 scale) {
    s32 i;

    for (i = 0; i < 4; i++) {
        p->mUnk_64[i] = &p->mUnk_74[i];
        p->mUnk_74[i] = points[i];
    }
    p->mUnk_60 = 0;
    func_020d7d18(&p->mUnk_00, 1, p->mUnk_64, scale);
}

s32 func_020f3fa8(Unk020f3fa8 *p, Vec3 *v) {
    Vec3 *first;

    p->mUnk_74[p->mUnk_60] = *v;
    p->mUnk_60 += 1;
    p->mUnk_60 &= 3;
    first = p->mUnk_64[0];
    p->mUnk_64[0] = p->mUnk_64[1];
    p->mUnk_64[1] = p->mUnk_64[2];
    p->mUnk_64[2] = p->mUnk_64[3];
    p->mUnk_64[3] = first;
    return func_020d7c84(&p->mUnk_00, 1, p->mUnk_64);
}

s32 func_020f3c54(Unk020f371c_Ref *in, Unk020f371c_Ref *out, Vec3 *pos) {
    Unk020f371c *node = in->mUnk_00;
    Unk020f371c *best;
    Unk020f371c *c;
    Unk020f371c *g;
    Vec3 *v = node->mUnk_18;
    s32 n;
    Unk020f371c *c2;
    Unk020f371c *g2;
    Vec3 *v2;
    s32 m;
    s32 d;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 bestDist;
    s32 i;
    s32 j;
    s32 k;
    Vec3 *q = pos;
    Unk020f371c *n2 = node;

    best = node;
    dx = (v->x - pos->x) >> 12;
    dy = (v->y - pos->y) >> 12;
    dz = (v->z - pos->z) >> 12;
    bestDist = dx * dx + dy * dy + dz * dz;
    for (i = 0; i < n2->mUnk_24; i++) {
        c = node->mUnk_00[i];
        if (c != 0) {
            v = c->mUnk_18;
            dx = (v->x - pos->x) >> 12;
            dy = (v->y - q->y) >> 12;
            dz = (v->z - q->z) >> 12;
            d = dx * dx + dy * dy + dz * dz;
            n = c->mUnk_24;
            if (d < bestDist) {
                bestDist = d;
                best = c;
            }
            for (j = 0; j < n; j++) {
                g = c->mUnk_00[j];
                v = g->mUnk_18;
                dx = (v->x - pos->x) >> 12;
                dy = (v->y - q->y) >> 12;
                dz = (v->z - q->z) >> 12;
                d = dx * dx + dy * dy + dz * dz;
                if (d < bestDist) {
                    bestDist = d;
                    best = g;
                }
            }
            m = c->mUnk_26;
            for (k = 0; k < m; k++) {
                g = c->mUnk_0c[k];
                if (g != node) {
                    v = g->mUnk_18;
                    dx = (v->x - pos->x) >> 12;
                    dy = (v->y - q->y) >> 12;
                    dz = (v->z - q->z) >> 12;
                    d = dx * dx + dy * dy + dz * dz;
                    if (d < bestDist) {
                        bestDist = d;
                        best = g;
                    }
                }
            }
        }
    }
    for (i = 0; i < n2->mUnk_26; i++) {
        c2 = node->mUnk_0c[i];
        if (c2 != 0) {
            v2 = c2->mUnk_18;
            dx = (v2->x - pos->x) >> 12;
            dy = (v2->y - q->y) >> 12;
            dz = (v2->z - q->z) >> 12;
            d = dx * dx + dy * dy + dz * dz;
            m = c2->mUnk_26;
            if (d < bestDist) {
                bestDist = d;
                best = c2;
            }
            for (j = 0; j < m; j++) {
                g2 = c2->mUnk_0c[j];
                v2 = g2->mUnk_18;
                dx = (v2->x - pos->x) >> 12;
                dy = (v2->y - q->y) >> 12;
                dz = (v2->z - q->z) >> 12;
                d = dx * dx + dy * dy + dz * dz;
                if (d < bestDist) {
                    bestDist = d;
                    best = g2;
                }
            }
            n = c2->mUnk_24;
            for (k = 0; k < n; k++) {
                g2 = c2->mUnk_00[k];
                if (g2 != node) {
                    v2 = g2->mUnk_18;
                    dx = (v2->x - pos->x) >> 12;
                    dy = (v2->y - q->y) >> 12;
                    dz = (v2->z - q->z) >> 12;
                    d = dx * dx + dy * dy + dz * dz;
                    if (d < bestDist) {
                        bestDist = d;
                        best = g2;
                    }
                }
            }
        }
    }
    out->mUnk_00 = best;
    out->mUnk_04 = 1;
    return best != node;
}

s32 func_020f3bb4(Unk020f371c_Ref *a, Unk020f371c_Ref *b, Unk020f371c_Ref *out, Vec3 *pos) {
    Vec3 *va = a->mUnk_00->mUnk_18;
    Vec3 *vb = b->mUnk_00->mUnk_18;
    s32 da = ((va->x - pos->x) >> 12) * ((va->x - pos->x) >> 12) + ((va->y - pos->y) >> 12) * ((va->y - pos->y) >> 12) +
             ((va->z - pos->z) >> 12) * ((va->z - pos->z) >> 12);
    s32 db = ((vb->x - pos->x) >> 12) * ((vb->x - pos->x) >> 12) + ((vb->y - pos->y) >> 12) * ((vb->y - pos->y) >> 12) +
             ((vb->z - pos->z) >> 12) * ((vb->z - pos->z) >> 12);

    if (db < da) {
        *out = *b;
        return 1;
    }
    return 0;
}

s32 func_020f3a58(Unk020f371c_Ref *in, Unk020f371c_Ref *out, Vec3 *pos) {
    Unk020f371c *node = in->mUnk_00;
    s32 d;
    Vec3 *v;
    s32 dy;
    Vec3 *q;
    s32 dx;
    s32 start;
    s32 limit;
    s32 dz;
    Unk020f371c *child;
    Unk020f371c *cur;
    Unk020f371c *best;
    s32 bestDist;
    s32 i;

    v = node->mUnk_18;
    dx = (v->x - pos->x) >> 12;
    dy = (v->y - pos->y) >> 12;
    dz = (v->z - pos->z) >> 12;
    start = dx * dx + dy * dy + dz * dz;
    limit = data_02175620->mUnk_58;
    q = pos;

    cur = node;
    do {
        best = 0;
        bestDist = 0x7fffffff;
        for (i = 0; i < cur->mUnk_24; i++) {
            child = cur->mUnk_00[i];
            if (child != 0) {
                v = child->mUnk_18;
                dx = (v->x - pos->x) >> 12;
                dy = (v->y - q->y) >> 12;
                dz = (v->z - q->z) >> 12;
                d = dx * dx + dy * dy + dz * dz;
                if (d < bestDist) {
                    bestDist = d;
                    best = child;
                }
            }
        }
        if (bestDist < start) {
            out->mUnk_00 = best;
            out->mUnk_04 = 1;
            return best != node;
        }
        limit--;
        cur = best;
    } while (limit > 1 && best != node);
    out->mUnk_00 = node;
    out->mUnk_04 = 1;
    return 0;
}

// non-matching: 0x334 bytes vs 0x33c; the original keeps the pointer behind `origin` in a stack rec across the call to
// func_0207a974 (one store and the reloads), ours holds it in r6 and keeps a second copy in a rec.
void func_020f371c(Unk020f371c_Ref *in, Unk020f371c_Ref *out, u32 idx, s32 flag) {
    Unk020f371c *node = in->mUnk_00;
    s32 side = in->mUnk_04;
    Unk020f371c *cur;
    Unk020f371c *child;
    Unk020f371c *best2;
    s32 count;
    s32 count2;
    s32 found;
    s32 best;
    s32 i;
    Vec3 *origin;
    Vec3 *pos;
    Vec3 *o2;
    Vec3 *p2;
    Vec3 *c;
    Unk0206bcb0 *other;
    s32 d;

    if (side != 0) {
        count = node->mUnk_24;
        cur = node->mUnk_00[0];
    } else {
        count = node->mUnk_26;
        cur = node->mUnk_0c[0];
    }
    if (count <= 1 && (side != 0 ? cur->mUnk_26 : cur->mUnk_24) <= 1) {
    done:
        out->mUnk_00 = cur;
        out->mUnk_04 = side;
        return;
    }
    origin = node->mUnk_18;
    found = 0;
    best = 0x5f592e1;
    if (idx < 8) {
        other = func_0207a974(idx);
        pos = &other->mUnk_98;
        o2 = origin;
        p2 = pos;
        {
            s64 sq = (s64) (pos->z - origin->z) * (pos->z - origin->z);
            sq += (s64) (pos->x - origin->x) * (pos->x - origin->x);
            if (sq < 0x225510000000LL) {
                found = 1;
                for (i = 0; i < count; i++) {
                    child = side != 0 ? node->mUnk_00[i] : node->mUnk_0c[i];
                    if (child != 0) {
                        c = child->mUnk_18;
                        if (((p2->x - o2->x) >> 12) * ((c->x - o2->x) >> 12) +
                                ((p2->z - o2->z) >> 12) * ((c->z - o2->z) >> 12) >
                            0) {
                            d = ((c->y - p2->y) >> 12) * ((c->y - p2->y) >> 12) +
                                ((c->x - p2->x) >> 12) * ((c->x - p2->x) >> 12) +
                                ((c->z - p2->z) >> 12) * ((c->z - p2->z) >> 12);
                            if (d < best) {
                                best = d;
                                cur = child;
                            }
                        }
                    }
                }
            }
        }
    }
    if (side == 0 || (found != 0 && flag != 0)) {
        if ((side != 0 ? cur->mUnk_26 : cur->mUnk_24) > 1) {
            best2 = 0;
            count2 = side != 0 ? cur->mUnk_26 : cur->mUnk_24;
            for (i = 0; i < count2; i++) {
                child = side != 0 ? cur->mUnk_0c[i] : cur->mUnk_00[i];
                if (child != 0 && child != node) {
                    if (found != 0) {
                        c = child->mUnk_18;
                        if (((p2->x - o2->x) >> 12) * ((c->x - o2->x) >> 12) +
                                ((p2->z - o2->z) >> 12) * ((c->z - o2->z) >> 12) >
                            0) {
                            d = ((c->y - p2->y) >> 12) * ((c->y - p2->y) >> 12) +
                                ((c->x - p2->x) >> 12) * ((c->x - p2->x) >> 12) +
                                ((c->z - p2->z) >> 12) * ((c->z - p2->z) >> 12);
                            if (d < best) {
                                best = d;
                                best2 = child;
                            }
                        }
                    } else {
                        cur = child;
                        side = 1;
                        goto done;
                    }
                }
            }
            if (best2 != 0) {
                cur = best2;
                if (side == 0) {
                    side = 1;
                } else {
                    side = 0;
                }
            }
        }
    }
    goto done;
}

u8 func_020f36d8(Unk020f36d8 *p) {
    s32 t = p->mUnk_00;

    if (t == 0) {
        return 0xff;
    }
    return (t - data_02175620->mUnk_b0) / 40;
}
