#include <iostream>
#include "../include/fhe_context.h"

#include <cereal/archives/binary.hpp>
#include <cereal/archives/xml.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/types/memory.hpp>
#include <fstream>
#include <sstream>

#include <cassert>
#define assertm(exp, msg) assert(((void)msg, exp))

 




void test_for_default_full_domain_encoding(){

    std::cout << "=========== test_for_default_full_domain_encoding =============" << std::endl;

    fhe_context context; 
    std::cout << "Generate Keys..." << std::endl;
    context.generate_context(rlwe_hom_acc_scheme_C_11_B);
    
    std::cout << "Encrypt..." << std::endl;
    ciphertext c1  = context.encrypt(1);  



    std::cout << "Encrypt..." << std::endl;
    ciphertext c2  = context.encrypt(2);  

    std::cout << "Decrypt..." << std::endl;
    assertm(context.decrypt(&c1) == 1, "Decrypt(c1) == 1");
    std::cout << "Decrypt(c1) == 1: OK" << std::endl; 
    
    assertm(context.decrypt(&c2) == 2, "Decrypt(c2) == 2");
    std::cout << "Decrypt(c2) == 2: OK" << std::endl; 
 
     
    ciphertext c3 = context.encrypt(0);
    c3.add(&c1); 
    
    assertm(context.decrypt(&c3) == 1, "Decrypt(c3+c1) == 1");
    std::cout << "Decrypt(c3+c1): OK" << std::endl;
    c3.add(&c2); 
    assertm(context.decrypt(&c3) == 3, "Decrypt(c3+c1+c2) == 3");
    std::cout << "Decrypt(c3+c1+c2): OK" << std::endl;
    c3.add(&c2); 
    assertm(context.decrypt(&c3) == 1, "Decrypt(c3+c1+c2+c2) == 1");
    std::cout << "Decrypt(c3+c1+c2+c2) OK" << std::endl;


    c3.mul(3); 
    assertm(context.decrypt(&c3) == 3, "Decrypt((c3+c1+c2+c2) * 3) == 3");
    std::cout << "Decrypt((c3+c1+c2+c2) * 3): OK"  << std::endl; 
 
    std::cout << "Copying to LWE ct objects" << std::endl;
    ciphertext ct1 = c1;
 

    ciphertext ct2 = c2;
    assertm(context.decrypt(&ct1) == 1, "context.decrypt(&ct1) == 1");
    std::cout << "context.decrypt(&ct1) == 1: OK"  << std::endl;

    assertm(context.decrypt(&ct2) == 2, "context.decrypt(&ct2) == 2");
    std::cout << "context.decrypt(&ct2) == 2: OK"  << std::endl;
    ciphertext ct3 = ct1 + 1;  
    assertm(context.decrypt(&ct3) == 2, "context.decrypt(&(ct1 + 1)) == 2");
    std::cout << "context.decrypt(&(ct1 + 1)) == 2: OK"  << std::endl;

    ct3 = 1 + ct1;  
    assertm(context.decrypt(&ct3) == 2, "context.decrypt(&(1+ ct1)) == 2");
    std::cout << "context.decrypt(&(1+ ct1)) == 2: OK"  << std::endl;

    ct3 = ct1 - 2; 
    assertm(context.decrypt(&ct3) == 3, "context.decrypt(&(ct1 - 2)) == 3");
    std::cout << "context.decrypt(&(ct1 - 2)) == 3: OK"  << std::endl;

    ct3 = 2 - ct1; 
    assertm(context.decrypt(&ct3) == 1, "context.decrypt(&(2 - ct1)) == 1");
    std::cout << "context.decrypt(&(2 - ct1)) == 1: OK"  << std::endl;
 
    ct3 = ct1 * 2; 
    assertm(context.decrypt(&ct3) == 2, "context.decrypt(&(ct1 * 2)) == 2");
    std::cout << "context.decrypt(&(ct1 * 2)) == 2: "  << std::endl;

    ct3 = 2 * ct1; 
    assertm(context.decrypt(&ct3) == 2, "context.decrypt(&(2 * ct1)) == 2");
    std::cout << "context.decrypt(&(2 * ct1)) == 2: OK"   << std::endl;

    ct3 = ct1 + ct2; 
    assertm(context.decrypt(&ct3) == 3, "context.decrypt(&(ct1 + ct2)) == 3");
    std::cout << "context.decrypt(&(ct1 + ct2)) == 3: OK"  << std::endl;

    ct3 = ct2 - ct1; 
    assertm(context.decrypt(&ct3) == 1, "context.decrypt(&(ct2 - ct1)) == 1");
    std::cout << "context.decrypt(&(ct2 - ct1)) == 1: OK"   << std::endl;

    assertm(context.decrypt(&ct1) == 1, "context.decrypt(&ct1) == 1"); 
    std::cout << "context.decrypt(&ct1) == 1: OK" << std::endl;
    ct3 = - ct1; 
    assertm(context.decrypt(&ct3) == 3, "context.decrypt(&(ct3 = - ct1))) == 3"); 
    std::cout << "context.decrypt(&(ct3 = - ct1))) == 3: OK" << std::endl;
    assertm(context.decrypt(&ct1) == 1, "context.decrypt(&ct1) == 1"); 
    std::cout << "context.decrypt(&ct1) == 1: OK" << std::endl;
     
    ciphertext ct4 = ct1;
    assertm(context.decrypt(&ct4) == 1, "context.decrypt(&(ct4 = ct1))) == 1"); 
    std::cout << "context.decrypt(&(ct4 = ct1))) == 1: OK"   << std::endl;
    ct4 = ct1;
    assertm(context.decrypt(&ct4) == 1, "context.decrypt(&(ct4 = ct1))) == 1"); 
    std::cout << "context.decrypt(&(ct4 = ct1))) == 1: OK"   << std::endl; 
    ct4 = ct2;
    assertm(context.decrypt(&ct4) == 2, "context.decrypt(&(ct4 = ct2))) == 2"); 
    std::cout << "context.decrypt(&(ct4 = ct2))) == 2: OK"   << std::endl;
 


    std::vector<ciphertext> v;
    v.push_back(ct1);
    v.push_back(ct2);

    std::vector<long> scalars;
    scalars.push_back(2);
    scalars.push_back(1);
    long scalar = 3;
    ct4 = context.eval_affine_function(v, scalars, scalar);  
    // The outcome should be 3, because (2 * 1 + 1 * 2 + 3) % 4 = 3
    assertm(context.decrypt(&ct4) == 3, "context.decrypt(&((2 * 1 + 1 * 2 + 3) % 4 = 3))) == 3"); 
    std::cout << "context.decrypt(&((2 * 1 + 1 * 2 + 3) % 4 = 3))) == 3: OK"   << std::endl; 
 
       

    auto id = [](long m, long t) -> long {
        return m % t;
    }; 
  
    rotation_poly lut_identity = context.genrate_lut(id); 
 
    ct4 = context.eval_lut(&ct1, lut_identity);
    assertm(context.decrypt(&ct4) == 1, "context.decrypt(context.eval_lut(&ct1, lut_identity)) == 1"); 
    std::cout << "context.decrypt(context.eval_lut(&ct1, lut_identity)) == 1: OK"  << std::endl;


    auto id_plus = [](long m, long t) -> long {
        return (m+1) % t;
    }; 
    rotation_poly lut_id_plus = context.genrate_lut(id_plus); 
    ct4 = context.eval_lut(&ct1, lut_id_plus);
    assertm(context.decrypt(&ct4) == 2, "context.decrypt(context.eval_lut(&ct1, lut_id_plus)) == 2"); 
    std::cout << "context.decrypt(context.eval_lut(&ct1, lut_id_plus)) == 2: OK"  << std::endl;
 
    ct4 = context.eval_lut(&ct4, lut_id_plus);
    assertm(context.decrypt(&ct4) == 3, "context.decrypt(context.eval_lut(&ct4, lut_id_plus)) == 3"); 
    std::cout << "context.decrypt(context.eval_lut(&ct4, lut_id_plus)) == 3: OK"  << std::endl;

    ct4 = context.eval_lut(&ct4, lut_id_plus);
    assertm(context.decrypt(&ct4) == 0, "context.decrypt(context.eval_lut(&ct4, lut_id_plus)) == 0"); 
    std::cout << "context.decrypt(context.eval_lut(&ct4, lut_id_plus)) == 0: OK"  << std::endl;

    auto fun_msb = [](long m, long t) -> long {
        if(m < t/2){
            return 0;
        }else{
            return 1;
        } 
    }; 
    rotation_poly lut_fun_msb = context.genrate_lut(fun_msb); 
    ct4 = context.eval_lut(&ct1, lut_fun_msb);

    assertm(context.decrypt(&ct4) == 0, "context.decrypt(context.eval_lut(&ct1, lut_fun_msb)) == 0"); 
    std::cout << "context.decrypt(context.eval_lut(&ct1, lut_fun_msb)) == 0: OK"  << std::endl;
  

    std::cout << "Done. See you....." << std::endl;
}

