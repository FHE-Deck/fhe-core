#include "polynomial.h"
 
using namespace fhe_deck;
 

void PolynomialMultiplicationEngine::mul(Polynomial *out, Polynomial *in_1, Polynomial *in_2){   
    PolynomialEvalForm* eval_in_1 = init_polynomial_eval_form();
    to_eval(eval_in_1, in_1);  
    PolynomialEvalForm* eval_in_2 = init_polynomial_eval_form();
    to_eval(eval_in_2, in_2); 
    PolynomialEvalForm* eval_out = init_polynomial_eval_form(); 
    mul(eval_out, eval_in_1, eval_in_2);  
    to_coef(out, eval_out); 
    delete eval_in_1;
    delete eval_in_2;
    delete eval_out;
}
  

  
PolynomialEvalFormLongInteger::~PolynomialEvalFormLongInteger(){
    if(is_init){
        delete[] eval_long;
    }
}

PolynomialEvalFormLongInteger::PolynomialEvalFormLongInteger(int64_t* eval_long, int32_t size, int64_t coef_modulus){
    this->eval_long = eval_long;
    this->coef_modulus = coef_modulus;
    this->is_init = true; 
    this->size = size;
}

void PolynomialEvalFormLongInteger::zeroize(){ 
    for(int32_t i = 0; i < size; ++i){
        this->eval_long[i] = 0;
    }
}

void PolynomialEvalFormLongInteger::add(PolynomialEvalForm *out, PolynomialEvalForm *other){ 
    PolynomialEvalFormLongInteger* other_cast = static_cast<PolynomialEvalFormLongInteger*>(other);
    PolynomialEvalFormLongInteger* out_cast = static_cast<PolynomialEvalFormLongInteger*>(out);
    for(int32_t i = 0; i < size; ++i){
        out_cast->eval_long[i] = this->eval_long[i] + other_cast->eval_long[i];
    }
}

void PolynomialEvalFormLongInteger::sub(PolynomialEvalForm *out, PolynomialEvalForm *other){
    PolynomialEvalFormLongInteger* other_cast = static_cast<PolynomialEvalFormLongInteger*>(other);
    PolynomialEvalFormLongInteger* out_cast = static_cast<PolynomialEvalFormLongInteger*>(out);
    for(int32_t i = 0; i < size; ++i){
        out_cast->eval_long[i] = this->eval_long[i] - other_cast->eval_long[i];
    }  
}

void PolynomialEvalFormLongInteger::mul(PolynomialEvalForm *out, int64_t scalar){
    PolynomialEvalFormLongInteger* out_cast = static_cast<PolynomialEvalFormLongInteger*>(out);
    for(int32_t i = 0; i < size; ++i){
        out_cast->eval_long[i] = this->eval_long[i] * scalar;
    } 
}
 
void PolynomialEvalFormLongInteger::neg(PolynomialEvalForm *out){
    PolynomialEvalFormLongInteger* out_cast = static_cast<PolynomialEvalFormLongInteger*>(out);
    for(int32_t i = 0; i < size; ++i){
        out_cast->eval_long[i] = -this->eval_long[i];
    } 
}
  

PolynomialEvalFormFFTWComplex::~PolynomialEvalFormFFTWComplex(){
    if(is_init){
        delete[] eval_fftw;
    }
}
 
PolynomialEvalFormFFTWComplex::PolynomialEvalFormFFTWComplex(fftw_complex* eval_fftw, int32_t size){
    this->eval_fftw = eval_fftw; 
    this->is_init = true; 
    this->size = size; 
}

void PolynomialEvalFormFFTWComplex::zeroize(){
    for(int32_t i = 0; i < size; ++i){
        this->eval_fftw[i][0] = 0;
        this->eval_fftw[i][1] = 0;
    }
}

void PolynomialEvalFormFFTWComplex::add(PolynomialEvalForm *out, PolynomialEvalForm *other){
    PolynomialEvalFormFFTWComplex* other_cast = static_cast<PolynomialEvalFormFFTWComplex*>(other);
    PolynomialEvalFormFFTWComplex* out_cast = static_cast<PolynomialEvalFormFFTWComplex*>(out);
    for(int32_t i = 0; i < size; ++i){
        out_cast->eval_fftw[i][0] = this->eval_fftw[i][0] + other_cast->eval_fftw[i][0];
        out_cast->eval_fftw[i][1] = this->eval_fftw[i][1] + other_cast->eval_fftw[i][1];
    } 
}

