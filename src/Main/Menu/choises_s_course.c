#include "Main/Menu/choises_s_course.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"

u32 GetCourseNumber(void) {
    return (gRaceSetup->mCourseNumber);
}

u32 ChoisesSGetCurrentRaceKind(void) {
    return gRaceSetup->mRaceKind;
}
