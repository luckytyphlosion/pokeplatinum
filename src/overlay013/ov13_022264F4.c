#include <nitro.h>
#include <string.h>

#include "data_021BF67C.h"

#include "struct_decls/struct_02006C24_decl.h"
#include "struct_decls/struct_0200B144_decl.h"
#include "struct_decls/struct_02018340_decl.h"
#include "struct_decls/struct_0201CD38_decl.h"
#include "struct_decls/struct_02023790_decl.h"
#include "struct_defs/pokemon.h"
#include "struct_decls/struct_020797DC_decl.h"
#include "struct_decls/struct_party_decl.h"
#include "struct_decls/struct_0207ADB4_decl.h"
#include "struct_decls/struct_0207D99C_decl.h"

#include "struct_defs/union_02022594_020225E0.h"
#include "overlay013/struct_ov13_022264F4.h"
#include "overlay013/struct_ov13_02227244.h"
#include "overlay084/struct_ov84_0223BA5C.h"
#include "overlay097/struct_ov97_0222DB78.h"

#include "unk_02002B7C.h"
#include "unk_02002F38.h"
#include "unk_02005474.h"
#include "unk_0200679C.h"
#include "narc.h"
#include "unk_02006E3C.h"
#include "unk_0200AC5C.h"
#include "unk_0200B358.h"
#include "unk_0200C440.h"
#include "unk_0200C6E4.h"
#include "unk_0200DA60.h"
#include "heap.h"
#include "unk_02018340.h"
#include "unk_0201CCF0.h"
#include "unk_0201D670.h"
#include "gx_layers.h"
#include "unk_02022594.h"
#include "strbuf.h"
#include "unk_02073C2C.h"
#include "unk_020797C8.h"
#include "party.h"
#include "item.h"
#include "unk_0207D3B8.h"
#include "overlay013/ov13_022264F4.h"
#include "overlay013/ov13_02227288.h"
#include "overlay013/ov13_02227A4C.h"
#include "overlay013/ov13_02227BDC.h"
#include "overlay013/ov13_02228128.h"
#include "overlay013/ov13_02228A38.h"
#include "overlay016/ov16_0223DF00.h"
#include "overlay016/ov16_0225177C.h"
#include "overlay016/ov16_0226DE44.h"

static void ov13_02226590(UnkStruct_0201CD38 * param0, void * param1);
static u8 ov13_0222668C(UnkStruct_ov13_02227244 * param0);
static u8 ov13_02226760(UnkStruct_ov13_02227244 * param0);
static u8 ov13_02226838(UnkStruct_ov13_02227244 * param0);
static u8 ov13_022269C0(UnkStruct_ov13_02227244 * param0);
static u8 ov13_02226C48(UnkStruct_ov13_02227244 * param0);
static u8 ov13_02226C54(UnkStruct_ov13_02227244 * param0);
static u8 ov13_02226C60(UnkStruct_ov13_02227244 * param0);
static u8 ov13_02226948(UnkStruct_ov13_02227244 * param0);
static u8 ov13_02226C6C(UnkStruct_ov13_02227244 * param0);
static u8 ov13_02226C7C(UnkStruct_ov13_02227244 * param0);
static u8 ov13_02226C94(UnkStruct_ov13_02227244 * param0);
static u8 ov13_02226CBC(UnkStruct_ov13_02227244 * param0);
static u8 ov13_02226D94(UnkStruct_ov13_02227244 * param0);
static u8 ov13_02226CD4(UnkStruct_ov13_02227244 * param0);
static u8 ov13_02226CFC(UnkStruct_0201CD38 * param0, UnkStruct_ov13_02227244 * param1);
static void ov13_02226ED0(UnkStruct_ov13_02227244 * param0);
static void ov13_02226F9C(UnkStruct_02018340 * param0);
static void ov13_02226FC4(UnkStruct_ov13_02227244 * param0);
static void ov13_022270B8(UnkStruct_ov13_02227244 * param0);
static void ov13_022270F8(UnkStruct_ov13_02227244 * param0);
static u8 ov13_02226A5C(UnkStruct_ov13_02227244 * param0);
static void ov13_02227118(UnkStruct_ov13_02227244 * param0, u8 param1);
static void ov13_022271D0(UnkStruct_ov13_02227244 * param0, u8 param1);
static int ov13_02227238(UnkStruct_ov13_02227244 * param0, const UnkUnion_02022594 * param1);
static void ov13_02227260(UnkStruct_0207ADB4 * param0, u16 param1, u16 param2, u32 param3);

