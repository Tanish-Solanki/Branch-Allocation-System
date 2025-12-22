# Branch Allocation System

A console-based application that allocates academic branches to students based on their rank, preferences, and seat availability.  
The system simulates a real-world college counseling process using efficient data structures in C++.

---

## Problem Statement
During college admissions, students are allocated branches based on merit (rank) and their preferred choices, subject to seat availability.  
This project models that process by prioritizing higher-ranked students and assigning them the best available branch from their preference list.

---

## Features
- Rank-based student processing using a priority queue
- Branch allocation based on student preferences
- Seat availability tracking for each branch
- Input validation for contact number and email
- Summary view of final branch allocation
- Candidate list displayed in rank order

---

## Core Concepts Used
- Object-Oriented Programming (OOP)
- Priority Queue (Heap) for rank-based allocation
- STL Containers (`vector`, `priority_queue`)
- Custom comparator for student ranking
- Input validation using regex and standard algorithms

---

## Project Structure
branch-allocation-system/
│
├── Innovative.cpp
├── README.md

---

## How the Allocation Works
1. Branches and their seat capacities are initialized.
2. Student data is collected along with branch preferences.
3. Students are inserted into a priority queue based on rank.
4. The highest-ranked student is processed first.
5. The system assigns the first available branch from the student’s preference list.
6. Allocation continues until all students are processed.

---
Tanish Solanki
GitHub: https://github.com/Tanish-Solanki
