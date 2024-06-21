
#ifndef VECTOR_CIPHERTEXT_H
#define VECTOR_CIPHERTEXT_H

#include <memory>

namespace fhe_deck{

class VectorCT;

class VectorCTParam{
    public:
    // The size of the vector
    int32_t size; 
    // Initiates a VectorCT object which is not necessarily decryptable. its for allocating space.
    virtual VectorCT* init_ct(std::shared_ptr<VectorCTParam> param) = 0;

    template <class Archive>
    void save( Archive & ar ) const {}
        
    template <class Archive>
    void load( Archive & ar ) {} 
};

class VectorCT{

    public:   
  
    virtual ~VectorCT() = default;
    // Rotates the plaintext within the ciphertext without affecting its decryptability
    // Note that this isn't necessarily a cyclic rotation. It's up to the implementation how the rotation is done.
    virtual void homomorphic_rotate(VectorCT *out, int32_t rot) = 0;

    virtual void add(VectorCT *out,  VectorCT *ct) = 0;
    
    virtual void sub(VectorCT *out, VectorCT *ct) = 0;
  
    virtual void neg(VectorCT *out) = 0; 

    template <class Archive>
    void save( Archive & ar ) const {}
        
    template <class Archive>
    void load( Archive & ar ) {} 
};
 
class GadgetVectorCT{

    public: 

    virtual ~GadgetVectorCT() = default;

    virtual void mul(VectorCT *out, const VectorCT *ct) = 0;

    template <class Archive>
    void save( Archive & ar ) const {}
        
    template <class Archive>
    void load( Archive & ar ) {} 
};

class GadgetVectorCTSK{

    public: 

    std::shared_ptr<VectorCTParam> vector_ct_param;

    /// Encrypt the input msg array
    virtual GadgetVectorCT* gadget_encrypt(uint64_t *msg, int32_t size) = 0; 
    /// Encrypts the polynomials coefficients
    virtual GadgetVectorCT* gadget_encrypt(Polynomial *msg) = 0;  

    template <class Archive>
    void save( Archive & ar ) const {}
        
    template <class Archive>
    void load( Archive & ar ) {} 
};

}

#endif