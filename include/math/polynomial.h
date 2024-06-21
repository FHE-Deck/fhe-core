#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <memory> 
#include "enums.h"
#include "utils.h"  


#include <NTL/ZZX.h>
#include <NTL/ZZ_pX.h>
#include <NTL/ZZ_p.h>

#include "fft_plan.h"
#include "hexl/hexl.hpp"  
#include <cereal/archives/binary.hpp>
#include <cereal/types/base_class.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/types/polymorphic.hpp>

namespace fhe_deck{
      
// Forward declaration if the Polynomial class and PolynomialEvalForm class that used by all other classes.
// Both are defined in this file.
class Polynomial; 
class PolynomialEvalForm;

// Forward declarations of PolynomialArrayCoefForm and PolynomialArrayEvalForm classes, as these classes refer to each other.
class PolynomialArrayCoefForm;
class PolynomialArrayEvalForm;




class PolynomialMultiplicationEngine{

    public: 

    PolynomialArithmetic type;

    virtual PolynomialEvalForm* init_polynomial_eval_form() = 0;

    virtual PolynomialArrayEvalForm* init_polynomial_array_eval_form(int32_t array_size) = 0;
  
    virtual void to_eval(PolynomialEvalForm *out, Polynomial *in) = 0; 

    virtual void to_eval(PolynomialArrayEvalForm *out, PolynomialArrayCoefForm *in) = 0;
  
    virtual void to_coef(Polynomial *out, PolynomialEvalForm *in) = 0; 

    virtual void to_coef(PolynomialArrayCoefForm *out, PolynomialArrayEvalForm *in) = 0;

    virtual void mul(PolynomialEvalForm *out, PolynomialEvalForm *in_1, PolynomialEvalForm *in_2) = 0;
 
    virtual void mul(Polynomial *out, Polynomial *in_1,  Polynomial *in_2); 
   
    virtual void multisum(Polynomial *out, PolynomialArrayCoefForm *in_1, PolynomialArrayEvalForm *in_2) = 0;

    virtual void multisum(Polynomial *out, PolynomialArrayEvalForm *in_1, PolynomialArrayEvalForm *in_2) = 0;
 
    virtual void multisum(Polynomial *out_multisum, PolynomialArrayEvalForm *out_in_1_eval, PolynomialArrayCoefForm *in_1, PolynomialArrayEvalForm *in_2) = 0;
 
};
 
 
class PolynomialEvalForm{

    public:
 
    int32_t size;
    int64_t coef_modulus;
 
    virtual ~PolynomialEvalForm() = default;

    virtual void zeroize() = 0;

    /// TODO: The thing with this modulus reduction is weird and not necessarily true. In NTT there is modulus reduction.

    /// NOTE: There is no modulus reduction here
    virtual void add(PolynomialEvalForm *out, PolynomialEvalForm *other) = 0;
    /// NOTE: There is no modulus reduction here
    virtual void sub(PolynomialEvalForm *out, PolynomialEvalForm *other) = 0;
    /// NOTE: There is no modulus reduction here
    virtual void mul(PolynomialEvalForm *out, int64_t scalar) = 0; 
    /// NOTE: There is no modulus reduction here
    virtual void neg(PolynomialEvalForm *out) = 0; 

    /// TODO: Annother issue with this mod_reduce is its inconsistent, with the style as it should have on output.
    virtual void mod_reduce(int64_t Q) = 0;
};

class PolynomialEvalFormLongInteger : public PolynomialEvalForm{

    public:
  
    int64_t* eval_long; 
    bool is_init = false;

    ~PolynomialEvalFormLongInteger();

    PolynomialEvalFormLongInteger(int64_t* eval_long, int32_t size, int64_t coef_modulus);

    void zeroize();

    void add(PolynomialEvalForm *out, PolynomialEvalForm *other);

    void sub(PolynomialEvalForm *out, PolynomialEvalForm *other);

    void mul(PolynomialEvalForm *out, int64_t scalar);

    void neg(PolynomialEvalForm *out);

    void mod_reduce(int64_t Q); 
};

class PolynomialEvalFormFFTWComplex : public PolynomialEvalForm{

    public:
 
    fftw_complex* eval_fftw;
    bool is_init = false;

    ~PolynomialEvalFormFFTWComplex();	

