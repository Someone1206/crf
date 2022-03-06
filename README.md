# crf
A command line utility for windows to create files


## Nomenclature
crf = ***Cr***eate ***F***iles


## Short Description
This is a simple command line utility that can be used in Windows command prompt to create multiple files. It is similar to the `touch` command in Linux.

**Why is this made?**
To reduce the hassle caused by windows for creating files directly from the command line. The usual way was to use notepad (`notepad file.txt`). It leads to a GUI confirmation and then you may quit it. This application simply creates the file and shows the errors, if any.

**Any Workaround for this without using *crf*?**
Of course YES. You can use `WSL` with a distribution of your choice.

**Okay, so once again, why is it made?**
I always don't have `WSL` open and there are times, while working with platform(Windows) specific projects like *this* one, I tend to use the `CMD` for building. I know you can use the IDE for creating file but that's a lot of work, right😅😁? So I made this.  
+  
There are *udder* situations where I need to create files and don't wanna touch the boring GUI of notepad/move my hands from the keyboard/remove focus from the `CMD`.


## Getting Started
Download the latest executable under `tags` and add the path of the executable to the environment variables under `Path`


## Usage
```
crf [<path to new file(s)>]
```
Example:
```
crf test.txt test2.txt iH8Java.java
```
There are currently no flags.

## Contribution
Fork the repository, make changes and build using and different script(`compile.cmd`).

***Keep in mind the rules & norms to contribute mentioned in `CONTRIBUTING.md`***