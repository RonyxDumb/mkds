#include "Main/Menu/choises_s_course.h"
#include "Main/Unknown/unk_021759c0.h"

u32 GetCourseNumber(void) {
    return (gRaceSetup->mCourseNumber);
}

u32 ChoisesSGetCurrentRaceKind(void) {
    return gRaceSetup->mRaceKind;
}