void test_for_partial_domain_encoding(){

    std::cout << "=========== test_for_partial_domain_encoding =============" << std::endl;

    fhe_context context; 
    std::cout << "Generate Keys..." << std::endl;
    context.generate_context(rlwe_hom_acc_scheme_C_11_B);
    context.set_default_message_encoding_type(partial_domain);
 
    ciphertext c0  = context.encrypt(0);  
    ciphertext c1  = context.encrypt(1);    
    ciphertext c2  = context.encrypt(2);  
    ciphertext c3  = context.encrypt(3);  
 


    assertm(context.decrypt(&c0) == 0, "Decrypt(c0) == 0");
    std::cout << "Decrypt(c0) == 0: OK" << std::endl; 
    assertm(context.decrypt(&c1) == 1, "Decrypt(c1) == 1");
    std::cout << "Decrypt(c1) == 1: OK" << std::endl; 
    assertm(context.decrypt(&c2) == 2, "Decrypt(c2) == 2");
    std::cout << "Decrypt(c2) == 2: OK" << std::endl; 
    assertm(context.decrypt(&c3) == 3, "Decrypt(c3) == 3");
    std::cout << "Decrypt(c3) == 3: OK" << std::endl; 

 
    

    auto fun_ham = [](long m, long t) -> long {
        switch(m){
            case 0: 
                return 0;
                break;
            case 1: 
                return 1; 
                break;
            case 2: 
                return 1;   
                break; 
            case 3: 
                return 2;  
            default:
                return 0;
        }
    }; 
    rotation_poly lut_fun_ham = context.genrate_lut(fun_ham); 

    ciphertext ct4;
    ct4 = context.eval_lut(&c0, lut_fun_ham);
    assertm(context.decrypt(&ct4) == 0, "context.eval_lut(c0, lut_fun_ham) == 0");
    std::cout << "context.eval_lut(c0, lut_fun_ham) == 0: OK" << std::endl; 
    //std::cout << "ct4 = Hamming_Weight(ct0): " << context.decrypt(ct4) << std::endl;

    ct4 = context.eval_lut(&c1, lut_fun_ham);
    assertm(context.decrypt(&ct4) == 1, "context.eval_lut(c1, lut_fun_ham) == 1");
    std::cout << "context.eval_lut(c1, lut_fun_ham) == 1: OK" << std::endl; 
    //std::cout << "ct4 = Hamming_Weight(ct1): " << context.decrypt(ct4) << std::endl;

    ct4 = context.eval_lut(&c2, lut_fun_ham);
    assertm(context.decrypt(&ct4) == 1, "context.eval_lut(c2, lut_fun_ham) == 1");
    std::cout << "context.eval_lut(c2, lut_fun_ham) == 1: OK" << std::endl; 
    //std::cout << "ct4 = Hamming_Weight(ct2): " << context.decrypt(ct4) << std::endl;

    ct4 = context.eval_lut(&c3, lut_fun_ham);
    assertm(context.decrypt(&ct4) == 2, "context.eval_lut(c3, lut_fun_ham) == 2");
    std::cout << "context.eval_lut(c3, lut_fun_ham) == 2: OK" << std::endl; 
    //std::cout << "ct4 = Hamming_Weight(ct3): " << context.decrypt(ct4) << std::endl;



    auto fun_nand = [](long m) -> long {
        switch(m){
            case 0: 
                return 1;
                break;
            case 1: 
                return 1; 
                break;
            case 2: 
                return 1;   
                break; 
            case 3: 
                return 0;  
            default:
                return 2;
        }
    }; 
    rotation_poly lut_fun_nand = context.genrate_lut(fun_nand); 

    ciphertext ct0 = context.encrypt(1);  
    ciphertext ct1 = context.encrypt(0);   
    ciphertext combined = ct0 + (ct1 * 2);  
    ciphertext ct_nand = context.eval_lut(&combined, lut_fun_nand);
    assertm(context.decrypt(&ct_nand) == 1, "ct_nand(0, 0) == 1");
    //std::cout << "ct_nand(0, 0) = 1: OK" << context.decrypt(&ct_nand) << std::endl;


    ct0 = context.encrypt(1);  
    ct1 = context.encrypt(0);  
    combined = ct0 + (ct1 * 2); 
    ct_nand = context.eval_lut(&combined, lut_fun_nand);
    assertm(context.decrypt(&ct_nand) == 1, "ct_nand(0, 1) == 1");
    std::cout << "ct_nand(0, 1) = 1: OK"  << std::endl;
    //std::cout << "ct_nand(1, 0): " << context.decrypt(&ct_nand) << std::endl;

    ct0 = context.encrypt(0);  
    ct1 = context.encrypt(1);  
    combined = ct0 + (ct1 * 2); 
    ct_nand = context.eval_lut(&combined, lut_fun_nand);
    assertm(context.decrypt(&ct_nand) == 1, "ct_nand(1, 0) == 1");
    std::cout << "ct_nand(1, 0) = 1: OK"   << std::endl;
    //std::cout << "ct_nand(0, 1): " << context.decrypt(&ct_nand) << std::endl;


    ct0 = context.encrypt(1);  
    ct1 = context.encrypt(1);  
    combined = ct0 + (ct1 * 2); 
    ct_nand = context.eval_lut(&combined, lut_fun_nand);
    assertm(context.decrypt(&ct_nand) == 0, "ct_nand(1, 1) == 0");
    std::cout << "ct_nand(1, 1) = 0: OK"   << std::endl;
    //std::cout << "ct_nand(1, 1): " << context.decrypt(&ct_nand) << std::endl;
 
}

