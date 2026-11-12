#include "Main/Net/race_mp_state16.h"
#include "Main/Net/mp.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"

void RequestMPState16ForNextRace(void) {
    u32 courseId;
    u32 mode;
    u32 value12;
    courseId = gRaceSetup->mNextHeader.mCourseId;
    mode = gRaceSetup->mNextHeader.mMode;
    RequestMPState16((void *) courseId, (void *) mode);
}
