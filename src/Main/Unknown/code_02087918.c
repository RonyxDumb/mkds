#include "Main/Unknown/code_02087918.h"
#include "Main/Unknown/code_02087934.h"

void DrawKartNameTagColoredVertices(u32 texWidthFixed, u32 texHeightFixed, u32 color) {
    ColoredDrawKartNameTagQuadVertices(texWidthFixed, texHeightFixed);
    DrawKartNameTagColorQuad(color);
}