static const UnkUnion_02022594 Unk_ov13_02229A1C[] = {
    {0x8, 0x4F, 0x0, 0x7F},
    {0x50, 0x97, 0x0, 0x7F},
    {0x8, 0x4F, 0x80, 0xFF},
    {0x50, 0x97, 0x80, 0xFF},
    {0x98, 0xBF, 0x0, 0xCF},
    {0x98, 0xBF, 0xD8, 0xFF},
    {0xFF, 0x0, 0x0, 0x0}
};

static const UnkUnion_02022594 Unk_ov13_02229A38[] = {
    {0x8, 0x37, 0x0, 0x7F},
    {0x8, 0x37, 0x80, 0xFF},
    {0x38, 0x67, 0x0, 0x7F},
    {0x38, 0x67, 0x80, 0xFF},
    {0x68, 0x97, 0x0, 0x7F},
    {0x68, 0x97, 0x80, 0xFF},
    {0x98, 0xBF, 0x0, 0x27},
    {0x98, 0xBF, 0x28, 0x4F},
    {0x98, 0xBF, 0xD8, 0xFF},
    {0xFF, 0x0, 0x0, 0x0}
};

static const UnkUnion_02022594 Unk_ov13_022299AC[] = {
    {0x98, 0xBF, 0x0, 0xCF},
    {0x98, 0xBF, 0xD8, 0xFF},
    {0xFF, 0x0, 0x0, 0x0}
};

void ov13_022264F4 (UnkStruct_ov13_022264F4 * param0)
{
    UnkStruct_ov13_02227244 * v0;

    v0 = sub_0201CED0(sub_0200679C(ov13_02226590, sizeof(UnkStruct_ov13_02227244), 100, param0->unk_0C));
    memset(v0, 0, sizeof(UnkStruct_ov13_02227244));

    v0->unk_00 = param0;
    v0->unk_04 = ov16_0223DF00(param0->unk_00);
    v0->unk_08 = ov16_0223E064(param0->unk_00);
    v0->unk_114A = 0;

    {
        UnkStruct_0207D99C * v1;
        u8 v2;

        v1 = ov16_0223E1B0(param0->unk_00);

        for (v2 = 0; v2 < 5; v2++) {
            sub_0207D9D8(v1, v2, &v0->unk_00->unk_27[v2], &v0->unk_00->unk_2C[v2]);
        }

        v0->unk_00->unk_20 = sub_0207D9E4(v1);
        v0->unk_00->unk_1F = sub_0207D9E8(v1);
    }

    ov13_02227A4C(v0);

    if (ov16_0223DF0C(v0->unk_00->unk_00) & 0x400) {
        v0->unk_00->unk_14 = 1;
    }
}

static void ov13_02226590 (UnkStruct_0201CD38 * param0, void * param1)
{
    UnkStruct_ov13_02227244 * v0 = (UnkStruct_ov13_02227244 *)param1;

    switch (v0->unk_114A) {
    case 0:
        v0->unk_114A = ov13_0222668C(v0);
        break;
    case 1:
        v0->unk_114A = ov13_02226760(v0);
        break;
    case 2:
        v0->unk_114A = ov13_02226838(v0);
        break;
    case 3:
        v0->unk_114A = ov13_022269C0(v0);
        break;
    case 4:
        v0->unk_114A = ov13_02226C48(v0);
        break;
    case 5:
        v0->unk_114A = ov13_02226C54(v0);
        break;
    case 6:
        v0->unk_114A = ov13_02226C60(v0);
        break;
    case 7:
        v0->unk_114A = ov13_02226948(v0);
        break;
    case 8:
        v0->unk_114A = ov13_02226C6C(v0);
        break;
    case 9:
        v0->unk_114A = ov13_02226C7C(v0);
        break;
    case 10:
        v0->unk_114A = ov13_02226C94(v0);
        break;
    case 11:
        v0->unk_114A = ov13_02226CBC(v0);
        break;
    case 12:
        v0->unk_114A = ov13_02226D94(v0);
        break;
    case 13:
        v0->unk_114A = ov13_02226CD4(v0);
        break;
    case 14:
        if (ov13_02226CFC(param0, v0) == 1) {
            return;
        }
    }

    ov13_02228848(v0);
    sub_0200C7EC(v0->unk_30C);
}

