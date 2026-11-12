#include "Main/MapObjects/balloon_park.h"
#include "Main/MapObjects/map_object_park.h"

// Takes the balloon off its kart and parks it.
void ParkBalloon(Balloon *balloon, u16 kartIndex) {
    balloon->mKartIndex = -1;
    balloon->mDrawCount = 1;
    balloon->mDrawList = NULL;
    ParkMapObject(&balloon->mMapObject);
}
