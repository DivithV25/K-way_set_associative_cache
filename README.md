# K-Way Set Associative Cache Implementation in C++

## Overview

This project implements a K-way set associative cache using C++. The cache is designed with the aim of optimizing memory access times through an efficient data retrieval mechanism. The core of this implementation leverages a combination of a double linked list and a map.

## Features

- **Add Data to Cache**: Efficiently add data to the cache, ensuring optimal memory usage.
- **Fetch Data from Cache**: Quickly retrieve data from the cache with minimal latency.
- **Display Memory Access Time**: Measure and display the memory access time to demonstrate the efficiency of the cache.

## Implementation Details

### Data Structures

- **Double Linked List**: Used to maintain the order of elements in the cache, facilitating quick updates and deletions.
- **Map**: Provides O(1) average time complexity for data access, ensuring rapid lookups.

### Cache Operations

1. **Add Data**: Adds new data to the cache, updating the linked list and map accordingly.
2. **Fetch Data**: Retrieves data from the cache, updating the position of the accessed data in the linked list to maintain access order.
3. **Display Memory Access Time**: Measures and displays the time taken for memory access operations.
