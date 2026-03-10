Student Name: Gabriel Fernandez
Student ID: 24394306

In order to input data into the program, the "example.in" file should be used, as the program parses its data into cache capacity, number of requests, and a sequence of integers.
The input is assumed to always be valid, meaning there is little-to-no error checking in this current version. The current formatting of the enclosed "example.in" file should be followed in inputting new data.

Question 1:
a.) Optimal offline will, as the name suggests, be either equal to or greater than either FIFO or LRU due to having data offline which can be referenced to always take the best path. The information given prior to computation allows for the best choice to be made at every point where FIFO and LRU are likely to not choose the most optimal.

b.) FIFO generally operates slightly less efficiently than LRU due to the placement order being assumedly arbitrary, as opposed to LRU, which uses a metric by which data is pulled from the cache to make its determination for eviction. In many cases, especially with smaller data sets, they may have little difference, but at a very large scale, LRU can potentially save a lot of resources compared to FIFO.

Question 2:
In the case of a bad sequence for LRU, with only a capacity of 3, the OPTFF will miss strictly less whenever the same items keep being passed in at a frequency more broad than 3 spaces. In this situation, LRU would continuously evict the ID which corresponds to the upcoming ID in the next pass, whereas OPTFF will be able to work around this situation to miss strictly less than LRU.

An example of such a sequence would be {3, 6, 9, 3, 6, 9, 3, 5, 6, 7, 8, 5}, where, out of 12 IDs, LRU incurs 5 misses more than OPTFF, which is able to hit more often on the repeated sequences in addition to recognize a unique repeating number once the sequence of three ends.  
