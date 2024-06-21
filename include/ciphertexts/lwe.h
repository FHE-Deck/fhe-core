 
#ifndef LWE_H
#define LWE_H

#include <random>
#include <iostream> 
#include "utils.h"
#include "plaintext_encoding.h"
#include "polynomial_multiplication_engine_builder.h"

#include <cereal/archives/binary.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/types/vector.hpp>

namespace fhe_deck{

class LWEParam{

  public:  

  // LWE Dimension
  int32_t dim;
  // LWE Modulus
  int64_t modulus; 
  /// NOTE: Never explicitely used in FHE-Deck, but its required by cereal.
  LWEParam() = default;
 
  LWEParam(int32_t dim, int64_t modulus); 

   template<class Archive> 
   void serialize(Archive & ar) 
   { 
     ar(dim, modulus); 
   }   
};

class LWECT{
 
  public:
 
    std::shared_ptr<LWEParam> param;
 
    int64_t *ct;
    bool init = false;

    /// NOTE: Never explicitely used in FHE-Deck, but its required by cereal.
    LWECT() = default;

    ~LWECT();

    // Initializes the ciphertext with zeros (the actual initialization will be done in some encrypt)
    LWECT(std::shared_ptr<LWEParam> lwe_par);
  
    LWECT(const LWECT &c);
  
    LWECT& operator=(const LWECT other); 

    LWECT* clone();

    void mul(LWECT *out, int64_t scalar);

    void mul_lazy(LWECT *out, int64_t scalar); 

    void add(LWECT *out, LWECT *in); 

    void sub(LWECT *out, LWECT *in); 

    void add_lazy(LWECT* out, LWECT *in);  

    void add(LWECT* out, int64_t b); 

    void sub(LWECT* out, int64_t b);

    void neg(LWECT* out);
  
    template <class Archive>
    void save( Archive & ar ) const
    { 
      ar(param);  
      std::vector<int64_t> ct_arr; 
      for(int32_t i = 0; i < param->dim+1; ++i){
        ct_arr.push_back(ct[i]);
      }
      ar(ct_arr);
    }
        
    template <class Archive>
    void load( Archive & ar )
    {  
      ar(param);
      std::vector<int64_t> ct_arr;
      ar(ct_arr);
      ct = new int64_t[param->dim+1];
      for(int32_t i = 0; i < param->dim+1; ++i){
        ct[i] = ct_arr[i];
      }
      this->init = true;
    } 
};
 
class LWEModSwitcher{

  public:
  std::shared_ptr<LWEParam> from;
  std::shared_ptr<LWEParam> to;

  bool long_arithmetic = false;

  // Some precomputation
  int32_t ct_size;
  double Q_from;
  double Q_to;
  double temp; 
  // If we need larger precision
  long double long_Q_from;
  long double long_Q_to;
  long double long_temp; 

  LWEModSwitcher() = default;

  // Initializes the ciphertext with zeros (the actual initialization will be done in some encrypt)
  LWEModSwitcher(std::shared_ptr<LWEParam> from, std::shared_ptr<LWEParam> to);
   
  void switch_modulus(LWECT *out_ct, LWECT *in_ct);
};
 
class LWESK {
 
    public:  

    std::shared_ptr<LWEParam> param; 
    std::shared_ptr<Distribution> unif_dist; 
    std::shared_ptr<Distribution> error_dist;
    KeyDistribution key_type;
    double stddev;
    // Initialized in the constructors and freed in the destructor.
    int64_t *key; 

    std::unique_ptr<LongIntegerMultipler> multiplier;
    
    ~LWESK();
    /// NOTE: Never explicitely used in FHE-Deck, but its required by cereal.
    LWESK() = default;
  
    LWESK(std::shared_ptr<LWEParam> lwe_par, double stddev, KeyDistribution key_type);
  
    LWESK(std::shared_ptr<LWEParam> lwe_par, int64_t* key, double stddev, KeyDistribution key_type);
 
    LWESK(const LWESK &other);

    LWESK& operator=(const LWESK other);
 
    LWECT* encrypt(int64_t m);

    void encrypt(LWECT* ct, int64_t m); 
    
    LWECT* encode_and_encrypt(int64_t m, PlaintextEncoding encoding); 
    
    void encode_and_encrypt(LWECT* in, int64_t m, PlaintextEncoding encoding);
  
