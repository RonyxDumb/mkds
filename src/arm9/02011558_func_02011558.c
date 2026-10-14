/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define blendScaleVec_ func_02011558
#include <nnsys/g3d/anm.h>
#include <nnsys/g3d/kernel.h>

#include <nnsys/g3d/anm/nsbca.h>
#include <nnsys/g3d/anm/nsbma.h>
#include <nnsys/g3d/anm/nsbta.h>
#include <nnsys/g3d/anm/nsbtp.h>
#include <nnsys/g3d/anm/nsbva.h>
#include <nnsys/g3d/binres/res_struct_accessor.h>

#include <nitro/code32.h>
#include <nitro/codereset.h>

#include <nitro/code32.h>
#include <nitro/codereset.h>

#pragma thumb off
void blendScaleVec_ (VecFx32 * v0, const VecFx32 * v1, fx32 ratio, BOOL isV1One)
{
    if (isV1One) {

        v0->x += ratio;
        v0->y += ratio;
        v0->z += ratio;
    } else {
        v0->x += ratio * v1->x >> FX32_SHIFT;
        v0->y += ratio * v1->y >> FX32_SHIFT;
        v0->z += ratio * v1->z >> FX32_SHIFT;
    }
}
