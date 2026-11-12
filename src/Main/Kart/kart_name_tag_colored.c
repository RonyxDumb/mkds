#include "Main/Kart/kart_name_tag_colored.h"
#include "Main/Graphics/model_animation_loop.h"

void DrawKartNameTagColoredVertices(u32 texWidthFixed, u32 texHeightFixed, u32 color) {
    ColoredDrawKartNameTagQuadVertices(texWidthFixed, texHeightFixed);
    DrawKartNameTagColorQuad(color);
}