    PolynomialEvalFormFFTWComplex(fftw_complex* eval_fftw, int32_t size, int64_t coef_modulus);

    void zeroize();

    void add(PolynomialEvalForm *out, PolynomialEvalForm *other);

    void sub(PolynomialEvalForm *out, PolynomialEvalForm *other);

    void mul(PolynomialEvalForm *out, int64_t scalar);

    void neg(PolynomialEvalForm *out);

    void mod_reduce(int64_t Q); 
};

class PolynomialEvalFormFFTWLongComplex : public PolynomialEvalForm{

    public:
 
    fftwl_complex* eval_fftwl;
    bool is_init = false;

    ~PolynomialEvalFormFFTWLongComplex();	

    PolynomialEvalFormFFTWLongComplex(fftwl_complex* eval_fftwl, int32_t size, int64_t coef_modulus);

    void zeroize();

    void add(PolynomialEvalForm *out, PolynomialEvalForm *other);

    void sub(PolynomialEvalForm *out, PolynomialEvalForm *other);

    void mul(PolynomialEvalForm *out, int64_t scalar);

    void neg(PolynomialEvalForm *out);

    void mod_reduce(int64_t Q); 
};

class PolynomialInversionEngine{

    public: 
    
    PolynomialInversionEngineType type;

    virtual void inv(Polynomial *out, Polynomial &in) = 0;
 
};
 
class Polynomial{

    public:

    int64_t* coefs;
    bool is_init = false;

    // Coefficient Modulus Q
    int64_t coef_modulus;
    int32_t coef_modulus_bit_size;
    // Degree
    int32_t degree;

    std::shared_ptr<PolynomialMultiplicationEngine> mul_engine;
    bool is_mul_engine_set = false;
   
    std::shared_ptr<PolynomialInversionEngine> inv_engine;
    bool is_inv_engine_set = false;

    ~Polynomial();
    
    Polynomial() = default;

    Polynomial(int32_t degree, int64_t coef_modulus);
  
    Polynomial(int32_t degree, int64_t coef_modulus, std::shared_ptr<PolynomialMultiplicationEngine> mul_engine);

    Polynomial(int32_t degree, int64_t coef_modulus, std::shared_ptr<PolynomialInversionEngine> inv_engine);

    Polynomial(int32_t degree, int64_t coef_modulus, std::shared_ptr<PolynomialMultiplicationEngine> mul_engine, std::shared_ptr<PolynomialInversionEngine> inv_engine);

    void init(int32_t degree, int64_t coef_modulus);
  
    Polynomial(const Polynomial &other);

    Polynomial& operator=(const Polynomial other);

    void set_multiplication_engine(std::shared_ptr<PolynomialMultiplicationEngine> mul_engine);

    void set_inversion_engine(std::shared_ptr<PolynomialInversionEngine> inv_engine);
 
    void to_eval(PolynomialEvalForm *out);
   
    void zeroize();

    Polynomial clone();

    void cyclic_rotate(Polynomial *out, int64_t rotation);

    void negacyclic_rotate(Polynomial *out, int64_t rotation);

    void add(Polynomial *out, Polynomial *other);

    void add_coef(Polynomial *out, Polynomial *other);

    void sub(Polynomial *out, Polynomial *other);

    void sub_coef(Polynomial *out, Polynomial *other);

    void neg(Polynomial *out);

    void neg_coef(Polynomial *out);

    void mul(Polynomial *out, int64_t scalar);

    void mul(Polynomial *out, Polynomial *other);

    void mul(Polynomial *out, Polynomial *other, std::shared_ptr<PolynomialMultiplicationEngine> mul_engine);

    void inv(Polynomial *out);

    void inv(Polynomial *out, std::shared_ptr<PolynomialInversionEngine> inv_engine); 

    template <class Archive>
    void save( Archive & ar ) const
    { 
        ar(coef_modulus, degree);   
        ar(cereal::binary_data(coefs, sizeof(int64_t) * degree));  
    }
        
    template <class Archive>
    void load( Archive & ar )
    {  
        ar(coef_modulus, degree); 
        init(degree, coef_modulus);   
        ar(cereal::binary_data(coefs, sizeof(int64_t) * degree));   
    }  
};
   
class PolynomialArrayCoefForm{

    public:

