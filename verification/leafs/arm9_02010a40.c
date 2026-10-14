/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define removeLink_ func_02010a40
#include <nnsys/g3d/kernel.h>
#include <nnsys/g3d/anm.h>
#include <nnsys/g3d/binres/res_struct.h>
#include <nnsys/g3d/binres/res_struct_accessor.h>

#pragma thumb off
BOOL removeLink_ (NNSG3dAnmObj ** l, NNSG3dAnmObj * item)
{
    NNSG3dAnmObj * p;
    NNSG3dAnmObj * pp;

    if (!*l) {
        return FALSE;
    }

    if (*l == item) {
        *l = (*l)->next;
        item->next = NULL;
        return TRUE;
    }

    p = (*l)->next;
    pp = (*l);
    while (p) {
        if (p == item) {
            pp->next = p->next;
            p->next = NULL;
            return TRUE;
        }
        pp = p;
        p = p->next;
    }
    return FALSE;
}
