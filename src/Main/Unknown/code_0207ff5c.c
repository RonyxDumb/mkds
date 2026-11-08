#include "Main/Unknown/code_0207ff5c.h"
#include "Main/Unknown/code_02039774.h"
#include "code_02147cd8.h"

// Steps the cursor to the first next link without a choice; returns the length of the new direction.
u32 AdvancePointLinkCursorToFirstNext(PointLinkCursor *cursor) {
    cursor->mPreviousLink = cursor->mLink;
    cursor->mLink = cursor->mLink->mUnk_00[0];
    VEC_Subtract(cursor->mLink->mUnk_18, cursor->mPreviousLink->mUnk_18, &cursor->mDirection);
    return Vec3NormalizeAndGetLengthUnchecked(&cursor->mDirection, &cursor->mDirection);
}
