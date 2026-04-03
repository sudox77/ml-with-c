#include <stdio.h>

/* training data: house size (square feet) and price (in thousands) */
double house_sizes[] = { 600, 800, 1000, 1200, 1500, 1800, 2000 };
double house_prices[] = { 150, 200, 250, 300, 350, 400, 450 };
int data_count = 7;

int main() {
    double slope = 0.0;        /* how much price increases per square foot */
    double intercept = 0.0;    /* base price when size is zero */
    double step_size = 0.000001;
    int training_rounds = 10000;

    printf("teaching the computer to predict house prices...\n");

    for (int round = 0; round < training_rounds; round++) {
        double total_error = 0.0;

        for (int i = 0; i < data_count; i++) {
            double guessed_price = slope * house_sizes[i] + intercept;
            double prediction_error = guessed_price - house_prices[i];

            /* adjust slope and intercept to make better guesses next time */
            slope = slope - step_size * prediction_error * house_sizes[i];
            intercept = intercept - step_size * prediction_error;

            total_error += prediction_error * prediction_error;
        }

        if (round % 2000 == 0) {
            printf("round %d | error = %.2f\n", round, total_error);
        }
    }

    printf("\ntrained model:\n");
    printf("price = %.4f * size + %.2f\n\n", slope, intercept);

    /* try out our trained model on new sizes */
    printf("guessed price for 1100 sq ft: %.0f thousand\n", slope * 1100 + intercept);
    printf("guessed price for 1700 sq ft: %.0f thousand\n", slope * 1700 + intercept);
    printf("guessed price for 2500 sq ft: %.0f thousand\n", slope * 2500 + intercept);

    return 0;
}