static u8 ov13_0222668C (UnkStruct_ov13_02227244 * param0)
{
    G2S_BlendNone();

    param0->unk_34 = ov13_02228A38(param0->unk_00->unk_0C);

    ov13_02226ED0(param0);
    ov13_02226FC4(param0);
    ov13_022270B8(param0);
    sub_02002BB8(2, param0->unk_00->unk_0C);

    param0->unk_114D = (u8)sub_0207D9EC(ov16_0223E1B0(param0->unk_00->unk_00));

    ov13_02227AC8(param0);
    ov13_02228924(param0, param0->unk_114C);
    ov13_02227288(param0);
    ov13_02227350(param0, param0->unk_114C);
    ov13_02227BDC(param0);
    ov13_02227E68(param0, param0->unk_114C);

    if (param0->unk_00->unk_25 != 0) {
        ov13_02228A60(param0->unk_34, 1);
    }

    ov13_02228008(param0, param0->unk_114C);
    ov13_022280F0(param0, param0->unk_114C);
    sub_02003178(param0->unk_08, (0x2 | 0x8), 0xffff, -8, 16, 0, 0);

    if (param0->unk_00->unk_14 == 1) {
        return 12;
    }

    return 1;
}

static u8 ov13_02226760 (UnkStruct_ov13_02227244 * param0)
{
    if (sub_0200384C(param0->unk_08) != 0) {
        return 1;
    }

    {
        int v0 = ov13_02227238(param0, Unk_ov13_02229A1C);

        if (v0 == 0xffffffff) {
            v0 = ov13_02228B64(param0->unk_34);

            if (v0 == 0xfffffffe) {
                v0 = 5;
            }
        } else {
            ov13_02228050(param0);
        }

        switch (v0) {
        case 0:
        case 1:
        case 2:
        case 3:
            sub_02005748(1501);
            param0->unk_114D = (u8)v0;
            param0->unk_114B = 5;
            ov13_0222880C(param0, 0 + v0 - 0, 0);
            return 11;
        case 4:
            if (param0->unk_00->unk_20 != 0) {
                sub_02005748(1501);
                param0->unk_114D = param0->unk_00->unk_1F;
                param0->unk_114B = 6;
                ov13_02227A7C(param0);
                ov13_0222880C(param0, 4, 0);
                return 11;
            }
            break;
        case 5:
            sub_02005748(1501);
            param0->unk_00->unk_1C = 0;
            param0->unk_00->unk_1E = 4;
            ov13_0222880C(param0, 5, 0);
            return 13;
        }
    }

    return 1;
}

static u8 ov13_02226838 (UnkStruct_ov13_02227244 * param0)
{
    {
        int v0 = ov13_02227238(param0, Unk_ov13_02229A38);

        if (v0 == 0xffffffff) {
            v0 = ov13_02228B64(param0->unk_34);

            if (v0 == 0xfffffffe) {
                v0 = 8;
            }
        } else {
            ov13_02228050(param0);
        }

        switch (v0) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            if (ov13_02227BA8(param0, v0) != 0) {
                sub_02005748(1501);
                param0->unk_00->unk_27[param0->unk_114D] = (u8)v0;
                param0->unk_114B = 6;
                ov13_0222880C(param0, 6 + v0, 0);
                return 11;
            }
            break;
        case 6:
            if (param0->unk_1154[param0->unk_114D] != 0) {
                sub_02005748(1501);
                param0->unk_114B = 7;
                param0->unk_114E = -1;
                ov13_0222880C(param0, 12, 0);
                return 11;
            }
            break;
        case 7:
            if (param0->unk_1154[param0->unk_114D] != 0) {
                sub_02005748(1501);
                param0->unk_114B = 7;
                param0->unk_114E = 1;
                ov13_0222880C(param0, 13, 0);
                return 11;
            }
            break;
        case 8:
            sub_02005748(1501);
            param0->unk_114B = 4;
            ov13_0222880C(param0, 14, 0);
            return 11;
        }
    }

    return 2;
}