void test_for_signed_limied_short_int(){
    
    std::cout << "=========== test_for_signed_limied_short_int =============" << std::endl;

    fhe_context context; 
    std::cout << "Generate Keys..." << std::endl;
    context.generate_context(rlwe_hom_acc_scheme_C_11_B);
    context.set_default_message_encoding_type(signed_limied_short_int);

    std::cout << "plaintext_space: " << context.get_default_plaintext_space() << std::endl;

    ciphertext ct0 = context.encrypt(0);   
    ciphertext ct1 = context.encrypt(1); 
    ciphertext ct2 = context.encrypt(2);    
    ciphertext ct3 = context.encrypt(3); 

    ciphertext mct1 = context.encrypt(-1); 
    ciphertext mct2 = context.encrypt(-2);    
    ciphertext mct3 = context.encrypt(-3); 



    ciphertext ct4 = context.encrypt(4);  
   
    ciphertext mct4 = context.encrypt(-4); 

    assertm(context.decrypt(&ct0) == 0, "context.decrypt(&ct0) == 0");
    std::cout << "context.decrypt(&ct0) == 0: OK"   << std::endl;
    assertm(context.decrypt(&ct1) == 1, "context.decrypt(&ct1) == 1");
    std::cout << "context.decrypt(&ct1) == 1: OK"   << std::endl;
    assertm(context.decrypt(&ct2) == 2, "context.decrypt(&ct2) == 2");
    std::cout << "context.decrypt(&ct2) == 2: OK"   << std::endl;
    assertm(context.decrypt(&ct3) == 3, "context.decrypt(&ct3) == 3");
    std::cout << "context.decrypt(&ct3) == 3: OK"   << std::endl;
    
    assertm(context.decrypt(&mct1) == -1, "context.decrypt(&mct1) == -1");
    std::cout << "context.decrypt(&mct1) == -1: OK"   << std::endl;
    assertm(context.decrypt(&mct2) == -2, "context.decrypt(&mct1) == -2");
    std::cout << "context.decrypt(&mct2) == -2: OK"   << std::endl;
    assertm(context.decrypt(&mct3) == -3, "context.decrypt(&mct1) == -3");
    std::cout << "context.decrypt(&mct3) == -3: OK"   << std::endl;

 
    std::cout << "Decrypt(ct4): " << context.decrypt(&ct4) << std::endl; 
 
    std::cout << "Decrypt(mct4): " << context.decrypt(&mct4) << std::endl;


    ciphertext ct_add = ct1 + mct1;
    assertm(context.decrypt(&ct_add) == 0, "context.decrypt(&ct1 + mct1) == 0");
    std::cout << "Decrypt(ct_add = ct1 + mct1): OK"  << std::endl; 
    ct_add = ct2 + mct2;
    assertm(context.decrypt(&ct_add) == 0, "context.decrypt(&ct_add) == 0");
    std::cout << "Decrypt(ct_add = ct2 + mct2): OK"   << std::endl;  
    ct_add = ct3 + mct3;
    assertm(context.decrypt(&ct_add) == 0, "context.decrypt(&ct_add) == 0");
    std::cout << "Decrypt(ct_add = ct3 + mct3): OK"  << std::endl; 

 
    
    auto fun_identity = [](long m) -> long {
        return m;
    }; 
 
 
    rotation_poly lut_fun_identity = context.genrate_lut(fun_identity); 
    ciphertext ct_id = context.eval_lut(&mct1, lut_fun_identity); 
    std::cout << "context.decrypt(&mct1): " << context.decrypt(&mct1) << std::endl; 
    std::cout << "context.decrypt(&ct_id): " << context.decrypt(&ct_id) << std::endl; 
    assertm(context.decrypt(&ct_id) == -1, "context.eval_lut(&mct1, lut_fun_identity) == -1");
    std::cout << "context.eval_lut(&mct1, lut_fun_identity) == -1: OK"  << std::endl; 

    ct_id = context.eval_lut(&mct2, lut_fun_identity); 
    assertm(context.decrypt(&ct_id) == -2, "context.eval_lut(&mct2, lut_fun_identity) == -2");
    std::cout << "context.eval_lut(&mct2, lut_fun_identity) == -2: OK"  << std::endl;  

    ct_id = context.eval_lut(&mct3, lut_fun_identity); 
    assertm(context.decrypt(&ct_id) == -3, "context.eval_lut(&mct3, lut_fun_identity) == -3");
    std::cout << "context.eval_lut(&mct3, lut_fun_identity) == -3: OK"  << std::endl;  

 
 
 

    auto fun_relu = [](long m) -> long {
        if(m >= 0){
            return m; 
        }else{
            return 0;
        }
    };  
 

    ciphertext ct_relu = context.eval_lut(&ct2, fun_relu);  
    assertm(context.decrypt(&ct_relu) == 2, "context.eval_lut(&ct2, fun_relu) == 2");
    std::cout << "context.eval_lut(&ct2, fun_relu) == 2: OK" << std::endl; 


    ct_relu = context.eval_lut(&mct3, fun_relu);  
    assertm(context.decrypt(&ct_relu) == 0, "context.eval_lut(&mct3, fun_relu) == 0");
    std::cout << "context.eval_lut(&mct0, fun_relu) == 0: OK" << std::endl; 
   
    ct_relu = context.eval_lut(&ct1, fun_relu); 
    assertm(context.decrypt(&ct_relu) == 1, "context.eval_lut(&ct1, fun_relu) == 1");
    std::cout << "context.eval_lut(&ct1, fun_relu) == 1: OK" << std::endl; 

    ct_relu = context.eval_lut(&ct2, fun_relu); 
    assertm(context.decrypt(&ct_relu) == 2, "context.eval_lut(&ct2, fun_relu) == 2");
    std::cout << "context.eval_lut(&ct2, fun_relu) == 2: OK" << std::endl; 

    ct_relu = context.eval_lut(&ct3, fun_relu); 
    assertm(context.decrypt(&ct_relu) == 3, "context.eval_lut(&ct3, fun_relu) == 3");
    std::cout << "context.eval_lut(&ct3, fun_relu) == 3: OK" << std::endl; 
    
    ct_relu = context.eval_lut(&mct1, fun_relu); 
    assertm(context.decrypt(&ct_relu) == 0, "context.eval_lut(&mct1, fun_relu) == 0");
    std::cout << "context.eval_lut(&mct1, fun_relu) == 0: OK" << std::endl; 


    ct_relu = context.eval_lut(&mct2, fun_relu); 
    assertm(context.decrypt(&ct_relu) == 0, "context.eval_lut(&mct2, fun_relu) == 0");
    std::cout << "context.eval_lut(&mct2, fun_relu) == 0: OK" << std::endl; 

    ct_relu = context.eval_lut(&mct3, fun_relu); 
    assertm(context.decrypt(&ct_relu) == 0, "context.eval_lut(&mct3, fun_relu) == 0");
    std::cout << "context.eval_lut(&mct3, fun_relu) == 0: OK" << std::endl; 
  
}
 

