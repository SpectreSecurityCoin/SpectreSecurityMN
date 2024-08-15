
Debian
====================
This directory contains files used to package spectresecurityd/spectresecurity-qt
for Debian-based Linux systems. If you compile spectresecurityd/spectresecurity-qt yourself, there are some useful files here.

## spectresecurity: URI support ##


spectresecurity-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install spectresecurity-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your spectresecurity-qt binary to `/usr/bin`
and the `../../share/pixmaps/spectresecurity128.png` to `/usr/share/pixmaps`

spectresecurity-qt.protocol (KDE)

