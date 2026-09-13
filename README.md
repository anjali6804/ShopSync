# ShopSync

## Concurrent Multi-Client E-Commerce & Communication System

ShopSync is a C++ based application that combines **data structures, object-oriented programming, file persistence, TCP socket programming, multithreading, and memory tracking** into a single practical project.

The project simulates an e-commerce system with product and cart management while also providing a concurrent multi-client TCP chat system.

---

## Features

### E-Commerce System
- Add, remove, search, and update products
- Update product price and stock
- Display complete product inventory
- Sort products by price
- Sort products by stock
- Add products to cart
- Remove products from cart
- Calculate cart total
- Create orders with unique order IDs
- Automatically update product stock after checkout

### Data Persistence
- Product inventory is stored in `data/products.txt`
- Products are loaded when the application starts
- Inventory changes can be saved back to the file
- Pipe-separated file format is used for structured storage

### Data Structures
- `std::unordered_map` for fast product lookup by ID
- `std::vector` for cart and order item storage
- `std::stack` for cart history
- `std::unordered_set` for tracking active memory allocations

### Concurrent Multi-Client Chat
- TCP client-server communication
- Multiple clients supported simultaneously
- Dedicated thread for each connected client
- Message broadcasting between connected clients
- Client disconnect detection
- Graceful client shutdown
- Thread-safe client management using `std::mutex`
- Send/receive error handling

### Memory Leak Detection Toolkit
- Manual allocation tracking
- Deallocation tracking
- Active memory block tracking
- Detection of potential leaked blocks
- Memory tracking test cases

---

## Project Architecture

```text
                         ShopSync
                            |
              +-------------+-------------+
              |                           |
       E-Commerce System             Chat System
              |                           |
        ProductManager              TCP Server
              |                           |
        +-----+-----+              Multi-client
        |           |              communication
      Cart        Order                  |
        |                             Threads
    CartStack                            |
        |                              Mutex
     STL Stack

## PROJECT STRUCTURE 
ShopSync/
│
├── include/
│   ├── product.h
│   ├── product_manager.h
│   ├── cart.h
│   ├── cart_stack.h
│   ├── order.h
│   ├── menu.h
│   ├── server.h
│   ├── client.h
│   └── memory_tracker.h
│
├── src/
│   ├── main.cpp
│   ├── menu.cpp
│   ├── product.cpp
│   ├── product_manager.cpp
│   ├── cart.cpp
│   ├── cart_stack.cpp
│   ├── order.cpp
│   ├── server.cpp
│   ├── server_main.cpp
│   ├── client.cpp
│   ├── client_main.cpp
│   └── memory_tracker.cpp
│
├── data/
│   └── products.txt
│
├── tests/
│   ├── test_stack.cpp
│   └── test_memory_tracker.cpp
│
└── README.md


##Technologies & Concepts
Language: C++
Standard: C++17
Operating System: Linux / Ubuntu
Build Tool: g++
Version Control: Git & GitHub
Debugging: GDB
Networking: TCP/IP sockets
Concurrency: std::thread
Synchronization: std::mutex
Data Structures: vector, stack, unordered_map, unordered_set
File Handling: C++ file streams
OOP: Classes, objects, constructors, encapsulation

Build & Run
1. Build the E-Commerce Application
From the project root:
g++ -std=c++17 src/main.cpp src/menu.cpp src/product.cpp src/product_manager.cpp src/cart.cpp src/cart_stack.cpp src/order.cpp src/memory_tracker.cpp -Iinclude -o shopsync

Run:./shopsync

# Multi-Client Chat
Build Server
g++ -std=c++17 src/server_main.cpp src/server.cpp -Iinclude -pthread -o shopsync_server
Run:./shopsync_server

Build Client
In another terminal:
g++ -std=c++17 src/client_main.cpp src/client.cpp -Iinclude -pthread -o shopsync_client
Run:./shopsync_client

##Open multiple terminals and run shopsync_client to test multi-client communication.

Testing
Cart Stack Test
g++ -std=c++17 tests/test_stack.cpp src/cart.cpp src/cart_stack.cpp src/product.cpp -Iinclude -o stack_test
Run:./stack_test

Memory Tracker Test
g++ -std=c++17 tests/test_memory_tracker.cpp src/memory_tracker.cpp -Iinclude -o memory_test
Run:./memory_test

The memory tracker reports:
Allocations
Deallocations
Active blocks
Memory status
Debugging with GDB

#A debug build can be created using:
g++ -std=c++17 -g src/main.cpp src/menu.cpp src/product.cpp src/product_manager.cpp src/cart.cpp src/cart_stack.cpp src/order.cpp src/memory_tracker.cpp -Iinclude -o shopsync_debug

Start GDB: gdb ./shopsync_debug

## Useful commands:
break
run
next
print
continue
where

##Key Learning Outcomes
This project demonstrates practical understanding of:
-Object-oriented C++ programming
-Data structure implementation and -usage
-Hash-based product lookup
-Stack-based history management
-File-based data persistence
-TCP socket programming
-Concurrent client handling
-Thread synchronization
-Error and disconnect handling
-Debugging using GDB
-Modular C++ project organization
-Manual memory allocation tracking

##Current Status
Core functionality completed and tested.
The project includes the e-commerce simulator, persistent inventory, data structures, concurrent multi-client TCP communication, memory tracking, testing, debugging, and modular menu architecture.

### Future Improvements
Possible future enhancements include:
Persistent order history
User authentication
Product categories and advanced filtering
Improved command-line interface
Automated unit testing
Automated build system using Makefile/CMake
Automatic memory instrumentation
More advanced socket error recovery
GUI or web-based front end