static u8 ov13_02226948 (UnkStruct_ov13_02227244 * param0)
{
    s8 v0 = param0->unk_00->unk_2C[param0->unk_114D];

    param0->unk_00->unk_27[param0->unk_114D] = 0;
    v0 += param0->unk_114E;

    if (v0 > param0->unk_1154[param0->unk_114D]) {
        param0->unk_00->unk_2C[param0->unk_114D] = 0;
    } else if (v0 < 0) {
        param0->unk_00->unk_2C[param0->unk_114D] = param0->unk_1154[param0->unk_114D];
    } else {
        param0->unk_00->unk_2C[param0->unk_114D] = v0;
    }

    ov13_02227650(param0);
    ov13_02227698(param0);
    ov13_02227E68(param0, param0->unk_114C);
    ov13_02228924(param0, param0->unk_114C);

    return 2;
}

static u8 ov13_022269C0 (UnkStruct_ov13_02227244 * param0)
{
    {
        int v0 = ov13_02227238(param0, Unk_ov13_022299AC);

        if (v0 == 0xffffffff) {
            v0 = ov13_02228B64(param0->unk_34);

            if (v0 == 0xfffffffe) {
                v0 = 1;
            }
        } else {
            ov13_02228050(param0);
        }

        switch (v0) {
        case 0:
            sub_02005748(1501);
            param0->unk_00->unk_1C = ov13_02227BA8(param0, param0->unk_00->unk_27[param0->unk_114D]);
            param0->unk_00->unk_1E = param0->unk_114D;
            ov13_0222880C(param0, 15, 0);
            return ov13_02226A5C(param0);
        case 1:
            sub_02005748(1501);
            param0->unk_114B = 5;
            ov13_0222880C(param0, 16, 0);
            return 11;
        }
    }

    return 3;
}

static u8 ov13_02226A5C (UnkStruct_ov13_02227244 * param0)
{
    UnkStruct_ov13_022264F4 * v0 = param0->unk_00;

    if (param0->unk_114D == 3) {
        int v1 = ov13_02227244(param0);
        u32 v2 = Item_GetAttribute(v0->unk_1C, 7, v0->unk_0C);

        if ((v0->unk_18 != 0) && (v0->unk_1C != 55) && (v2 != 3)) {
            Pokemon * v3;
            Strbuf* v4;

            v3 = ov16_0223DFAC(v0->unk_00, v0->unk_10, v1);
            v4 = sub_0200B1EC(param0->unk_10, 46);

            sub_0200B5CC(param0->unk_14, 0, sub_02076B10(v3));
            sub_0200B630(param0->unk_14, 1, 373);
            sub_0200C388(param0->unk_14, param0->unk_18, v4);
            Strbuf_Free(v4);

            ov13_022279F4(param0);
            param0->unk_114B = 8;

            return 9;
        }

        if (ov16_0223E30C(v0->unk_00, v0->unk_10, v1, 0, v0->unk_1C) == 1) {
            ov13_02227260(v0->unk_00, v0->unk_1C, param0->unk_114D, v0->unk_0C);
            return 13;
        } else if (v2 == 3) {
            if (!(ov16_0223DF0C(v0->unk_00) & 0x1)) {
                ov13_02227260(v0->unk_00, v0->unk_1C, param0->unk_114D, v0->unk_0C);
                return 13;
            } else {
                UnkStruct_0200B144 * v5;
                Strbuf* v6;

                v5 = sub_0200B144(1, 26, 213, v0->unk_0C);
                v6 = sub_0200B1EC(v5, 36);
                sub_0200B498(param0->unk_14, 0, v0->unk_04);
                sub_0200C388(param0->unk_14, param0->unk_18, v6);
                Strbuf_Free(v6);
                sub_0200B190(v5);
                ov13_022279F4(param0);
                param0->unk_114B = 8;
                return 9;
            }
        } else {
            MessageFormatter_LoadStrbuf(param0->unk_10, 34, param0->unk_18);
            ov13_022279F4(param0);
            param0->unk_114B = 8;
            return 9;
        }
    } else if (param0->unk_114D == 2) {
        if (v0->unk_22 == 1) {
            MessageFormatter_LoadStrbuf(param0->unk_10, 44, param0->unk_18);
            ov13_022279F4(param0);
            param0->unk_114B = 8;
            return 9;
        }

        if (v0->unk_23 == 1) {
            MessageFormatter_LoadStrbuf(param0->unk_10, 47, param0->unk_18);
            ov13_022279F4(param0);
            param0->unk_114B = 8;
            return 9;
        }

        if (v0->unk_24 == 1) {
            MessageFormatter_LoadStrbuf(param0->unk_10, 48, param0->unk_18);
            ov13_022279F4(param0);
            param0->unk_114B = 8;
            return 9;
        }

        {
            Party * v7 = ov16_0223DF20(v0->unk_00, v0->unk_10);
            UnkStruct_020797DC * v8 = ov16_0223E228(v0->unk_00);

            if ((Party_GetCurrentCount(v7) == 6) && (sub_020799A0(v8) == 18)) {
                MessageFormatter_LoadStrbuf(param0->unk_10, 45, param0->unk_18);
                ov13_022279F4(param0);
                param0->unk_114B = 8;
                return 9;
            }
        }
    }

    return 13;
}