void basic_ciphertext_tests(){

    std::cout << "=========== basic_ciphertext_tests =============" << std::endl;

    fhe_context context; 
    std::cout << "Generate Keys..." << std::endl;
    context.generate_context(rlwe_hom_acc_scheme_C_11_B);
    
    std::cout << "Encrypt..." << std::endl;
    std::cout << "Testing: lwe_ct c1  = context.encrypt_temp(1);  " << std::endl;
    ciphertext c1  = context.encrypt(1);  
 
    assertm(context.decrypt(&c1) == 1, "Decrypt(c1) == 1");
    std::cout << "context.decrypt(&c1) == 1: OK" << std::endl; 
      
    std::cout << "Testing: lwe_ct::lwe_ct(lwe_ct &c)" << std::endl;
    ciphertext c2  = c1;   
    assertm(context.decrypt(&c2) == 1, "Decrypt(c2) == 1");
    std::cout << "context.decrypt(&c2) == 1: OK" << std::endl; 
 
    std::cout << "Testing: lwe_ct& lwe_ct::operator=(const lwe_ct other)" << std::endl;
    c1 = c2;
    assertm(context.decrypt(&c1) == 1, "Decrypt(c1) == 1");
    std::cout << "context.decrypt(&c1) == 1: OK" << std::endl;  
    
}



