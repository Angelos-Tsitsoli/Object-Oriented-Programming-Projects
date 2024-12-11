# Exercises About Object Oriented Programming

<img width="371" alt="image" src="https://github.com/user-attachments/assets/c02d8ec5-edfb-40c0-9def-16aabc997dcb">

This collection of exercises aims to reinforce foundational concepts of Object-Oriented Programming (OOP), such as classes, objects, inheritance, polymorphism, encapsulation, and abstraction. Each exercise focuses on applying these principles to real-world scenarios, promoting an understanding of how OOP improves code structure, reusability, and maintainability.

# Exercise #1 (Library)
## Description
This exercise aims to practice the fundamental concepts of class composition, constructors and destructors, as well as the accessibility and scope of class members in C++. In this exercise, i was  required to implement a simulation of a library's functionality, which consists of a base, a cupboard, and three shelves. The cupboard contains two internal shelves, and each shelf hosts books. Each book includes its title, the author's full name, and its ISBN.
The library provides functionality for placing books on specific shelves, removing books from them, and printing the current status of the library with the books it contains. Each class has a constructor that prints related messages during the creation of the object (e.g., "a library is being created") and a destructor that prints messages when the object is destroyed.


# Exercise #2
## Description
This exercise aims to practice the use of the new and delete operators, copy constructor functions, the use of the this pointer, inheritance, and virtual functions.

In this exercise, we have a community of creatures: good creatures and bad creatures. These creatures live side by side in specific positions, with each creature occupying its own place. The creatures have the following characteristics:

* Each creature has a name.
Each creature has a lifespan, which is initially set to a value L (where 𝐿>0  and is the same for all creatures).
* When a creature’s life reaches zero, it enters a zombie state. In the zombie state, any further actions have no effect on the creature.
* A creature can clone itself into the position of another creature. In this case, the other creature is destroyed, and a new creature, which is a copy of the original, takes its place.
* Each creature can either be blessed or beaten. When blessed, the creature's lifespan increases by one unit, and when beaten, it decreases by one unit.
  
Good creatures, when blessed and in a sufficiently healthy state, clone themselves into the next available position in the community (with the next position after the last one being the first). They are considered "healthy" if their current lifespan is greater than a threshold value (good thrsh), which is common to all good creatures.

Bad creatures, when blessed and in a sufficiently healthy state, clone themselves into all the consecutive positions in the community that are occupied by zombies (unless the bad creature is at the end of the community). They are considered "healthy" if their current lifespan is greater than a threshold value (bad thrsh), which is common to all bad creatures.

At any given time, a random creature is chosen, and a random action (blessing or beating) is applied to it. This process is repeated 𝑀 times. It is possible for the same creature to be chosen multiple times.


# Exercise #3
## Description