void PolynomialEvalFormFFTWComplex::sub(PolynomialEvalForm *out, PolynomialEvalForm *other){
    PolynomialEvalFormFFTWComplex* other_cast = static_cast<PolynomialEvalFormFFTWComplex*>(other);
    PolynomialEvalFormFFTWComplex* out_cast = static_cast<PolynomialEvalFormFFTWComplex*>(out);
    for(int32_t i = 0; i < size; ++i){
        out_cast->eval_fftw[i][0] = this->eval_fftw[i][0] - other_cast->eval_fftw[i][0];
        out_cast->eval_fftw[i][1] = this->eval_fftw[i][1] - other_cast->eval_fftw[i][1];
    } 
}

void PolynomialEvalFormFFTWComplex::mul(PolynomialEvalForm *out, int64_t scalar){
    PolynomialEvalFormFFTWComplex* out_cast = static_cast<PolynomialEvalFormFFTWComplex*>(out);
    for(int32_t i = 0; i < size; ++i){
        out_cast->eval_fftw[i][0] = this->eval_fftw[i][0] * scalar;
        out_cast->eval_fftw[i][1] = this->eval_fftw[i][1] * scalar;
    }  
}
 
void PolynomialEvalFormFFTWComplex::neg(PolynomialEvalForm *out){ 
    PolynomialEvalFormFFTWComplex* out_cast = static_cast<PolynomialEvalFormFFTWComplex*>(out);
    for(int32_t i = 0; i < size; ++i){
        out_cast->eval_fftw[i][0] = -this->eval_fftw[i][0];
        out_cast->eval_fftw[i][1] = -this->eval_fftw[i][1];
    } 
}
 

PolynomialEvalFormFFTWLongComplex::~PolynomialEvalFormFFTWLongComplex(){
    if(is_init){
        delete[] eval_fftwl;
    }
}
  
PolynomialEvalFormFFTWLongComplex::PolynomialEvalFormFFTWLongComplex(fftwl_complex* eval_fftwl, int32_t size){
    this->eval_fftwl = eval_fftwl; 
    this->is_init = true; 
    this->size = size; 
}

void PolynomialEvalFormFFTWLongComplex::zeroize(){
    for(int32_t i = 0; i < size; ++i){
        this->eval_fftwl[i][0] = 0;
        this->eval_fftwl[i][1] = 0;
    }
}

void PolynomialEvalFormFFTWLongComplex::add(PolynomialEvalForm *out, PolynomialEvalForm *other){
    PolynomialEvalFormFFTWLongComplex* other_cast = static_cast<PolynomialEvalFormFFTWLongComplex*>(other);
    PolynomialEvalFormFFTWLongComplex* out_cast = static_cast<PolynomialEvalFormFFTWLongComplex*>(out);
    for(int32_t i = 0; i < size; ++ i){
        out_cast->eval_fftwl[i][0] = this->eval_fftwl[i][0] + other_cast->eval_fftwl[i][0];
        out_cast->eval_fftwl[i][1] = this->eval_fftwl[i][1] + other_cast->eval_fftwl[i][1];
    }       
}
 
void PolynomialEvalFormFFTWLongComplex::sub(PolynomialEvalForm *out, PolynomialEvalForm *other){
    PolynomialEvalFormFFTWLongComplex* other_cast = static_cast<PolynomialEvalFormFFTWLongComplex*>(other);
    PolynomialEvalFormFFTWLongComplex* out_cast = static_cast<PolynomialEvalFormFFTWLongComplex*>(out);
    for(int32_t i = 0; i < size; ++i){
        out_cast->eval_fftwl[i][0] = this->eval_fftwl[i][0] - other_cast->eval_fftwl[i][0];
        out_cast->eval_fftwl[i][1] = this->eval_fftwl[i][1] - other_cast->eval_fftwl[i][1];
    } 
}

void PolynomialEvalFormFFTWLongComplex::mul(PolynomialEvalForm *out, int64_t scalar){
    PolynomialEvalFormFFTWLongComplex* out_cast = static_cast<PolynomialEvalFormFFTWLongComplex*>(out);
    for(int32_t i = 0; i < size; ++i){
            out_cast->eval_fftwl[i][0] = this->eval_fftwl[i][0] * scalar;
            out_cast->eval_fftwl[i][1] = this->eval_fftwl[i][1] * scalar;
        } 
}
 