void amortized_full_domain_bootstrap_test(){
    std::cout << "=========== amortized_full_domain_bootstrap_test =============" << std::endl;


    fhe_context context; 
    std::cout << "Generate Keys..." << std::endl;
    context.generate_context(rlwe_hom_acc_scheme_C_11_NTT_amortized);
    
    auto id = [](long m, long t) -> long {
        return m % t;
    }; 
  
    rotation_poly lut_identity = context.genrate_lut(id); 

    std::vector<rotation_poly> luts;
    luts.push_back(lut_identity);
    luts.push_back(lut_identity);
 
    ciphertext ct1 = context.encrypt_public(1); 

    std::vector<ciphertext> out_cts = context.eval_lut_amortized(&ct1, luts);

    std::cout << "context.decrypt(&out_cts[0]): " << context.decrypt(&out_cts[0]) << std::endl;
    assertm(context.decrypt(&out_cts[0]) == 1, "context.decrypt(context.eval_lut(&out_cts[0], lut_identity)) == 1"); 
    std::cout << "context.decrypt(context.eval_lut(&out_cts[0], lut_identity)) == 1: OK"  << std::endl;

    std::cout << "context.decrypt(&out_cts[1]): " << context.decrypt(&out_cts[1]) << std::endl;
    assertm(context.decrypt(&out_cts[1]) == 1, "context.decrypt(context.eval_lut(&out_cts[1], lut_identity)) == 1"); 
    std::cout << "context.decrypt(context.eval_lut(&out_cts[1], lut_identity)) == 1: OK"  << std::endl;


    out_cts = context.eval_lut_amortized(&ct1, luts);

    std::cout << "context.decrypt(&out_cts[0]): " << context.decrypt(&out_cts[0]) << std::endl;
    assertm(context.decrypt(&out_cts[0]) == 1, "context.decrypt(context.eval_lut(&out_cts[0], lut_identity)) == 1"); 
    std::cout << "context.decrypt(context.eval_lut(&out_cts[0], lut_identity)) == 1: OK"  << std::endl;

    std::cout << "context.decrypt(&out_cts[1]): " << context.decrypt(&out_cts[1]) << std::endl;
    assertm(context.decrypt(&out_cts[1]) == 1, "context.decrypt(context.eval_lut(&out_cts[1], lut_identity)) == 1"); 
    std::cout << "context.decrypt(context.eval_lut(&out_cts[1], lut_identity)) == 1: OK"  << std::endl;



    auto first_bit = [](long m) -> long {
        return m % 2;
    };  
 

    auto second_bit = [](long m) -> long {
        return (m % 4)/2;
    };  

    auto third_bit = [](long m) -> long {
        return (m % 8)/4; 
    };  

    std::vector<rotation_poly> bit_decomp_luts;
    bit_decomp_luts.push_back(context.genrate_lut(first_bit));
    bit_decomp_luts.push_back(context.genrate_lut(second_bit));
    bit_decomp_luts.push_back(context.genrate_lut(third_bit));

    ciphertext ct0 = context.encrypt_public(0);
    ciphertext ct2 = context.encrypt_public(2);
    ciphertext ct3 = context.encrypt_public(3);
    ciphertext ct4 = context.encrypt_public(4);
    ciphertext ct5 = context.encrypt_public(5);
    ciphertext ct6 = context.encrypt_public(6);
    ciphertext ct7 = context.encrypt_public(7);


    out_cts = context.eval_lut_amortized(&ct0, bit_decomp_luts);
    assert(context.decrypt(&out_cts[0]) == 0); 
    assert(context.decrypt(&out_cts[1]) == 0); 
    assert(context.decrypt(&out_cts[2]) == 0); 
    std::cout << "Test Bin Decomp 0: OK" << std::endl;

    out_cts = context.eval_lut_amortized(&ct1, bit_decomp_luts);
    assert(context.decrypt(&out_cts[0]) == 1); 
    assert(context.decrypt(&out_cts[1]) == 0); 
    assert(context.decrypt(&out_cts[2]) == 0); 
    std::cout << "Test Bin Decomp 1: OK" << std::endl;

    out_cts = context.eval_lut_amortized(&ct2, bit_decomp_luts);
    assert(context.decrypt(&out_cts[0]) == 0); 
    assert(context.decrypt(&out_cts[1]) == 1); 
    assert(context.decrypt(&out_cts[2]) == 0); 
    std::cout << "Test Bin Decomp 2: OK" << std::endl;

    out_cts = context.eval_lut_amortized(&ct3, bit_decomp_luts);
    assert(context.decrypt(&out_cts[0]) == 1); 
    assert(context.decrypt(&out_cts[1]) == 1); 
    assert(context.decrypt(&out_cts[2]) == 0); 
    std::cout << "Test Bin Decomp 3: OK" << std::endl;

    out_cts = context.eval_lut_amortized(&ct4, bit_decomp_luts);
    assert(context.decrypt(&out_cts[0]) == 0); 
    assert(context.decrypt(&out_cts[1]) == 0); 
    assert(context.decrypt(&out_cts[2]) == 1); 
    std::cout << "Test Bin Decomp 4: OK" << std::endl;


    out_cts = context.eval_lut_amortized(&ct5, bit_decomp_luts);
    assert(context.decrypt(&out_cts[0]) == 1); 
    assert(context.decrypt(&out_cts[1]) == 0); 
    assert(context.decrypt(&out_cts[2]) == 1); 
    std::cout << "Test Bin Decomp 5: OK" << std::endl;


    out_cts = context.eval_lut_amortized(&ct6, bit_decomp_luts);
    assert(context.decrypt(&out_cts[0]) == 0); 
    assert(context.decrypt(&out_cts[1]) == 1); 
    assert(context.decrypt(&out_cts[2]) == 1); 
    std::cout << "Test Bin Decomp 6: OK" << std::endl;


    out_cts = context.eval_lut_amortized(&ct7, bit_decomp_luts);
    assert(context.decrypt(&out_cts[0]) == 1); 
    assert(context.decrypt(&out_cts[1]) == 1); 
    assert(context.decrypt(&out_cts[2]) == 1); 
    std::cout << "Test Bin Decomp 7: OK" << std::endl;

}



