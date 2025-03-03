#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Structure to store the API response
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function to handle API response
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    mem->memory = realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        printf("Not enough memory (realloc returned NULL)\n");
        return 0;
    }

    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

// Function to fetch exchange rate
double get_exchange_rate(const char *currency) {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk;
    chunk.memory = malloc(1);  // Initialize memory
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        char url[256];
        snprintf(url, sizeof(url), "https://v6.exchangerate-api.com/v6/43707713c641d57e8c750d93/latest/%s", currency);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // Parse JSON response to get KES rate
            char *kes_rate_str = strstr(chunk.memory, "\"KES\":");
            if (kes_rate_str) {
                double kes_rate = atof(kes_rate_str + 6); // Extract the rate
                curl_easy_cleanup(curl);
                free(chunk.memory);
                curl_global_cleanup();
                return kes_rate;
            }
        }

        curl_easy_cleanup(curl);
    }

    free(chunk.memory);
    curl_global_cleanup();
    return -1; // Return -1 if there's an error
}

int main() {
    char currency[10];
    double amount;

    printf("Enter the currency code (e.g., USD, EUR, GBP): ");
    scanf("%s", currency);
    printf("Enter the amount: ");
    scanf("%lf", &amount);

    double rate = get_exchange_rate(currency);
    if (rate > 0) {
        double kshs = amount * rate;
        printf("%.2f %s = %.2f Kshs\n", amount, currency, kshs);
    } else {
        printf("Failed to fetch exchange rate. Please check your input or try again later.\n");
    }

    return 0;
}
