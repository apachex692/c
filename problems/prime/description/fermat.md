# Fermat Primality Test

- Fermat primality test states that if a number N is prime, then for every A
ranging from 2 to N - 1, A^(N - 1) % N = 1.
- If the number is prime, then this method always returns true, but if the
number is composite, then the function may either return true or false. However,
the probability of getting false is very less.
- The values of A are randomly choosen. Let the number of checks be K. More the
value of K, better the probabilty of getting the right answer.
