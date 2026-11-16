#include "Main/Unknown/code_020c2118.h"
#include "Main/Unknown/code_020c214c.h"

void r2dres_render(RaceHudOamBuffer *oamBuffer) {
    int state;
    state = r2d_getMapMode();
    if (state != 5) {
        r2dres_renderResults(oamBuffer);
        return;
    }
    r2dres_renderTeamResults(oamBuffer);
}
