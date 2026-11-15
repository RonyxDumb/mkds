#include "Main/MapObjects/shadow_model_alpha.h"
#include "01/MapObjects/map_object_model.h"
#include "Main/MapObjects/view_frustum.h"

void DrawShadowModelWithMaxAlpha(ShadowModel *model, int maxAlpha) {
    u16 savedAlpha;
    u16 savedPolygonId;
    u16 newPolygonId;
    savedAlpha = model->mAlpha;
    if (maxAlpha < savedAlpha) {
        savedPolygonId = model->mPolygonId;
        newPolygonId = AllocPolygonIdWrapping();
        model->mPolygonId = newPolygonId;
        model->mAlpha = maxAlpha;
        DrawShadowModelIfDrawFlag(model);
        model->mPolygonId = savedPolygonId;
        model->mAlpha = savedAlpha;
        return;
    }
    DrawShadowModelIfDrawFlag();
}