    int64_t partial_decrypt(LWECT *in); 

    int64_t decrypt(LWECT *ct, PlaintextEncoding encoding); 
   
    template <class Archive>
    void save( Archive & ar ) const
    { 
      ar(param);  
      std::vector<int64_t> s_arr; 
      for(int32_t i = 0; i < param->dim; ++i){
        s_arr.push_back(key[i]);
      }
      ar(s_arr, stddev, key_type);
    }
        
    template <class Archive>
    void load( Archive & ar )
    {  
      ar(param);
      std::vector<int64_t> s_arr;
      ar(s_arr, stddev, key_type);
      init(); 
      for(int32_t i = 0; i < param->dim; ++i){
        this->key[i] = s_arr[i];
      }   
    } 

    private:
    void init();
    void init_key();

};
    
class LWEGadgetCT{

  public: 
   
  int64_t base;
  int32_t digits;
  int32_t bits_base;  
  std::shared_ptr<LWEParam> lwe_param;
   
  std::unique_ptr<std::unique_ptr<LWECT>[]> ct_content;

  LWEGadgetCT() = default;
  
  LWEGadgetCT(std::shared_ptr<LWEParam> lwe_par, int64_t base);
  
  void gadget_mul(LWECT *out_ct, int64_t scalar); 

  void gadget_mul_lazy(LWECT *out_ct, int64_t scalar); 

    template <class Archive>
    void save( Archive & ar ) const
    { 
      ar(base, digits, bits_base, lwe_param);    
      for(int32_t i = 0; i < digits; ++i){
        ar(ct_content[i]);
      } 
    }
        
    template <class Archive>
    void load( Archive & ar )
    {  
      ar(base, digits, bits_base, lwe_param); 
      this->ct_content = std::unique_ptr<std::unique_ptr<LWECT>[]>(new std::unique_ptr<LWECT>[digits]); 
      for(int32_t i = 0; i < digits; ++i){
        ar(ct_content[i]);
      } 
    }  
};

class LWEGadgetSK{

  public: 
  
    std::shared_ptr<LWESK> lwe;

    int64_t base;
    int32_t digits;
    int32_t bits_base;  
    /// NOTE: Never explicitely used in FHE-Deck, but its required by cereal.
    LWEGadgetSK() = default;
  
    LWEGadgetSK(std::shared_ptr<LWESK> lwe, int64_t base);
  
    LWEGadgetSK(const LWEGadgetSK& other);

    LWEGadgetSK& operator=(const LWEGadgetSK other); 

    LWEGadgetCT* gadget_encrypt(int64_t m); 

    void gadget_encrypt(LWEGadgetCT*, int64_t m);
  
    template <class Archive>
    void save( Archive & ar ) const
    { 
      ar(lwe, base, digits, bits_base);  
    }
        
    template <class Archive>
    void load( Archive & ar )
    {  
      ar(lwe, base, digits, bits_base);  
    }    
};


class LWEPublicKey{

  public:
 
    double stddev; 
    int32_t size;  
    std::shared_ptr<Distribution> rand_masking;
   
    std::unique_ptr<std::unique_ptr<LWECT>[]> public_key_ptr;

    std::shared_ptr<LWEParam> param;
 
    LWEPublicKey() = default;

    LWEPublicKey(std::shared_ptr<LWESK> lwe_sk, int32_t key_size, double stddev);

    LWEPublicKey(const LWEPublicKey &other);
   
    LWEPublicKey& operator=(const LWEPublicKey other);
  
    void encrypt(LWECT* out, int64_t message);
  
    LWECT* encrypt(int64_t message);

    LWECT* ciphertext_of_zero();

    template <class Archive>
    void save( Archive & ar ) const
    { 
      ar(param, stddev, size);     
      for(int32_t i = 0; i < this->size; ++i){   
          ar(public_key_ptr[i]);  
      }   
    }
        
    template <class Archive>
    void load( Archive & ar )
    {  
      ar(param, stddev, size); 
      this->rand_masking = std::shared_ptr<Distribution>(new StandardRoundedGaussianDistribution(0, stddev));
      this->public_key_ptr = std::unique_ptr<std::unique_ptr<LWECT>[]>(new std::unique_ptr<LWECT>[size]); 
      for(int32_t i = 0; i < this->size; ++i){   
          ar(public_key_ptr[i]);  
      }   
    }    
    
};

}

#endif