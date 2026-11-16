#include "Main/MapObjects/picture_init.h"
#include "Main/MapObjects/picture_puddle.h"

// Index 0 selects gPicture1.
void InitPicture1(Picture *picture) {
    picture->mPictureIndex = 0x0u;
}

// Index 1 selects gPicture2.
void InitPicture2(Picture *picture) {
    picture->mPictureIndex = 0x1u;
}
