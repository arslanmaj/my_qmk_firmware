# Useful bash commands

### Find/Grep related

* This command does the following: Finds '.jpg' or '.png' file extensions that have the words 'hello' in them. Then it moves all the files found to ``my_dir_name``.

    ``mv $(find -name \*.jpg -or -name \*.png | grep "hello") my_dir_name/``

### PS

* ``ps -A | grep flux``
* This finds all processes with the name 'flux'

### Gnome keyboard Mapping

* Desktop/
* To remove 'switch-to-workspace-down'  
    ``gsettings set org.gnome.desktop.wm.keybindings switch-to-workspace-down "['']"``

### apt

If ``sudo apt-get update`` gets a PPA error, then you should remove the PPA causing the error

Example: 
```
sudo apt-get update
Hit:1 http://dl.google.com/linux/chrome/deb stable InRelease
Ign:2 http://ppa.launchpad.net/nathan-renniewaldock/flux/ubuntu focal InRelease        
Err:3 http://ppa.launchpad.net/nathan-renniewaldock/flux/ubuntu focal Release          
  404  Not Found [IP: 91.189.95.85 80]
Hit:4 http://us.archive.ubuntu.com/ubuntu focal InRelease
Hit:5 http://security.ubuntu.com/ubuntu focal-security InRelease
Hit:6 http://us.archive.ubuntu.com/ubuntu focal-updates InRelease
Hit:7 http://us.archive.ubuntu.com/ubuntu focal-backports InRelease
Reading package lists... Done
E: The repository 'http://ppa.launchpad.net/nathan-renniewaldock/flux/ubuntu focal Release' does not have a Release file.
N: Updating from such a repository can't be done securely, and is therefore disabled by default.
N: See apt-secure(8) manpage for repository creation and user configuration details.
```

To remove the cause of the problem, I ran:

``sudo apt-add-repository -r ppa:nathan-renniewaldock/flux``


### Modifying a Gnome extension 'schema' file and recompiling

1. Download extension to ~/.local/share/gnome-shell/extensions/
    * i.e. cd to 'extensions'
    * git clone 'https://....git'

2. Modify 'schema' *.xml file
    * Location: ~/.local/share/gnome-shell/extensions/*/schemas/'

3. Compile it   
    ``glib-compile-schemas ~/.local/share/gnome-shell/extensions/switcher@landau.fi/schemas/``s


### Disk Partitions

1. To list all partitions:
    ``sudo fdisk -l`` 

Important notes for your system

Linux Partition: 
* /dev/nvme0n1p7 1122375680 1998360575  875984896 417.7G Linux filesystem
* /dev/nvme0n1p7: UUID="74982420-98c2-4797-833e-7271b762c57a" TYPE="ext4" PARTUUID="52b4914c-af2c-4c32-bffa-3dd8b4d0b183"

Windows Partition:
* /dev/nvme0n1p3     567296 1020813311 1020246016 486.5G Microsoft basic data
* /dev/nvme0n1p3: TYPE="BitLocker" PARTLABEL="Basic data partition" PARTUUID="341dc84a-c86b-46e9-a452-39558966b1f7"
