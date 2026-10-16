#include "lbgx.h"

#include <placeholder.h>

#include <dolphin/gx.h>
#include <dolphin/mtx.h>
#include <sysdolphin/baselib/cobj.h>

bool lbGx_8001E2F8(Vec4* arg0, Vec3* arg1, U8Vec4* arg2, u32 arg3, float argf1)
{
    if (arg3 == 2) {
        GXSetColorUpdate(GX_TRUE);
        GXSetAlphaUpdate(GX_FALSE);
        GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA,
                       GX_LO_NOOP);
        GXSetAlphaCompare(GX_GREATER, 0, GX_AOP_AND, GX_GREATER, 0);
        GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
        GXSetZCompLoc(GX_FALSE);
        GXSetNumTexGens(0);
        GXSetTevClampMode(GX_TEVSTAGE0, 0);
        GXSetNumTevStages(1);
        GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL,
                      GX_COLOR0A0);
        GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
        GXSetNumChans(1);
        GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_REG, GX_SRC_VTX,
                      GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
        GXSetCullMode(GX_CULL_NONE);
        GXClearVtxDesc();
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
        GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
        GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
        GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
        {
            HSD_CObj* cobj = HSD_CObjGetCurrent();
            GXLoadPosMtxImm(HSD_CObjGetViewingMtxPtrDirect(cobj), GX_PNMTX0);
            GXSetCurrentMtx(GX_PNMTX0);
            GXBegin(GX_DRAW_TRIANGLE_STRIP, GX_VTXFMT0, 5);
            {
                float temp_f1;
                float temp_f1_2;
                float temp_f2;
                float temp_f2_2;
                float temp_f3;
                float temp_f4;
                float temp_f4_2;
                float temp_f5;
                PAD_STACK(16);

                temp_f4 = arg0->x * argf1 + arg1->x;
                temp_f2 = arg0->z;
                temp_f1 = arg1->y + arg0->y;
                temp_f3 = arg0->w;
                temp_f5 = temp_f4 + temp_f2;
                temp_f2_2 = temp_f4 - temp_f2;
                temp_f4_2 = temp_f3 + temp_f1;
                temp_f1_2 = temp_f1 - temp_f3;
                GXPosition3f32(temp_f5, temp_f4_2, 0.0f);
                {
                    // Not a #U8Vec4 (or other struct)? Bitfields?
                    u8 v_x, v_y, v_z, v_w;
                    v_w = arg2->w;
                    v_z = arg2->z;
                    v_y = arg2->y;
                    v_x = arg2->x;
                    GXPosition2u8(v_x, v_y);
                    GXPosition2u8(v_z, v_w);
                    GXPosition3f32(temp_f2_2, temp_f4_2, 0.0f);
                    GXPosition2u8(v_x, v_y);
                    GXPosition2u8(v_z, v_w);
                    GXPosition3f32(temp_f5, temp_f1_2, 0.0f);
                    GXPosition2u8(v_x, v_y);
                    GXPosition2u8(v_z, v_w);
                    GXPosition3f32(temp_f2_2, temp_f4_2, 0.0f);
                    GXPosition2u8(v_x, v_y);
                    GXPosition2u8(v_z, v_w);
                    GXPosition3f32(temp_f2_2, temp_f1_2, 0.0f);
                    GXPosition2u8(v_x, v_y);
                    GXPosition2u8(v_z, v_w);
                    GXEnd();
                    return true;
                }
            }
        }
    }

    return false;
}