void amortized_partial_domain_bootstrap_test(){
    std::cout << "=========== amortized_partial_domain_bootstrap_test =============" << std::endl;


    fhe_context context; 
    std::cout << "Generate Keys..." << std::endl;
    context.generate_context(rlwe_hom_acc_scheme_C_11_NTT_amortized);
    context.set_default_message_encoding_type(partial_domain);
  
    auto first_bit = [](long m) -> long {
        return m % 2;
    };  
  
    auto second_bit = [](long m) -> long {
        return (m % 4)/2;
    };  

    auto third_bit = [](long m) -> long {
        return (m % 8)/4; 
    };  

    std::vector<rotation_poly> bit_decomp_luts;
    bit_decomp_luts.push_back(context.genrate_lut(first_bit));
    bit_decomp_luts.push_back(context.genrate_lut(second_bit));
    bit_decomp_luts.push_back(context.genrate_lut(third_bit));

    ciphertext ct0 = context.encrypt_public(0); 
    ciphertext ct1 = context.encrypt_public(1); 
    ciphertext ct2 = context.encrypt_public(2);
    ciphertext ct3 = context.encrypt_public(3);
    ciphertext ct4 = context.encrypt_public(4);
    ciphertext ct5 = context.encrypt_public(5);
    ciphertext ct6 = context.encrypt_public(6);
    ciphertext ct7 = context.encrypt_public(7);


    std::vector<ciphertext> out_cts = context.eval_lut_amortized(&ct0, bit_decomp_luts);

    std::cout << "context.decrypt(&out_cts[0]): " << context.decrypt(&out_cts[0]) << std::endl;
    std::cout << "context.decrypt(&out_cts[1]): " << context.decrypt(&out_cts[1]) << std::endl;
    std::cout << "context.decrypt(&out_cts[2]): " << context.decrypt(&out_cts[2]) << std::endl;

    assert(context.decrypt(&out_cts[0]) == 0); 
    assert(context.decrypt(&out_cts[1]) == 0); 
    assert(context.decrypt(&out_cts[2]) == 0); 
    std::cout << "Test Bin Decomp 0: OK" << std::endl;


    out_cts = context.eval_lut_amortized(&ct1, bit_decomp_luts);

    
    std::cout << "context.decrypt(&out_cts[0]): " << context.decrypt(&out_cts[0]) << std::endl;
    std::cout << "context.decrypt(&out_cts[1]): " << context.decrypt(&out_cts[1]) << std::endl;
    std::cout << "context.decrypt(&out_cts[2]): " << context.decrypt(&out_cts[2]) << std::endl;

    

    assert(context.decrypt(&out_cts[0]) == 1); 
    assert(context.decrypt(&out_cts[1]) == 0); 
    assert(context.decrypt(&out_cts[2]) == 0); 
    std::cout << "Test Bin Decomp 1: OK" << std::endl;


    
    out_cts = context.eval_lut_amortized(&ct2, bit_decomp_luts);

    
    std::cout << "context.decrypt(&out_cts[0]): " << context.decrypt(&out_cts[0]) << std::endl;
    std::cout << "context.decrypt(&out_cts[1]): " << context.decrypt(&out_cts[1]) << std::endl;
    std::cout << "context.decrypt(&out_cts[2]): " << context.decrypt(&out_cts[2]) << std::endl;

    assert(context.decrypt(&out_cts[0]) == 0); 
    assert(context.decrypt(&out_cts[1]) == 1); 
    assert(context.decrypt(&out_cts[2]) == 0); 
    std::cout << "Test Bin Decomp 2: OK" << std::endl;

    out_cts = context.eval_lut_amortized(&ct3, bit_decomp_luts);
    assert(context.decrypt(&out_cts[0]) == 1); 
    assert(context.decrypt(&out_cts[1]) == 1); 
    assert(context.decrypt(&out_cts[2]) == 0); 
    std::cout << "Test Bin Decomp 3: OK" << std::endl;

    out_cts = context.eval_lut_amortized(&ct4, bit_decomp_luts);
    assert(context.decrypt(&out_cts[0]) == 0); 
    assert(context.decrypt(&out_cts[1]) == 0); 
    assert(context.decrypt(&out_cts[2]) == 1); 
    std::cout << "Test Bin Decomp 4: OK" << std::endl;


    out_cts = context.eval_lut_amortized(&ct5, bit_decomp_luts);
    assert(context.decrypt(&out_cts[0]) == 1); 
    assert(context.decrypt(&out_cts[1]) == 0); 
    assert(context.decrypt(&out_cts[2]) == 1); 
    std::cout << "Test Bin Decomp 5: OK" << std::endl;


    out_cts = context.eval_lut_amortized(&ct6, bit_decomp_luts);
    assert(context.decrypt(&out_cts[0]) == 0); 
    assert(context.decrypt(&out_cts[1]) == 1); 
    assert(context.decrypt(&out_cts[2]) == 1); 
    std::cout << "Test Bin Decomp 6: OK" << std::endl;


    out_cts = context.eval_lut_amortized(&ct7, bit_decomp_luts);
    assert(context.decrypt(&out_cts[0]) == 1); 
    assert(context.decrypt(&out_cts[1]) == 1); 
    assert(context.decrypt(&out_cts[2]) == 1); 
    std::cout << "Test Bin Decomp 7: OK" << std::endl;

}

 



