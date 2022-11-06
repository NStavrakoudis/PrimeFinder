#include <stdio.h>

#include <math.h>
#include <stdlib.h>

struct result calculate_primes(int);

struct result {
	int c_primes_found;
	int *primes_found;
};

int main(int argc, char **argv){

	int upper_limit = atoi(argv[1]) != 0 ? atoi(argv[1]) : 0;
	if(upper_limit == 0){
		printf("ERROR: Upper limit should be greater than 5. \n");
		return 1;
	}
	struct result found = calculate_primes(upper_limit);

	for(int k = 0; k < found.c_primes_found; ++k){
		printf("%d, ", found.primes_found[k]);

	}
	printf("%s", "...\n");
	return 0;
}

struct result calculate_primes(int upper_limit){
	int *primes_found = malloc(3*sizeof(int));
	int c_primes_found = 3;
	primes_found[0] = 2;
	primes_found[1] = 3;
	primes_found[2] = 5;
	int current_number = 5;
	int current_limit = (int) pow((double) primes_found[c_primes_found - 1], 2);

	while(current_number < upper_limit){
		if(current_number < current_limit){
			if((current_number % 100) % 25 == 0){
				continue;
			}
			for(int i = 1; i < c_primes_found; ++i){

				if(current_number % primes_found[i] == 0){
					break;
				} else if(primes_found[i] == primes_found[c_primes_found - 1]){
					++c_primes_found;
					primes_found = realloc(primes_found, c_primes_found*sizeof(int));
					primes_found[c_primes_found-1] = current_number;
					break;
				} else {
					continue;
				}
			}
			if(current_number % 10 == 3){
				current_number += 4;
			}
			else{
				current_number += 2;
			}
		}
		else{
			current_limit = (int) pow((double) primes_found[c_primes_found - 1], 2);
		}
	}
	struct result primes;
	primes.c_primes_found = c_primes_found;
	primes.primes_found = primes_found;
	return primes;
}