void PolynomialEvalFormFFTWLongComplex::neg(PolynomialEvalForm *out){
    PolynomialEvalFormFFTWLongComplex* out_cast = static_cast<PolynomialEvalFormFFTWLongComplex*>(out);
    for(int32_t i = 0; i < size; ++i){
            out_cast->eval_fftwl[i][0] = -this->eval_fftwl[i][0];
            out_cast->eval_fftwl[i][1] = -this->eval_fftwl[i][1];
        } 
}
  
Polynomial::~Polynomial(){ 
    if(this->is_init){
        delete[] coefs; 
    } 
}

Polynomial::Polynomial(int32_t degree, int64_t coef_modulus){
    this->init(degree, coef_modulus);
}
 
Polynomial::Polynomial(int32_t degree, int64_t coef_modulus, std::shared_ptr<PolynomialMultiplicationEngine> mul_engine){
    this->init(degree, coef_modulus);
    this->mul_engine = mul_engine;
    is_mul_engine_set = true; 
}

Polynomial::Polynomial(int32_t degree, int64_t coef_modulus, std::shared_ptr<PolynomialInversionEngine> inv_engine){
    this->init(degree, coef_modulus);
    this->inv_engine = inv_engine;
    this->is_inv_engine_set = true;
}

Polynomial::Polynomial(int32_t degree, int64_t coef_modulus, std::shared_ptr<PolynomialMultiplicationEngine> mul_engine, std::shared_ptr<PolynomialInversionEngine> inv_engine){
    this->init(degree, coef_modulus);
    this->mul_engine = mul_engine;
    is_mul_engine_set = true; 
    this->inv_engine = inv_engine;
    this->is_inv_engine_set = true;
}

void Polynomial::init(int32_t degree, int64_t coef_modulus){
    this->degree = degree;
    this->coef_modulus = coef_modulus;
    this->coef_modulus_bit_size = Utils::power_times(coef_modulus, 2);
    this->coefs = new int64_t[degree];
    this->is_init = true;
}
 
Polynomial::Polynomial(const Polynomial &other){
    this->init(other.degree, other.coef_modulus); 
    Utils::cp(this->coefs, other.coefs, this->degree);  
    this->mul_engine = other.mul_engine;
    this->is_mul_engine_set = other.is_mul_engine_set; 
    this->inv_engine = other.inv_engine;
    this->is_inv_engine_set = other.is_inv_engine_set;
} 
  
Polynomial& Polynomial::operator=(const Polynomial other){
    if(!this->is_init){ 
        this->init(other.degree, other.coef_modulus);
    }
    Utils::cp(this->coefs, other.coefs, this->degree);  
    this->mul_engine = other.mul_engine;
    this->is_mul_engine_set = other.is_mul_engine_set; 
    this->inv_engine = other.inv_engine;
    this->is_inv_engine_set = other.is_inv_engine_set;
    return *this;
}
 
void Polynomial::set_multiplication_engine(std::shared_ptr<PolynomialMultiplicationEngine> mul_engine){
    this->mul_engine = mul_engine;
    this->is_mul_engine_set = true; 
}

void Polynomial::set_inversion_engine(std::shared_ptr<PolynomialInversionEngine> inv_engine){
    this->inv_engine = inv_engine;
    this->is_inv_engine_set = true; 
}

void Polynomial::cyclic_rotate(Polynomial *out, int64_t rotation){
    Utils::rotate_poly(out->coefs, this->coefs, this->degree, rotation);  
}

void Polynomial::negacyclic_rotate(Polynomial *out, int64_t rotation){   
    Utils::negacyclic_rotate_poly(out->coefs, this->coefs, this->degree, rotation);  
    Utils::array_mod_form(out->coefs, out->coefs, this->degree, this->coef_modulus);
}
 
void Polynomial::to_eval(PolynomialEvalForm *out){ 
    mul_engine->to_eval(out, this);
}
 
