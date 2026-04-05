#include <stdio.h>

int main() {
    /* simple decision rule: adult if taller than 150cm and heavier than 40kg */
    
    struct person_info {
        int weight_kg;
        int height_cm;
        int is_adult;  /* 0 = child, 1 = adult */
    };

    struct person_info people[6] = {
        {30, 120, 0},  
        {35, 130, 0},  
        {25, 110, 0},  
        {60, 170, 1},  
        {75, 180, 1},  
        {55, 165, 1}   
    };

    int guesses_correct = 0;
    printf("testing our simple decision rule:\n");

    for (int i = 0; i < 6; i++) {
        /* our rule: adult if both height and weight are above thresholds */
        int our_guess = (people[i].height_cm > 150 && people[i].weight_kg > 40) ? 1 : 0;
        
        printf("person %d: %dkg, %dcm -> guessed: %d (actual: %d)\n",
               i + 1, people[i].weight_kg, people[i].height_cm, 
               our_guess, people[i].is_adult);

        if (our_guess == people[i].is_adult) {
            guesses_correct++;
        }
    }

    printf("\ngot %d out of 6 right (%.0f%%)\n", guesses_correct, (guesses_correct / 6.0) * 100);

    return 0;
}
