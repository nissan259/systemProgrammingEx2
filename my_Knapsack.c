#include <stdio.h>
#define Weight 20
#define N 5
#define limit 20

void GetFromUser(char items[], int values[], int weights[]) {
    // Input items, values, and weights
    for (int i = 0; i < N; i++) {
        scanf(" %c", &items[i]);
        scanf("%d", &values[i]);
        scanf("%d", &weights[i]);
    }
}

int knapSack(int weights[], int values[], int selected_bool[]) {
    int table[N + 1][limit + 1];

    // Build table[][] in bottom-up manner
    for (int i = 0; i <= N; i++) {
        for (int w = 0; w <= limit; w++) {
            if (i == 0 || w == 0)
                table[i][w] = 0;
            else if (weights[i - 1] <= w) {
                int withItem = values[i - 1] + table[i - 1][w - weights[i - 1]];
                int withoutItem = table[i - 1][w];
                if (withItem > withoutItem) {
                    table[i][w] = withItem;
                } else {
                    table[i][w] = withoutItem;
                }
            } else
                table[i][w] = table[i - 1][w];
        }
    }

    // Determining which items are selected
    int w = limit;
    for (int i = N; i > 0; i--) {
        if (table[i][w] != table[i - 1][w]) {
            selected_bool[i - 1] = 1;
            w -= weights[i - 1];
        }
    }

    return table[N][limit];
}

int main() {
    char items[N];
    int values[N];
    int weights[N];
    int selected_bool[N] = {0};
    GetFromUser(items, values, weights);
    printf("Maximum profit: %d\n", knapSack(weights, values, selected_bool));
    printf("Selected items: ");
    for (int i = 0; i < N; i++) {
        if (selected_bool[i]) {
            printf("%c ", items[i]);
        }
    }
    printf("\n");
    return 0;
}
