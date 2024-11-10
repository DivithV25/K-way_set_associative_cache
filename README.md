# LRU Cache & Set Associative Cache Simulation

This repository contains a simulation of an **LRU (Least Recently Used) Cache** and a **Set-Associative Cache** in C++. The implementation demonstrates cache management and access operations with an emphasis on efficient memory usage. It is designed to help users understand how caches work, specifically in managing memory access in computer systems.

## Features

- **LRU Cache Implementation**:
  - The `LRUCache` class implements the Least Recently Used caching mechanism where the most recently accessed or added items are stored at the front, and the least recently used ones are evicted when the cache exceeds its capacity.
  - Handles cache hits and misses efficiently with proper eviction strategies.

- **Set-Associative Cache Simulation**:
  - The `SetAssociativeCache` class simulates a set-associative cache using multiple LRU caches, where each set can hold multiple blocks. Each set in the cache can hold up to `k` items.
  - Memory addresses are mapped to specific sets, and data can be added, fetched, or evicted depending on the access pattern.

- **Memory Access Time**:
  - The system measures the time it takes to perform a memory access (both read and write) in microseconds and displays the results.

- **Cache Hit and Miss Tracking**:
  - The system tracks and displays the number of cache hits and misses.

## Structure

- `LRUCache`:
  - Implements the logic for an individual Least Recently Used cache with operations to get and put data.
  - The cache is implemented using a doubly linked list and a map for efficient access and removal.

- `SetAssociativeCache`:
  - A higher-level cache system that simulates a set-associative cache where memory addresses are divided across multiple LRU caches (sets).
  - Allows you to access memory blocks, perform operations, and measure memory access time.


## Code Structure

The program is structured as follows:

- **LRUCache Class:**
  - Handles cache operations such as putting and getting data, managing the cache eviction, and measuring the time for memory accesses.
  
- **SetAssociativeCache Class:**
  - Implements a set-associative cache, dividing the cache into multiple sets and performing operations on them.

- **Main Function:**
  - Provides an interactive CLI for users to interact with the cache system, choose operations, and input data.

## Enhancements & Future Work

- **Concurrency:** Add thread safety to simulate cache behavior in multithreaded environments.
- **LRU Cache Optimization:** Enhance the LRU logic to handle larger caches more efficiently.
- **Cache Replacement Policies:** Implement other cache replacement strategies such as FIFO, Random, or LFU.
- **Support for More Operations:** Add additional operations like cache flush, cache clear, etc.

## Acknowledgments

- This simulation was built to demonstrate cache algorithms and is intended for educational purposes.


