#include "Main/Kart/camera_entry.h"
#include "Main/System/wireless_vram_state.h"
#include "Main/Race/race.h"
#include "Main/System/backup_net_camera_work.h"
#include "fixed_vector_math.h"
#include "Main/Kart/camera.h"

u32 GetCameraEntryChanged(void) {
    return gCameraEntryChanged;
}

// Distance of the point a along the forward axis of the current camera.
int GetCameraForwardDistance(const Vec3 *position) {
    Camera *currentCamera;
    Vec3 offset;
    currentCamera = GetGlobalHD4();
    VecFx32_Subtract(position, &currentCamera->mPos, &offset);
    return VecFx32_CrossProduct_0(&currentCamera->mForward, &offset);
}

// Distance of the point a along mSide of the current camera, times mSideDistanceSign (-1 in mirror mode).
int GetCameraSideDistance(const Vec3 *position) {
    Camera *currentCamera;
    int sideDistance;
    Vec3 offset;
    currentCamera = GetGlobalHD4();
    VecFx32_Subtract(position, &currentCamera->mPos, &offset);
    sideDistance = ((u32) VecFx32_CrossProduct_0(&currentCamera->mSide, &offset));
    return currentCamera->mSideDistanceSign * sideDistance;
}
