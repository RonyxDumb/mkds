/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define addLink_ func_02010bc8
#include <nnsys/g3d/kernel.h>
#include <nnsys/g3d/anm.h>
#include <nnsys/g3d/binres/res_struct.h>
#include <nnsys/g3d/binres/res_struct_accessor.h>

#pragma thumb off
void addLink_ (NNSG3dAnmObj ** l, NNSG3dAnmObj * item)
{
#ifdef NITRO_DEBUG
    {
        NNSG3dAnmObj * p = *l;
        while (p) {
            NNS_G3D_ASSERT(p != item);
            p = p->next;
        }
    }
#endif
    if (!(*l)) {
        *l = item;
    } else if (!((*l)->next))   {
        if ((*l)->priority > item->priority) {
            NNSG3dAnmObj * p = item;
            while (p->next) {
                p = p->next;
            }
            p->next = (*l);
            *l = item;
        } else {
            (*l)->next = item;
        }
    } else {
        NNSG3dAnmObj * p = *l;
        NNSG3dAnmObj * x = (*l)->next;

        while (x) {
            if (x->priority >= item->priority) {
                NNSG3dAnmObj * pp = item;
                while (pp->next) {
                    pp = pp->next;
                }
                p->next = item;
                pp->next = x;
                return;
            }
            p = x;
            x = x->next;
        }

        p->next = item;
    }
}
