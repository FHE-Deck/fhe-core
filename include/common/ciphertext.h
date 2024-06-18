#ifndef CIPHERTEXT_H
#define CIPHERTEXT_H

#include <iostream>
#include "lwe.h"
#include "enums.h"  
#include "plaintext_encoding.h" 
#include "polynomial.h"

namespace fhe_deck{
    
class FHEContext; // Forward declaration
 
/// TODO: Need to think about this interface first.
// Note that some ciphertexts may be packed, have Polynomial scalars, and some may not.
class LinearHomomorphicCiphertext{
    public:

    virtual void add(LinearHomomorphicCiphertext* out, int64_t b) = 0;

    virtual void add(LinearHomomorphicCiphertext* out, LinearHomomorphicCiphertext* in) = 0;

    virtual void sub(LinearHomomorphicCiphertext* out, int64_t b) = 0;

    virtual void sub(LinearHomomorphicCiphertext* out, LinearHomomorphicCiphertext* in) = 0;

    virtual void neg(LinearHomomorphicCiphertext* out) = 0;

    virtual void mul(LinearHomomorphicCiphertext* out, int64_t b) = 0;

    virtual LinearHomomorphicCiphertext* clone() = 0;
};

/// TODO: This also seems to collide a little with vector ciphertext
class LinearHomomorphicPolynomialCiphertext : LinearHomomorphicCiphertext{
    public:
    
    virtual void add(LinearHomomorphicCiphertext* out, Polynomial b) = 0;

    virtual void sub(LinearHomomorphicCiphertext* out, Polynomial b) = 0;

    virtual void mul(LinearHomomorphicCiphertext* out, Polynomial b) = 0;
    
};

class Ciphertext{

    public: 
 
        std::shared_ptr<LWECT> lwe_c;
        bool is_lwe_ct = false;

        bool is_init = false;
 
        PlaintextEncoding encoding;

        FHEContext* context;

        ~Ciphertext() = default;

        Ciphertext() = default;
  
        Ciphertext(std::shared_ptr<LWECT> lwe_c, PlaintextEncoding encoding, FHEContext* context);
 
        Ciphertext(const Ciphertext &c);

        Ciphertext(Ciphertext &other);
 
        Ciphertext& operator=(const Ciphertext other);
 
        void add(Ciphertext* ct);

        void sub(Ciphertext* ct) ;

        void mul(int64_t b);
  
        Ciphertext operator+(int64_t b);

        Ciphertext operator+(Ciphertext ct);

        Ciphertext operator-(int64_t b);

        Ciphertext operator-(Ciphertext ct);

        Ciphertext operator-();
    
        Ciphertext operator*(int64_t b); 
};
 
} /// End of namesapce fhe_deck
  
fhe_deck::Ciphertext operator+(int64_t b, fhe_deck::Ciphertext ct);

fhe_deck::Ciphertext operator-(int64_t b, fhe_deck::Ciphertext ct);

fhe_deck::Ciphertext operator*(int64_t b, fhe_deck::Ciphertext ct);

#endif