void Polynomial::zeroize(){
    for(int32_t i = 0; i < degree; ++i){
        coefs[i] = 0;
    }
}

 
Polynomial* Polynomial::clone(){
    if(!is_init){
        throw std::logic_error("Polynomial::clone: Polynomial is not initialized!");
    }
    Polynomial* out;
    if(is_mul_engine_set && is_inv_engine_set){
        out = new Polynomial(degree, coef_modulus, mul_engine, inv_engine);
    }else if(is_mul_engine_set){
        out = new Polynomial(degree, coef_modulus, mul_engine);
    }else if(is_inv_engine_set){
        out = new Polynomial(degree, coef_modulus, inv_engine);
    }else{
        out = new Polynomial(degree, coef_modulus);
    }
    Utils::cp(out->coefs, coefs, degree);
    out->is_init = true;
    return out;
} 
 
void Polynomial::add(Polynomial *out, Polynomial *other){
    if(this->degree != other->degree){
        throw std::logic_error("Polynomial::add: Both Polynomials must be the same size!");
    }
    if(this->coef_modulus != other->coef_modulus){
        throw std::logic_error("Polynomial::add: Both Polynomials must have the same coefficient modulus!");
    } 
    this->add_coef(out, other);  
}

void Polynomial::add_coef(Polynomial *out, Polynomial *other){
    for(int32_t i = 0; i < degree; ++i){
        out->coefs[i] = coefs[i] + other->coefs[i];
        out->coefs[i] %= this->coef_modulus;
    }
}


void Polynomial::sub(Polynomial *out, Polynomial *other){ 
    if(this->degree != other->degree){
        throw std::logic_error("Polynomial::add: Both Polynomials must be the same size!");
    }
    if(this->coef_modulus != other->coef_modulus){
        throw std::logic_error("Polynomial::add: Both Polynomials must have the same coefficient modulus!");
    }
    sub_coef(out, other);
}

void Polynomial::sub_coef(Polynomial *out, Polynomial *other){
    for(int32_t i = 0; i < degree; ++i){
        out->coefs[i] = this->coefs[i] - other->coefs[i];    
    }
    Utils::array_mod_form(out->coefs, out->coefs, degree, this->coef_modulus); 
}

void Polynomial::neg(Polynomial *out){
    neg_coef(out);  
}

void Polynomial::neg_coef(Polynomial *out){
    for(int32_t i = 0; i < degree; ++i){
        out->coefs[i] = -this->coefs[i];
    }
    Utils::array_mod_form(out->coefs, out->coefs, degree, this->coef_modulus); 
}

void Polynomial::mul(Polynomial *out, int64_t scalar){ 
    if(this->degree != out->degree){
        throw std::logic_error("Polynomial::mul(Polynomial *out, int64_t scalar): Degrees of polynomials don't match!");
    }
    if(this->coef_modulus != out->coef_modulus){
        throw std::logic_error("Polynomial::mul(Polynomial *out, int64_t scalar): Coefficient moduli of polynomials don't match!");
    } 
    int32_t scalar_bit_size = Utils::number_of_bits(scalar);
    if((scalar_bit_size + this->coef_modulus_bit_size) < 64){
        for(int32_t j=0; j < this->degree; ++j){ 
            out->coefs[j] = (this->coefs[j] * scalar) % this->coef_modulus;  
        }
    }else{
        /// TODO: The case where the scalar is bigger is handled by LongIntegerMultipler class in util.h. Use it here.
         // Note that we need to handle the case scalar is bigger. 
        int32_t free_bits = 63 - this->coef_modulus_bit_size;
        int64_t div = Utils::pow(free_bits, 2); 
        for(int32_t j=0; j < this->degree; ++j){  
            int64_t temp_scalar = scalar;
            while(temp_scalar > div){ 
                /// TODO: Make bit shift with free_bits instead of difision
                temp_scalar /= div; 
                out->coefs[j] = (this->coefs[j] * div) % this->coef_modulus;  
            }  
            out->coefs[j] = (this->coefs[j] * temp_scalar) % this->coef_modulus;   
        } 
    } 
}

void Polynomial::mul(Polynomial *out, Polynomial *other){   
    if(this->is_mul_engine_set){ 
        this->mul(out, other, this->mul_engine); 
    }else{
        throw std::logic_error("Polynomial::mul(Polynomial *out, Polynomial *other): No multiplication engin set!");
    }
}

void Polynomial::mul(Polynomial *out, Polynomial *other, std::shared_ptr<PolynomialMultiplicationEngine> mul_engine){  
    mul_engine->mul(out, this, other); 
}
  
void Polynomial::inv(Polynomial *out){
    this->inv_engine->inv(out, *this);
}

