#include <benchmark/benchmark.h>
#include "fhe_context.h"
using namespace fhe_deck;


std::vector<long>
test_image_sharpen_lut4fa(FHEContext& ctx, uint64_t window = 0)
{
    Ciphertext ct_window8 = ctx.encrypt_public((window >> 0) & 1);
    Ciphertext ct_window9 = ctx.encrypt_public((window >> 1) & 1);
    Ciphertext ct_window10 = ctx.encrypt_public((window >> 2) & 1);
    Ciphertext ct_window11 = ctx.encrypt_public((window >> 3) & 1);
    Ciphertext ct_window12 = ctx.encrypt_public((window >> 4) & 1);
    Ciphertext ct_window13 = ctx.encrypt_public((window >> 5) & 1);
    Ciphertext ct_window14 = ctx.encrypt_public((window >> 6) & 1);
    Ciphertext ct_window15 = ctx.encrypt_public((window >> 7) & 1);
    Ciphertext ct_window24 = ctx.encrypt_public((window >> 8) & 1);
    Ciphertext ct_window25 = ctx.encrypt_public((window >> 9) & 1);
    Ciphertext ct_window26 = ctx.encrypt_public((window >> 10) & 1);
    Ciphertext ct_window27 = ctx.encrypt_public((window >> 11) & 1);
    Ciphertext ct_window28 = ctx.encrypt_public((window >> 12) & 1);
    Ciphertext ct_window29 = ctx.encrypt_public((window >> 13) & 1);
    Ciphertext ct_window30 = ctx.encrypt_public((window >> 14) & 1);
    Ciphertext ct_window31 = ctx.encrypt_public((window >> 15) & 1);
    Ciphertext ct_window32 = ctx.encrypt_public((window >> 16) & 1);
    Ciphertext ct_window33 = ctx.encrypt_public((window >> 17) & 1);
    Ciphertext ct_window34 = ctx.encrypt_public((window >> 18) & 1);
    Ciphertext ct_window35 = ctx.encrypt_public((window >> 19) & 1);
    Ciphertext ct_window36 = ctx.encrypt_public((window >> 20) & 1);
    Ciphertext ct_window37 = ctx.encrypt_public((window >> 21) & 1);
    Ciphertext ct_window38 = ctx.encrypt_public((window >> 22) & 1);
    Ciphertext ct_window39 = ctx.encrypt_public((window >> 23) & 1);
    Ciphertext ct_window40 = ctx.encrypt_public((window >> 24) & 1);
    Ciphertext ct_window41 = ctx.encrypt_public((window >> 25) & 1);
    Ciphertext ct_window42 = ctx.encrypt_public((window >> 26) & 1);
    Ciphertext ct_window43 = ctx.encrypt_public((window >> 27) & 1);
    Ciphertext ct_window44 = ctx.encrypt_public((window >> 28) & 1);
    Ciphertext ct_window45 = ctx.encrypt_public((window >> 29) & 1);
    Ciphertext ct_window46 = ctx.encrypt_public((window >> 30) & 1);
    Ciphertext ct_window47 = ctx.encrypt_public((window >> 31) & 1);
    Ciphertext ct_window56 = ctx.encrypt_public((window >> 32) & 1);
    Ciphertext ct_window57 = ctx.encrypt_public((window >> 33) & 1);
    Ciphertext ct_window58 = ctx.encrypt_public((window >> 34) & 1);
    Ciphertext ct_window59 = ctx.encrypt_public((window >> 35) & 1);
    Ciphertext ct_window60 = ctx.encrypt_public((window >> 36) & 1);
    Ciphertext ct_window61 = ctx.encrypt_public((window >> 37) & 1);
    Ciphertext ct_window62 = ctx.encrypt_public((window >> 38) & 1);
    Ciphertext ct_window63 = ctx.encrypt_public((window >> 39) & 1);

    std::vector<RotationPoly> decomp;
    std::vector<long (*)(long)> fdecomp;
    auto decomp0 = [](long I) -> long {
        switch (I) {
            case  0: return 0;
            case  1: return 1;
            case  2: return 0;
            case  3: return 1;
            case  4: return 0;
            case  5: return 1;
            case  6: return 0;
            case  7: return 1;
            case  8: return 0;
            case  9: return 1;
            case 10: return 0;
            case 11: return 1;
            case 12: return 0;
            case 13: return 1;
            case 14: return 0;
            case 15: return 1;
            default: assert(0);
        };
    };
    decomp.push_back(ctx.genrate_lut(decomp0));
    fdecomp.push_back(decomp0);
    auto decomp1 = [](long I) -> long {
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 1;
            case  3: return 1;
            case  4: return 0;
            case  5: return 0;
            case  6: return 1;
            case  7: return 1;
            case  8: return 0;
            case  9: return 0;
            case 10: return 1;
            case 11: return 1;
            case 12: return 0;
            case 13: return 0;
            case 14: return 1;
            case 15: return 1;
            default: assert(0);
        };
    };
    decomp.push_back(ctx.genrate_lut(decomp1));
    fdecomp.push_back(decomp1);
    auto decomp2 = [](long I) -> long {
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 0;
            case  3: return 0;
            case  4: return 1;
            case  5: return 1;
            case  6: return 1;
            case  7: return 1;
            case  8: return 0;
            case  9: return 0;
            case 10: return 0;
            case 11: return 0;
            case 12: return 1;
            case 13: return 1;
            case 14: return 1;
            case 15: return 1;
            default: assert(0);
        };
    };
    decomp.push_back(ctx.genrate_lut(decomp2));
    fdecomp.push_back(decomp2);
    auto decomp3 = [](long I) -> long {
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 0;
            case  3: return 0;
            case  4: return 0;
            case  5: return 0;
            case  6: return 0;
            case  7: return 0;
            case  8: return 1;
            case  9: return 1;
            case 10: return 1;
            case 11: return 1;
            case 12: return 1;
            case 13: return 1;
            case 14: return 1;
            case 15: return 1;
            default: assert(0);
        };
    };
    decomp.push_back(ctx.genrate_lut(decomp3));
    fdecomp.push_back(decomp3);
    auto vdecomp = [fdecomp](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 4; ++i)
            ret.push_back(fdecomp[i](I));
        return ret;
    };

    std::vector<RotationPoly> lut0;
    std::vector<long (*)(long)> flut0;
    auto lut0idx0 = [](long I) -> long {
        /* GATE 10 (LUT4 _061_ INIT 0x1777 PERM 2301) */
        switch (I) {
            case  0: return 1;
            case  1: return 1;
            case  2: return 1;
            case  3: return 1;
            case  4: return 1;
            case  5: return 1;
            case  6: return 1;
            case  7: return 0;
            case  8: return 1;
            case  9: return 1;
            case 10: return 1;
            case 11: return 0;
            case 12: return 0;
            case 13: return 0;
            case 14: return 0;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut0.push_back(ctx.genrate_lut(lut0idx0));
    flut0.push_back(lut0idx0);
    auto lut0idx1 = [](long I) -> long {
        /* GATE 8 (LUT4 _059_ INIT 0x8778 PERM 0123) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 0;
            case  3: return 1;
            case  4: return 1;
            case  5: return 1;
            case  6: return 1;
            case  7: return 0;
            case  8: return 1;
            case  9: return 1;
            case 10: return 1;
            case 11: return 0;
            case 12: return 0;
            case 13: return 0;
            case 14: return 0;
            case 15: return 1;
            default: assert(0);
        };
    };
    lut0.push_back(ctx.genrate_lut(lut0idx1));
    flut0.push_back(lut0idx1);
    auto lut0idx2 = [](long I) -> long {
        /* GATE 19 (LUT2 _070_ INIT 0x6 PERM 01) */
        switch (I) {
            case  0: return 0;
            case  1: return 1;
            case  2: return 1;
            case  3: return 0;
            case  4: return 0;
            case  5: return 1;
            case  6: return 1;
            case  7: return 0;
            case  8: return 0;
            case  9: return 1;
            case 10: return 1;
            case 11: return 0;
            case 12: return 0;
            case 13: return 1;
            case 14: return 1;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut0.push_back(ctx.genrate_lut(lut0idx2));
    flut0.push_back(lut0idx2);
    auto fvec0 = [flut0](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 3; ++i)
            ret.push_back(flut0[i](I));
        return ret;
    };

    std::cerr << "\rLUT0   ";
    Ciphertext gin0 = 1 * ct_window34 + 2 * ct_window32 + 4 * ct_window35 + 8 * ct_window33;
    std::vector<Ciphertext> gout0 = ctx.eval_lut_amortized(&gin0, lut0);

    std::cerr << "\rFA1    ";
    Ciphertext gin1 = 0 + 1 * ct_window8 + 2 * ct_window9 + 4 * ct_window10 + 1 * ct_window24 + 2 * ct_window25 + 4 * ct_window26;
    std::vector<Ciphertext> gout1 = ctx.eval_lut_amortized(&gin1, decomp);

    std::vector<RotationPoly> lut2;
    std::vector<long (*)(long)> flut2;
    auto lut2idx0 = [](long I) -> long {
        /* GATE 12 (LUT2 _063_ INIT 0x6 PERM 10) */
        switch (I) {
            case  0: return 0;
            case  1: return 1;
            case  2: return 1;
            case  3: return 0;
            case  4: return 0;
            case  5: return 1;
            case  6: return 1;
            case  7: return 0;
            case  8: return 0;
            case  9: return 1;
            case 10: return 1;
            case 11: return 0;
            case 12: return 0;
            case 13: return 1;
            case 14: return 1;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut2.push_back(ctx.genrate_lut(lut2idx0));
    flut2.push_back(lut2idx0);
    auto lut2idx1 = [](long I) -> long {
        /* GATE 15 (LUT2 _066_ INIT 0x8 PERM 10) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 0;
            case  3: return 1;
            case  4: return 0;
            case  5: return 0;
            case  6: return 0;
            case  7: return 1;
            case  8: return 0;
            case  9: return 0;
            case 10: return 0;
            case 11: return 1;
            case 12: return 0;
            case 13: return 0;
            case 14: return 0;
            case 15: return 1;
            default: assert(0);
        };
    };
    lut2.push_back(ctx.genrate_lut(lut2idx1));
    flut2.push_back(lut2idx1);
    auto fvec2 = [flut2](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 2; ++i)
            ret.push_back(flut2[i](I));
        return ret;
    };

    std::cerr << "\rLUT2   ";
    Ciphertext gin2 = 1 * ct_window37 + 2 * ct_window35;
    std::vector<Ciphertext> gout2 = ctx.eval_lut_amortized(&gin2, lut2);

    std::vector<RotationPoly> lut3;
    std::vector<long (*)(long)> flut3;
    auto lut3idx0 = [](long I) -> long {
        /* GATE 14 (LUT4 _065_ INIT 0x2bff PERM 1320) */
        switch (I) {
            case  0: return 1;
            case  1: return 1;
            case  2: return 1;
            case  3: return 1;
            case  4: return 1;
            case  5: return 0;
            case  6: return 1;
            case  7: return 1;
            case  8: return 1;
            case  9: return 0;
            case 10: return 1;
            case 11: return 1;
            case 12: return 1;
            case 13: return 0;
            case 14: return 1;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut3.push_back(ctx.genrate_lut(lut3idx0));
    flut3.push_back(lut3idx0);
    auto lut3idx1 = [](long I) -> long {
        /* GATE 11 (LUT4 _062_ INIT 0x2bd4 PERM 1320) */
        switch (I) {
            case  0: return 0;
            case  1: return 1;
            case  2: return 0;
            case  3: return 1;
            case  4: return 1;
            case  5: return 0;
            case  6: return 0;
            case  7: return 1;
            case  8: return 1;
            case  9: return 0;
            case 10: return 0;
            case 11: return 1;
            case 12: return 1;
            case 13: return 0;
            case 14: return 1;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut3.push_back(ctx.genrate_lut(lut3idx1));
    flut3.push_back(lut3idx1);
    auto fvec3 = [flut3](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 2; ++i)
            ret.push_back(flut3[i](I));
        return ret;
    };

    std::cerr << "\rLUT3   ";
    Ciphertext gin3 = 1 * gout2[0] + 2 * gout0[0] + 4 * ct_window36 + 8 * ct_window34;
    std::vector<Ciphertext> gout3 = ctx.eval_lut_amortized(&gin3, lut3);

    std::cerr << "\rFA4    ";
    Ciphertext gin4 = 0 + 1 * ct_window40 + 2 * ct_window41 + 4 * ct_window42 + 1 * ct_window56 + 2 * ct_window57 + 4 * ct_window58;
    std::vector<Ciphertext> gout4 = ctx.eval_lut_amortized(&gin4, decomp);

    std::vector<RotationPoly> lut5;
    std::vector<long (*)(long)> flut5;
    auto lut5idx0 = [](long I) -> long {
        /* GATE 18 (LUT4 _069_ INIT 0x7887 PERM 3120) */
        switch (I) {
            case  0: return 1;
            case  1: return 0;
            case  2: return 1;
            case  3: return 0;
            case  4: return 0;
            case  5: return 1;
            case  6: return 0;
            case  7: return 1;
            case  8: return 1;
            case  9: return 0;
            case 10: return 0;
            case 11: return 1;
            case 12: return 0;
            case 13: return 1;
            case 14: return 1;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut5.push_back(ctx.genrate_lut(lut5idx0));
    flut5.push_back(lut5idx0);
    auto lut5idx1 = [](long I) -> long {
        /* GATE 16 (LUT2 _067_ INIT 0x6 PERM 31) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 1;
            case  3: return 1;
            case  4: return 0;
            case  5: return 0;
            case  6: return 1;
            case  7: return 1;
            case  8: return 1;
            case  9: return 1;
            case 10: return 0;
            case 11: return 0;
            case 12: return 1;
            case 13: return 1;
            case 14: return 0;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut5.push_back(ctx.genrate_lut(lut5idx1));
    flut5.push_back(lut5idx1);
    auto fvec5 = [flut5](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 2; ++i)
            ret.push_back(flut5[i](I));
        return ret;
    };

    std::cerr << "\rLUT5   ";
    Ciphertext gin5 = 1 * ct_window39 + 2 * ct_window38 + 4 * ct_window37 + 8 * ct_window36;
    std::vector<Ciphertext> gout5 = ctx.eval_lut_amortized(&gin5, lut5);

    std::cerr << "\rFA6    ";
    Ciphertext gin6 = gout1[3] + 1 * ct_window11 + 2 * ct_window12 + 4 * ct_window13 + 1 * ct_window27 + 2 * ct_window28 + 4 * ct_window29;
    std::vector<Ciphertext> gout6 = ctx.eval_lut_amortized(&gin6, decomp);

    std::cerr << "\rFA7    ";
    Ciphertext gin7 = gout4[3] + 1 * ct_window43 + 2 * ct_window44 + 4 * ct_window45 + 1 * ct_window59 + 2 * ct_window60 + 4 * ct_window61;
    std::vector<Ciphertext> gout7 = ctx.eval_lut_amortized(&gin7, decomp);

    std::vector<RotationPoly> lut8;
    std::vector<long (*)(long)> flut8;
    auto lut8idx0 = [](long I) -> long {
        /* GATE 9 (LUT3 _060_ INIT 0x69 PERM 021) */
        switch (I) {
            case  0: return 1;
            case  1: return 0;
            case  2: return 0;
            case  3: return 1;
            case  4: return 0;
            case  5: return 1;
            case  6: return 1;
            case  7: return 0;
            case  8: return 1;
            case  9: return 0;
            case 10: return 0;
            case 11: return 1;
            case 12: return 0;
            case 13: return 1;
            case 14: return 1;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut8.push_back(ctx.genrate_lut(lut8idx0));
    flut8.push_back(lut8idx0);
    auto fvec8 = [flut8](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut8[i](I));
        return ret;
    };

    std::cerr << "\rLUT8   ";
    Ciphertext gin8 = 1 * gout0[0] + 2 * ct_window36 + 4 * ct_window34;
    std::vector<Ciphertext> gout8 = ctx.eval_lut_amortized(&gin8, lut8);

    std::cerr << "\rFA9    ";
    Ciphertext gin9 = 0 + 1 * gout4[0] + 2 * gout4[1] + 4 * gout4[2] + 1 * gout1[0] + 2 * gout1[1] + 4 * gout1[2];
    std::vector<Ciphertext> gout9 = ctx.eval_lut_amortized(&gin9, decomp);

    std::cerr << "\rFA10    ";
    Ciphertext gin10 = gout7[3] + 1 * ct_window46 + 2 * ct_window47 + 1 * ct_window62 + 2 * ct_window63;
    std::vector<Ciphertext> gout10 = ctx.eval_lut_amortized(&gin10, decomp);

    std::cerr << "\rFA11    ";
    Ciphertext gin11 = gout9[3] + 1 * gout7[0] + 2 * gout7[1] + 4 * gout7[2] + 1 * gout6[0] + 2 * gout6[1] + 4 * gout6[2];
    std::vector<Ciphertext> gout11 = ctx.eval_lut_amortized(&gin11, decomp);

    std::vector<RotationPoly> lut12;
    std::vector<long (*)(long)> flut12;
    auto lut12idx0 = [](long I) -> long {
        /* GATE 17 (LUT4 _068_ INIT 0xd42b PERM 1230) */
        switch (I) {
            case  0: return 1;
            case  1: return 0;
            case  2: return 1;
            case  3: return 0;
            case  4: return 0;
            case  5: return 1;
            case  6: return 1;
            case  7: return 0;
            case  8: return 0;
            case  9: return 1;
            case 10: return 1;
            case 11: return 0;
            case 12: return 0;
            case 13: return 1;
            case 14: return 0;
            case 15: return 1;
            default: assert(0);
        };
    };
    lut12.push_back(ctx.genrate_lut(lut12idx0));
    flut12.push_back(lut12idx0);
    auto lut12idx1 = [](long I) -> long {
        /* GATE 13 (LUT3 _064_ INIT 0x69 PERM 123) */
        switch (I) {
            case  0: return 1;
            case  1: return 1;
            case  2: return 0;
            case  3: return 0;
            case  4: return 0;
            case  5: return 0;
            case  6: return 1;
            case  7: return 1;
            case  8: return 0;
            case  9: return 0;
            case 10: return 1;
            case 11: return 1;
            case 12: return 1;
            case 13: return 1;
            case 14: return 0;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut12.push_back(ctx.genrate_lut(lut12idx1));
    flut12.push_back(lut12idx1);
    auto fvec12 = [flut12](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 2; ++i)
            ret.push_back(flut12[i](I));
        return ret;
    };

    std::cerr << "\rLUT12   ";
    Ciphertext gin12 = 1 * gout5[0] + 2 * gout3[0] + 4 * gout2[1] + 8 * gout5[1];
    std::vector<Ciphertext> gout12 = ctx.eval_lut_amortized(&gin12, lut12);

    std::cerr << "\rINV13   ";
    std::vector<Ciphertext> gout13;
    gout13.push_back(1 - gout9[1]);

    std::cerr << "\rINV14   ";
    std::vector<Ciphertext> gout14;
    gout14.push_back(1 - gout9[2]);

    std::cerr << "\rINV15   ";
    std::vector<Ciphertext> gout15;
    gout15.push_back(1 - gout9[0]);

    std::cerr << "\rINV16   ";
    std::vector<Ciphertext> gout16;
    gout16.push_back(1 - gout11[2]);

    std::cerr << "\rFA17    ";
    Ciphertext gin17 = gout6[3] + 1 * ct_window14 + 2 * ct_window15 + 1 * ct_window30 + 2 * ct_window31;
    std::vector<Ciphertext> gout17 = ctx.eval_lut_amortized(&gin17, decomp);

    std::cerr << "\rFA18    ";
    Ciphertext gin18 = 1 + 1 * ct_window32 + 2 * ct_window33 + 4 * gout0[2] + 1 * gout15[0] + 2 * gout13[0] + 4 * gout14[0];
    std::vector<Ciphertext> gout18 = ctx.eval_lut_amortized(&gin18, decomp);

    std::cerr << "\rFA19    ";
    Ciphertext gin19 = gout11[3] + 1 * gout10[0] + 2 * gout10[1] + 1 * gout17[0] + 2 * gout17[1];
    std::vector<Ciphertext> gout19 = ctx.eval_lut_amortized(&gin19, decomp);

    std::cerr << "\rINV20   ";
    std::vector<Ciphertext> gout20;
    gout20.push_back(1 - gout11[0]);

    std::cerr << "\rINV21   ";
    std::vector<Ciphertext> gout21;
    gout21.push_back(1 - gout11[1]);

    std::cerr << "\rINV22   ";
    std::vector<Ciphertext> gout22;
    gout22.push_back(1 - gout19[1]);

    std::cerr << "\rINV23   ";
    std::vector<Ciphertext> gout23;
    gout23.push_back(1 - gout19[0]);

    std::cerr << "\rFA24    ";
    Ciphertext gin24 = gout18[3] + 1 * gout0[1] + 2 * gout8[0] + 4 * gout3[1] + 1 * gout20[0] + 2 * gout21[0] + 4 * gout16[0];
    std::vector<Ciphertext> gout24 = ctx.eval_lut_amortized(&gin24, decomp);

    std::vector<RotationPoly> lut25;
    std::vector<long (*)(long)> flut25;
    auto lut25idx0 = [](long I) -> long {
        /* GATE 3 (LUT4 _054_ INIT 0x7 PERM 3201) */
        switch (I) {
            case  0: return 1;
            case  1: return 0;
            case  2: return 0;
            case  3: return 0;
            case  4: return 1;
            case  5: return 0;
            case  6: return 0;
            case  7: return 0;
            case  8: return 1;
            case  9: return 0;
            case 10: return 0;
            case 11: return 0;
            case 12: return 0;
            case 13: return 0;
            case 14: return 0;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut25.push_back(ctx.genrate_lut(lut25idx0));
    flut25.push_back(lut25idx0);
    auto fvec25 = [flut25](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut25[i](I));
        return ret;
    };

    std::cerr << "\rLUT25   ";
    Ciphertext gin25 = 1 * gout24[1] + 2 * gout24[2] + 4 * gout18[2] + 8 * gout24[0];
    std::vector<Ciphertext> gout25 = ctx.eval_lut_amortized(&gin25, lut25);

    std::cerr << "\rFA26    ";
    Ciphertext gin26 = gout24[3] + 1 * gout12[1] + 2 * gout12[0] + 1 * gout23[0] + 2 * gout22[0];
    std::vector<Ciphertext> gout26 = ctx.eval_lut_amortized(&gin26, decomp);

    std::vector<RotationPoly> lut27;
    std::vector<long (*)(long)> flut27;
    auto lut27idx0 = [](long I) -> long {
        /* GATE 4 (LUT4 _055_ INIT 0x1 PERM 0123) */
        switch (I) {
            case  0: return 1;
            case  1: return 0;
            case  2: return 0;
            case  3: return 0;
            case  4: return 0;
            case  5: return 0;
            case  6: return 0;
            case  7: return 0;
            case  8: return 0;
            case  9: return 0;
            case 10: return 0;
            case 11: return 0;
            case 12: return 0;
            case 13: return 0;
            case 14: return 0;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut27.push_back(ctx.genrate_lut(lut27idx0));
    flut27.push_back(lut27idx0);
    auto fvec27 = [flut27](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut27[i](I));
        return ret;
    };

    std::cerr << "\rLUT27   ";
    Ciphertext gin27 = 1 * gout24[1] + 2 * gout24[2] + 4 * gout26[0] + 8 * gout26[1];
    std::vector<Ciphertext> gout27 = ctx.eval_lut_amortized(&gin27, lut27);

    std::vector<RotationPoly> lut28;
    std::vector<long (*)(long)> flut28;
    auto lut28idx0 = [](long I) -> long {
        /* GATE 2 (LUT4 _053_ INIT 0xd PERM 0132) */
        switch (I) {
            case  0: return 1;
            case  1: return 0;
            case  2: return 1;
            case  3: return 1;
            case  4: return 0;
            case  5: return 0;
            case  6: return 0;
            case  7: return 0;
            case  8: return 0;
            case  9: return 0;
            case 10: return 0;
            case 11: return 0;
            case 12: return 0;
            case 13: return 0;
            case 14: return 0;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut28.push_back(ctx.genrate_lut(lut28idx0));
    flut28.push_back(lut28idx0);
    auto fvec28 = [flut28](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut28[i](I));
        return ret;
    };

    std::cerr << "\rLUT28   ";
    Ciphertext gin28 = 1 * gout26[0] + 2 * gout25[0] + 4 * gout26[1] + 8 * gout27[0];
    std::vector<Ciphertext> gout28 = ctx.eval_lut_amortized(&gin28, lut28);

    std::vector<RotationPoly> lut29;
    std::vector<long (*)(long)> flut29;
    auto lut29idx0 = [](long I) -> long {
        /* GATE 6 (LUT3 _057_ INIT 0xf8 PERM 102) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 0;
            case  3: return 1;
            case  4: return 1;
            case  5: return 1;
            case  6: return 1;
            case  7: return 1;
            case  8: return 0;
            case  9: return 0;
            case 10: return 0;
            case 11: return 1;
            case 12: return 1;
            case 13: return 1;
            case 14: return 1;
            case 15: return 1;
            default: assert(0);
        };
    };
    lut29.push_back(ctx.genrate_lut(lut29idx0));
    flut29.push_back(lut29idx0);
    auto fvec29 = [flut29](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut29[i](I));
        return ret;
    };

    std::cerr << "\rLUT29   ";
    Ciphertext gin29 = 1 * gout18[2] + 2 * gout27[0] + 4 * gout28[0];
    std::vector<Ciphertext> gout29 = ctx.eval_lut_amortized(&gin29, lut29);

    std::vector<RotationPoly> lut30;
    std::vector<long (*)(long)> flut30;
    auto lut30idx0 = [](long I) -> long {
        /* GATE 1 (LUT3 _052_ INIT 0xf8 PERM 102) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 0;
            case  3: return 1;
            case  4: return 1;
            case  5: return 1;
            case  6: return 1;
            case  7: return 1;
            case  8: return 0;
            case  9: return 0;
            case 10: return 0;
            case 11: return 1;
            case 12: return 1;
            case 13: return 1;
            case 14: return 1;
            case 15: return 1;
            default: assert(0);
        };
    };
    lut30.push_back(ctx.genrate_lut(lut30idx0));
    flut30.push_back(lut30idx0);
    auto fvec30 = [flut30](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut30[i](I));
        return ret;
    };

    std::cerr << "\rLUT30   ";
    Ciphertext gin30 = 1 * gout18[0] + 2 * gout27[0] + 4 * gout28[0];
    std::vector<Ciphertext> gout30 = ctx.eval_lut_amortized(&gin30, lut30);

    std::vector<RotationPoly> lut31;
    std::vector<long (*)(long)> flut31;
    auto lut31idx0 = [](long I) -> long {
        /* GATE 5 (LUT3 _056_ INIT 0xf8 PERM 102) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 0;
            case  3: return 1;
            case  4: return 1;
            case  5: return 1;
            case  6: return 1;
            case  7: return 1;
            case  8: return 0;
            case  9: return 0;
            case 10: return 0;
            case 11: return 1;
            case 12: return 1;
            case 13: return 1;
            case 14: return 1;
            case 15: return 1;
            default: assert(0);
        };
    };
    lut31.push_back(ctx.genrate_lut(lut31idx0));
    flut31.push_back(lut31idx0);
    auto fvec31 = [flut31](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut31[i](I));
        return ret;
    };

    std::cerr << "\rLUT31   ";
    Ciphertext gin31 = 1 * gout18[1] + 2 * gout27[0] + 4 * gout28[0];
    std::vector<Ciphertext> gout31 = ctx.eval_lut_amortized(&gin31, lut31);

    std::vector<RotationPoly> lut32;
    std::vector<long (*)(long)> flut32;
    auto lut32idx0 = [](long I) -> long {
        /* GATE 7 (LUT3 _058_ INIT 0xf8 PERM 012) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 0;
            case  3: return 1;
            case  4: return 1;
            case  5: return 1;
            case  6: return 1;
            case  7: return 1;
            case  8: return 0;
            case  9: return 0;
            case 10: return 0;
            case 11: return 1;
            case 12: return 1;
            case 13: return 1;
            case 14: return 1;
            case 15: return 1;
            default: assert(0);
        };
    };
    lut32.push_back(ctx.genrate_lut(lut32idx0));
    flut32.push_back(lut32idx0);
    auto fvec32 = [flut32](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut32[i](I));
        return ret;
    };

    std::cerr << "\rLUT32   ";
    Ciphertext gin32 = 1 * gout27[0] + 2 * gout24[0] + 4 * gout28[0];
    std::vector<Ciphertext> gout32 = ctx.eval_lut_amortized(&gin32, lut32);

    std::cerr << "\r          \r";
    std::vector<long> test_out;
    test_out.push_back(ctx.decrypt(&gout30[0])); /* out0 */
    test_out.push_back(ctx.decrypt(&gout31[0])); /* out1 */
    test_out.push_back(ctx.decrypt(&gout29[0])); /* out2 */
    test_out.push_back(ctx.decrypt(&gout32[0])); /* out3 */
    test_out.push_back(0); /* out7 */
    return test_out;
}

static void
BM_image_sharpen_lut4fa(benchmark::State& state)
{
    FHEContext ctx;
    ctx.generate_context(tfhe_12_NTT_amortized);
    ctx.set_default_message_encoding_type(partial_domain);
    ctx.set_default_plaintext_space(16);

    for (auto _ : state) {
        test_image_sharpen_lut4fa(ctx);
    }
}

BENCHMARK(BM_image_sharpen_lut4fa)->Unit(benchmark::kSecond);
BENCHMARK_MAIN();