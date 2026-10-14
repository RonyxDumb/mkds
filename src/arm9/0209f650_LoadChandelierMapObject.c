/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define data_0216759c SDK_data_0216759c
#define data_0217b1a4 SDK_data_0217b1a4
#define data_021675b0 SDK_data_021675b0
extern int data_0216759c;
extern int data_021675b0;
extern void *data_0217b1a4;
extern void *CreateMapObjectFromModel_from_thumb(void *a0, void *a1);
extern void StructMapObject_AddAnimationNsbca_from_thumb(void *obj, void *a1);
extern void StructMapObject_MaybeSetPolygonId(void *obj, int id);
void LoadChandelierMapObject(void *a0) {
    void *obj = CreateMapObjectFromModel_from_thumb(a0, &data_0216759c);
    data_0217b1a4 = obj;
    StructMapObject_AddAnimationNsbca_from_thumb(obj, &data_021675b0);
    StructMapObject_MaybeSetPolygonId(data_0217b1a4, 0x3f);
}
