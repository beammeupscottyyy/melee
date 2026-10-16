#include "gmapproach.h"

#include <melee/ft/forward.h>

#include "gm_unsplit.h"
#include "gmscene.h"
#include <melee/lb/lbarchive.h>
#include <melee/lb/lbaudio_ax.h>
#include <melee/lb/lbspdisplay.h>
#include <melee/sc/types.h>
#include <sysdolphin/baselib/cobj.h>
#include <sysdolphin/baselib/controller.h>
#include <sysdolphin/baselib/dobj.h>
#include <sysdolphin/baselib/gobj.h>
#include <sysdolphin/baselib/gobjgxlink.h>
#include <sysdolphin/baselib/gobjobject.h>
#include <sysdolphin/baselib/gobjproc.h>
#include <sysdolphin/baselib/jobj.h>

static struct gm_80480D98_t {
    HSD_Archive* x0;
    CharacterKind x4;
    u16 x8;
    u16 xA;
    u16 xC;
    u8 xE;
} gm_80480D98;

struct VsApproachData gmVsMelee_ApproachData;

static void fn_801AD920(HSD_GObj* gobj)
{
    HSD_JObj* jobj = gobj->hsd_obj;
    HSD_JObj* var_r3 = gobj->hsd_obj == NULL ? NULL : GET_JOBJ(gobj)->child;
    HSD_JObj* var_r4 = var_r3 == NULL ? NULL : var_r3->next;
    HSD_JObj* var_r0 = var_r4 == NULL ? NULL : var_r4->next;
    int var_r0_2;

    if (gm_80480D98.x8 <= 0x12C) {
        gm_80480D98.x8++;
    } else {
        gm_80480D98.x8 = 0;
    }
    if (gm_80480D98.xA < 0x12C) {
        gm_80480D98.xA++;
    }
    HSD_JObjReqAnimAll(var_r3, gm_80480D98.x8);
    HSD_JObjReqAnimAll(var_r4, gm_80480D98.xA);
    HSD_JObjReqAnimAll(var_r0, gm_80480D98.xA);
    switch (gm_80480D98.x4) {
    case CKind_GameWatch:
        var_r0_2 = 1;
        break;
    case CKind_Luigi:
        var_r0_2 = 2;
        break;
    case CKind_Mars:
        var_r0_2 = 3;
        break;
    case CKind_Mewtwo:
        var_r0_2 = 4;
        break;
    case CKind_Purin:
        var_r0_2 = 5;
        break;
    case CKind_Falco:
        var_r0_2 = 6;
        break;
    case CKind_CLink:
        var_r0_2 = 7;
        break;
    case CKind_DrMario:
        var_r0_2 = 8;
        break;
    case CKind_Emblem:
        var_r0_2 = 9;
        break;
    case CKind_Pichu:
        var_r0_2 = 10;
        break;
    case CKind_Ganon:
        var_r0_2 = 11;
        break;
    default:
        var_r0_2 = 0;
        break;
    }
    HSD_TObjReqAnimAll(var_r0->u.dobj->mobj->tobj, var_r0_2);
    HSD_AObjSetRate(var_r0->u.dobj->mobj->tobj->aobj, 0.0F);
    HSD_JObjAnimAll(jobj);
}

static void gm_801ADB04(void)
{
    SceneDesc* spC;
    HSD_GObj* gobj;
    HSD_JObj* jobj;
    HSD_CObj* cobj;
    HSD_LObj* lobj;
    PAD_STACK(4);

    gm_80480D98.x0 =
        lbArchive_80016DBC("NtAppro", &spC, "ScNtcApproach_scene_data", 0);
    gobj = GObj_Create(0x13, 0x14, 0);
    cobj = HSD_CObjLoadDesc(spC->cameras[0].desc);
    HSD_GObjObject_80390A70(gobj, HSD_GObj_CameraKind, cobj);
    GObj_SetupGXLinkMax(gobj, HSD_GObj_803910D8, 0);
    gobj->gxlink_prios = 0x4801;

    gobj = GObj_Create(0xB, 0xF, 0);
    lobj = lb_80011AC4(spC->lights);
    HSD_GObjObject_80390A70(gobj, HSD_GObj_LightKind, lobj);
    GObj_SetupGXLink(gobj, HSD_GObj_LObjCallback, 0, 0);

    gobj = GObj_Create(0xE, 0xF, 0);
    jobj = HSD_JObjLoadJoint(spC->models[0]->joint);
    HSD_GObjObject_80390A70(gobj, HSD_GObj_JObjKind, jobj);
    GObj_SetupGXLink(gobj, HSD_GObj_JObjCallback, 0xB, 0);
    gm_8016895C(jobj, spC->models[0], 0);
    HSD_JObjReqAnimAll(jobj, 0.0F);
    HSD_JObjAnimAll(jobj);
    HSD_GObj_SetupProc(gobj, fn_801AD920, 1);
}

void gm_Scene_Approach_OnFrame(void)
{
    if (gm_80480D98.xC++ >= 0xB4 &&
        (HSD_PadCopyStatus[gm_80480D98.xE].trigger &
         (HSD_PAD_A | HSD_PAD_START)))
    {
        gm_801A4B60();
    }
}

void gm_Scene_Approach_OnEnter(void* arg0_)
{
    struct VsApproachData* arg0 = arg0_;
    CharacterKind var_r0;

    gm_801ADB04();
    var_r0 = arg0->cpu_ckind;
    if (var_r0 != CKind_GameWatch && var_r0 != CKind_Luigi &&
        var_r0 != CKind_Mars && var_r0 != CKind_Mewtwo &&
        var_r0 != CKind_Purin && var_r0 != CKind_Falco &&
        var_r0 != CKind_CLink && var_r0 != CKind_DrMario &&
        var_r0 != CKind_Emblem && var_r0 != CKind_Pichu &&
        var_r0 != CKind_Ganon)
    {
        var_r0 = CKind_Ganon;
    }

    gm_80480D98.x4 = var_r0;
    gm_80480D98.xE = arg0->human_slot;
    gm_80480D98.x8 = 0;
    gm_80480D98.xA = 0;
    gm_80480D98.xC = 0;
    lbAudioAx_80023F28(0x48);
}

void gm_Scene_Approach_OnExit(UNUSED void* exit_data)
{
    lbArchive_80016EFC(gm_80480D98.x0);
    lbAudioAx_800236DC();
}
