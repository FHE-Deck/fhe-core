
#include "../include/rlwe_hom_acc_scheme_gen.h"


rlwe_hom_acc_scheme_gen::~rlwe_hom_acc_scheme_gen(){
    delete[] u;
    delete[] ext_s;
}


rlwe_hom_acc_scheme_gen::rlwe_hom_acc_scheme_gen(){}


rlwe_hom_acc_scheme_gen::rlwe_hom_acc_scheme_gen(rlwe_gadget_param rlwe_gadget_par, lwe_gadget_param lwe_gadget_par){
    rlwe_sk rlwe(rlwe_gadget_par.param);
    this->rlwe_gadget =  gadget_rlwe_sk(rlwe_gadget_par, rlwe);
    lwe_sk g_lwe = lwe_sk(lwe_gadget_par.lwe_par);
    this->lwe_gadget = lwe_gadget_sk(lwe_gadget_par, g_lwe);

    // For now we support only cyclic rings here
    long q = rlwe_gadget_par.param.N * 2; 
    this->lwe = lwe_gadget.lwe.modulus_switch(q);   
    // Another LWE for the extracted 
    // It should be based on the RLWE secret key!!!
    lwe_param extract_lwe_par = lwe_param(rlwe_gadget_par.param.N, rlwe_gadget_par.param.Q, lwe_gadget.lwe_g_par.lwe_par.key_d, lwe_gadget.lwe_g_par.lwe_par.stddev);
    long* extract_key = extract_rlwe_key();
    extract_lwe = lwe_sk(extract_lwe_par, extract_key); 

    // TODO: Need a second LWE for functional bootstrapping!!!
    if(lwe_gadget.lwe_g_par.lwe_par.key_d == binary){   
        this->init_binary_key(); 
    }else{  
        this->init_ternary_key();
    }   
    delete[] extract_key;
}



rlwe_hom_acc_scheme* rlwe_hom_acc_scheme_gen::get_public_param(){
    // The key switching key
    long ***ksk = key_switching_key_gen();
    // The blind rotation key
    rlwe_gadget_ct *bk = blind_rotation_key_gen();
    return new rlwe_hom_acc_scheme(rlwe_gadget.gadget_param, lwe_gadget.lwe_g_par, lwe.lwe_par, bk, ksk);
}


long* rlwe_hom_acc_scheme_gen::extract_rlwe_key(){ 
    long* key = new long[rlwe_gadget.gadget_param.param.N];
    for(int i = 0; i < rlwe_gadget.gadget_param.param.N; ++i){
        key[i] = -rlwe_gadget.sk.s[i];
    }
    return key;
}


void rlwe_hom_acc_scheme_gen::init_binary_key(){
        sizeof_u = 1;
        this->u = new long[sizeof_u];
        u[0] = 1;
        sizeof_ext_s = lwe.lwe_par.n;
        this->ext_s = new long[sizeof_ext_s];
        for(int i = 0; i < lwe.lwe_par.n; ++i){
            this->ext_s[i] = lwe.s[i];
        }
}

void rlwe_hom_acc_scheme_gen::init_ternary_key(){
        sizeof_u = 1;
        this->u = new long[sizeof_u];
        u[0] = 1;
        sizeof_ext_s = lwe.lwe_par.n;
        this->ext_s = new long[sizeof_ext_s];
        for(int i = 0; i < lwe.lwe_par.n; ++i){
            this->ext_s[i] = lwe.s[i];
        }
}



long*** rlwe_hom_acc_scheme_gen::key_switching_key_gen(){ 
    // Initialize the key switching key
    long ***ksk = new long**[rlwe_gadget.gadget_param.param.N]; 
    for(int i = 0; i < rlwe_gadget.gadget_param.param.N; ++i){
        ksk[i] = new long*[lwe_gadget.lwe_g_par.ell];
        for(int j = 0; j < lwe_gadget.lwe_g_par.ell; ++j){ 
            ksk[i][j] = lwe_gadget.lwe_g_par.lwe_par.init_ct();
        }
    } 
    for(int i = 0; i < rlwe_gadget.gadget_param.param.N; ++i){  
        ksk[i] = lwe_gadget.gadget_encrypt(-rlwe_gadget.sk.s[i]);  
    } 
    return ksk;
}
    

rlwe_gadget_ct* rlwe_hom_acc_scheme_gen::blind_rotation_key_gen(){ 
    long *ext_key_mono = rlwe_gadget.gadget_param.param.init_zero_poly();
    rlwe_gadget_ct* bk = new rlwe_gadget_ct[sizeof_ext_s]; 
    for(int i = 0; i < sizeof_ext_s; ++i){
        ext_key_mono[0] = ext_s[i];    
        bk[i] = rlwe_gadget.gadget_encrypt_fft(ext_key_mono);
    } 
    delete[] ext_key_mono;
    return bk;
}




