#include "ginx_blind_rotation.h"

using namespace fhe_deck;
  
 

GINXBlindRotationKey::GINXBlindRotationKey(std::shared_ptr<GadgetVectorCTSK> gadget_sk, std::shared_ptr<LWESK> lwe_sk){ 
    this->lwe_par = lwe_sk->param;   
    //this->next_acc = gadget_sk->vector_ct_param->init_ct(gadget_sk->vector_ct_param);
    this->vector_ct_param = gadget_sk->vector_ct_param;

    // The follwing code may be sensitive. Especially ext_s and the question of its removal from memory.
    std::shared_ptr<uint64_t[]> ext_s;
    ext_s = std::unique_ptr<uint64_t[]>(this->init_binary_extended_lwe_key(lwe_sk));  
    blind_rotation_key_gen(gadget_sk, ext_s);  
}
  
void GINXBlindRotationKey::blind_rotate(VectorCT* out, LWECT* lwe_ct_in, std::shared_ptr<VectorCTAccumulator> acc){    
    std::unique_ptr<VectorCT> next_acc(this->vector_ct_param->init_ct(vector_ct_param));
    acc->acc_content->homomorphic_rotate(out, lwe_ct_in->ct[0]);     
    for(int32_t i = 0; i < lwe_par->dim; ++i){    
        out->homomorphic_rotate(next_acc.get(), lwe_ct_in->ct[i+1]);   
        next_acc->sub(next_acc.get(), out);      
        bk[i]->mul(next_acc.get(), next_acc.get());    
        next_acc->add(out, out); 
    }   
}
   
void GINXBlindRotationKey::blind_rotation_key_gen(std::shared_ptr<GadgetVectorCTSK> rlwe_gadget_sk, std::shared_ptr<uint64_t[]> ext_s){
    std::unique_ptr<uint64_t[]> msg(new uint64_t[1]);
    for(int32_t i = 0; i < lwe_par->dim; ++i){    
        msg[0] = ext_s[i]; 
        bk.push_back(std::unique_ptr<GadgetVectorCT>(rlwe_gadget_sk->gadget_encrypt(msg.get(), 1)));
    }      
}

uint64_t* GINXBlindRotationKey::init_binary_extended_lwe_key(std::shared_ptr<LWESK> lwe_sk){
        //sizeof_ext_s = lwe_par->dim;
        uint64_t* ext_s = new uint64_t[lwe_par->dim];
        for(int32_t i = 0; i < lwe_par->dim; ++i){
            ext_s[i] = lwe_sk->key[i];
        } 
        return ext_s;
}

uint64_t* GINXBlindRotationKey::init_ternary_extended_lwe_key(std::shared_ptr<LWESK> lwe_sk){
        //sizeof_ext_s = lwe_par->dim;
        uint64_t*  ext_s = new uint64_t[lwe_par->dim];
        for(int32_t i = 0; i < lwe_par->dim; ++i){
            ext_s[i] = lwe_sk->key[i];
        } 
        return ext_s;
}

 