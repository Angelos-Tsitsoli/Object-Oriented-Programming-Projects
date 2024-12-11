# Exercises About Object Oriented Programming

<img width="371" alt="image" src="https://github.com/user-attachments/assets/c02d8ec5-edfb-40c0-9def-16aabc997dcb">

This collection of exercises aims to reinforce foundational concepts of Object-Oriented Programming (OOP), such as classes, objects, inheritance, polymorphism, encapsulation, and abstraction. Each exercise focuses on applying these principles to real-world scenarios, promoting an understanding of how OOP improves code structure, reusability, and maintainability.

# Exercise #1 (Library)
## Description
This exercise aims to practice the fundamental concepts of class composition, constructors and destructors, as well as the accessibility and scope of class members in C++. In this exercise, i was  required to implement a simulation of a library's functionality, which consists of a base, a cupboard, and three shelves. The cupboard contains two internal shelves, and each shelf hosts books. Each book includes its title, the author's full name, and its ISBN.
The library provides functionality for placing books on specific shelves, removing books from them, and printing the current status of the library with the books it contains. Each class has a constructor that prints related messages during the creation of the object (e.g., "a library is being created") and a destructor that prints messages when the object is destroyed.


# Exercise #2
## Description



# Exercise #3
## Description
This exercise aims to practice the use of the new and delete operators, copy constructor functions, the use of the this pointer, inheritance, and virtual functions.

In this exercise, we have a community of creatures: good creatures and bad creatures. These creatures live side by side in specific positions, with each creature occupying its own place. The creatures have the following characteristics:

Good creatures, when blessed and in a sufficiently healthy state, clone themselves into the next available position in the community (with the next position after the last one being the first). They are considered "healthy" if their current lifespan is greater than a threshold value (good thrsh), which is common to all good creatures.

Bad creatures, when blessed and in a sufficiently healthy state, clone themselves into all the consecutive positions in the community that are occupied by zombies (unless the bad creature is at the end of the community). They are considered "healthy" if their current lifespan is greater than a threshold value (bad thrsh), which is common to all bad creatures.


# Java Exercise
## Description
This exercise tests a combination of object-oriented programming concepts, including inheritance, polymorphism, encapsulation, and abstraction. It also involves implementing conditional logic, managing data input/output, and manipulating collections of objects.
This exercise required me to implement the following hierarchy of artifacts in Java. An artifact has an index number, a creator, and a creation year, all of which are assigned initially and remain constant. Additionally, the artifact has two methods:

* getInfo(): This method prints the creator and the creation year of the artifact.
* getIndex(): This method prints only the index number of the artifact.
The task involves creating a class to represent an artifact with these attributes and methods, ensuring the values for the index, creator, and year are immutable once assigned. This exercise will help you practice the principles of class design, encapsulation, and method implementation in Java.

# Project
## Description
This exercise involves simulating a hypothetical one-way operation of the Attiki Odos highway in C++. The simulation will include the following details:

* The highway has an initial node (entry), a final node (exit), and a set of intermediate nodes.
* Vehicles can enter only at the initial node and exit only at the final node. Intermediate nodes allow both entry and exit of vehicles.
* The highway consists of NSegs segments between nodes, with each segment having a defined capacity (maximum number of vehicles it can hold at once).
* Each node, except the final one, has toll booths for vehicle entry into the segment starting from that node. The number of toll booths and their types (manual or electronic) can vary across nodes.
* Vehicles may be in different states: either ready to exit (if they are at the correct segment and their destination is the current exit), or staying in the segment for the next round. The simulation will also track vehicles waiting to enter a segment at toll booths.
* For each segment, a percentage (PPercent) of the vehicles in the segment may transition to "ready to exit" status, based on the current situation.
The simulation runs in reverse order, starting from the final segment and working back towards the initial node. Vehicles with the destination of the final node exit first. Then, vehicles ready to enter from the previous segment will move into the current segment, provided the capacity allows. The simulation respects the segment capacities and manages the number of vehicles entering from the toll booths. Manual toll booths allow up to K vehicles to enter, while electronic booths allow up to 2K vehicles, without exceeding the segment capacity.

In each cycle, the simulation will adjust the number of vehicles allowed to enter based on the capacity and update the toll booth entry limits (K). If the maximum number of vehicles enter a segment, the value of K will increase for the next cycle. Conversely, if fewer vehicles enter, K will decrease.

This exercise requires a solid understanding of C++ classes, data structures, and simulating a dynamic system with constraints such as capacity, toll booth types, and vehicle management.
