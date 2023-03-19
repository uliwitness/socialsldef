# SocialsLDEF
A List Manager LDEF (List Definition Function) plus test app for displaying social media
posts with bold username and avatar image.

# Prerequisites
To build this, you need

* CodeWarrior Pro 6 for Macintosh System 7.0
* A Mac to run it on (or an emulator like Basilisk II or SheepShaver)
* StuffIt 5 to unpack the `.sit` files
* The HyperCard stack in the `CheapVersionControl.sit` archive in this repository
  to copy the `.rsrc` files back from the data fork into the resource fork, and
  to convert the source files back from UTF8 with LF to MacRoman with CR line endings.
  (Its "Revert" button can be used to do this)

# How to use in your MacOS 9 app

The file SocialsLDEF/SocialsLDEFData.h contains the `SocialsEntry` struct that defines what
a list cell's data has to look like. Note that the `message` array is actually a variable-length
array that can be any size you want (below 32k) for the text to show.
