# Week 4: Implementation of Orphan and Zombie Processes

## Aim
To demonstrate the creation and behavior of orphan and zombie processes.

## Problem Statement

Part A: Orphan Process
Write a C program in which the parent process terminates
before the child process completes execution.

Part B: Zombie Process
Write a C program in which the child process terminates
but the parent process does not immediately collect its
termination status.

## Concepts Used
- fork()
- getpid()
- getppid()
- sleep()
- Process termination
- Zombie and orphan processes