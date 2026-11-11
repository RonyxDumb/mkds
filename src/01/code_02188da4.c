#include "01/code_02188da4.h"
#include "01/code_02188e88.h"

void SetStoppedCallback(MissionRunMapObject *mapObject, UnkFunc *callback) {
    if (callback == NULL) {
        callback = (UnkFunc *) StopMapObjectState;
    }
    mapObject->mStoppedCallback = callback;
}

void SetCourseCollisionCallback(MissionRunMapObject *mapObject, void (*callback)(MissionRunMapObject *)) {
    if (callback == NULL) {
        callback = (UnkFunc *) StopMapObjectState;
    }
    mapObject->mCourseCollisionCallback = callback;
}

void SetUnusedCallback(MissionRunMapObject *mapObject, UnkFunc *callback) {
    if (callback == NULL) {
        callback = (UnkFunc *) StopMapObjectState;
    }
    mapObject->mUnk_230 = callback;
}
