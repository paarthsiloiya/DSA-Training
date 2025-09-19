# **Assignment -1**

---

**Subject:** DS Training & Leet Code Practice  
**Total Marks:** 30  

**Date of Issue:** 18/09/25  
**Date of Submission:** 25/09/25  

**Faculty Name:** Aman Kumar

**Note:** All Problem Statements are compulsory to attempt. Use C as your coding language.

---

## Problem Statement: 01

You are designing a system for a stock brokerage firm. The firm wants to analyze daily stock prices of a company over N days.

**Implement -**

a. Given an array of stock prices, implement a function to find the maximum profit that can be earned by buying and selling the stock only once.  
   - Example: [7,1,5,3,6,4] → Max Profit = 5 (buy at 1, sell at 6)  

b. Extend the problem: Find the maximum profit with at most 2 transactions.  
   - Example: [3,3,5,0,0,3,1,4] → Max Profit = 6 (buy at 0 sell at 3, buy at 1 sell at 4)  


## Problem Statement: 02

You are required to develop a menu-driven Java program to manage a music playlist using a singly linked list. Each node in the linked list should represent a song, containing:

- String songTitle
- String artist
- int durationInSeconds

Your program should allow users to perform the following operations:

### Functional Requirements (Menu Options):

1. Add song at the beginning of the playlist
2. Add song at the end of the playlist
3. Add song at a specific position
4. Delete song from beginning
5. Delete song from end
6. Delete song from specific position
7. Update song details at a given position (e.g., title or artist)
8. Display the entire playlist with song details
9. Exit

## Problem Statement: 03

A hospital maintains a queue of patients in the emergency ward. Each patient has:

- Patient ID
- Name
- Severity Score (1–10, where 10 = most critical)

The hospital policy is:

1. Patients with higher severity are treated first.
2. If two patients have the same severity, the one who arrived earlier is treated first.
3. After treatment, the patient is removed from the list.

**Implement -**

- a priority-based linked list that supports:
  1. addPatient(id, name, severity) – insert patient in the correct order.
  2. treatPatient() – remove and return the highest priority patient.
  3. displayQueue() – show the current patient order.

- Test the system with at least 10 patients, mixing severities and insertion orders.