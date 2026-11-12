#include "Main/Sound/sound_file_id_list.h"
#include "Main/Sound/sound_set_load.h"

SndFileIdList *GetSoundSetFileIdList(void) {
    return &gSoundSetFileIdList;
}

SndFileIdList *GetSndDataFileIdList(void) {
    return &gSndDataFileIdList;
}
