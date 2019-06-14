#include "fann.h"

int main()
{
    const unsigned int couche_entree = 26;
    const unsigned int couche_sortie = 3;
    const unsigned int nombre_couche = 2;
//    const unsigned int couche_cache_1 = 20;
//    const unsigned int couche_cache_2 = 11;
//    const unsigned int couche_cache_3 = 5;
    const float desired_error = (const float) 0.000000001;
    const unsigned int max_epochs = 20000000;
    const unsigned int epochs_between_reports = 100;

//    struct fann *ann = fann_create_standard(nombre_couche, couche_entree, \
//couche_cache_1, couche_cache_2, couche_cache_3, couche_sortie);
    struct fann *ann = fann_create_standard(nombre_couche, couche_entree, \
 couche_sortie);

    fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);
    fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC);

    fann_train_on_file(ann, "f.data", max_epochs, epochs_between_reports, desired_error);

    fann_save(ann, "langue.net");

    fann_destroy(ann);

    return 0;
}