void Polynomial::inv(Polynomial *out, std::shared_ptr<PolynomialInversionEngine> inv_engine){
    inv_engine->inv(out, *this);
}
 
PolynomialArrayCoefForm::~PolynomialArrayCoefForm(){ 
    if(this->is_init){
        delete[] poly_array;
    } 
}

PolynomialArrayCoefForm::PolynomialArrayCoefForm(int32_t degree, int64_t coef_modulus, int32_t array_size){
    this->init(degree, coef_modulus, array_size);
}
 
PolynomialArrayCoefForm::PolynomialArrayCoefForm(int32_t degree, int64_t coef_modulus, int32_t array_size, std::shared_ptr<PolynomialMultiplicationEngine> mul_engine){ 
    this->init(degree, coef_modulus, array_size);
    this->mul_engine = mul_engine;
    is_mul_engine_set = true; 
}
  
void PolynomialArrayCoefForm::init(int32_t degree, int64_t coef_modulus, int32_t array_size){ 
    this->degree = degree;
    this->coef_modulus = coef_modulus;
    this->array_size = array_size; 
    this->full_size = this->array_size * this->degree; 
    this->poly_array = new int64_t[full_size];
    this->is_init = true; 
}
 
PolynomialArrayCoefForm::PolynomialArrayCoefForm(const PolynomialArrayCoefForm &other){
    this->init(other.degree, other.coef_modulus, other.array_size); 
    Utils::cp(this->poly_array, other.poly_array, this->full_size);  
    this->mul_engine = other.mul_engine;
    this->is_mul_engine_set = other.is_mul_engine_set;  
} 
  
PolynomialArrayCoefForm& PolynomialArrayCoefForm::operator=(const PolynomialArrayCoefForm other){
    this->init(other.degree, other.coef_modulus, other.array_size);
    Utils::cp(this->poly_array, other.poly_array, this->full_size);  
    this->mul_engine = other.mul_engine;
    this->is_mul_engine_set = other.is_mul_engine_set;  
    return *this;
}

void PolynomialArrayCoefForm::set_polynomial_at(int32_t i, Polynomial *poly){
    if(poly->degree != this->degree){
        throw std::logic_error("PolynomialArrayCoefForm::set_polynomial_at(int32_t i, Polynomial *poly): degrees are inconsistent.");
    }
    if(poly->coef_modulus != this->coef_modulus){
        throw std::logic_error("PolynomialArrayCoefForm::set_polynomial_at(int32_t i, Polynomial *poly): coef_moduli are inconsistent.");
    }
    for(int32_t j = 0; j < this->degree; ++j){
        this->poly_array[i * degree + j] = poly->coefs[j];
    }
}
  
void PolynomialArrayCoefForm::set_multiplication_engine(std::shared_ptr<PolynomialMultiplicationEngine> mul_engine){
    this->mul_engine = mul_engine;
}
  
void PolynomialArrayCoefForm::add(PolynomialArrayCoefForm *out, PolynomialArrayCoefForm *other){
    for(int32_t i = 0; i < full_size; ++i){
        out->poly_array[i] = poly_array[i] + other->poly_array[i];
        out->poly_array[i] %= this->coef_modulus;
    }
}
  
void PolynomialArrayCoefForm::sub(PolynomialArrayCoefForm *out, PolynomialArrayCoefForm *other){
    for(int32_t i = 0; i < full_size; ++i){
        out->poly_array[i] = this->poly_array[i] - other->poly_array[i];    
    }
    Utils::array_mod_form(out->poly_array, out->poly_array, full_size, this->coef_modulus); 
}
  
void PolynomialArrayCoefForm::neg(PolynomialArrayCoefForm *out){
    for(int32_t i = 0; i < full_size; ++i){
        out->poly_array[i] = -this->poly_array[i];
    }
    Utils::array_mod_form(out->poly_array, out->poly_array, full_size, this->coef_modulus); 
}
  
void PolynomialArrayCoefForm::mul(PolynomialArrayCoefForm *out, int64_t scalar){
    for(int32_t i = 0; i < full_size; ++i){
        out->poly_array[i] = poly_array[i] + scalar;
        out->poly_array[i] %= this->coef_modulus;
    }
}

PolynomialArrayEvalFormLong::~PolynomialArrayEvalFormLong(){
    if(this->is_init){
        delete[] eval_long;
    } 
}

