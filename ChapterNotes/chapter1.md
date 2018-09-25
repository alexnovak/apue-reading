# Chapter 1

## Intro
Focus of text is to describe the services provided by various versions of tue UNIX os
Whrilwind tour of UNIX from a programmer's perspective.

## Architecture
OS is the software that controls the hardware resources of the computer
and provides an environment under which programs can run. We call this the kerne.

System calls are an interface to the kernel.
Shell is a special application that provides an interface for running other applications.

os is a kernal and all other software that makes a computer useful.

Linux is used by the GNU os.

## Logging in
Usernames are looked up in /etc/passwd
entries are login name, encrypted password, uuid, guid, comment, home directory, and shell program.

Entry for me on my computer is
alex:x:1000:1000:alex,,,:/home/alex:/bin/bash

All contemporary systems have passwords moved to a different file (/etc/shadow I think)

A shell is a command line interpreter that reads user input and executes commands.
User input to a shell is from a terminal. Sometimes from a file.

## Files and directories

**File system**
Unis file system is hierarchical arrangement starting from `/`. A directory is a file
thta contains directory entries. `stat` and `fstat` functions return a structure of info containing all attributes of a file.

**Filename**
Cannot have / or null character in a filename. Good practice to restrict characters in a filename to
a subset of the normal printing characters.
Some special characters can be used.

**Pathname**
A sequence of one or more filenames, separated by slashes and optionally starting with
a slash formas a pathname.

**Working Directory**
Every process has a working directory. Directory from which all relative pathnames are
interpreted. A process can change its working directory with the `chdir` function.

## Input and Output
**File Descriptors**
Small non-negative integers that the kernel uses to identify the files accessed by a
process. When opening an existing file or creating a new file, return a file descriptor
to read or write the file.

**Standard Input, Output, and Error**
All shells open three descriptors when run, si, so, se.

**Unbuffered I/O**
Provides open, read, write, lseek, and close. All work with file descriptors.

**Std i/o**
Provide buffered interface to the unbuffered I/O functions.
No optimal buffer sizes.
Simplify dealing with lines.
Lets us control style of buffering used by library.


## Programs and Processes
**Program**
An executable file residing on disk in directory. Read into memory
and executed by kernel as a result of one of _seven_ exec functions.

**Process and process ID**
Executing an instance of a pgoram is a process.
Every process has a unique pid identifying it. nonnegative integer.

**Process Control**
There are three functions for process control, `fork`, `exec`, and `waitpid`.

**Threads and Thread IDs**
Usually, process only has one thread of control. Can spawn multiple threads
to exploit parallelism. All threads share same same address space, file
descriptors, stacks, and process attributes. All have own stacks, but can
access stacks of others.

Threads have ids that are unique to process.

**Error Handling**
Errors typically produce negative response codes. Integer errno is usually set
to a value that tells why.
<errno.h> defines the symbol errno and constants for each value that errno can assume.
Each begin with the character E.
Error constants are listed in the errno(3) manual page.

**Error Recovery**
Errors defined in `<errno.h>` can be divided into fatal and nonfatal.
fatal has no recovery action. Print, log, kill.
Typical recovery action for a nonfatal is delay and retry later.

#User Identification
**User ID**
User id from our entry in passwd is numeric and identifies user to the system.

#Signals
A technique to notify a process about some conditions that have occurred.
Can do one of three things with these:
1. Ignore it. Not recommended for hardware level exceptions.
2. Let the default action occur.
3. Provide a function called when the signal occurs. A catch.

A lot of things generate signals.

# Time Values
UNIX systems maintain two different time values:
Calendar time, the nubmer of seconds since the Epoch(January 1, 1970)

Process time, the cpu ticks used by a process.

Three values for a process:
* Clock time: The amount of time the process takes to run. Depends on number of
other processes being used on the system.
* User CPU time is the CPU time attributed to user instructions.
* System CPU time

Use the time command to measure any of that shit.

#System calls and Library Functions
There are service points to request services from kernel. All implementations of
UNIX have a well defined and limited number of entry points called system calls.

Technique used on UNIX systems for each call is to have a function of the same
name in the standard C library. This function then invokes the appropriate service.

To an implementer, the distinction between a system call and a library function
is critical. Users don't care.
