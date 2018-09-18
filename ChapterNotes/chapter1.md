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