PolynomialArrayEvalFormLong::PolynomialArrayEvalFormLong(int32_t array_size, int64_t degree, int64_t coef_modulus){
    this->array_size = array_size;
    this->size = degree;
    this->coef_modulus = coef_modulus;
    this->full_size = array_size * this->size;
    this->eval_long = new int64_t[full_size];
    this->is_init = true; 
}

void PolynomialArrayEvalFormLong::add(PolynomialArrayEvalForm *out, PolynomialArrayEvalForm *other){
    PolynomialArrayEvalFormLong* other_cast = static_cast<PolynomialArrayEvalFormLong*>(other);
    PolynomialArrayEvalFormLong* out_cast = static_cast<PolynomialArrayEvalFormLong*>(out);
    for(int32_t i = 0; i < full_size; ++i){
         out_cast->eval_long[i] = this->eval_long[i] + other_cast->eval_long[i];
    }
}

void PolynomialArrayEvalFormLong::sub(PolynomialArrayEvalForm *out, PolynomialArrayEvalForm *other){
    PolynomialArrayEvalFormLong* other_cast = static_cast<PolynomialArrayEvalFormLong*>(other);
    PolynomialArrayEvalFormLong* out_cast = static_cast<PolynomialArrayEvalFormLong*>(out);
    for(int32_t i = 0; i < full_size; ++i){
         out_cast->eval_long[i] = this->eval_long[i] - other_cast->eval_long[i];
    }
}


void PolynomialArrayEvalFormLong::mul(PolynomialArrayEvalForm *out, int64_t scalar){
    PolynomialArrayEvalFormLong* out_cast = static_cast<PolynomialArrayEvalFormLong*>(out); 
    for(int32_t i = 0; i < full_size; ++i){
        out_cast->eval_long[i] = this->eval_long[i] * scalar;
    }
}

void PolynomialArrayEvalFormLong::neg(PolynomialArrayEvalForm *out){
    PolynomialArrayEvalFormLong* out_cast = static_cast<PolynomialArrayEvalFormLong*>(out); 
    for(int32_t i = 0; i < full_size; ++i){
        out_cast->eval_long[i] = -this->eval_long[i];
    }
}

void PolynomialArrayEvalFormLong::mod_reduce(int64_t modulus){
    Utils::array_mod_form(this->eval_long, this->eval_long, full_size, modulus); 
}


PolynomialArrayEvalFormFFTWComplex::~PolynomialArrayEvalFormFFTWComplex(){
    if(this->is_init){
        delete[] eval_fftw;
    }
}   

PolynomialArrayEvalFormFFTWComplex::PolynomialArrayEvalFormFFTWComplex(int32_t size, int32_t array_size){ 
    this->array_size = array_size; 
    this->size = size; 
    this->full_size = this->size * array_size; 
    this->eval_fftw = new fftw_complex[full_size];   
    this->is_init = true;
}


void PolynomialArrayEvalFormFFTWComplex::add(PolynomialArrayEvalForm *out, PolynomialArrayEvalForm *other){
    PolynomialArrayEvalFormFFTWComplex* other_cast = static_cast<PolynomialArrayEvalFormFFTWComplex*>(other);
    PolynomialArrayEvalFormFFTWComplex* out_cast = static_cast<PolynomialArrayEvalFormFFTWComplex*>(out);
    for(int32_t i = 0; i < full_size; ++i){
            out_cast->eval_fftw[i][0] = this->eval_fftw[i][0] + other_cast->eval_fftw[i][0];
            out_cast->eval_fftw[i][1] = this->eval_fftw[i][1] + other_cast->eval_fftw[i][1];
        } 
}

void PolynomialArrayEvalFormFFTWComplex::sub(PolynomialArrayEvalForm *out, PolynomialArrayEvalForm *other){
    PolynomialArrayEvalFormFFTWComplex* other_cast = static_cast<PolynomialArrayEvalFormFFTWComplex*>(other);
    PolynomialArrayEvalFormFFTWComplex* out_cast = static_cast<PolynomialArrayEvalFormFFTWComplex*>(out);
    for(int32_t i = 0; i < full_size; ++i){
            out_cast->eval_fftw[i][0] = this->eval_fftw[i][0] - other_cast->eval_fftw[i][0];
            out_cast->eval_fftw[i][1] = this->eval_fftw[i][1] - other_cast->eval_fftw[i][1];
        } 
}