static u8 ov13_02226C48 (UnkStruct_ov13_02227244 * param0)
{
    ov13_022271D0(param0, 0);
    return 1;
}

static u8 ov13_02226C54 (UnkStruct_ov13_02227244 * param0)
{
    ov13_022271D0(param0, 1);
    return 2;
}

static u8 ov13_02226C60 (UnkStruct_ov13_02227244 * param0)
{
    ov13_022271D0(param0, 2);
    return 3;
}

static u8 ov13_02226C6C (UnkStruct_ov13_02227244 * param0)
{
    sub_0200E084(&param0->unk_1C, 0);
    return 3;
}

static u8 ov13_02226C7C (UnkStruct_ov13_02227244 * param0)
{
    if (sub_0201D724(param0->unk_32) == 0) {
        return 10;
    }

    return 9;
}

static u8 ov13_02226C94 (UnkStruct_ov13_02227244 * param0)
{
    if ((Unk_021BF67C.unk_48 & (PAD_BUTTON_A | PAD_BUTTON_B)) || (sub_02022798() == 1)) {
        return param0->unk_114B;
    }

    return 10;
}

static u8 ov13_02226CBC (UnkStruct_ov13_02227244 * param0)
{
    if (param0->unk_113E == 2) {
        return param0->unk_114B;
    }

    return 11;
}

static u8 ov13_02226CD4 (UnkStruct_ov13_02227244 * param0)
{
    sub_02003178(param0->unk_08, (0x2 | 0x8), 0xffff, -8, 0, 16, 0);
    return 14;
}

static u8 ov13_02226CFC (UnkStruct_0201CD38 * param0, UnkStruct_ov13_02227244 * param1)
{
    if (sub_0200384C(param1->unk_08) != 0) {
        return 0;
    }

    ov13_02227E08(param1);
    ov13_02227334(param1);
    ov13_022270F8(param1);
    ov13_02226F9C(param1->unk_04);

    param1->unk_00->unk_25 = ov13_02228A5C(param1->unk_34);

    ov13_02228A50(param1->unk_34);
    sub_02002C60(2);

    if (param1->unk_00->unk_1C != 0) {
        UnkStruct_0207D99C * v0;
        u8 v1;

        v0 = ov16_0223E1B0(param1->unk_00->unk_00);

        for (v1 = 0; v1 < 5; v1++) {
            sub_0207D9F0(v0, v1, param1->unk_00->unk_27[v1], param1->unk_00->unk_2C[v1]);
        }

        sub_0207DA24(v0, param1->unk_114D);
    }

    param1->unk_00->unk_26 = 1;
    sub_020067D0(param0);

    return 1;
}

