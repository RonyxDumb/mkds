/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define CreateMapObjectFromModel_from_thumb CreateMapObjectFromModel_2_from_thumb
#define data_02167680 SDK_data_021679e8
#define data_0217b1f8 SDK_data_0217b230
#define LoadAirshipMapObject Maybe_helper_0a9db0
extern int data_02167680;
extern void *data_0217b1f8;
extern void *CreateMapObjectFromModel_from_thumb(void *a0, void *a1);
extern void StructMapObject_MaybeSetPolygonId(void *obj, int id);
void LoadAirshipMapObject(void *a0) {
    void *obj = CreateMapObjectFromModel_from_thumb(a0, &data_02167680);
    data_0217b1f8 = obj;
    StructMapObject_MaybeSetPolygonId(obj, 0x3f);
}
