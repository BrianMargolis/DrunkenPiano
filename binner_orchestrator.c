//
//  polybang.c
//  PolyBang
//
//  Created by hdez on 7/8/16.
//  Copyright © 2016 hdez. All rights reserved.
//

//Get the Pure Data headers from: https://github.com/pure-data/pure-data/blob/master/src/m_pd.h
#include "m_pd.h"

//Carve out memory for the class data model and typdef it
typedef struct _polybang {
    t_object    x_obj;
    t_int       init_count, current_count;
    t_int       mod_A, mod_B;
} t_polybang;


//The _new method is a class constructor
//It is required to be named [filename]_new()
void *polybang_new(t_floatarg f1, t_floatarg f2){
    //Create an instance of the polybang class
    t_polybang *x = (t_polybang *)pd_new(polybang_class);
   
      
    //Return the instance
    return (void *)x;
}

//Create a static pointer to the class; it will be initialized in the _setup() method
static t_class *polybang_class;

//The _setup method initializes the class in memory
//This method is the place where class behaviors are added
//It is required to be named [filename]_setup()
void polybang_setup(void){
    //Initialize the class
    polybang_class = class_new(gensym("polybang"),
                               (t_newmethod)polybang_new,
                               0,
                               sizeof(t_polybang),
                               CLASS_DEFAULT,
                               A_DEFFLOAT, //A of A:B
                               A_DEFFLOAT, //B of A:B
                               0);
    //Define the handling of various inputs
    // PLUMBING - BMM

    // Bang
    // REGISTERING EVENT HANDLER - BMM
    class_addbang(polybang_class, (t_method)polybang_onBangMsg);
}

//Perform on bang
void polybang_onBangMsg(t_polybang *x){
    bin(...);
}

int bin (...) {
    // TODO: code
}