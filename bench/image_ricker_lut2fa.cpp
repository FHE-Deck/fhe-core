#include <benchmark/benchmark.h>
#include "fhe_context.h"
using namespace fhe_deck;


std::vector<long>
test_image_ricker_lut2fa(FHEContext& ctx, std::vector<uint64_t> window = { 0 })
{
    Ciphertext ct_window0 = ctx.encrypt_public((window[0] >> 0) & 1);
    Ciphertext ct_window1 = ctx.encrypt_public((window[0] >> 1) & 1);
    Ciphertext ct_window2 = ctx.encrypt_public((window[0] >> 2) & 1);
    Ciphertext ct_window3 = ctx.encrypt_public((window[0] >> 3) & 1);
    Ciphertext ct_window4 = ctx.encrypt_public((window[0] >> 4) & 1);
    Ciphertext ct_window5 = ctx.encrypt_public((window[0] >> 5) & 1);
    Ciphertext ct_window6 = ctx.encrypt_public((window[0] >> 6) & 1);
    Ciphertext ct_window7 = ctx.encrypt_public((window[0] >> 7) & 1);
    Ciphertext ct_window8 = ctx.encrypt_public((window[0] >> 8) & 1);
    Ciphertext ct_window9 = ctx.encrypt_public((window[0] >> 9) & 1);
    Ciphertext ct_window10 = ctx.encrypt_public((window[0] >> 10) & 1);
    Ciphertext ct_window11 = ctx.encrypt_public((window[0] >> 11) & 1);
    Ciphertext ct_window12 = ctx.encrypt_public((window[0] >> 12) & 1);
    Ciphertext ct_window13 = ctx.encrypt_public((window[0] >> 13) & 1);
    Ciphertext ct_window14 = ctx.encrypt_public((window[0] >> 14) & 1);
    Ciphertext ct_window15 = ctx.encrypt_public((window[0] >> 15) & 1);
    Ciphertext ct_window16 = ctx.encrypt_public((window[0] >> 16) & 1);
    Ciphertext ct_window17 = ctx.encrypt_public((window[0] >> 17) & 1);
    Ciphertext ct_window18 = ctx.encrypt_public((window[0] >> 18) & 1);
    Ciphertext ct_window19 = ctx.encrypt_public((window[0] >> 19) & 1);
    Ciphertext ct_window20 = ctx.encrypt_public((window[0] >> 20) & 1);
    Ciphertext ct_window21 = ctx.encrypt_public((window[0] >> 21) & 1);
    Ciphertext ct_window22 = ctx.encrypt_public((window[0] >> 22) & 1);
    Ciphertext ct_window23 = ctx.encrypt_public((window[0] >> 23) & 1);
    Ciphertext ct_window24 = ctx.encrypt_public((window[0] >> 24) & 1);
    Ciphertext ct_window25 = ctx.encrypt_public((window[0] >> 25) & 1);
    Ciphertext ct_window26 = ctx.encrypt_public((window[0] >> 26) & 1);
    Ciphertext ct_window27 = ctx.encrypt_public((window[0] >> 27) & 1);
    Ciphertext ct_window28 = ctx.encrypt_public((window[0] >> 28) & 1);
    Ciphertext ct_window29 = ctx.encrypt_public((window[0] >> 29) & 1);
    Ciphertext ct_window30 = ctx.encrypt_public((window[0] >> 30) & 1);
    Ciphertext ct_window31 = ctx.encrypt_public((window[0] >> 31) & 1);
    Ciphertext ct_window32 = ctx.encrypt_public((window[0] >> 32) & 1);
    Ciphertext ct_window33 = ctx.encrypt_public((window[0] >> 33) & 1);
    Ciphertext ct_window34 = ctx.encrypt_public((window[0] >> 34) & 1);
    Ciphertext ct_window35 = ctx.encrypt_public((window[0] >> 35) & 1);
    Ciphertext ct_window36 = ctx.encrypt_public((window[0] >> 36) & 1);
    Ciphertext ct_window37 = ctx.encrypt_public((window[0] >> 37) & 1);
    Ciphertext ct_window38 = ctx.encrypt_public((window[0] >> 38) & 1);
    Ciphertext ct_window39 = ctx.encrypt_public((window[0] >> 39) & 1);
    Ciphertext ct_window40 = ctx.encrypt_public((window[0] >> 40) & 1);
    Ciphertext ct_window41 = ctx.encrypt_public((window[0] >> 41) & 1);
    Ciphertext ct_window42 = ctx.encrypt_public((window[0] >> 42) & 1);
    Ciphertext ct_window43 = ctx.encrypt_public((window[0] >> 43) & 1);
    Ciphertext ct_window44 = ctx.encrypt_public((window[0] >> 44) & 1);
    Ciphertext ct_window45 = ctx.encrypt_public((window[0] >> 45) & 1);
    Ciphertext ct_window46 = ctx.encrypt_public((window[0] >> 46) & 1);
    Ciphertext ct_window47 = ctx.encrypt_public((window[0] >> 47) & 1);
    Ciphertext ct_window48 = ctx.encrypt_public((window[0] >> 48) & 1);
    Ciphertext ct_window49 = ctx.encrypt_public((window[0] >> 49) & 1);
    Ciphertext ct_window50 = ctx.encrypt_public((window[0] >> 50) & 1);
    Ciphertext ct_window51 = ctx.encrypt_public((window[0] >> 51) & 1);
    Ciphertext ct_window52 = ctx.encrypt_public((window[0] >> 52) & 1);
    Ciphertext ct_window53 = ctx.encrypt_public((window[0] >> 53) & 1);
    Ciphertext ct_window54 = ctx.encrypt_public((window[0] >> 54) & 1);
    Ciphertext ct_window55 = ctx.encrypt_public((window[0] >> 55) & 1);
    Ciphertext ct_window56 = ctx.encrypt_public((window[0] >> 56) & 1);
    Ciphertext ct_window57 = ctx.encrypt_public((window[0] >> 57) & 1);
    Ciphertext ct_window58 = ctx.encrypt_public((window[0] >> 58) & 1);
    Ciphertext ct_window59 = ctx.encrypt_public((window[0] >> 59) & 1);
    Ciphertext ct_window60 = ctx.encrypt_public((window[0] >> 60) & 1);
    Ciphertext ct_window61 = ctx.encrypt_public((window[0] >> 61) & 1);
    Ciphertext ct_window62 = ctx.encrypt_public((window[0] >> 62) & 1);
    Ciphertext ct_window63 = ctx.encrypt_public((window[0] >> 63) & 1);
    Ciphertext ct_window64 = ctx.encrypt_public((window[1] >> 0) & 1);
    Ciphertext ct_window65 = ctx.encrypt_public((window[1] >> 1) & 1);
    Ciphertext ct_window66 = ctx.encrypt_public((window[1] >> 2) & 1);
    Ciphertext ct_window67 = ctx.encrypt_public((window[1] >> 3) & 1);
    Ciphertext ct_window68 = ctx.encrypt_public((window[1] >> 4) & 1);
    Ciphertext ct_window69 = ctx.encrypt_public((window[1] >> 5) & 1);
    Ciphertext ct_window70 = ctx.encrypt_public((window[1] >> 6) & 1);
    Ciphertext ct_window71 = ctx.encrypt_public((window[1] >> 7) & 1);

    std::vector<RotationPoly> decomp;
    std::vector<long (*)(long)> fdecomp;
    auto decomp0 = [](long I) -> long {
        switch (I) {
            case  0: return 0;
            case  1: return 1;
            case  2: return 0;
            case  3: return 1;
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
            default: assert(0);
        };
    };
    decomp.push_back(ctx.genrate_lut(decomp1));
    fdecomp.push_back(decomp1);
    auto vdecomp = [fdecomp](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 2; ++i)
            ret.push_back(fdecomp[i](I));
        return ret;
    };

    std::cerr << "\rFA0    ";
    Ciphertext gin0 = 0 + 1 * ct_window16 + 1 * ct_window24;
    std::vector<Ciphertext> gout0 = ctx.eval_lut_amortized(&gin0, decomp);

    std::cerr << "\rFA1    ";
    Ciphertext gin1 = 0 + 1 * ct_window40 + 1 * ct_window48;
    std::vector<Ciphertext> gout1 = ctx.eval_lut_amortized(&gin1, decomp);

    std::cerr << "\rFA2    ";
    Ciphertext gin2 = 0 + 1 * ct_window0 + 1 * ct_window8;
    std::vector<Ciphertext> gout2 = ctx.eval_lut_amortized(&gin2, decomp);

    std::cerr << "\rFA3    ";
    Ciphertext gin3 = gout2[1] + 1 * ct_window1 + 1 * ct_window9;
    std::vector<Ciphertext> gout3 = ctx.eval_lut_amortized(&gin3, decomp);

    std::cerr << "\rFA4    ";
    Ciphertext gin4 = gout0[1] + 1 * ct_window17 + 1 * ct_window25;
    std::vector<Ciphertext> gout4 = ctx.eval_lut_amortized(&gin4, decomp);

    std::cerr << "\rFA5    ";
    Ciphertext gin5 = gout1[1] + 1 * ct_window41 + 1 * ct_window49;
    std::vector<Ciphertext> gout5 = ctx.eval_lut_amortized(&gin5, decomp);

    std::cerr << "\rFA6    ";
    Ciphertext gin6 = 0 + 1 * ct_window56 + 1 * ct_window64;
    std::vector<Ciphertext> gout6 = ctx.eval_lut_amortized(&gin6, decomp);

    std::cerr << "\rFA7    ";
    Ciphertext gin7 = 0 + 1 * gout2[0] + 1 * gout0[0];
    std::vector<Ciphertext> gout7 = ctx.eval_lut_amortized(&gin7, decomp);

    std::cerr << "\rFA8    ";
    Ciphertext gin8 = gout3[1] + 1 * ct_window2 + 1 * ct_window10;
    std::vector<Ciphertext> gout8 = ctx.eval_lut_amortized(&gin8, decomp);

    std::cerr << "\rFA9    ";
    Ciphertext gin9 = 0 + 1 * gout1[0] + 1 * gout6[0];
    std::vector<Ciphertext> gout9 = ctx.eval_lut_amortized(&gin9, decomp);

    std::cerr << "\rFA10    ";
    Ciphertext gin10 = gout4[1] + 1 * ct_window18 + 1 * ct_window26;
    std::vector<Ciphertext> gout10 = ctx.eval_lut_amortized(&gin10, decomp);

    std::cerr << "\rFA11    ";
    Ciphertext gin11 = gout5[1] + 1 * ct_window42 + 1 * ct_window50;
    std::vector<Ciphertext> gout11 = ctx.eval_lut_amortized(&gin11, decomp);

    std::cerr << "\rFA12    ";
    Ciphertext gin12 = gout6[1] + 1 * ct_window57 + 1 * ct_window65;
    std::vector<Ciphertext> gout12 = ctx.eval_lut_amortized(&gin12, decomp);

    std::cerr << "\rFA13    ";
    Ciphertext gin13 = gout7[1] + 1 * gout3[0] + 1 * gout4[0];
    std::vector<Ciphertext> gout13 = ctx.eval_lut_amortized(&gin13, decomp);

    std::cerr << "\rFA14    ";
    Ciphertext gin14 = gout9[1] + 1 * gout5[0] + 1 * gout12[0];
    std::vector<Ciphertext> gout14 = ctx.eval_lut_amortized(&gin14, decomp);

    std::cerr << "\rFA15    ";
    Ciphertext gin15 = gout11[1] + 1 * ct_window43 + 1 * ct_window51;
    std::vector<Ciphertext> gout15 = ctx.eval_lut_amortized(&gin15, decomp);

    std::cerr << "\rFA16    ";
    Ciphertext gin16 = 0 + 1 * gout7[0] + 1 * gout9[0];
    std::vector<Ciphertext> gout16 = ctx.eval_lut_amortized(&gin16, decomp);

    std::cerr << "\rFA17    ";
    Ciphertext gin17 = gout15[1] + 1 * ct_window44 + 1 * ct_window52;
    std::vector<Ciphertext> gout17 = ctx.eval_lut_amortized(&gin17, decomp);

    std::cerr << "\rFA18    ";
    Ciphertext gin18 = gout10[1] + 1 * ct_window19 + 1 * ct_window27;
    std::vector<Ciphertext> gout18 = ctx.eval_lut_amortized(&gin18, decomp);

    std::cerr << "\rFA19    ";
    Ciphertext gin19 = gout8[1] + 1 * ct_window3 + 1 * ct_window11;
    std::vector<Ciphertext> gout19 = ctx.eval_lut_amortized(&gin19, decomp);

    std::cerr << "\rFA20    ";
    Ciphertext gin20 = gout13[1] + 1 * gout8[0] + 1 * gout10[0];
    std::vector<Ciphertext> gout20 = ctx.eval_lut_amortized(&gin20, decomp);

    std::cerr << "\rFA21    ";
    Ciphertext gin21 = gout16[1] + 1 * gout13[0] + 1 * gout14[0];
    std::vector<Ciphertext> gout21 = ctx.eval_lut_amortized(&gin21, decomp);

    std::cerr << "\rFA22    ";
    Ciphertext gin22 = gout12[1] + 1 * ct_window58 + 1 * ct_window66;
    std::vector<Ciphertext> gout22 = ctx.eval_lut_amortized(&gin22, decomp);

    std::cerr << "\rFA23    ";
    Ciphertext gin23 = gout14[1] + 1 * gout11[0] + 1 * gout22[0];
    std::vector<Ciphertext> gout23 = ctx.eval_lut_amortized(&gin23, decomp);

    std::cerr << "\rFA24    ";
    Ciphertext gin24 = gout17[1] + 1 * ct_window45 + 1 * ct_window53;
    std::vector<Ciphertext> gout24 = ctx.eval_lut_amortized(&gin24, decomp);

    std::cerr << "\rFA25    ";
    Ciphertext gin25 = gout19[1] + 1 * ct_window4 + 1 * ct_window12;
    std::vector<Ciphertext> gout25 = ctx.eval_lut_amortized(&gin25, decomp);

    std::cerr << "\rFA26    ";
    Ciphertext gin26 = gout20[1] + 1 * gout19[0] + 1 * gout18[0];
    std::vector<Ciphertext> gout26 = ctx.eval_lut_amortized(&gin26, decomp);

    std::cerr << "\rFA27    ";
    Ciphertext gin27 = gout18[1] + 1 * ct_window20 + 1 * ct_window28;
    std::vector<Ciphertext> gout27 = ctx.eval_lut_amortized(&gin27, decomp);

    std::cerr << "\rFA28    ";
    Ciphertext gin28 = gout22[1] + 1 * ct_window59 + 1 * ct_window67;
    std::vector<Ciphertext> gout28 = ctx.eval_lut_amortized(&gin28, decomp);

    std::cerr << "\rFA29    ";
    Ciphertext gin29 = gout23[1] + 1 * gout15[0] + 1 * gout28[0];
    std::vector<Ciphertext> gout29 = ctx.eval_lut_amortized(&gin29, decomp);

    std::cerr << "\rFA30    ";
    Ciphertext gin30 = gout21[1] + 1 * gout20[0] + 1 * gout23[0];
    std::vector<Ciphertext> gout30 = ctx.eval_lut_amortized(&gin30, decomp);

    std::cerr << "\rFA31    ";
    Ciphertext gin31 = gout24[1] + 1 * ct_window46 + 1 * ct_window54;
    std::vector<Ciphertext> gout31 = ctx.eval_lut_amortized(&gin31, decomp);

    std::cerr << "\rFA32    ";
    Ciphertext gin32 = gout25[1] + 1 * ct_window5 + 1 * ct_window13;
    std::vector<Ciphertext> gout32 = ctx.eval_lut_amortized(&gin32, decomp);

    std::cerr << "\rFA33    ";
    Ciphertext gin33 = gout27[1] + 1 * ct_window21 + 1 * ct_window29;
    std::vector<Ciphertext> gout33 = ctx.eval_lut_amortized(&gin33, decomp);

    std::cerr << "\rFA34    ";
    Ciphertext gin34 = gout28[1] + 1 * ct_window60 + 1 * ct_window68;
    std::vector<Ciphertext> gout34 = ctx.eval_lut_amortized(&gin34, decomp);

    std::cerr << "\rFA35    ";
    Ciphertext gin35 = gout26[1] + 1 * gout25[0] + 1 * gout27[0];
    std::vector<Ciphertext> gout35 = ctx.eval_lut_amortized(&gin35, decomp);

    std::cerr << "\rFA36    ";
    Ciphertext gin36 = gout29[1] + 1 * gout17[0] + 1 * gout34[0];
    std::vector<Ciphertext> gout36 = ctx.eval_lut_amortized(&gin36, decomp);

    std::cerr << "\rFA37    ";
    Ciphertext gin37 = gout30[1] + 1 * gout26[0] + 1 * gout29[0];
    std::vector<Ciphertext> gout37 = ctx.eval_lut_amortized(&gin37, decomp);

    std::cerr << "\rFA38    ";
    Ciphertext gin38 = gout35[1] + 1 * gout32[0] + 1 * gout33[0];
    std::vector<Ciphertext> gout38 = ctx.eval_lut_amortized(&gin38, decomp);

    std::cerr << "\rINV39   ";
    std::vector<Ciphertext> gout39;
    gout39.push_back(1 - gout37[0]);

    std::cerr << "\rFA40    ";
    Ciphertext gin40 = gout31[1] + 1 * ct_window47 + 1 * ct_window55;
    std::vector<Ciphertext> gout40 = ctx.eval_lut_amortized(&gin40, decomp);

    std::cerr << "\rFA41    ";
    Ciphertext gin41 = gout33[1] + 1 * ct_window22 + 1 * ct_window30;
    std::vector<Ciphertext> gout41 = ctx.eval_lut_amortized(&gin41, decomp);

    std::cerr << "\rFA42    ";
    Ciphertext gin42 = gout32[1] + 1 * ct_window6 + 1 * ct_window14;
    std::vector<Ciphertext> gout42 = ctx.eval_lut_amortized(&gin42, decomp);

    std::cerr << "\rFA43    ";
    Ciphertext gin43 = 1 + 1 * ct_window32 + 1 * gout39[0];
    std::vector<Ciphertext> gout43 = ctx.eval_lut_amortized(&gin43, decomp);

    std::cerr << "\rFA44    ";
    Ciphertext gin44 = gout37[1] + 1 * gout35[0] + 1 * gout36[0];
    std::vector<Ciphertext> gout44 = ctx.eval_lut_amortized(&gin44, decomp);

    std::cerr << "\rFA45    ";
    Ciphertext gin45 = gout34[1] + 1 * ct_window61 + 1 * ct_window69;
    std::vector<Ciphertext> gout45 = ctx.eval_lut_amortized(&gin45, decomp);

    std::cerr << "\rFA46    ";
    Ciphertext gin46 = gout38[1] + 1 * gout42[0] + 1 * gout41[0];
    std::vector<Ciphertext> gout46 = ctx.eval_lut_amortized(&gin46, decomp);

    std::cerr << "\rFA47    ";
    Ciphertext gin47 = gout36[1] + 1 * gout24[0] + 1 * gout45[0];
    std::vector<Ciphertext> gout47 = ctx.eval_lut_amortized(&gin47, decomp);

    std::cerr << "\rFA48    ";
    Ciphertext gin48 = gout42[1] + 1 * ct_window7 + 1 * ct_window15;
    std::vector<Ciphertext> gout48 = ctx.eval_lut_amortized(&gin48, decomp);

    std::cerr << "\rINV49   ";
    std::vector<Ciphertext> gout49;
    gout49.push_back(1 - gout44[0]);

    std::cerr << "\rFA50    ";
    Ciphertext gin50 = gout41[1] + 1 * ct_window23 + 1 * ct_window31;
    std::vector<Ciphertext> gout50 = ctx.eval_lut_amortized(&gin50, decomp);

    std::cerr << "\rFA51    ";
    Ciphertext gin51 = gout45[1] + 1 * ct_window62 + 1 * ct_window70;
    std::vector<Ciphertext> gout51 = ctx.eval_lut_amortized(&gin51, decomp);

    std::cerr << "\rFA52    ";
    Ciphertext gin52 = gout46[1] + 1 * gout48[0] + 1 * gout50[0];
    std::vector<Ciphertext> gout52 = ctx.eval_lut_amortized(&gin52, decomp);

    std::cerr << "\rFA53    ";
    Ciphertext gin53 = gout47[1] + 1 * gout31[0] + 1 * gout51[0];
    std::vector<Ciphertext> gout53 = ctx.eval_lut_amortized(&gin53, decomp);

    std::cerr << "\rFA54    ";
    Ciphertext gin54 = gout44[1] + 1 * gout38[0] + 1 * gout47[0];
    std::vector<Ciphertext> gout54 = ctx.eval_lut_amortized(&gin54, decomp);

    std::cerr << "\rFA55    ";
    Ciphertext gin55 = gout43[1] + 1 * ct_window33 + 1 * gout49[0];
    std::vector<Ciphertext> gout55 = ctx.eval_lut_amortized(&gin55, decomp);

    std::cerr << "\rFA56    ";
    Ciphertext gin56 = gout51[1] + 1 * ct_window63 + 1 * ct_window71;
    std::vector<Ciphertext> gout56 = ctx.eval_lut_amortized(&gin56, decomp);

    std::cerr << "\rFA57    ";
    Ciphertext gin57 = gout53[1] + 1 * gout40[0] + 1 * gout56[0];
    std::vector<Ciphertext> gout57 = ctx.eval_lut_amortized(&gin57, decomp);

    std::cerr << "\rFA58    ";
    Ciphertext gin58 = gout54[1] + 1 * gout46[0] + 1 * gout53[0];
    std::vector<Ciphertext> gout58 = ctx.eval_lut_amortized(&gin58, decomp);

    std::cerr << "\rFA59    ";
    Ciphertext gin59 = gout52[1] + 1 * gout48[1] + 1 * gout50[1];
    std::vector<Ciphertext> gout59 = ctx.eval_lut_amortized(&gin59, decomp);

    std::cerr << "\rINV60   ";
    std::vector<Ciphertext> gout60;
    gout60.push_back(1 - gout54[0]);

    std::cerr << "\rINV61   ";
    std::vector<Ciphertext> gout61;
    gout61.push_back(1 - gout58[0]);

    std::vector<RotationPoly> lut62;
    std::vector<long (*)(long)> flut62;
    auto lut62idx0 = [](long I) -> long {
        /* GATE 11 (LUT2 _081_ INIT 0x8 PERM 10) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 0;
            case  3: return 1;
            default: assert(0);
        };
    };
    lut62.push_back(ctx.genrate_lut(lut62idx0));
    flut62.push_back(lut62idx0);
    auto lut62idx1 = [](long I) -> long {
        /* GATE 10 (LUT2 _080_ INIT 0x1 PERM 10) */
        switch (I) {
            case  0: return 1;
            case  1: return 0;
            case  2: return 0;
            case  3: return 0;
            default: assert(0);
        };
    };
    lut62.push_back(ctx.genrate_lut(lut62idx1));
    flut62.push_back(lut62idx1);
    auto fvec62 = [flut62](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 2; ++i)
            ret.push_back(flut62[i](I));
        return ret;
    };

    std::cerr << "\rLUT62   ";
    Ciphertext gin62 = 1 * gout43[0] + 2 * gout55[0];
    std::vector<Ciphertext> gout62 = ctx.eval_lut_amortized(&gin62, lut62);

    std::cerr << "\rFA63    ";
    Ciphertext gin63 = gout55[1] + 1 * ct_window34 + 1 * gout60[0];
    std::vector<Ciphertext> gout63 = ctx.eval_lut_amortized(&gin63, decomp);

    std::cerr << "\rFA64    ";
    Ciphertext gin64 = gout58[1] + 1 * gout52[0] + 1 * gout57[0];
    std::vector<Ciphertext> gout64 = ctx.eval_lut_amortized(&gin64, decomp);

    std::vector<RotationPoly> lut65;
    std::vector<long (*)(long)> flut65;
    auto lut65idx0 = [](long I) -> long {
        /* GATE 9 (LUT2 _079_ INIT 0x4 PERM 10) */
        switch (I) {
            case  0: return 0;
            case  1: return 1;
            case  2: return 0;
            case  3: return 0;
            default: assert(0);
        };
    };
    lut65.push_back(ctx.genrate_lut(lut65idx0));
    flut65.push_back(lut65idx0);
    auto fvec65 = [flut65](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut65[i](I));
        return ret;
    };

    std::cerr << "\rLUT65   ";
    Ciphertext gin65 = 1 * gout62[1] + 2 * gout63[0];
    std::vector<Ciphertext> gout65 = ctx.eval_lut_amortized(&gin65, lut65);

    std::cerr << "\rFA66    ";
    Ciphertext gin66 = gout57[1] + 1 * gout40[1] + 1 * gout56[1];
    std::vector<Ciphertext> gout66 = ctx.eval_lut_amortized(&gin66, decomp);

    std::cerr << "\rINV67   ";
    std::vector<Ciphertext> gout67;
    gout67.push_back(1 - gout64[0]);

    std::cerr << "\rFA68    ";
    Ciphertext gin68 = gout63[1] + 1 * ct_window35 + 1 * gout61[0];
    std::vector<Ciphertext> gout68 = ctx.eval_lut_amortized(&gin68, decomp);

    std::cerr << "\rFA69    ";
    Ciphertext gin69 = gout64[1] + 1 * gout59[0] + 1 * gout66[0];
    std::vector<Ciphertext> gout69 = ctx.eval_lut_amortized(&gin69, decomp);

    std::vector<RotationPoly> lut70;
    std::vector<long (*)(long)> flut70;
    auto lut70idx0 = [](long I) -> long {
        /* GATE 8 (LUT2 _078_ INIT 0x4 PERM 10) */
        switch (I) {
            case  0: return 0;
            case  1: return 1;
            case  2: return 0;
            case  3: return 0;
            default: assert(0);
        };
    };
    lut70.push_back(ctx.genrate_lut(lut70idx0));
    flut70.push_back(lut70idx0);
    auto fvec70 = [flut70](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut70[i](I));
        return ret;
    };

    std::cerr << "\rLUT70   ";
    Ciphertext gin70 = 1 * gout65[0] + 2 * gout68[0];
    std::vector<Ciphertext> gout70 = ctx.eval_lut_amortized(&gin70, lut70);

    std::cerr << "\rFA71    ";
    Ciphertext gin71 = gout69[1] + 1 * gout59[1] + 1 * gout66[1];
    std::vector<Ciphertext> gout71 = ctx.eval_lut_amortized(&gin71, decomp);

    std::cerr << "\rINV72   ";
    std::vector<Ciphertext> gout72;
    gout72.push_back(1 - gout69[0]);

    std::cerr << "\rFA73    ";
    Ciphertext gin73 = gout68[1] + 1 * ct_window36 + 1 * gout67[0];
    std::vector<Ciphertext> gout73 = ctx.eval_lut_amortized(&gin73, decomp);

    std::vector<RotationPoly> lut74;
    std::vector<long (*)(long)> flut74;
    auto lut74idx0 = [](long I) -> long {
        /* GATE 7 (LUT2 _077_ INIT 0x4 PERM 10) */
        switch (I) {
            case  0: return 0;
            case  1: return 1;
            case  2: return 0;
            case  3: return 0;
            default: assert(0);
        };
    };
    lut74.push_back(ctx.genrate_lut(lut74idx0));
    flut74.push_back(lut74idx0);
    auto fvec74 = [flut74](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut74[i](I));
        return ret;
    };

    std::cerr << "\rLUT74   ";
    Ciphertext gin74 = 1 * gout70[0] + 2 * gout73[0];
    std::vector<Ciphertext> gout74 = ctx.eval_lut_amortized(&gin74, lut74);

    std::cerr << "\rINV75   ";
    std::vector<Ciphertext> gout75;
    gout75.push_back(1 - gout71[0]);

    std::cerr << "\rINV76   ";
    std::vector<Ciphertext> gout76;
    gout76.push_back(1 - gout71[1]);

    std::cerr << "\rFA77    ";
    Ciphertext gin77 = gout73[1] + 1 * ct_window37 + 1 * gout72[0];
    std::vector<Ciphertext> gout77 = ctx.eval_lut_amortized(&gin77, decomp);

    std::cerr << "\rFA78    ";
    Ciphertext gin78 = gout77[1] + 1 * ct_window38 + 1 * gout75[0];
    std::vector<Ciphertext> gout78 = ctx.eval_lut_amortized(&gin78, decomp);

    std::vector<RotationPoly> lut79;
    std::vector<long (*)(long)> flut79;
    auto lut79idx0 = [](long I) -> long {
        /* GATE 6 (LUT2 _076_ INIT 0x4 PERM 10) */
        switch (I) {
            case  0: return 0;
            case  1: return 1;
            case  2: return 0;
            case  3: return 0;
            default: assert(0);
        };
    };
    lut79.push_back(ctx.genrate_lut(lut79idx0));
    flut79.push_back(lut79idx0);
    auto fvec79 = [flut79](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut79[i](I));
        return ret;
    };

    std::cerr << "\rLUT79   ";
    Ciphertext gin79 = 1 * gout74[0] + 2 * gout77[0];
    std::vector<Ciphertext> gout79 = ctx.eval_lut_amortized(&gin79, lut79);

    std::cerr << "\rFA80    ";
    Ciphertext gin80 = gout78[1] + 1 * ct_window39 + 1 * gout76[0];
    std::vector<Ciphertext> gout80 = ctx.eval_lut_amortized(&gin80, decomp);

    std::cerr << "\rINV81   ";
    std::vector<Ciphertext> gout81;
    gout81.push_back(1 - gout80[1]);

    std::vector<RotationPoly> lut82;
    std::vector<long (*)(long)> flut82;
    auto lut82idx0 = [](long I) -> long {
        /* GATE 5 (LUT2 _075_ INIT 0x4 PERM 10) */
        switch (I) {
            case  0: return 0;
            case  1: return 1;
            case  2: return 0;
            case  3: return 0;
            default: assert(0);
        };
    };
    lut82.push_back(ctx.genrate_lut(lut82idx0));
    flut82.push_back(lut82idx0);
    auto fvec82 = [flut82](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut82[i](I));
        return ret;
    };

    std::cerr << "\rLUT82   ";
    Ciphertext gin82 = 1 * gout79[0] + 2 * gout78[0];
    std::vector<Ciphertext> gout82 = ctx.eval_lut_amortized(&gin82, lut82);

    std::vector<RotationPoly> lut83;
    std::vector<long (*)(long)> flut83;
    auto lut83idx0 = [](long I) -> long {
        /* GATE 3 (LUT2 _073_ INIT 0x1 PERM 10) */
        switch (I) {
            case  0: return 1;
            case  1: return 0;
            case  2: return 0;
            case  3: return 0;
            default: assert(0);
        };
    };
    lut83.push_back(ctx.genrate_lut(lut83idx0));
    flut83.push_back(lut83idx0);
    auto fvec83 = [flut83](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut83[i](I));
        return ret;
    };

    std::cerr << "\rLUT83   ";
    Ciphertext gin83 = 1 * gout62[1] + 2 * gout81[0];
    std::vector<Ciphertext> gout83 = ctx.eval_lut_amortized(&gin83, lut83);

    std::vector<RotationPoly> lut84;
    std::vector<long (*)(long)> flut84;
    auto lut84idx0 = [](long I) -> long {
        /* GATE 12 (LUT2 _082_ INIT 0x8 PERM 10) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 0;
            case  3: return 1;
            default: assert(0);
        };
    };
    lut84.push_back(ctx.genrate_lut(lut84idx0));
    flut84.push_back(lut84idx0);
    auto fvec84 = [flut84](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut84[i](I));
        return ret;
    };

    std::cerr << "\rLUT84   ";
    Ciphertext gin84 = 1 * gout55[0] + 2 * gout81[0];
    std::vector<Ciphertext> gout84 = ctx.eval_lut_amortized(&gin84, lut84);

    std::vector<RotationPoly> lut85;
    std::vector<long (*)(long)> flut85;
    auto lut85idx0 = [](long I) -> long {
        /* GATE 2 (LUT2 _072_ INIT 0x4 PERM 01) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 1;
            case  3: return 0;
            default: assert(0);
        };
    };
    lut85.push_back(ctx.genrate_lut(lut85idx0));
    flut85.push_back(lut85idx0);
    auto fvec85 = [flut85](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut85[i](I));
        return ret;
    };

    std::cerr << "\rLUT85   ";
    Ciphertext gin85 = 1 * gout62[0] + 2 * gout83[0];
    std::vector<Ciphertext> gout85 = ctx.eval_lut_amortized(&gin85, lut85);

    std::vector<RotationPoly> lut86;
    std::vector<long (*)(long)> flut86;
    auto lut86idx0 = [](long I) -> long {
        /* GATE 15 (LUT2 _085_ INIT 0x1 PERM 01) */
        switch (I) {
            case  0: return 1;
            case  1: return 0;
            case  2: return 0;
            case  3: return 0;
            default: assert(0);
        };
    };
    lut86.push_back(ctx.genrate_lut(lut86idx0));
    flut86.push_back(lut86idx0);
    auto fvec86 = [flut86](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut86[i](I));
        return ret;
    };

    std::cerr << "\rLUT86   ";
    Ciphertext gin86 = 1 * gout81[0] + 2 * gout65[0];
    std::vector<Ciphertext> gout86 = ctx.eval_lut_amortized(&gin86, lut86);

    std::vector<RotationPoly> lut87;
    std::vector<long (*)(long)> flut87;
    auto lut87idx0 = [](long I) -> long {
        /* GATE 21 (LUT2 _091_ INIT 0x1 PERM 10) */
        switch (I) {
            case  0: return 1;
            case  1: return 0;
            case  2: return 0;
            case  3: return 0;
            default: assert(0);
        };
    };
    lut87.push_back(ctx.genrate_lut(lut87idx0));
    flut87.push_back(lut87idx0);
    auto fvec87 = [flut87](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut87[i](I));
        return ret;
    };

    std::cerr << "\rLUT87   ";
    Ciphertext gin87 = 1 * gout79[0] + 2 * gout81[0];
    std::vector<Ciphertext> gout87 = ctx.eval_lut_amortized(&gin87, lut87);

    std::vector<RotationPoly> lut88;
    std::vector<long (*)(long)> flut88;
    auto lut88idx0 = [](long I) -> long {
        /* GATE 19 (LUT2 _089_ INIT 0x1 PERM 10) */
        switch (I) {
            case  0: return 1;
            case  1: return 0;
            case  2: return 0;
            case  3: return 0;
            default: assert(0);
        };
    };
    lut88.push_back(ctx.genrate_lut(lut88idx0));
    flut88.push_back(lut88idx0);
    auto fvec88 = [flut88](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut88[i](I));
        return ret;
    };

    std::cerr << "\rLUT88   ";
    Ciphertext gin88 = 1 * gout74[0] + 2 * gout81[0];
    std::vector<Ciphertext> gout88 = ctx.eval_lut_amortized(&gin88, lut88);

    std::vector<RotationPoly> lut89;
    std::vector<long (*)(long)> flut89;
    auto lut89idx0 = [](long I) -> long {
        /* GATE 23 (LUT2 _093_ INIT 0x4 PERM 01) */
        switch (I) {
            case  0: return 0;
            case  1: return 0;
            case  2: return 1;
            case  3: return 0;
            default: assert(0);
        };
    };
    lut89.push_back(ctx.genrate_lut(lut89idx0));
    flut89.push_back(lut89idx0);
    auto fvec89 = [flut89](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut89[i](I));
        return ret;
    };

    std::cerr << "\rLUT89   ";
    Ciphertext gin89 = 1 * gout82[0] + 2 * gout80[1];
    std::vector<Ciphertext> gout89 = ctx.eval_lut_amortized(&gin89, lut89);

    std::vector<RotationPoly> lut90;
    std::vector<long (*)(long)> flut90;
    auto lut90idx0 = [](long I) -> long {
        /* GATE 17 (LUT2 _087_ INIT 0x1 PERM 10) */
        switch (I) {
            case  0: return 1;
            case  1: return 0;
            case  2: return 0;
            case  3: return 0;
            default: assert(0);
        };
    };
    lut90.push_back(ctx.genrate_lut(lut90idx0));
    flut90.push_back(lut90idx0);
    auto fvec90 = [flut90](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut90[i](I));
        return ret;
    };

    std::cerr << "\rLUT90   ";
    Ciphertext gin90 = 1 * gout70[0] + 2 * gout81[0];
    std::vector<Ciphertext> gout90 = ctx.eval_lut_amortized(&gin90, lut90);

    std::vector<RotationPoly> lut91;
    std::vector<long (*)(long)> flut91;
    auto lut91idx0 = [](long I) -> long {
        /* GATE 13 (LUT2 _083_ INIT 0x6 PERM 01) */
        switch (I) {
            case  0: return 0;
            case  1: return 1;
            case  2: return 1;
            case  3: return 0;
            default: assert(0);
        };
    };
    lut91.push_back(ctx.genrate_lut(lut91idx0));
    flut91.push_back(lut91idx0);
    auto fvec91 = [flut91](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut91[i](I));
        return ret;
    };

    std::cerr << "\rLUT91   ";
    Ciphertext gin91 = 1 * gout83[0] + 2 * gout63[0];
    std::vector<Ciphertext> gout91 = ctx.eval_lut_amortized(&gin91, lut91);

    std::vector<RotationPoly> lut92;
    std::vector<long (*)(long)> flut92;
    auto lut92idx0 = [](long I) -> long {
        /* GATE 1 (LUT2 _071_ INIT 0xe PERM 01) */
        switch (I) {
            case  0: return 0;
            case  1: return 1;
            case  2: return 1;
            case  3: return 1;
            default: assert(0);
        };
    };
    lut92.push_back(ctx.genrate_lut(lut92idx0));
    flut92.push_back(lut92idx0);
    auto fvec92 = [flut92](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut92[i](I));
        return ret;
    };

    std::cerr << "\rLUT92   ";
    Ciphertext gin92 = 1 * gout85[0] + 2 * gout84[0];
    std::vector<Ciphertext> gout92 = ctx.eval_lut_amortized(&gin92, lut92);

    std::vector<RotationPoly> lut93;
    std::vector<long (*)(long)> flut93;
    auto lut93idx0 = [](long I) -> long {
        /* GATE 16 (LUT2 _086_ INIT 0x6 PERM 01) */
        switch (I) {
            case  0: return 0;
            case  1: return 1;
            case  2: return 1;
            case  3: return 0;
            default: assert(0);
        };
    };
    lut93.push_back(ctx.genrate_lut(lut93idx0));
    flut93.push_back(lut93idx0);
    auto fvec93 = [flut93](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut93[i](I));
        return ret;
    };

    std::cerr << "\rLUT93   ";
    Ciphertext gin93 = 1 * gout90[0] + 2 * gout73[0];
    std::vector<Ciphertext> gout93 = ctx.eval_lut_amortized(&gin93, lut93);

    std::vector<RotationPoly> lut94;
    std::vector<long (*)(long)> flut94;
    auto lut94idx0 = [](long I) -> long {
        /* GATE 14 (LUT2 _084_ INIT 0x6 PERM 01) */
        switch (I) {
            case  0: return 0;
            case  1: return 1;
            case  2: return 1;
            case  3: return 0;
            default: assert(0);
        };
    };
    lut94.push_back(ctx.genrate_lut(lut94idx0));
    flut94.push_back(lut94idx0);
    auto fvec94 = [flut94](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut94[i](I));
        return ret;
    };

    std::cerr << "\rLUT94   ";
    Ciphertext gin94 = 1 * gout86[0] + 2 * gout68[0];
    std::vector<Ciphertext> gout94 = ctx.eval_lut_amortized(&gin94, lut94);

    std::vector<RotationPoly> lut95;
    std::vector<long (*)(long)> flut95;
    auto lut95idx0 = [](long I) -> long {
        /* GATE 20 (LUT2 _090_ INIT 0x6 PERM 01) */
        switch (I) {
            case  0: return 0;
            case  1: return 1;
            case  2: return 1;
            case  3: return 0;
            default: assert(0);
        };
    };
    lut95.push_back(ctx.genrate_lut(lut95idx0));
    flut95.push_back(lut95idx0);
    auto fvec95 = [flut95](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut95[i](I));
        return ret;
    };

    std::cerr << "\rLUT95   ";
    Ciphertext gin95 = 1 * gout87[0] + 2 * gout78[0];
    std::vector<Ciphertext> gout95 = ctx.eval_lut_amortized(&gin95, lut95);

    std::vector<RotationPoly> lut96;
    std::vector<long (*)(long)> flut96;
    auto lut96idx0 = [](long I) -> long {
        /* GATE 22 (LUT2 _092_ INIT 0x6 PERM 01) */
        switch (I) {
            case  0: return 0;
            case  1: return 1;
            case  2: return 1;
            case  3: return 0;
            default: assert(0);
        };
    };
    lut96.push_back(ctx.genrate_lut(lut96idx0));
    flut96.push_back(lut96idx0);
    auto fvec96 = [flut96](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut96[i](I));
        return ret;
    };

    std::cerr << "\rLUT96   ";
    Ciphertext gin96 = 1 * gout89[0] + 2 * gout80[0];
    std::vector<Ciphertext> gout96 = ctx.eval_lut_amortized(&gin96, lut96);

    std::vector<RotationPoly> lut97;
    std::vector<long (*)(long)> flut97;
    auto lut97idx0 = [](long I) -> long {
        /* GATE 18 (LUT2 _088_ INIT 0x6 PERM 01) */
        switch (I) {
            case  0: return 0;
            case  1: return 1;
            case  2: return 1;
            case  3: return 0;
            default: assert(0);
        };
    };
    lut97.push_back(ctx.genrate_lut(lut97idx0));
    flut97.push_back(lut97idx0);
    auto fvec97 = [flut97](long I) -> std::vector<long> {
        std::vector<long> ret;
        for (size_t i = 0; i < 1; ++i)
            ret.push_back(flut97[i](I));
        return ret;
    };

    std::cerr << "\rLUT97   ";
    Ciphertext gin97 = 1 * gout88[0] + 2 * gout77[0];
    std::vector<Ciphertext> gout97 = ctx.eval_lut_amortized(&gin97, lut97);

    std::cerr << "\r          \r";
    std::vector<long> test_out;
    test_out.push_back(ctx.decrypt(&gout43[0])); /* out0 */
    test_out.push_back(ctx.decrypt(&gout92[0])); /* out1 */
    test_out.push_back(ctx.decrypt(&gout91[0])); /* out2 */
    test_out.push_back(ctx.decrypt(&gout94[0])); /* out3 */
    test_out.push_back(ctx.decrypt(&gout93[0])); /* out4 */
    test_out.push_back(ctx.decrypt(&gout97[0])); /* out5 */
    test_out.push_back(ctx.decrypt(&gout95[0])); /* out6 */
    test_out.push_back(ctx.decrypt(&gout96[0])); /* out7 */
    return test_out;
}

static void
BM_image_ricker_lut2fa(benchmark::State& state)
{
    FHEContext ctx;
    ctx.generate_context(tfhe_11_NTT);
    ctx.set_default_message_encoding_type(partial_domain);
    ctx.set_default_plaintext_space(4);

    for (auto _ : state) {
        test_image_ricker_lut2fa(ctx);
    }
}

BENCHMARK(BM_image_ricker_lut2fa)->Unit(benchmark::kSecond);
BENCHMARK_MAIN();