// This is a special way of encoding the lwe, so that we can immediately do a functional blind rotation
 long* rlwe_hom_acc_scheme_gen::scale_and_encrypt_initial_lwe(long m, int t){
     long* out = lwe.lwe_par.init_ct();
     scale_and_encrypt_initial_lwe(out, m, t);
     return out;
 }
    
    // This is a special way of encoding the lwe, so that we can immediately do a functional blind rotation
 void rlwe_hom_acc_scheme_gen::scale_and_encrypt_initial_lwe(long* ct, long m, int t){
    double scale = (double)lwe.lwe_par.Q/ (2 * t);
    long m_scaled =  (long)round((double)m*scale); 
    lwe.encrypt(ct, m_scaled);
 }





rlwe_hom_acc_scheme_named_param_generator::rlwe_hom_acc_scheme_named_param_generator(rlwe_hom_acc_scheme_named_param name){
    if(name == rlwe_hom_acc_scheme_C_11_B){
        init_rlwe_hom_acc_scheme_C_11_B();
    } else if(name == rlwe_hom_acc_scheme_C_12_B){
        init_rlwe_hom_acc_scheme_C_12_B();
    } else if(name == rlwe_hom_acc_scheme_small_test){
        init_rlwe_hom_acc_scheme_small_test();
    }else{
        std::cout << "No parameter set selected!" <<  std::endl;
    }
}
 

void rlwe_hom_acc_scheme_named_param_generator::generate_bootstapping_keys(){
    this->boot_sk = new rlwe_hom_acc_scheme_gen(rlwe_gadget_par, lwe_gadget_par); 
    this->boot = boot_sk->get_public_param(); 
} 



void rlwe_hom_acc_scheme_named_param_generator::init_rlwe_hom_acc_scheme_small_test(){
    // TODO: For now I just put some parameters for testing
    int N = 32;
    // 2**13
    long Q = 4096;
    double rlwe_stddev = 0;
    int rlwe_basis = 2;
    double stddev_simul = rlwe_basis;
    rlwe_param rlwe_par(negacyclic, N, Q, ternary, any, rlwe_stddev);
    rlwe_gadget_par = rlwe_gadget_param(rlwe_par, rlwe_basis, stddev_simul);
    
    int n = 10;
    int lwe_basis = 2;
    double lwe_stddev = 0;
    lwe_param lwe_par(n, Q, binary, lwe_stddev);
    lwe_gadget_par = lwe_gadget_param(lwe_par, lwe_basis); 
} 

void rlwe_hom_acc_scheme_named_param_generator::init_rlwe_hom_acc_scheme_C_11_B(){ 
    // 2**11
    int N = 2048;
    // 2**36
    long Q = 68719476736;
    double rlwe_stddev = 3.2;
    // 2**4
    int rlwe_basis = 16; 
    double stddev_simul = 2686.41;
    rlwe_param rlwe_par(negacyclic, N, Q, ternary, any, rlwe_stddev);
    rlwe_gadget_par = rlwe_gadget_param(rlwe_par, rlwe_basis, stddev_simul);
 
    // 2**9 + 430
    int n = 977;
    int lwe_basis = 2;
    // 2**(14)
    //double lwe_stddev = 16384;
    double lwe_stddev = 4096;
    lwe_param lwe_par(n, Q, binary, lwe_stddev);
    lwe_gadget_par = lwe_gadget_param(lwe_par, lwe_basis); 
} 


void rlwe_hom_acc_scheme_named_param_generator::init_rlwe_hom_acc_scheme_C_12_B(){ 
    // 2**12
    int N = 4096;
    // 2**36
    long Q = 68719476736;
    double rlwe_stddev = 3.2;
    // 2**4
    int rlwe_basis = 16; 
    double stddev_simul = 3790.1;
    rlwe_param rlwe_par(negacyclic, N, Q, ternary, any, rlwe_stddev);
    rlwe_gadget_par = rlwe_gadget_param(rlwe_par, rlwe_basis, stddev_simul);
 
    // 2**9 + 400
    int n = 977;
    int lwe_basis = 16;
    // 2**(14)
    double lwe_stddev = 16384;
    lwe_param lwe_par(n, Q, binary, lwe_stddev);
    lwe_gadget_par = lwe_gadget_param(lwe_par, lwe_basis); 
} 