void serialization_test(){
    std::cout << "=========== serialization_test =============" << std::endl;

    fhe_context first_context; 
    std::cout << "Generate Keys..." << std::endl;
    first_context.generate_context(rlwe_hom_acc_scheme_C_11_NTT);
   
     
    first_context.save_secret_key("z_sk.cereal"); 
    first_context.save_public_key("z_pk.cereal");
 
    fhe_context context;
    context.load_secret_key("z_sk.cereal"); 
    context.load_public_key("z_pk.cereal");
    
    ciphertext ct0 = context.encrypt_public(1);   
    assert(context.decrypt(&ct0) == 1);
    std::cout << "Test Encrypt/Decrypt: OK" << std::endl;

    auto id = [](long m, long t) -> long {
        return m % t;
    }; 
      
    ct0 = context.eval_lut(&ct0, id);  
 
    context.save_ciphertext("z_ct.cereal", ct0);  
    ciphertext ct_out = context.load_ciphertext("z_ct.cereal"); 
    assert(context.decrypt(&ct_out) == 1);
    std::cout << "Test Eval-Lut/Save and Load Ciphertext: OK" << std::endl;
     
    std::ofstream os("z_rlwe_ct.cereal", std::ios::binary);
    os << ct_out; 
    ciphertext ct_from_stream = context.load_ciphertext("z_rlwe_ct.cereal");
    assert(context.decrypt(&ct_from_stream) == 1);
    std::cout << "Test Writa and Save from Stream: OK" << std::endl;
}


int main(){  
    
    basic_ciphertext_tests();
 
    test_for_default_full_domain_encoding();

    test_for_partial_domain_encoding();

    test_for_signed_limied_short_int();

    amortized_full_domain_bootstrap_test();

    amortized_partial_domain_bootstrap_test();

    serialization_test();

}