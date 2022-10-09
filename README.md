# Data-Structures-and-Algos-Hashing-Analysis
Performed an analysis of hash table number of collisions versus load factor as a function of collision resolution scheme and hash function.
Chose three hash table sizes.  Made one of the hash table sizes a prime number.

For each hash table size, randomly generated key values between 0 and 3 times the hash table size.   
(If the table size is 100, generate key values between 0 and 300).  
As each key value is placed in the hash table, recorded the current load factor and the number of collisions that have occurred.  
When counting collisions, for each key there is at most one collision.  
(Even if the key requires multiple probes to find a spot, this counts as one collision.)

Performed this experiment for four combinations of hash function and collision resolution scheme.

Hash functions: key mod table size, mid square

Collision resolution schemes: separate chaining, open addressing.

Thus there are 4 experiments with three table sizes per experiment.