    // This is a pointer to a 1d array of coefficients, that stores a 1d array of polynomials
    // The array will be initialized as new int64_t[size * degree]
    int64_t* poly_array;
    bool is_init = false;
  
    // Coefficient Modulus Q
    int64_t coef_modulus;
    // Degree
    int32_t degree;
    // Size of the array
    int32_t array_size;

    // full_size = degree * array_size. Initialized in the constructors. 
    int32_t full_size;
 
    std::shared_ptr<PolynomialMultiplicationEngine> mul_engine;
    bool is_mul_engine_set = false;
  
    ~PolynomialArrayCoefForm();

    PolynomialArrayCoefForm() = default;

    PolynomialArrayCoefForm(int32_t degree, int64_t coef_modulus, int32_t array_size);
  
    PolynomialArrayCoefForm(int32_t degree, int64_t coef_modulus, int32_t array_size, std::shared_ptr<PolynomialMultiplicationEngine> mul_engine);
  
    void init(int32_t degree, int64_t coef_modulus, int32_t array_size);
 
    PolynomialArrayCoefForm(const PolynomialArrayCoefForm &other);

    PolynomialArrayCoefForm& operator=(const PolynomialArrayCoefForm other);

    void set_multiplication_engine(std::shared_ptr<PolynomialMultiplicationEngine> mul_engine);
  
    void set_polynomial_at(int32_t i, Polynomial *poly); 
 
    void add(PolynomialArrayCoefForm *out, PolynomialArrayCoefForm *other);
  
    void sub(PolynomialArrayCoefForm *out, PolynomialArrayCoefForm *other);
  
    void neg(PolynomialArrayCoefForm *out);
  
    void mul(PolynomialArrayCoefForm *out, int64_t scalar);

    template <class Archive>
    void save( Archive & ar ) const
    { 
        ar(coef_modulus, degree, array_size);   
        ar(cereal::binary_data(poly_array, sizeof(int64_t) * full_size));  
    }
        
    template <class Archive>
    void load( Archive & ar )
    {  
        ar(coef_modulus, degree, array_size);   
        full_size = degree * array_size;
        ar(cereal::binary_data(poly_array, sizeof(int64_t) * full_size));  
        is_init = true;
    } 
     
};


class PolynomialArrayEvalForm{

    public: 

    // Refers to the number of polynomials in the array
    int32_t array_size;
    // Referse to the size of the evaluation form.
    // May differ from the degree of the polynomial (e.g. due to padding)
    int32_t size;

    // full_size = size * array_size
    int32_t full_size;

    int64_t coef_modulus;
    
    virtual ~PolynomialArrayEvalForm() = default; 
  
    // NOTE: There is no modulus reduction here
    virtual void add(PolynomialArrayEvalForm *out, PolynomialArrayEvalForm *other) = 0;
    // NOTE: There is no modulus reduction here
    virtual void sub(PolynomialArrayEvalForm *out, PolynomialArrayEvalForm *other) = 0;
    // NOTE: There is no modulus reduction here
    virtual void mul(PolynomialArrayEvalForm *out, int64_t scalar) = 0;
 
    // NOTE: There is no modulus reduction here
    virtual void neg(PolynomialArrayEvalForm *out) = 0;

    virtual void mod_reduce(int64_t modulus) = 0;   
   
    template <class Archive>
    void save( Archive & ar ) const
    { 
        ar(coef_modulus, size, array_size);  
    }
        
    template <class Archive>
    void load( Archive & ar )
    {  
        ar(coef_modulus, size, array_size);   
        full_size = size * array_size;
    }    

};


class PolynomialArrayEvalFormLong: public PolynomialArrayEvalForm{

    public:
 
    int64_t* eval_long; 

    bool is_init = false; 

    ~PolynomialArrayEvalFormLong();

    PolynomialArrayEvalFormLong() = default;
 
    PolynomialArrayEvalFormLong(int32_t array_size, int64_t degree, int64_t coef_modulus);
  
    // NOTE: There is no modulus reduction here
    void add(PolynomialArrayEvalForm *out, PolynomialArrayEvalForm *other);
    // NOTE: There is no modulus reduction here
    void sub(PolynomialArrayEvalForm *out, PolynomialArrayEvalForm *other);
    // NOTE: There is no modulus reduction here
    void mul(PolynomialArrayEvalForm *out, int64_t scalar); 
    // NOTE: There is no modulus reduction here
    void neg(PolynomialArrayEvalForm *out);