static u8 ov13_02226D94 (UnkStruct_ov13_02227244 * param0)
{
    if (sub_0200384C(param0->unk_08) != 0) {
        return 12;
    }

    switch (param0->unk_1159) {
    case 0:

        if (ov16_0226DFD4(param0->unk_38) == 1) {
            sub_02005748(1501);
            param0->unk_114D = 2;
            param0->unk_114B = 12;
            ov13_0222880C(param0, 2, 0);
            param0->unk_115A = 0;
            param0->unk_1159++;
            return 11;
        } else {
            param0->unk_115A++;
        }
        break;
    case 1:
        ov13_02226C54(param0);
        param0->unk_1159++;
        break;
    case 2:
        if (ov16_0226DFD4(param0->unk_38) == 1) {
            sub_02005748(1501);
            param0->unk_00->unk_27[param0->unk_114D] = 0;
            param0->unk_114B = 12;
            ov13_0222880C(param0, 6, 0);
            param0->unk_115A = 0;
            param0->unk_1159++;
            return 11;
        } else {
            param0->unk_115A++;
        }
        break;
    case 3:
        ov13_02226C60(param0);
        param0->unk_1159++;
        break;
    case 4:
        if (ov16_0226DFD4(param0->unk_38) == 1) {
            sub_02005748(1501);
            param0->unk_00->unk_1C = ov13_02227BA8(param0, param0->unk_00->unk_27[param0->unk_114D]);
            param0->unk_00->unk_1E = param0->unk_114D;
            ov13_0222880C(param0, 15, 0);
            return ov13_02226A5C(param0);
        } else {
            param0->unk_115A++;
        }
        break;
    }

    return 12;
}

static void ov13_02226ED0 (UnkStruct_ov13_02227244 * param0)
{
    {
        UnkStruct_ov84_0223BA5C v0 = {
            GX_DISPMODE_GRAPHICS,
            GX_BGMODE_0,
            GX_BGMODE_0,
            GX_BG0_AS_3D,
        };

        sub_020183A0(&v0, 1);
    }

    {
        UnkStruct_ov97_0222DB78 v1 = {
            0,
            0,
            0x2000,
            0,
            4,
            GX_BG_COLORMODE_16,
            GX_BG_SCRBASE_0xd000,
            GX_BG_CHARBASE_0x00000,
            GX_BG_EXTPLTT_23,
            3,
            0,
            0,
            0
        };

        sub_020183C4(param0->unk_04, 6, &v1, 0);
    }

    {
        UnkStruct_ov97_0222DB78 v2 = {
            0,
            0,
            0x800,
            0,
            1,
            GX_BG_COLORMODE_16,
            GX_BG_SCRBASE_0xf800,
            GX_BG_CHARBASE_0x10000,
            GX_BG_EXTPLTT_01,
            1,
            0,
            0,
            0
        };

        sub_020183C4(param0->unk_04, 5, &v2, 0);
        sub_02019EBC(param0->unk_04, 5);
    }

    {
        UnkStruct_ov97_0222DB78 v3 = {
            0,
            0,
            0x800,
            0,
            1,
            GX_BG_COLORMODE_16,
            GX_BG_SCRBASE_0xf000,
            GX_BG_CHARBASE_0x00000,
            GX_BG_EXTPLTT_01,
            0,
            0,
            0,
            0
        };

        sub_020183C4(param0->unk_04, 4, &v3, 0);
        sub_02019EBC(param0->unk_04, 4);
    }

    sub_02019690(5, 32, 0, param0->unk_00->unk_0C);
    sub_02019690(4, 32, 0, param0->unk_00->unk_0C);
    sub_0201C3C0(param0->unk_04, 5);
    sub_0201C3C0(param0->unk_04, 4);
}

static void ov13_02226F9C (UnkStruct_02018340 * param0)
{
    GXLayers_EngineBToggleLayers(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ, 0);
    sub_02019044(param0, 4);
    sub_02019044(param0, 5);
    sub_02019044(param0, 6);
}

