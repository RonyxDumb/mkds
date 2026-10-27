#include "Main/Unknown/code_020e6b58.h"

#include "Main/Unknown/code_02146000.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/unk_0217b000.h"

void func_020e6df0(Unk020e6b58 *p) {
    data_0217b850->mUnk_00.x = 0x1000;
    data_0217b850->mUnk_00.y = 0;
    data_0217b850->mUnk_00.z = 0;
    data_0217b850->mUnk_0c.x = 0;
    data_0217b850->mUnk_0c.y = p->mUnk_0c.y;
    data_0217b850->mUnk_0c.z = p->mUnk_0c.z;
    data_0217b850->mUnk_18.x = 0;
    data_0217b850->mUnk_18.y = -p->mUnk_0c.z;
    data_0217b850->mUnk_18.z = p->mUnk_0c.y;
    func_02146d0c((const s32 *) p, (s32 *) data_0217b848);
    func_02146dfc((const s32 *) data_0217b850, (const s32 *) data_0217b848, (s32 *) data_0217b860);
    {
        Unk020e6b58 *h;
        Vec3 *v;
        s32 a;
        s32 b;

        h = data_0217b85c;
        v = &h->mUnk_18;
        *v = data_0217b848->mUnk_18;
        a = h->mUnk_18.x;
        b = v->z;
        h->mUnk_00.z = -a;
        h->mUnk_00.x = b;
        h->mUnk_00.y = 0;
    }
    if ((s64) data_0217b85c->mUnk_00.x * data_0217b85c->mUnk_00.x +
            (s64) data_0217b85c->mUnk_00.y * data_0217b85c->mUnk_00.y +
            (s64) data_0217b85c->mUnk_00.z * data_0217b85c->mUnk_00.z >=
        0x10) {
        func_02039860(&data_0217b85c->mUnk_00, &data_0217b85c->mUnk_00);
    }
    func_020397a8(&data_0217b85c->mUnk_18, &data_0217b85c->mUnk_00, &data_0217b85c->mUnk_0c);
    *data_0217b854 = *p;
}

s32 func_020e6d88(Vec3 *v) {
    data_0217b84c->mUnk_0c = *v;
    data_0217b84c->mUnk_18 = data_0217b860->mUnk_18;
    func_020397a8(&data_0217b84c->mUnk_0c, &data_0217b84c->mUnk_18, &data_0217b84c->mUnk_00);
    return func_02039860(&data_0217b84c->mUnk_00, &data_0217b84c->mUnk_00);
}

s32 func_020e6d34(Vec3 *v, Unk020e6b58 *h) {
    h->mUnk_0c = *v;
    h->mUnk_18 = data_0217b860->mUnk_18;
    func_020397a8(&h->mUnk_0c, &h->mUnk_18, &h->mUnk_00);
    return func_02039860(&h->mUnk_00, &h->mUnk_00);
}

Unk020e6b58 *func_020e6cf8(Vec3 *param_1) {
    Unk020e6b58 *p;
    Vec3 *q;

    p = data_0217b848;
    q = &p->mUnk_24;
    q->x = param_1->x >> 4;
    q->y = param_1->y >> 4;
    q->z = param_1->z >> 4;
    return data_0217b848;
}

Unk020e6b58 *func_020e6cbc(Vec3 *param_1) {
    Unk020e6b58 *p;
    Vec3 *q;

    p = data_0217b860;
    q = &p->mUnk_24;
    q->x = param_1->x >> 4;
    q->y = param_1->y >> 4;
    q->z = param_1->z >> 4;
    return data_0217b860;
}

Unk020e6b58 *func_020e6c3c(Vec3 *v, s32 a1, s32 a2) {
    Vec3 *q;

    data_0217b860->mUnk_0c.x = (a1 * data_0217b860->mUnk_00.x) >> 12;
    data_0217b860->mUnk_0c.y = a2 + 0x1000;
    data_0217b860->mUnk_0c.z = (a1 * data_0217b860->mUnk_00.z) >> 12;
    q = &data_0217b860->mUnk_24;
    q->x = v->x >> 4;
    q->y = v->y >> 4;
    q->z = v->z >> 4;
    return data_0217b860;
}

void func_020e6c0c(void) {
    data_0217b860->mUnk_0c.z = 0;
    data_0217b860->mUnk_0c.x = data_0217b860->mUnk_0c.z;
    data_0217b860->mUnk_0c.y = 0x1000;
}

Unk020e6b58 *func_020e6bd0(Vec3 *param_1) {
    Unk020e6b58 *p;
    Vec3 *q;

    p = data_0217b84c;
    q = &p->mUnk_24;
    q->x = param_1->x >> 4;
    q->y = param_1->y >> 4;
    q->z = param_1->z >> 4;
    return data_0217b84c;
}

Unk020e6b58 *func_020e6b94(Vec3 *param_1) {
    Unk020e6b58 *p;
    Vec3 *q;

    p = data_0217b85c;
    q = &p->mUnk_24;
    q->x = param_1->x >> 4;
    q->y = param_1->y >> 4;
    q->z = param_1->z >> 4;
    return data_0217b85c;
}

Unk020e6b58 *func_020e6b58(Vec3 *param_1) {
    Unk020e6b58 *p;
    Vec3 *q;

    p = data_0217b844;
    q = &p->mUnk_24;
    q->x = param_1->x >> 4;
    q->y = param_1->y >> 4;
    q->z = param_1->z >> 4;
    return data_0217b844;
}