    void mod_reduce(int64_t modulus); 

    template <class Archive>
    void save( Archive & ar ) const
    { 
        ar(cereal::base_class<PolynomialArrayEvalForm>(this));     
        ar(cereal::binary_data(eval_long, sizeof(int64_t) * full_size));  
    }
        
    template <class Archive>
    void load( Archive & ar )
    {  
        ar(cereal::base_class<PolynomialArrayEvalForm>(this));  
        full_size = size * array_size;
        this->eval_long = new int64_t[full_size];
        ar(cereal::binary_data(eval_long, sizeof(int64_t) * full_size));  
        is_init = true;
    }    

};

class PolynomialArrayEvalFormFFTWComplex: public PolynomialArrayEvalForm{

    public:
 
    fftw_complex* eval_fftw; 

    bool is_init = false; 
 
    ~PolynomialArrayEvalFormFFTWComplex();

    PolynomialArrayEvalFormFFTWComplex() = default;

    PolynomialArrayEvalFormFFTWComplex(int32_t size, int32_t array_size);
  
    // NOTE: There is no modulus reduction here
    void add(PolynomialArrayEvalForm *out, PolynomialArrayEvalForm *other);
    // NOTE: There is no modulus reduction here
    void sub(PolynomialArrayEvalForm *out, PolynomialArrayEvalForm *other);
    // NOTE: There is no modulus reduction here
    void mul(PolynomialArrayEvalForm *out, int64_t scalar); 
    // NOTE: There is no modulus reduction here
    void neg(PolynomialArrayEvalForm *out);

    void mod_reduce(int64_t modulus); 

    template <class Archive>
    void save( Archive & ar ) const
    { 
        ar(cereal::base_class<PolynomialArrayEvalForm>(this));     
        ar(cereal::binary_data(eval_fftw, sizeof(fftw_complex) * full_size));  
    }
        
    template <class Archive>
    void load( Archive & ar )
    {  
        ar(cereal::base_class<PolynomialArrayEvalForm>(this));    
        full_size = size * array_size;
        eval_fftw = new fftw_complex[full_size];
        ar(cereal::binary_data(eval_fftw, sizeof(fftw_complex) * full_size));  
        is_init = true;
    }    

};

class PolynomialArrayEvalFormFFTWLongComplex: public PolynomialArrayEvalForm{

    public:
  
    fftwl_complex* eval_fftwl; 

    bool is_init = false; 

    ~PolynomialArrayEvalFormFFTWLongComplex();

    PolynomialArrayEvalFormFFTWLongComplex() = default;
 
    PolynomialArrayEvalFormFFTWLongComplex(int32_t size, int32_t array_size);
  
    // NOTE: There is no modulus reduction here
    void add(PolynomialArrayEvalForm *out, PolynomialArrayEvalForm *other);
    // NOTE: There is no modulus reduction here
    void sub(PolynomialArrayEvalForm *out, PolynomialArrayEvalForm *other);
    // NOTE: There is no modulus reduction here
    void mul(PolynomialArrayEvalForm *out, int64_t scalar);
 
    // NOTE: There is no modulus reduction here
    void neg(PolynomialArrayEvalForm *out);

    void mod_reduce(int64_t modulus); 

    template <class Archive>
    void save( Archive & ar ) const
    { 

        ar(cereal::base_class<PolynomialArrayEvalForm>(this));    
        ar(cereal::binary_data(eval_fftwl, sizeof(fftwl_complex) * full_size));  
    }
        
    template <class Archive>
    void load( Archive & ar )
    {  
        ar(cereal::base_class<PolynomialArrayEvalForm>(this));    
        full_size = size * array_size;
        eval_fftwl = new fftwl_complex[full_size];
        ar(cereal::binary_data(eval_fftwl, sizeof(fftwl_complex) * full_size));  
        is_init = true;
    }    
};


} 

CEREAL_REGISTER_TYPE(fhe_deck::PolynomialArrayEvalFormLong)
CEREAL_REGISTER_TYPE(fhe_deck::PolynomialArrayEvalFormFFTWComplex)
CEREAL_REGISTER_TYPE(fhe_deck::PolynomialArrayEvalFormFFTWLongComplex)
 
 

#endif