void PolynomialArrayEvalFormFFTWComplex::mul(PolynomialArrayEvalForm *out, int64_t scalar){
    PolynomialArrayEvalFormFFTWComplex* out_cast = static_cast<PolynomialArrayEvalFormFFTWComplex*>(out);
     for(int32_t i = 0; i < full_size; ++i){
            out_cast->eval_fftw[i][0] = this->eval_fftw[i][0] * scalar;
            out_cast->eval_fftw[i][1] = this->eval_fftw[i][1] * scalar;
        } 
}

void PolynomialArrayEvalFormFFTWComplex::neg(PolynomialArrayEvalForm *out){
    PolynomialArrayEvalFormFFTWComplex* out_cast = static_cast<PolynomialArrayEvalFormFFTWComplex*>(out);
    for(int32_t i = 0; i < full_size; ++i){
            out_cast->eval_fftw[i][0] = -this->eval_fftw[i][0];
            out_cast->eval_fftw[i][1] = -this->eval_fftw[i][1];
        } 
}

/*
void PolynomialArrayEvalFormFFTWComplex::mod_reduce(int64_t modulus){ 
}
*/


PolynomialArrayEvalFormFFTWLongComplex::~PolynomialArrayEvalFormFFTWLongComplex(){
    if(this->is_init){
        delete[] eval_fftwl;
    }
}

PolynomialArrayEvalFormFFTWLongComplex::PolynomialArrayEvalFormFFTWLongComplex(int32_t size, int32_t array_size){ 
    this->array_size = array_size; 
    this->size = size; 
    this->full_size = this->size * array_size; 
    this->eval_fftwl = new fftwl_complex[full_size];  
    this->is_init = true;
}

void PolynomialArrayEvalFormFFTWLongComplex::add(PolynomialArrayEvalForm *out, PolynomialArrayEvalForm *other){
    PolynomialArrayEvalFormFFTWLongComplex* out_cast = static_cast<PolynomialArrayEvalFormFFTWLongComplex*>(out);
    PolynomialArrayEvalFormFFTWLongComplex* other_cast = static_cast<PolynomialArrayEvalFormFFTWLongComplex*>(other);
    for(int32_t i = 0; i < full_size; ++i){
        out_cast->eval_fftwl[i][0] = this->eval_fftwl[i][0] + other_cast->eval_fftwl[i][0];
        out_cast->eval_fftwl[i][1] = this->eval_fftwl[i][1] + other_cast->eval_fftwl[i][1];
    } 
}

void PolynomialArrayEvalFormFFTWLongComplex::sub(PolynomialArrayEvalForm *out, PolynomialArrayEvalForm *other){
    PolynomialArrayEvalFormFFTWLongComplex* out_cast = static_cast<PolynomialArrayEvalFormFFTWLongComplex*>(out);
    PolynomialArrayEvalFormFFTWLongComplex* other_cast = static_cast<PolynomialArrayEvalFormFFTWLongComplex*>(other);
    for(int32_t i = 0; i < full_size; ++i){
        out_cast->eval_fftwl[i][0] = this->eval_fftwl[i][0] - other_cast->eval_fftwl[i][0];
        out_cast->eval_fftwl[i][1] = this->eval_fftwl[i][1] - other_cast->eval_fftwl[i][1];
    } 
}

void PolynomialArrayEvalFormFFTWLongComplex::mul(PolynomialArrayEvalForm *out, int64_t scalar){
    PolynomialArrayEvalFormFFTWLongComplex* out_cast = static_cast<PolynomialArrayEvalFormFFTWLongComplex*>(out);
    for(int32_t i = 0; i < full_size; ++i){
        out_cast->eval_fftwl[i][0] = this->eval_fftwl[i][0] * scalar;
        out_cast->eval_fftwl[i][1] = this->eval_fftwl[i][1] * scalar;
    }
}

void PolynomialArrayEvalFormFFTWLongComplex::neg(PolynomialArrayEvalForm *out){
    PolynomialArrayEvalFormFFTWLongComplex* out_cast = static_cast<PolynomialArrayEvalFormFFTWLongComplex*>(out);
    for(int32_t i = 0; i < full_size; ++i){
        out_cast->eval_fftwl[i][0] = -this->eval_fftwl[i][0];
        out_cast->eval_fftwl[i][1] = -this->eval_fftwl[i][1];
    } 
}
 