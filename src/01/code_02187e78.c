#include "01/code_02187e78.h"
#include "01/code_02188950.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"

void IncrementEntryIndex(MissionRunMapObject *mapObject) {
    int nextEntryIndex;

    if (mapObject->mEntryGroupIndex < gCourseMap->mEntryGroupCount) {
        nextEntryIndex = mapObject->mEntryIndex + 1;
        if (nextEntryIndex >= GetCourseMapEntryGroup(mapObject->mEntryGroupIndex)->mEntryCount) {
            nextEntryIndex = 0;
        }
        mapObject->mEntryIndex = nextEntryIndex;
    }
}