static void ov13_02226FC4 (UnkStruct_ov13_02227244 * param0)
{
    NARC * v0;

    v0 = NARC_ctor(77, param0->unk_00->unk_0C);

    sub_020070E8(v0, 2, param0->unk_04, 6, 0, 0, 0, param0->unk_00->unk_0C);
    sub_0200710C(v0, 0, param0->unk_04, 6, 0, 0, 0, param0->unk_00->unk_0C);

    {
        NNSG2dScreenData * v1;
        void * v2;
        u16 * v3;

        v2 = NARC_AllocAndReadWholeMember(v0, 1, param0->unk_00->unk_0C);
        NNS_G2dGetUnpackedScreenData(v2, &v1);
        v3 = (u16 *)v1->rawData;
        ov13_02228128(param0, v3);
        Heap_FreeToHeap(v2);
    }

    NARC_dtor(v0);
    sub_02003050(param0->unk_08, 77, 3, param0->unk_00->unk_0C, 1, 0x20 * 12, 0);
    sub_02003050(param0->unk_08, 14, 7, param0->unk_00->unk_0C, 1, 0x20, 15 * 16);

    {
        int v4 = ov16_0223EDE0(param0->unk_00->unk_00);

        sub_02006E3C(38, sub_0200DD04(v4), param0->unk_04, 4, 1024 - (18 + 12), 0, 0, param0->unk_00->unk_0C);
        sub_02003050(param0->unk_08, 38, sub_0200DD08(v4), param0->unk_00->unk_0C, 1, 0x20, 14 * 16);
    }
}

static void ov13_022270B8 (UnkStruct_ov13_02227244 * param0)
{
    param0->unk_10 = sub_0200B144(0, 26, 2, param0->unk_00->unk_0C);
    param0->unk_0C = sub_0200C440(15, 14, 0, param0->unk_00->unk_0C);
    param0->unk_14 = sub_0200B358(param0->unk_00->unk_0C);
    param0->unk_18 = Strbuf_Init(512, param0->unk_00->unk_0C);
}

static void ov13_022270F8 (UnkStruct_ov13_02227244 * param0)
{
    sub_0200B190(param0->unk_10);
    sub_0200C560(param0->unk_0C);
    sub_0200B3F0(param0->unk_14);
    Strbuf_Free(param0->unk_18);
}

static void ov13_02227118 (UnkStruct_ov13_02227244 * param0, u8 param1)
{
    switch (param1) {
    case 0:
        sub_0201C63C(param0->unk_04, 6, 0, 0);
        sub_0201C63C(param0->unk_04, 6, 3, 0);
        break;
    case 1:
        sub_0201C63C(param0->unk_04, 6, 0, 256);
        sub_0201C63C(param0->unk_04, 6, 3, 0);
        break;
    case 2:
        sub_0201C63C(param0->unk_04, 6, 0, 0);
        sub_0201C63C(param0->unk_04, 6, 3, 256);
        break;
    }
}

static void ov13_0222717C (UnkStruct_ov13_02227244 * param0, u8 param1)
{
    if (param1 != 2) {
        return;
    }

    sub_02019E2C(param0->unk_04, 6, 2, 35, 28, 4, 8 + param0->unk_114D);
    sub_02019E2C(param0->unk_04, 6, 2, 40, 28, 8, 8 + param0->unk_114D);
}

static void ov13_022271D0 (UnkStruct_ov13_02227244 * param0, u8 param1)
{
    ov13_0222717C(param0, param1);
    ov13_02227118(param0, param1);

    sub_02019F04(param0->unk_04, 4, 0);
    sub_02019F04(param0->unk_04, 5, 0);

    ov13_02227324(param0);
    ov13_022272AC(param0, param1);
    ov13_02227350(param0, param1);
    ov13_02228924(param0, param1);
    ov13_02228008(param0, param1);
    ov13_022280F0(param0, param1);

    param0->unk_114C = param1;

    ov13_02227E68(param0, param0->unk_114C);
}

static int ov13_02227238 (UnkStruct_ov13_02227244 * param0, const UnkUnion_02022594 * param1)
{
    int v0 = sub_02022664(param1);
    return v0;
}

int ov13_02227244 (UnkStruct_ov13_02227244 * param0)
{
    int v0;

    v0 = ov16_0225B45C(param0->unk_00->unk_00, ov16_0223DF10(param0->unk_00->unk_00), 2, param0->unk_00->unk_10);
    return v0;
}

static void ov13_02227260 (UnkStruct_0207ADB4 * param0, u16 param1, u16 param2, u32 param3)
{
    sub_0207D60C(ov16_0223E1AC(param0), param1, 1, param3);
    sub_0207DA1C(ov16_0223E1B0(param0), param1, param2);
}
