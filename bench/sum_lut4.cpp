#include <benchmark/benchmark.h>
#include "fhe_context.h"
using namespace fhe_deck;


std::vector<long>
test_sum_lut4(FHEContext& ctx, uint32_t a = 0, uint32_t b = 0)
{
    Ciphertext ct_a0 = ctx.encrypt_public((a >> 0) & 1);
    Ciphertext ct_a1 = ctx.encrypt_public((a >> 1) & 1);
    Ciphertext ct_a2 = ctx.encrypt_public((a >> 2) & 1);
    Ciphertext ct_a3 = ctx.encrypt_public((a >> 3) & 1);
    Ciphertext ct_a4 = ctx.encrypt_public((a >> 4) & 1);
    Ciphertext ct_a5 = ctx.encrypt_public((a >> 5) & 1);
    Ciphertext ct_a6 = ctx.encrypt_public((a >> 6) & 1);
    Ciphertext ct_a7 = ctx.encrypt_public((a >> 7) & 1);
    Ciphertext ct_a8 = ctx.encrypt_public((a >> 8) & 1);
    Ciphertext ct_a9 = ctx.encrypt_public((a >> 9) & 1);
    Ciphertext ct_a10 = ctx.encrypt_public((a >> 10) & 1);
    Ciphertext ct_a11 = ctx.encrypt_public((a >> 11) & 1);
    Ciphertext ct_a12 = ctx.encrypt_public((a >> 12) & 1);
    Ciphertext ct_a13 = ctx.encrypt_public((a >> 13) & 1);
    Ciphertext ct_a14 = ctx.encrypt_public((a >> 14) & 1);
    Ciphertext ct_a15 = ctx.encrypt_public((a >> 15) & 1);
    Ciphertext ct_a16 = ctx.encrypt_public((a >> 16) & 1);
    Ciphertext ct_a17 = ctx.encrypt_public((a >> 17) & 1);
    Ciphertext ct_a18 = ctx.encrypt_public((a >> 18) & 1);
    Ciphertext ct_a19 = ctx.encrypt_public((a >> 19) & 1);
    Ciphertext ct_a20 = ctx.encrypt_public((a >> 20) & 1);
    Ciphertext ct_a21 = ctx.encrypt_public((a >> 21) & 1);
    Ciphertext ct_a22 = ctx.encrypt_public((a >> 22) & 1);
    Ciphertext ct_a23 = ctx.encrypt_public((a >> 23) & 1);
    Ciphertext ct_a24 = ctx.encrypt_public((a >> 24) & 1);
    Ciphertext ct_a25 = ctx.encrypt_public((a >> 25) & 1);
    Ciphertext ct_a26 = ctx.encrypt_public((a >> 26) & 1);
    Ciphertext ct_a27 = ctx.encrypt_public((a >> 27) & 1);
    Ciphertext ct_a28 = ctx.encrypt_public((a >> 28) & 1);
    Ciphertext ct_a29 = ctx.encrypt_public((a >> 29) & 1);
    Ciphertext ct_a30 = ctx.encrypt_public((a >> 30) & 1);
    Ciphertext ct_a31 = ctx.encrypt_public((a >> 31) & 1);
    Ciphertext ct_b0 = ctx.encrypt_public((b >> 0) & 1);
    Ciphertext ct_b1 = ctx.encrypt_public((b >> 1) & 1);
    Ciphertext ct_b2 = ctx.encrypt_public((b >> 2) & 1);
    Ciphertext ct_b3 = ctx.encrypt_public((b >> 3) & 1);
    Ciphertext ct_b4 = ctx.encrypt_public((b >> 4) & 1);
    Ciphertext ct_b5 = ctx.encrypt_public((b >> 5) & 1);
    Ciphertext ct_b6 = ctx.encrypt_public((b >> 6) & 1);
    Ciphertext ct_b7 = ctx.encrypt_public((b >> 7) & 1);
    Ciphertext ct_b8 = ctx.encrypt_public((b >> 8) & 1);
    Ciphertext ct_b9 = ctx.encrypt_public((b >> 9) & 1);
    Ciphertext ct_b10 = ctx.encrypt_public((b >> 10) & 1);
    Ciphertext ct_b11 = ctx.encrypt_public((b >> 11) & 1);
    Ciphertext ct_b12 = ctx.encrypt_public((b >> 12) & 1);
    Ciphertext ct_b13 = ctx.encrypt_public((b >> 13) & 1);
    Ciphertext ct_b14 = ctx.encrypt_public((b >> 14) & 1);
    Ciphertext ct_b15 = ctx.encrypt_public((b >> 15) & 1);
    Ciphertext ct_b16 = ctx.encrypt_public((b >> 16) & 1);
    Ciphertext ct_b17 = ctx.encrypt_public((b >> 17) & 1);
    Ciphertext ct_b18 = ctx.encrypt_public((b >> 18) & 1);
    Ciphertext ct_b19 = ctx.encrypt_public((b >> 19) & 1);
    Ciphertext ct_b20 = ctx.encrypt_public((b >> 20) & 1);
    Ciphertext ct_b21 = ctx.encrypt_public((b >> 21) & 1);
    Ciphertext ct_b22 = ctx.encrypt_public((b >> 22) & 1);
    Ciphertext ct_b23 = ctx.encrypt_public((b >> 23) & 1);
    Ciphertext ct_b24 = ctx.encrypt_public((b >> 24) & 1);
    Ciphertext ct_b25 = ctx.encrypt_public((b >> 25) & 1);
    Ciphertext ct_b26 = ctx.encrypt_public((b >> 26) & 1);
    Ciphertext ct_b27 = ctx.encrypt_public((b >> 27) & 1);
    Ciphertext ct_b28 = ctx.encrypt_public((b >> 28) & 1);
    Ciphertext ct_b29 = ctx.encrypt_public((b >> 29) & 1);
    Ciphertext ct_b30 = ctx.encrypt_public((b >> 30) & 1);
    Ciphertext ct_b31 = ctx.encrypt_public((b >> 31) & 1);

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
        /* GATE 62 (LUT2 _251_ INIT 0x9 PERM 01) */
        switch (I) {
            case  0: return 1;
            case  1: return 0;
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
            case 14: return 0;
            case 15: return 1;
            default: assert(0);
        };
    };
    lut0.push_back(ctx.genrate_lut(lut0idx0));
    flut0.push_back(lut0idx0);
    auto fvec0 = [flut0](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut0[i](I));
        return ret;
    };

    std::cerr << "\rLUT0   ";
    Ciphertext gin0 = 1 * ct_a31 + 2 * ct_b31;
    std::vector<Ciphertext> gout0 = ctx.eval_lut_amortized(&gin0, lut0);

    std::vector<RotationPoly> lut1;
    std::vector<long (*)(long)> flut1;
    auto lut1idx0 = [](long I) -> long {
        /* GATE 10 (LUT2 _199_ INIT 0x8 PERM 01) */
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
    lut1.push_back(ctx.genrate_lut(lut1idx0));
    flut1.push_back(lut1idx0);
    auto lut1idx1 = [](long I) -> long {
        /* GATE 9 (LUT2 _198_ INIT 0x6 PERM 01) */
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
    lut1.push_back(ctx.genrate_lut(lut1idx1));
    flut1.push_back(lut1idx1);
    auto fvec1 = [flut1](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 2; ++i)
            ret.push_back(flut1[i](I));
        return ret;
    };

    std::cerr << "\rLUT1   ";
    Ciphertext gin1 = 1 * ct_a3 + 2 * ct_b3;
    std::vector<Ciphertext> gout1 = ctx.eval_lut_amortized(&gin1, lut1);

    std::vector<RotationPoly> lut2;
    std::vector<long (*)(long)> flut2;
    auto lut2idx0 = [](long I) -> long {
        /* GATE 13 (LUT2 _202_ INIT 0x1 PERM 01) */
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
            case 12: return 1;
            case 13: return 0;
            case 14: return 0;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut2.push_back(ctx.genrate_lut(lut2idx0));
    flut2.push_back(lut2idx0);
    auto lut2idx1 = [](long I) -> long {
        /* GATE 14 (LUT2 _203_ INIT 0x8 PERM 01) */
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
    Ciphertext gin2 = 1 * ct_a9 + 2 * ct_b9;
    std::vector<Ciphertext> gout2 = ctx.eval_lut_amortized(&gin2, lut2);

    std::vector<RotationPoly> lut3;
    std::vector<long (*)(long)> flut3;
    auto lut3idx0 = [](long I) -> long {
        /* GATE 64 (LUT4 _253_ INIT 0x8778 PERM 0123) */
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
    lut3.push_back(ctx.genrate_lut(lut3idx0));
    flut3.push_back(lut3idx0);
    auto lut3idx1 = [](long I) -> long {
        /* GATE 8 (LUT4 _197_ INIT 0x1777 PERM 2301) */
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
    lut3.push_back(ctx.genrate_lut(lut3idx1));
    flut3.push_back(lut3idx1);
    auto lut3idx2 = [](long I) -> long {
        /* GATE 63 (LUT2 _252_ INIT 0x6 PERM 01) */
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
    lut3.push_back(ctx.genrate_lut(lut3idx2));
    flut3.push_back(lut3idx2);
    auto fvec3 = [flut3](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 3; ++i)
            ret.push_back(flut3[i](I));
        return ret;
    };

    std::cerr << "\rLUT3   ";
    Ciphertext gin3 = 1 * ct_a0 + 2 * ct_b0 + 4 * ct_a1 + 8 * ct_b1;
    std::vector<Ciphertext> gout3 = ctx.eval_lut_amortized(&gin3, lut3);

    std::vector<RotationPoly> lut4;
    std::vector<long (*)(long)> flut4;
    auto lut4idx0 = [](long I) -> long {
        /* GATE 41 (LUT2 _230_ INIT 0x8 PERM 01) */
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
    lut4.push_back(ctx.genrate_lut(lut4idx0));
    flut4.push_back(lut4idx0);
    auto lut4idx1 = [](long I) -> long {
        /* GATE 42 (LUT2 _231_ INIT 0x1 PERM 01) */
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
            case 12: return 1;
            case 13: return 0;
            case 14: return 0;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut4.push_back(ctx.genrate_lut(lut4idx1));
    flut4.push_back(lut4idx1);
    auto fvec4 = [flut4](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 2; ++i)
            ret.push_back(flut4[i](I));
        return ret;
    };

    std::cerr << "\rLUT4   ";
    Ciphertext gin4 = 1 * ct_a21 + 2 * ct_b21;
    std::vector<Ciphertext> gout4 = ctx.eval_lut_amortized(&gin4, lut4);

    std::vector<RotationPoly> lut5;
    std::vector<long (*)(long)> flut5;
    auto lut5idx0 = [](long I) -> long {
        /* GATE 46 (LUT2 _235_ INIT 0x6 PERM 01) */
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
    lut5.push_back(ctx.genrate_lut(lut5idx0));
    flut5.push_back(lut5idx0);
    auto lut5idx1 = [](long I) -> long {
        /* GATE 49 (LUT2 _238_ INIT 0x8 PERM 01) */
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
    lut5.push_back(ctx.genrate_lut(lut5idx1));
    flut5.push_back(lut5idx1);
    auto fvec5 = [flut5](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 2; ++i)
            ret.push_back(flut5[i](I));
        return ret;
    };

    std::cerr << "\rLUT5   ";
    Ciphertext gin5 = 1 * ct_a24 + 2 * ct_b24;
    std::vector<Ciphertext> gout5 = ctx.eval_lut_amortized(&gin5, lut5);

    std::vector<RotationPoly> lut6;
    std::vector<long (*)(long)> flut6;
    auto lut6idx0 = [](long I) -> long {
        /* GATE 16 (LUT2 _205_ INIT 0x6 PERM 01) */
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
    lut6.push_back(ctx.genrate_lut(lut6idx0));
    flut6.push_back(lut6idx0);
    auto lut6idx1 = [](long I) -> long {
        /* GATE 19 (LUT2 _208_ INIT 0x8 PERM 01) */
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
    lut6.push_back(ctx.genrate_lut(lut6idx1));
    flut6.push_back(lut6idx1);
    auto fvec6 = [flut6](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 2; ++i)
            ret.push_back(flut6[i](I));
        return ret;
    };

    std::cerr << "\rLUT6   ";
    Ciphertext gin6 = 1 * ct_a12 + 2 * ct_b12;
    std::vector<Ciphertext> gout6 = ctx.eval_lut_amortized(&gin6, lut6);

    std::vector<RotationPoly> lut7;
    std::vector<long (*)(long)> flut7;
    auto lut7idx0 = [](long I) -> long {
        /* GATE 55 (LUT2 _244_ INIT 0x6 PERM 01) */
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
    lut7.push_back(ctx.genrate_lut(lut7idx0));
    flut7.push_back(lut7idx0);
    auto lut7idx1 = [](long I) -> long {
        /* GATE 58 (LUT2 _247_ INIT 0x8 PERM 01) */
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
    lut7.push_back(ctx.genrate_lut(lut7idx1));
    flut7.push_back(lut7idx1);
    auto fvec7 = [flut7](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 2; ++i)
            ret.push_back(flut7[i](I));
        return ret;
    };

    std::cerr << "\rLUT7   ";
    Ciphertext gin7 = 1 * ct_a28 + 2 * ct_b28;
    std::vector<Ciphertext> gout7 = ctx.eval_lut_amortized(&gin7, lut7);

    std::vector<RotationPoly> lut8;
    std::vector<long (*)(long)> flut8;
    auto lut8idx0 = [](long I) -> long {
        /* GATE 34 (LUT2 _223_ INIT 0x8 PERM 01) */
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
    lut8.push_back(ctx.genrate_lut(lut8idx0));
    flut8.push_back(lut8idx0);
    auto lut8idx1 = [](long I) -> long {
        /* GATE 31 (LUT2 _220_ INIT 0x6 PERM 01) */
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
    lut8.push_back(ctx.genrate_lut(lut8idx1));
    flut8.push_back(lut8idx1);
    auto fvec8 = [flut8](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 2; ++i)
            ret.push_back(flut8[i](I));
        return ret;
    };

    std::cerr << "\rLUT8   ";
    Ciphertext gin8 = 1 * ct_a18 + 2 * ct_b18;
    std::vector<Ciphertext> gout8 = ctx.eval_lut_amortized(&gin8, lut8);

    std::vector<RotationPoly> lut9;
    std::vector<long (*)(long)> flut9;
    auto lut9idx0 = [](long I) -> long {
        /* GATE 26 (LUT2 _215_ INIT 0x8 PERM 01) */
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
    lut9.push_back(ctx.genrate_lut(lut9idx0));
    flut9.push_back(lut9idx0);
    auto lut9idx1 = [](long I) -> long {
        /* GATE 27 (LUT2 _216_ INIT 0x1 PERM 01) */
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
            case 12: return 1;
            case 13: return 0;
            case 14: return 0;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut9.push_back(ctx.genrate_lut(lut9idx1));
    flut9.push_back(lut9idx1);
    auto fvec9 = [flut9](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 2; ++i)
            ret.push_back(flut9[i](I));
        return ret;
    };

    std::cerr << "\rLUT9   ";
    Ciphertext gin9 = 1 * ct_a15 + 2 * ct_b15;
    std::vector<Ciphertext> gout9 = ctx.eval_lut_amortized(&gin9, lut9);

    std::vector<RotationPoly> lut10;
    std::vector<long (*)(long)> flut10;
    auto lut10idx0 = [](long I) -> long {
        /* GATE 12 (LUT2 _201_ INIT 0x8 PERM 01) */
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
    lut10.push_back(ctx.genrate_lut(lut10idx0));
    flut10.push_back(lut10idx0);
    auto lut10idx1 = [](long I) -> long {
        /* GATE 11 (LUT2 _200_ INIT 0x6 PERM 01) */
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
    lut10.push_back(ctx.genrate_lut(lut10idx1));
    flut10.push_back(lut10idx1);
    auto fvec10 = [flut10](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 2; ++i)
            ret.push_back(flut10[i](I));
        return ret;
    };

    std::cerr << "\rLUT10   ";
    Ciphertext gin10 = 1 * ct_a6 + 2 * ct_b6;
    std::vector<Ciphertext> gout10 = ctx.eval_lut_amortized(&gin10, lut10);

    std::vector<RotationPoly> lut11;
    std::vector<long (*)(long)> flut11;
    auto lut11idx0 = [](long I) -> long {
        /* GATE 7 (LUT4 _196_ INIT 0xd400 PERM 0123) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 0;
            case  3: return 0;
            case  4: return 0;
            case  5: return 0;
            case  6: return 0;
            case  7: return 0;
            case  8: return 0;
            case  9: return 0;
            case 10: return 1;
            case 11: return 0;
            case 12: return 1;
            case 13: return 0;
            case 14: return 1;
            case 15: return 1;
            default: assert(0);
        };
    };
    lut11.push_back(ctx.genrate_lut(lut11idx0));
    flut11.push_back(lut11idx0);
    auto lut11idx1 = [](long I) -> long {
        /* GATE 66 (LUT4 _255_ INIT 0x2bd4 PERM 0123) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 1;
            case  3: return 0;
            case  4: return 1;
            case  5: return 0;
            case  6: return 1;
            case  7: return 1;
            case  8: return 1;
            case  9: return 1;
            case 10: return 0;
            case 11: return 1;
            case 12: return 0;
            case 13: return 1;
            case 14: return 0;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut11.push_back(ctx.genrate_lut(lut11idx1));
    flut11.push_back(lut11idx1);
    auto lut11idx2 = [](long I) -> long {
        /* GATE 65 (LUT3 _254_ INIT 0x69 PERM 012) */
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
    lut11.push_back(ctx.genrate_lut(lut11idx2));
    flut11.push_back(lut11idx2);
    auto fvec11 = [flut11](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 3; ++i)
            ret.push_back(flut11[i](I));
        return ret;
    };

    std::cerr << "\rLUT11   ";
    Ciphertext gin11 = 1 * gout3[1] + 2 * ct_a2 + 4 * ct_b2 + 8 * gout1[1];
    std::vector<Ciphertext> gout11 = ctx.eval_lut_amortized(&gin11, lut11);

    std::vector<RotationPoly> lut12;
    std::vector<long (*)(long)> flut12;
    auto lut12idx0 = [](long I) -> long {
        /* GATE 6 (LUT4 _195_ INIT 0x1117 PERM 2301) */
        switch (I) {
            case  0: return 1;
            case  1: return 1;
            case  2: return 1;
            case  3: return 1;
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
    lut12.push_back(ctx.genrate_lut(lut12idx0));
    flut12.push_back(lut12idx0);
    auto lut12idx1 = [](long I) -> long {
        /* GATE 67 (LUT4 _256_ INIT 0xe11e PERM 0123) */
        switch (I) {
            case  0: return 0;
            case  1: return 1;
            case  2: return 1;
            case  3: return 1;
            case  4: return 1;
            case  5: return 0;
            case  6: return 0;
            case  7: return 0;
            case  8: return 1;
            case  9: return 0;
            case 10: return 0;
            case 11: return 0;
            case 12: return 0;
            case 13: return 1;
            case 14: return 1;
            case 15: return 1;
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
    Ciphertext gin12 = 1 * gout11[0] + 2 * gout1[0] + 4 * ct_a4 + 8 * ct_b4;
    std::vector<Ciphertext> gout12 = ctx.eval_lut_amortized(&gin12, lut12);

    std::vector<RotationPoly> lut13;
    std::vector<long (*)(long)> flut13;
    auto lut13idx0 = [](long I) -> long {
        /* GATE 69 (LUT4 _258_ INIT 0x2bd4 PERM 0123) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 1;
            case  3: return 0;
            case  4: return 1;
            case  5: return 0;
            case  6: return 1;
            case  7: return 1;
            case  8: return 1;
            case  9: return 1;
            case 10: return 0;
            case 11: return 1;
            case 12: return 0;
            case 13: return 1;
            case 14: return 0;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut13.push_back(ctx.genrate_lut(lut13idx0));
    flut13.push_back(lut13idx0);
    auto lut13idx1 = [](long I) -> long {
        /* GATE 5 (LUT4 _194_ INIT 0xd400 PERM 0123) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 0;
            case  3: return 0;
            case  4: return 0;
            case  5: return 0;
            case  6: return 0;
            case  7: return 0;
            case  8: return 0;
            case  9: return 0;
            case 10: return 1;
            case 11: return 0;
            case 12: return 1;
            case 13: return 0;
            case 14: return 1;
            case 15: return 1;
            default: assert(0);
        };
    };
    lut13.push_back(ctx.genrate_lut(lut13idx1));
    flut13.push_back(lut13idx1);
    auto lut13idx2 = [](long I) -> long {
        /* GATE 68 (LUT3 _257_ INIT 0x69 PERM 012) */
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
    lut13.push_back(ctx.genrate_lut(lut13idx2));
    flut13.push_back(lut13idx2);
    auto fvec13 = [flut13](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 3; ++i)
            ret.push_back(flut13[i](I));
        return ret;
    };

    std::cerr << "\rLUT13   ";
    Ciphertext gin13 = 1 * gout12[0] + 2 * ct_a5 + 4 * ct_b5 + 8 * gout10[1];
    std::vector<Ciphertext> gout13 = ctx.eval_lut_amortized(&gin13, lut13);

    std::vector<RotationPoly> lut14;
    std::vector<long (*)(long)> flut14;
    auto lut14idx0 = [](long I) -> long {
        /* GATE 70 (LUT4 _259_ INIT 0xe11e PERM 0123) */
        switch (I) {
            case  0: return 0;
            case  1: return 1;
            case  2: return 1;
            case  3: return 1;
            case  4: return 1;
            case  5: return 0;
            case  6: return 0;
            case  7: return 0;
            case  8: return 1;
            case  9: return 0;
            case 10: return 0;
            case 11: return 0;
            case 12: return 0;
            case 13: return 1;
            case 14: return 1;
            case 15: return 1;
            default: assert(0);
        };
    };
    lut14.push_back(ctx.genrate_lut(lut14idx0));
    flut14.push_back(lut14idx0);
    auto lut14idx1 = [](long I) -> long {
        /* GATE 4 (LUT4 _193_ INIT 0x1117 PERM 2301) */
        switch (I) {
            case  0: return 1;
            case  1: return 1;
            case  2: return 1;
            case  3: return 1;
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
    lut14.push_back(ctx.genrate_lut(lut14idx1));
    flut14.push_back(lut14idx1);
    auto fvec14 = [flut14](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 2; ++i)
            ret.push_back(flut14[i](I));
        return ret;
    };

    std::cerr << "\rLUT14   ";
    Ciphertext gin14 = 1 * gout13[1] + 2 * gout10[0] + 4 * ct_a7 + 8 * ct_b7;
    std::vector<Ciphertext> gout14 = ctx.eval_lut_amortized(&gin14, lut14);

    std::vector<RotationPoly> lut15;
    std::vector<long (*)(long)> flut15;
    auto lut15idx0 = [](long I) -> long {
        /* GATE 3 (LUT4 _192_ INIT 0xd4 PERM 0123) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 1;
            case  3: return 0;
            case  4: return 1;
            case  5: return 0;
            case  6: return 1;
            case  7: return 1;
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
    lut15.push_back(ctx.genrate_lut(lut15idx0));
    flut15.push_back(lut15idx0);
    auto lut15idx1 = [](long I) -> long {
        /* GATE 73 (LUT3 _262_ INIT 0x2b PERM 012) */
        switch (I) {
            case  0: return 1;
            case  1: return 1;
            case  2: return 0;
            case  3: return 1;
            case  4: return 0;
            case  5: return 1;
            case  6: return 0;
            case  7: return 0;
            case  8: return 1;
            case  9: return 1;
            case 10: return 0;
            case 11: return 1;
            case 12: return 0;
            case 13: return 1;
            case 14: return 0;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut15.push_back(ctx.genrate_lut(lut15idx1));
    flut15.push_back(lut15idx1);
    auto lut15idx2 = [](long I) -> long {
        /* GATE 71 (LUT3 _260_ INIT 0x69 PERM 012) */
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
    lut15.push_back(ctx.genrate_lut(lut15idx2));
    flut15.push_back(lut15idx2);
    auto fvec15 = [flut15](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 3; ++i)
            ret.push_back(flut15[i](I));
        return ret;
    };

    std::cerr << "\rLUT15   ";
    Ciphertext gin15 = 1 * gout14[1] + 2 * ct_a8 + 4 * ct_b8 + 8 * gout2[0];
    std::vector<Ciphertext> gout15 = ctx.eval_lut_amortized(&gin15, lut15);

    std::vector<RotationPoly> lut16;
    std::vector<long (*)(long)> flut16;
    auto lut16idx0 = [](long I) -> long {
        /* GATE 72 (LUT3 _261_ INIT 0x69 PERM 012) */
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
    lut16.push_back(ctx.genrate_lut(lut16idx0));
    flut16.push_back(lut16idx0);
    auto fvec16 = [flut16](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut16[i](I));
        return ret;
    };

    std::cerr << "\rLUT16   ";
    Ciphertext gin16 = 1 * gout15[1] + 2 * ct_a9 + 4 * ct_b9;
    std::vector<Ciphertext> gout16 = ctx.eval_lut_amortized(&gin16, lut16);

    std::vector<RotationPoly> lut17;
    std::vector<long (*)(long)> flut17;
    auto lut17idx0 = [](long I) -> long {
        /* GATE 2 (LUT4 _191_ INIT 0x1117 PERM 0123) */
        switch (I) {
            case  0: return 1;
            case  1: return 1;
            case  2: return 1;
            case  3: return 0;
            case  4: return 1;
            case  5: return 0;
            case  6: return 0;
            case  7: return 0;
            case  8: return 1;
            case  9: return 0;
            case 10: return 0;
            case 11: return 0;
            case 12: return 1;
            case 13: return 0;
            case 14: return 0;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut17.push_back(ctx.genrate_lut(lut17idx0));
    flut17.push_back(lut17idx0);
    auto lut17idx1 = [](long I) -> long {
        /* GATE 74 (LUT4 _263_ INIT 0xe11e PERM 2301) */
        switch (I) {
            case  0: return 0;
            case  1: return 1;
            case  2: return 1;
            case  3: return 0;
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
            case 14: return 0;
            case 15: return 1;
            default: assert(0);
        };
    };
    lut17.push_back(ctx.genrate_lut(lut17idx1));
    flut17.push_back(lut17idx1);
    auto fvec17 = [flut17](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 2; ++i)
            ret.push_back(flut17[i](I));
        return ret;
    };

    std::cerr << "\rLUT17   ";
    Ciphertext gin17 = 1 * ct_a10 + 2 * ct_b10 + 4 * gout15[0] + 8 * gout2[1];
    std::vector<Ciphertext> gout17 = ctx.eval_lut_amortized(&gin17, lut17);

    std::vector<RotationPoly> lut18;
    std::vector<long (*)(long)> flut18;
    auto lut18idx0 = [](long I) -> long {
        /* GATE 15 (LUT4 _204_ INIT 0x2bd4 PERM 0123) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 1;
            case  3: return 0;
            case  4: return 1;
            case  5: return 0;
            case  6: return 1;
            case  7: return 1;
            case  8: return 1;
            case  9: return 1;
            case 10: return 0;
            case 11: return 1;
            case 12: return 0;
            case 13: return 1;
            case 14: return 0;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut18.push_back(ctx.genrate_lut(lut18idx0));
    flut18.push_back(lut18idx0);
    auto lut18idx1 = [](long I) -> long {
        /* GATE 18 (LUT4 _207_ INIT 0xd400 PERM 0123) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 0;
            case  3: return 0;
            case  4: return 0;
            case  5: return 0;
            case  6: return 0;
            case  7: return 0;
            case  8: return 0;
            case  9: return 0;
            case 10: return 1;
            case 11: return 0;
            case 12: return 1;
            case 13: return 0;
            case 14: return 1;
            case 15: return 1;
            default: assert(0);
        };
    };
    lut18.push_back(ctx.genrate_lut(lut18idx1));
    flut18.push_back(lut18idx1);
    auto lut18idx2 = [](long I) -> long {
        /* GATE 1 (LUT3 _190_ INIT 0x69 PERM 012) */
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
    lut18.push_back(ctx.genrate_lut(lut18idx2));
    flut18.push_back(lut18idx2);
    auto fvec18 = [flut18](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 3; ++i)
            ret.push_back(flut18[i](I));
        return ret;
    };

    std::cerr << "\rLUT18   ";
    Ciphertext gin18 = 1 * gout17[0] + 2 * ct_a11 + 4 * ct_b11 + 8 * gout6[0];
    std::vector<Ciphertext> gout18 = ctx.eval_lut_amortized(&gin18, lut18);

    std::vector<RotationPoly> lut19;
    std::vector<long (*)(long)> flut19;
    auto lut19idx0 = [](long I) -> long {
        /* GATE 17 (LUT4 _206_ INIT 0xe11e PERM 0123) */
        switch (I) {
            case  0: return 0;
            case  1: return 1;
            case  2: return 1;
            case  3: return 1;
            case  4: return 1;
            case  5: return 0;
            case  6: return 0;
            case  7: return 0;
            case  8: return 1;
            case  9: return 0;
            case 10: return 0;
            case 11: return 0;
            case 12: return 0;
            case 13: return 1;
            case 14: return 1;
            case 15: return 1;
            default: assert(0);
        };
    };
    lut19.push_back(ctx.genrate_lut(lut19idx0));
    flut19.push_back(lut19idx0);
    auto lut19idx1 = [](long I) -> long {
        /* GATE 21 (LUT4 _210_ INIT 0xeee8 PERM 2301) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 0;
            case  3: return 0;
            case  4: return 0;
            case  5: return 1;
            case  6: return 1;
            case  7: return 1;
            case  8: return 0;
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
    lut19.push_back(ctx.genrate_lut(lut19idx1));
    flut19.push_back(lut19idx1);
    auto fvec19 = [flut19](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 2; ++i)
            ret.push_back(flut19[i](I));
        return ret;
    };

    std::cerr << "\rLUT19   ";
    Ciphertext gin19 = 1 * gout18[1] + 2 * gout6[1] + 4 * ct_a13 + 8 * ct_b13;
    std::vector<Ciphertext> gout19 = ctx.eval_lut_amortized(&gin19, lut19);

    std::vector<RotationPoly> lut20;
    std::vector<long (*)(long)> flut20;
    auto lut20idx0 = [](long I) -> long {
        /* GATE 25 (LUT4 _214_ INIT 0x17 PERM 1230) */
        switch (I) {
            case  0: return 1;
            case  1: return 0;
            case  2: return 1;
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
    lut20.push_back(ctx.genrate_lut(lut20idx0));
    flut20.push_back(lut20idx0);
    auto lut20idx1 = [](long I) -> long {
        /* GATE 20 (LUT3 _209_ INIT 0x96 PERM 123) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 1;
            case  3: return 1;
            case  4: return 1;
            case  5: return 1;
            case  6: return 0;
            case  7: return 0;
            case  8: return 1;
            case  9: return 1;
            case 10: return 0;
            case 11: return 0;
            case 12: return 0;
            case 13: return 0;
            case 14: return 1;
            case 15: return 1;
            default: assert(0);
        };
    };
    lut20.push_back(ctx.genrate_lut(lut20idx1));
    flut20.push_back(lut20idx1);
    auto lut20idx2 = [](long I) -> long {
        /* GATE 23 (LUT3 _212_ INIT 0x17 PERM 123) */
        switch (I) {
            case  0: return 1;
            case  1: return 1;
            case  2: return 1;
            case  3: return 1;
            case  4: return 1;
            case  5: return 1;
            case  6: return 0;
            case  7: return 0;
            case  8: return 1;
            case  9: return 1;
            case 10: return 0;
            case 11: return 0;
            case 12: return 0;
            case 13: return 0;
            case 14: return 0;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut20.push_back(ctx.genrate_lut(lut20idx2));
    flut20.push_back(lut20idx2);
    auto fvec20 = [flut20](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 3; ++i)
            ret.push_back(flut20[i](I));
        return ret;
    };

    std::cerr << "\rLUT20   ";
    Ciphertext gin20 = 1 * gout9[0] + 2 * gout19[1] + 4 * ct_a14 + 8 * ct_b14;
    std::vector<Ciphertext> gout20 = ctx.eval_lut_amortized(&gin20, lut20);

    std::vector<RotationPoly> lut21;
    std::vector<long (*)(long)> flut21;
    auto lut21idx0 = [](long I) -> long {
        /* GATE 22 (LUT3 _211_ INIT 0x69 PERM 012) */
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
    lut21.push_back(ctx.genrate_lut(lut21idx0));
    flut21.push_back(lut21idx0);
    auto fvec21 = [flut21](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut21[i](I));
        return ret;
    };

    std::cerr << "\rLUT21   ";
    Ciphertext gin21 = 1 * gout20[2] + 2 * ct_a15 + 4 * ct_b15;
    std::vector<Ciphertext> gout21 = ctx.eval_lut_amortized(&gin21, lut21);

    std::vector<RotationPoly> lut22;
    std::vector<long (*)(long)> flut22;
    auto lut22idx0 = [](long I) -> long {
        /* GATE 29 (LUT4 _218_ INIT 0x54fd PERM 2103) */
        switch (I) {
            case  0: return 1;
            case  1: return 1;
            case  2: return 1;
            case  3: return 1;
            case  4: return 0;
            case  5: return 1;
            case  6: return 1;
            case  7: return 1;
            case  8: return 0;
            case  9: return 1;
            case 10: return 1;
            case 11: return 1;
            case 12: return 0;
            case 13: return 0;
            case 14: return 0;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut22.push_back(ctx.genrate_lut(lut22idx0));
    flut22.push_back(lut22idx0);
    auto lut22idx1 = [](long I) -> long {
        /* GATE 24 (LUT4 _213_ INIT 0x1ee1 PERM 0123) */
        switch (I) {
            case  0: return 1;
            case  1: return 0;
            case  2: return 0;
            case  3: return 0;
            case  4: return 0;
            case  5: return 1;
            case  6: return 1;
            case  7: return 1;
            case  8: return 0;
            case  9: return 1;
            case 10: return 1;
            case 11: return 1;
            case 12: return 1;
            case 13: return 0;
            case 14: return 0;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut22.push_back(ctx.genrate_lut(lut22idx1));
    flut22.push_back(lut22idx1);
    auto fvec22 = [flut22](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 2; ++i)
            ret.push_back(flut22[i](I));
        return ret;
    };

    std::cerr << "\rLUT22   ";
    Ciphertext gin22 = 1 * gout20[0] + 2 * gout9[1] + 4 * ct_a16 + 8 * ct_b16;
    std::vector<Ciphertext> gout22 = ctx.eval_lut_amortized(&gin22, lut22);

    std::vector<RotationPoly> lut23;
    std::vector<long (*)(long)> flut23;
    auto lut23idx0 = [](long I) -> long {
        /* GATE 33 (LUT4 _222_ INIT 0xd400 PERM 0123) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 0;
            case  3: return 0;
            case  4: return 0;
            case  5: return 0;
            case  6: return 0;
            case  7: return 0;
            case  8: return 0;
            case  9: return 0;
            case 10: return 1;
            case 11: return 0;
            case 12: return 1;
            case 13: return 0;
            case 14: return 1;
            case 15: return 1;
            default: assert(0);
        };
    };
    lut23.push_back(ctx.genrate_lut(lut23idx0));
    flut23.push_back(lut23idx0);
    auto lut23idx1 = [](long I) -> long {
        /* GATE 30 (LUT4 _219_ INIT 0x2bd4 PERM 0123) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 1;
            case  3: return 0;
            case  4: return 1;
            case  5: return 0;
            case  6: return 1;
            case  7: return 1;
            case  8: return 1;
            case  9: return 1;
            case 10: return 0;
            case 11: return 1;
            case 12: return 0;
            case 13: return 1;
            case 14: return 0;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut23.push_back(ctx.genrate_lut(lut23idx1));
    flut23.push_back(lut23idx1);
    auto lut23idx2 = [](long I) -> long {
        /* GATE 28 (LUT3 _217_ INIT 0x69 PERM 012) */
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
    lut23.push_back(ctx.genrate_lut(lut23idx2));
    flut23.push_back(lut23idx2);
    auto fvec23 = [flut23](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 3; ++i)
            ret.push_back(flut23[i](I));
        return ret;
    };

    std::cerr << "\rLUT23   ";
    Ciphertext gin23 = 1 * gout22[0] + 2 * ct_a17 + 4 * ct_b17 + 8 * gout8[1];
    std::vector<Ciphertext> gout23 = ctx.eval_lut_amortized(&gin23, lut23);

    std::vector<RotationPoly> lut24;
    std::vector<long (*)(long)> flut24;
    auto lut24idx0 = [](long I) -> long {
        /* GATE 36 (LUT4 _225_ INIT 0xeee8 PERM 0123) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 0;
            case  3: return 1;
            case  4: return 0;
            case  5: return 1;
            case  6: return 1;
            case  7: return 1;
            case  8: return 0;
            case  9: return 1;
            case 10: return 1;
            case 11: return 1;
            case 12: return 0;
            case 13: return 1;
            case 14: return 1;
            case 15: return 1;
            default: assert(0);
        };
    };
    lut24.push_back(ctx.genrate_lut(lut24idx0));
    flut24.push_back(lut24idx0);
    auto lut24idx1 = [](long I) -> long {
        /* GATE 32 (LUT4 _221_ INIT 0xe11e PERM 2301) */
        switch (I) {
            case  0: return 0;
            case  1: return 1;
            case  2: return 1;
            case  3: return 0;
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
            case 14: return 0;
            case 15: return 1;
            default: assert(0);
        };
    };
    lut24.push_back(ctx.genrate_lut(lut24idx1));
    flut24.push_back(lut24idx1);
    auto fvec24 = [flut24](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 2; ++i)
            ret.push_back(flut24[i](I));
        return ret;
    };

    std::cerr << "\rLUT24   ";
    Ciphertext gin24 = 1 * ct_a19 + 2 * ct_b19 + 4 * gout23[0] + 8 * gout8[0];
    std::vector<Ciphertext> gout24 = ctx.eval_lut_amortized(&gin24, lut24);

    std::vector<RotationPoly> lut25;
    std::vector<long (*)(long)> flut25;
    auto lut25idx0 = [](long I) -> long {
        /* GATE 40 (LUT4 _229_ INIT 0x17 PERM 1230) */
        switch (I) {
            case  0: return 1;
            case  1: return 0;
            case  2: return 1;
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
    auto lut25idx1 = [](long I) -> long {
        /* GATE 38 (LUT3 _227_ INIT 0x17 PERM 123) */
        switch (I) {
            case  0: return 1;
            case  1: return 1;
            case  2: return 1;
            case  3: return 1;
            case  4: return 1;
            case  5: return 1;
            case  6: return 0;
            case  7: return 0;
            case  8: return 1;
            case  9: return 1;
            case 10: return 0;
            case 11: return 0;
            case 12: return 0;
            case 13: return 0;
            case 14: return 0;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut25.push_back(ctx.genrate_lut(lut25idx1));
    flut25.push_back(lut25idx1);
    auto lut25idx2 = [](long I) -> long {
        /* GATE 35 (LUT3 _224_ INIT 0x96 PERM 123) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 1;
            case  3: return 1;
            case  4: return 1;
            case  5: return 1;
            case  6: return 0;
            case  7: return 0;
            case  8: return 1;
            case  9: return 1;
            case 10: return 0;
            case 11: return 0;
            case 12: return 0;
            case 13: return 0;
            case 14: return 1;
            case 15: return 1;
            default: assert(0);
        };
    };
    lut25.push_back(ctx.genrate_lut(lut25idx2));
    flut25.push_back(lut25idx2);
    auto fvec25 = [flut25](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 3; ++i)
            ret.push_back(flut25[i](I));
        return ret;
    };

    std::cerr << "\rLUT25   ";
    Ciphertext gin25 = 1 * gout4[0] + 2 * gout24[0] + 4 * ct_a20 + 8 * ct_b20;
    std::vector<Ciphertext> gout25 = ctx.eval_lut_amortized(&gin25, lut25);

    std::vector<RotationPoly> lut26;
    std::vector<long (*)(long)> flut26;
    auto lut26idx0 = [](long I) -> long {
        /* GATE 39 (LUT4 _228_ INIT 0x1ee1 PERM 2103) */
        switch (I) {
            case  0: return 1;
            case  1: return 0;
            case  2: return 0;
            case  3: return 1;
            case  4: return 0;
            case  5: return 1;
            case  6: return 0;
            case  7: return 1;
            case  8: return 0;
            case  9: return 1;
            case 10: return 1;
            case 11: return 0;
            case 12: return 1;
            case 13: return 0;
            case 14: return 1;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut26.push_back(ctx.genrate_lut(lut26idx0));
    flut26.push_back(lut26idx0);
    auto lut26idx1 = [](long I) -> long {
        /* GATE 44 (LUT4 _233_ INIT 0x54fd PERM 0123) */
        switch (I) {
            case  0: return 1;
            case  1: return 0;
            case  2: return 1;
            case  3: return 1;
            case  4: return 1;
            case  5: return 1;
            case  6: return 1;
            case  7: return 1;
            case  8: return 0;
            case  9: return 0;
            case 10: return 1;
            case 11: return 0;
            case 12: return 1;
            case 13: return 0;
            case 14: return 1;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut26.push_back(ctx.genrate_lut(lut26idx1));
    flut26.push_back(lut26idx1);
    auto fvec26 = [flut26](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 2; ++i)
            ret.push_back(flut26[i](I));
        return ret;
    };

    std::cerr << "\rLUT26   ";
    Ciphertext gin26 = 1 * ct_a22 + 2 * gout4[1] + 4 * gout25[0] + 8 * ct_b22;
    std::vector<Ciphertext> gout26 = ctx.eval_lut_amortized(&gin26, lut26);

    std::vector<RotationPoly> lut27;
    std::vector<long (*)(long)> flut27;
    auto lut27idx0 = [](long I) -> long {
        /* GATE 37 (LUT3 _226_ INIT 0x69 PERM 012) */
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
    lut27.push_back(ctx.genrate_lut(lut27idx0));
    flut27.push_back(lut27idx0);
    auto fvec27 = [flut27](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut27[i](I));
        return ret;
    };

    std::cerr << "\rLUT27   ";
    Ciphertext gin27 = 1 * gout25[1] + 2 * ct_a21 + 4 * ct_b21;
    std::vector<Ciphertext> gout27 = ctx.eval_lut_amortized(&gin27, lut27);

    std::vector<RotationPoly> lut28;
    std::vector<long (*)(long)> flut28;
    auto lut28idx0 = [](long I) -> long {
        /* GATE 48 (LUT4 _237_ INIT 0xd400 PERM 0123) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 0;
            case  3: return 0;
            case  4: return 0;
            case  5: return 0;
            case  6: return 0;
            case  7: return 0;
            case  8: return 0;
            case  9: return 0;
            case 10: return 1;
            case 11: return 0;
            case 12: return 1;
            case 13: return 0;
            case 14: return 1;
            case 15: return 1;
            default: assert(0);
        };
    };
    lut28.push_back(ctx.genrate_lut(lut28idx0));
    flut28.push_back(lut28idx0);
    auto lut28idx1 = [](long I) -> long {
        /* GATE 45 (LUT4 _234_ INIT 0x2bd4 PERM 0123) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 1;
            case  3: return 0;
            case  4: return 1;
            case  5: return 0;
            case  6: return 1;
            case  7: return 1;
            case  8: return 1;
            case  9: return 1;
            case 10: return 0;
            case 11: return 1;
            case 12: return 0;
            case 13: return 1;
            case 14: return 0;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut28.push_back(ctx.genrate_lut(lut28idx1));
    flut28.push_back(lut28idx1);
    auto lut28idx2 = [](long I) -> long {
        /* GATE 43 (LUT3 _232_ INIT 0x69 PERM 012) */
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
    lut28.push_back(ctx.genrate_lut(lut28idx2));
    flut28.push_back(lut28idx2);
    auto fvec28 = [flut28](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 3; ++i)
            ret.push_back(flut28[i](I));
        return ret;
    };

    std::cerr << "\rLUT28   ";
    Ciphertext gin28 = 1 * gout26[1] + 2 * ct_a23 + 4 * ct_b23 + 8 * gout5[0];
    std::vector<Ciphertext> gout28 = ctx.eval_lut_amortized(&gin28, lut28);

    std::vector<RotationPoly> lut29;
    std::vector<long (*)(long)> flut29;
    auto lut29idx0 = [](long I) -> long {
        /* GATE 47 (LUT4 _236_ INIT 0xe11e PERM 0123) */
        switch (I) {
            case  0: return 0;
            case  1: return 1;
            case  2: return 1;
            case  3: return 1;
            case  4: return 1;
            case  5: return 0;
            case  6: return 0;
            case  7: return 0;
            case  8: return 1;
            case  9: return 0;
            case 10: return 0;
            case 11: return 0;
            case 12: return 0;
            case 13: return 1;
            case 14: return 1;
            case 15: return 1;
            default: assert(0);
        };
    };
    lut29.push_back(ctx.genrate_lut(lut29idx0));
    flut29.push_back(lut29idx0);
    auto lut29idx1 = [](long I) -> long {
        /* GATE 51 (LUT4 _240_ INIT 0x1117 PERM 2301) */
        switch (I) {
            case  0: return 1;
            case  1: return 1;
            case  2: return 1;
            case  3: return 1;
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
    lut29.push_back(ctx.genrate_lut(lut29idx1));
    flut29.push_back(lut29idx1);
    auto fvec29 = [flut29](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 2; ++i)
            ret.push_back(flut29[i](I));
        return ret;
    };

    std::cerr << "\rLUT29   ";
    Ciphertext gin29 = 1 * gout28[0] + 2 * gout5[1] + 4 * ct_a25 + 8 * ct_b25;
    std::vector<Ciphertext> gout29 = ctx.eval_lut_amortized(&gin29, lut29);

    std::vector<RotationPoly> lut30;
    std::vector<long (*)(long)> flut30;
    auto lut30idx0 = [](long I) -> long {
        /* GATE 50 (LUT3 _239_ INIT 0x69 PERM 012) */
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
    lut30.push_back(ctx.genrate_lut(lut30idx0));
    flut30.push_back(lut30idx0);
    auto lut30idx1 = [](long I) -> long {
        /* GATE 53 (LUT3 _242_ INIT 0x2b PERM 012) */
        switch (I) {
            case  0: return 1;
            case  1: return 1;
            case  2: return 0;
            case  3: return 1;
            case  4: return 0;
            case  5: return 1;
            case  6: return 0;
            case  7: return 0;
            case  8: return 1;
            case  9: return 1;
            case 10: return 0;
            case 11: return 1;
            case 12: return 0;
            case 13: return 1;
            case 14: return 0;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut30.push_back(ctx.genrate_lut(lut30idx1));
    flut30.push_back(lut30idx1);
    auto fvec30 = [flut30](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 2; ++i)
            ret.push_back(flut30[i](I));
        return ret;
    };

    std::cerr << "\rLUT30   ";
    Ciphertext gin30 = 1 * gout29[1] + 2 * ct_a26 + 4 * ct_b26;
    std::vector<Ciphertext> gout30 = ctx.eval_lut_amortized(&gin30, lut30);

    std::vector<RotationPoly> lut31;
    std::vector<long (*)(long)> flut31;
    auto lut31idx0 = [](long I) -> long {
        /* GATE 57 (LUT4 _246_ INIT 0xd400 PERM 0123) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 0;
            case  3: return 0;
            case  4: return 0;
            case  5: return 0;
            case  6: return 0;
            case  7: return 0;
            case  8: return 0;
            case  9: return 0;
            case 10: return 1;
            case 11: return 0;
            case 12: return 1;
            case 13: return 0;
            case 14: return 1;
            case 15: return 1;
            default: assert(0);
        };
    };
    lut31.push_back(ctx.genrate_lut(lut31idx0));
    flut31.push_back(lut31idx0);
    auto lut31idx1 = [](long I) -> long {
        /* GATE 54 (LUT4 _243_ INIT 0x2bd4 PERM 0123) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 1;
            case  3: return 0;
            case  4: return 1;
            case  5: return 0;
            case  6: return 1;
            case  7: return 1;
            case  8: return 1;
            case  9: return 1;
            case 10: return 0;
            case 11: return 1;
            case 12: return 0;
            case 13: return 1;
            case 14: return 0;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut31.push_back(ctx.genrate_lut(lut31idx1));
    flut31.push_back(lut31idx1);
    auto lut31idx2 = [](long I) -> long {
        /* GATE 52 (LUT3 _241_ INIT 0x69 PERM 012) */
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
    lut31.push_back(ctx.genrate_lut(lut31idx2));
    flut31.push_back(lut31idx2);
    auto fvec31 = [flut31](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 3; ++i)
            ret.push_back(flut31[i](I));
        return ret;
    };

    std::cerr << "\rLUT31   ";
    Ciphertext gin31 = 1 * gout30[1] + 2 * ct_a27 + 4 * ct_b27 + 8 * gout7[0];
    std::vector<Ciphertext> gout31 = ctx.eval_lut_amortized(&gin31, lut31);

    std::vector<RotationPoly> lut32;
    std::vector<long (*)(long)> flut32;
    auto lut32idx0 = [](long I) -> long {
        /* GATE 60 (LUT4 _249_ INIT 0x1117 PERM 0123) */
        switch (I) {
            case  0: return 1;
            case  1: return 1;
            case  2: return 1;
            case  3: return 0;
            case  4: return 1;
            case  5: return 0;
            case  6: return 0;
            case  7: return 0;
            case  8: return 1;
            case  9: return 0;
            case 10: return 0;
            case 11: return 0;
            case 12: return 1;
            case 13: return 0;
            case 14: return 0;
            case 15: return 0;
            default: assert(0);
        };
    };
    lut32.push_back(ctx.genrate_lut(lut32idx0));
    flut32.push_back(lut32idx0);
    auto lut32idx1 = [](long I) -> long {
        /* GATE 56 (LUT4 _245_ INIT 0xe11e PERM 2301) */
        switch (I) {
            case  0: return 0;
            case  1: return 1;
            case  2: return 1;
            case  3: return 0;
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
            case 14: return 0;
            case 15: return 1;
            default: assert(0);
        };
    };
    lut32.push_back(ctx.genrate_lut(lut32idx1));
    flut32.push_back(lut32idx1);
    auto fvec32 = [flut32](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 2; ++i)
            ret.push_back(flut32[i](I));
        return ret;
    };

    std::cerr << "\rLUT32   ";
    Ciphertext gin32 = 1 * ct_a29 + 2 * ct_b29 + 4 * gout31[0] + 8 * gout7[1];
    std::vector<Ciphertext> gout32 = ctx.eval_lut_amortized(&gin32, lut32);

    std::vector<RotationPoly> lut33;
    std::vector<long (*)(long)> flut33;
    auto lut33idx0 = [](long I) -> long {
        /* GATE 61 (LUT4 _250_ INIT 0xd42b PERM 0123) */
        switch (I) {
            case  0: return 1;
            case  1: return 1;
            case  2: return 0;
            case  3: return 1;
            case  4: return 0;
            case  5: return 1;
            case  6: return 0;
            case  7: return 0;
            case  8: return 0;
            case  9: return 0;
            case 10: return 1;
            case 11: return 0;
            case 12: return 1;
            case 13: return 0;
            case 14: return 1;
            case 15: return 1;
            default: assert(0);
        };
    };
    lut33.push_back(ctx.genrate_lut(lut33idx0));
    flut33.push_back(lut33idx0);
    auto lut33idx1 = [](long I) -> long {
        /* GATE 59 (LUT3 _248_ INIT 0x69 PERM 012) */
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
    lut33.push_back(ctx.genrate_lut(lut33idx1));
    flut33.push_back(lut33idx1);
    auto fvec33 = [flut33](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 2; ++i)
            ret.push_back(flut33[i](I));
        return ret;
    };

    std::cerr << "\rLUT33   ";
    Ciphertext gin33 = 1 * gout32[0] + 2 * ct_a30 + 4 * ct_b30 + 8 * gout0[0];
    std::vector<Ciphertext> gout33 = ctx.eval_lut_amortized(&gin33, lut33);

    std::cerr << "\r          \r";
    std::vector<long> test_out;
    test_out.push_back(ctx.decrypt(&gout3[2])); /* out0 */
    test_out.push_back(ctx.decrypt(&gout3[0])); /* out1 */
    test_out.push_back(ctx.decrypt(&gout11[2])); /* out2 */
    test_out.push_back(ctx.decrypt(&gout11[1])); /* out3 */
    test_out.push_back(ctx.decrypt(&gout12[1])); /* out4 */
    test_out.push_back(ctx.decrypt(&gout13[2])); /* out5 */
    test_out.push_back(ctx.decrypt(&gout13[0])); /* out6 */
    test_out.push_back(ctx.decrypt(&gout14[0])); /* out7 */
    test_out.push_back(ctx.decrypt(&gout15[2])); /* out8 */
    test_out.push_back(ctx.decrypt(&gout16[0])); /* out9 */
    test_out.push_back(ctx.decrypt(&gout17[1])); /* out10 */
    test_out.push_back(ctx.decrypt(&gout18[2])); /* out11 */
    test_out.push_back(ctx.decrypt(&gout18[0])); /* out12 */
    test_out.push_back(ctx.decrypt(&gout19[0])); /* out13 */
    test_out.push_back(ctx.decrypt(&gout20[1])); /* out14 */
    test_out.push_back(ctx.decrypt(&gout21[0])); /* out15 */
    test_out.push_back(ctx.decrypt(&gout22[1])); /* out16 */
    test_out.push_back(ctx.decrypt(&gout23[2])); /* out17 */
    test_out.push_back(ctx.decrypt(&gout23[1])); /* out18 */
    test_out.push_back(ctx.decrypt(&gout24[1])); /* out19 */
    test_out.push_back(ctx.decrypt(&gout25[2])); /* out20 */
    test_out.push_back(ctx.decrypt(&gout27[0])); /* out21 */
    test_out.push_back(ctx.decrypt(&gout26[0])); /* out22 */
    test_out.push_back(ctx.decrypt(&gout28[2])); /* out23 */
    test_out.push_back(ctx.decrypt(&gout28[1])); /* out24 */
    test_out.push_back(ctx.decrypt(&gout29[0])); /* out25 */
    test_out.push_back(ctx.decrypt(&gout30[0])); /* out26 */
    test_out.push_back(ctx.decrypt(&gout31[2])); /* out27 */
    test_out.push_back(ctx.decrypt(&gout31[1])); /* out28 */
    test_out.push_back(ctx.decrypt(&gout32[1])); /* out29 */
    test_out.push_back(ctx.decrypt(&gout33[1])); /* out30 */
    test_out.push_back(ctx.decrypt(&gout33[0])); /* out31 */
    return test_out;
}

static void
BM_sum_lut4(benchmark::State& state)
{
    FHEContext ctx;
    ctx.generate_context(tfhe_12_NTT_amortized);
    ctx.set_default_message_encoding_type(partial_domain);
    ctx.set_default_plaintext_space(16);

    for (auto _ : state) {
        test_sum_lut4(ctx);
    }
}

BENCHMARK(BM_sum_lut4)->Unit(benchmark::kSecond);
BENCHMARK_MAIN();