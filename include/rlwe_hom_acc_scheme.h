
#ifndef RLWE_HOM_ACC_SCHEME_H
#define RLWE_HOM_ACC_SCHEME_H
 
#include "lwe.h"
#include "rlwe.h"
#include "rlwe_param.h"  
 
class rlwe_hom_acc_scheme{

    public:
        
    rlwe_gadget_param rlwe_gadget_par; 

    // The blind rotation key
    rlwe_gadget_ct *bk;
    
    // The key switching key
    long ***ksk;
    lwe_gadget_param lwe_gadget_par;

    // LWE after modulus switching to 2*N;
    lwe_param lwe_par;

    // LWE after modulus switching to N
    lwe_param lwe_par_tiny;
    long* acc_msb;

    lwe_param extract_lwe_par;

    // Parameteres of the encoding of the LWE key in the blind rotation. These are paramters about the secret key of lwe_par (and lwe_g_par as lwe_par is a modulus switch of lwe_g_par)
    key_dist key_d;
    int sizeof_ext_s;
    long *u;
    int sizeof_u;

    ~rlwe_hom_acc_scheme();

    rlwe_hom_acc_scheme();

    // TODO: In ntrunium.h the key distribution (for the LWE gadget param) is given as input
    // But actually it should be in the corresponding LWE_param.
    rlwe_hom_acc_scheme(rlwe_gadget_param rlwe_gadget_par, lwe_gadget_param lwe_gadget_par, lwe_param lwe_par, rlwe_gadget_ct *bk, long ***ksk);

    void blind_rotate(rlwe_ct *out, long* lwe_ct_in, long *acc_msg, gadget_mul_mode mode);

    void extract_lwe_from_rlwe(long *lwe_ct_out, const rlwe_ct *rlwe_ct_in);

    void lwe_to_lwe_key_switch(long *lwe_ct_out, long *lwe_ct_in);
 
    void bootstrap(long *lwe_ct_out, long *acc_in, long *lwe_ct_in, gadget_mul_mode mode);
 
    void functional_bootstrap_initial(long *lwe_ct_out, long *acc_in, long *lwe_ct_in, gadget_mul_mode mode);

    void functional_bootstrap(long *lwe_ct_out, long *acc_in, long *lwe_ct_in, gadget_mul_mode mode, int t);
 
    static long* rot_identity(int t, long N, long Q); 

    static long* rot_msb(int t, long N, long Q); 

    static long* rot_uni_poly(int* poly, int poly_size, int t, long N, long Q);

    static long* rot_is_zero_of_poly(int* poly, int poly_size, int t, long N, long Q, int t_out);

    // NOTE: Remind that this is a special rotation polynomial, and is not going to work correctly with all bootstrappings
    static long* rot_is_zero(int t, long N, long Q);

    private:

    void init_binary_key();
    void init_ternary_key();

    // TODO: Put the static functions, that generate accumulators in some other file
 
};


#endif